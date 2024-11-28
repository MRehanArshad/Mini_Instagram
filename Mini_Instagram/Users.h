#pragma once
#include"SignUp.h"
#include"Login.h"
#include"Friend.h"
#include"Notification.h"
#include"Messages.h"

class User {
public:
	std::string username;
	std::string password;
	std::string date_Of_Birth;
	std::string country;
	User* left;
	User* right;
	int height;
	Friend Friend_List;
	Notification notification;
	MessageStack msgStk;
	User();
	User(SignUp signup);
	bool AddFriend(std::string name);
	bool deleteFriend(std::string name);
	bool unblockFriend(std::string key);
	bool blockFriend(std::string key);
	bool viewMessages();
	bool addMsg(std::string name, std::string msg);
	void displayFriends();
};

class AllUsers {
	User* root;
	int userCount;
	User* InsertUser(User* root, SignUp signup);

public:
	AllUsers();
	void Insert(SignUp signup);
	void DeleteUser(std::string username);
	bool ValidatePassword(Login login);
	void viewNotification(Login login);
	bool addMsg(std::string name, std::string msg);
	void display();
};