#include<iostream>
#include<Windows.h>
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
	system("cls");
	cout << "\n\n\t\t\t\t     Login Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\tEnter the Username : ";
	getline(cin, username);
	cout << "\n\t\t\tEnter the Password : ";
	getline(cin, password);
	cout << "\n\n\n\t\t ================================================" << endl;
}