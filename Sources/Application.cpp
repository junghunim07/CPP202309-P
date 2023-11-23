#include "Student.h"
#include "Grade.h"
#include <iostream>
#include <vector>

using namespace std;

int result;
int studentCount;

vector<Student> students;
vector<Grade> studentGrade;

int printMenu();
void inputStudentCount();
void inputStudentScore();
void searchStudentInformation();
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
		}
		else {
			cout << "학번이 존재하지 않습니다." << endl;
		}
	}
}