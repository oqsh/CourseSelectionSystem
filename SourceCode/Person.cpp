#include "Person.h"
#include "Course.h"
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <stdio.h>
#include <fstream>
using namespace std;

void Person::setName(const string& name) {
	this->name = name;
}
void Person::setId(const int& id) {
	this->id = id;
}
void Person::setPassword(const string& password) {
	this->password = password;
}
const string Person::getName() const {
	return name;
}
const string Person::getPassword() const {
	return password;
}
const int Person::getCourseSum() const {
	return ownCourse.size();
}
const int Person::getId() const {
	return id;
}
void Person::addCourse(const int& course) {
	ownCourse.push_back(course);
}
void Person::deleteCourse(const int& course) {
	vector<int>::iterator i = find(ownCourse.begin(), ownCourse.end(), course);
	ownCourse.erase(i);
}
void Person::showOwnCourse() const {
	if (ownCourse.size() == 0) {
		cout << "暂时没有需要上的课\n";
		return ;
	}
	cout << "以下是你的所有课程：\n";
	printf("%-17s%-20s%-15s%-20s%-10s\n", "Course_SerialNum", "Course_Name", "Teacher_Name", "Time", "Position");
	for (int i = 0; i < ownCourse.size(); i++)
		Course::allCourse[ownCourse[i]]->display();
	cout << "------------------------------------------------------------------\n";
}
bool Person::checkPassword(const string& password) {
	if (this->password == password)
		return true;
	return false;
}
void Person::readCourse(ifstream& fin) {
	string temp;
	int num;
	stringstream ss;
	while (1) {
		getline(fin, temp, '*');
		if (temp == "") {
			getline(fin, temp);
			return ;
		}
		ss << temp;
		ss >> num;
		ss.clear();
		ownCourse.push_back(num);
	}
}
void Person::storeCourse(ostream& fout) {
	for (int i = 0; i < ownCourse.size(); i++)
		fout << ownCourse[i] << "*";
	fout << "*\n";
}