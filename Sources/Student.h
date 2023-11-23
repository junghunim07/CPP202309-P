#pragma once
#include <iostream>
#include <string>

class Student {
private :
	std::string studentName;
	std::string phoneNumber;
	int studentID;
	bool checkStudentInformationValidation(int studentID, std::string phoneNumber);
	bool checkStudentID(int studentID);
	bool checkStudentPhoneNumber(std::string phoneNumber);

public :
	Student();
	Student(std::string studentName, int studentID, std::string phoneNumber);
	std::string getStudentName();
	std::string getPhoneNumber();
	int getStudentID();
};