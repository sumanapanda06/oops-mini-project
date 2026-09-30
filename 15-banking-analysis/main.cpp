#include <iostream>
#include <string>
#include <vector>

#include "../student_info.h"

using namespace std;

// Base exception class
class TransactionException
{
public:
    virtual void message()
    {
        cout << "Transaction error occurred." << endl;
    }
};

// Derived exception
class InvalidTransaction : public TransactionException
{
public:
    void message()
    {
        cout << "Error: Invalid transaction." << endl;
    }
};

class InsufficientBalance : public TransactionException
{
public:
    void message()
    {
        cout << "Error: Insufficient balance." << endl;
    }
};

class TransactionLimit : public TransactionException
{
public:
    void message()
    {
        cout << "Error: Transaction limit exceeded." << endl;
    }
};

// Abstract base class
class Transaction
{
protected:
    int transactionId;
    float amount;

public:

    Transaction(int id, float a)
    {
        transactionId = id;
        amount = a;
    }

    virtual void process() = 0;

    virtual void display()
    {
        cout << "Transaction ID : " << transactionId << endl;
        cout << "Amount         : Rs. " << amount << endl;
    }
};

// ATM Withdrawal
class ATMWithdrawal : public Transaction
{
private:
    float balance;

public:

    ATMWithdrawal(int id, float a, float b)
        : Transaction(id, a)
    {
        balance = b;
    }

    void process()
    {
        if (amount <= 0)
            throw InvalidTransaction();

        if (amount > balance)
            throw InsufficientBalance();

        if (amount > 20000)
            throw TransactionLimit();

        cout << "ATM withdrawal successful." << endl;
    }

    void display()
    {
        cout << "\nTransaction Type : ATM Withdrawal" << endl;
        Transaction::display();
    }
};

// Online Payment
class OnlinePayment : public Transaction
{
public:

    OnlinePayment(int id, float a)
        : Transaction(id, a)
    {
    }

    void process()
    {
        if (amount <= 0)
            throw InvalidTransaction();

        if (amount > 50000)
            throw TransactionLimit();

        cout << "Online payment successful." << endl;
    }

    void display()
    {
        cout << "\nTransaction Type : Online Payment" << endl;
        Transaction::display();
    }
};

// Card Payment
class CardPayment : public Transaction
{
public:

    CardPayment(int id, float a)
        : Transaction(id, a)
    {
    }

    void process()
    {
        if (amount <= 0)
            throw InvalidTransaction();

        if (amount > 30000)
            throw TransactionLimit();

        cout << "Card payment successful." << endl;
    }

    void display()
    {
        cout << "\nTransaction Type : Card Payment" << endl;
        Transaction::display();
    }
};

// Bank Transfer
class BankTransfer : public Transaction
{
private:
    float balance;

public:

    BankTransfer(int id, float a, float b)
        : Transaction(id, a)
    {
        balance = b;
    }

    void process()
    {
        if (amount <= 0)
            throw InvalidTransaction();

        if (amount > balance)
            throw InsufficientBalance();

        if (amount > 100000)
            throw TransactionLimit();

        cout << "Bank transfer successful." << endl;
    }

    void display()
    {
        cout << "\nTransaction Type : Bank Transfer" << endl;
        Transaction::display();
    }
};

// International Transaction
class InternationalTransaction : public Transaction
{
public:

    InternationalTransaction(int id, float a)
        : Transaction(id, a)
    {
    }

    void process()
    {
        if (amount <= 0)
            throw InvalidTransaction();

        if (amount > 200000)
            throw TransactionLimit();

        cout << "International transaction successful." << endl;
    }

    void display()
    {
        cout << "\nTransaction Type : International Transaction" << endl;
        Transaction::display();
    }
};

int main()
{
    cout << "BANKING TRANSACTION ANALYSIS SYSTEM\n";
    cout << "Student Name     : " << STUDENT_NAME << endl;
    cout << "Registration No. : " << REG_NO << endl;

    ATMWithdrawal t1(101, 5000, 10000);
    OnlinePayment t2(102, 25000);
    CardPayment t3(103, 40000);
    BankTransfer t4(104, 15000, 10000);
    InternationalTransaction t5(105, 300000);

    // STL container
    vector<Transaction*> transactions(5);

    transactions[0] = &t1;
    transactions[1] = &t2;
    transactions[2] = &t3;
    transactions[3] = &t4;
    transactions[4] = &t5;

    cout << "\n========== TRANSACTION REPORT ==========\n";

    for (int i = 0; i < 5; i++)
    {
        transactions[i]->display();

        try
        {
            transactions[i]->process();
        }
        catch (TransactionException &e)
        {
            e.message();
        }

        cout << "-----------------------------\n";
    }

    return 0;
}