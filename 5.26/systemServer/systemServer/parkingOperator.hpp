#ifndef  __PARKING_OPERTORO_HPP__
#define  __PARKING_OPERTORO_HPP__

#include"Comm.hpp"

int arr[ROW][COL] = {};

class Build
{
public:
	void menu()
	{
		cout << "*********************************************" << endl;
		cout << "*****************0.�˳�**********************" << endl;
		cout << "****1.��λ����*******2.�������**************" << endl;
		cout << "****3.���������*****4.������ͣ��������******" << endl;
		cout << "***************5.������**********************" << endl;
		cout << "***************8.չʾ**********************" << endl;
		cout << "*********************************************" << endl;
	}

	void give(int arr[ROW][COL], int x, int y, int wide, int length, int index)
	{
		for (int i = x - wide + 1; i <= x; i++)//���оֲ��ĸ�ֵ
		{
			for (int j = y; j <= y + length - 1; j++)
			if (index == 1)//��λ
				arr[i][j] = 1;
			else if (index == 2)//���
				arr[i][j] = 2;
			else if (index == 3)//�������λ
				arr[i][j] = 3;
			else if (index == 4)//������С��ͣ����λ
				arr[i][j] = 4;
			else if (index == 5)//�������
				arr[i][j] = 5;
			else if (index == 0)//ͣ�����������
				arr[i][j] = 10;
		}
	}

	//FOREGROUND��ɫֻ�����֣�GREEN��BLUE��RED��INTENSIFY����ǿ��
	//  ��ɫ + ��ɫ = ��ɫ
	//	��ɫ + ��ɫ = ��ɫ
	//	��ɫ + ��ɫ = Ʒ��
	//	��ɫ + ��ɫ + ��ɫ = ��ɫ
	//  0 = ��ɫ                8 = ��ɫ����
	//	1 = ��ɫ                9 = ����ɫ       
	//	2 = ��ɫ                10 = ����ɫ       
	//	3 = ����ɫ              11 = ��ǳ��ɫ     
	//	4 = ��ɫ                12 = ����ɫ       
	//	5 = ��ɫ                13 = ����ɫ       
	//	6 = ��ɫ                14 = ����ɫ       
	//	7 = ��ɫ                15 = ����ɫ     

