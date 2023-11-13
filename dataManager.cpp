// Name : Mohamed Mrizek Id : 40234343
#include "dataManager.h"
#include "Course.h"
#include "Date.h"
#include "FullTimeProfessor.h"
#include "PartTimeProfessor.h"
#include "GraduateStudent.h"
#include "UndergraduateStudent.h"
#include "CourseRegistration.h"
#include <iostream>
#include <fstream>
using namespace std;
dataManager::dataManager() {
	Students = new Student*[2300]; // 2000 is the maximum number of undergraduate students that can be enrolled in the University + 300 is the maximum number of Graduate student that can be enrolled in the University
	Professors = new Professor*[50];  // 40 is the maximum number of Full time profressors employed in the University + 10 is the maximum number of Part time Professor employed in the University 
	coursearray = new CourseRegistration* [50];  // 50 is the maximum number of courses in the University
	for (size_t i = 0; i < 2300; i++)
	{
		Students[i] = nullptr;

	}
	for (size_t i = 0; i < 50; i++)
	{
		Professors[i] = nullptr;
	}
	for (size_t i = 0; i < 50; i++)
	{
		coursearray[i] = nullptr;
	}
	numStudents = 0;
	numUndergraduateStudents = 0;
	numGraduateStudents = 0;
	numFullTimeProfessors = 0;
	numPartTimeProfessors = 0;
	numProfessors = 0;
	numCourseRegistrations = 0;
}

bool dataManager::insert_info(Student* student) {
	UndergraduateStudent* ugstudent = dynamic_cast <UndergraduateStudent*>(student); // Attempting to downcast the base class pointer 'student' to an 'UndergraduateStudent' pointer.
	if (ugstudent !=0)
	{
		if (numUndergraduateStudents < 2000) // checks if the limit is reached
		{
			Students[numStudents++] = ugstudent; // adds the undergraduate student to the Students array and increments the number of undergraduate students and students
			numUndergraduateStudents++;
			return 1;
		}
		else
		{
			cout << "The maximum number of undergraduate students enrolled in the University is reached ";
			return 0;
		}
	}
	else
	{
		GraduateStudent* gradstudent = dynamic_cast <GraduateStudent*>(student);

		if (numGraduateStudents < 300) // checks if the limit is reached
		{
			Students[numStudents++] = gradstudent; // adds the Graduate student to the Students array and increments the number of Graduate students
			numGraduateStudents++;
			return 1;
		}
		else
		{
			cout << "The maximum number of Graduate students enrolled in the University is reached ";
			return 0;
		}
	}
	
}

bool dataManager::insert_info(Professor* professor) {
	FullTimeProfessor* ftprofessor = dynamic_cast<FullTimeProfessor*>(professor);
	if (ftprofessor != 0)
	{
		if (numFullTimeProfessors < 40) // checks if the limit is reached 
		{
			Professors[numProfessors++] = ftprofessor;// adds the Full time professors to the Professors array and increments the number of full time professors 
			numFullTimeProfessors++;
			return 1;
		}
		else
		{
			cout << "The maximum number of Full time professors employed in the University is reached ";
			return 0;
		}
	}
	else
	{
		PartTimeProfessor* ptprofessor = dynamic_cast<PartTimeProfessor*>(professor);
		if (numPartTimeProfessors < 10) // checks if the limit is reached
		{
			Professors[numProfessors++] = ptprofessor;// adds the Part time professors to the Professors array and increments the number of part time professors 
			numPartTimeProfessors++;
			return 1;
		}
		else
		{
			cout << "The maximum number of Part time professors employed in the University is reached ";
			return 0;
		}
	}
}

