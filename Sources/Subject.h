#pragma once
#include "Grade.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Subject {
private:
	std::string subjectName;
	std::unordered_map<int, Grade> studentGrade;

public:
	Subject(std::string subjectName, std::vector<int> studentID);
	std::string getSubjectName();
	std::unordered_map<int, Grade> getStudentGrade();
	void enterGrade(Subject* subject, int studentID, std::string exam, float mark);
	bool searchSubject(Subject subject, std::string subjectName);
	void calculateRank(Subject* subject, int studentID, std::string format);
};