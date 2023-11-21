#include "Student.h"

Student::Student(std::string name, int studentID, std::string phoneNumber) {
	this->name = name;
	this->studentID = studentID;
	this->phoneNumber = phoneNumber;
}

std::string Student::getName() {
	return name;
}

std::string Student::getPhoneNumber() {
	return phoneNumber;
}

int Student::getStudentID() {
	return studentID;
}

void Student::studentValidation(Student student) {
	std::string strID = std::to_string(studentID);

	if (strID.length() < 6) {
		std::cout << "학번을 다시 입력해주세요." << std::endl;
	}
}