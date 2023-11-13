// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include "Date.h"
#include <iostream>
#include <iostream>
using namespace std;
class Person
{ 
	friend ostream& operator<<(ostream& out, const Person& person); // a function to overload the << operator
private:
	string person_name;//The name of the person
	Date* person_birthdate; //The birthdate of the person
public:
	Person(string person_name, Date* person_birthdate);// regular constructor
	string getperson_name() const;//getter for the person's name
	Date* getperson_birthdate() const;
	virtual int getid() const = 0; // virtual getter for the id of the student or professor
	virtual void print() const; // prints the name and birthdate of the person
};

