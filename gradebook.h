#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility> //for pairs
#ifndef GRADEBOOK_H
#define GRADEBOOK_H

class GradeBook{
private:
    std::vector<std::string> category;
    std::vector<float> points_earned;
    std::vector<std::string> name;
    int size;
    std::vector<std::string> unique_category;

public:
    //default constructor
    GradeBook();
    //constructor
    GradeBook (std::vector<std::string> category_vector, std::vector<std::string> name_vector, std::vector<float> points_earned_vector);
    //orders categories into unique categories
    void order_category();

    //methods that allow you to append a value to one of the three vectors
    void category_add_on(std::string value);
    void name_add_on(std::string value);
    void points_earned_add_on(float value);

    void printAssignment(std::string file_name);
    void printCategory(std::string file_name);
    void printOverall(std::string file_name, int condition);
    //for each of these, these return the points_earned and points_total.
    //The reason why is because I can reuse code.
    //we will do this using a pair<int><int>. First will be points_earned and second will be points_total
    std::pair<float, float> individual_grade(std::string individual_name);
    std::pair<float, float> category_grade(std::string individual_category);
    std::pair<float, float> course_total_grade();
    //turns a set of points_earend and points_total into a percentage;
    float turn_to_percentage(float grade_points_earned, float grade_points_total);

    //grabs the point total of a specific category
    float get_assignment_points_total(std::string category_name);
    //allows user to change the grade of a specific assignment
    void change_grade(std::string assignment_name, float new_grade);
    //prints out the gradebook in the original csv file format
    void printGradeBook(std::string file_name);
    //prints out one chosen assignment
    void printIndividualAssignment(std::string file_name, std::string assign_name);

};

#endif //GRADEBOOK_H
