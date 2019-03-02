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
		cout << "���Ƿ����롿�˴�����������\n";
		cout << "���롰b��������һ���˵�������������½��в���. . . \n";
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
		cout << "��ѡ�����Ȩ�ޣ�\n"
			<< "1. ����Ա\n"
			<< "2. ��ʦ\n"
			<< "3. ѧ��\n"
			<< "4. �˳�ϵͳ\n>>> ";
		test = enterNum(c, choice, ss);
		if (test == 0) {
			if (choice == 4) {
				cout << "Bye-bye!\n";
				return false;
			}
			return true;
		}
		else if (test == -1) {
			cout << "ȷ���˳�ϵͳ��\n���롰f��ȡ�������������������\n>>> ";
			getline(cin, c);
			if (c != "f") {
				cout << "�ټ�. . . \n";
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
		cout << "���������룺 \n>>> ";
		getline(cin, temp);
		if (temp == "666666")
			break;
		else {
			cout << "�����������������\n"
				<< "���롰b��������һ���˵�������������½��в���. . . \n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
		}
	}

	while (1) {
		system("cls");
		cout << "��ã�����Ա����ӭʹ����ɽ��ѧѡ��ϵͳ\n";
		cout << "---------------------------------------------------------------\n";
		cout << "��ѡ����Ҫ���еĲ�����\n"
			<< "1. �鿴���пγ�\n"
			<< "2. ����γ�\n"
			<< "3. ȡ���γ�\n"
			<< "4. ɾ��ѧ��\n"
			<< "5. ɾ����ʦ\n"
			<< "6. ����ѡ��Ȩ�޲˵�\n>>> ";
		test = enterNum(temp, choice, ss);
		if (test == 0) {
			switch (choice) {
			case 1: {
				system("cls");
				Course::showAllCourse();
				cout << "�������������һ���˵�. . . \n";
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
				cout << "���Ƿ����롿����������1-5�е�����һ������\n";
				cout << "���롰b��������һ���˵�������������½��в���. . . \n>>> ";
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
	cout << "��������Ҫ�����Ŀγ����ƣ� \n>>> ";
	getline(cin, courseName);
	cout << "�������ο���ʦ�Ĺ��ţ� \n>>> ";
	test = enterNum(temp, teacher, ss);
	if (test == 1)
		return 0;
	else if (test == -1)
		return 1;
	int serialNum = Administrator::getAdministrator()->addCourse(teacher, courseName);
	if (serialNum != -1) {
		cout << "������˿γ̵��Ͽ�ʱ�䣺 \n>>> ";
		getline(cin, temp);
		Course::allCourse[serialNum]->setTime(temp);
		cout << "������˿γ̵��Ͽεص㣺 \n>>> ";
		getline(cin, temp);
		Course::allCourse[serialNum]->setPosition(temp);
		Course::allCourse[serialNum]->setTeacherName(Teacher::allTeacher[teacher]->getName());
		system("cls");
		cout << "�ɹ���Ӵ˿γ̵�ϵͳ��\n";
		cout << "���롰b��������һ���˵�������������½��в���. . . \n";
		getline(cin, temp);
		system("cls");
		if (temp == "b")
			return 1;
		return 0;
	}
	else {
		cout << "���롰b��������һ���˵�������������½��в���. . . \n";
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
	cout << "��������Ҫɾ���Ŀγ̵ı�ţ� \n>>> ";
	test = enterNum(temp, serialNum, ss);
	if (test == 0) {
		Administrator::getAdministrator()->deleteCourse(serialNum);
		cout << "���롰b��������һ���˵�������������½��в���. . . \n";
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
	cout << "��������Ҫ��ϵͳ���Ƴ���ѧ����ѧ�ţ� \n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Administrator::getAdministrator()->deleteStudent(id)) {
			cout << "�ɹ��Ѵ�ѧ����ϵͳ��ɾ���� \n>>> ";
		}
		cout << "���롰b��������һ���˵�������������½��в���. . . \n";
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
	cout << "��������Ҫ��ϵͳ���Ƴ�����ʦ�Ĺ��ţ� \n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Administrator::getAdministrator()->deleteTeacher(id)) {
			cout << "�ɹ��Ѵ���ʦ��ϵͳ��ɾ���� \n>>> ";
		}
		cout << "���롰b��������һ���˵�������������½��в���. . . \n";
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
		cout << "��ã�" << name << "��ʦ����ӭʹ����ɽ��ѧѡ��ϵͳ\n";
		cout << "---------------------------------------------------------------\n";
		cout << "��ѡ����Ҫ���еĲ�����\n"
			<< "1. �鿴���пγ�\n"
			<< "2. �鿴�Լ����еĿγ�\n"
			<< "3. ����ѡ��Ȩ�޲˵�\n>>> ";
		test = enterNum(temp, choice, ss);
		if (test == 0) {
			switch (choice) {
			case 1: {
				system("cls");
				Course::showAllCourse();
				cout << "�������������һ���˵�. . . \n";
				getline(cin, temp);
				break;
			}
			case 2: {
				system("cls");
				Teacher::allTeacher[id]->showOwnCourse();
				cout << "�������������һ���˵�. . . \n";
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
				cout << "���Ƿ����롿����������1-3�е�����һ������\n";
				cout << "���롰b��������һ���˵�������������½��в���. . . \n>>> ";
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
		cout << "��ã�" << name << "ͬѧ����ӭʹ����ɽ��ѧѡ��ϵͳ\n";
		cout << "---------------------------------------------------------------\n";
		cout << "��ѡ����Ҫ���еĲ�����\n"
			<< "1. �鿴���пγ�\n"
			<< "2. ѡ��\n"
			<< "3. �˿�\n"
			<< "4. �鿴�Լ����еĿγ�\n"
			<< "5. ����ѡ��Ȩ�޲˵�\n>>> ";
		test = enterNum(temp, choice, ss);
		if (test == 0) {
			switch (choice) {
			case 1: {
				system("cls");
				Course::showAllCourse();
				cout << "�������������һ���˵�. . . \n";
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
				cout << "�������������һ���˵�. . . \n";
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
				cout << "���Ƿ����롿����������1-5�е�����һ������\n";
				cout << "���롰b��������һ���˵�������������½��в���. . . \n>>> ";
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
		cout << "��ѡ����Ҫ���еĲ�����\n"
			<< "1. ��½���е��˺�\n"
			<< "2. ע���µ��˺�\n"
			<< "3. ����\n>>> ";
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
				cout << "���Ƿ����롿����������1-3�е�����һ������\n";
				cout << "����������½�������. . . \n";
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
	cout << "��ѡ����Ҫ���еĲ�����\n"
		<< "1. ��½���е��˺�\n"
		<< "2. ע���µ��˺�\n"
		<< "3. ����\n>>> ";
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
			cout << "���Ƿ����롿����������1-3�е�����һ������\n";
			cout << "����������½�������. . . \n";
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
	cout << "��������Ĺ��ţ�\n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Teacher::allTeacher.find(id) == Teacher::allTeacher.end()) {
			cout << "�����󡿸ù�����δע��\n\n";
			cout << "���롰b��������һ����棬���������������. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
		cout << "������������룺\n>>> ";
		getline(cin, temp);
		if (Teacher::allTeacher[id]->checkPassword(temp)) {
			name = Teacher::allTeacher[id]->getName();
			return 1;
		}
		else {
			int choose;
			cout << "�������������\n\n";
			cout << "���롰b��������һ����棬���������������. . .\n>>> ";
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
	cout << "��������Ĺ��ţ�\n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Teacher::allTeacher.find(id) != Teacher::allTeacher.end()) {
			cout << "�����󡿸ù����Ѿ���ע��\n\n";
			cout << "���롰b��������һ����棬���������������. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
		cout << "������������룺\n>>> ";
		getline(cin, temp);
		cout << "���������������\n>>> ";
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
	cout << "���������ѧ�ţ�\n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Student::allStudent.find(id) == Student::allStudent.end()) {
			cout << "�����󡿸�ѧ����δע��\n\n";
			cout << "���롰b��������һ����棬���������������. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
		cout << "������������룺\n>>> ";
		getline(cin, temp);
		if (Student::allStudent[id]->checkPassword(temp)) {
			name = Student::allStudent[id]->getName();
			return 1;
		}
		else {
			int choose;
			cout << "�������������\n\n";
			cout << "���롰b��������һ����棬���������������. . .\n>>> ";
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
	cout << "���������ѧ�ţ�\n>>> ";
	test = enterNum(temp, id, ss);
	if (test == 0) {
		if (Student::allStudent.find(id) != Student::allStudent.end()) {
			cout << "�����󡿸�ѧ���Ѿ���ע��\n\n";
			cout << "���롰b��������һ����棬���������������. . .\n>>> ";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return -1;
			return 0;
		}
		cout << "������������룺\n>>> ";
		getline(cin, temp);
		cout << "���������������\n>>> ";
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
	cout << "����������Ҫѡ��Ŀγ̵Ŀγ̱��:\n>>> ";
	test = enterNum(temp, choice, ss);
	if (test == 0) {
		if (Course::allCourse.find(choice) != Course::allCourse.end()) {
			Student::allStudent[id]->chooseCourse(choice);
			cout << "���롰b��������һ���˵������������������ѡ��. . . \n";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return 1;
			return 0;
		}
		else {
			cout << "������ϵͳ�в����ڶ�Ӧ�ÿγ̱�ŵĿγ�\n";
			cout << "���롰b��������һ���˵�������������½��в���. . . \n";
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
	cout << "����������Ҫ��ѡ�Ŀγ̵Ŀγ̱��:\n>>> ";
	test = enterNum(temp, choice, ss);
	if (test == 0) {
		if (Course::allCourse.find(choice) != Course::allCourse.end()) {
			Student::allStudent[id]->dropCourse(choice);
			cout << "���롰b��������һ���˵������������������ѡ��. . . \n";
			getline(cin, temp);
			system("cls");
			if (temp == "b")
				return 1;
			return 0;
		}
		else {
			cout << "������ϵͳ�в����ڶ�Ӧ�ÿγ̱�ŵĿγ�\n";
			cout << "���롰b��������һ���˵�������������½��в���. . . \n";
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