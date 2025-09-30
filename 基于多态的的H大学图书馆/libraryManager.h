#pragma once  //��֤ͷ�ļ�ֻ����һ��
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
	
	//���캯��
	LibraryManager();

	//չ�����ϵͳ�Ĳ˵�
	void ShowMenu();

	//�˳�ϵͳ
	void Exit_LibraryManager();

	//��ȡ���а�
	void Show_Ranking_List(Book* book, Reader* reader);

	//ע���û���Ϣ    ����Ա
	void Register_Manager(Manager* manager);

	//ע���û���Ϣ    ����
	void Register_Reader(Reader* reader);

	//д�ļ�    �鼮
	void Ofstream_Book(Book* book);
	//���ļ�    �鼮
	void Ifstream_Book(Book* book);

	//д�ļ�    ����Ա��Ϣ
	void Ofstream_Manager(Manager* manager);
	//���ļ�    ����Ա��Ϣ
	void Ifstream_Manager(Manager* manager);

	//д�ļ�    ������Ϣ
	void Ofstream_Reader(Reader* reader);
	//���ļ�    ������Ϣ
	void Ifstream_Reader(Reader* reader);

	//��ӡ�鼮��Ϣ����
	void Show_InFo(Book* book, int indef);

	//������������ͼ��    Ϊ��ʵ���ֵ�����
	void Sort_Title_Book(Book* book);

	//����ͼ��    ��������
	int Find_Title_Book(Book* book, string Find_name);
	//����ͼ��    ����ͼ����ʱ��
	int Find_Id_Book(Book* book, string Find_id);
	//����ͼ��    ��������
	void Find_Writer_Book(Book* book, string Find_Writer);
	//����ͼ��    ���ݳ�����
	void Find_Press_Book(Book* book, string Find_id);

	//�ۺ����ֲ��ҹ���
	void Find_ALL_Func(Book* book);

	//��������
	~LibraryManager();
};