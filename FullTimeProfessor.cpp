// Name : Mohamed Mrizek Id : 40234343
#include "FullTimeProfessor.h"
#include <iostream>
#include "Professor.h"
FullTimeProfessor::FullTimeProfessor(int employee_id, string person_name, Date* person_birthdate, Date* employment_date)
	:Professor(employee_id,employment_date,person_name,person_birthdate)// regular constructor with a member initializer list calling the constructor of the professor class
{
	// initializing the variables and the arrays
	no_of_supervised_students = 0;
	no_of_courses_teaching = 0;
	supervised_grads = new GraduateStudent * [10];
	courses_teaching = new Course * [2];// a professor teaches 2 courses during a semester and supervises a maximum of 10 students
	for (size_t i = 0; i < 10; i++)
	{
		supervised_grads[i] = nullptr;
	}
	for (size_t i = 0; i < 2; i++)
	{
		courses_teaching[i] = nullptr;
	}
}
int FullTimeProfessor::getno_of_supervised_students() { //getter implementation
	return no_of_supervised_students;
}
void FullTimeProfessor::add_supervised_grad(GraduateStudent* grad) {
	supervised_grads[no_of_supervised_students++] = grad;//adding a graduate student to the supervised_grads array at the position corresponding to the current number of supervised students and adding one
}
void FullTimeProfessor::add_teaching_course(Course* c) {
	if (no_of_courses_teaching < 2) // a full professor can teach a maximum of two courses
	{
		courses_teaching[no_of_courses_teaching++] = c; // adds the course to the array courses_teaching and incrementing the number of courses the professors is teaching
	}
}
GraduateStudent** FullTimeProfessor::getsupervised_grads() {
	return supervised_grads;//getter implementation
}
int FullTimeProfessor::get_no_of_courses_teaching() {
	return no_of_courses_teaching; //getter for the number of courses the professor is teaching
}
Course** FullTimeProfessor::getcourses_teaching() {
	return courses_teaching;//getter implementation
}
void FullTimeProfessor::print() const { //prints information about the fullTime professor
	cout << "The following professor: \n ";
	Professor::print(); cout << "He is teaching the following courses: " << endl;
	for (size_t i = 0; i < no_of_courses_teaching; i++) // for loop to go over the courses the professors is teaching
	{
		cout << "course's number: " << courses_teaching[i]->getcourseNumber() << " and its name is: " << courses_teaching[i]->getcourseName() << endl; //prints info of the course
	}
	if (no_of_courses_teaching == 0)
	{
		cout << "This professor isn't teaching any courses" << endl;
	}
	cout << "Graduate students supervised by the professor " << getperson_name() << " are: " << endl;
	for (size_t i = 0; i < no_of_supervised_students; i++)
	{
		cout << "graduate student name's : " <<supervised_grads[i]->getperson_name() << endl; // prints the name of the graduate students that are in the supervised_grads array
	}
	if (no_of_supervised_students == 0)
	{
		cout << "This professor isn't supervisng any graduate students " << endl;
	}
	cout << "-----------------------------------------------------------" << endl;
}
FullTimeProfessor::~FullTimeProfessor() {
	delete[] supervised_grads;
	delete[] courses_teaching;
	cout << "object containing Full Time professor" << getperson_name() << " is destroyed" << endl; // destructor implemetation
}