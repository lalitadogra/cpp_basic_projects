#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Class to represent a student
class Student
{
private:
    string name;
    int rollNumber;
    float marks[5]; // Assuming 5 subjects

public:
    // Function to input student details
    void inputDetails()
    {
        cout << "Enter student name: ";
        getline(cin >> ws, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks for 5 subjects:" << endl;
        for (int i = 0; i < 5; ++i)
        {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    // Function to calculate total marks
    float calculateTotalMarks()
    {
        float totalMarks = 0;
        for (int i = 0; i < 5; ++i)
        {
            totalMarks += marks[i];
        }
        return totalMarks;
    }

    // Function to calculate percentage
    float calculatePercentage()
    {
        return (calculateTotalMarks() / 5);
    }

    // Function to calculate grade
    char calculateGrade()
    {
        float percentage = calculatePercentage();
        if (percentage >= 90)
        {
            return 'A';
        }
        else if (percentage >= 80)
        {
            return 'B';
        }
        else if (percentage >= 70)
        {
            return 'C';
        }
        else if (percentage >= 60)
        {
            return 'D';
        }
        else
        {
            return 'F';
        }
    }

    // Function to display student details and grade
    void displayReportCard()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks:" << endl;
        for (int i = 0; i < 5; ++i)
        {
            cout << "Subject " << (i + 1) << ": " << marks[i] << endl;
        }
        cout << "Total Marks: " << calculateTotalMarks() << endl;
        cout << "Percentage: " << fixed << setprecision(2) << calculatePercentage() << "%" << endl;
        cout << "Grade: " << calculateGrade() << endl;
    }
};

int main()
{
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore(); // Clear input buffer

    Student *students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i)
    {
        cout << "\nEnter details for Student " << (i + 1) << ":" << endl;
        students[i].inputDetails();
    }

    cout << "\nReport Cards:" << endl;
    for (int i = 0; i < numStudents; ++i)
    {
        cout << "\nReport Card for Student " << (i + 1) << ":" << endl;
        students[i].displayReportCard();
    }

    delete[] students; // Free memory allocated for students array

    return 0;
}
