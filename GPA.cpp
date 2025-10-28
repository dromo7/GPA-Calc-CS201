#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
    bool programloop = true;
    cout << "Welcome to the GPA Calculator!" << endl;
    do {
        int amount;
        double gpa;
        char choice = ' ';

        double totalCredits = 0.0;
        double totalPoints = 0.0;
        string tmpStr;
        //double points = 0.0;
        //int totalCredits = 0;
        //int totalPoints = 0;

        cout << "Enter amount the number of courses you took: " << endl;
        cin >> amount;

        std::vector<string> class_names;
        string name;
    
        for (int i=0; i < amount; ++i) {
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

            double points = 0.0;
        
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