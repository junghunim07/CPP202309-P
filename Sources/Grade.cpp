#include "Grade.h"

void Grade::setStudenID(int studentID) {
	this->studentID = studentID;
}

void Grade::setMidtermScore(float score) {
	midtermScore = score;
}

void Grade::setLasttermScore(float score) {
	lasttermScore = score;
}

void Grade::calculateExamAverage(Grade* grade) {
	grade->average = (grade->midtermScore + grade->lasttermScore) / 2;
}



Grade::Grade(int studentID) {
	setStudenID(studentID);
	midtermScore = 0;
	lasttermScore = 0;
	average = 0;
	grade = "";
}

void Grade::inputStudentScore(Grade* grade,float score, std::string examName) {
	if (examName == "중간") {
		grade->setMidtermScore(score);
	}
	if (examName == "기말") {
		grade->setLasttermScore(score);
	}
}

void Grade::getGradeCard(Grade* grade, std::string examName) {
	if (grade->midtermScore != 0 && grade->lasttermScore != 0) {
		grade->calculateExamAverage(grade);
	}
	else if (grade->lasttermScore == 0) {
		grade->average = grade->midtermScore;
	}
	else if (grade->midtermScore == 0) {
		grade->average = grade->lasttermScore;
	}
}

int Grade::getStudentID() {
	return studentID;
}

float Grade::getMidtermScore() {
	return midtermScore;
}

float Grade::getLasttermScore() {
	return lasttermScore;
}

float Grade::getAverage() {
	return average;
}

std::string Grade::getGrade() {
	return grade;
}