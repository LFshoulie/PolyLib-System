#include "libraryManager.h"
#include "manager.h"

//无参构造函数
Manager::Manager()
{

}

//有参构造函数
Manager::Manager(string id, string code, int dId)
{
	this->m_Id = id;
	this->m_Code = code;
	this->m_DeptId = dId;
}

//显示个人信息
void Manager::showInfo()
{
	cout << "账号:  " << this->m_Id
		<< "\t密码:  " << this->m_Code
		<< "\t用户身份:  " << this->getDeptName() << endl;
}

//显示个人信息
void Manager::showInfo(Manager* manager, int val)
{
	cout << "账号:  " << manager[val].m_Id
		<< "\t密码:  " << manager[val].m_Code
		<< "\t用户身份:  " << manager[val].getDeptName() << endl;
	system("pause");
	system("cls");
}

//获取用户身份
string Manager::getDeptName()
{
	return string("管理员");
}

//调用管理员菜单
void Manager::Show_Manager_Menu()
{
	cout << "**********管理员操作系统***********" << endl;
	cout << "*********  [00].退出系统  *********" << endl;
	cout << "*********  [01].修改密码  *********" << endl;
	cout << "*********  [02].添加读者  *********" << endl;
	cout << "*********  [03].删除读者  *********" << endl;
	cout << "*********  [04].修改读者  *********" << endl;
	cout << "*********  [05].查找读者  *********" << endl;
	cout << "*********  [06].重置密码  *********" << endl;
	cout << "*********  [07].添加图书  *********" << endl;
	cout << "*********  [08].删除图书  *********" << endl;
	cout << "*********  [09].修改图书  *********" << endl;
	cout << "*********  [10].查找图书  *********" << endl;
	cout << "*********  [11].调取排行  *********" << endl;
	cout << "***********************************" << endl;
}

//用户登录时查找管理员
int Manager::Find_Manager(Manager* manager, string Find_id)
{
	if (manager[0].m_DeptId == 0)
	{
		cout << "读者库为空！！！请您注册" << endl;
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

	cout << "抱歉！！您输入的账号不存在" << endl;
	cout << "若要使用，请注册！！！！" << endl;
	system("pause");
	system("cls");
	return -1;
}

//修改密码
void Manager::Modf_Code(Manager* manager, int indef)
{
	string temp_code_old;
	string temp_code_new;
	while (1)
	{
		cout << "请输入原密码:  " << endl;
		cin >> temp_code_old;
		if (manager[indef].m_Code != temp_code_old)
		{
			cout << "原密码错误！！请重新输入" << endl;
		}
		else
		{
			cout << "请输入新密码:  " << endl;
			cin >> temp_code_new;
			manager[indef].m_Code = temp_code_new;
			break;
		}
	}
}

//修改图书
void Manager::Modr_Book(Book* book)
{
	int Modf_choice = 0;
	cout << "请输入修改图书信息" << endl;
	cout << "1,书名\n2,国际图书编号" << endl;
	cin >> Modf_choice;
	int Modf_val = 0;
	string Modf_Both;
	LibraryManager temp_LM;
	switch (Modf_choice)
	{
	case 1:
	{
		cout << "请输入书籍书名:  " << endl;
		cin >> Modf_Both;
		Modf_val = temp_LM.Find_Title_Book(book, Modf_Both);
	}
		break;
	case 2:
	{
		cout << "请输入书籍国际编号:  " << endl;
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
		cout << "请输入修改后的内容::" << endl;
		cout << "图书书名:\t";     cin >> book[Modf_val].m_Title_Book;
		cout << "图书国际编号:\t"; cin >> book[Modf_val].m_Id_Book;
		cout << "作者:\t";         cin >> book[Modf_val].m_Writer;
		cout << "出版社:\t";       cin >> book[Modf_val].m_Press;
		cout << "价格:\t";         cin >> book[Modf_val].m_Price;
		cout << "馆藏记录:\t";     cin >> book[Modf_val].m_Collect_Num;
		cout << "借阅记录:\t";     cin >> book[Modf_val].m_Read_Sum;

		//保存会文档
		temp_LM.Ofstream_Book(book);

		cout << "修改成功！！！！！" << endl;
		system("pause");
		system("cls");
	}
}

//删除图书
void Manager::Delete_Book(Book* book)
{
	int Delete_choice = 0;
	cout << "请输入修改图书信息" << endl;
	cout << "1,书名\n2,国际图书编号" << endl;
	cin >> Delete_choice;
	int Delete_val = 0;
	string Delete_Both;
	LibraryManager temp_LM;
	switch (Delete_choice)
	{
	case 1:
	{
		cout << "请输入书籍书名:  " << endl;
		cin >> Delete_Both;
		Delete_val = temp_LM.Find_Title_Book(book, Delete_Both);
	}
	break;
	case 2:
	{
		cout << "请输入书籍国际编号:  " << endl;
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

		//保存会文档
		temp_LM.Ofstream_Book(book);

		cout << "删除成功！！！！！" << endl;
		system("pause");
		system("cls");
	}
}

//添加图书
void Manager::Add_Book(Book* book)
{
	LibraryManager temp_LM;
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Collect_Num == 0)
		{
			cout << "请输入添加书本的信息::" << endl;
			cout << "图书书名:\t";     cin >> book[i].m_Title_Book;
			cout << "图书国际编号:\t"; cin >> book[i].m_Id_Book;
			cout << "作者:\t";         cin >> book[i].m_Writer;
			cout << "出版社:\t";       cin >> book[i].m_Press;
			cout << "价格:\t";         cin >> book[i].m_Price;
			book[i].m_Collect_Num = 10;
			book[i].m_Read_Sum = 0;
			break;
		}
	}
	//保存会文档
	temp_LM.Ofstream_Book(book);

	cout << "添加成功！！！" << endl;
	system("pause");
	system("cls");
}


//添加读者
void Manager::Add_Reader(Reader* reader)
{
	LibraryManager temp_LM;
	string temp_id;
	while (1)
	{
		bool bo_reader = true;
		cout << "输入账号:    " << endl;   cin >> temp_id;
		for (int i = 0; i < 10; i++)
		{
			if (reader[i].m_Id == temp_id)
			{
				bo_reader = false;
				cout << "该账号已存在，请重新输入！！！" << endl;
				break;
			}
		}
		if (bo_reader == true)
		{
			break;
		}
	}
	string temp_code;
	cout << "输入密码:   " << endl;    cin >> temp_code;
	for (int i = 0; i < 10; i++)
	{
		if (reader[i].m_DeptId == 0)
		{
			reader[i].m_Id = temp_id;
			reader[i].m_Code = temp_code;
			reader[i].m_DeptId = 2;

			//保存至读者文件
			temp_LM.Ofstream_Reader(reader);

			cout << "添加成功！！！" << endl;
			system("pause");
			system("cls");

			return;
		}
	}
	cout << "抱歉！读者已满！！" << endl;
	system("pause");
	return;
}

//删除读者
void Manager::Delete_Reader(Reader* reader)
{
	Reader temp_R;
	LibraryManager temp_LM;
	string Delete_id;
	cout << "请输入要删除的账号id:" << endl;
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

		//保存会文档
		temp_LM.Ofstream_Reader(reader);
		
		cout << "删除成功！！！！" << endl;
		system("pause");
		system("cls");
	}
}

