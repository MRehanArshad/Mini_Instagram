#include<iostream>
#include"UserProfile.h"
using namespace std;

UserProfile::UserProfile() { }
UserProfile::UserProfile(Login login) {
	this->user = login;
}
void UserProfile::setUserProfile(Login login) {
	this->user = login;
}
void UserProfile::showProfile() {
	cout << "UserName : " << user.getUsername() << endl;
}
// This is a change