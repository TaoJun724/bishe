#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <WinSock.h>  //һ��Ҫ�������������winsock2.h
#include <mysql.h>//����mysqlͷ�ļ�(һ�ַ�ʽ����vcĿ¼�������ã�һ�����ļ��п�������Ŀ¼��Ȼ����������)
#include <Windows.h>
#include<iostream>
#include<string.h>
using namespace std;

//�������������Ҳ�����ڹ���--������������
#pragma comment(lib,"wsock32.lib")
#pragma comment(lib,"libmysql.lib")
MYSQL mysql; //mysql����
MYSQL_FIELD *fd;  //�ֶ�������
char field[32][32];  //���ֶ�����ά����
MYSQL_RES *res; //����ṹ�������е�һ����ѯ�����
MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
char query[150]; //��ѯ���



class CMysqlOperatoe
{
public:
	//�������ݿ�
	bool ConnectDatabase()
	{
		//��ʼ��mysql
		mysql_init(&mysql);  //����mysql�����ݿ�
		//����false������ʧ�ܣ�����true�����ӳɹ�
		if (!(mysql_real_connect(&mysql, "localhost", "root", "17382572860", "parkinglot", 3306, NULL, 0)))
			//�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ
		{
			//printf("Error connecting to database:%s\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			//printf("Connected...\n");
			return true;
		}
	}

	//�ͷ���Դ
	void FreeConnect()
	{
		//�ͷ���Դ
		mysql_free_result(res);
		mysql_close(&mysql);
	}

	/***************************���ݿ����***********************************/
	//��ѯ����
	bool QueryDatabase1()
	{
		sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); //ִ�в�ѯ��䣬�����ǲ�ѯ���У�user�Ǳ��������ü����ţ���strcpyҲ����
		mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������
		//����0 ��ѯ�ɹ�������1��ѯʧ��
		if (mysql_query(&mysql, query))        //ִ��SQL���
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf("query success\n");
		}
		//��ȡ�����
		if (!(res = mysql_store_result(&mysql)))    //���sql�������󷵻صĽ����
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}
		//��ӡ��������
		printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
		//��ȡ�ֶε���Ϣ
		char *str_field[32];  //����һ���ַ�������洢�ֶ���Ϣ
		for (int i = 0; i<3; i++)   //����֪�ֶ�����������»�ȡ�ֶ���
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i<3; i++)   //��ӡ�ֶ�
			printf("%10s\t", str_field[i]);
		printf("\n");
		//��ӡ��ȡ������
		while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
		{
			printf("%10s\t%10s\t%10s\t\n", column[0], column[1], column[2]);  //column��������
		}
		return true;

	}

	bool QueryDatabase2()
	{
		sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); //ִ�в�ѯ��䣬�����ǲ�ѯ���У�user�Ǳ��������ü����ţ���strcpyҲ����
		mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������
		//����0 ��ѯ�ɹ�������1��ѯʧ��
		if (mysql_query(&mysql, query))        //ִ��SQL���
		{
		//	printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
		//	printf("query success\n");
		}
		//��ȡ�����
		if (!(res = mysql_store_result(&mysql)))    //���sql�������󷵻صĽ����
		{
			printf("Couldn't get result from %s\n", mysql_error(&mysql));
			return false;
		}
		//��ӡ��������
		printf("number of dataline returned: %d\n", mysql_affected_rows(&mysql));
		//��ȡ�ֶε���Ϣ
		char *str_field[32];  //����һ���ַ�������洢�ֶ���Ϣ
		for (int i = 0; i<3; i++)   //����֪�ֶ�����������»�ȡ�ֶ���
		{
			str_field[i] = mysql_fetch_field(res)->name;
		}
		for (int i = 0; i<3; i++)   //��ӡ�ֶ�
			printf("%10s\t", str_field[i]);
		printf("\n");
		//��ӡ��ȡ������
		while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
		{
			printf("%10s\t%10s\t%10s\t\n", column[0], column[1], column[2]);  //column��������
		}
		return true;
	}


	//�޸�����
	bool ModifyData(char* sql)
	{
		sprintf(query, sql);
		if (mysql_query(&mysql, query))        //ִ��SQL���
		{
			printf("Query failed (%s)\n", mysql_error(&mysql));
			return false;
		}
		else
		{
			printf("ModifyData success\n");
			return true;
		}
	}

	//ɾ������
	bool DeleteData(const char * sql)
	{
		char SQl[1024];
		sprintf_s(SQl, sql);
		if (mysql_query(&mysql, sql) != 0)
		{
			cerr << "ִ��sql���ʧ�ܣ�������ϢΪ�� " << mysql_error(&mysql) << endl;
			return false;
		}
		return true;
	}


	//��������
	bool InsertDate(const char * sql)
	{
		mysql_query(&mysql, "set names gbk");
		if (mysql_query(&mysql, sql))
		{
			// �����log������ֱ����ʾ������̨
			cerr << "ִ��sql���ʧ�ܣ�������ϢΪ�� " << mysql_error(&mysql) << endl;
			return false;
		}
		else
		{
			cout << "ִ��sql���ɹ���" << endl;
		}

		return true;
	}


};


//���ݿ��������
//int main()
//{
//	CMysqlOperatoe m;
//	mysql_query(&mysql, "set names gbk");
//	m.ConnectDatabase();
//	char* SQL = "Insert into userInfo(licensePlate, userName, passwd) values('��A42244', '˼˼', '123456');";
//	m.InsertDate(SQL);
//	m.QueryDatabase1();
//	//SQL = "Update userInfo set userName = '�Ŵ���' where userName = '����'";
//	//m.ModifyData(SQL);
//	//m.QueryDatabase1();
//
//	//char* SQL = "delete from userInfo where delete_licensePlate = '��B44444'";
//  /*  const 	char* SQL = "delete from userInfo where userName = 'aa'";
//	m.DeleteData(SQL);
//	m.QueryDatabase1();*/
//	m.FreeConnect();
//	system("pause");
//
//	return 0;
//
//}