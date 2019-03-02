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
		bool checkPassword(const string&);//��ȡ����Ա����
		bool chooseCourse(const int&, const int&);//ͨ����ʦ��ID�Ϳγ̵ı����ѡ��
		bool dropCourse(const int&, const int&);//ͨ����ʦ��ID�Ϳγ̵ı�����˿�
		int addCourse(const int&, const string&); //ͨ����ʦ��ID�Ϳγ̵�����������γ�
		bool deleteCourse(const int&);//ͨ���γ̵ı����ɾ���γ�
		bool deleteStudent(const int&);//ͨ��ѧ����ID��ɾ��ѧ��
		bool deleteTeacher(const int&);//ͨ����ʦ��ID��ɾ����ʦ
};
#endif // !ADMINISTRATOR_H
#pragma once
