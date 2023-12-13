#include "Grade.h"

// ����ǥ�� �� ������ set�Լ��� ���� ����.
void Grade::setStudenID(int studentID) {
	this->studentID = studentID;
}

// �ش� ������ �´��� Ȯ���ϴ� �Լ�
bool Grade::checkScore(float score) {
	std::cout << score << "���� �½��ϱ�?(y/n): ";
	std::string answer;
	std::cin >> answer;
	if (answer == "y") {
		return true;
	}
	else if (answer == "n") {
		return false;
	}
	else {
		throw answer;
	}
}

// �߰���� ������ ������ �Լ�
bool Grade::setMidtermScore(float score) {
	try {
		if (checkScore(score)) {
			midtermScore = score;
		}
		else {
			std::cout << "������ �ٽ� �Է����ּ��� : ";
			std::cin >> score;
			midtermScore = score;
		}
		return true;
	}
	catch (std::string input) {
		std::cout << "���� y or n���θ� ���ϼž��մϴ�." << std::endl;
		return false;
	}
}

// �⸻��� ������ ������ �Լ�
bool Grade::setLasttermScore(float score) {
	try {
		if (checkScore(score)) {
			midtermScore = score;
		}
		else {
			std::cout << "������ �ٽ� �Է����ּ��� : ";
			std::cin >> score;
			lasttermScore = score;
		}
		return true;
	}
	catch (std::string input) {
		std::cout << "���� y or n���θ� ���ϼž��մϴ�." << std::endl;
		return false;
	}
}

// ������ ����� �� �Լ�
void Grade::calculateExamAverage(Grade* grade) {
	grade->average = (grade->midtermScore + grade->lasttermScore) / 2;
}



Grade::Grade(int studentID) {
	setStudenID(studentID);
	midtermScore = -1;
	lasttermScore = -1;
	average = -1;
}

// �⺻���� ���� �Է��� ȣ�⿡ ���� �Լ����� ȣ���� �Լ�
void Grade::inputStudentScore(Grade* grade, float score, std::string examName) {
	if (examName == "�߰�") {
		if (grade->setMidtermScore(score)) {
			std::cout << grade->studentID << "�� �л��� " << examName << "������ '" << grade->midtermScore << "' �Դϴ�." << std::endl;
			std::cout << "���� �Է��� �Ϸ�ƽ��ϴ�." << std::endl;
		}
		else {
			std::cout << "���� �Է¿� �����Ͽ����ϴ�." << std::endl;
		}
	}
	if (examName == "�⸻") {
		if (grade->setLasttermScore(score)) {
			std::cout << grade->studentID << "�� �л��� " << examName << "������ '" << grade->lasttermScore << "' �Դϴ�." << std::endl;
			std::cout << "���� �Է��� �Ϸ�ƽ��ϴ�." << std::endl;
		}
		else {
			std::cout << "���� �Է¿� �����Ͽ����ϴ�." << std::endl;
		}
	}
}

// ���� �����ϴ� �Լ�
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

// �⸻ �������� �Է��� �Ǿ��ִ��� Ȯ���� �Լ�
bool Grade::checkEveryExamScore() {
	if (lasttermScore > 0) {
		return true;
	}
	return false;
}