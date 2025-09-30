#include <iostream>
using namespace std;
#include "libraryManager.h"
#include "user.h"
#include "manager.h"
#include "reader.h"
#include "book.h"
Manager manager[10];  //���10������Ա   ������ȫ�ֺ������û���ݳ�ʼ��Ϊ0
Reader reader[10];    //���10������     ������ȫ�ֺ������û���ݳ�ʼ��Ϊ0
Book book[10];        //������10����   ������ȫ�ֺ������鼮�Ĵ���������ʼ��Ϊ0


int main()
{
	//ʵ����ͼ��ݹ���ϵͳ
	LibraryManager LM;
	

	//���ļ��е��飬����Ա�����߶���
	LM.Ifstream_Book(book);
	LM.Ifstream_Manager(manager);
	LM.Ifstream_Reader(reader);

	//�ṩ�û�ѡ��ť
	int choice1 = 0;
	while (1)
	{
		//���ò˵�
		LM.ShowMenu();

		cout << "������Ҫִ�еĹ���: " << endl;
		cin >> choice1;
		switch (choice1)
		{
		case 0:  //�˳�ϵͳ
			LM.Exit_LibraryManager();
			break;
		case 1:  //��¼
		{
			int choice3 = 0;
			cout << "������Ҫ��¼�˺ŵ����: " << endl;
			cout << "1,����Ա\n2,����" << endl;
			cin >> choice3;
			switch (choice3)
			{
			case 1:  //��¼����Ա�˺�
			{
				//ʵ��������Ա��
				Manager M;
				string val_id;
				cout << "�������˺�:  " << endl;
				cin >> val_id;
				//�����˺��Ƿ����
				int val = M.Find_Manager(manager, val_id);
				if (val == -1)
				{
					break;
				}

				string val_code;
				while (1)
				{
					cout << "����������:  " << endl;
					cin >> val_code;

					if (val_code != manager[val].m_Code)
					{
						cout << "������󣡣�����������" << endl;
						int Exit = 0;
						cout << "�Ƿ���ݹ���Ա��֤���������룡��" << endl;
						cout << "1,Yes\n0,No" << endl;
						cin >> Exit;
						if (Exit == 1)
						{
							while (1)
							{
								string Unify_Code;
								cout << "���������Աͨ����֤��" << endl;
								cin >> Unify_Code;
								if (Unify_Code == "295072")
								{
									manager[val].m_Code = "295072";

									//����ع���Ա�ĵ�
									LM.Ofstream_Manager(manager);
									cout << "�޸ĳɹ����������µ�¼" << endl;
									exit(0);
								}
								else
								{
									cout << "��֤�����" << endl;

									cout << "�Ƿ��˳�ϵͳ" << endl;
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
					cout << "��ӭʹ�ù���Աϵͳ������" << endl;
					system("pause");
					system("cls");
					break;
				}

				//�ṩ����Աѡ��ť
				int choice5 = 0;

				while (1)
				{
					//�ṩ����Ա���ܲ˵�
					M.Show_Manager_Menu();

					cout << "������Ҫִ�еĹ���:" << endl;
					cin >> choice5;

					switch (choice5)
					{
					case 0:  //�˳�ϵͳ
						LM.Exit_LibraryManager();
						break;
					case 1:  //�޸�����
					{
						M.Modf_Code(manager, val);
						cout << "�޸ĳɹ�����" << endl;
						LM.Ofstream_Manager(manager);   //����ض����ĵ�
						cout << "�����µ�¼��" << endl;
						system("pause");
						system("cls");
						exit(0);
					}
						break;
					case 2:  //��Ӷ���
						M.Add_Reader(reader);
						break;
					case 3:  //ɾ������
						M.Delete_Reader(reader);
						break;
					case 4:  //�޸Ķ���
						M.Modf_Reader(reader);
						break;
					case 5:  //���Ҷ���
						M.Find_Reader(reader);
						break;
					case 6:  //��������
						M.Reset_Reader_Code(reader);
						break;
					case 7:  //���ͼ��
						M.Add_Book(book);
						break;
					case 8:  //ɾ��ͼ��
						M.Delete_Book(book);
						break;
					case 9:  //�޸�ͼ��
						M.Modr_Book(book);
						break;
					case 10:  //����ͼ��
						LM.Find_ALL_Func(book);
						break;
					case 11:  //��ȡ����
						LM.Show_Ranking_List(book, reader);
						break;
					default:
						cout << "�������󣡣�����������" << endl;
						system("pause");
						system("cls");
						break;
					}
				}
			}
				break;
			case 2:  //��¼�����˺�
			{
				//ʵ����������
				Reader R;
				string val_id;
				cout << "�������˺�:  " << endl;
				cin >> val_id;
				//�����˺��Ƿ����
				int val = R.Find_Reader(reader, val_id);
				if (val == -1)
				{
					break;
				}

				string val_code;
				while (1)
				{
					cout << "����������:  " << endl;
					cin >> val_code;

					if (val_code != reader[val].m_Code)
					{
						cout << "������󣡣�����������" << endl;
						int Exit = 0;
						cout << "�Ƿ��˳��ù���Ա�������룡��"<<endl;
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
					cout << "��ӭʹ�ö���ϵͳ������" << endl;
					system("pause");
					system("cls");
					break;
				}

				//�ṩ����ѡ��ť
				int choice4 = 0;

				while (1)
				{
					//�ṩ����ѡ��˵�
					R.Show_Reader_Menu();

					cout << "��������Ҫִ�еĹ���: " << endl;
					cin >> choice4;

					switch (choice4)
					{
					case 0:  //�˳�ϵͳ
						LM.Exit_LibraryManager();
						break;
					case 1:  //��ȡ��Ϣ
						R.showInfo(reader, val);
						break;
					case 2:  //�޸�����
					{
						R.Modf_Code(reader, val);
						cout << "�޸ĳɹ�����" << endl;
						LM.Ofstream_Reader(reader);   //����ض����ĵ�
						cout << "�����µ�¼��" << endl;
						system("pause");
						system("cls");
						exit(0);
					}
						break;
					case 3:  //����ͼ��
						LM.Find_ALL_Func(book);
						break;
					case 4:  //���ͼ��
						R.Show_ALL_Book(book);
						break;
					case 5:  //����ͼ��
						R.Borrow_Book(book, reader, val);
						LM.Ofstream_Reader(reader);  //������ĵ�
						LM.Ofstream_Book(book);   //������ĵ�
						break;
					case 6:  //�黹ͼ��
						R.Return_Book(book, reader, val);
						LM.Ofstream_Reader(reader);  //������ĵ�
						LM.Ofstream_Book(book);   //������ĵ�
						break;
					case 7:  //��������
						LM.Show_Ranking_List(book, reader);
						break;
					default:
						cout << "�������󣡣�����������" << endl;
						system("pause");
						system("cls");
						break;
					}
				}
			}
				break;
			default:
				cout << "�������󣡣�����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
			break;
		case 2:  //ע��
		{
			int choice2 = 0;
			cout << "������Ҫע������: " << endl;
			cout << "1,����Ա\n2,����" << endl;
			cin >> choice2;
			switch (choice2)
			{
			case 1:  //ע�����Ա
				LM.Register_Manager(manager);
				system("cls");
				break;
			case 2:  //ע�����
				LM.Register_Reader(reader);
				system("cls");
				break;
			default:
				cout << "�������󣡣�����������" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
			break;
		case 3:  //��ȡ���а�
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