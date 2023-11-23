#include "Student.h"

bool Student::checkStudentID(int studentID) {
	std::string strID = std::to_string(studentID);

	if (strID.length() != 6) {
		return false;
	}
	return true;
}

bool Student::checkStudentPhoneNumber(std::string phoneNumber) {
	int firstDash = phoneNumber.find('-');
	int secondDash = phoneNumber.find('-', firstDash + 1);

	std::string areaCode = phoneNumber.substr(0, firstDash);
	std::string firstPart = phoneNumber.substr(firstDash + 1, secondDash - firstDash - 1);
	std::string secondPart = phoneNumber.substr(secondDash + 1);

	if (areaCode != "010") {
		return false;
	}
	if (firstPart.length() != 4) {
		return false;
	}
	if (secondPart.length() != 4) {
		return false;
	}
	return true;
}

bool Student::checkStudentInformationValidation(int studentID, std::string phoneNumber) {
	if (checkStudentID(studentID)) {
		if (checkStudentPhoneNumber(phoneNumber)) {
			return true;
		}
	}
	std::cout << "다시 입력해주세요." << std::endl;
	return false;
}

Student::Student() {
	studentName = "";
	phoneNumber = "";
	studentID = 0;
}

Student::Student(std::string studentName, int studentID, std:: string phoneNumber) {
	if (checkStudentInformationValidation(studentID, phoneNumber)) {
		this->studentName = studentName;
		this->studentID = studentID;
		this->phoneNumber = phoneNumber;
	}

	if (studentName == "" || studentID == 0 || phoneNumber == "") {
		std::cout << "학생의 정보가 입력이 되지 않았습니다." << std::endl;
	}
}

std::string Student::getStudentName() {
	return studentName;
}

std::string Student::getPhoneNumber() {
	return phoneNumber;
}

int Student::getStudentID() {
	return studentID;
}