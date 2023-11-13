// Name : Mohamed Mrizek Id : 40234343
#include "Professor.h"
#include <iostream>;
using namespace std;
// regular constructor with a member initializer list calling the constructor of the person class
Professor::Professor(int employee_id, Date* employment_date,string person_name, Date* person_birthdate)
	:Person(person_name, person_birthdate) {
	this->employee_id = employee_id;// using "this" operator to initialize the data members
	this->employment_date = employment_date;
}
int Professor::getid() const {
	return employee_id;//getter for the student id
}
void Professor::print() const {
	Person::print();
	cout << "Employee id: " << employee_id << " Employment date: "; employment_date->printDate(); cout << endl; // prints the information about the professor
}
