#pragma once
#include"SignUp.h"
class UserProfile {
	SignUp* signup;

public:
	UserProfile();
	UserProfile(SignUp* signup);
	void setUserProfile(SignUp* signup);
	void showProfile();
};