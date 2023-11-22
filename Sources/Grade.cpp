#include "Grade.h"

Grade::Grade() {
	midterm_Score = 0.0;
	last_Score = 0.0;
	average = 0.0;
	grade = "";
}

void Grade::setMidtermScore(float score) {
	midterm_Score = score;
	calculateAverage();
}

void Grade::setLastScore(float score) {
	last_Score = score;
	calculateAverage();
}

float Grade::getMidtermScore() {
	return midterm_Score;
}

float Grade::getLastScore() {
	return last_Score;
}

float Grade::getAverage() {
	return average;
}

void Grade::calculateAverage() {
	if (last_Score == 0) {
		average = midterm_Score;
	}
	else if (midterm_Score == 0) {
		average = last_Score;
	}
	else {
		average = (midterm_Score + last_Score) / 2;
	}
}

std::string Grade::getGrade() {
	return grade;
}