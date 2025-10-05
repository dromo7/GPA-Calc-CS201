#include <iostream>
#include <string>
using namespace std;

int main() {
    int amount;
    double gpa;

    cout << "Enter amount of courses: " << endl;
    cin >> amount;

    for (int i=0; i < amountl ++i) {
        string course;
        char grade;
        int credits;
        cout << "Enter course name: " << endl;  
        cin >> course;
        cout << "Enter grade received(A-F): " << endl;
        cin >> grade;
        cout << "Enter credits received: " << endl;
        cin >> credits;

        double points = 0.0;
        int totalCredits = 0;
        int totalPoints = 0;
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
        } else {
            cout << "Invalid grade entered." << endl;
            continue;
        }

        totalPoints += credits * points;
        totalCredits += credits;
        
    }
    gpa = totalPoints / totalCredits;
    cout << "Your GPA is: " << gpa << endl;
    return 0;
}