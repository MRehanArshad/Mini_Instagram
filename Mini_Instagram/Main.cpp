#include<iostream>
#include<Windows.h>
#include"Login.h"
#include"SignUp.h"
#include"Posts.h"
#include"Notification.h"
#include"Messages.h"
#include<string>
#include"FriendRequest.h"
#include"UserProfile.h"
#include"Users.h"
#include<conio.h>
#include<fstream>
#include"Friend.h"
#include "Messages.h"
#include"HashTable.h"

using namespace std;

void intro()
{
	string str = "\n\n\n\t /$$$$$$                       /$$                                                         \n\t|_  $$_/                      | $$                                                         \n\t  | $$   /$$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$  /$$$$$$/$$$$ \n\t  | $$  | $$__  $$ /$$_____/|_  $$_/   |____  $$ /$$__  $$ /$$__  $$|____  $$| $$_  $$_  $$\n\t  | $$  | $$  \\ $$|  $$$$$$   | $$      /$$$$$$$| $$  \\ $$| $$  \\__/ /$$$$$$$| $$ \\ $$ \\ $$\n\t  | $$  | $$  | $$ \\____  $$  | $$ /$$ /$$__  $$| $$  | $$| $$      /$$__  $$| $$ | $$ | $$\n\t /$$$$$$| $$  | $$ /$$$$$$$/  |  $$$$/|  $$$$$$$|  $$$$$$$| $$     |  $$$$$$$| $$ | $$ | $$\n\t|______/|__/  |__/|_______/    \\___/   \\_______/ \\____  $$|__/      \\_______/|__/ |__/ |__/\n\t                                                 /$$  \\ $$                                 \n\t                                                |  $$$$$$/                                 \n\t                                                 \\______/                                  \n";

	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
		Sleep(0.5);
	}
}

template<typename T>
void input(T& val) {
	cin >> val;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n\t\t\tWrong input!\n" << "\t\t\tEnter Again: ";
		cin >> val;
	}
}

