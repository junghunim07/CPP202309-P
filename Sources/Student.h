#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student {
private :
	string name;
	int studentID;
	string phoneNumber;

public :
	Student(string name, int studentID, string phoneNumber);
	string getName();
	string getPhoneNumber();
	int getStudentID();
	void studentValidation(Student student);
};