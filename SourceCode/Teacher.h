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
		static map<int, Teacher*> allTeacher;//����������ʦ����Ϣ
		Teacher(const int&);//����ʦ��IDΪ�����Ĺ��캯��
		void popAllCourse();//ɾ������ʦ�ν̵����пγ�
};
#endif // !TEACHER_H
#pragma once
