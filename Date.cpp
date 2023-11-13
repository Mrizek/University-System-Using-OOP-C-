// Name : Mohamed Mrizek Id : 40234343
#include "Date.h"
#include <iostream>
using namespace std;
ostream& operator<<(ostream& out, const Date& date) {
	out << date.month << " / " << date.day << " / " << date.year << endl; //implementation of the overloaded operator <<
	return out;
}
// implementation of the default constructor
Date::Date() {
	month = 0;
	day = 0;
	year = 0;
}
// implementation of the regular constructor
Date::Date(int month, int day, int year) {
	this->month = month;
	this->day = day;
	this->year = year;
}
// return the month
int Date::getmonth() const {
	return month;
}
// return the day
int Date::getday() const {
	return day;
}
// return the year
int Date::getyear() const {
	return year;
}
// sets the month
void Date::setmonth(int month) {
	this->month = month;
}
// sets the day
void Date::setday(int day) {
	this->day = day;
}
//sets the year
void Date::setyear(int year) {
	this->year = year;
}
// prints the values of the data members
void Date::printDate() {
	cout << month << " / " << day << " / " << year << endl;
}
Date::~Date() {
	cout << "Date: " << month << " / " << day << " / " << year << " is destroyed" << endl; // destructor implementation
}