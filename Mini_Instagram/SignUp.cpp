#include<iostream>
#include"SignUp.h"
#include<ctime>
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

bool validateDate(string str) {
	if (str[2] != '/' || str[5] != '/' || str.size() > 10) {
		cout << "Wrong Format date entered\n";
		return 0;
	}
	string check = str.substr(6, 4);
	if (stoi(check) > 2022) {
		cout << "Invalid year entered!\n";
		return 0;
	}
	check = str.substr(3, 2);
	if (stoi(check) > 12) {
		cout << "Invalid month entered!\n";
		return 0;
	}
	check = str.substr(0, 2);
	if (stoi(check) > 30) {
		cout << "Invalid day entered!\n";
		return 0;
	}
}

bool validateCountry(string country) {
	for (char c : country) {
		if (isalpha(c)) {
			cout << "Country name can't have Numbers or digits\n";
			return 0;
		}
	}
}

// For Taking Details of Users
void SignUp::SignUpPage() {
	system("cls");
	cout << "\n\n\t\t\t\t     SignUp Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\tEnter the Username : ";
	getline(cin, Username);
	cout << "\n\t\t\tEnter the Password : ";
	getline(cin, Password);
	while (Password.size() < 7) {
		cout << "Password can't be shorter than 6 characters : ";
		getline(cin, Password);
	}
	cout << "\n\t\t\tEnter the Date of Birth (DD/MM/YYYY) : ";
	getline(cin, DateOfBirth);
	while (!validateDate(DateOfBirth)) {
		getline(cin, DateOfBirth);
	}
	cout << "\n\t\t\tEnter the Country : ";
	getline(cin, Country);
	while (!validateCountry(Country)) {
		getline(cin, Country);
	}
	cout << "\n\n\n\t\t ================================================" << endl;
	timetoSignUp = "";
	time_t now = time(nullptr);
	char buffer[26];
	if (ctime_s(buffer, sizeof(buffer), &now) == 0) {
		for (int i = 0; i < 24; i++) {
			timetoSignUp += buffer[i];
		}
 	}
}

std::string SignUp::getTimetoSignUp() {
	return timetoSignUp;
}