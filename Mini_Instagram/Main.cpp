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

int main() {
	Login login;
	SignUp signup;
	intro();
	Sleep(2000);
	signup.SignUpPage();
	system("pause");
}