#include "Student.h"

Student::Student(string name, int studentID, string phoneNumber) {
	this->name = name;
	this->studentID = studentID;
	this->phoneNumber = phoneNumber;
}

string Student::getName() {
	return name;
}

string Student::getPhoneNumber() {
	return phoneNumber;
}

int Student::getStudentID() {
	return studentID;
}

void Student::studentValidation(Student student) {
	string strID = to_string(studentID);

	if (strID.length() < 6) {
		cout << "학번을 다시 입력해주세요."<< endl;
	}
}