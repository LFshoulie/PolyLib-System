#pragma once
#include <iostream>
using namespace std;
#include <string>

class Book
{
public:

	//�޲ι��캯��     ��ʼ������
	Book();
	//�вι��캯��     ��������
	Book(string title_book, string id_book, string writer, string press, float price);

	string m_Title_Book;//����
	string m_Id_Book;//ͼ����ʱ��
	string m_Writer;//����
	string m_Press;//������
	float m_Price;//�۸�
	int m_Collect_Num;//�ݲؼ�¼
	int m_Read_Sum;//���ļ�¼
};