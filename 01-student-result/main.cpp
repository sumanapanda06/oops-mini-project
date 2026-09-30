#include <iostream>
using namespace std;

#include "../student_info.h"

class Student
{
private:
    int rollNumber;
    string name;
    int marks[5];

public:

    Student()
    {
        rollNumber = 0;
        name = "";

        for (int i = 0; i < 5; i++)
        {
            marks[i] = 0;
        }
    }

    void input()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Roll Number: ";
        cin >> rollNumber;

        cout << "Enter marks of 5 subjects:\n";

        for (int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }

    bool validateMarks()
    {
        for (int i = 0; i < 5; i++)
        {
            if (marks[i] < 0 || marks[i] > 100)
            {
                return false;
            }
        }

        return true;
    }

    int calculateTotal()
    {
        int total = 0;

        for (int i = 0; i < 5; i++)
        {
            total = total + marks[i];
        }

        return total;
    }

    float calculatePercentage()
    {
        return calculateTotal() / 5.0;
    }

    char calculateGrade()
    {
        float percentage = calculatePercentage();

        if (percentage >= 90)
            return 'S';
        else if (percentage >= 80)
            return 'A';
        else if (percentage >= 70)
            return 'B';
        else if (percentage >= 60)
            return 'C';
        else if (percentage >= 50)
            return 'D';
        else
            return 'F';
    }

    bool isPassed()
    {
        if (calculatePercentage() >= 40)
            return true;
        else
            return false;
    }

    void display()
    {
        cout << "\n-----------------------------\n";
        cout << "Name       : " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;

        cout << "Marks      : ";

        for (int i = 0; i < 5; i++)
        {
            cout << marks[i] << " ";
        }

        cout << endl;

        cout << "Total      : " << calculateTotal() << endl;
        cout << "Percentage : " << calculatePercentage() << "%" << endl;
        cout << "Grade      : " << calculateGrade() << endl;

        if (isPassed())
            cout << "Status     : PASS" << endl;
        else
            cout << "Status     : FAIL" << endl;

        cout << "-----------------------------\n";
    }
};

int main()
{
    cout << "STUDENT RESULT MANAGEMENT SYSTEM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    int n;

    cout << "\nEnter number of students: ";
    cin >> n;

    Student students[10];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of Student " << i + 1 << ":\n";

        students[i].input();

        if (students[i].validateMarks() == false)
        {
            cout << "Invalid marks entered!\n";
        }
    }

    cout << "\n========== RESULT ==========\n";

    for (int i = 0; i < n; i++)
    {
        if (students[i].validateMarks())
        {
            students[i].display();
        }
    }

    return 0;
}