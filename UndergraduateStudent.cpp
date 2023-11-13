// Name : Mohamed Mrizek Id : 40234343
#include "UndergraduateStudent.h"
#include <iostream>
using namespace std;
// regular constructor
UndergraduateStudent::UndergraduateStudent(string person_name, Date* person_birthdate, Date* enrollment_date)
	: Student(enrollment_date, person_name, person_birthdate), num_of_courses_taking(0),num_of_grades(0)  //The constructor of the student class is called
{
	for (size_t i = 0; i < 15; i++)
	{
		student_grades[i] = nullptr;
	}
}
bool UndergraduateStudent::add_newcourse(Course* c) {// adding a course already taken by the student
	student_grades[num_of_courses_taking++] = new Grade(c->getcourseNumber(),c->getcourseName(),""); // adds the course to the registered_courses array
	num_of_grades++;
	return 1;

}
bool UndergraduateStudent::add_oldcourse(Grade* g) {

	student_grades[num_of_grades++] = g; // adds the course to the registered_courses array
	return 1;
}
bool UndergraduateStudent::set_studentGrade(int course_number, string grade) { ;// boolean function to grade a student given the number of the course and the grade that the student got
	for (size_t i = 0; i < num_of_grades; i++) // for loop to search for the course
	{
		if (student_grades[i]->getcourseNumber()==course_number) // checks for a match between the course number in the student_grades array and the course number given
		{
			student_grades[i]->setcourseGrade(grade);
			num_of_courses_taking--;
			cout << "a New grade was added to the student dashboard: " << getperson_name() << endl;
			cout << "-----------------------------------------------------------" << endl;
			return 1;
			
		}
	}
}
bool UndergraduateStudent::drop_course(Course* c) {
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
Grade** UndergraduateStudent::getstudent_grades() {
	return student_grades; //getter implementation

}
int UndergraduateStudent::getnum_of_courses_taking() {
	return num_of_courses_taking;//getter implementation
}
void UndergraduateStudent::print() const {
	cout << "The following student "; Student::print();
	for (size_t i = 0; i < num_of_grades; i++)// for loop to go over all the courses in the registered courses array
	{
		if (student_grades[i]->getcourseGrade()!= "")
		{
			cout << "Course taken previously by the student: \n" ;
			cout << "The course Number is: " << student_grades[i]->getcourseNumber() << endl;// displays course number
			cout << "The course Name is: " << student_grades[i]->getcourseName() << endl; // displays course name
			cout << "The Grade of the course is: " << student_grades[i]->getcourseGrade() << endl<<endl;// displays the instructor name of the course
		}
		else if(student_grades[i]->getcourseGrade() == "")
		{
			cout << "Course taken currently by the student \n";
			cout << "The course Number is: " << student_grades[i]->getcourseNumber() << endl;// displays course number
			cout << "The course Name is: " << student_grades[i]->getcourseName() << endl; // displays course name
			cout << "The Grade of the course is: No grade is available cureently\n " << endl;// displays the instructor name of the course
		}
	
		
	}
if (num_of_grades == 0)
	{
		cout << "sorry, this student isn't registered in any courses" << endl;
	}
	cout << "-----------------------------------------------------------" << endl;

}
void UndergraduateStudent::print_personal_info() const {
	Student::print();// prints the personal info of the Undergraduate student
}

UndergraduateStudent::~UndergraduateStudent() {
	for (size_t i = 0; i < 15; i++)
	{
		delete student_grades[i];
	}
	cout << "object containing Undergraduate student " << getperson_name() << " is destroyed" << endl; // destructor implemetation
}