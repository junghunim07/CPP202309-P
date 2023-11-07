#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// 학생 클래스
class Student {
	// 멤버 변수
private:
	string name;			// 이름
	int studentID;			// 학번
	string phoneNumber;		// 전화번호

public:
	// 생성자
	Student(string name, int studentID, string phoneNumber) {
		this->name = name;
		this->studentID = studentID;
		this->phoneNumber = phoneNumber;
	}

	// 학생의 이름을 반환하는 함수
	string getName() {
		return name;
	}

	// 학번을 반환하는 함수
	int getStudentID() {
		return studentID;
	}

	// 전화번호를 반환하는 함수
	string getPhoneNumber() {
		return phoneNumber;
	}
};

Student inputStudentsInformation() {
	string name;
	int studentID;
	string phone;

	cout << "이름을 입력하세요: ";
	cin >> name;

	cout << "학번을 입력하세요: ";
	cin >> studentID;

	cout << "전화번호를 입력하세요('-'로 구분해주세요): ";
	cin >> phone;

	Student student(name, studentID, phone);

	return student;
}
#endif