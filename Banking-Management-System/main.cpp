#include <iostream>
#include <string>
using namespace std;

class Transaction {
public:
string type;
float amount;

Transaction() {
type = "";
amount = 0;
}

Transaction(string t, float a) {
type = t;
amount = a;
}
};

class Account {
public:
int accountNumber;
float balance;
Transaction history[100];
int transCount;

Account(int num, float initialBalance) {
accountNumber = num;
balance = initialBalance;
transCount = 0;
}

void deposit(float amount) {
balance += amount;
history[transCount++] = Transaction("Deposit", amount);
cout << "Deposited: " << amount << "\n";
}

void withdraw(float amount) {
if (amount > balance) {
cout << "Insufficient funds.\n";
return;
}
balance -= amount;
history[transCount++] = Transaction("Withdrawal", amount);
cout << "Withdrawn: " << amount << "\n";
}

void showInfo() {
cout << "Account #" << accountNumber << " | Balance: " << balance << "\n";
cout << "Recent Transactions:\n";
int start = transCount > 5 ? transCount - 5 : 0;
for (int i = start; i < transCount; i++)
cout << " " << history[i].type << ": " << history[i].amount << "\n";
}
};

class Customer {
public:
string name;
int age;
Account* account;

Customer(string n, int a, int accNum, float initialBalance) {
name = n;
age = a;
account = new Account(accNum, initialBalance);
}

~Customer() {
delete account;
}
};

void transferFunds(Account* from, Account* to, float amount) {
if (from->balance < amount) {
cout << "Transfer failed: insufficient balance.\n";
return;
}
from->balance -= amount;
to->balance += amount;
from->history[from->transCount++] = Transaction("Transfer Out", amount);
to->history[to->transCount++] = Transaction("Transfer In", amount);
cout << "Transfer of " << amount << " completed.\n";
}

int main() {
string name1, name2;
int age1, age2;
float initialBalance1, initialBalance2;

cout << "=== Register Customer 1 ===\n";
cout << "Enter name: ";
cin >> name1;
cout << "Enter age: ";
cin >> age1;
cout << "Enter initial balance: ";
cin >> initialBalance1;

cout << "\n=== Register Customer 2 ===\n";
cout << "Enter name: ";
cin >> name2;
cout << "Enter age: ";
cin >> age2;
cout << "Enter initial balance: ";
cin >> initialBalance2;

Customer c1(name1, age1, 1001, initialBalance1);
Customer c2(name2, age2, 1002, initialBalance2);

int choice;
do {
cout << "\n=== Banking Menu ===\n";
cout << "1. Deposit\n";
cout << "2. Withdraw\n";
cout << "3. Transfer Funds\n";
cout << "4. View Account Info\n";
cout << "0. Exit\n";
cout << "Choice: ";
cin >> choice;

if (choice == 1) {
int cust;
float amount;
cout << "Which customer? (1 or 2): ";
cin >> cust;
cout << "Enter amount to deposit: ";
cin >> amount;
if (cust == 1) c1.account->deposit(amount);
else c2.account->deposit(amount);

} else if (choice == 2) {
int cust;
float amount;
cout << "Which customer? (1 or 2): ";
cin >> cust;
cout << "Enter amount to withdraw: ";
cin >> amount;
if (cust == 1) c1.account->withdraw(amount);
else c2.account->withdraw(amount);

} else if (choice == 3) {
int from;
float amount;
cout << "Transfer from which customer? (1 or 2): ";
cin >> from;
cout << "Enter amount to transfer: ";
cin >> amount;
if (from == 1) transferFunds(c1.account, c2.account, amount);
else transferFunds(c2.account, c1.account, amount);

} else if (choice == 4) {
int cust;
cout << "Which customer? (1 or 2): ";
cin >> cust;
if (cust == 1) {
cout << "\n" << c1.name << "'s Info:\n";
c1.account->showInfo();
} else {
cout << "\n" << c2.name << "'s Info:\n";
c2.account->showInfo();
}
}

} while (choice != 0);

cout << "Goodbye!\n";
return 0;
}
