#pragma once
#include"corrd.hpp"
#include"parkingOperator.hpp"
#include<string>
#include<iostream>
#include<Windows.h>
using namespace std;
int location;//�Դ��ж�ѡ���ĸ�ͣ����
string license;//����ĳ��ƺ�
namespace systemServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// parkForm ժҪ
	/// </summary>
	public ref class parkForm : public System::Windows::Forms::Form
	{
	public:
		parkForm(void)
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
		~parkForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(12, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"��������ĳ��ƺţ�";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(207, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(86, 25);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &parkForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(112, 139);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 37);
			this->button1->TabIndex = 4;
			this->button1->Text = L"ͣ��";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &parkForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(12, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"���������λ�ã�";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(207, 97);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(86, 25);
			this->textBox2->TabIndex = 6;
			// 
			// parkForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(310, 212);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"parkForm";
			this->Text = L"ͣ��";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 location = System::Convert::ToInt32(textBox2->Text);
				 using namespace System::Runtime::InteropServices;
				 license = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer();
				 MessageBox::Show("ϵͳ��ʼΪ��ͣ��");
	}

};
}