//查找读者
void Manager::Find_Reader(Reader* reader)
{
	Reader temp_R;
	string Find_id;
	cout << "请输入要查找的账号id:" << endl;
	cin >> Find_id;

	int Find_val = temp_R.Find_Reader(reader, Find_id);

	if (Find_val == -1)
	{
		return;
	}
	else
	{
		cout << "账号:  " << reader[Find_val].m_Id
			<< "\t密码:  " << reader[Find_val].m_Code
			<< "\t阅读次数:  " << reader[Find_val].m_ReadBook_Sum
			<< "\t用户身份:  " << reader[Find_val].getDeptName()
			<< "\t借阅书籍书名:  " << reader[Find_val].m_Borrow_Title_Book
			<< "\t借阅书籍国际编号:  " << reader[Find_val].m_Borrow_Id_Book << endl;
		system("pause");
		system("cls");
	}
}

//修改读者
void Manager::Modf_Reader(Reader* reader)
{
	Reader temp_R;
	LibraryManager temp_LM;
	string Modf_id;
	cout << "请输入要修改的账号id:" << endl;
	cin >> Modf_id;

	int Modf_val = temp_R.Find_Reader(reader, Modf_id);

	if (Modf_val == -1)
	{
		return;
	}
	else
	{
		cout << "修改该用户的信息为:  " << endl;
		cout << "账号:  "; cin >> reader[Modf_val].m_Id;
		cout << "密码:  "; cin >> reader[Modf_val].m_Code;
		cout << "阅读次数:  "; cin >> reader[Modf_val].m_ReadBook_Sum;
		cout << "借阅书籍书名:  "; cin >> reader[Modf_val].m_Borrow_Title_Book;
		cout << "借阅书籍国际编号:  "; cin >> reader[Modf_val].m_Borrow_Id_Book;
		cout << endl;

		//保存会文档
		temp_LM.Ofstream_Reader(reader);

		cout << "修改成功！！！！" << endl;
		system("pause");
		system("cls");
	}
}

//重置密码
void Manager::Reset_Reader_Code(Reader* reader)
{
	Reader temp_R;
	LibraryManager temp_LM;
	string Reset_id;
	cout << "请输入要重置密码的账号id:" << endl;
	cin >> Reset_id;

	int Reset_val = temp_R.Find_Reader(reader, Reset_id);

	if (Reset_val == -1)
	{
		return;
	}
	else
	{
		
		reader[Reset_val].m_Code = "123456";

		//保存会文档
		temp_LM.Ofstream_Reader(reader);

		cout << "重置密码成功！！！！" << endl;
		cout << "密码重置为:  123456  " << endl;
		system("pause");
		system("cls");
	}
}