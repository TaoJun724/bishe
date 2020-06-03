#pragma once
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
	/// showCarStatusForm 摘要
	/// </summary>
	public ref class showCarStatusForm : public System::Windows::Forms::Form
	{
	public:
		showCarStatusForm(void)
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
		~showCarStatusForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox7;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(58, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"AGV小车总数为：";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(223, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &showCarStatusForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(59, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"空闲小车数量为：";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(58, 162);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(169, 20);
			this->label3->TabIndex = 6;
			this->label3->Text = L"充电小车数量为：";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(59, 227);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(169, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"工作小车数量为：";
			this->label4->Click += gcnew System::EventHandler(this, &showCarStatusForm::label4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(223, 103);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 25);
			this->textBox2->TabIndex = 8;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(223, 162);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 25);
			this->textBox3->TabIndex = 9;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(223, 222);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 25);
			this->textBox4->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label5->Location = System::Drawing::Point(351, 103);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(89, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"编号为：";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(455, 102);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 25);
			this->textBox5->TabIndex = 14;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(455, 162);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 25);
			this->textBox6->TabIndex = 15;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(351, 162);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(89, 20);
			this->label6->TabIndex = 16;
			this->label6->Text = L"编号为：";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label7->Location = System::Drawing::Point(351, 221);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(89, 20);
			this->label7->TabIndex = 17;
			this->label7->Text = L"编号为：";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(455, 222);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 25);
			this->textBox7->TabIndex = 18;
			// 
			// showCarStatusForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(621, 497);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"showCarStatusForm";
			this->Text = L"查看小车状态";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 
}
       public:void find()
       {
				  textBox1->Text = "9";
				  int free = 0; int busy = 0; int ele = 0;
				  for (int i = 0; i < carVectA.size(); i++)
				  {
					  if (carVectA[i].status == false)
					  {
						  free++;
						  textBox5->Text += (i + 4);
						  textBox5->Text += "  ";
					  }
					  if (carVectA[i].status == true)
					  {
						  busy++;
						  textBox7->Text += (i + 4);
						  textBox7->Text += "  ";
					  }			
					  if (carVectA[i].eleFlag == 1)
					  {
						  ele++;
						  textBox6->Text += (i + 4);
						  textBox6->Text += "  ";
					  }
				  }
				  for (int i = 0; i < carVectB.size(); i++)
				  {
					  if (carVectB[i].status == false)
					  {
						  free++;
						  textBox5->Text += (i + 1);
						  textBox5->Text += "  ";
					  }
					  if (carVectB[i].status == true)
					  {
						  busy++;
						  textBox7->Text += (i + 1);
						  textBox7->Text += "  ";
					  }
					  if (carVectB[i].eleFlag == 1)
					  {
						  ele++;
						  textBox6->Text += (i + 1);
						  textBox6->Text += "  ";
					  }
				  }
				  if (free == 0)
				  {
					  textBox2->Text = "0";
				  } if (free == 1)
				  {
					  textBox2->Text = "1";
				  } if (free == 2)
				  {
					  textBox2->Text = "2";
				  } if (free == 3)
				  {
					  textBox2->Text = "3";
				  } if (free == 4)
				  {
					  textBox2->Text = "4";
				  } if (free == 5)
				  {
					  textBox2->Text = "5";
				  } if (free == 6)
				  {
					  textBox2->Text = "6";
				  } if (free == 7)
				  {
					  textBox2->Text = "7";
				  } if (free == 8)
				  {
					  textBox2->Text = "8";
				  } if (free == 9)
				  {
					  textBox2->Text = "9";
				  }

				  if (busy == 0)
				  {
					  textBox4->Text = "0";
				  }  if (busy == 1)
				  {
					  textBox4->Text = "1";
				  }  if (busy == 2)
				  {
					  textBox4->Text = "2";
				  }  if (busy == 3)
				  {
					  textBox4->Text = "3";
				  }  if (busy == 4)
				  {
					  textBox4->Text = "4";
				  }  if (busy == 5)
				  {
					  textBox4->Text = "5";
				  }  if (busy == 6)
				  {
					  textBox4->Text = "6";
				  }  if (busy == 7)
				  {
					  textBox4->Text = "7";
				  }  if (busy == 8)
				  {
					  textBox4->Text = "8";
				  }  if (busy == 9)
				  {
					  textBox4->Text = "9";
				  }

				  if (ele == 0)
				  {
					  textBox3->Text = "0";
				  }
				  if (ele == 1)
				  {
					  textBox3->Text = "1";
				  } if (ele == 2)
				  {
					  textBox3->Text = "2";
				  } if (ele == 3)
				  {
					  textBox3->Text = "3";
				  } if (ele == 4)
				  {
					  textBox3->Text = "4";
				  } if (ele == 5)
				  {
					  textBox3->Text = "5";
				  } if (ele == 6)
				  {
					  textBox3->Text = "6";
				  } if (ele == 7)
				  {
					  textBox3->Text = "7";
				  } if (ele == 8)
				  {
					  textBox3->Text = "8";
				  } if (ele == 9)
				  {
					  textBox3->Text = "9";
				  }


       }
};
}
