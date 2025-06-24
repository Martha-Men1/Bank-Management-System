// Bank Management Project
// Simple command-line bank account simulation in C++ (single account)
// Allows user to: open account, deposit money, withdraw money, display account details

#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

// Bank class definition
class bank {
    char name[100];    // The account holder name
    char adr[100];     // The address of account holder
    char y;            // The account type (saving = 's' or chequing = 'c')
    float balance;     // Current account balance

public:
    // Member functions (operations on bank account)
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
};

// open_account() -> creates a new account and stores user input
void bank::open_account() {
    cout << "Enter Full Name: ";
    cin.ignore();                   
    cin.getline(name, 100);         
    cout << "Enter Your Address: ";
    cin.getline(adr, 100);         
    cout << "What Type Of Account Do You Want To Open (saving (s) or chequing (c)): ";
    cin >> y;                       
    cout << "Enter Amount For Deposit: ";
    cin >> balance;                 
    cout << "Your account is created! \n";
}

// deposit_money() -> adds money to account
void bank::deposit_money() {
    float a = 0;
    cout << "Enter How Much You Would Like To Deposit: ";
    cin >> a;                       
    balance += a;                   
    cout << a << " has been deposited.\n";
    cout << "New Total Balance: " << balance << endl;
}

// withdraw_money() -> removes money from account if sufficient balance exists
void bank::withdraw_money() {
    float a = 0;
    cout << "Enter How Much You Would Like To Withdraw: ";
    cin >> a;                    
    if (a > balance) {
        cout << "Insufficient balance!\n";
    } else {
        balance -= a;
        cout << a << " has been withdrawn.\n";
        cout << "New Total Balance: " << balance << endl;
    }
}

// display_account() -> prints account information
void bank::display_account() {
    cout << "Full Name: " << name << endl;
    cout << "Your Address: " << adr << endl;
    cout << "Type of Account: " << y << endl;
    cout << "Current Balance: " << balance << endl;
}

// clearScreen() -> clears terminal screen using ANSI escape codes (macOS / Linux)
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// main() -> main program loop
int main() {
    int ch;         
    bank obj;       

    // Main menu loop
    do {
        cout << "\n=========== BANK MENU ===========\n";
        cout << "1) Open Account\n";
        cout << "2) Deposit Money\n";
        cout << "3) Withdraw Money\n";
        cout << "4) Display Account\n";
        cout << "5) Exit\n";
        cout << "=================================\n";
        cout << "Enter your choice: ";
        cin >> ch;   // Read user menu choice

        // Switch based on menu choice
        switch (ch) {
            case 1:
                cout << "1) Open Account\n";
                obj.open_account();
                break;

            case 2:
                cout << "2) Deposit Money\n";
                obj.deposit_money();
                break;

            case 3:
                cout << "3) Withdraw Money\n";
                obj.withdraw_money();
                break;

            case 4:
                cout << "4) Display Account\n";
                obj.display_account();
                break;

            case 5:
                cout << "Exiting the program. Thank you!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (ch != 5);    // Keep looping until user chooses to exit (5)

    return 0;
}