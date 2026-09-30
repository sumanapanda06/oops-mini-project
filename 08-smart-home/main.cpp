#include <iostream>
#include <string>

#include "../student_info.h"

using namespace std;

// Abstract base class
class Device
{
protected:
    string name;
    bool status;

public:
    Device(string n)
    {
        name = n;
        status = false;
    }

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void display() = 0;

    void showStatus()
    {
        if (status)
            cout << "Status : ON" << endl;
        else
            cout << "Status : OFF" << endl;
    }
};

// Light
class Light : public Device
{
private:
    int brightness;

public:
    Light(string n, int b)
        : Device(n)
    {
        brightness = b;
    }

    void turnOn()
    {
        status = true;
        cout << name << " turned ON" << endl;
    }

    void turnOff()
    {
        status = false;
        cout << name << " turned OFF" << endl;
    }

    void display()
    {
        cout << "\nDevice : " << name << endl;
        cout << "Type   : Light" << endl;
        cout << "Brightness : " << brightness << "%" << endl;
        showStatus();
    }
};

// Fan
class Fan : public Device
{
private:
    int speed;

public:
    Fan(string n, int s)
        : Device(n)
    {
        speed = s;
    }

    void turnOn()
    {
        status = true;
        cout << name << " turned ON" << endl;
    }

    void turnOff()
    {
        status = false;
        cout << name << " turned OFF" << endl;
    }

    void display()
    {
        cout << "\nDevice : " << name << endl;
        cout << "Type   : Fan" << endl;
        cout << "Speed  : " << speed << endl;
        showStatus();
    }
};

// Air Conditioner
class AirConditioner : public Device
{
private:
    int temperature;

public:
    AirConditioner(string n, int t)
        : Device(n)
    {
        temperature = t;
    }

    void turnOn()
    {
        status = true;
        cout << name << " turned ON" << endl;
    }

    void turnOff()
    {
        status = false;
        cout << name << " turned OFF" << endl;
    }

    void display()
    {
        cout << "\nDevice : " << name << endl;
        cout << "Type   : Air Conditioner" << endl;
        cout << "Temperature : " << temperature << " C" << endl;
        showStatus();
    }
};

int main()
{
    cout << "SMART HOME AUTOMATION SYSTEM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    // Dynamic objects
    Device *devices[3];

    devices[0] = new Light("Living Room Light", 80);
    devices[1] = new Fan("Bedroom Fan", 3);
    devices[2] = new AirConditioner("Bedroom AC", 24);

    cout << "\n========== DEVICE DETAILS ==========\n";

    for (int i = 0; i < 3; i++)
    {
        devices[i]->display();
    }

    cout << "\n========== ACTIVATING DEVICES ==========\n";

    for (int i = 0; i < 3; i++)
    {
        devices[i]->turnOn();
    }

    cout << "\n========== UPDATED STATUS ==========\n";

    for (int i = 0; i < 3; i++)
    {
        devices[i]->showStatus();
    }

    cout << "\nTurning off Bedroom Fan...\n";
    devices[1]->turnOff();

    cout << "\n========== FINAL STATUS ==========\n";

    for (int i = 0; i < 3; i++)
    {
        devices[i]->display();
    }

    // Delete dynamic objects
    for (int i = 0; i < 3; i++)
    {
        delete devices[i];
    }

    return 0;
}