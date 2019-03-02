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
		vector<int> ownCourse;//记录自己所有课程的编号
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
		void readCourse(ifstream&);//从文件中读取该老师的课程编号信息并写入内存
		void storeCourse(ostream&);//把该老师自己的课程编号信息写到文件中
};
#endif // !PERSON_H
#pragma once
