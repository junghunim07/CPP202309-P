#include "Student.h"
#include "Grade.h"
#include "GradeMachine.h"
#include <iostream>
#include <vector>

using namespace std;

int result;
int studentCount;

GradeMachine gradeMachine;

vector<Student> students;
vector<Grade> studentGrade;

int printMenu();
void inputStudentCount();
void inputStudentScore();
void searchStudentGrade();
void searchStudentInformation();
void searchWantGoalScore();

Student inputStudentInformation();
Grade makeStudentGradeCard(int studentID);

int main() {
	cout << "CPP 성적 관리 시스템입니다." << endl;
	inputStudentCount();

	for (int i = 0; i < studentCount; i++) {
		students.push_back(inputStudentInformation());
	}

	for (int i = 0; i < studentCount; i++) {
		studentGrade.push_back(makeStudentGradeCard(students[i].getStudentID()));
	}

	while (true) {
		bool finish = false;
		result = printMenu();

		switch (result) {
		case 1:
			searchStudentInformation();
			break;
		case 2:
			inputStudentScore();
			break;
		case 3:
			searchStudentGrade();
			break;
		case 4:
			searchWantGoalScore();
			break;
		case 0 :
			finish = true;
			break;
		}

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
	cout << "4. 원하는 성적을 받기 위해 필요한 점수를 알고 싶다면 4번" << endl;
	cout << "0. 종료하고 싶다면 0번" << endl;
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

	Student student(studentName, studentID, phoneNumber);

	return student;
}

void searchStudentInformation() {
	for (int i = 0; i < studentCount; i++) {
		cout << "학생의 이름 : " << students[i].getStudentName() << endl
			<< "학생의 학번 : " << students[i].getStudentID() << endl
			<< "학생의 전화번호 : " << students[i].getPhoneNumber() << endl;
	}
}

Grade makeStudentGradeCard(int studentID) {
	Grade grade(studentID);
	return grade;
}

void inputStudentScore() {
	int tmp = 0;
	int studentID;
	float score;
	string examName;

	cout << "학생의 학번을 입력하세요 : ";
	cin >> studentID;

	cout << "중간고사면 '중간' 기말고사면 '기말'을 입력해주세요 : ";
	cin >> examName;

	cout << "학생의 점수를 입력하세요 : ";
	cin >> score;

	for (auto& it : studentGrade) {
		if (it.getStudentID() == studentID) {
			it.inputStudentScore(&it, score, examName);
			it.getGradeCard(&it, examName);
			tmp++;
		}
	}

	if (tmp == 0) {
		cout << "해당 " << studentID << "학번은 존재하지 않습니다." << endl;
	}
	gradeMachine = GradeMachine(studentGrade, studentCount);
	gradeMachine.searchLimitALineScore(gradeMachine, studentGrade);
}

void searchStudentGrade() {
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

void searchWantGoalScore() {
	int studentID;
	string goalGrade;

	cout << "학번을 입력하세요 : ";
	cin >> studentID;

	cout << "원하는 학점을 적으세요. (A or B) : ";
	cin >> goalGrade;

	gradeMachine.searchStudentGoalGrade(studentGrade, studentID, goalGrade);
}