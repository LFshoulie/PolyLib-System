#pragma once
#include <iostream>
using namespace std;
#include <string>

class Book
{
public:

	//无参构造函数     初始化数据
	Book();
	//有参构造函数     更改数据
	Book(string title_book, string id_book, string writer, string press, float price);

	string m_Title_Book;//书名
	string m_Id_Book;//图书国际编号
	string m_Writer;//作者
	string m_Press;//出版社
	float m_Price;//价格
	int m_Collect_Num;//馆藏记录
	int m_Read_Sum;//借阅记录
};