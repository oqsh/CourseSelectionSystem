#include "Administrator.h"
#include "Person.h"
#include "Student.h"
#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, Student*> Student::allStudent;

Student::Student(const int& id) {
	setId(id);
}
void Student::chooseCourse(const int& course) {
	if (Administrator::getAdministrator()->chooseCourse(getId(), course))
		addCourse(course);
}
void Student::dropCourse(const int& course) {
	if (Administrator::getAdministrator()->dropCourse(getId(), course))
		deleteCourse(course);
}
void Student::popAllCourse() {
	for (int i = 0; i < ownCourse.size(); i++)
		Administrator::getAdministrator()->dropCourse(getId(), ownCourse[i]);
	system("cls");
	ownCourse.clear();
}