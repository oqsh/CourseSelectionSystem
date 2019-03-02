#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Course {
	private:
		int serialNum;
		string time, position, teacherName, courseName;
		vector<int> studentList;//存放选择此门课程的学生的ID
	public:
		static int sum;//用于记录课程的总数目（包括被删的）并给课程编号
		static map<int, Course*> allCourse;
		Course(const string&);//以课程的名字为参数的构造函数
		void setTime(const string&);
		void setPosition(const string&);
		void setTeacherName(const string&);
		void setCourseName(const string&);
		void setSerialNum(const int&);
		const int getSerialNum();
		const int getStudentSum();
		const int getStudentId(const int&);
		const string getTime();
		const string getPosition();
		const string getTeacherName();
		const string getCourseName();
		bool findStudent(const int&);
		void addStudent(const int&);//课程被该编号的学生选中
		void popStudent(const int&);//课程被该编号的学生退选
		void display();//显示该门课的详细信息
		static void showAllCourse();//显示全部课程的详细信息
		void readStudent(ifstream&);//从文件中读取该门课程学生的ID信息并写入内存
		void storeStudent(ostream&);//把该门课程学生的ID信息写到文件中
};
#endif // !COURSE_H
#pragma once
