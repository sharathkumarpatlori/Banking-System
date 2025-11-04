#include <iostream>
#include <string>
using namespace std;

class BankAccount { // user defined datatype
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string name = "", int number = 0, double bal = 0.0) {
        accountHolder = name;
        accountNumber = number;
        balance = bal;
    }
    
    void searchByName(BankAccount accounts[], int size, string name) {
        /* n accounts, and we go through each accounts name and
         check if the accounts name matches with name you are asking for */

        for (int i = 0; i < size; i++) {
            if (accounts[i].getName() == name) { 
                cout << "Accounts found!\n"; 
                return;
            }
        }
        cout << "Accounts not found!\n";
    }

    void searchByNumber(BankAccount accounts[], int size, string name) {
        /*  */

        for (int i = 0; i < size; i++) {

        }
    }

    void printSummary() const {
        cout << "Name: " << accountHolder
            << " | Account Number: " << accountNumber
            << " | Balance: $" << balance << endl;
    }

    string getName() const { return accountHolder; }
    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
};

int main() {
    BankAccount accounts[3] = { // accounts itself is an object and also array
        BankAccount("aditya", 1000, 1500), // aditya != ram, false
        BankAccount("ram", 998, 150000),  // ram == ram, true
        BankAccount("laxman", 1225, 15000) // laxman != ram
    };

    string name;
    cout << "Enter the name: ";
    cin >> name;

    BankAccount obj;
    obj.searchByName(accounts, 3, name);

    // cout << "Info of all accounts";
    // for (int i = 0; i < 3; i++) { accounts[i].printSummary(); }

    return 0;
}