#pragma once
#include <iostream>

class Grade {
private:
	int studentID;
	float midtermScore;
	float lasttermScore;
	float average;
	void setStudenID(int studentID);
	void setMidtermScore(float score);
	void setLasttermScore(float score);
	void calculateExamAverage(Grade* grade);

public:
	Grade(int studentID);
	void inputStudentScore(Grade* grade, float score, std::string examName);
	void getGradeCard(Grade* grade, std::string examName);
	int getStudentID();
	float getMidtermScore();
	float getLasttermScore();
	float getAverage();
};