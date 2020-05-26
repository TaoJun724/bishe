#pragma once
#include<string.h>
#include<map>
#include"CMysqlOperator.hpp"
map<string, string> plsql;
CMysqlOperatoe sql;

int index;
int show = 0;
namespace systemClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// clientForm 摘要
	/// </summary>
	public ref class clientForm : public System::Windows::Forms::Form
	{
	public:
		clientForm(void)
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
		~clientForm()
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
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label5;

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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(183, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(222, 28);
			this->label1->TabIndex = 1;
			this->label1->Text = L"AGV小车管理系统";
			this->label1->Click += gcnew System::EventHandler(this, &clientForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(433, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(113, 15);
			this->label2->TabIndex = 2;
			this->label2->Text = L"--西安科技大学";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(108, 162);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"车牌号";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label3->Click += gcnew System::EventHandler(this, &clientForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(117, 215);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(49, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"密码";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(201, 157);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(172, 25);
			this->textBox1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(201, 210);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(172, 25);
			this->textBox2->TabIndex = 8;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::AliceBlue;
			this->button1->Location = System::Drawing::Point(79, 269);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 45);
			this->button1->TabIndex = 10;
			this->button1->Text = L"管理员登录";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &clientForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->button2->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->button2->Location = System::Drawing::Point(245, 269);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 45);
			this->button2->TabIndex = 11;
			this->button2->Text = L"用户登录";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &clientForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button3->Location = System::Drawing::Point(413, 269);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 45);
			this->button3->TabIndex = 12;
			this->button3->Text = L"用户注册";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &clientForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(201, 105);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(172, 25);
			this->textBox3->TabIndex = 14;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(117, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 20);
			this->label5->TabIndex = 16;
			this->label5->Text = L"姓名";
			// 
			// clientForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(607, 326);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"clientForm";
			this->Text = L"AGV小车管理系统客户端";
			this->Load += gcnew System::EventHandler(this, &clientForm::clientForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void clientForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 string licenseplate;
			 using namespace System::Runtime::InteropServices;
			 licenseplate = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer();

			 string password = plsql[licenseplate];
			 string passed;
			 using namespace System::Runtime::InteropServices;
			 passed = (char*)Marshal::StringToHGlobalAnsi(textBox2->Text).ToPointer();
			 if (strcmp(password.c_str(), passed.c_str()) == 0)
			 {
				 MessageBox::Show(this, "用户登录成功");//这才是正确的
				 show = 1;
			 }
			 else{
				 MessageBox::Show(this, "用户登录失败，请重新登录");//这才是正确的
			 }

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 string licenseplate;
			 string name;
			 string passed;

			 using namespace System::Runtime::InteropServices;
			 licenseplate = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer();
			 using namespace System::Runtime::InteropServices;
			 passed = (char*)Marshal::StringToHGlobalAnsi(textBox2->Text).ToPointer();
			 using namespace System::Runtime::InteropServices;
			 name = (char*)Marshal::StringToHGlobalAnsi(textBox3->Text).ToPointer();

			 if (((strcmp(licenseplate.c_str(), "admin")) == 0) && ((strcmp(name.c_str(), "admin")) == 0) && ((strcmp(passed.c_str(), "admin")) == 0))
			 {
					 MessageBox::Show(this, "管理员登录成功");//这才是正确的
					 show = 2;
			 }
	     	 else{
				 		 MessageBox::Show(this, "管理员登录失败");//这才是正确的
			 }
}

		 //用户注册
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 string licenseplate;
			 string name;
			 string passed;

			 using namespace System::Runtime::InteropServices;
			 licenseplate = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer();
			 using namespace System::Runtime::InteropServices;
			 passed = (char*)Marshal::StringToHGlobalAnsi(textBox2->Text).ToPointer();
			 using namespace System::Runtime::InteropServices;
			 name = (char*)Marshal::StringToHGlobalAnsi(textBox3->Text).ToPointer();
		
			 int sqlsize0 = plsql.size();
			 plsql.insert(make_pair(licenseplate, passed));
			 int sqlsize1 = plsql.size();
        	 string SQL("Insert into userInfo(licensePlate, userName, passwd) values('");
			 SQL += licenseplate;
			 string SQL1("','");
			 string SQL2("');");
			 SQL += SQL1;
			 SQL += name;
			 SQL += SQL1;
			 SQL += passed;
			 SQL += SQL2;
			 const char* sq = SQL.c_str();
			 sql.InsertDate(sq);
			 if ((licenseplate.size() != 0) &&(name.size() != 0) && (passed.size() != 0)&&(sqlsize0 != sqlsize1))
			 {
				 MessageBox::Show(this, "注册成功");
			 }else
			 {
				 MessageBox::Show(this, "注册失败");
			 }
			 
}
};
}
