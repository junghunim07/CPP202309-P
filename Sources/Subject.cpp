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

void Subject::enterGrade(Subject subject, int studentID, std::string exam, float score) {
	for (auto it = studentGrade.begin(); it != studentGrade.end(); it++) {
		Grade grade = studentGrade[studentID];
		if (exam == "Áß°£") {
			grade.setMidtermScore(score);
		}
		else {
			grade.setLastScore(score);
		}
	}
}