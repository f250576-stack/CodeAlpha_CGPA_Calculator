#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;

    cout << "Enter number of courses: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of courses!" << endl;
        return 0;
    }

    float grade[100] = { 0 };
    float  credit[100] = { 0 };
    float totalCredits = 0;
    float totalGradePoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter grade (0.0 - 4.0): ";
        cin >> grade[i];

        if (grade[i] < 0 || grade[i] > 4) {
            cout << "Invalid grade! Try again.\n";
            i--;
            continue;
        }

        cout << "Enter credit hours (>0): ";
        cin >> credit[i];

        if (credit[i] <= 0) {
            cout << "Invalid credit hours! Try again.\n";
            i--;
            continue;
        }

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    float cgpa = totalGradePoints / totalCredits;
    cout << fixed << setprecision(2);
    cout << "\n------ Course Details ------" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Course " << i + 1
            << " -> Grade: " << grade[i]
            << ", Credits: " << credit[i] << endl;
    }

    cout << "\n------ Result ------" << endl;
    cout << "Total Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << cgpa << endl;
    system("pause");
    return 0;
}
