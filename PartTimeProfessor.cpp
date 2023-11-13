// Name : Mohamed Mrizek Id : 40234343
#include "PartTimeProfessor.h"
#include <iostream>
#include "Professor.h"
// regular constructor with a member initializer list calling the constructor of the Professor class
PartTimeProfessor::PartTimeProfessor(int employee_id, string person_name, Date* person_birthdate, Date* employment_date)
	:Professor(employee_id, employment_date, person_name, person_birthdate), no_of_courses_teaching(0)
{
	courses_teaching = new Course * [3]; // a part time professor teaches 3 courses during a semester
	for (size_t i = 0; i < 3; i++)
	{
		courses_teaching[i] = nullptr;
	}
}
void PartTimeProfessor::add_teaching_course(Course* c) {
	if (no_of_courses_teaching < 3) // a part time professor can teach a maximum of three courses
	{
		courses_teaching[no_of_courses_teaching++] = c; // adds the course to the array courses_teaching and incrementing the number of courses the professors is teaching
	}
}
void PartTimeProfessor::print() const {
	cout << "The following professor: \n"; //prints the information about the part time professor
	Professor::print(); cout << "He is teaching the following courses: " << endl;
	for (size_t i = 0; i < no_of_courses_teaching; i++)
	{
		cout << "course's number: " << courses_teaching[i]->getcourseNumber() << " and its name is: " << courses_teaching[i]->getcourseName() << endl; //prints info of the course
	}
	if (no_of_courses_teaching == 0)
	{
		cout << "This professor isn't teaching any courses" << endl;
	}
}
PartTimeProfessor::~PartTimeProfessor() {
	delete[] courses_teaching;
	cout << "object containing Part Time professor " << getperson_name() << " is destroyed" << endl; // destructor implemetation
}