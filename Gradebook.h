#include <vector>
#include <string>
#ifndef GRADEBOOK_H
#define GRADEBOOK_H
class GradeBook{
private:
    std::vector<std::string> catagory;
    std::vector<int>points_earned;
    std::vecotr<std::string> name;

public:
    int individual_grade();
    int category_grade();
    int course_total_grade();

};

#endif //GRADEBOOK_H
