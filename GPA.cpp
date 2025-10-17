#include <iostream>
#include <string>
using namespace std;

int main() {
    int amount;
    double gpa;

    double totalCredits = 0.0;
    double totalPoints = 0.0;

    double points = 0.0;
    //int totalCredits = 0;
    //int totalPoints = 0;

    cout << "Enter amount of courses: " << endl;
    cin >> amount;

    for (int i=0; i < amount; ++i) {
        char grade;
        int credits;

        cout << "Enter grade received for Course " << i+1 << "(A-F): " << endl;
        cin >> grade;
        cout << "Enter credits received: " << endl;
        cin >> credits;

        // Validate credits (cannot be negative)
        if (credits < 0) {
            cout << "Invalid credits entered. Credits cannot be negative." << endl;
            return 0;
        }

        // Validate grade (only A-F allowed)
        if (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'F') {
            cout << "Invalid grade entered. Only A-F grades are allowed." << endl;
            return 0;
        }

        double points = 0.0;
        
        if (grade == 'A') {
            points = 4.0;
        } else if (grade == 'B') {
            points = 3.0;
        } else if (grade == 'C') {
            points = 2.0;
        } else if (grade == 'D') {
            points = 1.0;
        } else if (grade == 'F') {
            points = 0.0;
        }

        totalPoints += credits * points;
        totalCredits += credits;
    }
    
    // Calculate and display GPA
    if (totalCredits > 0) {
        gpa = totalPoints / totalCredits;
        cout << "Your GPA is: " << gpa << endl;
    } else {
        cout << "No valid courses entered." << endl;
    }
    
    return 0;
}