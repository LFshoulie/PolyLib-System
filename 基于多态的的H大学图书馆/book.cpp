#include "book.h"

//无参构造函数     初始化数据
Book::Book()
{
	//整型数据初始化为0；字符型初始化为了空格
	//设为全局变量时全都初始化为了0，为了保证健壮性，在构造函数中进行初始化
	this->m_Collect_Num = 0;
	this->m_Read_Sum = 0;
	this->m_Price = 0;
}
//有参构造函数     更改数据
Book::Book(string title_book, string id_book, string writer, string press, float price)
{
	this->m_Title_Book = title_book;
	this->m_Id_Book = id_book;
	this->m_Writer = writer;
	this->m_Press = press;
	this->m_Price = price;
}