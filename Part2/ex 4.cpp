#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
public:
	//User is created as active by default but it can be specified that he is inactive
	User(string name, bool isActive = true) : name(name), isActive(isActive) {};
	//Is the user active?
	bool isUserActive() const { return isActive; };
	//Sets the user as inactive
	void setUserInactive() { isActive = false; };
	//Sets the user as active
	void setUserActive() { isActive = true; };
private:
	string name;
	bool isActive;
};


//Menu Idea:
//1 Book Management
//1.1 Lend a book
//1.2 Put back a book
//1.3 Mark a book as lost
//1.4 Mark a book as found
//1.5 Display all books and their status
//(...)
//2 User Management
//2.1 Make a user inactive
//2.2 Make a user active again
//2.3 Display all users and their status

int main() {


	return 0;
}