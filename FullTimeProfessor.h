// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include "GraduateStudent.h"
#include "Professor.h"
#include "Course.h"
class FullTimeProfessor : public Professor // a derived class from the base class Professor
{
private:
	GraduateStudent** supervised_grads; //Array of pointers to the GraduateStudents objects under its supervision
	int no_of_supervised_students; // number of students supervised by a full time professor
	int no_of_courses_teaching; // number of courses the professor is teaching
	Course** courses_teaching; //an array of pointers to the objects of courses professor is teaching
public:
	//regular constructor
	FullTimeProfessor(int employee_id, string person_name, Date* person_birthdate, Date* employment_date);
	int getno_of_supervised_students();// getter for the number of students supervised by the full time professor
	void add_supervised_grad(GraduateStudent* grad); //a function to add a graduate student to the array supervised_grads
	void add_teaching_course(Course* c); //adds the course to the courses_teaching array
	GraduateStudent** getsupervised_grads(); // a getter for the array supervised_grads
	int get_no_of_courses_teaching(); // getter for the number of courses teaching
	Course** getcourses_teaching(); // getter for the courses_teaching array
	virtual void print() const; // overrided virtual function to print the course a professor is teaching and the students the professor is supervising
	~FullTimeProfessor(); //destructor
};

