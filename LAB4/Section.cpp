#include "Section.h"
Section::Section()
{
	courseID = "XXXX";
	studentsCount = 3;
	studentsIDs = new string[studentsCount];
}
Section::Section(string ID, int count)
{
	courseID = ID;
	studentsCount = count;
	studentsIDs = new string[studentsCount];
}

void Section::setCourseID(string ID)
{
	courseID = ID;
}
string Section::getCourseID()
{
	return courseID;
}
void Section::setStudentID(string ID, int studentIndex)
{
	*(studentsIDs + studentIndex) = ID;
}
string Section::getStudentID(int studentIndex)
{
	return *(studentsIDs + studentIndex);
}
void Section::printData()
{
	cout << courseID << " has " << studentsCount << " students enrolled, whose IDs are ( ";
	for (int i = 0; i < studentsCount; i++)
		cout << *(studentsIDs + i) << " ";
	cout << ")";
}

bool Section::operator>(Section& a)
{
	if (studentsCount > a.studentsCount)
		return true;
	else return false;
}





bool Section::operator<=(Section& a) {
	if (studentsCount <= a.studentsCount)
		return true;
	else return false;

};


string Section::operator[](int a) {

		return getStudentID(a);

};


bool Section::operator==(Section& a) {

	if (studentsCount == a.studentsCount)
		return true;
	else return false;

};


Section Section::operator+(Section& b) {
	Section total(b.getCourseID(), this->studentsCount + b.studentsCount);
	if (this->getCourseID() == b.getCourseID()) {

		for (int i = 0; i < this->studentsCount; i++)
		{
			total.setStudentID(*(this->studentsIDs + i), i);
		}
		for (int i = 0; i < b.studentsCount; i++)
		{
			total.setStudentID(*(b.studentsIDs + i), this->studentsCount + i);
		}

			
		return total;

	} else cout << endl <<"Course ID not the same" << endl;

};



int main() {

	Section s1("CSCE1101", 10);
	Section s2("CSCE1101", 10);
	

	Section s3 = s1 + s2;
	s3.printData();

	Section s4("CSCE1101", 10);
	Section s5("not same", 10);
	

	Section s6 = s4 + s5;
	s6.printData();








	return 0;
}
