#pragma once
#include"Login.h"
class UserProfile {
	Login user;

public:
	UserProfile();
	UserProfile(Login signup);
	void setUserProfile(Login signup);
	void showProfile();
};