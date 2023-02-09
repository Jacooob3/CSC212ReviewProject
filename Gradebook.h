#include <vector>
#include <string>
#include <utility> //for pairs
#ifndef GRADEBOOK_H
#define GRADEBOOK_H
class GradeBook{
private:
    std::vector<std::string> category;
    std::vector<int>points_earned;
    std::vector<std::string> name;

public:
    //constructor
    GradeBook (std::vector<std::string> category_vector, std::vector<std::string> name_vector, std::vector<int> points_earned_vector);

    //methods that allow you to append a value to one of the three vectors
    void category_add_on(std::string value);
    void name_add_on(std::string value);
    void points_earned_add_on(int value);

    //for each of these, these return the points_earned and points_total.
    //The reason why is because I can reuse code.
    //we will do this using a pair<int><int>. First will be points_earned and second will be points_total
    std::pair<int, int> individual_grade(std::string individual_name);
    std::pair<int, int> category_grade(std::string individual_category);
    std::pair<int, int> course_total_grade();
    //turns a set of points_earend and points_total into a percentage;
    int turn_to_percentage(int points_earned, int points_total);

    //grabs the point total of a specific category
    int get_assignment_points_total(std::string category_name);

};

#endif //GRADEBOOK_H
