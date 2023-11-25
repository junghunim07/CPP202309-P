#include "GradeMachine.h"

// studentGradeCard�� ��� ������ �������� �������� ����
void GradeMachine::compareGrade(std::vector<Grade>& studentGradeCard) {
	for (int i = 0; i < studentGradeCard.size(); i++) {
		for (int j = i + 1; j < studentGradeCard.size(); j++) {
			if (studentGradeCard[i].getAverage() < studentGradeCard[j].getAverage()) {
				std::swap(studentGradeCard[i], studentGradeCard[j]);
			}
		}
	}
}

// A������ ���� �л� ���� ���
void GradeMachine::setA(int count) {
	A = (count * 50) / 100;
}

// A������ ��� ������ ����
void GradeMachine::setLimitAScore(Grade* sortGrade) {
	limitAScore = sortGrade->getAverage();
}

// GradeMachine�� �⺻ ���� ������ �ϱ� ���� ������
GradeMachine::GradeMachine(std::vector<Grade>& studentGradeCard, int count) {
	compareGrade(studentGradeCard);
	setA(count);
}

// A������ ��� ������ ã�Ƽ� set�Լ��� ȣ���� �Լ�
void GradeMachine::searchLimitALineScore(GradeMachine& gradeMachine, std::vector<Grade>& studentGradeCard) {
	if (gradeMachine.A != 0) {
		Grade grade = studentGradeCard[A - 1];
		gradeMachine.setLimitAScore(&grade);
	}
}

// ���� ��ȸ�� ���� �Լ�
void GradeMachine::searchStudentGrade(std::vector<Grade>& studentGradeCard, int studentID, std::string format) {
	// �ش� �л��� �����ϴ��� ���ϴ��� Ȯ���� bool ����
	bool exist = false;
	// ���ϴ� ���� ����� ������ ���
	if (format == "����") {
		for (auto it : studentGradeCard) {
			if (it.getStudentID() == studentID) {
				exist = true;
				if (it.getAverage() > limitAScore) {
					std::cout << "A���� �Դϴ�." << std::endl;
				}
				if (it.getAverage() < limitAScore) {
					std::cout << "B���� �Դϴ�." << std::endl;
				}
			}
		}
	}
	// ���ϴ� ���� ����� ������ ���
	if (format == "����") {
		for (auto it : studentGradeCard) {
			if (it.getStudentID() == studentID) {
				exist = true;
				std::cout << studentID << "�л��� ������ = " << it.getAverage() << "�Դϴ�." << std::endl;
			}
		}
	}
	// ���ϴ� ���� ����� ����� ���
	if (format == "���") {
		int index = 0;
		for (auto it : studentGradeCard) {
			index++;
			if (it.getStudentID() == studentID) {
				exist = true;
				std::cout << studentID << "�л��� ����� = " << index << "�Դϴ�." << std::endl;
			}
		}
	}

	// �ش� �й��� �������� ���� ���
	if (!exist) {
		std::cout << "�ش�" << studentID << "�й��� �������� �ʽ��ϴ�." << std::endl;
	}
}