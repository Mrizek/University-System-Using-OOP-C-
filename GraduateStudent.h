#pragma once
// Name : Mohamed Mrizek Id : 40234343
#include "Student.h"
#include "Course.h"
#include "CourseRegistration.h"
#include "Grade.h"
class GraduateStudent : public Student
{
private:
	string name_supervisor; // Supervisor is a full time professor
	int num_of_courses_taking; //Number of courses the student is taking
	Grade** student_grades; // array of pointers that regroups the ungraded courses that the student is taking currently and those that are graded and already taken 
	int num_of_grades;// number of objects in the student_grades array
public:
	GraduateStudent(string person_name, Date* person_birthdate, Date* enrollment_date); // regular constuctor
	bool add_newcourse(Course* c); //boolean function to add a course to the student_grades array
	bool set_studentGrade(int, string);// boolean function to grade a student given the number of the course and the grade that the student got
	bool add_oldcourse(Grade* g);// boolean function to add an old graded course to the transcript of the student.
	bool drop_course(Course* c);//boolean function to remove a course from the student_grades array
	Grade** getstudent_grades();// getter for the student_grades array
	int getnum_of_courses_taking();// getter for the number of courses the student is taking
	string get_name_supervisor(); // getter for the name of the supervisor
	void set_name_supervisor(string name_supervisor); //setter for the supervisor_name
	virtual void print() const; // virtual function to print the information about the graduate student
	void print_personal_info() const;// prints the personal info of the student
	~GraduateStudent(); //destructor
};

