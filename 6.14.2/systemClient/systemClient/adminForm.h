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
	/// adminForm ժҪ
	/// </summary>
	public ref class adminForm : public System::Windows::Forms::Form
	{
	public:
		adminForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �ڴ˴����ӹ��캯������
			//
		}

	protected:
		/// <summary>
		/// ������������ʹ�õ���Դ��
		/// </summary>
		~adminForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->Location = System::Drawing::Point(34, 242);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 59);
			this->button1->TabIndex = 1;
			this->button1->Text = L"��ѯ���ݿ�";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &adminForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button2->Location = System::Drawing::Point(231, 147);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 59);
			this->button2->TabIndex = 2;
			this->button2->Text = L"��ѯС��״̬";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &adminForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button3->Location = System::Drawing::Point(231, 51);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 59);
			this->button3->TabIndex = 3;
			this->button3->Text = L"ɾ���û���Ϣ";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &adminForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::White;
			this->button4->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button4->Location = System::Drawing::Point(34, 147);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(154, 59);
			this->button4->TabIndex = 4;
			this->button4->Text = L"��ѯ��λ״̬";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &adminForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::White;
			this->button5->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button5->Location = System::Drawing::Point(419, 147);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(155, 59);
			this->button5->TabIndex = 5;
			this->button5->Text = L"��ѯ���״̬";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &adminForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::White;
			this->button6->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button6->Location = System::Drawing::Point(419, 242);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(155, 59);
			this->button6->TabIndex = 6;
			this->button6->Text = L"չʾͣ����";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &adminForm::button6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::White;
			this->button7->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button7->Location = System::Drawing::Point(231, 242);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(156, 59);
			this->button7->TabIndex = 7;
			this->button7->Text = L"��ѯС��λ��";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &adminForm::button7_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::White;
			this->button8->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button8->Location = System::Drawing::Point(34, 51);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(154, 59);
			this->button8->TabIndex = 8;
			this->button8->Text = L"�����û���Ϣ";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &adminForm::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::White;
			this->button9->Font = (gcnew System::Drawing::Font(L"����", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button9->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button9->Location = System::Drawing::Point(419, 51);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(155, 59);
			this->button9->TabIndex = 9;
			this->button9->Text = L"�޸��û���Ϣ";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &adminForm::button9_Click);
			// 
			// adminForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(647, 349);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"adminForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����Ա���ܽ���";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 index = 3;
				 MessageBox::Show(this, "����ִ������");
				 this->Close();
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 index = 4;
				 MessageBox::Show(this, "����ִ������");
				 this->Close();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 index = 5;
				 MessageBox::Show(this, "����ִ������");
	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 index = 6;
			 MessageBox::Show(this, "����ִ������");
			 this->Close();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 index = 7;
			 MessageBox::Show(this, "����ִ������");
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 index = 8;
			 MessageBox::Show(this, "����ִ������");
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 index = 9;
			 MessageBox::Show(this, "����ִ������");
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 index = 10;
			 MessageBox::Show(this, "����ִ������");
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
			 index = 11;
			 MessageBox::Show(this, "����ִ������");
}
};
}