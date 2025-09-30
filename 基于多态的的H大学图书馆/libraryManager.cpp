#include "libraryManager.h"

//���캯��
LibraryManager::LibraryManager()
{

}

//չ�����ϵͳ�Ĳ˵�
void LibraryManager::ShowMenu()
{
	cout << "***********ͼ��ݹ���ϵͳ*********" << endl;
	cout << "*********  [0].�˳�ϵͳ  *********" << endl;
	cout << "*********  [1].  ��¼    *********" << endl;
	cout << "*********  [2].  ע��    *********" << endl;
	cout << "*********  [3].  ����    *********" << endl;
	cout << "**********************************" << endl;

}

//�˳�ϵͳ
void LibraryManager::Exit_LibraryManager()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);  //�������Ľ���ú�����ֱ���˳�����
}

//��ȡ���а�
void LibraryManager::Show_Ranking_List(Book* book, Reader* reader)
{
	cout << "**********************************" << endl;
	cout << "******  �Ķ�����ǰʮ��ͼ��  ******" << endl;
	cout << "**********************************" << endl;

	//��ȡ�Ķ�����ǰʮ��ͼ�飬���Ҵ�ӡ����Ϣ
	if (book[0].m_Collect_Num == 0)
	{
		cout << "��Ǹ������ͼ���Ϊ��" << endl;
		system("pause");
	}
	//�����Ķ���������
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (book[j].m_Read_Sum < book[j + 1].m_Read_Sum)
			{
				Book temp = book[j];
				book[j] = book[j + 1];
				book[j + 1] = temp;
			}
		}
	}

	//��ӡǰʮͼ��
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Collect_Num != 0)
		{
			Show_InFo(book, i);
		}
	}


	cout << "**********************************" << endl;
	cout << "******  �Ķ�����ǰʮ�Ķ���  ******" << endl;
	cout << "**********************************" << endl;

	//��ȡ�Ķ�����ǰʮ�Ķ���
	if (reader[0].m_DeptId == 0)
	{
		cout << "��Ǹ�����ö���Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	//���ݶ����Ķ���������
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (reader[j].m_ReadBook_Sum < reader[j + 1].m_ReadBook_Sum)
			{
				Reader temp = reader[j];
				reader[j] = reader[j + 1];
				reader[j + 1] = temp;
			}
		}
	}

	//��ӡǰʮ�Ķ���
	for (int i = 0; i < 10; i++)
	{
		if (reader[i].m_DeptId != 0)
		{
			cout << "�����˺�:  " << reader[i].m_Id
				<< "\t�Ķ�����:  " << reader[i].m_ReadBook_Sum << endl;
		}
	}

	system("pause");
	system("cls");
}

//ע���û���Ϣ   ����Ա
void LibraryManager::Register_Manager(Manager *manager)
{
	string temp_id;
	while (1)
	{
		bool bo_reader = true;
		cout << "�����˺�:    " << endl;   cin >> temp_id;
		for (int i = 0; i < 10; i++)
		{
			if (manager[i].m_Id == temp_id)
			{
				bo_reader = false;
				cout << "���˺��Ѵ��ڣ����������룡����" << endl;
				break;
			}
		}
		if (bo_reader == true)
		{
			break;
		}
	}

	string Ver_Code;
	int Ver_Code_num = 0;
	while (1)
	{
		cout << "�Ƿ��������Ա��֤��:  " << endl;
		cout << "1��������֤��\n0���˳�ע�� ����Ա" << endl;
		cin >> Ver_Code_num;
		if (Ver_Code_num == 1)
		{
			cout << "��������֤��" << endl;
			cin >> Ver_Code;
			if (Ver_Code == "295072")
			{
				cout << "��֤����ȷ" << endl;
				break;
			}
			else
				cout << "��֤�����" << endl;
			{
				continue;
			}
		}
		else
		{
			system("pause");
			system("cls");
			return;
		}
	}

	string temp_code;
	cout << "��������:   " << endl;    cin>> temp_code ;
	for (int i = 0; i < 10; i++)
	{
		if (manager[i].m_DeptId == 0)
		{
			manager[i].m_Id = temp_id;
			manager[i].m_Code = temp_code;
			manager[i].m_DeptId = 1;

			//����������Ա�ļ�
			Ofstream_Manager(manager);

			cout << "ע��ɹ�������" << endl;
			system("pause");
			system("cls");

			return;
		}
	}
	cout << "��Ǹ������Ա��������" << endl;
	system("pause");
	return;
}

