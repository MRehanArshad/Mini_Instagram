#pragma once
#include<string>
class Login {
	std::string username;
	std::string password;
public:
	Login();
	Login(std::string username, std::string password);
	void setUsername(std::string username);
	void setPassword(std::string password);
	std::string getUsername();
	std::string getPassword();
	void LoginDetails();
};