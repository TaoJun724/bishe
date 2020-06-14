#pragma once
#include<string>
#include<iostream>
#include"CMysqlOperator.hpp"
#include"insertDataBaseForm.h"
using namespace std;

namespace systemServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// modiftyDataForm 摘要
	/// </summary>
	public ref class modiftyDataForm : public System::Windows::Forms::Form
	{
	public:
		modiftyDataForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~modiftyDataForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(63, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"修改前用户信息：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(63, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"修改后用户信息：";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(63, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"姓名：";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(138, 64);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 30);
			this->textBox1->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(244, 67);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 20);
			this->label4->TabIndex = 6;
			this->label4->Text = L"车牌号：";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(328, 64);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 30);
			this->textBox2->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(434, 67);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 20);
			this->label5->TabIndex = 8;
			this->label5->Text = L"密码：";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(497, 64);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 30);
			this->textBox3->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(63, 198);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(69, 20);
			this->label6->TabIndex = 10;
			this->label6->Text = L"姓名：";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(138, 195);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 30);
			this->textBox4->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(244, 205);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 20);
			this->label7->TabIndex = 12;
			this->label7->Text = L"车牌号：";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(328, 198);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 30);
			this->textBox5->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(434, 208);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(69, 20);
			this->label8->TabIndex = 14;
			this->label8->Text = L"密码：";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(497, 202);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 30);
			this->textBox6->TabIndex = 15;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &modiftyDataForm::textBox6_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(522, 263);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 38);
			this->button1->TabIndex = 17;
			this->button1->Text = L"修改";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &modiftyDataForm::button1_Click);
			// 
			// modiftyDataForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(656, 313);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(134)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"modiftyDataForm";
			this->Text = L"修改用户信息";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 string licenseplate;
				 using namespace System::Runtime::InteropServices;
				 licenseplate = (char*)Marshal::StringToHGlobalAnsi(textBox2->Text).ToPointer();

				 string str4("delete from userInfo where licensePlate = '");
				 str4 += licenseplate;
				 string str5("'");
				 str4 += str5;
				 const char* SQL = str4.c_str();
				 sql.DeleteData(SQL);
				 
				 string name;
				 string passed;

				 using namespace System::Runtime::InteropServices;
				 name = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer();
				 using namespace System::Runtime::InteropServices;
				 licenseplate = (char*)Marshal::StringToHGlobalAnsi(textBox2->Text).ToPointer();
				 using namespace System::Runtime::InteropServices;
				 passed = (char*)Marshal::StringToHGlobalAnsi(textBox3->Text).ToPointer();


				 string str("Insert into userInfo(licensePlate, userName, passwd) values('");
				 using namespace System::Runtime::InteropServices;
				 string licenseplate2;
				 licenseplate2 = (char*)Marshal::StringToHGlobalAnsi(textBox5->Text).ToPointer();
				 str += licenseplate2;
				 string SQL1("','");
				 string SQL2("');");
				 str += SQL1;
				 using namespace System::Runtime::InteropServices;
				 name = (char*)Marshal::StringToHGlobalAnsi(textBox4->Text).ToPointer();
				 str += name;
				 str += SQL1;
				 using namespace System::Runtime::InteropServices;
				 passed = (char*)Marshal::StringToHGlobalAnsi(textBox6->Text).ToPointer();
				 str += passed;
				 str += SQL2;
				 const char* sq = str.c_str();
				 sql.InsertDate(sq);
				 if ((licenseplate2.size() != 0) && (name.size() != 0) && (passed.size() != 0))
				 {
					 MessageBox::Show(this, "修改成功");
					 this->Close();
				 }
				 else
				 {
					 MessageBox::Show(this, "修改失败，请重新修改。");
				 }
	}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
