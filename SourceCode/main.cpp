#include "Administrator.h"
#include "Course.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Operator.h"
#include "readData.h"
#include "storeData.h"
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

int main() {
	if (_access("./Data", 0) == -1) {
		_mkdir("./Data");
	}
	ifstream i_stuFin("./Data/Student.txt");
	if (!i_stuFin.is_open()) {
		ofstream o_stuFout("./Data/Student.txt");
		o_stuFout.close();
		i_stuFin.open("./Data/Student.txt");
	}
	ifstream i_teacherFin("./Data/Teacher.txt");
	if (!i_teacherFin.is_open()) {
		ofstream o_teacherFout("./Data/Teacher.txt");
		o_teacherFout.close();
		i_teacherFin.open("./Data/Teacher.txt");
	}
	ifstream i_courseFin("./Data/Course.txt");
	if (!i_courseFin.is_open()) {
		ofstream o_courseFout("./Data/Course.txt");
		o_courseFout.close();
		i_courseFin.open("./Data/Course.txt");
	}
	readTeacher(i_teacherFin);
	readCourse(i_courseFin);
	readStudent(i_stuFin);
	//以上操作为对文件的读入
	string end;
	int choice = 10;
	while (chooseIdentity(choice)) {
		system("cls");
		bool flag = true;
		switch (choice) {
		case 1: {
			administratorOperator();
			break;
		}
		case 2: {
			teacherOperator();
			break;
		}
		case 3: {
			studentOperator();
			break;
		}
		default: {
			cout << "【非法输入】请输入数字1-4中的任意一个数字\n\n";
			break;
		}
		}
	}
	//以下操作为将内存中的信息存储到文件中
	ofstream o_stuFile("./Data/Student.txt");
	ofstream o_teacherFile("./Data/Teacher.txt");
	ofstream o_courseFile("./Data/Course.txt");
	writeStudent(o_stuFile);
	writeTeacher(o_teacherFile);
	writeCourse(o_courseFile);
	i_teacherFin.close();
	i_courseFin.close();
	i_stuFin.close();
	o_stuFile.close();
	o_teacherFile.close();
	o_courseFile.close();
	cout << "按任意键继续. . . \n";
	getline(cin, end);
	return 0;
}