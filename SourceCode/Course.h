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
		vector<int> studentList;//���ѡ����ſγ̵�ѧ����ID
	public:
		static int sum;//���ڼ�¼�γ̵�����Ŀ��������ɾ�ģ������γ̱��
		static map<int, Course*> allCourse;
		Course(const string&);//�Կγ̵�����Ϊ�����Ĺ��캯��
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
		void addStudent(const int&);//�γ̱��ñ�ŵ�ѧ��ѡ��
		void popStudent(const int&);//�γ̱��ñ�ŵ�ѧ����ѡ
		void display();//��ʾ���ſε���ϸ��Ϣ
		static void showAllCourse();//��ʾȫ���γ̵���ϸ��Ϣ
		void readStudent(ifstream&);//���ļ��ж�ȡ���ſγ�ѧ����ID��Ϣ��д���ڴ�
		void storeStudent(ostream&);//�Ѹ��ſγ�ѧ����ID��Ϣд���ļ���
};
#endif // !COURSE_H
#pragma once
