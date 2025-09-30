#include "reader.h"
#include "libraryManager.h"

//无参构造函数
Reader::Reader()
{
	this->m_Borrow_Title_Book = "Empty";
	this->m_Borrow_Id_Book = "Empty";
	this->m_ReadBook_Sum = 0;
}

//有参构造函数
Reader::Reader(string id, string code, int dId)
{
	this->m_Id = id;
	this->m_Code = code;
	this->m_DeptId = dId;
}

//显示个人信息
void Reader::showInfo()
{

}

//显示个人信息
void Reader::showInfo(Reader* reader, int val)
{
	cout << "账号:  " << reader[val].m_Id
		<< "\t密码:  " << reader[val].m_Id
		<< "\t阅读次数:  " << reader[val].m_ReadBook_Sum
		<< "\t用户身份:  " << reader[val].getDeptName()
		<< "\t借阅书籍书名:  " << reader[val].m_Borrow_Title_Book
		<< "\t借阅书籍国际编号:  " << reader[val].m_Borrow_Id_Book << endl;
	system("pause");
	system("cls");
}

//获取用户身份
string Reader::getDeptName()
{
	return string("读者");
}

//用户登录时查找读者
int  Reader::Find_Reader(Reader* reader, string Find_id)
{
	if (reader[0].m_DeptId == 0)
	{
		cout << "读者库为空！！！请您注册" << endl;
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

	cout << "抱歉！！您输入的账号不存在" << endl;
	cout << "若要使用，请注册！！！！" << endl;
	system("pause");
	system("cls");
	return -1;
}

//调用读者菜单
void Reader::Show_Reader_Menu()
{
	cout << "***********读者操作系统***********" << endl;
	cout << "*********  [0].退出系统  *********" << endl;
	cout << "*********  [1].获取信息  *********" << endl;
	cout << "*********  [2].修改密码  *********" << endl;
	cout << "*********  [3].查找图书  *********" << endl;
	cout << "*********  [4].浏览图书  *********" << endl;
	cout << "*********  [5].借阅图书  *********" << endl;
	cout << "*********  [6].归还图书  *********" << endl;
	cout << "*********  [7].调取排行  *********" << endl;
	cout << "**********************************" << endl;
}

//修改密码
void Reader::Modf_Code(Reader *reader,int indef)
{
	string temp_code_old;
	string temp_code_new;
	while (1)
	{
		cout << "请输入原密码:  " << endl;
		cin >> temp_code_old;
		if (reader[indef].m_Code != temp_code_old)
		{
			cout << "原密码错误！！请重新输入" << endl;
		}
		else
		{
			cout << "请输入新密码:  " << endl;
			cin >> temp_code_new;
			reader[indef].m_Code = temp_code_new;
			break;
		}
	}
}

//浏览图书   打印所有图书的信息
void Reader::Show_ALL_Book(Book* book)
{
	if (book[0].m_Collect_Num == 0)
	{
		cout << "抱歉！！书库为空！！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Collect_Num != 0)
		{
			cout << "书名： " << book[i].m_Title_Book << "   "
				<< "国际图书编号: " << book[i].m_Id_Book << "   "
				<< "作者：" << book[i].m_Writer << "   "
				<< "出版社: " << book[i].m_Press << "   "
				<< "价格:  " << book[i].m_Price << "元   "
				<< "馆藏记录: " << book[i].m_Collect_Num << "   "
				<< "借阅记录: " << book[i].m_Read_Sum << endl;
		}
	}
	system("pause");
	system("cls");
	return;
}

//借阅图书
void Reader::Borrow_Book(Book* book,Reader *reader, int val)
{
	LibraryManager temp_LM;
	int Borrow_choice = 0;
	cout << "请输入借阅图书的方式:  " << endl;
	cout << "1,根据书名\n2,根据国际图书编号" << endl;
	cin >> Borrow_choice;
	switch (Borrow_choice)
	{
	case 1:
	{
		string Borrow_Title_Book;
		cout << "请输入您要借阅图书的书名" << endl;
		cin >> Borrow_Title_Book;
		int Borrow_val = temp_LM.Find_Title_Book(book, Borrow_Title_Book);
		if (Borrow_val == -1)
		{
			return;
		}
		cout << "恭喜您！！借阅成功！！！" << endl;
		cout << "请在一个月之内进行归还！！" << endl;
		system("pause");
		system("cls");
		
		//书库中该书少一本
		book[Borrow_val].m_Collect_Num--;
		//书库中该书的阅读记录加一
		book[Borrow_val].m_Read_Sum++;
		//该读者的阅读次数加一
		reader[val].m_ReadBook_Sum++;
		//该读者的阅读书籍名称和编号进行改变
		reader[val].m_Borrow_Title_Book = book[Borrow_val].m_Title_Book;
		reader[val].m_Borrow_Id_Book = book[Borrow_val].m_Id_Book;
	}
		break;
	case 2:
		break;
	default:
		cout << "输入有误！！请重新输入" << endl;
		system("pause");
		system("cls");
		return;
		break;
	}
}

//归还图书
void Reader::Return_Book(Book* book, Reader* reader, int val)
{
	int Return_choice = 0;
	cout << "请选择归还的方式" << endl;
	cout << "1,根据书名\n2,根据国际图书编号" << endl;
	cin >> Return_choice;
	cout << "欢迎下次阅读！！" << endl;
	system("pause");
	system("cls");

	//书库中该书多一本
	for (int i = 0; i < 10; i++)
	{
		if (book[i].m_Title_Book == reader[val].m_Borrow_Title_Book)
		{
			book[i].m_Collect_Num++;
			break;
		}
	}
	//该读者的阅读书籍名称和编号进行初始化
	reader[val].m_Borrow_Title_Book = "Empty";
	reader[val].m_Borrow_Id_Book = "Empty";
}