//ע���û���Ϣ    ����
void LibraryManager::Register_Reader(Reader* reader)
{
	string temp_id;
	while (1)
	{
		bool bo_reader = true;
		cout << "�����˺�:    " << endl;   cin >> temp_id;
		for (int i = 0; i < 10; i++)
		{
			if (reader[i].m_Id == temp_id)
			{
				bo_reader = false;
				cout << "���˺��Ѵ��ڣ����������룡����" << endl;
				break;
			}
		}
		if (bo_reader == true)
		{
			break;
		}
	}
	string temp_code;
	cout << "��������:   " << endl;    cin >> temp_code;
	for (int i = 0; i < 10; i++)
	{
		if (reader[i].m_DeptId == 0)
		{
			reader[i].m_Id = temp_id;
			reader[i].m_Code = temp_code;
			reader[i].m_DeptId = 2;

			//�����������ļ�
			Ofstream_Reader(reader);

			cout << "ע��ɹ�������" << endl;
			system("pause");
			system("cls");

			return;
		}
	}
	cout << "��Ǹ��������������" << endl;
	system("pause");
	return;
}

//д�ļ�    �鼮
void LibraryManager::Ofstream_Book(Book* book)
{
	ofstream ofs;   //����������
	ofs.open("book.txt", ios::out | ios::trunc);    //�����ļ����򿪷�ʽ

	//�ж��ļ��Ƿ�򿪳ɹ�
	if (!ofs.is_open())
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Collect_Num != 0)
		{
			ofs << book[i].m_Title_Book << " "
				<< book[i].m_Id_Book << " "
				<< book[i].m_Writer << " "
				<< book[i].m_Press << " "
				<< book[i].m_Price << " "
				<< book[i].m_Collect_Num << " "
				<< book[i].m_Read_Sum << "\n";
		}
	}
	ofs.close();
}
//���ļ�    �鼮
void LibraryManager::Ifstream_Book(Book* book)
{
	ifstream ifs;
	ifs.open("book.txt", ios::in);

	//�ж��ļ��Ƿ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Collect_Num == 0)
		{
			ifs >> book[i].m_Title_Book
				>> book[i].m_Id_Book
				>> book[i].m_Writer
				>> book[i].m_Press
				>> book[i].m_Price
				>> book[i].m_Collect_Num
				>> book[i].m_Read_Sum;
		}
	}
	ifs.close();
}

//д�ļ�    ����Ա��Ϣ
void LibraryManager::Ofstream_Manager(Manager* manager)
{
	ofstream ofs;
	ofs.open("Manager.txt", ios::out | ios::trunc);

	//�ж��ļ��Ƿ��
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (manager[i].m_DeptId != 0)
		{
			ofs << manager[i].m_Id << " "
				<< manager[i].m_Code << " "
				<< manager[i].m_DeptId<<"\n";
		}
	}
	ofs.close();
}
//���ļ�    ����Ա��Ϣ
void LibraryManager::Ifstream_Manager(Manager* manager)
{
	ifstream ifs;
	ifs.open("Manager.txt", ios::in);

	//�ж��ļ��Ƿ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (manager[i].m_DeptId == 0)
		{
			ifs >> manager[i].m_Id
				>> manager[i].m_Code
				>> manager[i].m_DeptId;
		}
	}
	ifs.close();
}


//д�ļ�    ������Ϣ
void LibraryManager::Ofstream_Reader(Reader* reader)
{
	ofstream ofs;
	ofs.open("Reader.txt", ios::out | ios::trunc);

	//�ж��ļ��Ƿ��
	if (!ofs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (reader[i].m_DeptId != 0)
		{
			ofs << reader[i].m_Id << " "
				<< reader[i].m_Code << " "
				<< reader[i].m_DeptId << " "
				<< reader[i].m_ReadBook_Sum << " "
				<< reader[i].m_Borrow_Title_Book << " "
				<< reader[i].m_Borrow_Id_Book << "\n";
		}
	}
	ofs.close();
}
//���ļ�    ������Ϣ
void LibraryManager::Ifstream_Reader(Reader* reader)
{
	ifstream ifs;
	ifs.open("Reader.txt", ios::in);

	//�ж��ļ��Ƿ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (reader[i].m_DeptId == 0)
		{
			ifs >> reader[i].m_Id
				>> reader[i].m_Code
				>> reader[i].m_DeptId
				>> reader[i].m_ReadBook_Sum
				>> reader[i].m_Borrow_Title_Book
				>> reader[i].m_Borrow_Id_Book;
		}
	}
	ifs.close();
}

//��ӡ�鼮��Ϣ����
void LibraryManager::Show_InFo(Book* book, int indef)
{
	cout << "����:  " << book[indef].m_Title_Book
		<< "\t����ͼ����:  " << book[indef].m_Id_Book
		<< "\t����:  " << book[indef].m_Writer
		<< "\t������:  " << book[indef].m_Press
		<< "\t�۸�:  " << book[indef].m_Price
		<< "\t�ݲ�����:  " << book[indef].m_Collect_Num
		<< "\t��������:  " << book[indef].m_Read_Sum << endl;
}

