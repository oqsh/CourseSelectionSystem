#include "Administrator.h"
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;
Administrator* Administrator::administrator = NULL;

Administrator::Administrator() {
	password = "666666";
}
Administrator* Administrator::getAdministrator() {
	return Administrator::administrator == NULL ? (Administrator::administrator = new Administrator()) : Administrator::administrator; administrator;
}
bool Administrator::checkPassword(const string& str) {
	if (str == password)
		return true;
	return false;
}
bool Administrator::chooseCourse(const int& student, const int& course) {
	if (Course::allCourse.find(course) != Course::allCourse.end()) {
		if (Course::allCourse[course]->findStudent(student)) {
			cout << "�����󡿴˿γ�������Ŀα���\n";
			return false;
		}
		else {
			Course::allCourse[course]->addStudent(student);
			cout << "ѡ�γɹ���\n";
			return true;
		}
	}
	cout << "������ϵͳ�в����ڸÿγ�\n";
	return false;
}
bool Administrator::dropCourse(const int& student, const int& course) {
	if (Course::allCourse.find(course) != Course::allCourse.end()) {
		if (Course::allCourse[course]->findStudent(student)) {
			Course::allCourse[course]->popStudent(student);
			cout << "�˿γɹ���\n";
			return true;
		}
		else {
			cout << "�������㲢û��ѡ��˿γ�\n";
			return false;
		}
	}
	cout << "������ϵͳ�в����ڸÿγ�\n";
	return false;
}
int Administrator::addCourse(const int& teacher, const string& course) {
	if (Teacher::allTeacher.find(teacher) != Teacher::allTeacher.end()) {
		Course* temp = new Course(course);
		Course::allCourse[temp->getSerialNum()] = temp;
		Teacher::allTeacher[teacher]->addCourse(temp->getSerialNum());
		return temp->getSerialNum();
	}
	else {
		cout << "������ϵͳ�в����ڸ���ʦ\n";
		return -1;
	}
}
bool Administrator::deleteCourse(const int& course) {
	map<int, Course*>::iterator i = Course::allCourse.find(course);
	if (i != Course::allCourse.end()) {
		int studentSum = Course::allCourse[course]->getStudentSum();
		for (int j = 0; j < studentSum; j++)
			Student::allStudent[Course::allCourse[course]->getStudentId(j)]->deleteCourse(course);
		for (map<int, Teacher*>::iterator iter = Teacher::allTeacher.begin(); iter != Teacher::allTeacher.end(); iter++) {
			if ((iter->second)->getName() == (Course::allCourse[course]->getTeacherName())) {
				(iter->second)->deleteCourse(course);
				break;
			}
		}
		Course::allCourse.erase(i);
		cout << "�ɹ����˿γ̴�ϵͳ���Ƴ�\n";
		return true;
	}
	else {
		cout << "������ϵͳ�в����ڴ˿γ�\n";
		return false;
	}
}
bool Administrator::deleteStudent(const int& id) {
	map<int, Student*>::iterator i = Student::allStudent.begin();
	for (; i != Student::allStudent.end(); i++) {
		if (i->first == id)
			break;
	}
	if (i == Student::allStudent.end()) {
		cout << "��ѧ�ŵ�ѧ��δ�ڴ�ϵͳע�ᡣ \n";
		return false;
	}
	else {
		Student::allStudent[id]->popAllCourse();
		Student::allStudent.erase(i);
		return true;
	}
}
bool Administrator::deleteTeacher(const int& id) {
	map<int, Teacher*>::iterator i = Teacher::allTeacher.begin();
	for (; i != Teacher::allTeacher.end(); i++) {
		if (i->first == id)
			break;
	}
	if (i == Teacher::allTeacher.end()) {
		cout << "�ù��ŵ���ʦδ�ڴ�ϵͳע�ᡣ \n";
		return false;
	}
	else {
		Teacher::allTeacher[id]->popAllCourse();
		Teacher::allTeacher.erase(id);
		return true;
	}
}