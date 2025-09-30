#pragma once
#include <iostream>
using namespace std;
#include "user.h"
#include <string>
#include "book.h"

//读者类
class Reader : public User
{
public:
	//无参构造函数
	Reader();

	//有参构造函数
	Reader(string id, string code, int dId);

	//显示个人信息
	void showInfo();

	//显示个人信息
	void showInfo(Reader *reader,int val);

	//获取用户身份
	string getDeptName();

	//用户登录时查找读者
	int Find_Reader(Reader* reader, string Find_id);

	//调用读者菜单
	void Show_Reader_Menu();

	//修改密码
	void Modf_Code(Reader* reader, int indef);

	//浏览图书   打印所有图书的信息
	void Show_ALL_Book(Book* book);

	//借阅图书
	void Borrow_Book(Book *book,Reader *reader,int val);

	//归还图书
	void Return_Book(Book* book, Reader* reader, int val);

	string m_Borrow_Title_Book;  //读者借书的书名
	string m_Borrow_Id_Book;  //读者借书的国际书籍编号
	int m_ReadBook_Sum;  //每位读者读书的次数
};