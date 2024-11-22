#include<iostream>
#include"Login.h"
using namespace std;

// Default Constructor
Login::Login() {
	username = "";
	password = "";
};

// Parameterize Constructor
Login::Login(string username, string password) :username(username), password(password) {};

// Setters
void Login::setUsername(string username) {
	this->username = username;
}

void Login::setPassword(string password) {
	this->password = password;
}

// Getter
string Login::getUsername() {
	return username;
}
string Login::getPassword() {
	return password;
}

// For Taking Input from User the Login Details
void Login::LoginDetails() {
	cin.ignore();
	cout << "Enter the Username : ";
	getline(cin, username);
	cout << "Enter the Password : ";
	getline(cin, password);
}