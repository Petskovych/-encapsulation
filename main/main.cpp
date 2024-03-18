#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class Transaction {
private:
    time_t timestamp;
    string description;
    double amount;

public:
    Transaction( string desc, double amt) : description(desc), amount(amt) {
        timestamp =  time(nullptr);
    }

    void display() const {
        char timeString[26];
        ctime_s(timeString, sizeof(timeString), &timestamp);
         cout << "Timestamp: " << timeString;
         cout << "Description: " << description <<  endl;
         cout << "Amount: $" << amount <<  endl;
    }
};

class BankAccount {
private:
     string ownerName;
     string accountNumber;
    double balance;
     vector<Transaction> transactionHistory;

public:
    BankAccount( string name,  string accNum, double initBalance)
        : ownerName(name), accountNumber(accNum), balance(initBalance) {}

    void deposit(double amount) {
        balance += amount;
        Transaction transaction("Deposit", amount);
        transactionHistory.push_back(transaction);
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            Transaction transaction("Withdrawal", -amount);
            transactionHistory.push_back(transaction);
        }
        else {
             cout << "Insufficient funds!" <<  endl;
        }
    }

    void displayTransactionHistory() const {
         cout << "Transaction History for Account: " << accountNumber <<  endl;
        for (const auto& transaction : transactionHistory) {
            transaction.display();
             cout <<  endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    // Створення об'єкта класу BankAccount
    BankAccount account("Petskovych", "4251 5721 1123 9421", 1000.0);

    // Початкове виведення інформації та можливості здійснення операцій
    std::cout << "Welcome to the Bank!" << std::endl;
    std::cout << "Current Balance: $" << account.getBalance() << std::endl;

    char choice;
    double amount;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "D - Deposit" << std::endl;
    std::cout << "W - Withdraw" << std::endl;
    std::cout << "H - Transaction History" << std::endl;
    std::cout << "Q - Quit" << std::endl;

    while (true) {
         cin >> choice;
        switch (choice) {
        case 'D':
             cout << "Enter amount to deposit: ";
             cin >> amount;
            account.deposit(amount);
            break;
       
        
        case 'W':
             cout << "Enter amount to withdraw: ";
             cin >> amount;
            account.withdraw(amount);
            break;
        case 'H':
            account.displayTransactionHistory();
            break;
        case 'Q':
             cout << "Thank you for using the Bank!" <<  endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." <<  endl;
        }
    }

    return 0;
}
