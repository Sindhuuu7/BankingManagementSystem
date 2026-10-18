
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract Base Class
class BankAccount {
private:
    int accountNumber;
    string holderName;
    float balance;

protected:
    float getBalance() const {
        return balance;
    }

    void setBalance(float newBalance) {
        balance = newBalance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    string getHolderName() const {
        return holderName;
    }

public:
    BankAccount(int accountNumber, string holderName, float balance) {
        this->accountNumber = accountNumber;
        this->holderName = holderName;
        this->balance = balance;
    }

    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful: Rs. " << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(float amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawal successful: Rs. " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void displayDetails() = 0;

    virtual ~BankAccount() {}
};

// Derived Class 1
class SavingsAccount : public BankAccount {
private:
    float interestRate;

public:
    SavingsAccount(int accountNumber, string holderName,
                   float balance, float interestRate)
        : BankAccount(accountNumber, holderName, balance) {
        this->interestRate = interestRate;
    }

    void displayDetails() override {
        cout << "\n--- Savings Account ---" << endl;
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Holder Name: " << getHolderName() << endl;
        cout << "Balance: Rs. " << getBalance() << endl;
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }

    float calculateInterest() {
        return getBalance() * interestRate / 100;
    }
};

// Derived Class 2
class CurrentAccount : public BankAccount {
private:
    float overdraftLimit;

public:
    CurrentAccount(int accountNumber, string holderName,
                   float balance, float overdraftLimit)
        : BankAccount(accountNumber, holderName, balance) {
        this->overdraftLimit = overdraftLimit;
    }

    void displayDetails() override {
        cout << "\n--- Current Account ---" << endl;
        cout << "Account Number: " << getAccountNumber() << endl;
        cout << "Holder Name: " << getHolderName() << endl;
        cout << "Balance: Rs. " << getBalance() << endl;
        cout << "Overdraft Limit: Rs. " << overdraftLimit << endl;
    }

    void withdraw(float amount) override {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (amount <= getBalance() + overdraftLimit) {
            setBalance(getBalance() - amount);
            cout << "Withdrawal successful: Rs. "
                 << amount << endl;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

// Main Function
int main() {
    SavingsAccount savings(101, "Sindhu", 10000, 5);
    CurrentAccount current(102, "Anu", 5000, 2000);

    // Runtime Polymorphism
    vector<BankAccount*> accounts = {&savings, &current};

    cout << "===== BANKING MANAGEMENT SYSTEM =====" << endl;

    for (BankAccount* account : accounts) {
        account->displayDetails();
    }

    cout << "\n--- Savings Account Transactions ---" << endl;
    savings.deposit(2000);
    savings.withdraw(1000);

    cout << "Annual Interest: Rs. "
         << savings.calculateInterest() << endl;

    savings.displayDetails();

    cout << "\n--- Current Account Transactions ---" << endl;
    current.withdraw(6000);
    current.displayDetails();

    return 0;
}
