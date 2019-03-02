#include "Person.h"
#include "Teacher.h"
#include "Administrator.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <map>
using namespace std;

map<int, Teacher*> Teacher::allTeacher;

Teacher::Teacher(const int& id) {
	setId(id);
}
void Teacher::popAllCourse() {
	for (int i = 0; i < ownCourse.size(); i++) {
		int studentSum = Course::allCourse[ownCourse[i]]->getStudentSum();
		for (int j = 0; j < studentSum; j++)	//ɾ������ѧ�������λ��ʦ�οεĿγ�
			Student::allStudent[Course::allCourse[ownCourse[i]]->getStudentId(j)]->deleteCourse(ownCourse[i]);
		Course::allCourse.erase(ownCourse[i]);	//ɾ�����пγ�������λ��ʦ�οεĿγ�
	}
	ownCourse.clear();
}