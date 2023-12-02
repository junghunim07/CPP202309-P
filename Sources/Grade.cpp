#include "Grade.h"

// ����ǥ�� �� ������ set�Լ��� ���� ����.
void Grade::setStudenID(int studentID) {
	this->studentID = studentID;
}

void Grade::setMidtermScore(float score) {
	midtermScore = score;
}

void Grade::setLasttermScore(float score) {
	lasttermScore = score;
}

// ������ ����� �� �Լ�
void Grade::calculateExamAverage(Grade* grade) {
	grade->average = (grade->midtermScore + grade->lasttermScore) / 2;
}



Grade::Grade(int studentID) {
	setStudenID(studentID);
	midtermScore = 0;
	lasttermScore = 0;
	average = 0;
}

// �⺻���� ���� �Է��� ȣ�⿡ ���� �Լ����� ȣ���� �Լ�
void Grade::inputStudentScore(Grade* grade,float score, std::string examName) {
	if (examName == "�߰�") {
		grade->setMidtermScore(score);
		std::cout << grade->studentID << "�� �л��� " << examName << "������ '" << grade->midtermScore << "' �Դϴ�." << std::endl;
		std::cout << "���� �Է��� �Ϸ�ƽ��ϴ�." << std::endl;
	}
	if (examName == "�⸻") {
		grade->setLasttermScore(score);
		std::cout << grade->studentID << "�� �л��� " << examName << "������ '" << grade->midtermScore << "' �Դϴ�." << std::endl;
		std::cout << "���� �Է��� �Ϸ�ƽ��ϴ�." << std::endl;
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

// �� ������ �� ��ȯ�ϱ� ���� get�Լ���
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