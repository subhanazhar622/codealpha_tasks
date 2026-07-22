#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(string username) {
ifstream file((username + ".txt").c_str());
return file.good();
}

void registerUser() {
string username, password;
cout << "Choose a username: ";
cin >> username;

if (userExists(username)) {
cout << "Username already taken. Try another one.\n";
return;
}

cout << "Choose a password: ";
cin >> password;

if (username.empty() || password.empty()) {
cout << "Username and password can't be empty.\n";
return;
}

ofstream file((username + ".txt").c_str());
file << password;
file.close();

cout << "Registration successful!\n";
}

void loginUser() {
string username, password;
cout << "Username: ";
cin >> username;
cout << "Password: ";
cin >> password;

if (!userExists(username)) {
cout << "No account found with that username.\n";
return;
}

ifstream file((username + ".txt").c_str());
string stored;
getline(file, stored);
file.close();

if (stored == password)
cout << "Login successful! Welcome, " << username << ".\n";
else
cout << "Wrong password. Please try again.\n";
}

int main() {
int choice;
cout << "1. Register\n2. Login\nChoice: ";
cin >> choice;

if (choice == 1)
registerUser();
else if (choice == 2)
loginUser();
else
cout << "Invalid option.\n";

return 0;
}
