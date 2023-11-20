#pragma once
#include "Grade.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Subject {
private:
	string subjectName;
	unordered_map<int, Grade> studentGrade;

public:
	Subject(string subjectName, vector<int> studentID);
	string getSubjectName();
	unordered_map<int, Grade> getStudentGrade();
	//int calculateGrade();
};