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

void MainMenu() {
	system("cls");
	cout << "\n\n\t\t\t\t     Page 1 ";
	cout << "\n\t\t ================================================" << endl;
	cout << "\n\n\n\t\t\t1. Login" << endl;
	cout << "\n\t\t\t2. SignUp" << endl;
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
	MainMenu();
	cout << "\n\t\t\tEnter a choice : ";
	cin >> choice;
	cin.ignore();

	if (choice == 1) {
		login.LoginDetails();
	}
	else if (choice == 2) {
		signup.SignUpPage();
		alluser.Insert(signup);
	}

	system("pause");
}