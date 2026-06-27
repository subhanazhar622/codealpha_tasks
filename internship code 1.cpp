#include <iostream>
#include <string>
using namespace std;

int main() {
int numSemesters;
cout << "Enter number of semesters: ";
cin >> numSemesters;

float totalPoints = 0, totalCredits = 0;

for (int i = 0; i < numSemesters; i++) {
cout << "\n--- Semester " << i + 1 << " ---\n";

int numCourses;
cout << "Enter number of courses: ";
cin >> numCourses;

string courseNames[50];
float grades[50], credits[50];
float semPoints = 0, semCredits = 0;

for (int j = 0; j < numCourses; j++) {
cout << "\nCourse " << j + 1 << " name: ";
cin >> courseNames[j];
cout << "Grade (out of 4.0): ";
cin >> grades[j];
cout << "Credit hours: ";
cin >> credits[j];

semPoints += grades[j] * credits[j];
semCredits += credits[j];
}

float semGPA = semPoints / semCredits;
cout << "\nSemester " << i + 1 << " Results:\n";
for (int j = 0; j < numCourses; j++) {
cout << courseNames[j] << " -> Grade: " << grades[j]
<< ", Credits: " << credits[j] << "\n";
}
cout << "Semester GPA: " << semGPA << "\n";

totalPoints += semPoints;
totalCredits += semCredits;
}

float cgpa = totalPoints / totalCredits;
cout << "\n============================\n";
cout << "Overall CGPA: " << cgpa << "\n";
cout << "============================\n";

return 0;
}
