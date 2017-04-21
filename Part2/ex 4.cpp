#include <iostream>
#include <string>
#include <map>

using namespace std;

//Describes a user
class User {
public:
	//User is created as active by default but it can be specified that he is inactive
	User(string name, bool isActive = true) : name(name), isActive(isActive) {}
	//Gets the user name
	string getName() { return name; }
	//Is the user active?
	bool isUserActive() const { return isActive; }
	//Sets the user as inactive
	void setUserInactive() { isActive = false; }
	//Sets the user as active
	void setUserActive() { isActive = true; }
	//Format is Name : Active/Inactive
	void print(ostream &out) const {
		out << name << " : " << (isActive ? "Active" : "Inactive");
	}
private:
	string name;
	bool isActive;
};

//Overloading insertion operator (<<) for User
ostream& operator <<(ostream &os, const User &u) {
	u.print(os);
	return os;
}

//Describes a book - it is assumed that a book cannot be lost and borrowed at the same time
class Book {
public:
	//Book constructor - requires name, is not borrowed nor lost by default
	Book(string name, bool isBorrowed = false, bool isLost = false)
		: name(name), isBorrowed(isBorrowed), isLost(isLost) {}
	//Gets the book name
	string getBookName() const { return name; }
	//Check if a book is borrowed
	bool isBookBorrowed() const { return isBorrowed; }
	//Check if a book is lost
	bool isBookLost() const { return isLost; }
	//Mark a book as borrowed
	void markBookBorrowed() { isBorrowed = true; isLost = false; }
	//Mark a book as returned (not borrowed)
	void markBookReturned() { isBorrowed = false; }
	//Mark a book as lost
	void markBookLost() { isLost = true; isBorrowed = false; }
	//Mark a book as found (not lost)
	void markBookFound() { isLost = false; }
	//Format is Name : In library/Lost/Borrowed
	void print(ostream &out) const {
		out << name << " : ";
		//If book is not borrowed nor lost it is in the library
		//Else, if it is borrowed it is borrowed, else it is lost
		out << (!isBorrowed && !isLost ? "In library" : isBorrowed ? "Borrowed" : "Lost");
	}
private:
	string name;
	bool isBorrowed;
	bool isLost;
};

//Overloading insertion operator (<<) for Book
ostream& operator <<(ostream &os, const Book &b) {
	b.print(os);
	return os;
}

//Describes a library - we consider it a set of books and users
class Library {
	Library(const map<string, Book> &books, const map<string, User> &users) : books(books), users(users) {}
private:
	map<string, Book> books;
	map<string, User> users;
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
//(...)
//Auto save? Sure

int main() {
	map<string, Book> books;

	Book b1("Lusiadas");
	Book b2("Livro do Desassossego", false, true);
	Book b3("Hitchhiker's Guide to The Galaxy", true);

	//Inserting the books into the map
	books.insert(pair<string, Book>(b1.getBookName(), b1));
	books.insert(pair<string, Book>(b2.getBookName(), b2));
	books.insert(pair<string, Book>(b3.getBookName(), b3));

	map<string, User> users;

	User u1("Josefino");
	User u2("Anderzinho", false);
	User u3("Cenas");

	//Inserting the users into the map
	users.insert(pair<string, User>(u1.getName(), u1));
	users.insert(pair<string, User>(u2.getName(), u2));
	users.insert(pair<string, User>(u3.getName(), u3));

	return 0;
}