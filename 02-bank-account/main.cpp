#include <iostream>
#include <string>

#include "../student_info.h"

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string name;
    float balance;

    string transactions[10];
    int transactionCount;

    static int nextAccountNumber;

public:

    // Constructor
    BankAccount(string n, float amount)
    {
        accountNumber = nextAccountNumber++;
        name = n;
        balance = 0;
        transactionCount = 0;

        if (amount >= 0)
        {
            balance = amount;
            transactions[transactionCount] = "Account created";
            transactionCount++;
        }
    }

    void deposit(float amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit amount\n";
            return;
        }

        balance = balance + amount;

        transactions[transactionCount] = "Deposit";
        transactionCount++;

        cout << "Deposit successful\n";
    }

    void withdraw(float amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdrawal amount\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance\n";
            return;
        }

        balance = balance - amount;

        transactions[transactionCount] = "Withdrawal";
        transactionCount++;

        cout << "Withdrawal successful\n";
    }

    void transfer(BankAccount &receiver, float amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid transfer amount\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance for transfer\n";
            return;
        }

        balance = balance - amount;
        receiver.balance = receiver.balance + amount;

        transactions[transactionCount] = "Transfer sent";
        transactionCount++;

        receiver.transactions[receiver.transactionCount] = "Transfer received";
        receiver.transactionCount++;

        cout << "Transfer successful\n";
    }

    void display()
    {
        cout << "\n-----------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Name           : " << name << endl;
        cout << "Balance        : Rs. " << balance << endl;

        cout << "Transaction History:\n";

        for (int i = 0; i < transactionCount; i++)
        {
            cout << transactions[i] << endl;
        }

        cout << "-----------------------------\n";
    }
};

int BankAccount::nextAccountNumber = 1001;

int main()
{
    cout << "SECURE BANK ACCOUNT MANAGEMENT SYSTEM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    BankAccount account1("Rahul", 5000);
    BankAccount account2("Ananya", 3000);

    cout << "\nInitial Account Details:";
    account1.display();
    account2.display();

    cout << "\nPerforming transactions...\n";

    account1.deposit(1000);
    account1.withdraw(500);
    account1.transfer(account2, 1500);

    // Invalid transaction
    account1.withdraw(10000);

    cout << "\nFinal Account Details:";
    account1.display();
    account2.display();

    return 0;
}