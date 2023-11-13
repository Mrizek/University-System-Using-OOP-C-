// Name : Mohamed Mrizek Id : 40234343
#include "Grade.h"
Grade::Grade(int courseNumber, string courseName, string courseGrade) { // regular constructor
	this->courseNumber = courseNumber; 
	this->courseName = courseName;
	this->courseGrade = courseGrade;
}
int Grade::getcourseNumber() {
	return courseNumber; // getter for the course Number
}
string Grade::getcourseGrade() {
	return courseGrade; // getter for the courseGrade
}
void Grade::setcourseGrade(string Grade) {
	courseGrade = Grade; //setter for the course Grade
}
string Grade::getcourseName() {
	return courseName; // implementation of the course name getter

}
Grade::~Grade() {
	cout << "The grade for the course " << courseNumber << " is destroyed" << endl; // destructor implementation
}