#include <iostream>
using namespace std;

class ATM {
private:
    int pin;
    double balance;

public:
    ATM() {
        pin = 7851;        // Def pin
        balance = 10000.0;  
    }

    bool validatePin(int enteredPin) {
        if (enteredPin == pin) {
            return true;
        }
        return false;
    }

    void checkBalance() {
        cout << "Current Balance: Rs" << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited Rs" << amount << endl;
            cout << "Updated Balance: Rs" << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            cout << "Successfully withdrew Rs" << amount << endl;
            cout << "Remaining Balance: Rs" << balance << endl;
        }
    }
};

int main() {
    ATM myAtm;
    int userPin;

    cout << "=== ATM Machine ===" << endl;
    cout << "Enter your 4-digit PIN: ";
    cin >> userPin;

    if (!myAtm.validatePin(userPin)) {
        cout << "Incorrect PIN. Access Denied." << endl;
        return 0;
    }

    cout << "PIN Validated Successfully!" << endl;

    int choice;
    double amount;

    do {
        cout << "\n--- Select Operation ---" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myAtm.checkBalance();
                break;
            case 2:
                cout << "Enter deposit amount: ";
                cin >> amount;
                myAtm.deposit(amount);
                break;
            case 3:
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                myAtm.withdraw(amount);
                break;
            case 4:
                cout << "Thank you for using the ATM." << endl;
                break;
            default:
                cout << "Invalid option! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}