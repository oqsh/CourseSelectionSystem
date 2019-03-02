#include "storeData.h"
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


void writeTeacher(ostream& fout) {
	fout << Teacher::allTeacher.size() << "\n";
	map<int, Teacher*>::iterator i = Teacher::allTeacher.begin();
	for (; i != Teacher::allTeacher.end(); i++) {
		fout << (i->second)->getId() << "\n";
		fout << (i->second)->getName() << "\n";
		fout << (i->second)->getPassword() << "\n";
		(i->second)->storeCourse(fout);
	}
}
void writeStudent(ostream& fout) {
	fout << Student::allStudent.size() << "\n";
	map<int, Student*>::iterator i = Student::allStudent.begin();
	for (; i != Student::allStudent.end(); i++) {
		fout << (i->second)->getId() << "\n";
		fout << (i->second)->getName() << "\n";
		fout << (i->second)->getPassword() << "\n";
		(i->second)->storeCourse(fout);
	}
}
void writeCourse(ofstream& fout) {
	fout << Course::allCourse.size() << "\n";
	map<int, Course*>::iterator i = Course::allCourse.begin();
	for (; i != Course::allCourse.end(); i++) {
		fout << (i->second)->getCourseName() << "\n";
		fout << (i->second)->getSerialNum() << "\n";
		fout << (i->second)->getTime() << "\n";
		fout << (i->second)->getPosition() << "\n";
		fout << (i->second)->getTeacherName() << "\n";
		(i->second)->storeStudent(fout);
	}
}

