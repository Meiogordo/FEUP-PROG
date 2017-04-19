#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//Describes a client
class Client {
public:
	Client(string name, string street, int doornumber, string postcode, string city)
		: addr(street, doornumber, postcode, city), name(name) {};
	string getName() const { return this->name; };
	string getFormattedAddress() const {
		return addr.street + ", " + (addr.doornumber == -1 ? "s/n" : to_string(addr.doornumber)) + "\n"
			+ addr.postcode + " " + addr.city;
	};
private:
	//Describes the adress
	struct address {
		//Constructor for the struct to be able to use member initialization list in class constructor - it is not required to do this
		//(Or to even use a struct for the adress at all)
		address(string street, int doornumber, string postcode, string city)
			: street(street), doornumber(doornumber), postcode(postcode), city(city) {};
		string street; //street name
		int doornumber; //door number, -1 for s/n
		string postcode; //post code ex: 4200-465
		string city; //city name
	};
	string name;
	address addr;
};
//Describes a product
class Product {
public:
	Product(string description, double price) : description(description), price(price) {};
	double getPrice() const { return price; };
	string getDescription() const { return description; };
private:
	//Product name or description
	string description;
	//Product price
	double price;
};
//Describes a line of the invoice
class Item {
public:
	Item(const Product &p, int quantity) : p(p), quantity(quantity) {};
	string getDescription() const { return p.getDescription(); };
	double getPrice() const { return p.getPrice(); };
	int getQuantity() const { return quantity; };
	double getTotal() const { return p.getPrice() * quantity; };
private:
	Product p;
	int quantity; //Amount of product p to be purchased
};
//The complete invoice
class Invoice {
public:
	Invoice(const Client &c, const vector<Item> &items) : c(c), items(items) {};
	void printCompleteInvoice(ostream &out) const {
		out << c.getName() << endl;
		out << c.getFormattedAddress();
		out << endl << endl;
		out << left << setw(20) << "Description" << right << setw(6) << "Price"
			<< setw(5) << "Qty" << setw(8) << "Total";
		out << endl;
		out << string(20, '-') << " " << string(6, '-') << " " << string(5, '-') << " " << string(8, '-');
		
	};
private:
	Client c;
	vector<Item> items;
};

int main() {

	Client c("Cliente 1", "Rua rua", -1, "4400-000", "Malgem Sul");

	cout << c.getName() << endl << c.getFormattedAddress() << endl;

}