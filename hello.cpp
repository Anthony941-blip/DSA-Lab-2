#include <iostream>
using namespace std;

struct User {
	string username;
	string password;
	string role; //for authorizatio " author", editor etc.
	User* next;

	User(const string& u, const string& p, const string& r = "viewer") {
		username = u;
		password = p;
		role = r;
		next = nullptr;
	}
};

bool insertUser(User*& head, const string& username, const string& password, const string& role = "viewer");
bool authorize(User* head, const string& username, const string& action);
User* find(User*& head, const string& username);

int main() {

	User* head = nullptr;
	int choice;
	string username, password, action, role;

	do {
		cout << "Authorization:\n";
		cout << "1. Enter user\n";
		cout << "2. Authorize\n";
		cout << "3. Find user\n";
		cin >> choice;
		cin.ignore();

		switch(choice) {
			case 1: {
				cout << "Enter username: ";
				getline(cin, username);
				cout << "Enter password: ";
				getline(cin, password);
				insertUser(head, username, password);
				break;
			}
			case 2: {
				cout << "Enter username: ";
				getline(cin, username);
				cout << "Enter action: ";
				getline(cin, action);
				if(authorize(head, username, action)) {
					cout << "Authorization success!\n";
				} else {
					cout << "Authorization denied!\n";
				}
				break;
			}
			case 3: {
				cout << "Search username: ";
				getline(cin, username);
				User* user = find(head, username);
				if(user) {
					cout << "User <" << user->username <<  "> found!" << ", Role: " << user->role << "\n";
				} else {
					cout << "User not found.\n";
				}
				break;
			}
			case 0:
				cout << "Exiting...\n";
				break;
	}
}
	while(choice != 0);

	return 0;
}



bool insertUser(User*& head, const string& username, const string& password, const string& role) {
	User* temp = head;
	while(temp) {
		if(temp->username == username) {
			return false;
		}
			temp = temp->next;
	}

	User* newUser = new User(username, password, role);

	newUser-> next = head;
 	head = newUser;

	return true;
}


bool authorize(User* head, const string& username, const string& action) {
    User* user = find(head, username);
	 if(!user) {
        	return false;
	}

	if(user->role == "admin") {
        	return true;

	} else if(user->role == "editor") {
        return action == "view" || action == "edit" || action == "create";

 	} else if(user->role == "viewer") {
        	return action == "view";
    }
    return false;
}

User* find(User*& head, const string& username) {
	while(head) {
		if(head->username == username) {
			return head;
		}
		head = head->next;
	}
	return nullptr;
}
