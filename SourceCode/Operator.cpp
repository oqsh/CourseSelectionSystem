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
using namespace std;
int enterNum(string& str, int& choose, stringstream& ss) {
	try {
		getline(cin, str);
		for (int i = 0; i < str.length(); i++) {
			if (str[i] < '0' || str[i] > '9')
				throw inputError();
		}
		ss << str;
		ss >> choose;
		ss.clear();
		return 0;
	}
	catch (inputError& ex) {
		system("cls");
		cout << "【非法输入】此处请输入数字\n";
		cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n";
		getline(cin, str);
		system("cls");
		if (str == "b")
			return -1;
		return 1;
	}
}
bool chooseIdentity(int& choice) {
	stringstream ss;
	string c;
	int test;
	while (1) {
		cout << "请选择你的权限：\n"
			<< "1. 管理员\n"
			<< "2. 老师\n"
			<< "3. 学生\n"
			<< "4. 退出系统\n>>> ";
		test = enterNum(c, choice, ss);
		if (test == 0) {
			if (choice == 4) {
				cout << "Bye-bye!\n";
				return false;
			}
			return true;
		}
		else if (test == -1) {
			cout << "确定退出系统？\n输入“f”取消操作，按任意键继续\n>>> ";
			getline(cin, c);
			if (c != "f") {
				cout << "再见. . . \n";
				return false;
			}
		}
	}
}
int administratorOperator(void) {
	int choice, result, id, test;
	string name, temp;
	stringstream ss;
	system("cls");
	while (1) {
		cout << "请输入密码： \n>>> ";
		getline(cin, temp);
		if (temp == "666666")
			break;
		else {
			cout << "【错误】输入密码错误！\n"
				<< "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
		}
	}

	while (1) {
		system("cls");
		cout << "你好，管理员，欢迎使用中山大学选课系统\n";
		cout << "---------------------------------------------------------------\n";
		cout << "请选择你要进行的操作：\n"
			<< "1. 查看所有课程\n"
			<< "2. 增添课程\n"
			<< "3. 取消课程\n"
			<< "4. 删除学生\n"
			<< "5. 删除老师\n"
			<< "6. 返回选择权限菜单\n>>> ";
		test = enterNum(temp, choice, ss);
		if (test == 0) {
			switch (choice) {
			case 1: {
				system("cls");
				Course::showAllCourse();
				cout << "按任意键返回上一级菜单. . . \n";
				getline(cin, temp);
				break;
			}
			case 2: {
				system("cls");
				for (result = createCourse(); result == 0; result = createCourse());
				break;
			}
			case 3: {
				system("cls");
				for (result = deleteCourse(); result == 0; result = deleteCourse());
				break;
			}
			case 4: {
				system("cls");
				for (result = deleteStudent(); result == 0; result = deleteStudent());
				break;
			}
			case 5: {
				system("cls");
				for (result = deleteTeacher(); result == 0; result = deleteTeacher());
				break;
			}
			case 6: {
				system("cls");
				return -1;
			}
			default: {
				system("cls");
				cout << "【非法输入】请输入数字1-5中的任意一个数字\n";
				cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n>>> ";
				getline(cin, temp);
				if (temp == "b")
					return -1;
				break;
			}
			}
		}
		else if (test == -1)
			return -1;
	}

}
int createCourse(void) {
	int test, teacher;
	string courseName, temp;
	stringstream ss;
	cout << "请输入你要创建的课程名称： \n>>> ";
	getline(cin, courseName);
	cout << "请输入任课老师的工号： \n>>> ";
	test = enterNum(temp, teacher, ss);
	if (test == 1)
		return 0;
	else if (test == -1)
		return 1;
	int serialNum = Administrator::getAdministrator()->addCourse(teacher, courseName);
	if (serialNum != -1) {
		cout << "请输入此课程的上课时间： \n>>> ";
		getline(cin, temp);
		Course::allCourse[serialNum]->setTime(temp);
		cout << "请输入此课程的上课地点： \n>>> ";
		getline(cin, temp);
		Course::allCourse[serialNum]->setPosition(temp);
		Course::allCourse[serialNum]->setTeacherName(Teacher::allTeacher[teacher]->getName());
		system("cls");
		cout << "成功添加此课程到系统。\n";
		cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n";
		getline(cin, temp);
		system("cls");
		if (temp == "b")
			return 1;
		return 0;
	}
	else {
		cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n";
		getline(cin, temp);
		system("cls");
		if (temp == "b")
			return 1;
		return 0;
	}
}
int deleteCourse(void) {
	int serialNum, test;
	string temp;
	stringstream ss;
	cout << "请输入你要删除的课程的编号： \n>>> ";
	test = enterNum(temp, serialNum, ss);
	if (test == 0) {
		Administrator::getAdministrator()->deleteCourse(serialNum);
		cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n";
		getline(cin, temp);
		system("cls");
		if (temp == "b")
			return 1;
		return 0;
	}
	else if (test == -1)
		return 1;
	else
		return 0;
}
int deleteStudent(void) {
	int id, test;
	string temp;
	stringstream ss;
	cout << "请输入你要从系统中移除的学生的学号： \n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Administrator::getAdministrator()->deleteStudent(id)) {
			cout << "成功把此学生从系统中删除。 \n>>> ";
		}
		cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n";
		getline(cin, temp);
		system("cls");
		if (temp == "b")
			return 1;
		return 0;
	}
	else if (test == -1)
		return 1;
	else
		return 0;
}
int deleteTeacher(void) {
	int id, test;
	string temp;
	stringstream ss;
	cout << "请输入你要从系统中移除的老师的工号： \n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Administrator::getAdministrator()->deleteTeacher(id)) {
			cout << "成功把此老师从系统中删除。 \n>>> ";
		}
		cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n";
		getline(cin, temp);
		system("cls");
		if (temp == "b")
			return 1;
		return 0;
	}
	else if (test == -1)
		return 1;
	else
		return 0;
}
int teacherOperator(void) {
	int result, choice;
	int id = 555, test;
	string name, temp;
	stringstream ss;
	for (result = teacherLogin(id, name); result == 0; result = teacherLogin(id, name));
	system("cls");
	if (result == -1)
		return 0;
	while (1) {
		system("cls");
		cout << "你好，" << name << "老师，欢迎使用中山大学选课系统\n";
		cout << "---------------------------------------------------------------\n";
		cout << "请选择你要进行的操作：\n"
			<< "1. 查看所有课程\n"
			<< "2. 查看自己已有的课程\n"
			<< "3. 返回选择权限菜单\n>>> ";
		test = enterNum(temp, choice, ss);
		if (test == 0) {
			switch (choice) {
			case 1: {
				system("cls");
				Course::showAllCourse();
				cout << "按任意键返回上一级菜单. . . \n";
				getline(cin, temp);
				break;
			}
			case 2: {
				system("cls");
				Teacher::allTeacher[id]->showOwnCourse();
				cout << "按任意键返回上一级菜单. . . \n";
				getline(cin, temp);
				system("cls");
				break;
			}
			case 3: {
				system("cls");
				return -1;
			}
			default: {
				system("cls");
				cout << "【非法输入】请输入数字1-3中的任意一个数字\n";
				cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n>>> ";
				getline(cin, temp);
				system("cls");
				if (temp == "b")
					return -1;
				break;
			}
			}
		}
		else if (test == -1)
			return -1;
	}
}
int studentOperator(void) {
	int result, choice;
	int id = 555, test;
	string name, temp;
	stringstream ss;
	for (result = studentLogin(id, name); result == 0; result = studentLogin(id, name));
	system("cls");
	if (result == -1)
		return 0;
	while (1) {
		system("cls");
		cout << "你好，" << name << "同学，欢迎使用中山大学选课系统\n";
		cout << "---------------------------------------------------------------\n";
		cout << "请选择你要进行的操作：\n"
			<< "1. 查看所有课程\n"
			<< "2. 选课\n"
			<< "3. 退课\n"
			<< "4. 查看自己已有的课程\n"
			<< "5. 返回选择权限菜单\n>>> ";
		test = enterNum(temp, choice, ss);
		if (test == 0) {
			switch (choice) {
			case 1: {
				system("cls");
				Course::showAllCourse();
				cout << "按任意键返回上一级菜单. . . \n";
				getline(cin, temp);
				system("cls");
				break;
			}
			case 2: {
				for (result = chooseCourse(id); result == 0; result = chooseCourse(id));
				break;
			}
			case 3: {
				for (result = dropCourse(id); result == 0; result = dropCourse(id));
				break;
			}
			case 4: {
				system("cls");
				Student::allStudent[id]->showOwnCourse();
				cout << "按任意键返回上一级菜单. . . \n";
				getline(cin, temp);
				system("cls");
				break;
			}
			case 5: {
				system("cls");
				return -1;
			}
			default: {
				system("cls");
				cout << "【非法输入】请输入数字1-5中的任意一个数字\n";
				cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n>>> ";
				getline(cin, temp);
				system("cls");
				if (temp == "b")
					return -1;
				break;
			}
			}
		}
		else if (test == -1)
			return -1;
	}
}

