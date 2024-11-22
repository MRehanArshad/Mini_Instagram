#include"Users.h"

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
		root = rotateLeft(root);
	}
	else if (bf < -1 && signup.getUsername() > root->right->username) {
		root = rotateRight(root);
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

User* deleteNode(User* node, std::string name)
{
	if(!node)
		return node;

	if (node->username > name)
		node->right = deleteNode(node->right, name);
	if(node->username < name)
		node->left = deleteNode(node->left, name);

	else if(node->username == name)
	{
		//No Child
		if(!node->left && !node->right)
		{
			delete node;
			node = NULL;
		}
		//1 Child
		if(!node->left && node->right)
		{
			User* temp = node;
			node = node->right;
			delete temp;
		}
		else if(node->left && !node->right)
		{
			User* temp = node;
			node = node->left;
			delete temp;
		}
		//2 Child
		if(node->left && node->right)
		{
			User* temp = getMin(node->right);
			copyNode(node, temp);
			deleteNode(node->right, temp->username);
			delete temp;
		}

		int BF = getHeight(node->left) - getHeight(node->right);

		if(BF > 1)
		{
			int balanceFactor = getHeight(node->left->left) - getHeight(node->left->right);
			if (balanceFactor > 1)
				node = rotateRight(node);
			else if(balanceFactor < -1)
			{
				node->left = rotateLeft(node->left);
				node = rotateRight(node);
			}
		}
		else if(BF < -1)
		{
			int balanceFactor = getHeight(node->right->left) - getHeight(node->right->right);
			if (balanceFactor > 1)
				node = rotateLeft(node);
			else if (balanceFactor < -1)
			{
				node->right = rotateRight(node->right);
				node = rotateLeft(node);
			}
		}
	}
}

//Deletion from Users AVL
void AllUsers::DeleteUser(std::string username)
{
	if(!root)
		return;
	deleteNode(root, username);
}