#include "Course.h"
#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;

int Course::sum = 0;
map<int, Course*> Course::allCourse;

Course::Course(const string& str) {
	courseName = str;
	serialNum = sum;
	allCourse[serialNum] = this;
	sum++;
}
void Course::setTime(const string& time) {
	this->time = time;
}
void Course::setPosition(const string& position) {
	this->position = position;
}
void Course::setTeacherName(const string& teacherName) {
	this->teacherName = teacherName;
}
void Course::setCourseName(const string& courseName) {
	this->courseName = courseName;
}
void Course::setSerialNum(const int& num) {
	serialNum = num;
}
const int Course::getSerialNum(){
	return serialNum;
}
const int Course::getStudentSum(){
	return studentList.size();
}
const int Course::getStudentId(const int& pos) {
	return studentList[pos];
}
const string Course::getTime(){
	return time;
}
const string Course::getPosition(){
	return position;
}
const string Course::getTeacherName(){
	return teacherName;
}
const string Course::getCourseName(){
	return courseName;
}
bool Course::findStudent(const int& student) {
	if (find(studentList.begin(), studentList.end(), student) != studentList.end())
		return true;
	return false;
}
void Course::addStudent(const int& student){
	studentList.push_back(student);
}
void Course::popStudent(const int& student){
	vector<int>::iterator i = find(studentList.begin(), studentList.end(), student);
	studentList.erase(i);
}
void Course::display() {
	printf("%-17d%-20s%-15s%-20s%-10s\n", serialNum, courseName.c_str(), teacherName.c_str(), time.c_str(), position.c_str());
}
void Course::showAllCourse() {
	if (allCourse.size() == 0)
		cout << "系统中没有可供选择的课程\n";
	else {
		cout << "以下是选课系统中可供选择的课程：\n";
		printf("%-17s%-20s%-15s%-20s%-10s\n", "Course_SerialNum", "Course_Name", "Teacher_Name", "Time", "Position");
		for (map<int, Course*>::iterator i = allCourse.begin(); i != allCourse.end(); i++)
			(i->second)->display();
	}
	cout << "------------------------------------------------------------------\n";
}
void Course::readStudent(ifstream& fin) {
	string temp;
	int num;
	stringstream ss;
	while (1) {
		getline(fin, temp, '*');
		if (temp == "") {
			getline(fin, temp);
			return;
		}
		ss << temp;
		ss >> num;
		ss.clear();
		
		studentList.push_back(num);
	}
}
void Course::storeStudent(ostream& fout) {
	for (int i = 0; i < studentList.size(); i++)
		fout << studentList[i] << "*";
	fout << "*\n";
}