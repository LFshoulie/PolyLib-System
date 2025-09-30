#pragma once
#include <iostream>
using namespace std;
#include "user.h"
#include "book.h"
#include <string>
#include "reader.h"


//管理员类
class Manager : public User
{
public:
	//无参构造函数
	Manager();

	//有参构造函数
	Manager(string id, string code,int dId);

	//显示个人信息
	void showInfo();

	//显示个人信息
	void showInfo(Manager* manager, int val);

	//调用管理员菜单
	void Show_Manager_Menu();

	//用户登录时查找管理员
	int Find_Manager(Manager* manager, string Find_id);

	//修改密码
	void Modf_Code(Manager* manager, int indef);

	//修改图书
	void Modr_Book(Book* book);

	//删除图书
	void Delete_Book(Book* book);

	//添加图书
	void Add_Book(Book* book);

	//添加读者
	void Add_Reader(Reader* reader);

	//删除读者
	void Delete_Reader(Reader* reader);

	//查找读者
	void Find_Reader(Reader* reader);

	//修改读者
	void Modf_Reader(Reader* reader);

	//重置密码
	void Reset_Reader_Code(Reader* reader);

	//获取用户身份
	string getDeptName();
};