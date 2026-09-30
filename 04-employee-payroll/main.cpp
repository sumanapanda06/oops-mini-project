#include <iostream>
#include <string>

#include "../student_info.h"

using namespace std;

// Base class
class Employee
{
protected:
    int id;
    string name;

public:
    Employee(int i, string n)
    {
        id = i;
        name = n;
    }

    virtual void calculateSalary() = 0;

    virtual void display()
    {
        cout << "Employee ID   : " << id << endl;
        cout << "Employee Name : " << name << endl;
    }
};

// Permanent Employee
class PermanentEmployee : public Employee
{
private:
    float basicSalary;
    float allowance;
    float deduction;

public:
    PermanentEmployee(int i, string n, float b, float a, float d)
        : Employee(i, n)
    {
        basicSalary = b;
        allowance = a;
        deduction = d;
    }

    void calculateSalary()
    {
        float grossSalary;
        float netSalary;

        grossSalary = basicSalary + allowance;
        netSalary = grossSalary - deduction;

        display();

        cout << "Employee Type : Permanent" << endl;
        cout << "Gross Salary  : " << grossSalary << endl;
        cout << "Deduction     : " << deduction << endl;
        cout << "Net Salary    : " << netSalary << endl;
    }
};

// Contract Employee
class ContractEmployee : public Employee
{
private:
    float hours;
    float hourlyRate;

public:
    ContractEmployee(int i, string n, float h, float r)
        : Employee(i, n)
    {
        hours = h;
        hourlyRate = r;
    }

    void calculateSalary()
    {
        float salary;

        salary = hours * hourlyRate;

        display();

        cout << "Employee Type : Contract" << endl;
        cout << "Gross Salary  : " << salary << endl;
        cout << "Deduction     : 0" << endl;
        cout << "Net Salary    : " << salary << endl;
    }
};

// Intern
class Intern : public Employee
{
private:
    float stipend;
    float deduction;

public:
    Intern(int i, string n, float s, float d)
        : Employee(i, n)
    {
        stipend = s;
        deduction = d;
    }

    void calculateSalary()
    {
        float salary;

        salary = stipend - deduction;

        display();

        cout << "Employee Type : Intern" << endl;
        cout << "Gross Salary  : " << stipend << endl;
        cout << "Deduction     : " << deduction << endl;
        cout << "Net Salary    : " << salary << endl;
    }
};

int main()
{
    cout << "EMPLOYEE PAYROLL MANAGEMENT SYSTEM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    PermanentEmployee p(101, "Rahul", 50000, 10000, 5000);
    ContractEmployee c(102, "Ananya", 160, 300);
    Intern i(103, "Sikhsha", 15000, 1000);

    Employee *employees[3];

    employees[0] = &p;
    employees[1] = &c;
    employees[2] = &i;

    cout << "\n========== PAYROLL REPORT ==========\n";

    for (int j = 0; j < 3; j++)
    {
        cout << "\n-----------------------------\n";
        employees[j]->calculateSalary();
        cout << "-----------------------------\n";
    }

    return 0;
}