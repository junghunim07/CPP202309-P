#pragma once
#include <iostream>

class Grade {
private:
	int studentID;
	float midtermScore;
	float lasttermScore;
	float average;
	void setStudenID(int studentID);
	bool setMidtermScore(float score);
	bool setLasttermScore(float score);
	void calculateExamAverage(Grade* grade);
	bool checkScore(float score);
	float isUsedOtherText(std::string score);
	bool isValidFloat(const::std::string& s);

public:
	Grade(int studentID);
	void inputStudentScore(Grade* grade, std::string scores, std::string examName);
	void getGradeCard(Grade* grade, std::string examName);
	int getStudentID();
	float getMidtermScore();
	float getLasttermScore();
	float getAverage();
	bool checkEveryExamScore();
};