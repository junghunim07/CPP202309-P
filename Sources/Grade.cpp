#include "Grade.h"

// 성적표의 각 정보를 set함수를 통해 설정.
void Grade::setStudenID(int studentID) {
	this->studentID = studentID;
}

// 해당 점수가 맞는지 확인하는 함수
bool Grade::checkScore(float score) {
	std::cout << score << "점이 맞습니까?(y/n): ";
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

// 중간고사 점수를 저장할 함수
bool Grade::setMidtermScore(float score) {
	try {
		if (checkScore(score)) {
			midtermScore = score;
		}
		else {
			std::cout << "점수를 다시 입력해주세요 : ";
			std::cin >> score;
			midtermScore = score;
		}
		return true;
	}
	catch (std::string input) {
		std::cout << "답은 y or n으로만 답하셔야합니다." << std::endl;
		return false;
	}
}

// 기말고사 점수를 저장할 함수
bool Grade::setLasttermScore(float score) {
	try {
		if (checkScore(score)) {
			midtermScore = score;
		}
		else {
			std::cout << "점수를 다시 입력해주세요 : ";
			std::cin >> score;
			lasttermScore = score;
		}
		return true;
	}
	catch (std::string input) {
		std::cout << "답은 y or n으로만 답하셔야합니다." << std::endl;
		return false;
	}
}

// 성적의 평균을 낼 함수
void Grade::calculateExamAverage(Grade* grade) {
	grade->average = (grade->midtermScore + grade->lasttermScore) / 2;
}



Grade::Grade(int studentID) {
	setStudenID(studentID);
	midtermScore = -1;
	lasttermScore = -1;
	average = -1;
}

// 기본적인 성적 입력의 호출에 따른 함수들을 호출할 함수
void Grade::inputStudentScore(Grade* grade, float score, std::string examName) {
	if (examName == "중간") {
		if (grade->setMidtermScore(score)) {
			std::cout << grade->studentID << "의 학생의 " << examName << "성적은 '" << grade->midtermScore << "' 입니다." << std::endl;
			std::cout << "성적 입력이 완료됐습니다." << std::endl;
		}
		else {
			std::cout << "성적 입력에 실패하였습니다." << std::endl;
		}
	}
	if (examName == "기말") {
		if (grade->setLasttermScore(score)) {
			std::cout << grade->studentID << "의 학생의 " << examName << "성적은 '" << grade->lasttermScore << "' 입니다." << std::endl;
			std::cout << "성적 입력이 완료됐습니다." << std::endl;
		}
		else {
			std::cout << "성적 입력에 실패하였습니다." << std::endl;
		}
	}
}

// 성적 산출하는 함수
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