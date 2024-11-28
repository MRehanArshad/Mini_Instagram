#include"Users.h"
#include<iostream>
#include<string>

// Contructor For User Class
User::User() {
	username = "";
	password = "";
	date_Of_Birth = "";
	country = "";
	left = nullptr;
	right = nullptr;
	height = 1;
}

bool User::AddFriend(std::string name) {
	Friend_List.addFriend(name, "Friend");
	return 1;
}

bool User::deleteFriend(std::string name)
{
	return Friend_List.deleteFriend(name);
}

bool User::unblockFriend(std::string key)
{
	return Friend_List.updateFriend(key, key, "Friend");
}

bool User::blockFriend(std::string key)
{
	return Friend_List.updateFriend(key, key, "Blocked");
}

User::User(SignUp signup) {
	username = signup.getUsername();
	password = signup.getPassword();
	date_Of_Birth = signup.getDateOfBirth();
	country = signup.getCountry();
	left = nullptr;
	right = nullptr;
	height = 1;
}

// Contructor of AllUsers Class
AllUsers::AllUsers() {
	root = nullptr;
	userCount = 0;
}
// For Inserting a User
void AllUsers::Insert(SignUp signup) {
	root = InsertUser(root, signup);
	userCount++;
}


// Helper Functions
int getHeight(User* root) {
	if (root == nullptr) return 0;
	return root->height;
}

User* getMin(User* root) {
	if (root && root->left) {
		root = root->left;
	}
	return root;
}

int max(int a, int b) {
	return (a > b ? a : b);
}

void copyNode(User* &u1, User* &u2){
	u1->country = u2->country;
	u1->date_Of_Birth = u2->date_Of_Birth;
	u1->password = u2->password;
	u1->username = u2->username;
	return;
}

User* rotateLeft(User* root) {
	User* right = root->right;
	User* LeftChild = right->left;

	right->left = root;
	root->right = LeftChild;

	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

	return right;
}

User* rotateRight(User* root) {
	User* left = root->left;
	User* RightChild = left->right;

	left->right = root;
	root->left = RightChild;

	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	left->height = max(getHeight(left->left), getHeight(left->right)) + 1;

	return left;
}

// Inserting a User

User* AllUsers::InsertUser(User* root, SignUp signup) {
	if (root == nullptr) {
		return new User(signup);
	}
	if (signup.getUsername() < root->username) {
		root->left = InsertUser(root->left, signup);
	}
	else if (signup.getUsername() > root->username) {
		root->right = InsertUser(root->right, signup);
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	int bf = getHeight(root->left) - getHeight(root->right);

	if (bf > 1 && signup.getUsername() < root->left->username) {
		root = rotateRight(root);
	}
	else if (bf < -1 && signup.getUsername() > root->right->username) {
		root = rotateLeft(root);
	}
	else if (bf > 1 && signup.getUsername() > root->left->username) {
		root->left = rotateLeft(root->left);
		root = rotateRight(root);
	}
	else if (bf < -1 && signup.getUsername() < root->right->username) {
		root->right = rotateRight(root->right);
		root = rotateLeft(root);
	}

	return root;
}

User* deleteNode(User* node, std::string name) {
	if (!node)
		return nullptr;

	// Recursive case for traversing the tree
	if (name < node->username) {
		node->left = deleteNode(node->left, name);
	}
	else if (name > node->username) {
		node->right = deleteNode(node->right, name);
	}
	else {
		// Node to be deleted found

		// Case 1: No child
		if (!node->left && !node->right) {
			delete node;
			return nullptr;
		}

		// Case 2: One child
		if (!node->left) {
			User* temp = node->right;
			delete node;
			return temp;
		}
		if (!node->right) {
			User* temp = node->left;
			delete node;
			return temp;
		}

		// Case 3: Two children
		User* temp = getMin(node->right); // Find the minimum node in the right subtree
		copyNode(node, temp);             // Copy the content of the successor
		node->right = deleteNode(node->right, temp->username);
	}

	// Update the height of the current node
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

	// Balance the node if it becomes unbalanced
	int bf = getHeight(node->left) - getHeight(node->right);

	// Left-Left case
	if (bf > 1 && getHeight(node->left->left) >= getHeight(node->left->right)) {
		return rotateRight(node);
	}

	// Left-Right case
	if (bf > 1 && getHeight(node->left->left) < getHeight(node->left->right)) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	// Right-Right case
	if (bf < -1 && getHeight(node->right->right) >= getHeight(node->right->left)) {
		return rotateLeft(node);
	}

	// Right-Left case
	if (bf < -1 && getHeight(node->right->right) < getHeight(node->right->left)) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}

// Deletion from Users AVL
void AllUsers::DeleteUser(std::string username) {
	if (!root)
		return;
	root = deleteNode(root, username); // Update the root of the tree
}


void preOrder(User* root) {
	if (root == nullptr) return;
	preOrder(root->left);
	std::cout << root->username << std::endl;
	preOrder(root->right);
}

void AllUsers::display() {
	preOrder(root);
}

bool SearchUser(User* root, std::string name, User*& target) {
	if (root == nullptr) return false;
	if (name < root->username) {
		return SearchUser(root->left, name, target);
	}
	else if (name > root->username) {
		return SearchUser(root->right, name, target);
	}
	else {
		target = root;
		return true;
	}
}

bool AllUsers::ValidatePassword(Login login) {
	User* target = nullptr;
	if (!SearchUser(root, login.getUsername(), target)) {
		std::cout<<"\n\t\t\tThis User does not Exsist in the database."<<std::endl;
		return false;
	}
	if (target->password != login.getPassword()) {
		std::cout << "\n\t\t\tPassword didn't match" << std::endl;
		return false;
	}
	std::cout << "\n\t\t\tYou have Successfully Login!!" << std::endl;
	return true;
}