int studentLogin(int& id, string& name){
		stringstream ss;
		string c, temp;
		int choose, test;
		system("cls");
		cout << "请选择你要进行的操作：\n"
			<< "1. 登陆已有的账号\n"
			<< "2. 注册新的账号\n"
			<< "3. 返回\n>>> ";
		test = enterNum(c, choose, ss);
		if (test == 0) {
			system("cls");
			switch (choose) {
			case 1: {
				int result;
				for (result = studentLand(id, name); result == 0; result = studentLand(id, name));
				if (result == -1)
					return -1;
				return 1;
			}
			case 2: {
				int result;
				for (result = studentRegister(id, name); result == 0; result = studentRegister(id, name));
				if (result == -1)
					return -1;
				return 1;
			}
			case 3: {
				return -1;
			}
			default: {
				cout << "【非法输入】请输入数字1-3中的任意一个数字\n";
				cout << "按任意键重新进行输入. . . \n";
				getline(cin, temp);
				system("cls");
				return 0;
			}
			}
		}
		else if (test == -1)
			return -1;
		else
			return 0;
}
int teacherLogin(int& id, string& name) {
	stringstream ss;
	string c, temp;
	int choose, test;
	system("cls");
	cout << "请选择你要进行的操作：\n"
		<< "1. 登陆已有的账号\n"
		<< "2. 注册新的账号\n"
		<< "3. 返回\n>>> ";
	test = enterNum(c, choose, ss);
	if (test == 0) {
		system("cls");
		switch (choose) {
		case 1: {
			int result;
			for (result = teacherLand(id, name); result == 0; result = teacherLand(id, name));
			if (result == -1)
				return -1;
			return 1;
		}
		case 2: {
			int result;
			for (result = teacherRegister(id, name); result == 0; result = teacherRegister(id, name));
			if (result == -1)
				return -1;
			return 1;
		}
		case 3: {
			return -1;
		}
		default: {
			cout << "【非法输入】请输入数字1-3中的任意一个数字\n";
			cout << "按任意键重新进行输入. . . \n";
			getline(cin, temp);
			system("cls");
			return 0;
		}
		}
	}
	else if (test == -1)
		return -1;
	else
		return 0;
}
int teacherLand(int& id, string& name) {
	stringstream ss;
	string temp;
	int test;
	cout << "请输入你的工号：\n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Teacher::allTeacher.find(id) == Teacher::allTeacher.end()) {
			cout << "【错误】该工号尚未注册\n\n";
			cout << "输入“b”返回上一层界面，按任意键重新输入. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
		cout << "请输入你的密码：\n>>> ";
		getline(cin, temp);
		if (Teacher::allTeacher[id]->checkPassword(temp)) {
			name = Teacher::allTeacher[id]->getName();
			return 1;
		}
		else {
			int choose;
			cout << "【错误】密码错误\n\n";
			cout << "输入“b”返回上一层界面，按任意键重新输入. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
	}
	else if (test == -1)
		return -1;
	else
		return 0;
}
int teacherRegister(int& id, string& name) {
	stringstream ss;
	string temp;
	int test;
	cout << "请输入你的工号：\n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Teacher::allTeacher.find(id) != Teacher::allTeacher.end()) {
			cout << "【错误】该工号已经被注册\n\n";
			cout << "输入“b”返回上一层界面，按任意键重新输入. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
		cout << "请输入你的密码：\n>>> ";
		getline(cin, temp);
		cout << "请输入你的姓名：\n>>> ";
		getline(cin, name);
		Teacher* teacher = new Teacher(id);
		teacher->setPassword(temp);
		teacher->setName(name);
		Teacher::allTeacher[id] = teacher;
		return 1;
	}
	else if (test == -1)
		return -1;
	else
		return 0;
}

