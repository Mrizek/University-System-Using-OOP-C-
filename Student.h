// Name : Mohamed Mrizek Id : 40234343
using namespace std;
#pragma once
#include <iostream>
#include "Date.h"
#include "Person.h"
class Student : public Person// a derived class from the base class Person
{
	friend ostream& operator<<(ostream& out, Student student); // a function to overload the << operator
private:
	int student_id; //student_id as an integer
	Date* enrollment_date; //enrollement date of the student
	static int idCounter;//static variable
public:
	Student( Date* enrollment_date, string person_name, Date* person_birthdate);//regular constructor
	virtual int getid() const; //getter for the student_id
	virtual void setid(int id);// sets the id of the student
	int getcounter() const;// gets the next student id
	void setcounter(int counter) ;//sets the counter
	virtual void print() const;// prints the information about the student
	Date* getenrollment_date() const; // gets the enrollement date of the student
};

