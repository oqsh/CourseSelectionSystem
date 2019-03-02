#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Person {
	private:
		int id;
		string name, password;
	protected:
		vector<int> ownCourse;//��¼�Լ����пγ̵ı��
	public:
		void setName(const string&);
		void setId(const int&);
		void setPassword(const string&);
		const string getName() const;
		const string getPassword() const;
		const int getCourseSum() const;
		const int getId() const;
		void addCourse(const int&);
		void deleteCourse(const int&);
		void showOwnCourse() const;
		bool checkPassword(const string&);
		void readCourse(ifstream&);//���ļ��ж�ȡ����ʦ�Ŀγ̱����Ϣ��д���ڴ�
		void storeCourse(ostream&);//�Ѹ���ʦ�Լ��Ŀγ̱����Ϣд���ļ���
};
#endif // !PERSON_H
#pragma once
