# CSC212ReviewProject

Summary : 
  This is a gradebook program where the user will create a csv file before running the program, divided by the assignment name, category and grade in that order, and the program will ask the user for input of the csv file name. The program will then ask the user different choices on whether they would like to view their grades individually, categorically, or overall grade or if they want to change or add grades and they can either do this through the terminal or through an output file. The program will stop when the user inputs quit, if not it will continue to ask for choices.
  
Planning: 
  For the planning we all met up and created a flow chart (flowchart.jpg) where we planned how the program would run, what libraries we would need, resources we would need, and how the csv file would be organized. We then wrote out a pseudocode(pseudocode in github) for a basic foundation for our program. We create basic functions or methods and instructions underneath each to explain what each would do to contribute to the program.

Compilation Instructions:
  For compilation, you will require main.cpp, Gradebook.cpp, Gradebook.h and a csv file named anything. They should all be in the same directory when compiling and the csv file should be formatted Assignment Name, Category Name(specifically formatted like this "Lab" or "Project1" no spaces and first letter of the word capitalized), and Grade(out of 100) for each line.

Runtime Instructions:
  During runtime, the program will first ask for a file name. It will then search the directory you are currently in and search for the given file (you have to include .csv at the end of the name). If it is not able to find it, it will ask again just in case you might have incorrectly typed it in. Then the program will ask if you would like to view your grades through the terminal or output it to a file. Then, the program will give you a list of choices where you can view your grades individually, categorically, overall, add or change your grades, print your grades or you can quit the program. Depending on the choice the user made on the ouput, the program will either print your output onto the file or the terminal and would add or change your grades directly to your input file.

Sample input/output screenshots with brief explanations of the images used:

![1](https://github.com/Jacooob3/CSC212ReviewProject/blob/main/Proj1.PNG?raw=true)
![2](https://github.com/Jacooob3/CSC212ReviewProject/blob/main/Proj2.PNG?raw=true)
![3](https://github.com/Jacooob3/CSC212ReviewProject/blob/main/Proj3.PNG?raw=true)
![4](https://github.com/Jacooob3/CSC212ReviewProject/blob/main/Proj4.PNG?raw=true)
