#include"Notification.h"
using namespace std;

NotificationDetails::NotificationDetails(string message) {
	this->messages = message;
	this->next = nullptr;
}

Notification::Notification() {
	front = rear = nullptr;
}

bool Notification::empty() {
	return (front == nullptr);
}

void Notification::Enqueue(string message) {
	if (empty()) {
		front = new NotificationDetails(message);
		rear = front;
		return;
	}
	NotificationDetails* newNode = new NotificationDetails(message);
	rear->next = newNode;
	rear = rear->next;
}

string Notification::Front() {
	return front->messages;
}

void Notification::Dequeue() {
	if (empty())
		return;
	NotificationDetails* temp = front;
	front = front->next;
	delete temp;
	temp = nullptr;
}


