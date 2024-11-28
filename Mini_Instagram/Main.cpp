#include<iostream>
#include<Windows.h>
#include"Login.h"
#include"SignUp.h"
#include"Posts.h"
#include"Notification.h"
#include"Messages.h"
#include"FriendRequest.h"
#include"UserProfile.h"
#include"Users.h"
#include<Windows.h>
using namespace std;

void intro()
{
	cout << "\n\n\n"
		<< "\t /$$$$$$                       /$$                                                         \n"
		<< "\t|_  $$_/                      | $$                                                         \n"
		<< "\t  | $$   /$$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$  /$$$$$$/$$$$ \n"
		<< "\t  | $$  | $$__  $$ /$$_____/|_  $$_/   |____  $$ /$$__  $$ /$$__  $$|____  $$| $$_  $$_  $$\n"
		<< "\t  | $$  | $$  \\ $$|  $$$$$$   | $$      /$$$$$$$| $$  \\ $$| $$  \\__/ /$$$$$$$| $$ \\ $$ \\ $$\n"
		<< "\t  | $$  | $$  | $$ \\____  $$  | $$ /$$ /$$__  $$| $$  | $$| $$      /$$__  $$| $$ | $$ | $$\n"
		<< "\t /$$$$$$| $$  | $$ /$$$$$$$/  |  $$$$/|  $$$$$$$|  $$$$$$$| $$     |  $$$$$$$| $$ | $$ | $$\n"
		<< "\t|______/|__/  |__/|_______/    \\___/   \\_______/ \\____  $$|__/      \\_______/|__/ |__/ |__/\n"
		<< "\t                                                 /$$  \\ $$                                 \n"
		<< "\t                                                |  $$$$$$/                                 \n"
		<< "\t                                                 \\______/                                  \n";

}

template<typename T>
void input(T& val) {
	cin >> val;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Wrong input!\n" << "Enter Again: ";
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
	cout << "\n\n\t\t\t\t     Posts Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Add a Post" << endl;
	cout << "\n\t\t\t2. Delete Post" << endl;
	cout << "\n\t\t\t3. Display Posts" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

void MessagesMenu()
{
	cout << "\n\n\t\t\t\t     Message Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Add a Message" << endl;
	cout << "\n\t\t\t2. View Message" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

void FriendsMenu()
{
	cout << "\n\n\t\t\t\t     Friends Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Add a Friend" << endl;
	cout << "\n\t\t\t2. View Friends" << endl;
	cout << "\n\t\t\t2. Block Friends" << endl;
	cout << "\n\t\t\t3. Delete Friends" << endl;
	cout << "\n\t\t\t4. UnBlock Friends" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

void UserProfile(Login login)
{
	system("cls");
	cout << "\t\t\t    Username : " << login.getUsername()<<endl;
	cout << "\n\n\t\t\t\t     Home Page ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Posts" << endl;
	cout << "\n\t\t\t2. Messages" << endl;
	cout << "\n\t\t\t3. Friends" << endl;
	cout << "\n\t\t\t4. View Notifications" << endl;
	cout << "\n\t\t\t5. Log Out" << endl;
	cout << "\n\n\n\t\t ================================================" << endl;
}

int main() {
	// Variables
	Login login;
	SignUp signup;
	AllUsers alluser;
	int choice;
	

	intro();
	Sleep(2000);
	bool isLogin = false;
	while (!isLogin) {
		MainMenu();
		cout << "\n\t\t\tEnter a choice : ";
		cin >> choice;
		cin.ignore();

		if (choice == 1) {
			login.LoginDetails();
			isLogin = alluser.ValidatePassword(login);
			Sleep(2000);
		}
		else if (choice == 2) {
			signup.SignUpPage();
			alluser.Insert(signup);
		}
		else if (choice == 3) {
			exit(0);
		}
	}
	UserProfile(login);
	cout << "\n\t\t\tEnter a choice : ";
	cin >> choice;
	if (choice == 1) {
		PostsMenu();
	}
	else if (choice == 2) {
		MessagesMenu();
	}
	else if (choice == 3) {
		FriendsMenu();
	}
	else if (choice == 4) {

	}
	system("pause");
}