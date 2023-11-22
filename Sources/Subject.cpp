#include "Subject.h"

Subject::Subject(std::string subjectName, std::vector<int> studentsID) {
	this->subjectName = subjectName;
	for (int i = 0; i < studentsID.size(); i++) {
		Grade grade;
		studentGrade.insert(std::pair<int, Grade>(studentsID[i], grade));
	}
}

std::string Subject::getSubjectName() {
	return subjectName;
}

std::unordered_map<int, Grade> Subject::getStudentGrade() {
	return studentGrade;
}

bool Subject::searchSubject(Subject subject, std::string subjectName) {
	if (subject.getSubjectName() == subjectName) {
		return true;
	}
	return false;
}

void Subject::enterGrade(Subject* subject, int studentID, std::string exam, float score) {
	for (auto it = studentGrade.begin(); it != studentGrade.end(); it++) {
		if (exam == "�߰�") {
			studentGrade[studentID].setMidtermScore(score);
		}
		else if (exam == "�⸻") {
			studentGrade[studentID].setLastScore(score);
		}
		else {
			std::cout << "�ٽ� �Է��ϼ���." << std::endl;
		}
	}
}

bool compareGrade(Grade& a, Grade& b) {
	return a.getAverage() > b.getAverage();
}

void Subject::calculateRank(Subject* subject, int studentID, std::string format) {
	//int rank = subject->;
	std::vector<Grade> allStudentGrade;
	for (auto it = subject->studentGrade.begin(); it != subject->studentGrade.end(); it++) {
		allStudentGrade.push_back(it->second);
	}

	std::sort(allStudentGrade.begin(), allStudentGrade.end(), compareGrade);

	if (format == "����") {
		std::cout << studentID << "�� ����� = " << subject->studentGrade.find(studentID)->second.getAverage();
	}
	else if (format == "����") {
		int size = (int)allStudentGrade.size();
	}
	else if (format == "���") {
		/*for (int i = 0; i < allStudentGrade.size(); i++) {
			if ()
		}*/
	}
}