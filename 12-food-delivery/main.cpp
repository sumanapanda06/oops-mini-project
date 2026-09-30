#include <iostream>
#include <vector>
#include <string>

#include "../student_info.h"

using namespace std;

// Function template to find maximum
template <class T>
T findMaximum(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

// Class template
template <class T>
class FoodBox
{
private:
    T items[5];
    int count;

public:
    FoodBox()
    {
        count = 0;
    }

    void addItem(T item)
    {
        if (count < 5)
        {
            items[count] = item;
            count++;
        }
    }

    void displayItems()
    {
        for (int i = 0; i < count; i++)
        {
            cout << items[i] << endl;
        }
    }
};

// Food class
class Food
{
private:
    string name;
    float price;

public:
    Food(string n = "", float p = 0)
    {
        name = n;
        price = p;
    }

    float getPrice()
    {
        return price;
    }

    void display()
    {
        cout << name << " - Rs. " << price << endl;
    }
};

int main()
{
    cout << "GENERIC FOOD DELIVERY PLATFORM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    // Class template with integers
    FoodBox<int> foodPrices;

    foodPrices.addItem(250);
    foodPrices.addItem(180);
    foodPrices.addItem(320);

    cout << "\nFood Prices:\n";
    foodPrices.displayItems();

    // Class template with strings
    FoodBox<string> foodNames;

    foodNames.addItem("Pizza");
    foodNames.addItem("Burger");
    foodNames.addItem("Pasta");

    cout << "\nFood Names:\n";
    foodNames.displayItems();

    // Function template
    cout << "\nMaximum Price: "
         << findMaximum(250, 320) << endl;

    cout << "Maximum Rating: "
         << findMaximum(4.2, 4.8) << endl;

    // STL container
    vector<Food> menu(3);

    menu[0] = Food("Pizza", 250);
    menu[1] = Food("Burger", 180);
    menu[2] = Food("Pasta", 320);

    cout << "\n========== MENU ==========\n";

    for (int i = 0; i < 3; i++)
    {
        menu[i].display();
    }

    return 0;
}