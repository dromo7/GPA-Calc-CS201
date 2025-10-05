#include <iostream>
#include <string>
using namespace std;

int main() {
    int amount;
    double gpa;
    double totalCredits = 0.0;
    double totalPoints = 0.0;

    cout << "Enter amount of courses: " << endl;
    cin >> amount;

    for (int i=0; i < amount; ++i) {
        char grade;
        int credits;

        cout << "Enter grade received for Course " << i+1 << "(A-F): " << endl;
        cin >> grade;
        cout << "Enter credits received: " << endl;
        cin >> credits;

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