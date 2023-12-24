#include "Grade.h"
#include <String>
#include <sstream>
#include <Vector>
#include <regex>

/*
* float 정규 표현식과 일치하는지 검사
* [-+]? : 부호가 있거나 없는 숫자
* [0-9]* : 0개 이상의 숫자
* \\.? : 소수점이 있거나 없는 숫자
* [0-9]+ : 1개 이상의 숫자
* ([eE][-+]?[0-9]+)? : 선택적으로 ‘e’ 또는 'E’를 포함하고, 그 뒤에 부호가 있거나 없는 숫자가 오는 지수 표현
** 이 중에서 하나라도 맞는게 있다면 true;
** 없다면 false를 반환
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
	// y, n 외 다른 입력값을 받을 경우 예외 처리
	try {
		// y값이 입력될 때까지 while문
		while (!checkScore(score)) {
			std::cout << "점수를 다시 입력해주세요 : ";
			std::cin >> score;
		}
		midtermScore = score;
		return true;
	}
	catch (std::string input) {
		std::cout << "답은 y or n으로만 답하셔야합니다." << std::endl;
		return false;
	}
}

// 기말고사 점수를 저장할 함수
bool Grade::setLasttermScore(float score) {
	// y, n 외 다른 입력값을 받을 경우 예외 처리
	try {
		// y값이 입력될 때까지 while문
		while (!checkScore(score)) {
			std::cout << "점수를 다시 입력해주세요 : ";
			std::cin >> score;
		}
		lasttermScore = score;
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

// "중간기말" 점수를 입력할 때 다른 문자열이 들어갔는지 확인
float Grade::isUsedOtherText(std::string score) {
	// 정규 표현식과 일치하는지 검사 틀리다면 예외 발생.
	if (!isValidFloat(score)) {
		throw new std::exception;
	}

	// string -> float 변환 중 발생할 수 있는 예외 처리 try-catch
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

// 기본적인 성적 입력의 호출에 따른 함수들을 호출할 함수
void Grade::inputStudentScore(Grade* grade, std::string scores, std::string examName) {
	if (examName == "중간") {
		try {
			if (grade->setMidtermScore(isUsedOtherText(scores))) {
				std::cout << grade->studentID << "의 학생의 " << examName << "성적은 '" << grade->midtermScore << "' 입니다." << std::endl;
				std::cout << "성적 입력이 완료됐습니다." << std::endl;
			}
		}
		catch (...) {
			std::cout << "잘못된 문자를 넣었습니다." << std::endl;
			std::cout << "성적 입력에 실패하였습니다." << std::endl;
		}
	}
	if (examName == "기말") {
		try {
			if (grade->setLasttermScore(isUsedOtherText(scores))) {
				std::cout << grade->studentID << "의 학생의 " << examName << "성적은 '" << grade->lasttermScore << "' 입니다." << std::endl;
				std::cout << "성적 입력이 완료됐습니다." << std::endl;
			}
		}
		catch (...) {
			std::cout << "잘못된 문자를 넣었습니다." << std::endl;
			std::cout << "성적 입력에 실패하였습니다." << std::endl;
		}
	}
	if (examName == "중간기말") {
		std::istringstream ss(scores);
		std::string token;
		std::vector<float> score;

		while (std::getline(ss, token, ',')) {
			try {
				score.push_back(isUsedOtherText(token));
			}
			catch (...) {
				std::cout << "잘못된 문자를 넣었습니다." << std::endl;
				std::cout << "성적 입력에 실패하였습니다." << std::endl;
			}
		}

		if (score.size() == 2) {
			if (grade->setMidtermScore(score[0])) {
				std::cout << grade->studentID << "의 학생의 중간 성적은 '" << grade->midtermScore << "' 입니다." << std::endl;
				std::cout << "성적 입력이 완료됐습니다." << std::endl;
			}
			if (grade->setLasttermScore(score[1])) {
				std::cout << grade->studentID << "의 학생의 기말 성적은 '" << grade->lasttermScore << "' 입니다." << std::endl;
				std::cout << "성적 입력이 완료됐습니다." << std::endl;
			}
		}
		else if (score.size() > 2) {
			std::cout << "점수 입력이 많습니다." << std::endl;
			std::cout << "성적 입력에 실패하였습니다." << std::endl;
		}
	}
}

// 성적 산출하는 함수
void Grade::getGradeCard(Grade* grade, std::string examName) {
	// 성적이 모두 입력했다면 평균 구하는 함수 호출
	if (grade->midtermScore >= 0 && grade->lasttermScore >= 0) {
		grade->calculateExamAverage(grade);
	}
	// 중간 성적만 입력 -> 평균 점수는 중간
	else if (grade->midtermScore >= 0 && grade->lasttermScore < 0) {
		grade->average = grade->midtermScore;
	}
	// 기말 성적만 입력 -> 평균 점수는 기말
	else if (grade->midtermScore < 0 && grade->lasttermScore >= 0) {
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