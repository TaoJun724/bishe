#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARINGS
#include<stdio.h>
#include<winsock2.h>
#include<WS2tcpip.h>
#include<iostream>
#include <string.h>
#include"Comm.hpp"
#include"parkingMember.hpp"
#include"parkingOperator.hpp"
#include"CMysqlOperator.hpp"
#include "CMysqlOperator.hpp"
using namespace std;
#pragma comment(lib,"ws2_32.lib")
#define MaxClient 10
#define MaxBufSize 1024
const int PORT = 8000;
Manage m;
map<string, string> plsql;
CMysqlOperatoe sql;


//�����߳�
DWORD WINAPI ServerThread(LPVOID lpParameter){
	bool flag;
	bool flag1;
	bool flag2;
	bool flag3;
	string licensestr;
//	m.initParking();
	mysql_query(&mysql, "set names gbk");
	sql.ConnectDatabase();
	sprintf(query, "SELECT licensePlate, userName, passwd from userInfo"); //ִ�в�ѯ��䣬�����ǲ�ѯ���У�user�Ǳ��������ü����ţ���strcpyҲ����
	mysql_query(&mysql, "set names gbk"); //���ñ����ʽ��SET NAMES GBKҲ�У�������cmd����������
	//����0 ��ѯ�ɹ�������1��ѯʧ��
	mysql_query(&mysql, query);      //ִ��SQL���
	//��ȡ�����
	if (!(res = mysql_store_result(&mysql)))    //���sql�������󷵻صĽ����
	{
		//	printf("Couldn't get result from %s\n", mysql_error(&mysql));
		//	return false;
	}
	//��ȡ�ֶε���Ϣ
	char *str_field[32];  //����һ���ַ�������洢�ֶ���Ϣ
	for (int i = 0; i<3; i++)   //����֪�ֶ�����������»�ȡ�ֶ���
	{
		str_field[i] = mysql_fetch_field(res)->name;
	}
	//��ӡ��ȡ������
	while (column = mysql_fetch_row(res))   //����֪�ֶ���������£���ȡ����ӡ��һ��
	{
		//printf("%10s\t%10s\t%10s\t\n", column[0], column[1], column[2]);  //column��������
		plsql.insert(make_pair(column[0], column[2]));
	}

	SOCKET *ClientSocket = (SOCKET*)lpParameter;
	int receByt = 0;
	char revData[MaxBufSize];
//	char sendData[MaxBufSize];
	while (1){
		receByt = recv(*ClientSocket, revData, sizeof(revData), 0);
		if (receByt>0){
			cout << "���յ�����Ϣ�ǣ�" << revData << "            ���Կͻ���:" << *ClientSocket << endl;
		}
		else
		{
			cout << "������Ϣ������" << endl;
			break;
		}

		//�¼�������		
		string str(revData);
		string str1;
		str1 = str.substr(0, 20);
		const char* str2;
		str2 = str1.c_str();

		string str6;
		str6 = str.substr(0, 13);
		const char* str7;
		str7 = str6.c_str();
		//�������ݸ��ͻ���
		char sendData[1024];



		/************����й���Ա����ѡ��***************\n
		******1.��ѯ���ݿ�**********2.ɾ�����ݿ�******\n
		******3.��ѯ��λ״̬********4.��ѯ���״̬****\n
		******5.��ѯС��״̬********6.չʾͣ����******\n
		     ********6.�˳���¼******\n\n*/
		if (strcmp(revData, "����Ա") == 0)
		{
			flag2 = true;
			send(*ClientSocket, "���������Ա����\n", sizeof(sendData), 0);
		}
		else if (flag2 == true)
		{
			if (strcmp(revData, "admin") == 0)
			{
				flag2 = false;
				send(*ClientSocket, "����Ա��¼�ɹ�\n\n************����й���Ա����ѡ��***************\n ******1.��ѯ���ݿ�**********2.ɾ�����ݿ�******\n******3.��ѯ��λ״̬********4.��ѯ���״̬****\n******5.��ѯС��״̬********6.չʾͣ����******\n        ********6.�˳���¼******\n\n", sizeof(sendData), 0);
			}
			else{
				send(*ClientSocket, "��������������������Ա����\n", sizeof(sendData), 0);
			}

		}
		else if ((strcmp(revData, "��ѯ���ݿ�") == 0))
		{
			sql.QueryDatabase1();
			send(*ClientSocket, "\n���ݿ���չʾ\n\n************����й���Ա����ѡ��***************\n ******1.��ѯ���ݿ�**********2.ɾ�����ݿ�******\n******3.��ѯ��λ״̬********4.��ѯ���״̬****\n******5.��ѯС��״̬********6.չʾͣ����******\n        ********6.�˳���¼******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "��ѯС��״̬") == 0))
		{
			int noWork = m.findAgvCarStatus();
			if (noWork < AgvCarNum){
				//����С���������� //�����
			}
			send(*ClientSocket, "\nС��״̬��չʾ\n\n************����й���Ա����ѡ��***************\n ******1.��ѯ���ݿ�**********2.ɾ�����ݿ�******\n******3.��ѯ��λ״̬********4.��ѯ���״̬****\n******5.��ѯС��״̬********6.չʾͣ����******\n        ********6.�˳���¼******\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "ɾ�����ݿ�") == 0)
		{
			flag3 = true;
			send(*ClientSocket, "������ɾ���ĳ��ƺ�\n", sizeof(sendData), 0);
		}
		else if (flag3 == true)
		{
			string str4("delete from userInfo where licensePlate = '");
			str4 += str;
			string str5("'");
			str4 += str5;
			const char* SQL = str4.c_str();
			sql.DeleteData(SQL);
			sql.QueryDatabase1();
			flag3 = false;
			send(*ClientSocket, "\n���ݿ�ɾ���������\n\n************����й���Ա����ѡ��***************\n ******1.��ѯ���ݿ�**********2.ɾ�����ݿ�******\n******3.��ѯ��λ״̬********4.��ѯ���״̬****\n******5.��ѯС��״̬********6.չʾͣ����******\n        ********6.�˳���¼******\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "�û�") == 0)
		{
			send(*ClientSocket, "\n**************************************************\n**********1.�û�ע��**********2.�û���¼**********\n**************************************************\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "�û���¼") == 0)
		{
			flag = true;
			send(*ClientSocket, "��������ĳ��ƺ�\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "�û�ע��") == 0)
		{
			flag1 = true;
			send(*ClientSocket, "��������ĳ��ƺţ���������¼����\n", sizeof(sendData), 0);
		}
		else if (flag1 == true)
		{
			char *temp;
			char *output = revData;
			string licenseplate;
			string name;
			string passed;
			int index = 1;
			while ((temp = strchr(output, ',')) != NULL) {
				*temp = '\0';
				if (index == 1){
					licenseplate = output;
					index++;
				}
				else if (index == 2){
					name = output;
				}
				output = temp + 1;
			}
			passed = output;
			plsql.insert(make_pair(licenseplate, passed));
			string SQL("Insert into userInfo(licensePlate, userName, passwd) values('");
			SQL += licenseplate;
			string fuhao("','");
			string fuhao1("');");
			SQL += fuhao;
			SQL += name;
			SQL += fuhao;
			SQL += passed;
			SQL += fuhao1;
			const char* sq = SQL.c_str();
			sql.InsertDate(sq);
			flag1 = false;
			send(*ClientSocket, "ע��ɹ�\n\n**************************************************\n**********1.�û�ע��**********2.�û���¼**********\n**************************************************\n", sizeof(sendData), 0);
		}
		else if (licensestr.size() == 0 && flag == true)
		{
			licensestr += str;
			send(*ClientSocket, "�������������\n", sizeof(sendData), 0);
		}
		else if (flag == true && licensestr.size() != 0)
		{
			string password = plsql[licensestr];
			const char *licenseindex = password.c_str();
			if (strcmp(licenseindex, revData) == 0)
			{
				flag = false;
				licensestr.clear();
				send(*ClientSocket, "�û���½�ɹ�\n\*******������û�����ѡ��*********\n******1.ͣ��**********2.ȡ��******\n      ******3.�˳���¼********\n\n", sizeof(sendData), 0);
			}
			else{
				//flag = false;
				licensestr.clear();
				send(*ClientSocket, "���ƻ�������������������복�ƺ�\n", sizeof(sendData), 0);
			}

		}
		else if ((strcmp(revData, "��ѯ��λ״̬") == 0))
		{
			m.findParkingSpaceStatus();
			send(*ClientSocket, "\n��λ״̬��չʾ\n\n************����й���Ա����ѡ��***************\n ******1.��ѯ���ݿ�**********2.ɾ�����ݿ�******\n******3.��ѯ��λ״̬********4.��ѯ���״̬****\n******5.��ѯС��״̬********6.չʾͣ����******\n        ********6.�˳���¼******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "��ѯ���״̬") == 0))
		{
			m.findRoadStatus();
			send(*ClientSocket, "\n���״̬��չʾ\n\n************����й���Ա����ѡ��***************\n ******1.��ѯ���ݿ�**********2.ɾ�����ݿ�******\n******3.��ѯ��λ״̬********4.��ѯ���״̬****\n******5.��ѯС��״̬********6.չʾͣ����******\n        ********6.�˳���¼******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "չʾͣ����") == 0))
		{
			m.show();
			send(*ClientSocket, "ͣ������չʾ\n\n************����й���Ա����ѡ��***************\n ******1.��ѯ���ݿ�**********2.ɾ�����ݿ�******\n******3.��ѯ��λ״̬********4.��ѯ���״̬****\n******5.��ѯС��״̬********6.չʾͣ����******\n        ********6.�˳���¼******\n\n", sizeof(sendData), 0);
		}
		else if ((strcmp(revData, "�˳���¼") == 0))
		{
			send(*ClientSocket, "�˳��ɹ�\n\n************��ѡ��������:******************\n*************1.����Ա********2.�û�**********\n*********************************************\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "ȡ��") == 0)
		{
			send(*ClientSocket, "ȡ�����ܴ�ʵ��\n\n*******������û�����ѡ��*********\n******1.ͣ��**********2.ȡ��******\n******3.�˳���¼********\n\n", sizeof(sendData), 0);
		}
		else if (strcmp(revData, "ͣ��") == 0)
		{
			send(*ClientSocket, "ͣ�����ܴ�ʵ��\n\n*******������û�����ѡ��*********\n******1.ͣ��**********2.ȡ��******\n******3.�˳���¼********\n\n", sizeof(sendData), 0);
		}
		else
		{
			send(*ClientSocket, "��Ч����\n", sizeof(sendData), 0);
		}
	}
	closesocket(*ClientSocket);
	free(ClientSocket);
	return 0;
}



int main(){
	m.initParking();
	WSAData wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	SOCKET ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ListenAddr;
	ListenAddr.sin_family = AF_INET;
	ListenAddr.sin_addr.S_un.S_addr = INADDR_ANY;//��ʾ���뱾��ip
	ListenAddr.sin_port = htons(PORT);
	int n;
	n = bind(ListenSocket, (LPSOCKADDR)&ListenAddr, sizeof(ListenAddr));
	if (n == SOCKET_ERROR){
		cout << "�˿ڰ�ʧ�ܣ�" << endl;
		return -1;
	}
	else{
		cout << "�˿ڰ󶨳ɹ���" << PORT << endl;
	}
	int l = listen(ListenSocket, 20);
	cout << "�����׼���������ȴ���������" << endl;

	while (1){
		//ѭ�����տͻ����������󲢴��������߳�
		SOCKET *ClientSocket = new SOCKET;
		ClientSocket = (SOCKET*)malloc(sizeof(SOCKET));
		//���տͻ�����������
		int SockAddrlen = sizeof(sockaddr);
		*ClientSocket = accept(ListenSocket, 0, 0);
		cout << "һ���ͻ��������ӵ���������socket�ǣ�" << *ClientSocket << endl;
		CreateThread(NULL, 0, &ServerThread, ClientSocket, 0, NULL);
	}//while
	closesocket(ListenSocket);
	WSACleanup();
	system("pause");
	return(0);
}//main

