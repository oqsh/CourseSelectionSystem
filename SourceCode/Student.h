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
		static map<int, Student*> allStudent;//���ڴ�������ѧ����Ϣ
		Student(const int&);//��ѧ����IDΪ�����Ĺ��캯��
		void chooseCourse(const int&);//ѡ��
		void dropCourse(const int&);//�˿�
		void popAllCourse();//��ѡ��ѧ�������пγ�
};
#endif // !STUDENT_H
#pragma once
