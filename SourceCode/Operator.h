#ifndef OPERATOR_H
#define OPERATOR_H
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
class inputError {
public:
	inputError() {}
};//输入错误判定
int enterNum(string&, int&, stringstream&);//判断输入的字符串是否为数字
bool chooseIdentity(int& choice);//选择身份
int administratorOperator(void);
int teacherOperator(void);
int studentOperator(void);
int createCourse(void);
int deleteCourse(void);
int deleteStudent(void);
int deleteTeacher(void);
int studentLogin(int&, string&);//学生登陆界面
int teacherLogin(int&, string&);//老师登陆界面
int teacherLand(int&, string&);//老师已有账号登陆
int teacherRegister(int&, string&);//老师账号注册
int studentLand(int&, string&);//学生已有账号登陆
int studentRegister(int&, string&);//学生已有账号注册
int chooseCourse(int&);//学生选课操作
int dropCourse(int&);//学生退课操作
#endif // !OPERATOR_H
#pragma once
