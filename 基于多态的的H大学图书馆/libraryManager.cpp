#include "libraryManager.h"

//构造函数
LibraryManager::LibraryManager()
{

}

//展会管理系统的菜单
void LibraryManager::ShowMenu()
{
	cout << "***********图书馆管理系统*********" << endl;
	cout << "*********  [0].退出系统  *********" << endl;
	cout << "*********  [1].  登录    *********" << endl;
	cout << "*********  [2].  注册    *********" << endl;
	cout << "*********  [3].  排名    *********" << endl;
	cout << "**********************************" << endl;

}

//退出系统
void LibraryManager::Exit_LibraryManager()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);  //无论在哪进入该函数，直接退出程序
}

//调取排行榜
void LibraryManager::Show_Ranking_List(Book* book, Reader* reader)
{
	cout << "**********************************" << endl;
	cout << "******  阅读次数前十的图书  ******" << endl;
	cout << "**********************************" << endl;

	//调取阅读次数前十的图书，并且打印其信息
	if (book[0].m_Collect_Num == 0)
	{
		cout << "抱歉！！该图书馆为空" << endl;
		system("pause");
	}
	//根据阅读次数排序
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

	//打印前十图书
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Collect_Num != 0)
		{
			Show_InFo(book, i);
		}
	}


	cout << "**********************************" << endl;
	cout << "******  阅读次数前十的读者  ******" << endl;
	cout << "**********************************" << endl;

	//调取阅读次数前十的读者
	if (reader[0].m_DeptId == 0)
	{
		cout << "抱歉！！该读者为空" << endl;
		system("pause");
		system("cls");
		return;
	}

	//根据读者阅读次数排序
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

	//打印前十的读者
	for (int i = 0; i < 10; i++)
	{
		if (reader[i].m_DeptId != 0)
		{
			cout << "读者账号:  " << reader[i].m_Id
				<< "\t阅读次数:  " << reader[i].m_ReadBook_Sum << endl;
		}
	}

	system("pause");
	system("cls");
}

