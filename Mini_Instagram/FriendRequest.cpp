#include "FriendRequest.h"
using namespace std;
FriendRequest::FriendRequest() {
	front = rear = NULL;
}

void FriendRequest::enQueue(string name) {
	if(!front && !rear) {
		front = rear = new Request(name);
	}
	else {
		rear->next = new Request(name);
		rear = rear->next;
	}
}

string FriendRequest::deQueue()
{
	if (!front && !rear)
		return "";

	else {
		string name = front->name;
		Request* temp = front;
		front = front->next;
		delete temp;
		temp = NULL;
		return name;
	}
}

string FriendRequest::Front() {
	if(front)
	return front->name;
}

string FriendRequest::Rear() {
	if(rear)
	return rear->name;
}

bool FriendRequest::isEmpty()
{
	return !front && !rear;
}