#include "Student.h"

// �л��� �й��� �ùٸ� �й����� Ȯ���� bool �Լ�
bool Student::checkStudentID(int studentID) {
	std::string strID = std::to_string(studentID);

	if (strID.length() != 6) {
		return false;
	}
	return true;
}

// �л��� ��ȣ�� �ùٸ� ��ȣ���� Ȯ���� bool �Լ�
bool Student::checkStudentPhoneNumber(std::string phoneNumber) {
	// ��ȣ�� Ȯ���ϱ� ���� '-'�� �������� �ɰ��� ���� ����
	int firstDash = phoneNumber.find('-');
	int secondDash = phoneNumber.find('-', firstDash + 1);

	std::string areaCode = phoneNumber.substr(0, firstDash);
	std::string firstPart = phoneNumber.substr(firstDash + 1, secondDash - firstDash - 1);
	std::string secondPart = phoneNumber.substr(secondDash + 1);

	// �ùٸ� ��ȣ�� �ƴ϶�� false ��ȯ
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

// �й��� ��ȭ��ȣ�� �ùٸ� �������� Ȯ���� �Լ��� ȣ���� �Լ�
bool Student::checkStudentInformationValidation(int studentID, std::string phoneNumber) {
	if (checkStudentID(studentID)) {
		if (checkStudentPhoneNumber(phoneNumber)) {
			return true;
		}
	}
	std::cout << "�ٽ� �Է����ּ���." << std::endl;
	return false;
}

// �⺻ ������
Student::Student() {
	studentName = "";
	phoneNumber = "";
	studentID = 0;
}

// �Է��� ���� �� �л� ��ü �ν��Ͻ� ������ ����
Student::Student(std::string studentName, int studentID, std::string phoneNumber) {
	if (checkStudentInformationValidation(studentID, phoneNumber)) {
		this->studentName = studentName;
		this->studentID = studentID;
		this->phoneNumber = phoneNumber;
	}

	if (studentName == "" || studentID == 0 || phoneNumber == "") {
		std::cout << "�л��� ������ �Է��� ���� �ʾҽ��ϴ�." << std::endl;
	}
}

// private ���� ���� ������ ���� �˷��ֱ� ���� get�Լ� ��
std::string Student::getStudentName() {
	return studentName;
}

std::string Student::getPhoneNumber() {
	return phoneNumber;
}

int Student::getStudentID() {
	return studentID;
}