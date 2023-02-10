#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include "Gradebook.h"

std::string openFile(){
    std::string file_name;
    while(true) {
        std::cout << "Enter file name: ";
        std::cin >> file_name;
        // read filename
        std::fstream file(file_name);

        if (file.is_open()) {
            return file_name;
        }
        else{
            std::cout <<"Incorrect File Name or Not Able To Find File. Try Again \n";
        }
    }
}


void extractCSV(std::string file_name, GradeBook &Grade) {
    std::fstream file;
    file.open(file_name, std::ios::in);
    int num;
    std::string line, assignment_name, category_name, temp;
    std::getline(file, line);
    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, assignment_name, ',');
        std::getline(ss, category_name, ',');
        std::getline(ss, temp, ',');
        num = stoi(temp);
        Grade.points_earned_add_on(num);
        Grade.category_add_on(category_name);
        Grade.name_add_on(assignment_name);
    }
}

int main() {
    bool boo = true;
    std::string inp;
    GradeBook Grade;
    //Open file
    std::string file_name = openFile();
    //extract data into  Grade
    extractCSV(file_name, Grade);
    //Ask user for options or quit
    while(boo){
        std::cout<<"Choose an option of \n";
        std::cout<<"If you want to access your grades by assignments enter 'assignment' \n";
        std::cout<<"If you want to access your grades by category enter 'category'\n";
        std::cout<<"If you want to access your overall grade enter 'overall'\n";
        std::cout<<"If you want to quit, enter 'quit'\n";
        std::cin >> inp;
        transform(inp.begin(), inp.end(), inp.begin(), ::toupper);
        if(inp == "ASSIGNMENT"){

        }
        else if(inp == "CATEGORICAL" or inp == "CATEGORY"){

        }
        else if(inp == "OVERALL"){

        }
        else if(inp == "QUIT"){
            boo = false;
        }
        else{
            std::cout<< "Unable to read input, Try Again \n";
        }
    }
    /*
     * GradeBook.getLabs();
    GradeBook.getHomework();
    GradeBook.getFinal();
    GradeBook.getProject();
    GradeBook.getMEC();
    GradeBook.calculateGrade();
    */
}