bool dataManager::insert_course_registration(CourseRegistration* course_reg) {
	if (numCourseRegistrations < 50) // checks if the limit is reached
	{
		coursearray[numCourseRegistrations++] = course_reg;// adds the course to the coursearray array and increments the number of course registrations
		for (size_t i = 0; i < numProfessors; i++)
		{
			if (course_reg->getcourse()->getinstructorName() == Professors[i]->getperson_name()) {
				FullTimeProfessor* ftprofessor = dynamic_cast <FullTimeProfessor*> (Professors[i]);
				if (ftprofessor != 0)
				{
					ftprofessor->add_teaching_course(course_reg->getcourse()); //adds the course to the array courses_teaching in the FullTimeProfessor class
				}
				else
				{
					PartTimeProfessor* ptprofessor = dynamic_cast <PartTimeProfessor*>(Professors[i]);
					ptprofessor->add_teaching_course(course_reg->getcourse()); //adds the course to the array courses_teaching in the PartTimeProfessor class
				}
			}
		}
	}
	else
	{
		cout << "The maximum number of Courses in the University is reached ";
		return 0;
	}
}
bool dataManager::registering_to_Course(Student* student, Course& c) {
	for (size_t i = 0; i < numCourseRegistrations; i++)
	{
		if (coursearray[i]->getcourse()->getcourseNumber() == c.getcourseNumber()) { // searches for the course in the coursearray
			UndergraduateStudent* ugstudent = dynamic_cast <UndergraduateStudent*>(student);
			if (ugstudent != 0)
			{
				if (coursearray[i]->getno_of_enrolled_students() < 50)
				{
					if (ugstudent->getnum_of_courses_taking() < 6) // checks if the maximum number of courses that a student can take is reached
					{
						coursearray[i]->register_student(ugstudent->getid()); //adds the student id in the array of enrolled student ids in the CourseRegistration object
						ugstudent->add_newcourse(&c);// adds the course to the array of courses the student is taking
						return 1;
					}
					else
					{
						cout << "The student can't take more than 6 courses";
					}
				}
			}
			else
			{
				GraduateStudent* gradstudent = dynamic_cast <GraduateStudent*>(student);
				if (coursearray[i]->getno_of_enrolled_students() < 20)
				{
					if (gradstudent->getnum_of_courses_taking() < 3) // checks if the maximum number of courses that a student can take is reached
					{
						coursearray[i]->register_student(gradstudent->getid()); //adds the student id in the array of enrolled student ids in the CourseRegistration object
						gradstudent->add_newcourse(&c);// adds the course to the array of courses the student is taking
						return 1;
					}
				}
			}
		}

	}
	return 0;
}
bool dataManager::dropping_a_Course(Student* student, Course& c){
	for (size_t i = 0; i < numCourseRegistrations; i++)
	{
		if (coursearray[i]->getcourse()->getcourseNumber() == c.getcourseNumber()) {// searches for the course in the coursearray
			UndergraduateStudent* ugstudent = dynamic_cast <UndergraduateStudent*>(student);
			if (ugstudent != 0)
			{
				coursearray[i]->unregister_student(ugstudent->getid()); // removes the student id from the arrays of enrolled student ids in the CourseRegistration object
				ugstudent->drop_course(&c);//removes the course from the array of courses the student is taking
				return 1;
			}
			else
			{
				GraduateStudent* gradstudent = dynamic_cast <GraduateStudent*>(student);
				coursearray[i]->unregister_student(gradstudent->getid());// removes the student id from the arrays of enrolled student ids in the CourseRegistration object
				gradstudent->drop_course(&c);//removes the course from the array of courses the student is taking
				return 1;
			}

		}
	}
	return 0;
}
void dataManager::add_old_course(Student* student, Grade* grade) { // adds a course already taken to the transcript of the student
	UndergraduateStudent* ugstudent = dynamic_cast <UndergraduateStudent*>(student);
	if (ugstudent != 0) { // checks if the student is an undergraduate
		ugstudent->add_oldcourse(grade);
	}
	else
	{
		GraduateStudent* gradstudent = dynamic_cast <GraduateStudent*>(student);
		gradstudent->add_oldcourse(grade);
	}

}
void dataManager::setGrade(Student* student, int courseNumber, string grade) { // sets the grade of a course a student is taking currently
	UndergraduateStudent* ugstudent = dynamic_cast <UndergraduateStudent*>(student);
	if (ugstudent != 0){ // checks if the student is an undergraduate
		ugstudent->set_studentGrade(courseNumber, grade);
	}
	else
	{
		GraduateStudent* gradstudent = dynamic_cast <GraduateStudent*>(student);
		gradstudent->set_studentGrade(courseNumber, grade);
	}
}
void dataManager::studentCourses(Student* student) {
	student->print();
}

