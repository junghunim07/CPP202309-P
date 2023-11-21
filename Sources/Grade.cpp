#include "Grade.h"

Grade::Grade() {
	midterm_Score = 0.0;
	last_Score = 0.0;
	grade = "";
}

void Grade::setMidtermScore(float score) {
	midterm_Score = score;
}

void Grade::setLastScore(float score) {
	last_Score = score;
}

float Grade::getMidtermScore() {
	return midterm_Score;
}

float Grade::getLastScore() {
	return last_Score;
}

std::string Grade::getGrade() {
	return grade;
}