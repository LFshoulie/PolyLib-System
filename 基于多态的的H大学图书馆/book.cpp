#include "book.h"

//�޲ι��캯��     ��ʼ������
Book::Book()
{
	//�������ݳ�ʼ��Ϊ0���ַ��ͳ�ʼ��Ϊ�˿ո�
	//��Ϊȫ�ֱ���ʱȫ����ʼ��Ϊ��0��Ϊ�˱�֤��׳�ԣ��ڹ��캯���н��г�ʼ��
	this->m_Collect_Num = 0;
	this->m_Read_Sum = 0;
	this->m_Price = 0;
}
//�вι��캯��     ��������
Book::Book(string title_book, string id_book, string writer, string press, float price)
{
	this->m_Title_Book = title_book;
	this->m_Id_Book = id_book;
	this->m_Writer = writer;
	this->m_Press = press;
	this->m_Price = price;
}