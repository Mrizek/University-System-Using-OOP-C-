// Name : Mohamed Mrizek Id : 40234343
#include "CourseRegistration.h"
#include <iostream>
using namespace std;
// regular constructor
CourseRegistration::CourseRegistration(Course* c)
	:course(c),no_of_enrolled_students(0)
{
	enrolled_student_ids = new int[50]; // maximum class size
	for (size_t i = 0; i < 50; i++)
	{
		enrolled_student_ids[i] = 0;
	}
}
int CourseRegistration::getno_of_enrolled_students() const {
	return no_of_enrolled_students; // getter for the number of enrolled students
}
Course* CourseRegistration::getcourse() {
	return course; //getter for the course object
}
void CourseRegistration::setcourse(Course* c) {
	course = c; // setter for the course object
}
void CourseRegistration::register_student(int student_id) {
	
	enrolled_student_ids[no_of_enrolled_students++] = student_id; // add the received student id to the enrolled students

}
void CourseRegistration::unregister_student(int student_id) {
	for (size_t i = 0; i < no_of_enrolled_students; i++)
	{
		if (enrolled_student_ids[i] == student_id) { // searches for the student id of the student about to drop
			for (size_t j = i; j < no_of_enrolled_students-1; j++)
			{
				enrolled_student_ids[j] = enrolled_student_ids[j + 1]; // shift the content of the array so the student id of the student dropping is removed
			}
			no_of_enrolled_students--; // decrements the number of enrolled students
		}
	}
}
int* CourseRegistration::getenrolled_student_ids() {
	return enrolled_student_ids; // getter for the array enrolled_student_ids
}
int CourseRegistration::operator+(int value) const {
	return no_of_enrolled_students + value; // returns the value of the number of enrolled students added to a value passed by the user
}
CourseRegistration::~CourseRegistration() {
	cout << "object containing the course registration " << course->getcourseName() << " is destroyed" << endl; // destructor implemetation
}