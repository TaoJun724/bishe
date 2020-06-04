#pragma once
#include<string>
#include<iostream>
#include<stdio.h>
#include"corrd.hpp"
using namespace std;
namespace systemServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// showCarRoteForm ժҪ
	/// </summary>
	public ref class showCarRoteForm : public System::Windows::Forms::Form
	{
	public:
		showCarRoteForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴���ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~showCarRoteForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;

	private:
		/// <summary>
		/// ����������������
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����֧������ķ��� - ��Ҫ
		/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(44, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������鿴��С����ţ�";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Window;
			this->button1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->ForeColor = System::Drawing::SystemColors::MenuText;
			this->button1->Location = System::Drawing::Point(173, 160);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 45);
			this->button1->TabIndex = 1;
			this->button1->Text = L"�鿴";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &showCarRoteForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(279, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 3;
			// 
			// showCarRoteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(478, 253);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"showCarRoteForm";
			this->Text = L"С��λ������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				int index =  System::Convert::ToInt32(textBox1->Text);
				int x = 0; int y = 0;
				//A��С��
				for (int i = 0; i < carVectA.size(); i++)
				{
					if (carVectA[i].index == index)
					{
						//�������
						for (int j = 0; j < aEle.size(); j++)
						{
							if (strcmp(carVectA[i].position.c_str(), aEle[j].index0.c_str()) == 0)
							{
								x = aEle[j].x; y = aEle[j].y;
							}
						}
						//�����
						for (int j = 0; j < aLine.size(); j++)
						{
							if (strcmp(carVectA[i].position.c_str(), aLine[j].index0.c_str()) == 0)
							{
								x = aLine[j].x; y = aLine[j].y;
							}
						}
						//ͣ����
						for (int j = 0; j < aPark1.size(); j++)
						{
							if (strcmp(carVectA[i].position.c_str(), aPark1[j].index0.c_str()) == 0)
							{
								x = aPark1[j].x; y = aPark1[j].y;
							}
						}
						for (int j = 0; j < aPark2.size(); j++)
						{
							if (strcmp(carVectA[i].position.c_str(), aPark2[j].index0.c_str()) == 0)
							{
								x = aPark2[j].x; y = aPark2[j].y;
							}
						}
						//��λ
						for (int j = 0; j < aSpace.size(); j++)
						{
							if (strcmp(carVectA[i].position.c_str(), aSpace[j].index0.c_str()) == 0)
							{
								x = aSpace[j].x; y = aSpace[j].y;
							}
						}
					}
				}
				//B��С��
				for (int i = 0; i < carVectB.size(); i++)
				{
					if (carVectB[i].index == index)
					{
						//�������
						for (int j = 0; j < bEle.size(); j++)
						{
							if (strcmp(carVectB[i].position.c_str(), bEle[j].index0.c_str()) == 0)
							{
								x = bEle[j].x; y = bEle[j].y;
							}
						}
						//�����
						for (int j = 0; j < bLine.size(); j++)
						{
							if (strcmp(carVectB[i].position.c_str(), bLine[j].index0.c_str()) == 0)
							{
								x = bLine[j].x; y = bLine[j].y;
							}
						}
						//ͣ����
						for (int j = 0; j < bPark.size(); j++)
						{
							if (strcmp(carVectB[i].position.c_str(), bPark[j].index0.c_str()) == 0)
							{
								x = bPark[j].x; y = bPark[j].y;
							}
						}
						//��λ
						for (int j = 0; j < bSpace.size(); j++)
						{
							if (strcmp(carVectB[i].position.c_str(), bSpace[j].index0.c_str()) == 0)
							{
								x = bSpace[j].x; y = bSpace[j].y;
							}
						}
					}
				}
			/*	MessageBox::Show(x.ToString(),"��ѯС����λ�ú�����Ϊ");
				MessageBox::Show(y.ToString(),"��ѯС����λ��������Ϊ");*/
			
				MessageBox::Show("��ѯС����λ�ú�����Ϊ" + x +"��ѯС��λ�õ�������Ϊ" + y);
	}
	};
}
