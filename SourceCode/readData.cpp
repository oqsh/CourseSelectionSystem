#include "readData.h"
#include "Administrator.h"
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Operator.h"
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <io.h>
#include <fstream>
#include <direct.h>
using namespace std;

stringstream ss;

void readTeacher(ifstream& fin) {
	int sum, num;
	string temp;
	getline(fin, temp);
	if (temp == "" || temp == "0")
		return;
	ss << temp;
	ss >> sum;
	ss.clear();
	for (int i = 0; i < sum; i++) {
		getline(fin, temp);
		ss << temp;
		ss >> num;
		ss.clear();
		Teacher* teacher = new Teacher(num);
		getline(fin, temp);
		teacher->setName(temp);
		getline(fin, temp);
		teacher->setPassword(temp);
		Teacher::allTeacher[num] = teacher;
		teacher->readCourse(fin);
	}
}
void readStudent(ifstream& fin) {
	int sum, num;
	string temp;
	getline(fin, temp);
	if (temp == "" || temp == "0")
		return;
	ss << temp;
	ss >> sum;
	ss.clear();
	for (int i = 0; i < sum; i++) {
		getline(fin, temp);
		ss << temp;
		ss >> num;
		ss.clear();
		Student* student = new Student(num);
		getline(fin, temp);
		student->setName(temp);
		getline(fin, temp);
		student->setPassword(temp);
		Student::allStudent[num] = student;
		student->readCourse(fin);
	}
}

void readCourse(ifstream& fin) {
	int sum, num;
	string temp;
	getline(fin, temp);
	if (temp == "" || temp == "0")
		return;
	ss << temp;
	ss >> sum;
	ss.clear();
	for (int i = 0; i < sum; i++) {
		getline(fin, temp);
		Course* course = new Course(temp);
		getline(fin, temp);
		ss << temp;
		ss >> num;
		ss.clear();
		course->setSerialNum(num);
		getline(fin, temp);
		course->setTime(temp);
		getline(fin, temp);
		course->setPosition(temp);
		getline(fin, temp);
		course->setTeacherName(temp);
		Course::allCourse[num] = course;
		course->readStudent(fin);
	}
	Course::sum = num + 1;
}