	void print(int arr[ROW][COL])
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				if (arr[i][j] == 1)//��ʾ��λ
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
					cout << "��";

				}
				else if (arr[i][j] == 0)//������
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					cout << "��";
				}
				else if (arr[i][j] == 2)//���
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					cout << "��";
				}
				else if (arr[i][j] == 3)//�����
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << "��";
				}
				else if (arr[i][j] == 4)//������С��ͣ����
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
					cout << "��";
				}
				else if (arr[i][j] == 5)//�߽�
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					cout << "��";
				}
				else if (arr[i][j] == 6)//Ԥ����λ
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << "��";
				}
				else if (arr[i][j] == 7)//�ĳ�λ�ѱ�ռ��
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					cout << "��";
				}
				else if (arr[i][j] == 8)//�ı���ѱ�ռ��
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					cout << "��";
				}
				else if (arr[i][j] == 9)//�ĳ���ѱ�ռ��
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					cout << "��";
				}
				else if (arr[i][j] == 11)//��ͣ���ѱ�ռ��
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					cout << "��";
				}
				else if (arr[i][j] == 10)//ǽ
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					cout << "��";
				}
			}
			if (j == COL)//��������з���
				cout << endl;
		}
	}

	void model(int arr[ROW][COL])
	{
		FILE* fp1;
		fp1 = fopen("��·����.txt", "r");
		while (1)
		{
			//	cout << "���������¶���������±�" << endl;
			int x, y;
			fscanf(fp1, "%d", &x);
			fscanf(fp1, "%d", &y);
			if (x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			int wide, length;
			fscanf(fp1, "%d", &length);
			fscanf(fp1, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 2);//���оֲ��ĸ�ֵ
				//	cout << "����չʾ:" << endl;//����չʾ
				//	print(arr);
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp1);



		FILE* fp3;
		fp3 = fopen("����������.txt", "r");
		while (1)
		{
			//	cout << "���������¶���������±�" << endl;
			int x, y;
			fscanf(fp3, "%d", &x);
			fscanf(fp3, "%d", &y);
			if (x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			int wide, length;
			fscanf(fp3, "%d", &length);
			fscanf(fp3, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 5);//���оֲ��ĸ�ֵ
				//	cout << "����չʾ:" << endl;//����չʾ
				//	print(arr);
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp3);

		FILE* fp2;
		fp2 = fopen("ͣ����A���������.txt", "r");
		while (1)
		{
			//	cout << "���������¶���������±�" << endl;
			int x, y;
			fscanf(fp2, "%d", &x);
			fscanf(fp2, "%d", &y);
			if (x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			int wide, length;
			fscanf(fp2, "%d", &length);
			fscanf(fp2, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 3);//���оֲ��ĸ�ֵ
				//	cout << "����չʾ:" << endl;//����չʾ
				//	print(arr);
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp2);

		FILE* fp6;
		fp6 = fopen("ͣ����B���������.txt", "r");
		while (1)
		{
			int x, y;
			fscanf(fp6, "%d", &x);
			fscanf(fp6, "%d", &y);
			if (x < 0)
				break;
			int wide, length;
			fscanf(fp6, "%d", &length);
			fscanf(fp6, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 3);//���оֲ��ĸ�ֵ
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp6);

		FILE* fp4;
		fp4 = fopen("AС��ͣ��������.txt", "r");
		while (1)
		{
			//	cout << "���������¶���������±�" << endl;
			int x, y;
			fscanf(fp4, "%d", &x);
			fscanf(fp4, "%d", &y);
			if (x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			int wide, length;
			fscanf(fp4, "%d", &length);
			fscanf(fp4, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 4);//���оֲ��ĸ�ֵ
				//	cout << "����չʾ:" << endl;//����չʾ
				//	print(arr);
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp4);

		FILE* fp7;
		fp7 = fopen("BС��ͣ��������.txt", "r");
		while (1)
		{
			//	cout << "���������¶���������±�" << endl;
			int x, y;
			fscanf(fp7, "%d", &x);
			fscanf(fp7, "%d", &y);
			if (x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			int wide, length;
			fscanf(fp7, "%d", &length);
			fscanf(fp7, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 4);//���оֲ��ĸ�ֵ
				//	cout << "����չʾ:" << endl;//����չʾ
				//	print(arr);
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp7);


		FILE* fp5;
		fp5 = fopen("A��λ����.txt", "r");
		while (1)
		{
			//	cout << "���������¶���������±�" << endl;
			int x, y;
			fscanf(fp5, "%d", &x);
			fscanf(fp5, "%d", &y);
			if (x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			int wide, length;
			fscanf(fp5, "%d", &length);
			fscanf(fp5, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 1);//���оֲ��ĸ�ֵ
				//	cout << "����չʾ:" << endl;//����չʾ
				//	print(arr);
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp5);

		FILE* fp8;
		fp8 = fopen("B��λ����.txt", "r");
		while (1)
		{
			//	cout << "���������¶���������±�" << endl;
			int x, y;
			fscanf(fp8, "%d", &x);
			fscanf(fp8, "%d", &y);
			if (x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			int wide, length;
			fscanf(fp8, "%d", &length);
			fscanf(fp8, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 1);//���оֲ��ĸ�ֵ
				//	cout << "����չʾ:" << endl;//����չʾ
				//	print(arr);
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp8);

		FILE* fp9;
		fp9 = fopen("���ó�λ����.txt", "r");
		while (1)
		{
			//	cout << "���������¶���������±�" << endl;
			int x, y;
			fscanf(fp9, "%d", &x);
			fscanf(fp9, "%d", &y);
			if (x < 0)
				break;
			//cout << "������ֲ�����ĳ�������" << endl;
			int wide, length;
			fscanf(fp9, "%d", &length);
			fscanf(fp9, "%d", &wide);

			int err = 0;
			if ((x - wide + 1 < 0) || (y + length - 1 > COL))
			{
				err = 1;
			}
			if (err == 0){
				give(arr, x, y, wide, length, 1);//���оֲ��ĸ�ֵ
				//	cout << "����չʾ:" << endl;//����չʾ
				//	print(arr);
			}
			else{
				//cout << "�������򲻴���" << endl;
			}
		}
		fclose(fp9);
		give(arr, 105, 95, 35, 1, 0);
	}

};

#endif