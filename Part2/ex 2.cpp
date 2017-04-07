#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Student {
public:
	//default initialization is with "undefined"
	Student() : code("undefined"), name("undefined") {};
	//using a member initialization list to initialize code and name
	Student(const string &code, const string &name) : code(code), name(name) {}
	void setGrades(double shortExam, double project, double exam) {
		(*this).shortExam = shortExam;
		(*this).project = project;
		(*this).exam = exam;

		//Ugly typecasting I know but otherwise it would always be 0 - potential solution: put everything in variables - bad because mostly useless variables :/
		double tempFinalGrade = (double) (((double)weightShortExam / 100) * shortExam) + (((double)weightProject / 100) * project) + (((double)weightExam / 100)  * exam);

		//the first part gets the first digit after the . -> 6.5 returns 5, 4.2 returns 2
		//condition is: if the first digit after the . is >= than 5, round it up, otherwise round it down
		(*this).finalGrade = ((((int)tempFinalGrade * 10) % 10) >= 5) ? ceil(tempFinalGrade) : floor(tempFinalGrade);
	}
	string getCode() const { return (*this).code; };
	string getName() const { return (*this).name; };
	int getFinalGrade() const { return (*this).finalGrade; };
	// other get and set methods - apparently not
	// is the student approved or not ?
	bool isApproved() const { return (*this).finalGrade >= 10; };
	static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
private:
	string code; // student code
	string name; // student complete name
	double shortExam, project, exam; // grades obtained by the student in the different components
	int finalGrade;
};

//declaring static variables
int Student::weightShortExam = 20;
int Student::weightProject = 30;
int Student::weightExam = 50;
//Btw this should be done with a public static function that sets these variables, so they can be private, IMO


//Prototype
void requestedFunction(const vector<Student> &vec, ostream &os);

int main() {

	//A - the weights are static because they are the same for all of the students

	//B
	//Creating variables
	string code, name;
	double shortExam, project, exam;
	//Asking for input
	cout << "Student code ? ";
	getline(cin, code);
	cout << "Student name ? ";
	getline(cin, name); //name can have spaces
	cout << "Short exam grade ? ";
	cin >> shortExam;
	cout << "Project grade ? ";
	cin >> project;
	cout << "Exam grade ? ";
	cin >> exam;

	//Creating object and setting values
	Student s(code, name);
	s.setGrades(shortExam, project, exam);

	//C
	//Testing requested function
	vector<Student> vect;

	Student temp("up001", "Arriba Mis Amigos");
	temp.setGrades(2.3, 8, 1);
	vect.push_back(temp);

	Student temp1("up002", "Aiaiai compadre");
	temp1.setGrades(10, 10, 10);
	vect.push_back(temp1);

	Student temp2("up003", "Que dices?");
	temp2.setGrades(20, 20, 20);
	vect.push_back(temp2);

	Student temp3("up004", "Era quase...");
	temp3.setGrades(8, 8, 9);
	vect.push_back(temp3);

	Student temp4("up005", "Fartei");
	temp4.setGrades(18, 19.4, 18.7);
	vect.push_back(temp4);

	//giving cout as the ostream so that the results are printed directly to the screen
	cout << "\nAprooved students:\n\n";
	requestedFunction(vect, cout);

	return 0;
}

//C
void requestedFunction(const vector<Student> &vec, ostream &os) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].isApproved())
			os << left << setw(50) << vec[i].getName() << "\t" << setw(2) << vec[i].getFinalGrade() << "\n";
	}
}