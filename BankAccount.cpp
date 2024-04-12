#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a bank account
struct BankAccount {
    string username;
    string password;
    double balance;

    // Constructor
    BankAccount(string uname, string pwd, double initialBalance) {
        username = uname;
        password = pwd;
        balance = initialBalance;
    }
};

// Function to register a new account
BankAccount registerAccount() {
    string username, password;
    double initialBalance;

    cout << "Enter a username: ";
    cin >> username;

    cout << "Enter a password: ";
    cin >> password;

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    // Create and return a new account
    return BankAccount(username, password, initialBalance);
}

// Function to perform login
bool login(const vector<BankAccount> &accounts, string username, string password) {
    for (const BankAccount &account : accounts) {
        if (account.username == username && account.password == password) {
            cout << "Login successful!" << endl;
            return true;
        }
    }
    cout << "Invalid username or password. Login failed." << endl;
    return false;
}

// Function to withdraw money
void withdraw(BankAccount &account, double amount) {
    if (amount > 0 && amount <= account.balance) {
        account.balance -= amount;
        cout << "Withdrawal successful. Remaining balance: $" << account.balance << endl;
    } else {
        cout << "Invalid withdrawal amount or insufficient balance." << endl;
    }
}

// Function to deposit money
void deposit(BankAccount &account, double amount) {
    if (amount > 0) {
        account.balance += amount;
        cout << "Deposit successful. New balance: $" << account.balance << endl;
    } else {
        cout << "Invalid deposit amount." << endl;
    }
}

// Function to check account balance
void checkBalance(const BankAccount &account) {
    cout << "Current balance: $" << account.balance << endl;
}

// Function to transfer money between accounts
void transferMoney(BankAccount &sender, BankAccount &receiver, double amount) {
    if (amount > 0 && amount <= sender.balance) {
        sender.balance -= amount;
        receiver.balance += amount;
        cout << "Transfer successful. New balance for " << sender.username << ": $" << sender.balance << endl;
        cout << "New balance for " << receiver.username << ": $" << receiver.balance << endl;
    } else {
        cout << "Invalid transfer amount or insufficient balance." << endl;
    }
}

// Function to display account information
void displayAccountInfo(const BankAccount &account) {
    cout << "Account Information:" << endl;
    cout << "Username: " << account.username << endl;
    cout << "Balance: $" << account.balance << endl;
}

int main() {
    vector<BankAccount> accounts;

    // Example usage:
    BankAccount account1 = registerAccount();
    accounts.push_back(account1);

    BankAccount account2 = registerAccount();
    accounts.push_back(account2);

    string enteredUsername, enteredPassword;
    cout << "Enter your username: ";
    cin >> enteredUsername;

    cout << "Enter your password: ";
    cin >> enteredPassword;

    if (login(accounts, enteredUsername, enteredPassword)) {
        // User is logged in, perform additional operations as needed
        int choice;
        do {
            cout << "\nChoose an operation:\n";
            cout << "1. Withdraw\n";
            cout << "2. Deposit\n";
            cout << "3. Check Balance\n";
            cout << "4. Transfer Money\n";
            cout << "5. Display Account Information\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    double withdrawAmount;
                    cout << "Enter withdrawal amount: $";
                    cin >> withdrawAmount;
                    withdraw(account1, withdrawAmount);
                    break;
                case 2:
                    double depositAmount;
                    cout << "Enter deposit amount: $";
                    cin >> depositAmount;
                    deposit(account1, depositAmount);
                    break;
                case 3:
                    checkBalance(account1);
                    break;
                case 4:
                    double transferAmount;
                    cout << "Enter transfer amount: $";
                    cin >> transferAmount;
                    transferMoney(account1, account2, transferAmount);
                    break;
                case 5:
                    displayAccountInfo(account1);
                    break;
                case 6:
                    cout << "Exiting the system.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
            }
        } while (choice != 6);
    }

    return 0;
}
