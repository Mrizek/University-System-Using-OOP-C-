// Name : Mohamed Mrizek Id : 40234343
#include "Person.h"
#include <iostream>
using namespace std;
ostream& operator<<(ostream& out, const Person& person) {
	out << "Name: " << person.person_name << " Birthdate: "; person.person_birthdate->printDate(); out << endl; //implementation of the overloaded operator <<
	return out;
}
// regular constructor
Person::Person(string person_name, Date* person_birthdate) {
	this->person_name = person_name;// using "this" operator to initialize the data members
	this->person_birthdate = person_birthdate;
}
// getter for the person's name
string Person::getperson_name() const{
	return person_name;
}
Date* Person::getperson_birthdate() const {
	return person_birthdate; //getter for the person birthdate
}
void Person::print() const {
	cout << "Name: " << person_name << " Birthdate: "; person_birthdate->printDate(); cout << endl; // prints the name and birthdate of the person
}