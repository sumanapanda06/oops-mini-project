#include <iostream>
#include <string>

#include "../student_info.h"

using namespace std;

// Base exception class
class WalletException
{
public:
    virtual void message()
    {
        cout << "Wallet error occurred." << endl;
    }
};

// Derived exception classes
class InsufficientBalance : public WalletException
{
public:
    void message()
    {
        cout << "Error: Insufficient balance." << endl;
    }
};

class InvalidAmount : public WalletException
{
public:
    void message()
    {
        cout << "Error: Invalid transaction amount." << endl;
    }
};

class InvalidAccount : public WalletException
{
public:
    void message()
    {
        cout << "Error: Invalid account." << endl;
    }
};

class TransactionLimitExceeded : public WalletException
{
public:
    void message()
    {
        cout << "Error: Transaction limit exceeded." << endl;
    }
};

// Digital Wallet class
class Wallet
{
private:
    string owner;
    float balance;
    float transactionLimit;

    string history[10];
    int historyCount;

public:

    Wallet(string name, float amount)
    {
        owner = name;
        balance = amount;
        transactionLimit = 10000;
        historyCount = 0;

        history[historyCount] = "Wallet created";
        historyCount++;
    }

    void addMoney(float amount)
    {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > transactionLimit)
            throw TransactionLimitExceeded();

        balance = balance + amount;

        history[historyCount] = "Money added";
        historyCount++;

        cout << "Money added successfully." << endl;
    }

    void makePayment(float amount)
    {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > transactionLimit)
            throw TransactionLimitExceeded();

        if (amount > balance)
            throw InsufficientBalance();

        balance = balance - amount;

        history[historyCount] = "Payment made";
        historyCount++;

        cout << "Payment successful." << endl;
    }

    void transfer(Wallet *receiver, float amount)
    {
        if (receiver == NULL)
            throw InvalidAccount();

        if (amount <= 0)
            throw InvalidAmount();

        if (amount > transactionLimit)
            throw TransactionLimitExceeded();

        if (amount > balance)
            throw InsufficientBalance();

        balance = balance - amount;
        receiver->balance = receiver->balance + amount;

        history[historyCount] = "Money transferred";
        historyCount++;

        receiver->history[receiver->historyCount] = "Money received";
        receiver->historyCount++;

        cout << "Transfer successful." << endl;
    }

    void refund(float amount)
    {
        if (amount <= 0)
            throw InvalidAmount();

        balance = balance + amount;

        history[historyCount] = "Refund received";
        historyCount++;

        cout << "Refund successful." << endl;
    }

    void display()
    {
        cout << "\n-----------------------------\n";
        cout << "Owner   : " << owner << endl;
        cout << "Balance : Rs. " << balance << endl;

        cout << "Transaction History:\n";

        for (int i = 0; i < historyCount; i++)
        {
            cout << history[i] << endl;
        }

        cout << "-----------------------------\n";
    }
};

int main()
{
    cout << "DIGITAL WALLET AND PAYMENT SYSTEM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    Wallet wallet1("Sikhsha", 5000);
    Wallet wallet2("Rahul", 3000);

    try
    {
        wallet1.addMoney(2000);
        wallet1.makePayment(1000);
        wallet1.transfer(&wallet2, 1500);
        wallet1.refund(500);
    }
    catch (WalletException &e)
    {
        e.message();
    }

    cout << "\nTesting invalid transactions:\n";

    try
    {
        wallet1.makePayment(20000);
    }
    catch (WalletException &e)
    {
        e.message();
    }

    try
    {
        wallet1.makePayment(-500);
    }
    catch (WalletException &e)
    {
        e.message();
    }

    try
    {
        wallet1.transfer(NULL, 500);
    }
    catch (WalletException &e)
    {
        e.message();
    }

    try
    {
        wallet1.makePayment(100000);
    }
    catch (WalletException &e)
    {
        e.message();
    }

    cout << "\n========== WALLET DETAILS ==========\n";

    wallet1.display();
    wallet2.display();

    return 0;
}