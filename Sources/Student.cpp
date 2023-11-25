#include "Student.h"

// 학생의 학번이 올바른 학번인지 확인할 bool 함수
bool Student::checkStudentID(int studentID) {
	std::string strID = std::to_string(studentID);

	if (strID.length() != 6) {
		return false;
	}
	return true;
}

// 학생의 번호가 올바른 번호인지 확인할 bool 함수
bool Student::checkStudentPhoneNumber(std::string phoneNumber) {
	// 번호를 확인하기 위해 '-'를 기준으로 쪼개기 위한 과정
	int firstDash = phoneNumber.find('-');
	int secondDash = phoneNumber.find('-', firstDash + 1);

	std::string areaCode = phoneNumber.substr(0, firstDash);
	std::string firstPart = phoneNumber.substr(firstDash + 1, secondDash - firstDash - 1);
	std::string secondPart = phoneNumber.substr(secondDash + 1);

	// 올바른 번호가 아니라면 false 반환
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

// 학번과 전화번호가 올바른 정보인지 확인할 함수를 호출할 함수
bool Student::checkStudentInformationValidation(int studentID, std::string phoneNumber) {
	if (checkStudentID(studentID)) {
		if (checkStudentPhoneNumber(phoneNumber)) {
			return true;
		}
	}
	std::cout << "다시 입력해주세요." << std::endl;
	return false;
}

// 기본 생성자
Student::Student() {
	studentName = "";
	phoneNumber = "";
	studentID = 0;
}

// 입력한 값을 각 학생 객체 인스턴스 변수에 저장
Student::Student(std::string studentName, int studentID, std::string phoneNumber) {
	if (checkStudentInformationValidation(studentID, phoneNumber)) {
		this->studentName = studentName;
		this->studentID = studentID;
		this->phoneNumber = phoneNumber;
	}

	if (studentName == "" || studentID == 0 || phoneNumber == "") {
		std::cout << "학생의 정보가 입력이 되지 않았습니다." << std::endl;
	}
}

// private 변수 값을 데이터 값을 알려주기 위한 get함수 들
std::string Student::getStudentName() {
	return studentName;
}

std::string Student::getPhoneNumber() {
	return phoneNumber;
}

int Student::getStudentID() {
	return studentID;
}