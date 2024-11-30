#pragma once
#include"SignUp.h"
#include"Login.h"
#include"Friend.h"
#include"Notification.h"
#include"Posts.h"
#include"Messages.h"

class User {
public:
	std::string username;
	std::string password;
	std::string date_Of_Birth;
	std::string country;
	std::string timetosignup;
	User* left;
	User* right;
	int height;
	Friend Friend_List;
	Notification notification;
	PostStack posts;
	MessageStack msgStk;
	User();
	User(SignUp signup);
	bool AddFriend(std::string name);
	bool deleteFriend(std::string name);
	bool unblockFriend(std::string key);
	bool blockFriend(std::string key);
	bool viewMessages();
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
	bool addMsg(std::string name, std::string msg);
	void viewNotification(Login login);
	void addPost(Login login, std::string str);
	void deletePost(Login login, std::string str);
	void displayPost(Login login);
	void display(Login login);
	void sendRequest(Login login, std::string username);
	void viewRequest(Login login);
	void AcceptRequest(Login login, std::string str);
	void viewFriends(Login login);
	void BlockFriend(Login login, std::string);
	void DeleteFriend(Login login, std::string);
	void viewBlockFriend(Login login);
	void unBlockFriend(Login login, std::string);
};