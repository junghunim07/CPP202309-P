#include "Grade.h"

// 성적표의 각 정보를 set함수를 통해 설정.
void Grade::setStudenID(int studentID) {
	this->studentID = studentID;
}

void Grade::setMidtermScore(float score) {
	// 점수가 '0'점일 시 점수 입력자에게 다시 한번 물어보는 조건문
	if (score == 0) {
		std::cout << score << "점수가 맞습니까?(y/n) : ";
		std::string answer;
		std::cin >> answer;
		if (answer == "y") {
			midtermScore = score;
		}
		else if (answer == "n") {
			std::cout << "점수를 다시 입력해주세요 : ";
			std::cin >> score;
			midtermScore = score;
		}
	}
}

void Grade::setLasttermScore(float score) {
	// 점수가 '0'점일 시 점수 입력자에게 다시 한번 물어보는 조건문
	if (score == 0) {
		std::cout << score << "점수가 맞습니까?(y/n) : ";
		std::string answer;
		std::cin >> answer;
		if (answer == "y") {
			lasttermScore = score;
		}
		else if (answer == "n") {
			std::cout << "점수를 다시 입력해주세요 : ";
			std::cin >> score;
			lasttermScore = score;
		}
	}
}

// 성적의 평균을 낼 함수
void Grade::calculateExamAverage(Grade* grade) {
	grade->average = (grade->midtermScore + grade->lasttermScore) / 2;
}



Grade::Grade(int studentID) {
	setStudenID(studentID);
	midtermScore = 0;
	lasttermScore = 0;
	average = 0;
}

// 기본적인 성적 입력의 호출에 따른 함수들을 호출할 함수
void Grade::inputStudentScore(Grade* grade, float score, std::string examName) {
	if (examName == "중간") {
		grade->setMidtermScore(score);
		std::cout << grade->studentID << "의 학생의 " << examName << "성적은 '" << grade->midtermScore << "' 입니다." << std::endl;
		std::cout << "성적 입력이 완료됐습니다." << std::endl;
	}
	if (examName == "기말") {
		grade->setLasttermScore(score);
		std::cout << grade->studentID << "의 학생의 " << examName << "성적은 '" << grade->lasttermScore << "' 입니다." << std::endl;
		std::cout << "성적 입력이 완료됐습니다." << std::endl;
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

// 각 데이터 값 반환하기 위한 get함수들
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

// 기말 성적까지 입력이 되어있는지 확인할 함수
bool Grade::checkEveryExamScore() {
	if (lasttermScore > 0) {
		return true;
	}
	return false;
}