#pragma once
#include"SignUp.h"
class User {
public:
	std::string username;
	std::string password;
	std::string date_Of_Birth;
	std::string country;
	User* left;
	User* right;
	int height;
	User();
	User(SignUp signup);
};

class AllUsers {
	User* root;
	int userCount;
	User* InsertUser(User* root, SignUp signup);

public:
	AllUsers();
	void Insert(SignUp signup);
	void DeleteUser(std::string username);
};