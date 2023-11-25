#include "Student.h"
#include "Grade.h"
#include "GradeMachine.h"
#include <iostream>
#include <vector>

using namespace std;

int result;									// 실행하고자 하는 메뉴를 저장할 변수
int studentCount;							// 학생의 수를 저장할 변수

vector<Student> students;					// 학생의 정보를 저장할 vector
vector<Grade> studentGrade;					// 각 학생의 성적을 저장할 vector

int printMenu();							// 메뉴를 출력할 함수
void inputStudentCount();					// 학생 수를 입력 받기 위한 함수
void inputStudentScore();					// 학생의 점수를 입력 받기 위한 함수
void searchStudentGrade();					// 학생의 성적을 조회하기 위한 함수
void searchStudentInformation();			// 학생의 정보를 조회하기 위한 함수
Student inputStudentInformation();			// 학생의 정보를 입력하고 학생 객체를 생성하기 위한 함수
Grade makeStudentGradeCard(int studentID);	// 학생 성적표를 만들기 위한 함수

int main() {
	cout << "CPP 성적 관리 시스템입니다." << endl;
	// 학생의 수를 입력받는 함수
	inputStudentCount();

	// 학생의 수 만큼 학생 객체를 만들어 students라는 vector에 push하기 위한 for문
	for (int i = 0; i < studentCount; i++) {
		students.push_back(inputStudentInformation());
	}
	
	// 학생들의 정보를 바탕으로 각 학생의 성적표를 Grade 객체로 생성해서 studentGrade vector에 push하기 위한 for문
	for (int i = 0; i < studentCount; i++) {
		studentGrade.push_back(makeStudentGradeCard(students[i].getStudentID()));
	}

	while (true) {
		// 종료를 판단하기 위한 bool 변수
		bool finish = false;
		// 실행하고자하는 메뉴 번호를 저장
		result = printMenu();

		switch (result) {
		// 학생 정보 조회
		case 1:
			searchStudentInformation();
			break;
		// 학생 성적 입력
		case 2:
			inputStudentScore();
			break;
		// 학생 성적 조회
		case 3:
			searchStudentGrade();
			break;
		// 종료
		case 0 :
			finish = true;
			break;
		}

		// 종료하길 원한다면 while문을 빠져나가기 위한 조건문
		if (finish) {
			break;
		}
	}
}

void inputStudentCount() {
	cout << "학생 수를 입력해주세요 : ";
	cin >> studentCount;
}

int printMenu() {
	cout << "1. 학생 정보를 조회하고 싶다면 1번" << endl;
	cout << "2. 학생 성적를 입력하고 싶다면 2번" << endl;
	cout << "3. 성적 조회를 하고 싶다면 3번" << endl;
	cout << "종료하고 싶다면 0번" << endl;
	cout << "눌러주세요." << endl;
	cin >> result;

	return result;
}

Student inputStudentInformation() {
	string studentName = "";
	string phoneNumber = "";
	int studentID = 0;

	cout << "학생의 이름을 입력해주세요 : ";
	cin >> studentName;

	cout << "학생의 학번을 입력해주세요 : ";
	cin >> studentID;

	cout << "학생의 번호를 입력해주세요('-'로 구분해주세요) : ";
	cin >> phoneNumber;

	// 학생 객체를 생성
	Student student(studentName, studentID, phoneNumber);

	return student;
}

void searchStudentInformation() {
	// 학생 정보 조회를 원했으면 학생들의 정보를 출력
	for (int i = 0; i < studentCount; i++) {
		cout << "학생의 이름 : " << students[i].getStudentName() << endl
			<< "학생의 학번 : " << students[i].getStudentID() << endl
			<< "학생의 전화번호 : " << students[i].getPhoneNumber() << endl;
	}
}

// 입력한 학생 정보를 바탕으로 각 학생 성적을 저장할 Grade객체 생성을 위한 함수
Grade makeStudentGradeCard(int studentID) {
	// 각 학생 별 Grade 객체 생성.
	Grade grade(studentID);
	return grade;
}

void inputStudentScore() {
	int studentID;
	float score;
	string examName;

	cout << "학생의 학번을 입력하세요 : ";
	cin >> studentID;

	cout << "중간고사면 '중간' 기말고사면 '기말'을 입력해주세요 : ";
	cin >> examName;

	cout << "학생의 점수를 입력하세요 : ";
	cin >> score;

	for (auto it : studentGrade) {
		if (it.getStudentID() == studentID) {
			it.inputStudentScore(&it, score, examName);
			it.getGradeCard(&it, examName);
		}
		else {
			cout << "학번이 존재하지 않습니다." << endl;
		}
	}
}

void searchStudentGrade() {
	GradeMachine gradeMachine(studentGrade, studentCount);
	gradeMachine.searchLimitALineScore(gradeMachine, studentGrade);
	int studentID;
	string gradeFormat;

	cout << "학번을 입력하세요 : ";
	cin >> studentID;

	cout << "점수가 궁금하면 '점수'" << endl
		<< "등수가 궁금하면 '등수'" << endl
		<< "학점이 궁금하면 '학점'" << endl
		<< "입력해주세요 : ";
	cin >> gradeFormat;

	gradeMachine.searchStudentGrade(studentGrade, studentID, gradeFormat);
}