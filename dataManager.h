// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include <iostream>
#include "CourseRegistration.h"
#include "FullTimeProfessor.h"
#include "PartTimeProfessor.h"
#include "GraduateStudent.h"
#include "UndergraduateStudent.h"
using namespace std;
class dataManager
{
private: 
	Student** Students;//• An array of pointers named Students to contain UndergraduateStudent and GraduateStudent objects
	Professor** Professors; //• An array of pointers named Professors to contain FullTimeProfessor and PartTimeProfessor objects
	CourseRegistration** coursearray; //• An array of pointers named coursearray to contain CourseRegistration objects
	int numStudents; //Total number of students in the University
	int numUndergraduateStudents; // number of undergraduate students in the Students array
	int numGraduateStudents;// number of Graduate students in the Students array
	int numProfessors; //Total number of professors in the University
	int numFullTimeProfessors;// number of FullTimeProfessors in the Professors array
	int numPartTimeProfessors;// number of PartTimeProfessors in the Professors array
	int numCourseRegistrations;// number of CourseRegistrations in the coursearray array
public:
	dataManager(); //default constructor
	//Overloaded insert functions to add undergraduate student, graduate student, fulltime professor and parttime professor objects to Students and Professor arrays 
	bool insert_info(Student*);
	bool insert_info(Professor*);
	bool insert_course_registration(CourseRegistration*); // insert function to add a new CourseRegistration object to the courseArray.
	bool registering_to_Course(Student*, Course&); //function to register a undergraduate/graduate student to a course.
	bool dropping_a_Course(Student*, Course&); // function that enables dropping of a course by a student.
	void add_old_course(Student*, Grade*); // a function to add a course that was taken before by the student to his transcript
	void setGrade(Student*, int,string); // sets the grade of a course taken currently by a student
	void studentCourses(Student*); //function that receives a student object and displays all the courses that this student has been registered to
	string getstudent_name(int); // return the student name given the student id
	void course_registration_info(Course&); //Given a Course object a function that displays names and student id’s of all students registered to a course.
	bool graduatesupervisor(FullTimeProfessor&, GraduateStudent&);// Insert function to add a professor as a supervisor of a graduate student.
	void FullTimeProfInfo(FullTimeProfessor&); //A function that displays number and names of courses being taught by a full time professor and names of the graduate students under his supervision
	void printcourses(); //A function that displays course numbers and instructors of all the courses the university is offering during a semester.
	void save(string StudentFile);// a function that saves the name, student id, birth date, enrollment date of all students at the university in a text file.If a student is a graduate student, it has to also store name of the supervisor
	void read(int studentid); // void read(int studentid) function
	int getTotal();// a member function that determines sum of the number of students enrolled in all of the courses offered by the university
	~dataManager(); //destructor
};
