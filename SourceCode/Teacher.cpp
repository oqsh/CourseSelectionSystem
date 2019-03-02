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
		for (int j = 0; j < studentSum; j++)	//删除所有学生里的这位老师任课的课程
			Student::allStudent[Course::allCourse[ownCourse[i]]->getStudentId(j)]->deleteCourse(ownCourse[i]);
		Course::allCourse.erase(ownCourse[i]);	//删除所有课程中由这位老师任课的课程
	}
	ownCourse.clear();
}