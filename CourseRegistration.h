// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include "Course.h"
class CourseRegistration
{
private:
	Course* course;
	int* enrolled_student_ids;//An array of student_ids of the students registered to the course 
	int no_of_enrolled_students; //number of enrolled students
public:
	CourseRegistration(Course* c); // regular constructor
	int getno_of_enrolled_students() const;// getter for the number of enrolled students
	Course* getcourse(); //gets the object course
	void setcourse(Course*c); // sets the object course
	void register_student(int student_id); // adds the student ID of the registering student to the array enrolled_student_ids, ensuring their enrollment in the course.
	void unregister_student(int student_id);//removes the student ID of the dropping student from the array enrolled_student_ids, removing them from the course enrollment.
	int* getenrolled_student_ids(); // gets the array enrolled_student_ids
	~CourseRegistration(); // destructor for the course registration objects
	int operator+(int value) const; // overloading the + operator so we can add the number of students enrolled in a course to an integer
};

