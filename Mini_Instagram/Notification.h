#pragma once
#include<string>

class NotificationDetails {
public:
	std::string messages;
	NotificationDetails* next;
	NotificationDetails(std::string);
};

class Notification {
	NotificationDetails* front, * rear;
public:
	Notification();
	bool empty();
	void Enqueue(std::string);
	std::string Front();
	void Dequeue();
};