int studentLand(int& id, string& name) {
	stringstream ss;
	string temp;
	int test;
	cout << "请输入你的学号：\n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Student::allStudent.find(id) == Student::allStudent.end()) {
			cout << "【错误】该学号尚未注册\n\n";
			cout << "输入“b”返回上一层界面，按任意键重新输入. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
		cout << "请输入你的密码：\n>>> ";
		getline(cin, temp);
		if (Student::allStudent[id]->checkPassword(temp)) {
			name = Student::allStudent[id]->getName();
			return 1;
		}
		else {
			int choose;
			cout << "【错误】密码错误\n\n";
			cout << "输入“b”返回上一层界面，按任意键重新输入. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
	}
	else if (test == -1)
		return -1;
	else
		return 0;
}
int studentRegister(int& id, string& name) {
	stringstream ss;
	string temp;
	int test;
	cout << "请输入你的学号：\n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Student::allStudent.find(id) != Student::allStudent.end()) {
			cout << "【错误】该学号已经被注册\n\n";
			cout << "输入“b”返回上一层界面，按任意键重新输入. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
		cout << "请输入你的密码：\n>>> ";
		getline(cin, temp);
		cout << "请输入你的姓名：\n>>> ";
		getline(cin, name);
		Student* student = new Student(id);
		student->setPassword(temp);
		student->setName(name);
		Student::allStudent[id] = student;
		return 1;
	}
	else if (test == -1)
		return -1;
	else
		return 0;
}
int chooseCourse(int& id) {
	int choice;
	string temp;
	stringstream ss;
	int test;
	system("cls");
	cout << "请输入你想要选择的课程的课程编号:\n>>> ";
	test = enterNum(temp, choice, ss);
	if (test == 0) {
		if (Course::allCourse.find(choice) != Course::allCourse.end()) {
			Student::allStudent[id]->chooseCourse(choice);
			cout << "输入“b”返回上一级菜单，按任意键继续进行选择. . . \n";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return 1;
			return 0;
		}
		else {
			cout << "【错误】系统中不存在对应该课程编号的课程\n";
			cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return 1;
			return 0;
		}
	}
	else if (test = -1)
		return 1;
	else
		return 0;
}
int dropCourse(int& id) {
	int choice;
	string temp;
	stringstream ss;
	int test = 0;
	system("cls");
	cout << "请输入你想要退选的课程的课程编号:\n>>> ";
	test = enterNum(temp, choice, ss);
	if (test == 0) {
		if (Course::allCourse.find(choice) != Course::allCourse.end()) {
			Student::allStudent[id]->dropCourse(choice);
			cout << "输入“b”返回上一级菜单，按任意键继续进行选择. . . \n";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return 1;
			return 0;
		}
		else {
			cout << "【错误】系统中不存在对应该课程编号的课程\n";
			cout << "输入“b”返回上一级菜单，按任意键重新进行操作. . . \n";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return 1;
			return 0;
		}
	}
	else if (test == -1)
		return 1;
	return 0;
}