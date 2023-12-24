#include "Grade.h"
#include <String>
#include <sstream>
#include <Vector>
#include <regex>

/*
* float ���� ǥ���İ� ��ġ�ϴ��� �˻�
* [-+]? : ��ȣ�� �ְų� ���� ����
* [0-9]* : 0�� �̻��� ����
* \\.? : �Ҽ����� �ְų� ���� ����
* [0-9]+ : 1�� �̻��� ����
* ([eE][-+]?[0-9]+)? : ���������� ��e�� �Ǵ� 'E���� �����ϰ�, �� �ڿ� ��ȣ�� �ְų� ���� ���ڰ� ���� ���� ǥ��
** �� �߿��� �ϳ��� �´°� �ִٸ� true;
** ���ٸ� false�� ��ȯ
*/
bool Grade::isValidFloat(const std::string& s) {
	std::regex e("^[-+]?[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$");
	if (std::regex_match(s, e)) {
		return true;
	}
	else {
		return false;
	}
}

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
	// y, n �� �ٸ� �Է°��� ���� ��� ���� ó��
	try {
		// y���� �Էµ� ������ while��
		while (!checkScore(score)) {
			std::cout << "������ �ٽ� �Է����ּ��� : ";
			std::cin >> score;
		}
		midtermScore = score;
		return true;
	}
	catch (std::string input) {
		std::cout << "���� y or n���θ� ���ϼž��մϴ�." << std::endl;
		return false;
	}
}

// �⸻��� ������ ������ �Լ�
bool Grade::setLasttermScore(float score) {
	// y, n �� �ٸ� �Է°��� ���� ��� ���� ó��
	try {
		// y���� �Էµ� ������ while��
		while (!checkScore(score)) {
			std::cout << "������ �ٽ� �Է����ּ��� : ";
			std::cin >> score;
		}
		lasttermScore = score;
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

// "�߰��⸻" ������ �Է��� �� �ٸ� ���ڿ��� ������ Ȯ��
float Grade::isUsedOtherText(std::string score) {
	// ���� ǥ���İ� ��ġ�ϴ��� �˻� Ʋ���ٸ� ���� �߻�.
	if (!isValidFloat(score)) {
		throw new std::exception;
	}

	// string -> float ��ȯ �� �߻��� �� �ִ� ���� ó�� try-catch
	try {
		float number = std::stof(score);
		return number;
	}
	catch (const std::invalid_argument& e1) {
		throw e1;
	}
	catch (const std::out_of_range& e2) {
		throw e2;
	}
}

Grade::Grade(int studentID) {
	setStudenID(studentID);
	midtermScore = -1;
	lasttermScore = -1;
	average = -1;
}

// �⺻���� ���� �Է��� ȣ�⿡ ���� �Լ����� ȣ���� �Լ�
void Grade::inputStudentScore(Grade* grade, std::string scores, std::string examName) {
	if (examName == "�߰�") {
		try {
			if (grade->setMidtermScore(isUsedOtherText(scores))) {
				std::cout << grade->studentID << "�� �л��� " << examName << "������ '" << grade->midtermScore << "' �Դϴ�." << std::endl;
				std::cout << "���� �Է��� �Ϸ�ƽ��ϴ�." << std::endl;
			}
		}
		catch (...) {
			std::cout << "�߸��� ���ڸ� �־����ϴ�." << std::endl;
			std::cout << "���� �Է¿� �����Ͽ����ϴ�." << std::endl;
		}
	}
	if (examName == "�⸻") {
		try {
			if (grade->setLasttermScore(isUsedOtherText(scores))) {
				std::cout << grade->studentID << "�� �л��� " << examName << "������ '" << grade->lasttermScore << "' �Դϴ�." << std::endl;
				std::cout << "���� �Է��� �Ϸ�ƽ��ϴ�." << std::endl;
			}
		}
		catch (...) {
			std::cout << "�߸��� ���ڸ� �־����ϴ�." << std::endl;
			std::cout << "���� �Է¿� �����Ͽ����ϴ�." << std::endl;
		}
	}
	if (examName == "�߰��⸻") {
		std::istringstream ss(scores);
		std::string token;
		std::vector<float> score;

		while (std::getline(ss, token, ',')) {
			try {
				score.push_back(isUsedOtherText(token));
			}
			catch (...) {
				std::cout << "�߸��� ���ڸ� �־����ϴ�." << std::endl;
				std::cout << "���� �Է¿� �����Ͽ����ϴ�." << std::endl;
			}
		}

		if (score.size() == 2) {
			if (grade->setMidtermScore(score[0])) {
				std::cout << grade->studentID << "�� �л��� �߰� ������ '" << grade->midtermScore << "' �Դϴ�." << std::endl;
				std::cout << "���� �Է��� �Ϸ�ƽ��ϴ�." << std::endl;
			}
			if (grade->setLasttermScore(score[1])) {
				std::cout << grade->studentID << "�� �л��� �⸻ ������ '" << grade->lasttermScore << "' �Դϴ�." << std::endl;
				std::cout << "���� �Է��� �Ϸ�ƽ��ϴ�." << std::endl;
			}
		}
		else if (score.size() > 2) {
			std::cout << "���� �Է��� �����ϴ�." << std::endl;
			std::cout << "���� �Է¿� �����Ͽ����ϴ�." << std::endl;
		}
	}
}

// ���� �����ϴ� �Լ�
void Grade::getGradeCard(Grade* grade, std::string examName) {
	// ������ ��� �Է��ߴٸ� ��� ���ϴ� �Լ� ȣ��
	if (grade->midtermScore >= 0 && grade->lasttermScore >= 0) {
		grade->calculateExamAverage(grade);
	}
	// �߰� ������ �Է� -> ��� ������ �߰�
	else if (grade->midtermScore >= 0 && grade->lasttermScore < 0) {
		grade->average = grade->midtermScore;
	}
	// �⸻ ������ �Է� -> ��� ������ �⸻
	else if (grade->midtermScore < 0 && grade->lasttermScore >= 0) {
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