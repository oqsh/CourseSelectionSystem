#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Administrator{
	private:
		string password;
		static Administrator *administrator;
	public:
		Administrator();
		static Administrator* getAdministrator();
		bool checkPassword(const string&);//获取管理员密码
		bool chooseCourse(const int&, const int&);//通过老师的ID和课程的编号来选课
		bool dropCourse(const int&, const int&);//通过老师的ID和课程的编号来退课
		int addCourse(const int&, const string&); //通过老师的ID和课程的名字来增添课程
		bool deleteCourse(const int&);//通过课程的编号来删除课程
		bool deleteStudent(const int&);//通过学生的ID来删除学生
		bool deleteTeacher(const int&);//通过老师的ID来删除老师
};
#endif // !ADMINISTRATOR_H
#pragma once
