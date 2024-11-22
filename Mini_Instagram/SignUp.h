#pragma once
#include<string>
class SignUp {
	std::string Username;
	std::string Password;
	std::string DateOfBirth;
	std::string Country;
public:
	SignUp();
	SignUp(std::string Username, std::string password, std::string DateOfBirth, std::string Country);
	void SetUsername(std::string Username);
	void SetPassword(std::string password);
	void SetDateOfBirth(std::string password);
	void SetCountry(std::string password);
	std::string getUsername();
	std::string getPassword();
	std::string getDateOfBirth();
	std::string getCountry();
	void SignUpPage();
};