string dataManager::getstudent_name(int student_id) { // this function is to get the student name if we have his student id
	for (size_t i = 0; i < numStudents; i++)
	{
		if (Students[i]->getid() == student_id) { //find the student id
			return Students[i]->getperson_name();// return the student name
		}
	}

}
void dataManager::course_registration_info(Course& c) {
	cout << "The students enrolled in " << c.getcourseName() << " are the following: " << endl;
	for (size_t i = 0; i < numCourseRegistrations; i++)
	{
		if (coursearray[i]->getcourse()->getcourseNumber() == c.getcourseNumber())// searches for the course c in the coursearray
		{
			for (size_t j = 0; j < coursearray[i]->getno_of_enrolled_students(); j++) // the for loop is to go over all the enrolled students
			{
				cout << "Student's name: " << getstudent_name(coursearray[i]->getenrolled_student_ids()[j]) << " Student's id: " << coursearray[i]->getenrolled_student_ids()[j] << endl;//displays information of all the students
			}
			if (coursearray[i]->getenrolled_student_ids()==0)
			{
				cout << "No one is registered in this course" << endl;
			}
		}
	}
	cout << "-----------------------------------------------------------" << endl;
}
bool dataManager::graduatesupervisor(FullTimeProfessor& prof, GraduateStudent& gradstudent){
	if (prof.getno_of_supervised_students()< 10 )
	{
		prof.add_supervised_grad(&gradstudent); // adds the graduate student to the array of supervised grads in the fulltime professor object
		gradstudent.set_name_supervisor(prof.getperson_name()); // sets the name of the supervisor in the graduate student object
		return 1;
	}
	else
	{
		return 0;
	}
}
void dataManager::FullTimeProfInfo(FullTimeProfessor& prof) {

	prof.print();
}
void dataManager::printcourses() {
	cout << "The University offers the following courses: " << endl;
	for (size_t i = 0; i < numCourseRegistrations; i++) // a for loop to go over all the elements in the coursearray
	{
		coursearray[i]->getcourse()->print();
	}
	cout << "-----------------------------------------------------------" << endl;
}
int dataManager::getTotal() {  //function that determines sum of the number of students enrolled in all of the courses offered by the university
	int total = 0;
	for (size_t i = 0; i < numCourseRegistrations; i++)// a for loop to go over all the elements in the coursearray
	{
		total = *(coursearray[i]) + total; // adds the number of enrolled students to the total
	}
	return total;//returns the total
}void dataManager::save(string StudentFile) {
	ofstream out;
	out.open(StudentFile);//opens the file
	if (!out)//checks if the file is opened succefully
	{
		throw "StudentFile couldn't be opened"; // throw an exception otherwise
	}
	for (size_t i = 0; i < numStudents; i++)
	{
		if (dynamic_cast<UndergraduateStudent*> (Students[i])) //determines if the class of the object is Undergraduate or Graduate
		{
			out << "ugstudent "; 
		}
		else
		{
			out << "gstudent ";
		}
		out << Students[i]->getperson_name() << " " << Students[i]->getperson_birthdate()->getmonth() << " " // inserts the info in the file
			<< Students[i]->getperson_birthdate()->getday() << " "
			<< Students[i]->getperson_birthdate()->getyear() << " "
			<< Students[i]->getid() << " "
			<< Students[i]->getenrollment_date()->getmonth() << " "
			<< Students[i]->getenrollment_date()->getday() << " "
			<< Students[i]->getenrollment_date()->getyear() << " ";
		if (dynamic_cast<GraduateStudent*> (Students[i]))
		{
			GraduateStudent* gradstudent = dynamic_cast<GraduateStudent*> (Students[i]);
			out<<gradstudent->get_name_supervisor(); // if it is a graduate student, we need to insert the supervisor name also
		}
		out << endl;
	}
	out.close(); // closes the file
}
void dataManager::read(int studentid) {
	ifstream in;
	string studentFile = "Studentinfo.txt";
	in.open(studentFile); // opens the file
	if (!in)
	{
		throw "File cannot be opened";// throws an exception if the file couldn't be opened
	}
	// intitalising the variables to extract from the file
	string classname;
	string name;
	int birthdate_month;
	int birthdate_day;
	int birthdate_year;
	int tempstudent_id;
	int enrollment_date_month;
	int enrollment_date_day;
	int enrollment_date_year;
	string supervisor_name;
	bool found = false; // a boolean variable to track if the student is found or not
	while (in >> classname >> name >> birthdate_month >> birthdate_day >>birthdate_year>> tempstudent_id >> enrollment_date_month >> enrollment_date_day >> enrollment_date_year)// extracting the variables of the file
	{
		if (classname == "gstudent")
		{
			in >> supervisor_name; // need to extract also the supervisor name if the student is a Graduate Student
		}
		if (tempstudent_id == studentid)
		{
			found = true;
			if (classname == "ugstudent") {
				Date birthdate = Date(birthdate_month, birthdate_day, birthdate_year); // creating the necessary objects
				Date enrollmentdate = Date(enrollment_date_month, enrollment_date_day, enrollment_date_year);
				UndergraduateStudent ugstudent(name, &(birthdate), &(enrollmentdate));
				ugstudent.setid(studentid); // setting the id of the student
				ugstudent.setcounter(ugstudent.getcounter() - 1); // decrementing the counter because an unnecessary incrementing occured when creating the undergraduate student object
				ugstudent.print_personal_info();// printing the personal info of the graduate student

			}
			if (classname == "gstudent") {
				Date birthdate = Date(birthdate_month, birthdate_day, birthdate_year);// creating the necessary objects
				Date enrollmentdate = Date(enrollment_date_month, enrollment_date_day, enrollment_date_year);
				GraduateStudent gradstudent(name, &(birthdate), &(enrollmentdate));
				in >> supervisor_name;
				gradstudent.set_name_supervisor(supervisor_name); // setting the name of the supervisor
				gradstudent.setid(studentid);// setting the id of the student
				gradstudent.setcounter(gradstudent.getcounter() - 1);// decrementing the counter because an unnecessary incrementing occured when creating the graduate student object
				gradstudent.print_personal_info(); // printing the personal info of the graduate student

			}
		}
	}
	if (found ==false)
	{
		throw "Student cannot be found"; // throws an exception if the student is not found
	}
	in.close();

}
dataManager::~dataManager(){

	delete[]Students;
	delete[]Professors;
	delete[]coursearray;

	cout << "The Students, Professors and the coursearray arrays are destroyed" << endl;
}
