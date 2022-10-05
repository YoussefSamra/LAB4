#pragma once
#include <iostream>
#include <string>
using namespace std;
class Section
{
private:
	string courseID;
	int studentsCount;
	string* studentsIDs;
public:
	Section();
	Section(string ID, int count);
	//~Section();
	void setCourseID(string ID);
	string getCourseID();
	void setStudentID(string ID, int studentIndex);
	string getStudentID(int studentIndex);
	void printData();
	bool operator>(Section& section);
	bool operator<=(Section& section);
	string operator[](int studentID);
	bool operator==(Section& section);
	Section operator+(Section& section);


};
