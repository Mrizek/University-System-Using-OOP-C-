// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include "GraduateStudent.h"
#include "Professor.h"
#include "Course.h"
class PartTimeProfessor : public Professor// a derived class from the base class Professor
{
private:
	Course** courses_teaching; //an array of pointers to the objects of courses that the part time professor is teaching 
	int no_of_courses_teaching; // number of courses the professor is teaching
public: 
PartTimeProfessor(int employee_id, string person_name, Date* person_birthdate, Date* employment_date);// regular constructor
void add_teaching_course(Course* c); // a function to add a course to the courses_teaching array
virtual void print() const; // virtual overrided function to print the information about a part time professor
~PartTimeProfessor();//destructor
};


