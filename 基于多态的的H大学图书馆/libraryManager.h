#pragma once  //保证头文件只编译一次
#include <iostream>
using namespace std;
#include "user.h"
#include "manager.h"
#include "reader.h"
#include "book.h"
#include <fstream>

class LibraryManager
{
public:
	
	//构造函数
	LibraryManager();

	//展会管理系统的菜单
	void ShowMenu();

	//退出系统
	void Exit_LibraryManager();

	//调取排行榜
	void Show_Ranking_List(Book* book, Reader* reader);

	//注册用户信息    管理员
	void Register_Manager(Manager* manager);

	//注册用户信息    读者
	void Register_Reader(Reader* reader);

	//写文件    书籍
	void Ofstream_Book(Book* book);
	//读文件    书籍
	void Ifstream_Book(Book* book);

	//写文件    管理员信息
	void Ofstream_Manager(Manager* manager);
	//读文件    管理员信息
	void Ifstream_Manager(Manager* manager);

	//写文件    读者信息
	void Ofstream_Reader(Reader* reader);
	//读文件    读者信息
	void Ifstream_Reader(Reader* reader);

	//打印书籍信息函数
	void Show_InFo(Book* book, int indef);

	//根据书名排序图书    为了实现字典排序
	void Sort_Title_Book(Book* book);

	//查找图书    根据书名
	int Find_Title_Book(Book* book, string Find_name);
	//查找图书    根据图书国际编号
	int Find_Id_Book(Book* book, string Find_id);
	//查找图书    根据作者
	void Find_Writer_Book(Book* book, string Find_Writer);
	//查找图书    根据出版社
	void Find_Press_Book(Book* book, string Find_id);

	//综合四种查找功能
	void Find_ALL_Func(Book* book);

	//析构函数
	~LibraryManager();
};