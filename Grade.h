// Name : Mohamed Mrizek Id : 40234343
#pragma once
#include <iostream>
using namespace std;
class Grade
{
private:
	int courseNumber; // example: 244, 573
	string courseName; // example: programming methodology
	string courseGrade; // Course grade will be A, B, C, D, F
public:
	Grade(int courseNumber, string courseName, string courseGrade); // regular constructor
	int getcourseNumber();// getter for the course number
	string getcourseName();// getter for the course name
	string getcourseGrade(); // getter for the course grade 
	void setcourseGrade(string Grade); //setter for the course grade
	~Grade(); // destructor
};
