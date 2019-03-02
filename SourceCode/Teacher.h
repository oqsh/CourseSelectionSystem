#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Teacher :public Person {
	public:
		static map<int, Teacher*> allTeacher;//储存所有老师的信息
		Teacher(const int&);//以老师的ID为参数的构造函数
		void popAllCourse();//删除这老师任教的所有课程
};
#endif // !TEACHER_H
#pragma once