//注册用户信息   管理员
void LibraryManager::Register_Manager(Manager *manager)
{
	string temp_id;
	while (1)
	{
		bool bo_reader = true;
		cout << "输入账号:    " << endl;   cin >> temp_id;
		for (int i = 0; i < 10; i++)
		{
			if (manager[i].m_Id == temp_id)
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

	string Ver_Code;
	int Ver_Code_num = 0;
	while (1)
	{
		cout << "是否输入管理员验证码:  " << endl;
		cout << "1，输入验证码\n0，退出注册 管理员" << endl;
		cin >> Ver_Code_num;
		if (Ver_Code_num == 1)
		{
			cout << "请输入验证码" << endl;
			cin >> Ver_Code;
			if (Ver_Code == "295072")
			{
				cout << "验证码正确" << endl;
				break;
			}
			else
				cout << "验证码错误" << endl;
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
	cout << "输入密码:   " << endl;    cin>> temp_code ;
	for (int i = 0; i < 10; i++)
	{
		if (manager[i].m_DeptId == 0)
		{
			manager[i].m_Id = temp_id;
			manager[i].m_Code = temp_code;
			manager[i].m_DeptId = 1;

			//保存至管理员文件
			Ofstream_Manager(manager);

			cout << "注册成功！！！" << endl;
			system("pause");
			system("cls");

			return;
		}
	}
	cout << "抱歉！管理员已满！！" << endl;
	system("pause");
	return;
}

//注册用户信息    读者
void LibraryManager::Register_Reader(Reader* reader)
{
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
			Ofstream_Reader(reader);

			cout << "注册成功！！！" << endl;
			system("pause");
			system("cls");

			return;
		}
	}
	cout << "抱歉！读者已满！！" << endl;
	system("pause");
	return;
}

//写文件    书籍
void LibraryManager::Ofstream_Book(Book* book)
{
	ofstream ofs;   //创建流对象
	ofs.open("book.txt", ios::out | ios::trunc);    //定义文件及打开方式

	//判断文件是否打开成功
	if (!ofs.is_open())
	{
		cout << "打开文件失败！" << endl;
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
//读文件    书籍
void LibraryManager::Ifstream_Book(Book* book)
{
	ifstream ifs;
	ifs.open("book.txt", ios::in);

	//判断文件是否打开
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
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

//写文件    管理员信息
void LibraryManager::Ofstream_Manager(Manager* manager)
{
	ofstream ofs;
	ofs.open("Manager.txt", ios::out | ios::trunc);

	//判断文件是否打开
	if (!ofs.is_open())
	{
		cout << "文件打开失败！" << endl;
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
//读文件    管理员信息
void LibraryManager::Ifstream_Manager(Manager* manager)
{
	ifstream ifs;
	ifs.open("Manager.txt", ios::in);

	//判断文件是否打开
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
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


//写文件    读者信息
void LibraryManager::Ofstream_Reader(Reader* reader)
{
	ofstream ofs;
	ofs.open("Reader.txt", ios::out | ios::trunc);

	//判断文件是否打开
	if (!ofs.is_open())
	{
		cout << "文件打开失败！" << endl;
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
//读文件    读者信息
void LibraryManager::Ifstream_Reader(Reader* reader)
{
	ifstream ifs;
	ifs.open("Reader.txt", ios::in);

	//判断文件是否打开
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
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

//打印书籍信息函数
void LibraryManager::Show_InFo(Book* book, int indef)
{
	cout << "书名:  " << book[indef].m_Title_Book
		<< "\t国际图书编号:  " << book[indef].m_Id_Book
		<< "\t作者:  " << book[indef].m_Writer
		<< "\t出版社:  " << book[indef].m_Press
		<< "\t价格:  " << book[indef].m_Price
		<< "\t馆藏数量:  " << book[indef].m_Collect_Num
		<< "\t借阅总数:  " << book[indef].m_Read_Sum << endl;
}

//根据书名排序图书    为了实现字典排序
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

//查找图书    根据书名
int LibraryManager::Find_Title_Book(Book* book,string Find_name)
{
	//如果图书馆没书，直接退出
	if (book[0].m_Collect_Num == 0)
	{
		cout << "抱歉！ 图书馆为空" << endl;
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

	cout << "抱歉！查无此书" << endl;
	system("pause");
	system("cls");
	return -1;
}
//查找图书    根据图书国际编号
int LibraryManager::Find_Id_Book(Book* book,string Find_id)
{
	//如果图书馆没书，直接退出
	if (book[0].m_Collect_Num == 0)
	{
		cout << "抱歉！ 图书馆为空" << endl;
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

	cout << "抱歉！查无此书" << endl;
	system("pause");
	system("cls");
	return -1;
}
//查找图书    根据作者
void LibraryManager::Find_Writer_Book(Book* book,string Find_Writer)
{
	//如果图书馆没书，直接退出
	if (book->m_Collect_Num == 0)
	{
		cout << "抱歉！ 图书馆为空" << endl;
		return;
	}

	//调用排序函数
	Sort_Title_Book(book);

	//打印作者相同的书籍
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
		cout << "无该作者的书籍！！！" << endl;
		return;
	}
}
//查找图书    根据出版社
void LibraryManager::Find_Press_Book(Book* book,string Find_id)
{
	//如果图书馆没书，直接退出
	if (book->m_Collect_Num == 0)
	{
		cout << "抱歉！ 图书馆为空" << endl;
		return;
	}

	//调用排序函数
	Sort_Title_Book(book);

	//打印出版社相同的书籍
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
		cout << "无该出版社的书籍！！！" << endl;
		return;
	}
}

//综合四种查找功能
void LibraryManager::Find_ALL_Func(Book *book)
{
	int temp_choice = 0;
	cout << "1,书名查找\n2,国际图书编号查找\n3,作者查找\n4,出版社查找" << endl;
	cout << "请输入查找的方式:  " << endl;
	cin >> temp_choice;
	switch (temp_choice)
	{
	case 1:  //书名查找
	{
		string temp_Find_Title_Book;
		cout << "请输入要查找的书籍书名" << endl;
		cin>> temp_Find_Title_Book;
		int val = LibraryManager::Find_Title_Book(book, temp_Find_Title_Book);
		if (val == -1)
		{
			return;
		}
		LibraryManager::Show_InFo(book, val);
	}
		break;
	case 2:   //国际图书编号查找
	{
		string temp_Find_Id_Book;
		cout << "请输入要查找书籍的国际编号" << endl;
		cin >> temp_Find_Id_Book;
		int val = LibraryManager::Find_Id_Book(book, temp_Find_Id_Book);
		if (val == -1)
		{
			return;
		}
		LibraryManager::Show_InFo(book, val);
	}
		break;
	case 3:  //作者查找
	{
		string temp_Find_Writer;
		cout << "请输入要查找的作者" << endl;
		cin >> temp_Find_Writer;
		LibraryManager::Find_Writer_Book(book, temp_Find_Writer);
		system("pause");
		system("cls");
	}
		break;
	case 4:  //出版社查找
	{
		string temp_Find_Press;
		cout << "请输入要查找的出版社" << endl;
		cin >> temp_Find_Press;
		LibraryManager::Find_Press_Book(book, temp_Find_Press);
		system("pause");
		system("cls");
	}
		break;
	default:
		cout << "输入有误！！请重新输入" << endl;
		break;
	}
	system("pause");
	system("cls");
}

//析构函数
LibraryManager::~LibraryManager()
{

}