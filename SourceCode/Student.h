#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student :public Person {
	public:
		static map<int, Student*> allStudent;//用于储存所有学生信息
		Student(const int&);//以学生的ID为参数的构造函数
		void chooseCourse(const int&);//选课
		void dropCourse(const int&);//退课
		void popAllCourse();//退选该学生的所有课程
};
#endif // !STUDENT_H
#pragma once
