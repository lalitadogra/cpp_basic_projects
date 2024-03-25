#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Class to represent a student
class Student
{
private:
    string username;
    string password;
    vector<string> attendanceHistory;

public:
    Student(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

    string getUsername() { return username; }
    string getPassword() { return password; }

    // Method to mark attendance for the current date
    void markAttendance()
    {
        time_t now = time(0);
        tm *current_time = localtime(&now);
        string date = to_string(current_time->tm_mday) + "/" + to_string(current_time->tm_mon + 1) + "/" + to_string(current_time->tm_year + 1900);
        attendanceHistory.push_back(date);
        cout << "Attendance marked for " << date << endl;
    }

    // Method to display attendance history
    void displayAttendanceHistory()
    {
        cout << "Attendance History:" << endl;
        for (const auto &date : attendanceHistory)
        {
            cout << date << endl;
        }
    }
};

// Function to check if username and password match admin credentials
bool isAdmin(string username, string password)
{
    return (username == "admin" && password == "admin@2");
}

int main()
{
    vector<Student> students;
    string adminUsername = "admin";
    string adminPassword = "admin@2";
    string username, password;
    int choice;

    // Admin authentication
    cout << "Enter admin username: ";
    cin >> username;
    cout << "Enter admin password: ";
    cin >> password;

    if (!isAdmin(username, password))
    {
        cout << "Invalid admin credentials. Exiting program." << endl;
        return 0;
    }

    while (true)
    {
        cout << "\nAttendance Management System" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Student Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter student username: ";
            cin >> username;
            cout << "Enter student password: ";
            cin >> password;
            students.push_back(Student(username, password));
            cout << "Student registered successfully." << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter student username: ";
            cin >> username;
            cout << "Enter student password: ";
            cin >> password;
            bool found = false;
            for (auto &student : students)
            {
                if (student.getUsername() == username && student.getPassword() == password)
                {
                    found = true;
                    int subChoice;
                    cout << "1. Mark Attendance" << endl;
                    cout << "2. View Attendance History" << endl;
                    cout << "Enter your choice: ";
                    cin >> subChoice;
                    if (subChoice == 1)
                    {
                        student.markAttendance();
                    }
                    else if (subChoice == 2)
                    {
                        student.displayAttendanceHistory();
                    }
                    else
                    {
                        cout << "Invalid choice." << endl;
                    }
                    break;
                }
            }
            if (!found)
            {
                cout << "Invalid username or password." << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting program. Thank you!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
