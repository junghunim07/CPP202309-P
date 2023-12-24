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

GradeMachine::GradeMachine() {

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
			// �л��� �����Ѵٸ�
			if (it.getStudentID() == studentID) {
				exist = true;
				// ������ �Է� �ȵ� ���
				if (it.getAverage() < 0) {
					std::cout << studentID << "�л��� ������ �ԷµǾ� ���� �ʽ��ϴ�." << std::endl;
				}
				// A����
				else if (it.getAverage() >= limitAScore) {
					std::cout << "A���� �Դϴ�." << std::endl;
				}
				// B����
				else if (it.getAverage() < limitAScore) {
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
				// �߰�, �⸻�� ��� �ԷµǾ� �ִٸ� -> ��� = (�߰� + �⸻) / 2
				if (it.getLasttermScore() >= 0 && it.getMidtermScore() >= 0) {
					std::cout << studentID << "�л��� ���� ����� = " << it.getAverage() << "�Դϴ�." << std::endl;
				}
				// �⸻ ��� �Է��� �ȵǾ� �ִٸ� -> ��� = �߰� ����
				else if (it.getLasttermScore() < 0 && it.getMidtermScore() >= 0) {
					std::cout << studentID << "�л��� �߰���� ������ = " << it.getMidtermScore() << "�Դϴ�." << std::endl;
				}
				// �߰� ��� �Է��� �ȵǾ� �ִٸ� -> ��� = �⸻ ����
				else if (it.getMidtermScore() < 0 && it.getLasttermScore() >= 0) {
					std::cout << studentID << "�л��� �⸻��� ������ = " << it.getLasttermScore() << "�Դϴ�." << std::endl;
				}
				// ��� �Է��� �ȵǾ� �ִٸ�
				else {
					std::cout << studentID << "�л��� ������ ���� �ԷµǾ� ���� �ʽ��ϴ�." << std::endl;
				}
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
				if (it.getAverage() < 0) {
					std::cout << studentID << "�л��� ������ �ԷµǾ� ���� �ʽ��ϴ�." << std::endl;
				}
				else {
					std::cout << studentID << "�л��� ����� = " << index << "�Դϴ�." << std::endl;
				}
			}
		}
	}

	// �ش� �й��� �������� ���� ���
	if (!exist) {
		std::cout << "�ش� " << studentID << "�й��� �������� �ʽ��ϴ�." << std::endl;
	}
}

// �л��� ��ǥ ������ �Է��Ͽ� ������ ��� ���� �Լ�
void GradeMachine::searchStudentGoalGrade(std::vector<Grade>& studentsGradeCard, int studentID, std::string goalGrade) {
	int index = 0;
	bool exist = false;
	for (auto it : studentsGradeCard) {
		index++;
		// ���� ������ �� �ԷµǾ� ���� ���
		if (it.checkEveryExamScore()) {
			if (it.getStudentID() == studentID) {
				exist = true;
				// ��ǥ ������ 'A'�� ���
				if (goalGrade._Equal("A")) {
					if (index > A) {
						std::cout << "���� ���� A ������ ������ = " << limitAScore << std::endl;
						std::cout << "���� " << studentID << "�л��� ���� = " << it.getAverage() << std::endl;
						std::cout << "���� " << studentID << "�й��� B ���� �Դϴ�." << std::endl;
					}
					else {
						std::cout << "����� �̹� A ���� �Դϴ�." << std::endl;
					}
				}
				// 'B'�� ���
				else {
					if (index < A) {
						std::cout << "����� ���� ������ A �Դϴ�." << std::endl;
					}
					else {
						std::cout << "����� �̹� ��ǥ ������ " << goalGrade << " ���� �Դϴ�." << std::endl;
					}
				}
			}
		}
		// ���� �Է��� �� �ȵǾ� ���� ���
		else {
			if (it.getStudentID() == studentID) {
				exist = true;
				// ��ǥ ������ 'A'�� ���
				if (goalGrade._Equal("A")) {
					if (index > A) {
						std::cout << "���� ���� A ������ ������ = " << limitAScore << std::endl;
						std::cout << "���� " << studentID << "�л��� �߰� ��� ���� = " << it.getMidtermScore() << std::endl;
						std::cout << "���� " << goalGrade << "������ �ޱ� ���ؼ� " << studentID << "�й��� " << limitAScore - it.getMidtermScore() << "��ŭ�� ������ �� �����ϴ�." << std::endl;
					}
					else {
						std::cout << "����� �̹� A ���� �Դϴ�." << std::endl;
					}
				}
				// 'B'�� ���
				else {
					if (index < A) {
						std::cout << "����� ���� ������ A �Դϴ�." << std::endl;
					}
					else {
						std::cout << "����� �̹� ��ǥ ������ " << goalGrade << " ���� �Դϴ�." << std::endl;
					}
				}
			}
		}
	}

	if (!exist) {
		std::cout << "�ش� " << studentID << "�й��� �������� �ʽ��ϴ�." << std::endl;
	}
}