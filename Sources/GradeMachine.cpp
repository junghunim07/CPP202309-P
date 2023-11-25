#include "GradeMachine.h"

// studentGradeCard를 평균 점수를 기준으로 내림차순 정렬
void GradeMachine::compareGrade(std::vector<Grade>& studentGradeCard) {
	for (int i = 0; i < studentGradeCard.size(); i++) {
		for (int j = i + 1; j < studentGradeCard.size(); j++) {
			if (studentGradeCard[i].getAverage() < studentGradeCard[j].getAverage()) {
				std::swap(studentGradeCard[i], studentGradeCard[j]);
			}
		}
	}
}

// A학점을 받을 학생 수를 계산
void GradeMachine::setA(int count) {
	A = (count * 50) / 100;
}

// A학점의 경계 점수를 저장
void GradeMachine::setLimitAScore(Grade* sortGrade) {
	limitAScore = sortGrade->getAverage();
}

// GradeMachine의 기본 적인 설정을 하기 위한 생성자
GradeMachine::GradeMachine(std::vector<Grade>& studentGradeCard, int count) {
	compareGrade(studentGradeCard);
	setA(count);
}

// A학점의 경계 점수를 찾아서 set함수를 호출할 함수
void GradeMachine::searchLimitALineScore(GradeMachine& gradeMachine, std::vector<Grade>& studentGradeCard) {
	if (gradeMachine.A != 0) {
		Grade grade = studentGradeCard[A - 1];
		gradeMachine.setLimitAScore(&grade);
	}
}

// 성적 조회를 위한 함수
void GradeMachine::searchStudentGrade(std::vector<Grade>& studentGradeCard, int studentID, std::string format) {
	// 해당 학생이 존재하는지 안하는지 확인할 bool 변수
	bool exist = false;
	// 원하는 성적 출력이 학점일 경우
	if (format == "학점") {
		for (auto it : studentGradeCard) {
			if (it.getStudentID() == studentID) {
				exist = true;
				if (it.getAverage() > limitAScore) {
					std::cout << "A학점 입니다." << std::endl;
				}
				if (it.getAverage() < limitAScore) {
					std::cout << "B학점 입니다." << std::endl;
				}
			}
		}
	}
	// 원하는 성적 출력이 점수일 경우
	if (format == "점수") {
		for (auto it : studentGradeCard) {
			if (it.getStudentID() == studentID) {
				exist = true;
				std::cout << studentID << "학생의 점수는 = " << it.getAverage() << "입니다." << std::endl;
			}
		}
	}
	// 원하는 성적 출력이 등수일 경우
	if (format == "등수") {
		int index = 0;
		for (auto it : studentGradeCard) {
			index++;
			if (it.getStudentID() == studentID) {
				exist = true;
				std::cout << studentID << "학생의 등수는 = " << index << "입니다." << std::endl;
			}
		}
	}

	// 해당 학번이 존재하지 않을 경우
	if (!exist) {
		std::cout << "해당" << studentID << "학번은 존재하지 않습니다." << std::endl;
	}
}