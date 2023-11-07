#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

// �л� Ŭ����
class Student {
	// ��� ����
private:
	string name;			// �̸�
	int studentID;			// �й�
	string phoneNumber;		// ��ȭ��ȣ

public:
	// ������
	Student(string name, int studentID, string phoneNumber) {
		this->name = name;
		this->studentID = studentID;
		this->phoneNumber = phoneNumber;
	}

	// �л��� �̸��� ��ȯ�ϴ� �Լ�
	string getName() {
		return name;
	}

	// �й��� ��ȯ�ϴ� �Լ�
	int getStudentID() {
		return studentID;
	}

	// ��ȭ��ȣ�� ��ȯ�ϴ� �Լ�
	string getPhoneNumber() {
		return phoneNumber;
	}
};

Student inputStudentsInformation() {
	string name;
	int studentID;
	string phone;

	cout << "�̸��� �Է��ϼ���: ";
	cin >> name;

	cout << "�й��� �Է��ϼ���: ";
	cin >> studentID;

	cout << "��ȭ��ȣ�� �Է��ϼ���('-'�� �������ּ���): ";
	cin >> phone;

	Student student(name, studentID, phone);

	return student;
}
#endif