//������������ͼ��    Ϊ��ʵ���ֵ�����
void LibraryManager::Sort_Title_Book(Book* book)
{
	for (int i = 0; i < 10 - 1; i++)
	{
		for (int j = 0; j < 10 - i - 1; j++)
		{
			if (book[j].m_Title_Book < book[j + 1].m_Title_Book && book[j].m_Collect_Num !=0 && book[j+1].m_Collect_Num !=0)
			{
				Book temp = book[j];
				book[j] = book[j + 1];
				book[j + 1] = temp;
			}
		}
	}
}

//����ͼ��    ��������
int LibraryManager::Find_Title_Book(Book* book,string Find_name)
{
	//���ͼ���û�飬ֱ���˳�
	if (book[0].m_Collect_Num == 0)
	{
		cout << "��Ǹ�� ͼ���Ϊ��" << endl;
		system("pause");
		system("cls");
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Title_Book == Find_name && book[i].m_Collect_Num != 0)
		{
			return i;
		}
	}

	cout << "��Ǹ�����޴���" << endl;
	system("pause");
	system("cls");
	return -1;
}
//����ͼ��    ����ͼ����ʱ��
int LibraryManager::Find_Id_Book(Book* book,string Find_id)
{
	//���ͼ���û�飬ֱ���˳�
	if (book[0].m_Collect_Num == 0)
	{
		cout << "��Ǹ�� ͼ���Ϊ��" << endl;
		system("pause");
		system("cls");
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Id_Book==Find_id && book[i].m_Collect_Num !=0)
		{
			return i;
		}
	}

	cout << "��Ǹ�����޴���" << endl;
	system("pause");
	system("cls");
	return -1;
}
//����ͼ��    ��������
void LibraryManager::Find_Writer_Book(Book* book,string Find_Writer)
{
	//���ͼ���û�飬ֱ���˳�
	if (book->m_Collect_Num == 0)
	{
		cout << "��Ǹ�� ͼ���Ϊ��" << endl;
		return;
	}

	//����������
	Sort_Title_Book(book);

	//��ӡ������ͬ���鼮
	bool bo = false;
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Writer == Find_Writer && book[i].m_Collect_Num!=0)
		{
			bo = true;
			Show_InFo(book, i);
		}
	}
	if (bo == false)
	{
		cout << "�޸����ߵ��鼮������" << endl;
		return;
	}
}
//����ͼ��    ���ݳ�����
void LibraryManager::Find_Press_Book(Book* book,string Find_id)
{
	//���ͼ���û�飬ֱ���˳�
	if (book->m_Collect_Num == 0)
	{
		cout << "��Ǹ�� ͼ���Ϊ��" << endl;
		return;
	}

	//����������
	Sort_Title_Book(book);

	//��ӡ��������ͬ���鼮
	bool bo = false;
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Press == Find_id && book[i].m_Collect_Num !=0 )
		{
			bo = true;
			Show_InFo(book, i);
		}
	}
	if (bo == false)
	{
		cout << "�޸ó�������鼮������" << endl;
		return;
	}
}

//�ۺ����ֲ��ҹ���
void LibraryManager::Find_ALL_Func(Book *book)
{
	int temp_choice = 0;
	cout << "1,��������\n2,����ͼ���Ų���\n3,���߲���\n4,���������" << endl;
	cout << "��������ҵķ�ʽ:  " << endl;
	cin >> temp_choice;
	switch (temp_choice)
	{
	case 1:  //��������
	{
		string temp_Find_Title_Book;
		cout << "������Ҫ���ҵ��鼮����" << endl;
		cin>> temp_Find_Title_Book;
		int val = LibraryManager::Find_Title_Book(book, temp_Find_Title_Book);
		if (val == -1)
		{
			return;
		}
		LibraryManager::Show_InFo(book, val);
	}
		break;
	case 2:   //����ͼ���Ų���
	{
		string temp_Find_Id_Book;
		cout << "������Ҫ�����鼮�Ĺ��ʱ��" << endl;
		cin >> temp_Find_Id_Book;
		int val = LibraryManager::Find_Id_Book(book, temp_Find_Id_Book);
		if (val == -1)
		{
			return;
		}
		LibraryManager::Show_InFo(book, val);
	}
		break;
	case 3:  //���߲���
	{
		string temp_Find_Writer;
		cout << "������Ҫ���ҵ�����" << endl;
		cin >> temp_Find_Writer;
		LibraryManager::Find_Writer_Book(book, temp_Find_Writer);
		system("pause");
		system("cls");
	}
		break;
	case 4:  //���������
	{
		string temp_Find_Press;
		cout << "������Ҫ���ҵĳ�����" << endl;
		cin >> temp_Find_Press;
		LibraryManager::Find_Press_Book(book, temp_Find_Press);
		system("pause");
		system("cls");
	}
		break;
	default:
		cout << "�������󣡣�����������" << endl;
		break;
	}
	system("pause");
	system("cls");
}

//��������
LibraryManager::~LibraryManager()
{

}