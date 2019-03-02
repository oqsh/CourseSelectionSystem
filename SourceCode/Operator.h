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
};//��������ж�
int enterNum(string&, int&, stringstream&);//�ж�������ַ����Ƿ�Ϊ����
bool chooseIdentity(int& choice);//ѡ�����
int administratorOperator(void);
int teacherOperator(void);
int studentOperator(void);
int createCourse(void);
int deleteCourse(void);
int deleteStudent(void);
int deleteTeacher(void);
int studentLogin(int&, string&);//ѧ����½����
int teacherLogin(int&, string&);//��ʦ��½����
int teacherLand(int&, string&);//��ʦ�����˺ŵ�½
int teacherRegister(int&, string&);//��ʦ�˺�ע��
int studentLand(int&, string&);//ѧ�������˺ŵ�½
int studentRegister(int&, string&);//ѧ�������˺�ע��
int chooseCourse(int&);//ѧ��ѡ�β���
int dropCourse(int&);//ѧ���˿β���
#endif // !OPERATOR_H
#pragma once
