// Name : Mohamed Mrizek Id : 40234343
#include "GraduateStudent.h"
#include <iostream>
using namespace std;
// regular constructor
GraduateStudent::GraduateStudent(string person_name, Date* person_birthdate, Date* enrollment_date)
	: Student(enrollment_date, person_name, person_birthdate), name_supervisor(""),num_of_courses_taking(0),num_of_grades(0)//The constructor of the student class is called
{
	student_grades = new Grade * [15];// A Graduate student can register upto 3 courses
	for (size_t i = 0; i < 15; i++)
	{
		student_grades[i] = nullptr;
	}
}
bool GraduateStudent::add_newcourse(Course* c) { // adds a new ungraded course to the student_grades array

	student_grades[num_of_courses_taking++] = new Grade(c->getcourseNumber(), c->getcourseName(), ""); // adds the course to the student_grades array
	num_of_grades++;
	return 1;
}
bool GraduateStudent::add_oldcourse(Grade* g) {

	student_grades[num_of_grades++] = g; // adding a graded course already taken by the student to the student_grades array
	return 1;
}
bool GraduateStudent::set_studentGrade(int course_number, string grade) { // adds a grade to a course a student is taking currently
	for (size_t i = 0; i < num_of_grades; i++)
	{
		if (student_grades[i]->getcourseNumber() == course_number) // checks for a match between the course number in the student_grades array and the course number given
		{
			if (student_grades[i]->getcourseGrade() == "") {
				student_grades[i]->setcourseGrade(grade);
				num_of_courses_taking--;
				cout << "a New grade was added to the student dashboard: " << getperson_name() << endl;
				return 1;
			}
			cout << " Sorry this course was already graded";
			return 0;
		}
	}
}
bool GraduateStudent::drop_course(Course* c) {
	for (int i = 0; i < num_of_grades; i++)
	{
		if (student_grades[i]->getcourseNumber() == c->getcourseNumber()) // searches for the course to be dropped 
		{
			for (size_t j = i; j < num_of_grades - 1; j++)
			{
				student_grades[j] = student_grades[j + 1];// shift the content of the array so the course to be dropped is removed
			}
			num_of_courses_taking--;// decrement the number of courses the student is taking
			num_of_grades--;
			return 1;
		}
	}
	return 0;
}
Grade** GraduateStudent::getstudent_grades() {
	return student_grades; //getter implementation

}
int GraduateStudent::getnum_of_courses_taking() {
	return num_of_courses_taking;//getter implementation
}
string GraduateStudent::get_name_supervisor() {
	return name_supervisor;
}
void GraduateStudent::set_name_supervisor(string name_supervisor) {
	this->name_supervisor = name_supervisor; //setter implementation
}
void GraduateStudent::print() const {
	cout << "The following student "; Student::print();
	for (size_t i = 0; i < num_of_grades; i++)// for loop to go over all the courses in the student_grades array
	{
		if (student_grades[i]->getcourseGrade() != "")
		{
			cout << "Courses taken previously by the student";
			cout << "The course Number is: " << student_grades[i]->getcourseNumber() << endl;// displays course number
			cout << "The course Name is: " << student_grades[i]->getcourseName() << endl; // displays course name
			cout << "The Grade of the course is: " << student_grades[i]->getcourseGrade() << endl;// displays the instructor name of the course
		}
		if (student_grades[i]->getcourseGrade() == "")
		{
			cout << "Courses taken currently by the student";
			cout << "The course Number is: " << student_grades[i]->getcourseNumber() << endl;// displays course number
			cout << "The course Name is: " << student_grades[i]->getcourseName() << endl; // displays course name
			cout << "The Grade of the course is: No grade is available cureently " << endl;// displays the instructor name of the course
		}

	}
	if (num_of_grades == 0)
	{
		cout << "sorry, this student isn't registered in any courses" << endl;
	}
	cout << "-----------------------------------------------------------" << endl;

}
void GraduateStudent::print_personal_info() const {
	Student::print(); // printing the personal info of the graduate student
}
GraduateStudent::~GraduateStudent() {
	delete[] student_grades;
	cout << "object containing Graduate student " << getperson_name() << " is destroyed" << endl; // destructor implemetation
}