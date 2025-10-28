GPA Calculator - README
========================

Author: Diego R., Ignacio B., Ali Z., Chengzhi Y.  
Course: CS 201  
Project: GPA Calculator

Description:
------------
This program calculates your GPA based on the grades and credits of your courses. It supports plus/minus grading and lets you repeat the calculation as needed.

Requirements:
-------------
To run this program, you need:
- A C++ compiler (such as g++)
- No additional software packages are required

Installation:
-------------
If you don't already have a C++ compiler:
- On Windows: Install [MinGW](https://www.mingw-w64.org/)
- On Mac: Use Xcode or install g++ via Homebrew (`brew install gcc`)
- On Linux: Use your package manager (`sudo apt install g++`)

How to Compile:
---------------
Open a terminal or command prompt and run:

    g++ -o gpa_calculator gpa_calculator.cpp

This will create an executable file named `gpa_calculator`.

How to Run:
-----------
After compiling, run the program:

    ./gpa_calculator   (Mac/Linux)
    gpa_calculator.exe (Windows)

Usage:
------
1. Enter the number of courses you took.
2. For each course, enter:
   - Course name
   - Grade (A-F, optional + or -)
   - Credits (whole numbers only)
3. The program will calculate and display your GPA.
4. You can choose to calculate again or exit.

Example:
--------
Welcome to the GPA Calculator!  
Enter number of courses: 2  
Course 1 name: Math  
Grade: A  
Credits: 3  
...  
Your GPA is: 4.00

# GPA-Calc-CS201