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
#include<conio.h>
using namespace std;

void intro()
{
	string str = "\n\n\n\t /$$$$$$                       /$$                                                         \n\t|_  $$_/                      | $$                                                         \n\t  | $$   /$$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$  /$$$$$$/$$$$ \n\t  | $$  | $$__  $$ /$$_____/|_  $$_/   |____  $$ /$$__  $$ /$$__  $$|____  $$| $$_  $$_  $$\n\t  | $$  | $$  \\ $$|  $$$$$$   | $$      /$$$$$$$| $$  \\ $$| $$  \\__/ /$$$$$$$| $$ \\ $$ \\ $$\n\t  | $$  | $$  | $$ \\____  $$  | $$ /$$ /$$__  $$| $$  | $$| $$      /$$__  $$| $$ | $$ | $$\n\t /$$$$$$| $$  | $$ /$$$$$$$/  |  $$$$/|  $$$$$$$|  $$$$$$$| $$     |  $$$$$$$| $$ | $$ | $$\n\t|______/|__/  |__/|_______/    \\___/   \\_______/ \\____  $$|__/      \\_______/|__/ |__/ |__/\n\t                                                 /$$  \\ $$                                 \n\t                                                |  $$$$$$/                                 \n\t                                                 \\______/                                  \n";

	for (char c : str) {
		cout << c;
		Sleep(0);
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

int main() {
	// Variables
	Login login;
	SignUp signup;
	AllUsers alluser;
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
				isLogin = alluser.ValidatePassword(login);
				Sleep(2000);
			}
			else if (choice == 2) {
				signup.SignUpPage();
				alluser.Insert(signup);
				cout << "\n\t\t\tNew SignUp at " << signup.getTimetoSignUp() << endl;
				cout << "\n\t\t\tPress any key to continue....." << endl;
				char ch = _getch();
			}
			else if (choice == 3) {
				exit(0);
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
				cout << "\n\n\t\t\tPress any key continue...." << endl;
				char ch = _getch();
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

				}
				else if (choice == 5) {

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