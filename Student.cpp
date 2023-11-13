// Name : Mohamed Mrizek Id : 40234343
#include "Student.h"
#include "Date.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, Student student) {//implementation of the overloaded operator <<
	out << "Name: " << student.getperson_name() << " Birthdate: "; student.getperson_birthdate()->printDate(); out << endl; // prints the name and birthdate of the person
	out << "student_id: " << student.student_id << " enrollement date: "; student.enrollment_date->printDate(); out << endl;// prints the information about the student
	return out;
}
int Student::idCounter = 400000;
// regular constructor with a member initializer list calling the constructor of the person class
Student::Student(Date* enrollment_date, string person_name, Date* person_birthdate) :Person(person_name, person_birthdate) {
	student_id = idCounter++;//incrementing the static variable to have unique student ids
	this->enrollment_date = enrollment_date;
}
Date* Student::getenrollment_date() const {
	return enrollment_date;
}
int Student::getid() const {
	return student_id;//getter for the student id
}
void Student::setid(int id)  {
	student_id = id; // setter for the id
}
int Student::getcounter() const {
	return idCounter; //getter for the next id
}
void Student::setcounter(int counter) {
	idCounter = counter; // setter for the counter
}
void Student::print() const {
	Person::print();
	cout << "student_id: " << student_id << " enrollement date: "; enrollment_date->printDate(); cout << endl;// prints the information about the student
}