#pragma once
#include"clientForm.h"
namespace systemClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// userMess 摘要
	/// </summary>
	public ref class userMess : public System::Windows::Forms::Form
	{
	public:
		userMess(void)
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
		~userMess()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button9;
	protected:

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
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::White;
			this->button8->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button8->Location = System::Drawing::Point(169, 39);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(154, 59);
			this->button8->TabIndex = 9;
			this->button8->Text = L"插入用户信息";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &userMess::button8_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->Location = System::Drawing::Point(169, 128);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 59);
			this->button3->TabIndex = 10;
			this->button3->Text = L"删除用户信息";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &userMess::button3_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::White;
			this->button9->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button9->Location = System::Drawing::Point(168, 221);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(155, 59);
			this->button9->TabIndex = 11;
			this->button9->Text = L"修改用户信息";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &userMess::button9_Click);
			// 
			// userMess
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(532, 313);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button8);
			this->Name = L"userMess";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"userMess";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
				 index = 10;
				 this->Close();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 index = 5;
				 this->Close();
	}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 index = 11;
			 this->Close();
}
};
}
