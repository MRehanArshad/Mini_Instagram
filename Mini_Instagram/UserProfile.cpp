#include<iostream>
#include"UserProfile.h"
using namespace std;

UserProfile::UserProfile() {
	signup = nullptr;
}
UserProfile::UserProfile(SignUp* signup) {
	this->signup = signup;
}
void UserProfile::setUserProfile(SignUp* signup) {
	this->signup = signup;
}
void UserProfile::showProfile() {
	cout << "UserName : " << signup->getUsername() << endl;
	cout << "Date Of Birth : " << signup->getDateOfBirth() << endl;
	cout << "Country : " << signup->getCountry() << endl;
}