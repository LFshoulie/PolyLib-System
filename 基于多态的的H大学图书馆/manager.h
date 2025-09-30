#pragma once
#include <iostream>
using namespace std;
#include "user.h"
#include "book.h"
#include <string>
#include "reader.h"


//����Ա��
class Manager : public User
{
public:
	//�޲ι��캯��
	Manager();

	//�вι��캯��
	Manager(string id, string code,int dId);

	//��ʾ������Ϣ
	void showInfo();

	//��ʾ������Ϣ
	void showInfo(Manager* manager, int val);

	//���ù���Ա�˵�
	void Show_Manager_Menu();

	//�û���¼ʱ���ҹ���Ա
	int Find_Manager(Manager* manager, string Find_id);

	//�޸�����
	void Modf_Code(Manager* manager, int indef);

	//�޸�ͼ��
	void Modr_Book(Book* book);

	//ɾ��ͼ��
	void Delete_Book(Book* book);

	//���ͼ��
	void Add_Book(Book* book);

	//��Ӷ���
	void Add_Reader(Reader* reader);

	//ɾ������
	void Delete_Reader(Reader* reader);

	//���Ҷ���
	void Find_Reader(Reader* reader);

	//�޸Ķ���
	void Modf_Reader(Reader* reader);

	//��������
	void Reset_Reader_Code(Reader* reader);

	//��ȡ�û����
	string getDeptName();
};