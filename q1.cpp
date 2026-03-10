#include <iostream>
#include <string>
using namespace std;


class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNo, string name, double bal, string type) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
        accountType = type;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation not defined for this account type." << endl;
    }

    virtual void printStatement() {
        cout << "Account Statement:" << endl;
        cout << "Balance: " << balance << endl;
    }

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
    }

    virtual ~Account() {}
};


class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNo, string name, double bal, double rate, double minBal)
        : Account(accNo, name, bal, "Savings") {
        interestRate = rate;
        minimumBalance = minBal;
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance) {
            balance -= amount;
            cout << "Withdrawn from Savings: " << amount << endl;
        } else {
            cout << "Cannot withdraw. Minimum balance requirement!" << endl;
        }
    }

    void printStatement() override {
        cout << "Savings Account Statement\nBalance: " << balance << endl;
    }
};


class CheckingAccount : public Account {
public:
    CheckingAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal, "Checking") {}

    void calculateInterest() override {
        cout << "Checking accounts usually have no interest." << endl;
    }

    void printStatement() override {
        cout << "Checking Account Statement\nBalance: " << balance << endl;
    }
};


class FixedDepositAccount : public Account {
private:
    string maturityDate;
    double fixedInterestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, string date, double rate)
        : Account(accNo, name, bal, "Fixed Deposit") {
        maturityDate = date;
        fixedInterestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * fixedInterestRate / 100;
        cout << "Fixed Deposit Interest: " << interest << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity date: " << maturityDate << endl;
    }

    void printStatement() override {
        cout << "Fixed Deposit Statement\nBalance: " << balance
             << "\nMaturity Date: " << maturityDate << endl;
    }
};

int main() {

    Account* acc1 = new SavingsAccount(101, "Ali", 5000, 5, 1000);
    Account* acc2 = new CheckingAccount(102, "Sara", 3000);
    Account* acc3 = new FixedDepositAccount(103, "Ahmed", 10000, "31-12-2027", 7);

    cout << "\n--- Savings Account ---\n";
    acc1->getAccountInfo();
    acc1->deposit(1000);
    acc1->withdraw(2000);
    acc1->calculateInterest();
    acc1->printStatement();

    cout << "\n--- Checking Account ---\n";
    acc2->getAccountInfo();
    acc2->withdraw(500);
    acc2->calculateInterest();
    acc2->printStatement();

    cout << "\n--- Fixed Deposit Account ---\n";
    acc3->getAccountInfo();
    acc3->calculateInterest();
    acc3->withdraw(1000);
    acc3->printStatement();

    delete acc1;
    delete acc2;
    delete acc3;

    return 0;
}