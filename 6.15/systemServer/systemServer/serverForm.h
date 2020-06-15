#pragma once

namespace systemServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// serverForm 摘要
	/// </summary>
	public ref class serverForm : public System::Windows::Forms::Form
	{
	public:
		serverForm(void)
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
		~serverForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;

	private:








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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(36, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"服务器设置";
			this->label1->Click += gcnew System::EventHandler(this, &serverForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(63, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 15);
			this->label2->TabIndex = 3;
			this->label2->Text = L"监听IP";
			this->label2->Click += gcnew System::EventHandler(this, &serverForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AllowDrop = true;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(63, 130);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 15);
			this->label3->TabIndex = 4;
			this->label3->Text = L"监听端口";
			this->label3->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label3->Click += gcnew System::EventHandler(this, &serverForm::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(156, 71);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"127.0.0.1";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(156, 127);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 25);
			this->textBox2->TabIndex = 8;
			this->textBox2->Text = L"8000";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &serverForm::textBox2_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(48, 318);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(236, 15);
			this->label4->TabIndex = 10;
			this->label4->Text = L"服务器正在运行....端口号为8000";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Click += gcnew System::EventHandler(this, &serverForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 230);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(255, 15);
			this->label5->TabIndex = 12;
			this->label5->Text = L"一个客户端连接到服务器,端口号为：";
			this->label5->Click += gcnew System::EventHandler(this, &serverForm::label5_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(263, 227);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(38, 25);
			this->textBox3->TabIndex = 13;
			// 
			// serverForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(339, 374);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"serverForm";
			this->Text = L"系统服务端";
			this->Load += gcnew System::EventHandler(this, &serverForm::serverForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
				 
	}
   private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

   }
private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
		
}

private: System::Void serverForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		
}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}



			 public: void change(int& sock)
			 {
				 textBox3->Text = (sock).ToString();
				 // MessageBox::Show(textBox1->Text);
		         textBox1->Refresh();
			 }

};
}
