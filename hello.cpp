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



int main() {

	cout<< "Hello Worlrd! \n";

	return 0;
}
