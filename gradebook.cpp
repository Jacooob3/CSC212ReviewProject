#include "gradebook.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <utility> //for pairs

//default constructor
GradeBook::GradeBook(){
    std::vector<int> grades;
    this -> size = 0;
}

//ideal constructor of the class. takes in the assignment name, category, and grade
GradeBook::GradeBook (std::vector<std::string> category_vector, std::vector<std::string> name_vector, std::vector<int> points_earned_vector){
    for (int i = 0; i < category_vector.size(); i++){
        this->category.push_back(category_vector[i]);
        this->name.push_back(name_vector[i]);
        this->points_earned.push_back(points_earned_vector[i]);
    }
    this -> size = category_vector.size();

}
//orders all the categories into unique categories, essentially making a list of every unique category
void GradeBook::order_category() {
    std::vector<std::string> temp;
    for (int i = 0; i < category.size(); i++) { //made loop to make unique category vector
        bool hi = true;
        for (int j = 0; j < temp.size(); j++) {
            if (category[i] == temp[j]) {
                hi = false;
                break;
            }
        }
        if (hi) {
            temp.push_back(category[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        bool test = true;
        for(int j = 0; j < unique_category.size(); j++) {
            if (temp[i] == unique_category[j]) {
                test = false;
                break;
            }
        }
        if (test) {
            this->unique_category.push_back(temp[i]);
        }
    }

}

//methods that allow you to append a value to one of the three vectors
void GradeBook::category_add_on(std::string value)
{
    this->category.push_back(value);
    this -> size += 1;
}
void GradeBook::name_add_on(std::string value)
{
    this->name.push_back(value);
}
void GradeBook::points_earned_add_on(int value)
{
    this->points_earned.push_back(value);
}

//I made this function as it is impossible to use strings as cases of a switch statement
//So this essentially assigns a number to each of the categories and returns the proper points_total for
//an individual project of that category
int GradeBook::get_assignment_points_total(std::string category_name)
{
    //const char* category_list[] = {"Lab", "Assignment", "Project1", "Project2", "Exam"};
    //grabs an index for the assignment so it can work for the switch statement
    int index;
    for (int i = 0; i < unique_category.size(); i++)
    {
        if (unique_category[i] == category_name)
        {
            index = i;
        }
    }
    switch(index)
    {
        case 0:
            return 20;
        case 1:
            return 50;
        case 2:
            return 150;
        case 3:
            return 350;
        case 4:
            return 100;
        default:
            break;
    }
    return 1; //return 1 as opposed to return 0 as to avoid dividing by 0;
}

//for each of these, these return the points_earned and points_total.
//The reason why is because I can reuse code.
//we will do this using a pair<int><int>. First will be points_earned and second will be points_total


//These next three functions print the all the assignment, category, and over all grades respectively
void GradeBook::printAssignment(std::string file_name){
    std::vector<std::string> ordered_list;
    for (int j = 0; j < unique_category.size(); j++) { //Orders all of the given assignments by category
        for (int i = 0; i < category.size(); i++) {
            if (category[i] == unique_category[j]) {
                ordered_list.push_back(name[i]);
            }
        }
    }
    //looping through to print the grade of all given assignments as a percentage and out of course value
    if (file_name.size() == 0) { //code to output to terminal
        std::cout << "Assignment Totals:" << "\n";
        for (int i = 0; i < size; i++) {
            std::pair<int, int> temp = individual_grade(ordered_list[i]);
            std::cout << ordered_list[i] << " " << float temp.first << "/" << float temp.second << "\t" << "or "
                      << float turn_to_percentage(temp.first, temp.second) << "%" << "\n";
        }
    }
    else { //code to output to file
        std::ofstream myfile;
        myfile.open(file_name);
        myfile << "Assignment , Grade" << "\n";
        for (int i = 0; i < size; i++) {
            std::pair<int, int> temp = individual_grade(ordered_list[i]);
            myfile << ordered_list[i] << " , " << float temp.first << "/" << float temp.second << "\t" << "or "
                   << turn_to_percentage(temp.first, temp.second) << "%" << "\n";
        }
        myfile.close();
    }
}

void GradeBook::printCategory(std::string file_name){
    //looping through to print the total grade of every given category as a percentage and out of course value

    if (file_name.size() == 0) { //code for printing to terminal
        std::cout << "Category Totals:" << "\n";
        for (int i = 0; i < unique_category.size(); i++) {
            std::cout << unique_category[i] << " " << category_grade(unique_category[i]).first << "/" << category_grade(unique_category[i]).second
                      << "\t" << "or " << turn_to_percentage(
                    category_grade(unique_category[i]).first, category_grade(unique_category[i]).second) << "%" << "\n";
        }
    }
    else { //code for printing to output file
        std::ofstream myfile;
        myfile.open(file_name);
        myfile << "Category , Grade" << "\n";
        for (int i = 0; i < unique_category.size(); i++) {
            myfile << unique_category[i] << " , " << category_grade(unique_category[i]).first << "/" << category_grade(unique_category[i]).second
                   << "\t" << "or " << turn_to_percentage(
                    category_grade(unique_category[i]).first, category_grade(unique_category[i]).second) << "%" << "\n";
        }
        myfile.close();
    }
}

void GradeBook::printOverall(std::string file_name, int condition){
    //printing overall course grade as a percentage and out of total point

    std::vector<std::string> ordered_list;
    for (int j = 0; j < unique_category.size(); j++) { //Orders all of the given assignments by category
        for (int i = 0; i < category.size(); i++) {
            if (category[i] == unique_category[j]) {
                ordered_list.push_back(name[i]);
            }
        }
    }

    if (file_name.size() == 0) { // code for printing to terminal
        std::cout << "Course Total: " << course_total_grade().first << "/" << course_total_grade().second << "\t" << "or "
                  << turn_to_percentage(course_total_grade().first, course_total_grade().second) << "%" << "\n";
    }
    else { // code for printing to output file
        if (condition == 0) { //all grades condition
            std::ofstream myfile;
            myfile.open(file_name);
            myfile << "Assignment , Grade" << "\n";
            for (int i = 0; i < size; i++) {
                std::pair<int, int> temp = individual_grade(ordered_list[i]);
                myfile << ordered_list[i] << " , " << float temp.first << "/" << float temp.second << "\t" << "or "
                       << turn_to_percentage(temp.first, temp.second) << "%" << "\n";
            }
            myfile << "Course Grade" << "\n";
            myfile << course_total_grade().first << "/" << course_total_grade().second << "\t" << "or "
                   << turn_to_percentage(course_total_grade().first, course_total_grade().second) << "%" << "\n";
            myfile.close();
        }
        else if (condition == 1) { //all categories condition
            std::ofstream myfile;
            myfile.open(file_name);
            myfile << "Category , Grade" << "\n";
            for (int i = 0; i < unique_category.size(); i++) {
                myfile << unique_category[i] << " , " << category_grade(unique_category[i]).first << "/" << category_grade(unique_category[i]).second
                       << "\t" << "or " << turn_to_percentage(
                        category_grade(unique_category[i]).first, category_grade(unique_category[i]).second) << "%" << "\n";
            }
            myfile << "Course Grade" << "\n";
            myfile << course_total_grade().first << "/" << course_total_grade().second << "\t" << "or "
                   << turn_to_percentage(course_total_grade().first, course_total_grade().second) << "%" << "\n";
            myfile.close();
        }
        else if (condition == 2) { //only course grade condition
            std::ofstream myfile;
            myfile.open(file_name);
            myfile << "Course Grade" << "\n";
            myfile << course_total_grade().first << "/" << course_total_grade().second << "\t" << "or "
                   << turn_to_percentage(course_total_grade().first, course_total_grade().second) << "%" << "\n";
            myfile.close();
        }
    }
}

std::pair<int, int> GradeBook::individual_grade(std::string individual_name)
{
    //we need to create an index so we can get the matching category and points_earned
    int index = 0;
    int individual_points_total = 0;
    for (int i = 0; i < name.size(); i++) //idk why it says the i++ part is unreachable code
    {
        if (name[i] == individual_name)
        {
            index = i;
            float individual_points_total = this->get_assignment_points_total(category[index]);

            float individual_points_earned = individual_points_total*(points_earned[index]/float(100.00));

            return std::make_pair((int(individual_points_earned)),individual_points_total);
        }

    }
}
//adds up scores of all assignments in a certain category
std::pair<int, int> GradeBook::category_grade(std::string individual_category)
{
    int total_points_earned = 0;
    std::vector<int> scores_per_category; //basically every points_earned value from a category;
    for (int i = 0; i < points_earned.size(); i++)
    {
        if (category[i] == individual_category)
        {
            scores_per_category.push_back(points_earned[i]);
        }
    }

    for (int i = 0; i < scores_per_category.size(); i++)
    {
        total_points_earned += scores_per_category[i];
    }
    int category_points_total = this->get_assignment_points_total(individual_category);
    float category_percent = float(total_points_earned)/float((100.00*scores_per_category.size())); //turning points earned in a category into percentage
    category_points_total*= scores_per_category.size(); //making sure the total points cover every project of that category;
    //std::cout << category_percent << "\n";
    int category_points = category_percent*float(category_points_total); //turning that percentage into points earned out of category total

    return std::make_pair(category_points,category_points_total);
}

//will essentially run the sum of category_grade for every category
std::pair<int, int> GradeBook::course_total_grade()
{
    //const char* category_list[] = {"Lab", "Assignment", "Project1", "Project2", "Exam"};
    std::pair<int, int> total_course_score; //first is points_earned, and second is points_total
    std::pair<int, int> individual_category_score;
    total_course_score.first = 0;
    total_course_score.second = 0;
    for (int i = 0; i < unique_category.size(); i++)
    {
        individual_category_score = category_grade(unique_category[i]);
        total_course_score.first += individual_category_score.first;
        total_course_score.second += individual_category_score.second;
    }
    return total_course_score;

}
//turns a set of points_earned and points_total into a percentage
float GradeBook::turn_to_percentage(int grade_points_earned, int grade_points_total)
{
    float ratio = float(grade_points_earned) / float(grade_points_total);
    ratio *= float(100.00);
    //float grade = (int) ratio;
    return ratio;
}
//changes the grade of a given assignment to the given grade
void GradeBook::change_grade(std::string assignment_name, int new_grade) {
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == assignment_name) {
            this->points_earned[i] = new_grade;
            break;
        }
    }
}
//prints out the whole gradebook to a file
void GradeBook::printGradeBook(std::string file_name) {
    std::ofstream myfile;
    myfile.open(file_name);
    myfile << "Assignment,Category,Grade" << "\n";
    for (int i = 0; i < name.size(); i++) {
        myfile << name[i] << "," << category[i] << "," << points_earned[i] << "\n";
    }
}
//prints out individual assignment grade to either terminal or file
void GradeBook::printIndividualAssignment(std::string file_name, std::string assign_name) {
    if (file_name.size() == 0) { //to terminal
        std::cout << assign_name << " " << individual_grade(assign_name).first << "/" << individual_grade(assign_name).second << "\t" << "or " << turn_to_percentage(
                individual_grade(assign_name).first, individual_grade(assign_name).second) << "%" << "\n";
    }
    else { // to file
        std::ofstream myfile;
        myfile.open(file_name);
        myfile << assign_name << " " << individual_grade(assign_name).first << "/" << individual_grade(assign_name).second << "\t" << "or " << turn_to_percentage(
                individual_grade(assign_name).first, individual_grade(assign_name).second) << "%" << "\n";
        myfile.close();
    }
}
