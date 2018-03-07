/**
* Class: CSCI2490 C++ Programming
* Instructor: Y. Daniel Liang
* Description: Adds and removes students to two course objects. 
* Due: 09/26/2016
* @author Shaun C. Dobbs
* @version 1.0

* I pledge by honor that I have completed the programming assignment independently.
* I have not copied the code from a student or any source.
* I have not given my code to any student.

Sign here: Shaun C. Dobbs
*/

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef COURSE_H
#define COURSE_H
class Course {
public: 
	Course(const string& courseName, int capacity);
	~Course();
	string getCourseName() const;
	void addStudent(const string& name);
	void dropStudent(const string& name);
	string* getStudents() const;
	int getNumberOfStudents() const;
	void clear();

private: 
	string courseName; 
	string* students; 
	int numberOfStudents; 
	int capacity; 

};
#endif
//Course constructor
Course::Course(const string& courseName, int capacity) {
	numberOfStudents = 0; 
	this->courseName = courseName; 
	this->capacity = capacity; 
	students = new string[capacity];
}
//Course destructor
Course::~Course() {
	delete[] students;
}


string Course::getCourseName() const {
	return courseName;
}

void Course::addStudent(const string& name) {


	if (numberOfStudents >= capacity) {

	capacity = numberOfStudents * 2 + 1;

	string* tempStudents = new string[numberOfStudents * 2 + 1];

	for (int i = 0; i < numberOfStudents; i++)
		tempStudents[i] = students[i];

	delete[] students;
	students = new string[numberOfStudents * 2 + 1];

	for (int i = 0; i < numberOfStudents; i++)
		students[i] = tempStudents[i];
	delete[] tempStudents;
}
	students[numberOfStudents] = name;
	numberOfStudents++;
	

}

void Course::dropStudent(const string& name) {
	//Find the students name, delete it and shift everything down one spot in the array
	int index;
	for (int i = 0; i < capacity; i++) {
		if (students[i] == name) {
			index = i;
			for (int j = index; j < numberOfStudents; j++) {
				students[j] = students[j + 1];
			}
			numberOfStudents--;
		}
	}
}

string* Course::getStudents() const {
	return students;
}

int Course::getNumberOfStudents() const {
	return numberOfStudents;
}

void Course::clear() {
	numberOfStudents = 0;
	delete[] students;
	students = new string[capacity];
}



int main()
{
	Course course1("Data Structures", 10);
	Course course2("Database Systems", 2);

	course1.addStudent("Peter Jones");
	course1.addStudent("Brian Smith");
	course1.addStudent("Anne Kennedy");
	course1.addStudent("Susan Kennedy");
	course1.addStudent("John Kennedy");
	course1.addStudent("Kim Johnson");
	course1.addStudent("S1");
	course1.addStudent("S2");
	course1.addStudent("S3");
	course1.addStudent("S4");
	course1.addStudent("S5");
	course1.addStudent("S6");
	course1.addStudent("S7");

	course2.addStudent("Peter Jones");
	course2.addStudent("Steve Smith");

	cout << "Number of students in course1: "
		<< course1.getNumberOfStudents() << endl;

	string *students = course1.getStudents();

	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		if (i < course1.getNumberOfStudents() - 1) {
			cout << students[i] << ", ";
		}
		else {
			cout << students[i];
		}

	cout << endl;

	cout << "Number of students in course2: " << course2.getNumberOfStudents() << endl;

	course1.dropStudent("S1");
	cout << "Number of students in course1: " << course1.getNumberOfStudents() << endl;

	students = course1.getStudents();

	for (int i = 0; i < course1.getNumberOfStudents(); i++)
		if (i < course1.getNumberOfStudents() - 1) {
			cout << students[i] << ", ";
		}
		else {
			cout << students[i];
		}

	cout << endl;
	course1.clear();
	cout << "Number of students in course1: " << course1.getNumberOfStudents() << "." << endl;

	return 0;
}

