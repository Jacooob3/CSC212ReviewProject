# CSC212ReviewProject

Summary : 
  This is a gradebook program where the user will create a csv file before running the program, divided by the assignment name, category and grade in that order, and the program will ask the user for input of the csv file name. The program will then ask the user different choices on whether they would like to view their grades individually, categorically, or overall grade. The program will stop when the user inputs quit, if not it will continue to ask for choices.
  
Planning: 
  For the planning we all met up and created a flow chart (flowchart.jpg) where we planned how the program would run, what libraries we would need, resources we would need, and how the csv file would be organized. We then wrote out a pseudocode(pseudocode in github) for a basic foundation for our program. We create basic functions or methods and instructions underneath each to explain what each would do to contribute to the program.

Compilation Instructions:
  For compilation, you will require main.cpp, Gradebook.cpp, Gradebook.h and a csv file named anything. They should all be in the same directory when compiling and the csv file should be formatted Assignment Name, Category Name, and points earned for each line.

Runtime Instructions:
  During runtime, the program will first ask for a file name. It will then search the directory you are currently in and search for the given file (you have to include .csv at the end of the name). If it is not able to find it, it will ask again just in case you might have incorrectly typed it in. Then, the program will give you a list of choices where you can view your grades individually, categorically, overall, or you can quit the program. If user chooses individually, then it will output the correct grades and names in the terminal and ask for more input again, up until the user inputs quit or if the user force quits.

Sample input/output screenshots with brief explanations of the images used:
  
