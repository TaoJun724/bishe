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

	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Panel^  panel15;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Panel^  panel16;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Panel^  panel17;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Panel^  panel18;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Panel^  panel19;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Panel^  panel20;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Panel^  panel21;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Panel^  panel22;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Panel^  panel23;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Panel^  panel24;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Panel^  panel25;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Panel^  panel26;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Panel^  panel27;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Panel^  panel28;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Panel^  panel29;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Panel^  panel30;
	private: System::Windows::Forms::Label^  label34;
	private: System::Windows::Forms::Panel^  panel31;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::Panel^  panel32;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Panel^  panel33;
	private: System::Windows::Forms::Label^  label37;
	private: System::Windows::Forms::Panel^  panel34;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  panel35;
	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Panel^  panel36;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Panel^  panel37;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Panel^  panel38;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Panel^  panel39;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Panel^  panel40;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Panel^  panel41;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::Panel^  panel42;
	private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::Panel^  panel43;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Panel^  panel44;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Panel^  panel45;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::Panel^  panel46;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Panel^  panel47;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::Panel^  panel48;
private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::Panel^  panel49;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::Panel^  panel50;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::Panel^  panel51;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::Panel^  panel52;
private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::Panel^  panel53;
private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::Panel^  panel54;
private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::Panel^  panel55;
private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::Panel^  panel56;
private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::Panel^  panel57;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::Panel^  panel58;
private: System::Windows::Forms::Label^  label62;









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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(showRoadStatusForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->panel15 = (gcnew System::Windows::Forms::Panel());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->panel16 = (gcnew System::Windows::Forms::Panel());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->panel17 = (gcnew System::Windows::Forms::Panel());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->panel18 = (gcnew System::Windows::Forms::Panel());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->panel19 = (gcnew System::Windows::Forms::Panel());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->panel20 = (gcnew System::Windows::Forms::Panel());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->panel21 = (gcnew System::Windows::Forms::Panel());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->panel25 = (gcnew System::Windows::Forms::Panel());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->panel26 = (gcnew System::Windows::Forms::Panel());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->panel27 = (gcnew System::Windows::Forms::Panel());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->panel28 = (gcnew System::Windows::Forms::Panel());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->panel29 = (gcnew System::Windows::Forms::Panel());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->panel30 = (gcnew System::Windows::Forms::Panel());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->panel31 = (gcnew System::Windows::Forms::Panel());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->panel32 = (gcnew System::Windows::Forms::Panel());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->panel33 = (gcnew System::Windows::Forms::Panel());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->panel34 = (gcnew System::Windows::Forms::Panel());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel35 = (gcnew System::Windows::Forms::Panel());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->panel36 = (gcnew System::Windows::Forms::Panel());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->panel37 = (gcnew System::Windows::Forms::Panel());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->panel38 = (gcnew System::Windows::Forms::Panel());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->panel39 = (gcnew System::Windows::Forms::Panel());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->panel40 = (gcnew System::Windows::Forms::Panel());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->panel41 = (gcnew System::Windows::Forms::Panel());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->panel42 = (gcnew System::Windows::Forms::Panel());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->panel43 = (gcnew System::Windows::Forms::Panel());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->panel44 = (gcnew System::Windows::Forms::Panel());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->panel45 = (gcnew System::Windows::Forms::Panel());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->panel46 = (gcnew System::Windows::Forms::Panel());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->panel47 = (gcnew System::Windows::Forms::Panel());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->panel48 = (gcnew System::Windows::Forms::Panel());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->panel49 = (gcnew System::Windows::Forms::Panel());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->panel50 = (gcnew System::Windows::Forms::Panel());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->panel51 = (gcnew System::Windows::Forms::Panel());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->panel52 = (gcnew System::Windows::Forms::Panel());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->panel53 = (gcnew System::Windows::Forms::Panel());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->panel54 = (gcnew System::Windows::Forms::Panel());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->panel55 = (gcnew System::Windows::Forms::Panel());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->panel56 = (gcnew System::Windows::Forms::Panel());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->panel57 = (gcnew System::Windows::Forms::Panel());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->panel58 = (gcnew System::Windows::Forms::Panel());
			this->label62 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel14->SuspendLayout();
			this->panel15->SuspendLayout();
			this->panel16->SuspendLayout();
			this->panel17->SuspendLayout();
			this->panel18->SuspendLayout();
			this->panel19->SuspendLayout();
			this->panel20->SuspendLayout();
			this->panel21->SuspendLayout();
			this->panel22->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel24->SuspendLayout();
			this->panel25->SuspendLayout();
			this->panel26->SuspendLayout();
			this->panel27->SuspendLayout();
			this->panel28->SuspendLayout();
			this->panel29->SuspendLayout();
			this->panel30->SuspendLayout();
			this->panel31->SuspendLayout();
			this->panel32->SuspendLayout();
			this->panel33->SuspendLayout();
			this->panel34->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel35->SuspendLayout();
			this->panel36->SuspendLayout();
			this->panel37->SuspendLayout();
			this->panel38->SuspendLayout();
			this->panel39->SuspendLayout();
			this->panel40->SuspendLayout();
			this->panel41->SuspendLayout();
			this->panel42->SuspendLayout();
			this->panel43->SuspendLayout();
			this->panel44->SuspendLayout();
			this->panel45->SuspendLayout();
			this->panel46->SuspendLayout();
			this->panel47->SuspendLayout();
			this->panel48->SuspendLayout();
			this->panel49->SuspendLayout();
			this->panel50->SuspendLayout();
			this->panel51->SuspendLayout();
			this->panel52->SuspendLayout();
			this->panel53->SuspendLayout();
			this->panel54->SuspendLayout();
			this->panel55->SuspendLayout();
			this->panel56->SuspendLayout();
			this->panel57->SuspendLayout();
			this->panel58->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(46, 109);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(202, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"空闲便道数量为：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(46, 401);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(226, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"非空闲便道数量为：";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(254, 108);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(46, 174);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(274, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"空闲便道坐标如下所示：";
			this->label3->Click += gcnew System::EventHandler(this, &showRoadStatusForm::label3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(50, 241);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(473, 106);
			this->textBox2->TabIndex = 4;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(254, 401);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 25);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(50, 552);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(473, 129);
			this->textBox4->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(46, 478);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(298, 24);
			this->label4->TabIndex = 7;
			this->label4->Text = L"非空闲便道坐标如下所示：";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(614, 499);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(505, 252);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Yellow;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Location = System::Drawing::Point(614, 51);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(118, 52);
			this->panel1->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Yellow;
			this->label5->Location = System::Drawing::Point(36, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 15);
			this->label5->TabIndex = 0;
			this->label5->Text = L"R00";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Yellow;
			this->panel2->Controls->Add(this->label6);
			this->panel2->Location = System::Drawing::Point(614, 111);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(67, 94);
			this->panel2->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Yellow;
			this->label6->Location = System::Drawing::Point(20, 18);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 15);
			this->label6->TabIndex = 0;
			this->label6->Text = L"R01";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Yellow;
			this->panel3->Controls->Add(this->label7);
			this->panel3->Location = System::Drawing::Point(687, 109);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(45, 52);
			this->panel3->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Yellow;
			this->label7->Location = System::Drawing::Point(11, 18);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 15);
			this->label7->TabIndex = 0;
			this->label7->Text = L"R02";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Yellow;
			this->panel4->Controls->Add(this->label8);
			this->panel4->Location = System::Drawing::Point(687, 161);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(121, 44);
			this->panel4->TabIndex = 14;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Yellow;
			this->label8->Location = System::Drawing::Point(14, 12);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 15);
			this->label8->TabIndex = 0;
			this->label8->Text = L"R03";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Yellow;
			this->panel5->Controls->Add(this->label9);
			this->panel5->Location = System::Drawing::Point(738, 111);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(70, 50);
			this->panel5->TabIndex = 15;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Yellow;
			this->label9->Location = System::Drawing::Point(14, 12);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(31, 15);
			this->label9->TabIndex = 0;
			this->label9->Text = L"R04";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Yellow;
			this->panel6->Controls->Add(this->label10);
			this->panel6->Location = System::Drawing::Point(814, 161);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(77, 44);
			this->panel6->TabIndex = 16;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Yellow;
			this->label10->Location = System::Drawing::Point(14, 12);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 15);
			this->label10->TabIndex = 0;
			this->label10->Text = L"R05";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Yellow;
			this->panel7->Controls->Add(this->label11);
			this->panel7->Location = System::Drawing::Point(814, 111);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(77, 50);
			this->panel7->TabIndex = 17;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Yellow;
			this->label11->Location = System::Drawing::Point(14, 12);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(31, 15);
			this->label11->TabIndex = 0;
			this->label11->Text = L"R06";
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Yellow;
			this->panel8->Controls->Add(this->label12);
			this->panel8->Location = System::Drawing::Point(897, 161);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(125, 44);
			this->panel8->TabIndex = 18;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Yellow;
			this->label12->Location = System::Drawing::Point(14, 12);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(31, 15);
			this->label12->TabIndex = 0;
			this->label12->Text = L"R07";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::Yellow;
			this->panel9->Controls->Add(this->label13);
			this->panel9->Location = System::Drawing::Point(897, 111);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(125, 50);
			this->panel9->TabIndex = 19;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Yellow;
			this->label13->Location = System::Drawing::Point(14, 12);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(31, 15);
			this->label13->TabIndex = 0;
			this->label13->Text = L"R08";
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::Yellow;
			this->panel10->Controls->Add(this->label14);
			this->panel10->Location = System::Drawing::Point(1042, 50);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(59, 26);
			this->panel10->TabIndex = 20;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Yellow;
			this->label14->Location = System::Drawing::Point(14, 4);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(31, 15);
			this->label14->TabIndex = 0;
			this->label14->Text = L"R09";
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::Yellow;
			this->panel11->Controls->Add(this->label15);
			this->panel11->Location = System::Drawing::Point(1042, 73);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(59, 30);
			this->panel11->TabIndex = 21;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Yellow;
			this->label15->Location = System::Drawing::Point(14, 6);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(31, 15);
			this->label15->TabIndex = 0;
			this->label15->Text = L"R10";
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::Yellow;
			this->panel12->Controls->Add(this->label16);
			this->panel12->Location = System::Drawing::Point(1028, 109);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(91, 52);
			this->panel12->TabIndex = 22;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Yellow;
			this->label16->Location = System::Drawing::Point(14, 12);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(31, 15);
			this->label16->TabIndex = 0;
			this->label16->Text = L"R11";
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::Yellow;
			this->panel13->Controls->Add(this->label17);
			this->panel13->Location = System::Drawing::Point(1028, 161);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(91, 44);
			this->panel13->TabIndex = 23;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Yellow;
			this->label17->Location = System::Drawing::Point(14, 12);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(31, 15);
			this->label17->TabIndex = 0;
			this->label17->Text = L"R12";
			// 
			// panel14
			// 
			this->panel14->BackColor = System::Drawing::Color::Yellow;
			this->panel14->Controls->Add(this->label18);
			this->panel14->Location = System::Drawing::Point(1125, 161);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(108, 44);
			this->panel14->TabIndex = 24;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Yellow;
			this->label18->Location = System::Drawing::Point(14, 12);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(31, 15);
			this->label18->TabIndex = 0;
			this->label18->Text = L"R13";
			// 
			// panel15
			// 
			this->panel15->BackColor = System::Drawing::Color::Yellow;
			this->panel15->Controls->Add(this->label19);
			this->panel15->Location = System::Drawing::Point(1125, 109);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(108, 52);
			this->panel15->TabIndex = 25;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Yellow;
			this->label19->Location = System::Drawing::Point(14, 12);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(31, 15);
			this->label19->TabIndex = 0;
			this->label19->Text = L"R14";
			// 
			// panel16
			// 
			this->panel16->BackColor = System::Drawing::Color::Yellow;
			this->panel16->Controls->Add(this->label20);
			this->panel16->Location = System::Drawing::Point(1239, 161);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(121, 44);
			this->panel16->TabIndex = 26;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::Color::Yellow;
			this->label20->Location = System::Drawing::Point(14, 12);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(31, 15);
			this->label20->TabIndex = 0;
			this->label20->Text = L"R15";
			// 
			// panel17
			// 
			this->panel17->BackColor = System::Drawing::Color::Yellow;
			this->panel17->Controls->Add(this->label21);
			this->panel17->Location = System::Drawing::Point(1239, 109);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(121, 52);
			this->panel17->TabIndex = 27;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->BackColor = System::Drawing::Color::Yellow;
			this->label21->Location = System::Drawing::Point(14, 12);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(31, 15);
			this->label21->TabIndex = 0;
			this->label21->Text = L"R16";
			// 
			// panel18
			// 
			this->panel18->BackColor = System::Drawing::Color::Yellow;
			this->panel18->Controls->Add(this->label22);
			this->panel18->Location = System::Drawing::Point(1366, 161);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(167, 44);
			this->panel18->TabIndex = 28;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->BackColor = System::Drawing::Color::Yellow;
			this->label22->Location = System::Drawing::Point(14, 12);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(31, 15);
			this->label22->TabIndex = 0;
			this->label22->Text = L"R17";
			// 
			// panel19
			// 
			this->panel19->BackColor = System::Drawing::Color::Yellow;
			this->panel19->Controls->Add(this->label23);
			this->panel19->Location = System::Drawing::Point(1366, 111);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(167, 50);
			this->panel19->TabIndex = 29;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->BackColor = System::Drawing::Color::Yellow;
			this->label23->Location = System::Drawing::Point(14, 12);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(31, 15);
			this->label23->TabIndex = 0;
			this->label23->Text = L"R18";
			// 
			// panel20
			// 
			this->panel20->BackColor = System::Drawing::Color::Yellow;
			this->panel20->Controls->Add(this->label24);
			this->panel20->Location = System::Drawing::Point(1539, 161);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(139, 44);
			this->panel20->TabIndex = 30;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BackColor = System::Drawing::Color::Yellow;
			this->label24->Location = System::Drawing::Point(14, 12);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(31, 15);
			this->label24->TabIndex = 0;
			this->label24->Text = L"R19";
			// 
			// panel21
			// 
			this->panel21->BackColor = System::Drawing::Color::Yellow;
			this->panel21->Controls->Add(this->label25);
			this->panel21->Location = System::Drawing::Point(1539, 111);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(139, 50);
			this->panel21->TabIndex = 31;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->BackColor = System::Drawing::Color::Yellow;
			this->label25->Location = System::Drawing::Point(14, 12);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(31, 15);
			this->label25->TabIndex = 0;
			this->label25->Text = L"R20";
			// 
			// panel22
			// 
			this->panel22->BackColor = System::Drawing::Color::Yellow;
			this->panel22->Controls->Add(this->label26);
			this->panel22->Location = System::Drawing::Point(1654, 401);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(182, 78);
			this->panel22->TabIndex = 32;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->BackColor = System::Drawing::Color::Yellow;
			this->label26->Location = System::Drawing::Point(14, 12);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(31, 15);
			this->label26->TabIndex = 0;
			this->label26->Text = L"R21";
			// 
			// panel23
			// 
			this->panel23->BackColor = System::Drawing::Color::Yellow;
			this->panel23->Controls->Add(this->label27);
			this->panel23->Location = System::Drawing::Point(1732, 211);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(47, 184);
			this->panel23->TabIndex = 33;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->BackColor = System::Drawing::Color::Yellow;
			this->label27->Location = System::Drawing::Point(3, 14);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(31, 15);
			this->label27->TabIndex = 0;
			this->label27->Text = L"R22";
			// 
			// panel24
			// 
			this->panel24->BackColor = System::Drawing::Color::Yellow;
			this->panel24->Controls->Add(this->label28);
			this->panel24->Location = System::Drawing::Point(1684, 111);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(152, 94);
			this->panel24->TabIndex = 34;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->BackColor = System::Drawing::Color::Yellow;
			this->label28->Location = System::Drawing::Point(14, 12);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(31, 15);
			this->label28->TabIndex = 0;
			this->label28->Text = L"R23";
			// 
			// panel25
			// 
			this->panel25->BackColor = System::Drawing::Color::Yellow;
			this->panel25->Controls->Add(this->label29);
			this->panel25->Location = System::Drawing::Point(1785, 211);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(51, 184);
			this->panel25->TabIndex = 35;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->BackColor = System::Drawing::Color::Yellow;
			this->label29->Location = System::Drawing::Point(14, 12);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(31, 15);
			this->label29->TabIndex = 0;
			this->label29->Text = L"R24";
			// 
			// panel26
			// 
			this->panel26->BackColor = System::Drawing::Color::Yellow;
			this->panel26->Controls->Add(this->label30);
			this->panel26->Location = System::Drawing::Point(1485, 401);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(163, 40);
			this->panel26->TabIndex = 36;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->BackColor = System::Drawing::Color::Yellow;
			this->label30->Location = System::Drawing::Point(14, 12);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(31, 15);
			this->label30->TabIndex = 0;
			this->label30->Text = L"R25";
			// 
			// panel27
			// 
			this->panel27->BackColor = System::Drawing::Color::Yellow;
			this->panel27->Controls->Add(this->label31);
			this->panel27->Location = System::Drawing::Point(1337, 401);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(142, 38);
			this->panel27->TabIndex = 37;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->BackColor = System::Drawing::Color::Yellow;
			this->label31->Location = System::Drawing::Point(14, 12);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(31, 15);
			this->label31->TabIndex = 0;
			this->label31->Text = L"R26";
			// 
			// panel28
			// 
			this->panel28->BackColor = System::Drawing::Color::Yellow;
			this->panel28->Controls->Add(this->label32);
			this->panel28->Location = System::Drawing::Point(1210, 401);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(121, 38);
			this->panel28->TabIndex = 38;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->BackColor = System::Drawing::Color::Yellow;
			this->label32->Location = System::Drawing::Point(14, 12);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(31, 15);
			this->label32->TabIndex = 0;
			this->label32->Text = L"R27";
			// 
			// panel29
			// 
			this->panel29->BackColor = System::Drawing::Color::Yellow;
			this->panel29->Controls->Add(this->label33);
			this->panel29->Location = System::Drawing::Point(1125, 325);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(77, 116);
			this->panel29->TabIndex = 39;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->BackColor = System::Drawing::Color::Yellow;
			this->label33->Location = System::Drawing::Point(14, 37);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(31, 15);
			this->label33->TabIndex = 0;
			this->label33->Text = L"R28";
			// 
			// panel30
			// 
			this->panel30->BackColor = System::Drawing::Color::Yellow;
			this->panel30->Controls->Add(this->label34);
			this->panel30->Location = System::Drawing::Point(1125, 211);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(77, 116);
			this->panel30->TabIndex = 40;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->BackColor = System::Drawing::Color::Yellow;
			this->label34->Location = System::Drawing::Point(14, 33);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(31, 15);
			this->label34->TabIndex = 0;
			this->label34->Text = L"R29";
			// 
			// panel31
			// 
			this->panel31->BackColor = System::Drawing::Color::Yellow;
			this->panel31->Controls->Add(this->label35);
			this->panel31->Location = System::Drawing::Point(1485, 445);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(163, 34);
			this->panel31->TabIndex = 41;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->BackColor = System::Drawing::Color::Yellow;
			this->label35->Location = System::Drawing::Point(14, 12);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(31, 15);
			this->label35->TabIndex = 0;
			this->label35->Text = L"R30";
			// 
			// panel32
			// 
			this->panel32->BackColor = System::Drawing::Color::Yellow;
			this->panel32->Controls->Add(this->label36);
			this->panel32->Location = System::Drawing::Point(1337, 445);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(142, 34);
			this->panel32->TabIndex = 42;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->BackColor = System::Drawing::Color::Yellow;
			this->label36->Location = System::Drawing::Point(14, 12);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(31, 15);
			this->label36->TabIndex = 0;
			this->label36->Text = L"R31";
			// 
			// panel33
			// 
			this->panel33->BackColor = System::Drawing::Color::Yellow;
			this->panel33->Controls->Add(this->label37);
			this->panel33->Location = System::Drawing::Point(1210, 445);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(121, 34);
			this->panel33->TabIndex = 43;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->BackColor = System::Drawing::Color::Yellow;
			this->label37->Location = System::Drawing::Point(14, 12);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(31, 15);
			this->label37->TabIndex = 0;
			this->label37->Text = L"R32";
			// 
			// panel34
			// 
			this->panel34->BackColor = System::Drawing::Color::Yellow;
			this->panel34->Controls->Add(this->label38);
			this->panel34->Location = System::Drawing::Point(1045, 445);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(159, 34);
			this->panel34->TabIndex = 44;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->BackColor = System::Drawing::Color::Yellow;
			this->label38->Location = System::Drawing::Point(14, 12);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(31, 15);
			this->label38->TabIndex = 0;
			this->label38->Text = L"R33";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(614, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1262, 809);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// panel35
			// 
			this->panel35->BackColor = System::Drawing::Color::Yellow;
			this->panel35->Controls->Add(this->label39);
			this->panel35->Location = System::Drawing::Point(1045, 325);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(74, 114);
			this->panel35->TabIndex = 45;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->BackColor = System::Drawing::Color::Yellow;
			this->label39->Location = System::Drawing::Point(10, 30);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(31, 15);
			this->label39->TabIndex = 0;
			this->label39->Text = L"R34";
			// 
			// panel36
			// 
			this->panel36->BackColor = System::Drawing::Color::Yellow;
			this->panel36->Controls->Add(this->label40);
			this->panel36->Location = System::Drawing::Point(1045, 211);
			this->panel36->Name = L"panel36";
			this->panel36->Size = System::Drawing::Size(74, 116);
			this->panel36->TabIndex = 46;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->BackColor = System::Drawing::Color::Yellow;
			this->label40->Location = System::Drawing::Point(10, 30);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(31, 15);
			this->label40->TabIndex = 0;
			this->label40->Text = L"R35";
			// 
			// panel37
			// 
			this->panel37->BackColor = System::Drawing::Color::Yellow;
			this->panel37->Controls->Add(this->label41);
			this->panel37->Location = System::Drawing::Point(940, 211);
			this->panel37->Name = L"panel37";
			this->panel37->Size = System::Drawing::Size(47, 78);
			this->panel37->TabIndex = 47;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->BackColor = System::Drawing::Color::Yellow;
			this->label41->Location = System::Drawing::Point(10, 30);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(31, 15);
			this->label41->TabIndex = 0;
			this->label41->Text = L"R36";
			// 
			// panel38
			// 
			this->panel38->BackColor = System::Drawing::Color::Yellow;
			this->panel38->Controls->Add(this->label42);
			this->panel38->Location = System::Drawing::Point(993, 211);
			this->panel38->Name = L"panel38";
			this->panel38->Size = System::Drawing::Size(46, 78);
			this->panel38->TabIndex = 48;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->BackColor = System::Drawing::Color::Yellow;
			this->label42->Location = System::Drawing::Point(10, 30);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(31, 15);
			this->label42->TabIndex = 0;
			this->label42->Text = L"R37";
			// 
			// panel39
			// 
			this->panel39->BackColor = System::Drawing::Color::Yellow;
			this->panel39->Controls->Add(this->label43);
			this->panel39->Location = System::Drawing::Point(940, 295);
			this->panel39->Name = L"panel39";
			this->panel39->Size = System::Drawing::Size(47, 79);
			this->panel39->TabIndex = 49;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->BackColor = System::Drawing::Color::Yellow;
			this->label43->Location = System::Drawing::Point(10, 30);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(31, 15);
			this->label43->TabIndex = 0;
			this->label43->Text = L"R38";
			// 
			// panel40
			// 
			this->panel40->BackColor = System::Drawing::Color::Yellow;
			this->panel40->Controls->Add(this->label44);
			this->panel40->Location = System::Drawing::Point(993, 295);
			this->panel40->Name = L"panel40";
			this->panel40->Size = System::Drawing::Size(46, 79);
			this->panel40->TabIndex = 50;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->BackColor = System::Drawing::Color::Yellow;
			this->label44->Location = System::Drawing::Point(10, 30);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(31, 15);
			this->label44->TabIndex = 0;
			this->label44->Text = L"R39";
			// 
			// panel41
			// 
			this->panel41->BackColor = System::Drawing::Color::Yellow;
			this->panel41->Controls->Add(this->label45);
			this->panel41->Location = System::Drawing::Point(940, 380);
			this->panel41->Name = L"panel41";
			this->panel41->Size = System::Drawing::Size(47, 99);
			this->panel41->TabIndex = 51;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->BackColor = System::Drawing::Color::Yellow;
			this->label45->Location = System::Drawing::Point(10, 30);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(31, 15);
			this->label45->TabIndex = 0;
			this->label45->Text = L"R40";
			// 
			// panel42
			// 
			this->panel42->BackColor = System::Drawing::Color::Yellow;
			this->panel42->Controls->Add(this->label46);
			this->panel42->Location = System::Drawing::Point(993, 380);
			this->panel42->Name = L"panel42";
			this->panel42->Size = System::Drawing::Size(46, 99);
			this->panel42->TabIndex = 52;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->BackColor = System::Drawing::Color::Yellow;
			this->label46->Location = System::Drawing::Point(10, 30);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(31, 15);
			this->label46->TabIndex = 0;
			this->label46->Text = L"R41";
			// 
			// panel43
			// 
			this->panel43->BackColor = System::Drawing::Color::Yellow;
			this->panel43->Controls->Add(this->label47);
			this->panel43->Location = System::Drawing::Point(1284, 652);
			this->panel43->Name = L"panel43";
			this->panel43->Size = System::Drawing::Size(57, 99);
			this->panel43->TabIndex = 53;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->BackColor = System::Drawing::Color::Yellow;
			this->label47->Location = System::Drawing::Point(10, 30);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(31, 15);
			this->label47->TabIndex = 0;
			this->label47->Text = L"R42";
			// 
			// panel44
			// 
			this->panel44->BackColor = System::Drawing::Color::Yellow;
			this->panel44->Controls->Add(this->label48);
			this->panel44->Location = System::Drawing::Point(1284, 575);
			this->panel44->Name = L"panel44";
			this->panel44->Size = System::Drawing::Size(57, 82);
			this->panel44->TabIndex = 54;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->BackColor = System::Drawing::Color::Yellow;
			this->label48->Location = System::Drawing::Point(10, 30);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(31, 15);
			this->label48->TabIndex = 0;
			this->label48->Text = L"R43";
			// 
			// panel45
			// 
			this->panel45->BackColor = System::Drawing::Color::Yellow;
			this->panel45->Controls->Add(this->label49);
			this->panel45->Location = System::Drawing::Point(1347, 575);
			this->panel45->Name = L"panel45";
			this->panel45->Size = System::Drawing::Size(119, 45);
			this->panel45->TabIndex = 55;
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->BackColor = System::Drawing::Color::Yellow;
			this->label49->Location = System::Drawing::Point(34, 15);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(31, 15);
			this->label49->TabIndex = 0;
			this->label49->Text = L"R44";
			// 
			// panel46
			// 
			this->panel46->BackColor = System::Drawing::Color::Yellow;
			this->panel46->Controls->Add(this->label50);
			this->panel46->Location = System::Drawing::Point(1472, 575);
			this->panel46->Name = L"panel46";
			this->panel46->Size = System::Drawing::Size(98, 45);
			this->panel46->TabIndex = 56;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->BackColor = System::Drawing::Color::Yellow;
			this->label50->Location = System::Drawing::Point(34, 15);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(31, 15);
			this->label50->TabIndex = 0;
			this->label50->Text = L"R45";
			// 
			// panel47
			// 
			this->panel47->BackColor = System::Drawing::Color::Yellow;
			this->panel47->Controls->Add(this->label51);
			this->panel47->Location = System::Drawing::Point(1580, 575);
			this->panel47->Name = L"panel47";
			this->panel47->Size = System::Drawing::Size(98, 45);
			this->panel47->TabIndex = 57;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->BackColor = System::Drawing::Color::Yellow;
			this->label51->Location = System::Drawing::Point(34, 15);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(31, 15);
			this->label51->TabIndex = 0;
			this->label51->Text = L"R46";
			// 
			// panel48
			// 
			this->panel48->BackColor = System::Drawing::Color::Yellow;
			this->panel48->Controls->Add(this->label52);
			this->panel48->Location = System::Drawing::Point(1684, 575);
			this->panel48->Name = L"panel48";
			this->panel48->Size = System::Drawing::Size(82, 45);
			this->panel48->TabIndex = 58;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->BackColor = System::Drawing::Color::Yellow;
			this->label52->Location = System::Drawing::Point(18, 15);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(31, 15);
			this->label52->TabIndex = 0;
			this->label52->Text = L"R47";
			// 
			// panel49
			// 
			this->panel49->BackColor = System::Drawing::Color::Yellow;
			this->panel49->Controls->Add(this->label53);
			this->panel49->Location = System::Drawing::Point(1724, 616);
			this->panel49->Name = L"panel49";
			this->panel49->Size = System::Drawing::Size(42, 81);
			this->panel49->TabIndex = 59;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->BackColor = System::Drawing::Color::Yellow;
			this->label53->Location = System::Drawing::Point(7, 26);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(31, 15);
			this->label53->TabIndex = 0;
			this->label53->Text = L"R48";
			// 
			// panel50
			// 
			this->panel50->BackColor = System::Drawing::Color::Yellow;
			this->panel50->Controls->Add(this->label54);
			this->panel50->Location = System::Drawing::Point(1772, 640);
			this->panel50->Name = L"panel50";
			this->panel50->Size = System::Drawing::Size(54, 57);
			this->panel50->TabIndex = 60;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->BackColor = System::Drawing::Color::Yellow;
			this->label54->Location = System::Drawing::Point(10, 26);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(31, 15);
			this->label54->TabIndex = 0;
			this->label54->Text = L"R49";
			// 
			// panel51
			// 
			this->panel51->BackColor = System::Drawing::Color::Yellow;
			this->panel51->Controls->Add(this->label55);
			this->panel51->Location = System::Drawing::Point(1832, 575);
			this->panel51->Name = L"panel51";
			this->panel51->Size = System::Drawing::Size(44, 122);
			this->panel51->TabIndex = 61;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->BackColor = System::Drawing::Color::Yellow;
			this->label55->Location = System::Drawing::Point(7, 26);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(31, 15);
			this->label55->TabIndex = 0;
			this->label55->Text = L"R50";
			// 
			// panel52
			// 
			this->panel52->BackColor = System::Drawing::Color::Yellow;
			this->panel52->Controls->Add(this->label56);
			this->panel52->Location = System::Drawing::Point(1732, 524);
			this->panel52->Name = L"panel52";
			this->panel52->Size = System::Drawing::Size(144, 45);
			this->panel52->TabIndex = 62;
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->BackColor = System::Drawing::Color::Yellow;
			this->label56->Location = System::Drawing::Point(28, 12);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(31, 15);
			this->label56->TabIndex = 0;
			this->label56->Text = L"R51";
			// 
			// panel53
			// 
			this->panel53->BackColor = System::Drawing::Color::Yellow;
			this->panel53->Controls->Add(this->label57);
			this->panel53->Location = System::Drawing::Point(1580, 524);
			this->panel53->Name = L"panel53";
			this->panel53->Size = System::Drawing::Size(147, 45);
			this->panel53->TabIndex = 63;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->BackColor = System::Drawing::Color::Yellow;
			this->label57->Location = System::Drawing::Point(61, 12);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(31, 15);
			this->label57->TabIndex = 0;
			this->label57->Text = L"R52";
			// 
			// panel54
			// 
			this->panel54->BackColor = System::Drawing::Color::Yellow;
			this->panel54->Controls->Add(this->label58);
			this->panel54->Location = System::Drawing::Point(1472, 524);
			this->panel54->Name = L"panel54";
			this->panel54->Size = System::Drawing::Size(102, 45);
			this->panel54->TabIndex = 64;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->BackColor = System::Drawing::Color::Yellow;
			this->label58->Location = System::Drawing::Point(28, 12);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(31, 15);
			this->label58->TabIndex = 0;
			this->label58->Text = L"R53";
			// 
			// panel55
			// 
			this->panel55->BackColor = System::Drawing::Color::Yellow;
			this->panel55->Controls->Add(this->label59);
			this->panel55->Location = System::Drawing::Point(1347, 524);
			this->panel55->Name = L"panel55";
			this->panel55->Size = System::Drawing::Size(114, 45);
			this->panel55->TabIndex = 65;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->BackColor = System::Drawing::Color::Yellow;
			this->label59->Location = System::Drawing::Point(28, 12);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(31, 15);
			this->label59->TabIndex = 0;
			this->label59->Text = L"R54";
			// 
			// panel56
			// 
			this->panel56->BackColor = System::Drawing::Color::Yellow;
			this->panel56->Controls->Add(this->label60);
			this->panel56->Location = System::Drawing::Point(1210, 524);
			this->panel56->Name = L"panel56";
			this->panel56->Size = System::Drawing::Size(131, 45);
			this->panel56->TabIndex = 66;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->BackColor = System::Drawing::Color::Yellow;
			this->label60->Location = System::Drawing::Point(28, 12);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(31, 15);
			this->label60->TabIndex = 0;
			this->label60->Text = L"R55";
			// 
			// panel57
			// 
			this->panel57->BackColor = System::Drawing::Color::Yellow;
			this->panel57->Controls->Add(this->label61);
			this->panel57->Location = System::Drawing::Point(1210, 575);
			this->panel57->Name = L"panel57";
			this->panel57->Size = System::Drawing::Size(67, 176);
			this->panel57->TabIndex = 67;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->BackColor = System::Drawing::Color::Yellow;
			this->label61->Location = System::Drawing::Point(13, 19);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(31, 15);
			this->label61->TabIndex = 0;
			this->label61->Text = L"R56";
			// 
			// panel58
			// 
			this->panel58->BackColor = System::Drawing::Color::Yellow;
			this->panel58->Controls->Add(this->label62);
			this->panel58->Location = System::Drawing::Point(1211, 757);
			this->panel58->Name = L"panel58";
			this->panel58->Size = System::Drawing::Size(130, 45);
			this->panel58->TabIndex = 68;
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->BackColor = System::Drawing::Color::Yellow;
			this->label62->Location = System::Drawing::Point(28, 12);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(31, 15);
			this->label62->TabIndex = 0;
			this->label62->Text = L"R57";
			// 
			// showRoadStatusForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1924, 858);
			this->Controls->Add(this->panel58);
			this->Controls->Add(this->panel57);
			this->Controls->Add(this->panel56);
			this->Controls->Add(this->panel55);
			this->Controls->Add(this->panel54);
			this->Controls->Add(this->panel53);
			this->Controls->Add(this->panel52);
			this->Controls->Add(this->panel51);
			this->Controls->Add(this->panel50);
			this->Controls->Add(this->panel49);
			this->Controls->Add(this->panel48);
			this->Controls->Add(this->panel47);
			this->Controls->Add(this->panel46);
			this->Controls->Add(this->panel45);
			this->Controls->Add(this->panel44);
			this->Controls->Add(this->panel43);
			this->Controls->Add(this->panel42);
			this->Controls->Add(this->panel41);
			this->Controls->Add(this->panel40);
			this->Controls->Add(this->panel39);
			this->Controls->Add(this->panel38);
			this->Controls->Add(this->panel37);
			this->Controls->Add(this->panel36);
			this->Controls->Add(this->panel35);
			this->Controls->Add(this->panel34);
			this->Controls->Add(this->panel33);
			this->Controls->Add(this->panel32);
			this->Controls->Add(this->panel31);
			this->Controls->Add(this->panel30);
			this->Controls->Add(this->panel29);
			this->Controls->Add(this->panel28);
			this->Controls->Add(this->panel27);
			this->Controls->Add(this->panel26);
			this->Controls->Add(this->panel25);
			this->Controls->Add(this->panel24);
			this->Controls->Add(this->panel23);
			this->Controls->Add(this->panel22);
			this->Controls->Add(this->panel21);
			this->Controls->Add(this->panel20);
			this->Controls->Add(this->panel19);
			this->Controls->Add(this->panel18);
			this->Controls->Add(this->panel17);
			this->Controls->Add(this->panel16);
			this->Controls->Add(this->panel15);
			this->Controls->Add(this->panel14);
			this->Controls->Add(this->panel13);
			this->Controls->Add(this->panel12);
			this->Controls->Add(this->panel11);
			this->Controls->Add(this->panel10);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"showRoadStatusForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"查看便道状态";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->panel14->ResumeLayout(false);
			this->panel14->PerformLayout();
			this->panel15->ResumeLayout(false);
			this->panel15->PerformLayout();
			this->panel16->ResumeLayout(false);
			this->panel16->PerformLayout();
			this->panel17->ResumeLayout(false);
			this->panel17->PerformLayout();
			this->panel18->ResumeLayout(false);
			this->panel18->PerformLayout();
			this->panel19->ResumeLayout(false);
			this->panel19->PerformLayout();
			this->panel20->ResumeLayout(false);
			this->panel20->PerformLayout();
			this->panel21->ResumeLayout(false);
			this->panel21->PerformLayout();
			this->panel22->ResumeLayout(false);
			this->panel22->PerformLayout();
			this->panel23->ResumeLayout(false);
			this->panel23->PerformLayout();
			this->panel24->ResumeLayout(false);
			this->panel24->PerformLayout();
			this->panel25->ResumeLayout(false);
			this->panel25->PerformLayout();
			this->panel26->ResumeLayout(false);
			this->panel26->PerformLayout();
			this->panel27->ResumeLayout(false);
			this->panel27->PerformLayout();
			this->panel28->ResumeLayout(false);
			this->panel28->PerformLayout();
			this->panel29->ResumeLayout(false);
			this->panel29->PerformLayout();
			this->panel30->ResumeLayout(false);
			this->panel30->PerformLayout();
			this->panel31->ResumeLayout(false);
			this->panel31->PerformLayout();
			this->panel32->ResumeLayout(false);
			this->panel32->PerformLayout();
			this->panel33->ResumeLayout(false);
			this->panel33->PerformLayout();
			this->panel34->ResumeLayout(false);
			this->panel34->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel35->ResumeLayout(false);
			this->panel35->PerformLayout();
			this->panel36->ResumeLayout(false);
			this->panel36->PerformLayout();
			this->panel37->ResumeLayout(false);
			this->panel37->PerformLayout();
			this->panel38->ResumeLayout(false);
			this->panel38->PerformLayout();
			this->panel39->ResumeLayout(false);
			this->panel39->PerformLayout();
			this->panel40->ResumeLayout(false);
			this->panel40->PerformLayout();
			this->panel41->ResumeLayout(false);
			this->panel41->PerformLayout();
			this->panel42->ResumeLayout(false);
			this->panel42->PerformLayout();
			this->panel43->ResumeLayout(false);
			this->panel43->PerformLayout();
			this->panel44->ResumeLayout(false);
			this->panel44->PerformLayout();
			this->panel45->ResumeLayout(false);
			this->panel45->PerformLayout();
			this->panel46->ResumeLayout(false);
			this->panel46->PerformLayout();
			this->panel47->ResumeLayout(false);
			this->panel47->PerformLayout();
			this->panel48->ResumeLayout(false);
			this->panel48->PerformLayout();
			this->panel49->ResumeLayout(false);
			this->panel49->PerformLayout();
			this->panel50->ResumeLayout(false);
			this->panel50->PerformLayout();
			this->panel51->ResumeLayout(false);
			this->panel51->PerformLayout();
			this->panel52->ResumeLayout(false);
			this->panel52->PerformLayout();
			this->panel53->ResumeLayout(false);
			this->panel53->PerformLayout();
			this->panel54->ResumeLayout(false);
			this->panel54->PerformLayout();
			this->panel55->ResumeLayout(false);
			this->panel55->PerformLayout();
			this->panel56->ResumeLayout(false);
			this->panel56->PerformLayout();
			this->panel57->ResumeLayout(false);
			this->panel57->PerformLayout();
			this->panel58->ResumeLayout(false);
			this->panel58->PerformLayout();
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
						fp1 = fopen("查询线路坐标.txt", "r");
						while (1)
						{
							fscanf(fp1, "%d", &x);
							fscanf(fp1, "%d", &y);
							if (x < 0)
								break;
							if (arr[x][y] == 2)
							{
								textBox2->Text += "R";
								if (index < 9){
									textBox2->Text += "0";
								}
								textBox2->Text += index;
								textBox2->Text += " ";
								index++;
								/*free++;
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
								textBox2->Text += " ";*/
							}
							else{
								if (index == 0){
									this->panel1->BackColor = System::Drawing::SystemColors::Desktop;
								}if (index == 1){
									this->panel2->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 2){
									this->panel3->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 3){
									this->panel4->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 4){
									this->panel5->BackColor = System::Drawing::SystemColors::Desktop;
								}if (index == 5){
									this->panel6->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 6){
									this->panel7->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 7){
									this->panel8->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 8){
									this->panel9->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 9){
									this->panel10->BackColor = System::Drawing::SystemColors::Desktop;
								}  if (index == 10){
									this->panel11->BackColor = System::Drawing::SystemColors::Desktop;
								}if (index == 11){
									this->panel12->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 12){
									this->panel13->BackColor = System::Drawing::SystemColors::Desktop;
								}  if (index == 13){
									this->panel14->BackColor = System::Drawing::SystemColors::Desktop;
								}if (index == 14){
									this->panel15->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 15){
									this->panel16->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 16){
									this->panel17->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 17){
									this->panel18->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 18){
									this->panel19->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 19){
									this->panel20->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 20){
									this->panel21->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 21){
									this->panel22->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 22){
									this->panel23->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 23){
									this->panel24->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 24){
									this->panel25->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 25){
									this->panel26->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 26){
									this->panel27->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 27){
									this->panel28->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 28){
									this->panel29->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 29){
									this->panel30->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 30){
									this->panel31->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 31){
									this->panel32->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 32){
									this->panel33->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 33){
									this->panel34->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 34){
									this->panel35->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 35){
									this->panel36->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 36){
									this->panel37->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 37){
									this->panel38->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 38){
									this->panel39->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 39){
									this->panel40->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 40){
									this->panel41->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 41){
									this->panel42->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 42){
									this->panel43->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 43){
									this->panel44->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 44){
									this->panel45->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 45){
									this->panel46->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 46){
									this->panel47->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 47){
									this->panel48->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 48){
									this->panel49->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 49){
									this->panel50->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 50){
									this->panel51->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 51){
									this->panel52->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 52){
									this->panel53->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 53){
									this->panel54->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 54){
									this->panel55->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 55){
									this->panel56->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 56){
									this->panel57->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 57){
									this->panel58->BackColor = System::Drawing::SystemColors::Desktop;
								}
								textBox4->Text += "R";
								if (index < 9){
									textBox4->Text += "0";
								}
								textBox4->Text += index;
								textBox4->Text += " ";
								index++;

								/*textBox4->Text += "x";
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
								textBox4->Text += " ";*/
							}
						}
						
						fclose(fp1);			
			 }
	};
}