void MainMenu() {
	system("cls");
	cout << "\n\n\t\t\t\t     Page 1 ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Login" << endl;
	cout << "\n\t\t\t2. SignUp" << endl;
	cout << "\n\t\t\t3. Exit" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

void PostsMenu()
{
	system("cls");
	cout << "\n\n\t\t\t\t     Posts Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Add a Post" << endl;
	cout << "\n\t\t\t2. Delete Post" << endl;
	cout << "\n\t\t\t3. Display Posts" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

void MessagesMenu()
{
	system("cls");
	cout << "\n\n\t\t\t\t     Message Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Add a Message" << endl;
	cout << "\n\t\t\t2. View Message" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

void FriendsMenu()
{
	system("cls");
	cout << "\n\n\t\t\t\t     Friends Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Send Friend Request" << endl;
	cout << "\n\t\t\t2. View Friend Request" << endl;
	cout << "\n\t\t\t3. View Friends" << endl;
	cout << "\n\t\t\t4. Block Friends" << endl;
	cout << "\n\t\t\t5. Delete Friends" << endl;
	cout << "\n\t\t\t6. UnBlock Friends" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

void UserProfile(Login login)
{
	system("cls");
	cout << "\t\t\t    Username : " << login.getUsername() << endl;
	cout << "\n\n\t\t\t\t     Home Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Posts" << endl;
	cout << "\n\t\t\t2. Messages" << endl;
	cout << "\n\t\t\t3. Friends" << endl;
	cout << "\n\t\t\t4. View Notifications" << endl;
	cout << "\n\t\t\t5. Log Out" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

void exit_Menu(AllUsers OBJ) {
	exit(0);
}

int main() {
	// Variables
	Login login;
	SignUp signup;
	AllUsers alluser;
	HashMap hashmap(30);
	int choice;
	string str;

	intro();
	Sleep(2000);
	while (1) {
		bool isLogin = false;
		while (!isLogin) {
			MainMenu();
			cout << "\n\t\t\tEnter a choice : ";
			input(choice);
			cin.ignore();

			if (choice == 1) {
				login.LoginDetails();
				string password = hashmap.Retrive(login.getUsername());
				if (password == login.getPassword()) {
					std::cout << "\n\t\t\tYou have Successfully Login!!" << std::endl;
					isLogin = true;
				}
				else if(password != "") {
					std::cout << "\n\t\t\tPassword didn't match" << std::endl;
					isLogin = false;
				}
				else {
					std::cout << "\n\t\t\tThis User does not Exsist in the database." << std::endl;
					isLogin = false;
				}
				Sleep(2000);
			}
			else if (choice == 2) {
				signup.SignUpPage();
				alluser.Insert(signup);
				hashmap.Insert(signup.getUsername(), signup.getPassword());
				cout << "\n\t\t\tNew SignUp at " << signup.getTimetoSignUp() << endl;
				cout << "\n\t\t\tPress any key to continue....." << endl;
				char ch = _getch();
			}
			else if (choice == 3) {
				exit_Menu(alluser);
			}
		}
		bool logout = false;
		while (!logout) {
			UserProfile(login);
			cout << "\n\t\t\tEnter a choice : ";
			input(choice);
			cin.ignore();
			if (choice == 1) {
				PostsMenu();
				cout << "\n\t\t\tEnter a choice : ";
				input(choice);
				cin.ignore();
				if (choice == 1) {
					cout << "\n\n\t\t\tEnter a Post : ";
					getline(cin, str);
					alluser.addPost(login, str);
				}
				else if (choice == 2) {
					cout << "\n\n\t\t\tEnter a Post to Delete : ";
					getline(cin, str);
					alluser.deletePost(login, str);
				}
				else if (choice == 3) {
					alluser.displayPost(login);
					cout << "\n\n\t\t\tPress any key continue...." << endl;
					char ch = _getch();
				}
			}
			else if (choice == 2) {
				MessagesMenu();
				cout << "\n\t\t\tEnter the choice : ";
				input(choice);
				cin.ignore();
				if (choice == 1) {
					alluser.viewFriends(login);
					cout << "\n\t\t\tEnter name of friend to message : ";
					getline(cin, str);
					string message;
					cout << "\n\t\t\tEnter the Message : ";
					getline(cin, message);
					alluser.addMsg(login, str, message);
				}
				else if (choice == 2) {
					alluser.viewMessage(login);
					cout << "\n\n\t\t\tPress any key continue...." << endl;
					char ch = _getch();
				}
			}
			else if (choice == 3) {
				FriendsMenu();
				cout << "\n\t\t\tEnter a choice : ";
				input(choice);
				cin.ignore();
				if (choice == 1) {
					alluser.display(login);
					cout << "\n\t\t\tGive Username to send friend request : ";
					getline(cin, str);
					alluser.sendRequest(login, str);
					cout << "\n\n\t\t\tPress any key continue...." << endl;
					char ch = _getch();
				}
				else if (choice == 2) {
					alluser.viewRequest(login);
					cout << "\n\t\t\tGive Username to send friend request : ";
					getline(cin, str);
					alluser.AcceptRequest(login, str);
					cout << "\n\n\t\t\tPress any key continue...." << endl;
					char ch = _getch();
				}
				else if (choice == 3) {
					alluser.viewFriends(login);
					cout << "\n\n\t\t\tPress any key continue...." << endl;
					char ch = _getch();
				}
				else if (choice == 4) {
					alluser.viewFriends(login);
					cout << "\n\t\t\tEnter the username to block : ";
					getline(cin, str);
					alluser.BlockFriend(login, str);
				}
				else if (choice == 5) {
					alluser.viewFriends(login);
					cout << "\n\t\t\tEnter the username to delete : ";
					getline(cin, str);
					alluser.DeleteFriend(login, str);
				}
				else if (choice == 6) {
					alluser.viewBlockFriend(login);
					cout << "\n\t\t\tEnter the username to unblock : ";
					getline(cin, str);
					alluser.unBlockFriend(login, str);
				}
			}
			else if (choice == 4) {
				alluser.viewNotification(login);
				cout << "\n\n\t\t\tPress any key continue...." << endl;
				char ch = _getch();
			}
			else if (choice == 5) {
				cout << "\n\n\t\t\tLogout Successfully........" << endl;
				Sleep(2000);
				logout = true;
			}
		}
	}
	system("pause");
}