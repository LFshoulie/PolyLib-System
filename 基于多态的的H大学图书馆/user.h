#pragma once
#include <iostream>
using namespace std;
#include <string>

//抽象用户类
class User
{
public:

	User()
	{
		this->m_DeptId = 0;
	}

	//显示个人信息
	virtual void showInfo() = 0;
	//获取用户身份
	virtual string getDeptName() = 0;

	string m_Id;  //账号
	string m_Code;  //密码
	int m_DeptId;  //用户身份
};