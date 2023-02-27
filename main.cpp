#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include "gradebook.h"
//asks for the file to be opened and opens it
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
//extracts all the info in the input file and puts it into our class object
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
    //making variables that will be useful later on
    bool boo = true;
    bool out_bool;
    std::string output;
    std::string inp;
    GradeBook Grade;
    std::string out_file;
    std::ofstream myfile;
    //Open file
    std::string file_name = openFile();
    //extract data into Grade
    extractCSV(file_name, Grade);
    //Ask user for output option and notes which one was chosen
    std::cout << "Output to terminal or output file:" << "\n" << "Enter 'terminal' or 'file':" << "\n";
    std::cin >> output;
    Grade.order_category();
    if (output == "terminal") { //making conditions to make output in terminal
        out_bool = true;
    }
    else if(output == "file") { //making conditions to make output in given file
        out_bool = false;
        std::cout << "Enter output file name (.txt or .csv):" << "\n";
        std::cin >> out_file;
    }
    //Ask user for options or quit
    while(boo){
        std::cout<<"Choose an option of \n";
        std::cout<<"If you want to access one of your assignment's grade enter 'searchassignment' \n";
        std::cout<<"If you want to access your grades by assignments enter 'assignment' \n";
        std::cout<<"If you want to access your grades by category enter 'category'\n";
        std::cout<<"If you want to access your overall grade enter 'overall'\n";
        std::cout<<"If you want to change a grade enter 'changegrade'\n";
        std::cout<<"If you want to quit, enter 'quit'\n";
        std::cin >> inp;
        transform(inp.begin(), inp.end(), inp.begin(), ::toupper);
        if (out_bool) { //case if user wants terminal outputs
            std::string null_string = ""; //making an empty string that allows print methods to differentiate between terminal and file output
            if (inp == "ASSIGNMENT") {
                Grade.printAssignment(null_string);
            } else if (inp == "SEARCHASSIGNMENT") { //searching for specific assignment
                std::string assign_name;
                std::cout << "Enter assignment name:" << "\n";
                std::cin >> assign_name;
                Grade.printIndividualAssignment(null_string, assign_name);
            } else if (inp == "CATEGORICAL" or inp == "CATEGORY") {
                Grade.printCategory(null_string);
            } else if (inp == "OVERALL") { //giving overall options
                std::string choice;
                std::cout << "Choose 'allgrades', 'allcategories', or 'onlyoverall':" << "\n";
                std::cin >> choice;

                if (choice == "allgrades") {
                    Grade.printAssignment(null_string);
                    Grade.printOverall(null_string,0);
                }
                else if (choice == "allcategories") {
                    Grade.printCategory(null_string);
                    Grade.printOverall(null_string,0);
                }
                else if (choice == "onlyoverall") {
                    Grade.printOverall(null_string,0);
                }
            } else if (inp == "CHANGEGRADE") {
                std::cout << "Enter assignment name:";
                std::string assignment_name;
                std::cin >> assignment_name;
                std::cout << "Enter new grade in %:";
                int new_grade;
                std::cin >> new_grade;
                Grade.change_grade(assignment_name, new_grade);
                std::cout << "Reprint to see new grades" << "\n";
            } else if (inp == "QUIT") {
                boo = false;
            } else {
                std::cout << "Unable to read input, Try Again \n";
            }
        }
        else if (!out_bool) { //case if user wants file outputs
            //std::string out_file = "output.csv";

            if (inp == "ASSIGNMENT") {
                Grade.printAssignment(out_file);
            } else if (inp == "SEARCHASSIGNMENT"){
                std::string assign_name;
                std::cout << "Enter assignment name:" << "\n";
                std::cin >> assign_name;
                Grade.printIndividualAssignment(out_file, assign_name);
            } else if (inp == "CATEGORICAL" or inp == "CATEGORY") {
                Grade.printCategory(out_file);
            } else if (inp == "OVERALL") {
                std::string choice;
                std::cout << "Choose 'allgrades', 'allcategories', or 'onlyoverall':" << "\n";
                std::cin >> choice;
                //utilizes a condition to print out 3 possible choices onto file
                if (choice == "allgrades") {
                    int condition = 0;
                    Grade.printOverall(out_file, condition);
                }
                else if (choice == "allcategories") {
                    int condition = 1;
                    Grade.printOverall(out_file,condition);
                }
                else if (choice == "onlyoverall") {
                    int condition = 2;
                    Grade.printOverall(out_file, condition);
                }
            } else if (inp == "CHANGEGRADE") {
                std::cout << "Enter assignment name:";
                std::string assignment_name;
                std::cin >> assignment_name;
                std::cout << "Enter new grade in %:";
                int new_grade;
                std::cin >> new_grade;
                Grade.change_grade(assignment_name, new_grade);
                Grade.printGradeBook(file_name);
            } else if (inp == "QUIT") {
                boo = false;
            } else {
                std::cout << "Unable to read input, Try Again \n";
            }
        }
    }
}
