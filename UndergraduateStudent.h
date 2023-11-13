// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include "Student.h"
#include "CourseRegistration.h"
#include "Course.h"
#include "Grade.h"
class UndergraduateStudent : public Student
{
private:
	int num_of_courses_taking; //Number of courses the student is taking
	Grade* student_grades[15];// array of pointers that regroups the ungraded courses that the student is taking currently and those that are graded and already taken 
	int num_of_grades;// number of objects in student_grades array
public:
	UndergraduateStudent(string person_name, Date* person_birthdate, Date* enrollment_date);// regular constructor
	bool add_newcourse(Course* c); //boolean function to add a course to student_grades array
	bool set_studentGrade(int ,string);// boolean function to grade a student given the number of the course and the grade that the student got
	bool add_oldcourse(Grade* g);// boolean function to an old graded course to the transcript of the student.
	bool drop_course(Course* c);//boolean function to remove a course from registered courses array
	Grade** getstudent_grades();// getter for the student_grades array
	int getnum_of_courses_taking();// getter for the number of courses the student is taking
	virtual void print() const; // virtual function to print the information about the Undergraduate student
	void print_personal_info() const; // prints the personal info of the student
	~UndergraduateStudent();// destructor

};