// Name : Mohamed Mrizek Id : 40234343
#include "dataManager.h"
#include "Course.h"
#include "Date.h"
#include "FullTimeProfessor.h"
#include "PartTimeProfessor.h"
#include "GraduateStudent.h"
#include "UndergraduateStudent.h"
#include "CourseRegistration.h"
#include "Grade.h"
#include <iostream>
using namespace std;
int main()
{
    dataManager* the_dean = new dataManager; //Creates an object of dataManager class
    //Creates objects of different classes and insert them to their arrays
    Date* birthdate1 = new Date(1998, 4, 15);
    Date* enrollDate1 = new Date(2020, 9, 1);
    UndergraduateStudent *student1= new UndergraduateStudent("Ferguson",birthdate1,enrollDate1);
    the_dean->insert_info(student1);

    Date* birthdate2 = new Date(1995, 9, 3);
    Date* enrollDate2 = new Date(2018, 9, 1);
    GraduateStudent* student2 = new GraduateStudent("Bryan", birthdate2, enrollDate2);
    the_dean->insert_info(student2);
    
    Date* birthdate3 = new Date(1999, 8, 25);
    Date* enrollDate3 = new Date(2021, 9, 3);
    UndergraduateStudent* student3= new UndergraduateStudent("Mckenzy", birthdate3, enrollDate3);
    the_dean->insert_info(student3);

    Date* birthdate4 = new Date(1994, 10, 3);
    Date* enrollDate4 = new Date(2022, 10, 1);
    GraduateStudent* student4 = new GraduateStudent("Gordon", birthdate4, enrollDate4);
    the_dean->insert_info(student4);
  
    Date* birthdate5 = new Date(1998, 4, 15);
    Date* enrollDate5 = new Date(2020, 9, 1);
    UndergraduateStudent* student5 = new UndergraduateStudent("Stokes", birthdate5, enrollDate5);
    the_dean->insert_info(student5);

    Date* birthdate6 = new Date(1978, 2, 10);
    Date* employDate1 = new Date(2005, 8, 1);
    FullTimeProfessor* professor1 = new FullTimeProfessor(450842, "Dr.Polcovich", birthdate6, employDate1);
    the_dean->insert_info(professor1);

    Date* birthdate7 = new Date(1985, 7, 20);
    Date* employDate2= new Date(2010, 1, 1);
    PartTimeProfessor* professor2= new PartTimeProfessor(486436,"Dr.Racitano", birthdate7, employDate2);
    the_dean->insert_info(professor2);

    Date* birthdate8 = new Date(1968, 5, 7);
    Date* employDate3= new Date(2007, 3, 1);
    FullTimeProfessor* professor3 = new FullTimeProfessor(496486, "Dr.Filarecki", birthdate8, employDate3);
    the_dean->insert_info(professor3);

    Date* birthdate9 = new Date(1984, 7, 20);
    Date* employDate4 = new Date(2013, 5, 8);
    PartTimeProfessor* professor4 = new PartTimeProfessor(678644, "Prof.Poulsen", birthdate9, employDate4);
    the_dean->insert_info(professor4);
    // creating the courses of the university and registrating them
    Course* course1 = new Course(244, "Programming Methodology", "Dr. Polcovich");
    Course* course2 = new Course(273, "Basic Circuit Analysis", "Dr. Racitano");
    Course* course3 = new Course(201, "Professional Practice and Responsibility", "Dr. Polcovich");
    Course* course4 = new Course(371, "Probability and Statistics in Engineering", "Prof. Poulsen");
    Course* course5 = new Course(314, "Digital Electronics I", "Dr. Filarecki");
    CourseRegistration* course1reg = new CourseRegistration(course1);
    CourseRegistration* course2reg = new CourseRegistration(course2);
    CourseRegistration* course3reg = new CourseRegistration(course3);
    CourseRegistration* course4reg = new CourseRegistration(course4);
    CourseRegistration* course5reg = new CourseRegistration(course5);
    the_dean->insert_course_registration(course1reg);
    the_dean->insert_course_registration(course2reg);
    the_dean->insert_course_registration(course3reg);
    the_dean->insert_course_registration(course4reg);
    the_dean->insert_course_registration(course5reg);
    //- Show outputs of execution of all the member functions of dataManager class.
    the_dean->graduatesupervisor(*professor1, *student2);
    the_dean->graduatesupervisor(*professor1, *student4);
    the_dean->FullTimeProfInfo(*professor1);
    the_dean->FullTimeProfInfo(*professor3);
    the_dean->registering_to_Course(student1, *course1);
    the_dean->registering_to_Course(student1, *course2);
    the_dean->registering_to_Course(student2, *course1);
    the_dean->registering_to_Course(student1, *course3);
    the_dean->dropping_a_Course(student1, *course2);
    Grade* grade1 = new Grade(352, "Data Structures and Algorithms", "A");
    the_dean->setGrade(student1, 201, "B");
    the_dean->add_old_course(student1, grade1);
    the_dean->course_registration_info(*course1);
    the_dean->printcourses();
    the_dean->studentCourses(student1);
    int total = 154;
    total = *course1reg + total;
    cout << total << endl; // the result should be 156
    cout << "the sum of the number of students enrolled in all of the courses offered by the university is: " << endl;
    cout << the_dean->getTotal() << endl; // the result is 3
    cout << "-----------------------------------------------------------" << endl;
    cout << *birthdate1; //prints the personal info
    cout << *student1;
    cout << *professor1;
    string studentFile = "Studentinfo.txt"; // the txt file to store the info
    try {
        the_dean->save(studentFile); // try catch block
    }
    catch (const char* error) {
        cout << error << endl;
    }
    int entered_id;
    while (true) {
        cout << "Enter the student id (0 to quit): "; // while loop to input from the user and stops when the user inputs 0
        cin >> entered_id;
        if (entered_id == 0)
            break;
        try {
            the_dean->read(entered_id);
        }
        catch (const char* error) {
            cout << error << endl;
        }
    }
    // destructors
    birthdate1->~Date();
    birthdate2->~Date();
    birthdate3->~Date();
    birthdate4->~Date();
    birthdate5->~Date();
    birthdate6->~Date();
    birthdate7->~Date();
    birthdate8->~Date();
    birthdate9->~Date();
    enrollDate1->~Date();
    enrollDate2->~Date();
    enrollDate3->~Date();
    enrollDate4->~Date();
    enrollDate5->~Date();
    employDate1->~Date();
    employDate2->~Date();
    employDate3->~Date();
    employDate4->~Date();
    student1->~UndergraduateStudent();
    student3->~UndergraduateStudent();
    student5->~UndergraduateStudent();
    student2->~GraduateStudent();
    student4->~GraduateStudent();
    professor1->~FullTimeProfessor();
    professor2->~PartTimeProfessor();
    professor3->~FullTimeProfessor();
    professor4->~PartTimeProfessor();
    course1->~Course();
    course2->~Course();
    course3->~Course();
    course4->~Course();
    course5->~Course();
    course1reg->~CourseRegistration();
    course2reg->~CourseRegistration();
    course3reg->~CourseRegistration();
    course4reg->~CourseRegistration();
    course5reg->~CourseRegistration();
    the_dean->~dataManager();
    grade1->~Grade();
}
