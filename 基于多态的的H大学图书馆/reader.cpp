#include "reader.h"
#include "libraryManager.h"

//�޲ι��캯��
Reader::Reader()
{
	this->m_Borrow_Title_Book = "Empty";
	this->m_Borrow_Id_Book = "Empty";
	this->m_ReadBook_Sum = 0;
}

//�вι��캯��
Reader::Reader(string id, string code, int dId)
{
	this->m_Id = id;
	this->m_Code = code;
	this->m_DeptId = dId;
}

//��ʾ������Ϣ
void Reader::showInfo()
{

}

//��ʾ������Ϣ
void Reader::showInfo(Reader* reader, int val)
{
	cout << "�˺�:  " << reader[val].m_Id
		<< "\t����:  " << reader[val].m_Id
		<< "\t�Ķ�����:  " << reader[val].m_ReadBook_Sum
		<< "\t�û����:  " << reader[val].getDeptName()
		<< "\t�����鼮����:  " << reader[val].m_Borrow_Title_Book
		<< "\t�����鼮���ʱ��:  " << reader[val].m_Borrow_Id_Book << endl;
	system("pause");
	system("cls");
}

//��ȡ�û����
string Reader::getDeptName()
{
	return string("����");
}

//�û���¼ʱ���Ҷ���
int  Reader::Find_Reader(Reader* reader, string Find_id)
{
	if (reader[0].m_DeptId == 0)
	{
		cout << "���߿�Ϊ�գ���������ע��" << endl;
		system("pause");
		system("cls");
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		if (reader[i].m_Id == Find_id)
		{
			return i;
		}
	}

	cout << "��Ǹ������������˺Ų�����" << endl;
	cout << "��Ҫʹ�ã���ע�ᣡ������" << endl;
	system("pause");
	system("cls");
	return -1;
}

//���ö��߲˵�
void Reader::Show_Reader_Menu()
{
	cout << "***********���߲���ϵͳ***********" << endl;
	cout << "*********  [0].�˳�ϵͳ  *********" << endl;
	cout << "*********  [1].��ȡ��Ϣ  *********" << endl;
	cout << "*********  [2].�޸�����  *********" << endl;
	cout << "*********  [3].����ͼ��  *********" << endl;
	cout << "*********  [4].���ͼ��  *********" << endl;
	cout << "*********  [5].����ͼ��  *********" << endl;
	cout << "*********  [6].�黹ͼ��  *********" << endl;
	cout << "*********  [7].��ȡ����  *********" << endl;
	cout << "**********************************" << endl;
}

//�޸�����
void Reader::Modf_Code(Reader *reader,int indef)
{
	string temp_code_old;
	string temp_code_new;
	while (1)
	{
		cout << "������ԭ����:  " << endl;
		cin >> temp_code_old;
		if (reader[indef].m_Code != temp_code_old)
		{
			cout << "ԭ������󣡣�����������" << endl;
		}
		else
		{
			cout << "������������:  " << endl;
			cin >> temp_code_new;
			reader[indef].m_Code = temp_code_new;
			break;
		}
	}
}

//���ͼ��   ��ӡ����ͼ�����Ϣ
void Reader::Show_ALL_Book(Book* book)
{
	if (book[0].m_Collect_Num == 0)
	{
		cout << "��Ǹ�������Ϊ�գ���" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Collect_Num != 0)
		{
			cout << "������ " << book[i].m_Title_Book << "   "
				<< "����ͼ����: " << book[i].m_Id_Book << "   "
				<< "���ߣ�" << book[i].m_Writer << "   "
				<< "������: " << book[i].m_Press << "   "
				<< "�۸�:  " << book[i].m_Price << "Ԫ   "
				<< "�ݲؼ�¼: " << book[i].m_Collect_Num << "   "
				<< "���ļ�¼: " << book[i].m_Read_Sum << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

//����ͼ��
void Reader::Borrow_Book(Book* book,Reader *reader, int val)
{
	LibraryManager temp_LM;
	int Borrow_choice = 0;
	cout << "���������ͼ��ķ�ʽ:  " << endl;
	cout << "1,��������\n2,���ݹ���ͼ����" << endl;
	cin >> Borrow_choice;
	switch (Borrow_choice)
	{
	case 1:
	{
		string Borrow_Title_Book;
		cout << "��������Ҫ����ͼ�������" << endl;
		cin >> Borrow_Title_Book;
		int Borrow_val = temp_LM.Find_Title_Book(book, Borrow_Title_Book);
		if (Borrow_val == -1)
		{
			return;
		}
		cout << "��ϲ���������ĳɹ�������" << endl;
		cout << "����һ����֮�ڽ��й黹����" << endl;
		system("pause");
		system("cls");
		
		//����и�����һ��
		book[Borrow_val].m_Collect_Num--;
		//����и�����Ķ���¼��һ
		book[Borrow_val].m_Read_Sum++;
		//�ö��ߵ��Ķ�������һ
		reader[val].m_ReadBook_Sum++;
		//�ö��ߵ��Ķ��鼮���ƺͱ�Ž��иı�
		reader[val].m_Borrow_Title_Book = book[Borrow_val].m_Title_Book;
		reader[val].m_Borrow_Id_Book = book[Borrow_val].m_Id_Book;
	}
		break;
	case 2:
		break;
	default:
		cout << "�������󣡣�����������" << endl;
		system("pause");
		system("cls");
		return;
		break;
	}
}

//�黹ͼ��
void Reader::Return_Book(Book* book, Reader* reader, int val)
{
	int Return_choice = 0;
	cout << "��ѡ��黹�ķ�ʽ" << endl;
	cout << "1,��������\n2,���ݹ���ͼ����" << endl;
	cin >> Return_choice;
	cout << "��ӭ�´��Ķ�����" << endl;
	system("pause");
	system("cls");

	//����и����һ��
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Title_Book == reader[val].m_Borrow_Title_Book)
		{
			book[i].m_Collect_Num++;
			break;
		}
	}
	//�ö��ߵ��Ķ��鼮���ƺͱ�Ž��г�ʼ��
	reader[val].m_Borrow_Title_Book = "Empty";
	reader[val].m_Borrow_Id_Book = "Empty";
}