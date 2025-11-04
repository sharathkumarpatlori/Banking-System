#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {

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

    bool saveToFile(const string& filename) {
        ofstream outFile(filename);

        if (!outFile.is_open()) {
            cout << "Error: Could not open file.\n";
            return false;
        }

        outFile << accountHolder << endl;
        outFile << accountNumber << endl;
        outFile << balance << endl;

        return true;
    }

    // Load from file
    bool loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            cout << "Error: Could not open file.\n";
            return false;
        }

        // cout << "Code reached....";
        // Just read 3 lines
        getline(inFile, accountHolder); // Fetch 1st line from file
        inFile >> accountNumber; // Fetch 2nd line from file 
        inFile >> balance; // Fetch 3rd line from file

        return true;
    }

    void printSummary() const {
        cout << "Account Holder: " << accountHolder
            << " | Account Number: " << accountNumber
            << " | Balance: $" << balance << endl;
    }
};

int test() {
    BankAccount acc("aditya", 2000, 1500.5);

    if (acc.loadFromFile("account.txt")) {
        cout << "Account loaded successfully!\n";
        acc.printSummary();
    }

    cin.get();
    return 0;
}


