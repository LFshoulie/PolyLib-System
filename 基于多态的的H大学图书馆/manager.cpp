#include "libraryManager.h"
#include "manager.h"

//�޲ι��캯��
Manager::Manager()
{

}

//�вι��캯��
Manager::Manager(string id, string code, int dId)
{
	this->m_Id = id;
	this->m_Code = code;
	this->m_DeptId = dId;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "�˺�:  " << this->m_Id
		<< "\t����:  " << this->m_Code
		<< "\t�û����:  " << this->getDeptName() << endl;
}

//��ʾ������Ϣ
void Manager::showInfo(Manager* manager, int val)
{
	cout << "�˺�:  " << manager[val].m_Id
		<< "\t����:  " << manager[val].m_Code
		<< "\t�û����:  " << manager[val].getDeptName() << endl;
	system("pause");
	system("cls");
}

//��ȡ�û����
string Manager::getDeptName()
{
	return string("����Ա");
}

//���ù���Ա�˵�
void Manager::Show_Manager_Menu()
{
	cout << "**********����Ա����ϵͳ***********" << endl;
	cout << "*********  [00].�˳�ϵͳ  *********" << endl;
	cout << "*********  [01].�޸�����  *********" << endl;
	cout << "*********  [02].��Ӷ���  *********" << endl;
	cout << "*********  [03].ɾ������  *********" << endl;
	cout << "*********  [04].�޸Ķ���  *********" << endl;
	cout << "*********  [05].���Ҷ���  *********" << endl;
	cout << "*********  [06].��������  *********" << endl;
	cout << "*********  [07].���ͼ��  *********" << endl;
	cout << "*********  [08].ɾ��ͼ��  *********" << endl;
	cout << "*********  [09].�޸�ͼ��  *********" << endl;
	cout << "*********  [10].����ͼ��  *********" << endl;
	cout << "*********  [11].��ȡ����  *********" << endl;
	cout << "***********************************" << endl;
}

//�û���¼ʱ���ҹ���Ա
int Manager::Find_Manager(Manager* manager, string Find_id)
{
	if (manager[0].m_DeptId == 0)
	{
		cout << "���߿�Ϊ�գ���������ע��" << endl;
		system("pause");
		system("cls");
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		if (manager[i].m_Id == Find_id)
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

//�޸�����
void Manager::Modf_Code(Manager* manager, int indef)
{
	string temp_code_old;
	string temp_code_new;
	while (1)
	{
		cout << "������ԭ����:  " << endl;
		cin >> temp_code_old;
		if (manager[indef].m_Code != temp_code_old)
		{
			cout << "ԭ������󣡣�����������" << endl;
		}
		else
		{
			cout << "������������:  " << endl;
			cin >> temp_code_new;
			manager[indef].m_Code = temp_code_new;
			break;
		}
	}
}

//�޸�ͼ��
void Manager::Modr_Book(Book* book)
{
	int Modf_choice = 0;
	cout << "�������޸�ͼ����Ϣ" << endl;
	cout << "1,����\n2,����ͼ����" << endl;
	cin >> Modf_choice;
	int Modf_val = 0;
	string Modf_Both;
	LibraryManager temp_LM;
	switch (Modf_choice)
	{
	case 1:
	{
		cout << "�������鼮����:  " << endl;
		cin >> Modf_Both;
		Modf_val = temp_LM.Find_Title_Book(book, Modf_Both);
	}
		break;
	case 2:
	{
		cout << "�������鼮���ʱ��:  " << endl;
		cin >> Modf_Both;
		Modf_val = temp_LM.Find_Id_Book(book, Modf_Both);
	}
		break;
	default:
		break;
	}

	if (Modf_val == -1)
	{
		return;
	}
	else
	{
		cout << "�������޸ĺ������::" << endl;
		cout << "ͼ������:\t";     cin >> book[Modf_val].m_Title_Book;
		cout << "ͼ����ʱ��:\t"; cin >> book[Modf_val].m_Id_Book;
		cout << "����:\t";         cin >> book[Modf_val].m_Writer;
		cout << "������:\t";       cin >> book[Modf_val].m_Press;
		cout << "�۸�:\t";         cin >> book[Modf_val].m_Price;
		cout << "�ݲؼ�¼:\t";     cin >> book[Modf_val].m_Collect_Num;
		cout << "���ļ�¼:\t";     cin >> book[Modf_val].m_Read_Sum;

		//������ĵ�
		temp_LM.Ofstream_Book(book);

		cout << "�޸ĳɹ�����������" << endl;
		system("pause");
		system("cls");
	}
}

//ɾ��ͼ��
void Manager::Delete_Book(Book* book)
{
	int Delete_choice = 0;
	cout << "�������޸�ͼ����Ϣ" << endl;
	cout << "1,����\n2,����ͼ����" << endl;
	cin >> Delete_choice;
	int Delete_val = 0;
	string Delete_Both;
	LibraryManager temp_LM;
	switch (Delete_choice)
	{
	case 1:
	{
		cout << "�������鼮����:  " << endl;
		cin >> Delete_Both;
		Delete_val = temp_LM.Find_Title_Book(book, Delete_Both);
	}
	break;
	case 2:
	{
		cout << "�������鼮���ʱ��:  " << endl;
		cin >> Delete_Both;
		Delete_val = temp_LM.Find_Id_Book(book, Delete_Both);
	}
	break;
	default:
		break;
	}

	if (Delete_val == -1)
	{
		return;
	}
	else
	{
		for (int i = Delete_val + 1; i < 10; i++)
		{
			book[i - 1] = book[i];
		}

		//������ĵ�
		temp_LM.Ofstream_Book(book);

		cout << "ɾ���ɹ�����������" << endl;
		system("pause");
		system("cls");
	}
}

//���ͼ��
void Manager::Add_Book(Book* book)
{
	LibraryManager temp_LM;
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Collect_Num == 0)
		{
			cout << "����������鱾����Ϣ::" << endl;
			cout << "ͼ������:\t";     cin >> book[i].m_Title_Book;
			cout << "ͼ����ʱ��:\t"; cin >> book[i].m_Id_Book;
			cout << "����:\t";         cin >> book[i].m_Writer;
			cout << "������:\t";       cin >> book[i].m_Press;
			cout << "�۸�:\t";         cin >> book[i].m_Price;
			book[i].m_Collect_Num = 10;
			book[i].m_Read_Sum = 0;
			break;
		}
	}
	//������ĵ�
	temp_LM.Ofstream_Book(book);

	cout << "��ӳɹ�������" << endl;
	system("pause");
	system("cls");
}


