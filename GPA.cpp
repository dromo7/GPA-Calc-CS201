#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    bool programloop = true;
    cout << "Welcome to the GPA Calculator!" << endl;
    cout << "------------------------------" << endl;
    do {
        int amount;
        double gpa;
        char choice = ' ';

        double totalCredits = 0.0;
        double totalPoints = 0.0;
        string tmpStr;

        std::vector<string> class_names;
        std::vector<char> grades_list;
        std::vector<char> plus_minus_list;
        std::vector<int> credits_list;
        string name;
        
        // Ask if user wants to load from file
        char loadChoice;
        cout << "Would you like to load courses from a file? (Y/N): ";
        cin >> loadChoice;
        
        if (toupper(loadChoice) == 'Y') {
            string filename;
            cout << "Enter filename: ";
            cin.ignore();
            getline(cin, filename);
            
            ifstream inFile(filename);
            if (inFile) {
                int numCourses;
                inFile >> numCourses;
                inFile.ignore();
                
                for (int i = 0; i < numCourses; ++i) {
                    string courseName;
                    char grade, plus_minus;
                    int credits;
                    
                    getline(inFile, courseName);
                    inFile >> grade >> plus_minus >> credits;
                    inFile.ignore();
                    
                    class_names.push_back(courseName);
                    grades_list.push_back(grade);
                    plus_minus_list.push_back(plus_minus);
                    credits_list.push_back(credits);
                }
                inFile.close();
                cout << "Courses loaded successfully!" << endl;
                amount = class_names.size();
            } else {
                cout << "Error: Could not open file." << endl;
                amount = 0;
            }
        }
        
        // If no courses loaded, ask how many to enter
        if (class_names.empty()) {
            cout << "Enter amount the number of courses you took: " << endl;
            cin >> amount;
        }
    
        for (int i = class_names.size(); i < amount; ++i) {
            char grade;
            char plus_minus;
            int credits;
        
            //Reads Course Names from User & puts it into vector
            cout << "Enter name for Course " << i+1 << ": ";
            getline(cin,tmpStr);
            getline(cin, name);
            class_names.push_back(name);

            cout << "Enter grade received for Course " << i+1 << "(A-F, +/- allowed but optional): " << endl;
            cin >> grade;
            grade = toupper(grade);
            cin.get(plus_minus);

            // Validate grade (only A-F allowed)
            if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'F') {
                cout << "Invalid grade entered. Only A-F grades are allowed." << endl;
                return 0;
            }

            // Validate +/- (check for other symbols)
            if (plus_minus != '\n' && plus_minus != ' ' && plus_minus != '+' && plus_minus != '-'){
                cout << "Invalid symbol entered. Only +/- or whitespace is allowed." << endl;
                return 0;
            }

            cout << "Enter credits received (Whole numbers only): " << endl;
            cin >> credits;

            // Validate credits (cannot be negative)
            if (credits < 0) {
                cout << "Invalid credits entered. Credits cannot be negative." << endl;
                return 0;
            }
            
            grades_list.push_back(grade);
            plus_minus_list.push_back(plus_minus);
            credits_list.push_back(credits);
        }
        
        // Menu for editing/managing courses before calculating
        bool editMenu = true;
        while (editMenu && !class_names.empty()) {
            // Display all courses
            cout << "\n--- Current Courses ---" << endl;
            for (size_t i = 0; i < class_names.size(); ++i) {
                cout << i + 1 << ". " << class_names[i] 
                     << " | Grade: " << grades_list[i] << plus_minus_list[i]
                     << " | Credits: " << credits_list[i] << endl;
            }
            cout << "-----------------------\n" << endl;
            
            cout << "What would you like to do?" << endl;
            cout << "1. Calculate GPA" << endl;
            cout << "2. Add a course" << endl;
            cout << "3. Edit a course" << endl;
            cout << "4. Remove a course" << endl;
            cout << "5. Save courses to file" << endl;
            cout << "Enter your choice: ";
            
            int menuChoice;
            cin >> menuChoice;
            
            if (menuChoice == 1) {
                // Exit menu and calculate GPA
                editMenu = false;
            } 
            else if (menuChoice == 2) {
                // Add a new course
                char grade;
                char plus_minus;
                int credits;
                
                cout << "Enter name for new course: ";
                cin.ignore();
                getline(cin, name);
                class_names.push_back(name);

                cout << "Enter grade received (A-F, +/- allowed but optional): " << endl;
                cin >> grade;
                grade = toupper(grade);
                cin.get(plus_minus);

                // Validate grade (only A-F allowed)
                if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'F') {
                    cout << "Invalid grade entered. Course not added." << endl;
                    class_names.pop_back();
                    continue;
                }

                // Validate +/- (check for other symbols)
                if (plus_minus != '\n' && plus_minus != ' ' && plus_minus != '+' && plus_minus != '-'){
                    cout << "Invalid symbol entered. Course not added." << endl;
                    class_names.pop_back();
                    continue;
                }

                cout << "Enter credits received (Whole numbers only): " << endl;
                cin >> credits;

                // Validate credits (cannot be negative)
                if (credits < 0) {
                    cout << "Invalid credits entered. Course not added." << endl;
                    class_names.pop_back();
                    continue;
                }
                
                grades_list.push_back(grade);
                plus_minus_list.push_back(plus_minus);
                credits_list.push_back(credits);
                
                cout << "Course added successfully!" << endl;
            } 
            else if (menuChoice == 3) {
                // Edit a course
                int courseNum;
                cout << "Enter course number to edit (1-" << class_names.size() << "): ";
                cin >> courseNum;
                
                if (courseNum >= 1 && courseNum <= static_cast<int>(class_names.size())) {
                    int index = courseNum - 1;
                    
                    cout << "Editing: " << class_names[index] << endl;
                    
                    // Edit name
                    cout << "Enter new name (or press Enter to keep current): ";
                    cin.ignore();
                    getline(cin, tmpStr);
                    if (!tmpStr.empty()) {
                        class_names[index] = tmpStr;
                    }
                    
                    // Edit grade
                    cout << "Enter new grade (or press Enter to keep current): ";
                    char newGrade;
                    cin.get(newGrade);
                    if (newGrade != '\n') {
                        grades_list[index] = toupper(newGrade);
                        
                        char newPlusMinus;
                        cin.get(newPlusMinus);
                        if (newPlusMinus == '+' || newPlusMinus == '-') {
                            plus_minus_list[index] = newPlusMinus;
                        } else {
                            plus_minus_list[index] = ' ';
                        }
                    }
                    cin.ignore(1000, '\n');
                    
                    // Edit credits
                    cout << "Enter new credits (or -1 to keep current): ";
                    int newCredits;
                    cin >> newCredits;
                    if (newCredits >= 0) {
                        credits_list[index] = newCredits;
                    }
                    
                    cout << "Course updated successfully!" << endl;
                } else {
                    cout << "Invalid course number." << endl;
                }
            } 
            else if (menuChoice == 4) {
                // Remove a course
                int courseNum;
                cout << "Enter course number to remove (1-" << class_names.size() << "): ";
                cin >> courseNum;
                
                if (courseNum >= 1 && courseNum <= static_cast<int>(class_names.size())) {
                    int index = courseNum - 1;
                    class_names.erase(class_names.begin() + index);
                    grades_list.erase(grades_list.begin() + index);
                    plus_minus_list.erase(plus_minus_list.begin() + index);
                    credits_list.erase(credits_list.begin() + index);
                    cout << "Course removed successfully!" << endl;
                } else {
                    cout << "Invalid course number." << endl;
                }
            } 
            else if (menuChoice == 5) {
                // Save to file
                string filename;
                cout << "Enter filename to save: ";
                cin.ignore();
                getline(cin, filename);
                
                ofstream outFile(filename);
                if (outFile) {
                    outFile << class_names.size() << endl;
                    for (size_t i = 0; i < class_names.size(); ++i) {
                        outFile << class_names[i] << endl;
                        outFile << grades_list[i] << endl;
                        outFile << plus_minus_list[i] << endl;
                        outFile << credits_list[i] << endl;
                    }
                    outFile.close();
                    cout << "Courses saved successfully to " << filename << endl;
                } else {
                    cout << "Error: Could not create file." << endl;
                }
            } 
            else {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    
        // Calculate and display GPA
        for (size_t i = 0; i < class_names.size(); ++i) {
            double points = 0.0;
            char grade = grades_list[i];
            char plus_minus = plus_minus_list[i];
            int credits = credits_list[i];
        
            if (grade == 'A' || grade == 'a') {
                points = 4.0;
            } else if (grade == 'B' || grade == 'b') {
                points = 3.0;
            } else if (grade == 'C' || grade == 'c') {
                points = 2.0;
            } else if (grade == 'D' || grade == 'd') {
                points = 1.0;
            } else if (grade == 'F' || grade == 'f') {
                points = 0.0;
            }

            if (plus_minus == '+'){
                points += 0.3;
            } else if(plus_minus == '-' && grade != 'D' && grade != 'F'){
                points -= 0.3;
            }

            totalPoints += credits * points;
            totalCredits += credits;
        }
    
        // Calculate and display GPA
        if (totalCredits > 0) {
            gpa = totalPoints / totalCredits;
            cout << "Your GPA is: " << fixed << setprecision(2) << gpa << endl;
        } else {
            cout << "No valid courses entered." << endl;
        }
        
        while (toupper(choice) != 'Y' && toupper(choice) != 'N'){
            cout << "Would you like to calculate a new GPA? (Enter Y for Yes| N for No)"<< endl;
            cin >> choice;
            if (toupper(choice) == 'N'){
                programloop = false;
            }
            else if (toupper(choice) == 'Y')
            {
                programloop = true;
            }
            else cout << "Not valid option." << endl;
        }
    } while (programloop);
    return 0;
}