#include "Student.h"
#include "Grade.h"
#include "GradeMachine.h"
#include <iostream>
#include <vector>

using namespace std;

int result;									// �����ϰ��� �ϴ� �޴��� ������ ����
int studentCount;							// �л��� ���� ������ ����

vector<Student> students;					// �л��� ������ ������ vector
vector<Grade> studentGrade;					// �� �л��� ������ ������ vector

int printMenu();							// �޴��� ����� �Լ�
void inputStudentCount();					// �л� ���� �Է� �ޱ� ���� �Լ�
void inputStudentScore();					// �л��� ������ �Է� �ޱ� ���� �Լ�
void searchStudentGrade();					// �л��� ������ ��ȸ�ϱ� ���� �Լ�
void searchStudentInformation();			// �л��� ������ ��ȸ�ϱ� ���� �Լ�
Student inputStudentInformation();			// �л��� ������ �Է��ϰ� �л� ��ü�� �����ϱ� ���� �Լ�
Grade makeStudentGradeCard(int studentID);	// �л� ����ǥ�� ����� ���� �Լ�

int main() {
	cout << "CPP ���� ���� �ý����Դϴ�." << endl;
	// �л��� ���� �Է¹޴� �Լ�
	inputStudentCount();

	// �л��� �� ��ŭ �л� ��ü�� ����� students��� vector�� push�ϱ� ���� for��
	for (int i = 0; i < studentCount; i++) {
		students.push_back(inputStudentInformation());
	}
	
	// �л����� ������ �������� �� �л��� ����ǥ�� Grade ��ü�� �����ؼ� studentGrade vector�� push�ϱ� ���� for��
	for (int i = 0; i < studentCount; i++) {
		studentGrade.push_back(makeStudentGradeCard(students[i].getStudentID()));
	}

	while (true) {
		// ���Ḧ �Ǵ��ϱ� ���� bool ����
		bool finish = false;
		// �����ϰ����ϴ� �޴� ��ȣ�� ����
		result = printMenu();

		switch (result) {
		// �л� ���� ��ȸ
		case 1:
			searchStudentInformation();
			break;
		// �л� ���� �Է�
		case 2:
			inputStudentScore();
			break;
		// �л� ���� ��ȸ
		case 3:
			searchStudentGrade();
			break;
		// ����
		case 0 :
			finish = true;
			break;
		}

		// �����ϱ� ���Ѵٸ� while���� ���������� ���� ���ǹ�
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

	// �л� ��ü�� ����
	Student student(studentName, studentID, phoneNumber);

	return student;
}

void searchStudentInformation() {
	// �л� ���� ��ȸ�� �������� �л����� ������ ���
	for (int i = 0; i < studentCount; i++) {
		cout << "�л��� �̸� : " << students[i].getStudentName() << endl
			<< "�л��� �й� : " << students[i].getStudentID() << endl
			<< "�л��� ��ȭ��ȣ : " << students[i].getPhoneNumber() << endl;
	}
}

// �Է��� �л� ������ �������� �� �л� ������ ������ Grade��ü ������ ���� �Լ�
Grade makeStudentGradeCard(int studentID) {
	// �� �л� �� Grade ��ü ����.
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

	for (auto it : studentGrade) {
		if (it.getStudentID() == studentID) {
			it.inputStudentScore(&it, score, examName);
			it.getGradeCard(&it, examName);
		}
		else {
			cout << "�й��� �������� �ʽ��ϴ�." << endl;
		}
	}
}

void searchStudentGrade() {
	GradeMachine gradeMachine(studentGrade, studentCount);
	gradeMachine.searchLimitALineScore(gradeMachine, studentGrade);
	int studentID;
	string gradeFormat;

	cout << "�й��� �Է��ϼ��� : ";
	cin >> studentID;

	cout << "������ �ñ��ϸ� '����'" << endl
		<< "����� �ñ��ϸ� '���'" << endl
		<< "������ �ñ��ϸ� '����'" << endl
		<< "�Է����ּ��� : ";
	cin >> gradeFormat;

	gradeMachine.searchStudentGrade(studentGrade, studentID, gradeFormat);
}