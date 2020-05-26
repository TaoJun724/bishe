#pragma once
#include<iostream>
#include"parkingOperator.hpp"
using namespace std;
namespace systemServer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// showRoadStatusForm 摘要
	/// </summary>
	public ref class showRoadStatusForm : public System::Windows::Forms::Form
	{
	public:
		showRoadStatusForm(void)
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
		~showRoadStatusForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label4;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(46, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"空闲便道数量为：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(46, 252);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(189, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"非空闲便道数量为：";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(241, 37);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(46, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(229, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"空闲便道坐标如下所示：";
			this->label3->Click += gcnew System::EventHandler(this, &showRoadStatusForm::label3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(50, 129);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(473, 106);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(241, 247);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 25);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(50, 329);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(473, 106);
			this->textBox4->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(46, 294);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(249, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"非空闲便道坐标如下所示：";
			// 
			// showRoadStatusForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(622, 513);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"showRoadStatusForm";
			this->Text = L"查看便道状态";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}

			 public:void find(int& free0, int& busy0)
			 {
						textBox1->Text = (free0).ToString();
						textBox3->Text = (busy0).ToString();						
						int x; int y;
						int index = 0;
						int free = 0;
						int busy = 0;

						FILE* fp1;
						fp1 = fopen("线路坐标.txt", "r");
						while (1)
						{
							fscanf(fp1, "%d", &x);
							fscanf(fp1, "%d", &y);
							if (x < 0)
								break;
							if (arr[x][y] == 2)
							{
								free++;
								textBox2->Text += "x";
								textBox2->Text += ":";
								if (x <= 9)
								{
									textBox2->Text += "00";
								}
								else if ((x > 9) && (x <= 99))
								{
									textBox2->Text += "0";
								}
								textBox2->Text += x;
								textBox2->Text += "/";
								textBox2->Text += "y";
								textBox2->Text += ":";
								if (y <= 9)
								{
									textBox2->Text += "0";
								}
								else if ((y > 9) && (y <= 99))
								{
									textBox2->Text += "0";
								}
								textBox2->Text += y;
								textBox2->Text += " ";
							}
						}
						while (1)
						{
							fscanf(fp1, "%d", &x);
							fscanf(fp1, "%d", &y);
							if (x < 0)
								break;
							if (arr[x][y] != 2)
							{
								busy++;
								textBox4->Text += "x";
								textBox4->Text += ":";
								if (x <= 9)
								{
									textBox4->Text += "00";
								}
								else if ((x > 9) && (x <= 99))
								{
									textBox4->Text += "0";
								}
								textBox4->Text += x;
								textBox4->Text += "/";
								textBox4->Text += "y";
								textBox4->Text += ":";
								if (y <= 9)
								{
									textBox4->Text += "0";
								}
								else if ((y > 9) && (y <= 99))
								{
									textBox4->Text += "0";
								}
								textBox4->Text += y;
								textBox4->Text += " ";
							}
						}
						fclose(fp1);			
			 }
	};
}
