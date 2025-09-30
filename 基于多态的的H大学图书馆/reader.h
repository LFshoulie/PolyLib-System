#pragma once
#include <iostream>
using namespace std;
#include "user.h"
#include <string>
#include "book.h"

//������
class Reader : public User
{
public:
	//�޲ι��캯��
	Reader();

	//�вι��캯��
	Reader(string id, string code, int dId);

	//��ʾ������Ϣ
	void showInfo();

	//��ʾ������Ϣ
	void showInfo(Reader *reader,int val);

	//��ȡ�û����
	string getDeptName();

	//�û���¼ʱ���Ҷ���
	int Find_Reader(Reader* reader, string Find_id);

	//���ö��߲˵�
	void Show_Reader_Menu();

	//�޸�����
	void Modf_Code(Reader* reader, int indef);

	//���ͼ��   ��ӡ����ͼ�����Ϣ
	void Show_ALL_Book(Book* book);

	//����ͼ��
	void Borrow_Book(Book *book,Reader *reader,int val);

	//�黹ͼ��
	void Return_Book(Book* book, Reader* reader, int val);

	string m_Borrow_Title_Book;  //���߽��������
	string m_Borrow_Id_Book;  //���߽���Ĺ����鼮���
	int m_ReadBook_Sum;  //ÿλ���߶���Ĵ���
};