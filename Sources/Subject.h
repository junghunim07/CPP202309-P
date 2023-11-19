#pragma once
#include <iostream>

using namespace std;

class Subject {
private :
	string subjectName;
	int studentID;
	float mark;
	string grade;

public :
	string getSubjectName();
	int getStudentID();
	float getMark();
	string getGrade();
};