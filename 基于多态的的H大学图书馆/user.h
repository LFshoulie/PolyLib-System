#pragma once
#include <iostream>
using namespace std;
#include <string>

//�����û���
class User
{
public:

	User()
	{
		this->m_DeptId = 0;
	}

	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ�û����
	virtual string getDeptName() = 0;

	string m_Id;  //�˺�
	string m_Code;  //����
	int m_DeptId;  //�û����
};