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
	cout << "CPP ���� ���� �ý����Դϴ�." << endl;
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
	cout << "�л� ���� �Է����ּ��� : ";
	cin >> studentCount;
}

int printMenu() {
	cout << "1. �л� ������ ��ȸ�ϰ� �ʹٸ� 1��" << endl;
	cout << "2. �л� ������ �Է��ϰ� �ʹٸ� 2��" << endl;
	cout << "3. ���� ��ȸ�� �ϰ� �ʹٸ� 3��" << endl;
	cout << "�����ϰ� �ʹٸ� 0��" << endl;
	cout << "�����ּ���." << endl;
	cin >> result;

	return result;
}

Student inputStudentInformation() {
	string studentName = "";
	string phoneNumber = "";
	int studentID = 0;

	cout << "�л��� �̸��� �Է����ּ��� : ";
	cin >> studentName;

	cout << "�л��� �й��� �Է����ּ��� : ";
	cin >> studentID;

	cout << "�л��� ��ȣ�� �Է����ּ���('-'�� �������ּ���) : ";
	cin >> phoneNumber;

	Student student(studentName, studentID, phoneNumber);

	return student;
}

void searchStudentInformation() {
	for (int i = 0; i < studentCount; i++) {
		cout << "�л��� �̸� : " << students[i].getStudentName() << endl
			<< "�л��� �й� : " << students[i].getStudentID() << endl
			<< "�л��� ��ȭ��ȣ : " << students[i].getPhoneNumber() << endl;
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

	cout << "�л��� �й��� �Է��ϼ��� : ";
	cin >> studentID;

	cout << "�߰����� '�߰�' �⸻���� '�⸻'�� �Է����ּ��� : ";
	cin >> examName;

	cout << "�л��� ������ �Է��ϼ��� : ";
	cin >> score;

	for (auto& it : studentGrade) {
		if (it.getStudentID() == studentID) {
			it.inputStudentScore(&it, score, examName);
			it.getGradeCard(&it, examName);
		}
		else {
			cout << "�й��� �������� �ʽ��ϴ�." << endl;
		}
	}
}