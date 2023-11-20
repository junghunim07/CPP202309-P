#pragma once
#include <iostream>
#include <vector>

class Grade {
private :
	float midterm_Score;
	float last_Score;
	std::string grade;

public :
	Grade();
	void setMidtermScore(float score);
	void setLastScore(float score);
	std::string getGrade();
};