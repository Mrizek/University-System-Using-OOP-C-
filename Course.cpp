// Name : Mohamed Mrizek Id : 40234343
#include "Course.h"
#include <iostream>
using namespace std;
// regular constructor
Course::Course(int courseNumber, string courseName, string instructorName) {
	this->courseNumber = courseNumber;
	this->courseName = courseName;
	this->instructorName = instructorName;
}
int Course::getcourseNumber() {
	return courseNumber; // implementation the courseNumber getter
}
string Course::getcourseName() {
	return courseName; // implementation of the course name getter

}
string Course::getinstructorName() {
	return instructorName; //implementation of the instructor name getter
}
void Course::print() const {
	cout << "course's number: " << courseNumber << " and it's taught by: " << instructorName << endl; // prints the course number of all the courses in the coursearray array
}
Course::~Course() {
	cout << "object containing the course " << courseName << " is destroyed" << endl; // destructor implemetation
}