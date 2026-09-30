#include <iostream>
#include <string>

#include "../student_info.h"

using namespace std;

// Abstract Base Class
class Vehicle
{
protected:
    string vehicleNumber;
    string model;
    bool available;

public:
    Vehicle(string number, string m)
    {
        vehicleNumber = number;
        model = m;
        available = true;
    }

    virtual float calculateRent(int days) = 0;

    void rentVehicle()
    {
        if (available)
        {
            available = false;
            cout << "Vehicle rented successfully.\n";
        }
        else
        {
            cout << "Vehicle is not available.\n";
        }
    }

    void returnVehicle()
    {
        available = true;
        cout << "Vehicle returned successfully.\n";
    }

    void display()
    {
        cout << "Vehicle Number : " << vehicleNumber << endl;
        cout << "Model          : " << model << endl;

        if (available)
            cout << "Status         : Available" << endl;
        else
            cout << "Status         : Rented" << endl;
    }
};

// Car
class Car : public Vehicle
{
public:
    Car(string number, string m)
        : Vehicle(number, m)
    {
    }

    float calculateRent(int days)
    {
        return days * 1500;
    }
};

// Motorcycle
class Motorcycle : public Vehicle
{
public:
    Motorcycle(string number, string m)
        : Vehicle(number, m)
    {
    }

    float calculateRent(int days)
    {
        return days * 800;
    }
};

// Bus
class Bus : public Vehicle
{
public:
    Bus(string number, string m)
        : Vehicle(number, m)
    {
    }

    float calculateRent(int days)
    {
        return days * 3000;
    }
};

// Electric Vehicle
class ElectricVehicle : public Vehicle
{
public:
    ElectricVehicle(string number, string m)
        : Vehicle(number, m)
    {
    }

    float calculateRent(int days)
    {
        return days * 1200;
    }
};

int main()
{
    cout << "VEHICLE RENTAL MANAGEMENT SYSTEM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    Car car("CAR101", "Honda City");
    Motorcycle bike("BIKE201", "Yamaha");
    Bus bus("BUS301", "Volvo");
    ElectricVehicle ev("EV401", "Tata Nexon EV");

    Vehicle *vehicles[4];

    vehicles[0] = &car;
    vehicles[1] = &bike;
    vehicles[2] = &bus;
    vehicles[3] = &ev;

    int days = 3;

    cout << "\n========== VEHICLE DETAILS ==========\n";

    for (int i = 0; i < 4; i++)
    {
        cout << "\n-----------------------------\n";

        vehicles[i]->display();

        cout << "Rent for " << days << " days : Rs. "
             << vehicles[i]->calculateRent(days) << endl;
    }

    cout << "\nRenting Car...\n";
    car.rentVehicle();

    cout << "\nTrying to rent Car again...\n";
    car.rentVehicle();

    cout << "\nReturning Car...\n";
    car.returnVehicle();

    return 0;
}