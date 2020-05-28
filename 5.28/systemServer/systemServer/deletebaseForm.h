#pragma once
#include<string>
#include"insertDataBaseForm.h"
namespace systemServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// deletebaseForm 摘要
	/// </summary>
	public ref class deletebaseForm : public System::Windows::Forms::Form
	{
	public:
		deletebaseForm(void)
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
		~deletebaseForm()
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(46, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"请输入删除的车牌号：";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(247, 93);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(126, 25);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(184, 165);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 42);
			this->button1->TabIndex = 2;
			this->button1->Text = L"删除";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &deletebaseForm::button1_Click);
			// 
			// deletebaseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(508, 253);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"deletebaseForm";
			this->Text = L"删除数据库";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 string licenseplate;
				 using namespace System::Runtime::InteropServices;
				 licenseplate = (char*)Marshal::StringToHGlobalAnsi(textBox1->Text).ToPointer();

				 string str4("delete from userInfo where licensePlate = '");
				 str4 += licenseplate;
				 string str5("'");
				 str4 += str5;
				 const char* SQL = str4.c_str();
				 sql.DeleteData(SQL);
				 sql.QueryDatabase1();
				
	}
	};
}
