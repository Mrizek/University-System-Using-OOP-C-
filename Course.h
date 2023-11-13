// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include <iostream>
using namespace std;
class Course
{
private:
	int courseNumber;//example: 244, 573
	string courseName; // example: programming methodology
	string instructorName; //name of the course instructor
public:
	Course(int courseNumber, string courseName, string instructorName); // regular constructor
	int getcourseNumber(); // getter for the course number
	string getcourseName();// getter for the course name
	string getinstructorName();//getter for the instructor name
	void print() const; // print function used to print the information about a course
	~Course(); //destructor for the course objects
};