//��Ӷ���
void Manager::Add_Reader(Reader* reader)
{
	LibraryManager temp_LM;
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
			temp_LM.Ofstream_Reader(reader);

			cout << "��ӳɹ�������" << endl;
			system("pause");
			system("cls");

			return;
		}
	}
	cout << "��Ǹ��������������" << endl;
	system("pause");
	return;
}

//ɾ������
void Manager::Delete_Reader(Reader* reader)
{
	Reader temp_R;
	LibraryManager temp_LM;
	string Delete_id;
	cout << "������Ҫɾ�����˺�id:" << endl;
	cin >> Delete_id;

	int Delete_val = temp_R.Find_Reader(reader, Delete_id);

	if (Delete_val == -1)
	{
		return;
	}
	else
	{
		for (int i = Delete_val + 1; i < 10; i++)
		{
			reader[i - 1] = reader[i];
		}

		//������ĵ�
		temp_LM.Ofstream_Reader(reader);
		
		cout << "ɾ���ɹ���������" << endl;
		system("pause");
		system("cls");
	}
}

//���Ҷ���
void Manager::Find_Reader(Reader* reader)
{
	Reader temp_R;
	string Find_id;
	cout << "������Ҫ���ҵ��˺�id:" << endl;
	cin >> Find_id;

	int Find_val = temp_R.Find_Reader(reader, Find_id);

	if (Find_val == -1)
	{
		return;
	}
	else
	{
		cout << "�˺�:  " << reader[Find_val].m_Id
			<< "\t����:  " << reader[Find_val].m_Code
			<< "\t�Ķ�����:  " << reader[Find_val].m_ReadBook_Sum
			<< "\t�û����:  " << reader[Find_val].getDeptName()
			<< "\t�����鼮����:  " << reader[Find_val].m_Borrow_Title_Book
			<< "\t�����鼮���ʱ��:  " << reader[Find_val].m_Borrow_Id_Book << endl;
		system("pause");
		system("cls");
	}
}

//�޸Ķ���
void Manager::Modf_Reader(Reader* reader)
{
	Reader temp_R;
	LibraryManager temp_LM;
	string Modf_id;
	cout << "������Ҫ�޸ĵ��˺�id:" << endl;
	cin >> Modf_id;

	int Modf_val = temp_R.Find_Reader(reader, Modf_id);

	if (Modf_val == -1)
	{
		return;
	}
	else
	{
		cout << "�޸ĸ��û�����ϢΪ:  " << endl;
		cout << "�˺�:  "; cin >> reader[Modf_val].m_Id;
		cout << "����:  "; cin >> reader[Modf_val].m_Code;
		cout << "�Ķ�����:  "; cin >> reader[Modf_val].m_ReadBook_Sum;
		cout << "�����鼮����:  "; cin >> reader[Modf_val].m_Borrow_Title_Book;
		cout << "�����鼮���ʱ��:  "; cin >> reader[Modf_val].m_Borrow_Id_Book;
		cout << endl;

		//������ĵ�
		temp_LM.Ofstream_Reader(reader);

		cout << "�޸ĳɹ���������" << endl;
		system("pause");
		system("cls");
	}
}

//��������
void Manager::Reset_Reader_Code(Reader* reader)
{
	Reader temp_R;
	LibraryManager temp_LM;
	string Reset_id;
	cout << "������Ҫ����������˺�id:" << endl;
	cin >> Reset_id;

	int Reset_val = temp_R.Find_Reader(reader, Reset_id);

	if (Reset_val == -1)
	{
		return;
	}
	else
	{
		
		reader[Reset_val].m_Code = "123456";

		//������ĵ�
		temp_LM.Ofstream_Reader(reader);

		cout << "��������ɹ���������" << endl;
		cout << "��������Ϊ:  123456  " << endl;
		system("pause");
		system("cls");
	}
}