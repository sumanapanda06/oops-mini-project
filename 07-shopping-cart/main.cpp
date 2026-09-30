#include <iostream>
#include <string>
#include <iomanip>

#include "../student_info.h"

using namespace std;

// Product class
class Product
{
private:
    int productId;
    string productName;
    float price;

public:
    Product(int id = 0, string name = "", float p = 0)
    {
        productId = id;
        productName = name;
        price = p;
    }

    int getId()
    {
        return productId;
    }

    float getPrice()
    {
        return price;
    }

    // Operator overloading
    bool operator==(Product p)
    {
        return productId == p.productId;
    }

    // Friend function
    friend ostream& operator<<(ostream& out, Product p)
    {
        out << p.productId << "  "
            << p.productName << "  Rs." << p.price;

        return out;
    }
};

// Shopping Cart class
class ShoppingCart
{
private:
    Product products[10];
    int quantity[10];
    int count;

public:
    ShoppingCart()
    {
        count = 0;
    }

    void addProduct(Product p, int q)
    {
        products[count] = p;
        quantity[count] = q;
        count++;

        cout << "Product added to cart.\n";
    }

    void removeProduct(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (products[i].getId() == id)
            {
                for (int j = i; j < count - 1; j++)
                {
                    products[j] = products[j + 1];
                    quantity[j] = quantity[j + 1];
                }

                count--;

                cout << "Product removed from cart.\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    void changeQuantity(int id, int newQuantity)
    {
        for (int i = 0; i < count; i++)
        {
            if (products[i].getId() == id)
            {
                quantity[i] = newQuantity;

                cout << "Quantity updated.\n";
                return;
            }
        }

        cout << "Product not found.\n";
    }

    float calculateTotal()
    {
        float total = 0;

        for (int i = 0; i < count; i++)
        {
            total = total + products[i].getPrice() * quantity[i];
        }

        return total;
    }

    float applyDiscount(float discount)
    {
        float total = calculateTotal();

        float amount = total * discount / 100;

        return total - amount;
    }

    void displayCart()
    {
        cout << "\n========== SHOPPING CART ==========\n";

        for (int i = 0; i < count; i++)
        {
            cout << products[i]
                 << "  Quantity: " << quantity[i] << endl;
        }

        cout << "Cart Total : Rs."
             << calculateTotal() << endl;
    }
};

// Customer class
class Customer
{
private:
    string name;

    // Composition
    ShoppingCart cart;

public:
    Customer(string n)
    {
        name = n;
    }

    ShoppingCart& getCart()
    {
        return cart;
    }

    void displayCustomer()
    {
        cout << "Customer Name : " << name << endl;
    }
};

// Order class
class Order
{
private:
    int orderNumber;

    static int nextOrderNumber;

public:
    Order()
    {
        orderNumber = nextOrderNumber++;
    }

    void generateOrderSummary(Customer &customer)
    {
        cout << "\n========== ORDER SUMMARY ==========\n";

        customer.displayCustomer();

        customer.getCart().displayCart();

        cout << "Final Amount after 10% discount : Rs."
             << customer.getCart().applyDiscount(10) << endl;

        cout << "Order Number : " << orderNumber << endl;
    }
};

int Order::nextOrderNumber = 1001;

int main()
{
    cout << "E-COMMERCE SHOPPING CART\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    Customer customer("Sikhsha");

    Product p1(101, "Laptop", 50000);
    Product p2(102, "Mouse", 1000);
    Product p3(103, "Keyboard", 2000);

    customer.getCart().addProduct(p1, 1);
    customer.getCart().addProduct(p2, 2);
    customer.getCart().addProduct(p3, 1);

    customer.getCart().displayCart();

    cout << "\nChanging Mouse quantity...\n";
    customer.getCart().changeQuantity(102, 3);

    cout << "\nRemoving Keyboard...\n";
    customer.getCart().removeProduct(103);

    Order order;

    order.generateOrderSummary(customer);

    return 0;
}