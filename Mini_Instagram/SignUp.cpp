#include<iostream>
#include"SignUp.h"
using namespace std;

// Contructors
SignUp::SignUp() {
	Username = "";
	Password = "";
	DateOfBirth = "";
	Country = "";
}

SignUp::SignUp(string Username, string Password, string DateOfBirth, string Country) {
	SetUsername(Username);
	SetPassword(Password);
	SetDateOfBirth(DateOfBirth);
	SetCountry(Country);
}

// Setters
void SignUp::SetUsername(string Username) {
	this->Username = Username;
}

void SignUp::SetPassword(string Password) {
	this->Password = Password;
}

void SignUp::SetDateOfBirth(string DateOfBirth) {
	this->DateOfBirth = DateOfBirth;
}
void SignUp::SetCountry(string Country) {
	this->Country = Country;
}

// Getters
string SignUp::getUsername() {
	return Username;
}

string SignUp::getPassword() {
	return Password;
}

string SignUp::getDateOfBirth() {
	return DateOfBirth;
}

string SignUp::getCountry() {
	return Country;
}

// For Taking Details of Users
void SignUp::SignUpPage() {
	cout << "Enter the Username : ";
	getline(cin, Username);
	cout << "Enter the Password : ";
	getline(cin, Password);
	cout << "Enter the Date of Birth : ";
	getline(cin, DateOfBirth);
	cout << "Enter the Country : ";
	getline(cin, Country);
}