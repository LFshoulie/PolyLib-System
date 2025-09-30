#include <iostream>
using namespace std;
#include "libraryManager.h"
#include "user.h"
#include "manager.h"
#include "reader.h"
#include "book.h"
Manager manager[10];  //最多10名管理员   并利用全局函数将用户身份初始化为0
Reader reader[10];    //最多10名读者     并利用全局函数将用户身份初始化为0
Book book[10];        //最多进货10本书   并利用全局函数将书籍的储藏数量初始化为0


int main()
{
	//实例化图书馆管理系统
	LibraryManager LM;
	

	//将文件中的书，管理员，读者读入
	LM.Ifstream_Book(book);
	LM.Ifstream_Manager(manager);
	LM.Ifstream_Reader(reader);

	//提供用户选择按钮
	int choice1 = 0;
	while (1)
	{
		//调用菜单
		LM.ShowMenu();

		cout << "输入您要执行的功能: " << endl;
		cin >> choice1;
		switch (choice1)
		{
		case 0:  //退出系统
			LM.Exit_LibraryManager();
			break;
		case 1:  //登录
		{
			int choice3 = 0;
			cout << "请输入要登录账号的身份: " << endl;
			cout << "1,管理员\n2,读者" << endl;
			cin >> choice3;
			switch (choice3)
			{
			case 1:  //登录管理员账号
			{
				//实例化管理员类
				Manager M;
				string val_id;
				cout << "请输入账号:  " << endl;
				cin >> val_id;
				//查找账号是否存在
				int val = M.Find_Manager(manager, val_id);
				if (val == -1)
				{
					break;
				}

				string val_code;
				while (1)
				{
					cout << "请输入密码:  " << endl;
					cin >> val_code;

					if (val_code != manager[val].m_Code)
					{
						cout << "密码错误！！请重新输入" << endl;
						int Exit = 0;
						cout << "是否根据管理员验证码重置密码！！" << endl;
						cout << "1,Yes\n0,No" << endl;
						cin >> Exit;
						if (Exit == 1)
						{
							while (1)
							{
								string Unify_Code;
								cout << "请输入管理员通用验证码" << endl;
								cin >> Unify_Code;
								if (Unify_Code == "295072")
								{
									manager[val].m_Code = "295072";

									//保存回管理员文档
									LM.Ofstream_Manager(manager);
									cout << "修改成功！！请重新登录" << endl;
									exit(0);
								}
								else
								{
									cout << "验证码错误" << endl;

									cout << "是否退出系统" << endl;
									cout << "1,Yes\n0,No" << endl;
									cin >> Exit;
									if (Exit == 1)
									{
										exit(0);
									}
								}
							}

						}
						else
						{
							continue;
						}
					}
					cout << "欢迎使用管理员系统！！！" << endl;
					system("pause");
					system("cls");
					break;
				}

				//提供管理员选择按钮
				int choice5 = 0;

				while (1)
				{
					//提供管理员功能菜单
					M.Show_Manager_Menu();

					cout << "请输入要执行的功能:" << endl;
					cin >> choice5;

					switch (choice5)
					{
					case 0:  //退出系统
						LM.Exit_LibraryManager();
						break;
					case 1:  //修改密码
					{
						M.Modf_Code(manager, val);
						cout << "修改成功！！" << endl;
						LM.Ofstream_Manager(manager);   //保存回读者文档
						cout << "请重新登录！" << endl;
						system("pause");
						system("cls");
						exit(0);
					}
						break;
					case 2:  //添加读者
						M.Add_Reader(reader);
						break;
					case 3:  //删除读者
						M.Delete_Reader(reader);
						break;
					case 4:  //修改读者
						M.Modf_Reader(reader);
						break;
					case 5:  //查找读者
						M.Find_Reader(reader);
						break;
					case 6:  //重置密码
						M.Reset_Reader_Code(reader);
						break;
					case 7:  //添加图书
						M.Add_Book(book);
						break;
					case 8:  //删除图书
						M.Delete_Book(book);
						break;
					case 9:  //修改图书
						M.Modr_Book(book);
						break;
					case 10:  //查找图书
						LM.Find_ALL_Func(book);
						break;
					case 11:  //调取排行
						LM.Show_Ranking_List(book, reader);
						break;
					default:
						cout << "输入有误！！请重新输入" << endl;
						system("pause");
						system("cls");
						break;
					}
				}
			}
				break;
			case 2:  //登录读者账号
			{
				//实例化读者类
				Reader R;
				string val_id;
				cout << "请输入账号:  " << endl;
				cin >> val_id;
				//查找账号是否存在
				int val = R.Find_Reader(reader, val_id);
				if (val == -1)
				{
					break;
				}

				string val_code;
				while (1)
				{
					cout << "请输入密码:  " << endl;
					cin >> val_code;

					if (val_code != reader[val].m_Code)
					{
						cout << "密码错误！！请重新输入" << endl;
						int Exit = 0;
						cout << "是否退出让管理员重置密码！！"<<endl;
						cout << "1,Yes\n0,No" << endl;
						cin >> Exit;
						if (Exit == 0)
						{
							continue;
						}
						else
						{
							exit(0);
						}
					}
					cout << "欢迎使用读者系统！！！" << endl;
					system("pause");
					system("cls");
					break;
				}

				//提供读者选择按钮
				int choice4 = 0;

				while (1)
				{
					//提供读者选项菜单
					R.Show_Reader_Menu();

					cout << "请输入您要执行的功能: " << endl;
					cin >> choice4;

					switch (choice4)
					{
					case 0:  //退出系统
						LM.Exit_LibraryManager();
						break;
					case 1:  //获取信息
						R.showInfo(reader, val);
						break;
					case 2:  //修改密码
					{
						R.Modf_Code(reader, val);
						cout << "修改成功！！" << endl;
						LM.Ofstream_Reader(reader);   //保存回读者文档
						cout << "请重新登录！" << endl;
						system("pause");
						system("cls");
						exit(0);
					}
						break;
					case 3:  //查找图书
						LM.Find_ALL_Func(book);
						break;
					case 4:  //浏览图书
						R.Show_ALL_Book(book);
						break;
					case 5:  //借阅图书
						R.Borrow_Book(book, reader, val);
						LM.Ofstream_Reader(reader);  //保存回文档
						LM.Ofstream_Book(book);   //保存回文档
						break;
					case 6:  //归还图书
						R.Return_Book(book, reader, val);
						LM.Ofstream_Reader(reader);  //保存回文档
						LM.Ofstream_Book(book);   //保存回文档
						break;
					case 7:  //调用排行
						LM.Show_Ranking_List(book, reader);
						break;
					default:
						cout << "输入有误！！请重新输入" << endl;
						system("pause");
						system("cls");
						break;
					}
				}
			}
				break;
			default:
				cout << "输入有误！！请重新输入" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
			break;
		case 2:  //注册
		{
			int choice2 = 0;
			cout << "请输入要注册的身份: " << endl;
			cout << "1,管理员\n2,读者" << endl;
			cin >> choice2;
			switch (choice2)
			{
			case 1:  //注册管理员
				LM.Register_Manager(manager);
				system("cls");
				break;
			case 2:  //注册读者
				LM.Register_Reader(reader);
				system("cls");
				break;
			default:
				cout << "输入有误！！请重新输入" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
			break;
		case 3:  //调取排行榜
			LM.Show_Ranking_List(book, reader);
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}