// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include "Person.h"
class Professor : public Person // a derived class from the base class Person
{
private:
	int employee_id;//Each employee is assigned a unique id
	Date* employment_date;//Employee’s hiring date
public:
	Professor(int employee_id, Date* employment_date, string person_name, Date* person_birthdate);// regular constructor
	virtual int getid() const; //getter for the id of the employee
	virtual void print() const; // prints the information about the professor
};

