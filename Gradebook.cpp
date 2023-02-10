#include "Gradebook.h"
#include <vector>
#include <string>
#include <utility> //for pairs

//constructor
GradeBook::GradeBook(){};
GradeBook::GradeBook (std::vector<std::string> category_vector, std::vector<std::string> name_vector, std::vector<int> points_earned_vector)
{
    for (int i = 0; i < category_vector.size(); i++)
    {
        this->category.push_back(category_vector[i]);
        this->name.push_back(name_vector[i]);
        this->points_earned.push_back(points_earned_vector[i]);
    }
}

//methods that allow you to append a value to one of the three vectors
void GradeBook::category_add_on(std::string value)
{
    this->category.push_back(value);
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
    const char* category_list[] = {"Lab", "Assignment", "Project1", "Project2", "Exam"};
    //grabs an index for the assignment so it can work for the switch statement
    int index;
    for (int i = 0; i < 5; i++)
    {
        if (category_list[i] == category_name)
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

std::pair<int, int> GradeBook::individual_grade(std::string individual_name)
{
    //we need to create an index so we can get the matching category and points_earned
    int index = 0;
    int points_total = 0;
    for (int i = 0; i < name.size(); i++) //idk why it says the i++ part is unreachable code
    {
        if (name[i] == individual_name)
        {
            index = i;
            break;
        }

        int points_total = this->get_assignment_points_total(category[i]);

        return std::make_pair((points_earned[index]),points_total);
    }



}

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
    category_points_total*= scores_per_category.size(); //making sure the total points cover every project of that category;

    return std::make_pair(total_points_earned,category_points_total);
}

std::pair<int, int> GradeBook::course_total_grade()
{
    int total_points_earned = 0;
    int total_points_total = 0;
}
//turns a set of points_earned and points_total into a percentage;
int GradeBook::turn_to_percentage(int points_earned, int points_total)
{
    //
}



