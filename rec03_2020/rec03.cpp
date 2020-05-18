/*
  Saimanasa Juluru
  CS2124
  Section C
  14 February 2020
  Lab 3
 */

// Provided
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

//
// Task 1: The Account struct. Call it AccountS
//
struct AccountS {
    string name;
    int accNum;
};

//
// Task 2: The Account class. Call it AccountC
//
class AccountC {
    friend ostream& operator<<(ostream& os, const AccountC& theAccount);
private:
    string accOwner;
    int accNumber;
public:
    // default constructor
    AccountC() {}
    // user defined constructor
    AccountC(string name, int num) : accOwner(name), accNumber(num) {}
    const string& getName() const {return accOwner;}
    int getNumber() const {return accNumber;}
};

// 2.b: AccountC output operator, not a friend.
//ostream& operator<<(ostream& os, const AccountC& theAccount) {
//    os << "Account Owner: " << theAccount.getName() << " Acc Number: " << theAccount.getNumber();
//    return os;
//}

// 2.2: AccountC output operator, reimplemented as a friend.
ostream& operator<<(ostream& os, const AccountC& theAccount) {
    os << "Account Owner: " << theAccount.accOwner << " Account Number: " << theAccount.accNumber;
    return os;
}

//
// Task 3
//
// Transaction class definition
class Transaction {
    friend ostream& operator<<(ostream& os, const Transaction& aTransaction) {
        os << aTransaction.transactionType << " of amount $" << aTransaction.transactionAmount;
        return os;
    }
public:
    Transaction(const string& type, int amount) : transactionType(type), transactionAmount(amount) {}
private:
    string transactionType;
    int transactionAmount;
};

// Account class definition
class Account {
    friend ostream& operator<<(ostream& os, const Account& anAccount){
        os << "Account: " << anAccount.accOwner << " #"
           << anAccount.accNumber << " Balance: " << anAccount.balance
           << " Transaction history: ";
        for (const Transaction& transaction : anAccount.transactionHistory) {
            os << transaction;
        }
        return os;
    };
private:
    string accOwner;
    int accNumber;
    double balance = 0;
    vector<Transaction> transactionHistory;
public:
    // default constructor
    Account() {}
    // user defined constructor
    Account(string name, int num) : accOwner(name), accNumber(num) {}
    const string& getName() const {return accOwner;}
    int getNumber() const {return accNumber;}
    void deposit(double amount) {
        balance += amount;
        transactionHistory.emplace_back("Deposit", amount);
    }
    void withdraw(double amount) {
        if (balance - amount < 0) {
            cerr << "Not enough money to withdraw $" << amount << " from " << accOwner << endl;
        }
        else {
            balance -= amount;
            transactionHistory.emplace_back("Withdraw", amount);
        }
    }
};

//
// Task 4
//
// Transaction class definition with embedded Account class



int main() {
    // opening the file and making sure it actually exists
    ifstream accountFile;
    accountFile.open("accounts.txt");
    if (!accountFile) {
        cerr << "File couldn't be opened.\n";
    }
    // create an empty vector
    vector<AccountS> accounts;
    //
    // Task 1: account as struct
    //
    //      1a. Fill vector of account structs from file

    cout << "Task1a:\n";
    cout << "Filling vector of struct objects, define a local struct instance "
         << " and set fields explicitly:\n";

    string nameOf;
    int numOf;
    while (accountFile >> nameOf >> numOf) {
        AccountS anAccount;
        anAccount.name = nameOf;
        anAccount.accNum = numOf;
        accounts.push_back(anAccount);
    }
    accountFile.close();
    for (const AccountS& theAccount : accounts) {
        cout << theAccount.name << " " << theAccount.accNum << endl;
    }
    accounts.clear();
    //      1b
    cout << "Task1b:\n";
    cout << "Filling vector of struct objects, using {} initialization:\n";

    accountFile.open("accounts.txt");

    string theAccName;
    int theAccNum;
    while (accountFile >> theAccName >> theAccNum) {
        AccountS newAccount{theAccName, theAccNum};
        accounts.push_back(newAccount);
    }
    for (const AccountS& theAccount : accounts) {
        cout << theAccount.name << " " << theAccount.accNum << endl;
    }
    accountFile.close();
    accounts.clear();
    //==================================
    //
    // Task 2: account as class
    //

    //      2a
    cout << "==============\n";
    cout << "\nTask2a:";
    cout << "\nFilling vector of class objects, using local class object:\n";
    vector<AccountC> classAccounts;
    string names;
    int nums;
    accountFile.open("accounts.txt");
    while(accountFile >> names >> nums) {
        AccountC newClass{names, nums};
        classAccounts.push_back(newClass);
    }
    accountFile.close();
    cout << "---\n";
    cout << "\nTask2b:\n";
    cout << "output using output operator with getters\n";
    for (const AccountC& theAccounts : classAccounts) {
        cout << theAccounts << endl;
    }

    cout << "\nTask2c:\n";
    cout << "output using output operator as friend without getters\n";
    // Note code here will be same as above.
    for (const AccountC& theAccounts : classAccounts) {
        cout << theAccounts << endl;
    }
    accounts.clear();
    cout << "\nTask2d:\n";
    cout << "Filling vector of class objects, using temporary class object:\n";
    accountFile.open("accounts.txt");
    string theName;
    int theNum;
    while(accountFile >> theName, theNum) {
        classAccounts.push_back(AccountC(theName, theNum));
    }
    accountFile.close();
    for (const AccountC& theAccounts : classAccounts) {
        cout << theAccounts << endl;
    }
    classAccounts.clear();
    cout << "\nTask2e:\n";
    cout << "\nFilling vector of class objects, using emplace_back:\n";
    accountFile.open("accounts.txt");
    string copyName;
    int copyNum;
    while(accountFile >> copyName >> copyNum) {
        classAccounts.emplace_back(AccountC(copyName, copyNum));
    }
    accountFile.close();
    for (const AccountC& theAccounts : classAccounts) {
        cout << theAccounts << endl;
    }

    // Task 3
    cout << "==============\n";
    cout << "\nTask 3:\n\nAccounts and Transaction:\n";
    string type, theOwner;
    int currAcc, position;
    double amount;
    vector<Account> actualAccounts;
    accountFile.open("accounts.txt");
    while(accountFile >> theOwner >> currAcc) {
        actualAccounts.emplace_back(Account(theOwner, currAcc));
    }
    accountFile.close();
    ifstream transactionFile;
    transactionFile.open("transactions.txt");

    while(transactionFile >> type >> currAcc >> amount) {
        if (type == "Deposit") {
            actualAccounts.back().deposit(amount);
        }
        else if (type == "Withdraw") { //Withdraw
            actualAccounts.back().withdraw(amount);
        }
    }

    for (const Account& theAccounts : actualAccounts) {
        cout << theAccounts << endl;
    }

    // Task 4
    cout << "==============\n";
    cout << "\nTask 4:\n\nAccounts and Transaction:\n"
         << "Account class is nested inside Transaction class.\n";

}



