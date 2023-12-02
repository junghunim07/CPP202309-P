#pragma once
#include "Grade.h"
#include <vector>

class GradeMachine {
private :
	int A;
	float limitAScore;

	void compareGrade(std::vector<Grade>& studentGradeCard);
	void setA(int count);
	void setLimitAScore(Grade* grade);

public :
	GradeMachine();
	GradeMachine(std::vector<Grade>& studentGradeCard, int count);
	void searchLimitALineScore(GradeMachine& gradeMachine, std::vector<Grade>& studentGradeCard);
	void searchStudentGrade(std::vector<Grade>& studentGradeCard, int studentID, std::string format);
	void searchStudentGoalGrade(std::vector<Grade>& studentsGradeCard, int studentID, std::string goalGrade);
};