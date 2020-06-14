#pragma once
#include<iostream>
#include<string>
#include<map>
#include"Comm.hpp"
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
	/// showSpaceStatusForm 摘要
	/// </summary>
	public ref class showSpaceStatusForm : public System::Windows::Forms::Form
	{
	public:
		showSpaceStatusForm(void)
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
		~showSpaceStatusForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox4;


	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel1;
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
private: System::Windows::Forms::Panel^  panel59;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Panel^  panel60;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Panel^  panel61;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Panel^  panel62;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Panel^  panel63;
private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Panel^  panel64;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Panel^  panel65;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Panel^  panel66;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Panel^  panel67;
private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::Panel^  panel68;
private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::Panel^  panel69;
private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::Panel^  panel70;
private: System::Windows::Forms::Label^  label74;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Panel^  panel71;
private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::Panel^  panel72;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::Panel^  panel73;
private: System::Windows::Forms::Label^  label77;
private: System::Windows::Forms::Panel^  panel74;
private: System::Windows::Forms::Label^  label78;
private: System::Windows::Forms::Panel^  panel75;
private: System::Windows::Forms::Label^  label79;
private: System::Windows::Forms::Panel^  panel76;
private: System::Windows::Forms::Label^  label80;
private: System::Windows::Forms::Panel^  panel77;
private: System::Windows::Forms::Label^  C76;
private: System::Windows::Forms::Panel^  panel78;
private: System::Windows::Forms::Label^  label81;
private: System::Windows::Forms::Panel^  panel79;
private: System::Windows::Forms::Label^  label82;
private: System::Windows::Forms::Panel^  panel80;
private: System::Windows::Forms::Label^  label83;
private: System::Windows::Forms::Panel^  panel81;
private: System::Windows::Forms::Label^  label84;
private: System::Windows::Forms::Panel^  panel82;
private: System::Windows::Forms::Label^  label85;
private: System::Windows::Forms::Panel^  panel83;
private: System::Windows::Forms::Label^  label86;
private: System::Windows::Forms::Panel^  panel84;
private: System::Windows::Forms::Label^  label87;
private: System::Windows::Forms::Panel^  panel85;
private: System::Windows::Forms::Label^  label88;
private: System::Windows::Forms::PictureBox^  pictureBox3;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(showSpaceStatusForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
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
			this->panel59 = (gcnew System::Windows::Forms::Panel());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->panel60 = (gcnew System::Windows::Forms::Panel());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->panel61 = (gcnew System::Windows::Forms::Panel());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->panel62 = (gcnew System::Windows::Forms::Panel());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->panel63 = (gcnew System::Windows::Forms::Panel());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->panel64 = (gcnew System::Windows::Forms::Panel());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->panel65 = (gcnew System::Windows::Forms::Panel());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->panel66 = (gcnew System::Windows::Forms::Panel());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->panel67 = (gcnew System::Windows::Forms::Panel());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->panel68 = (gcnew System::Windows::Forms::Panel());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->panel69 = (gcnew System::Windows::Forms::Panel());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->panel70 = (gcnew System::Windows::Forms::Panel());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel71 = (gcnew System::Windows::Forms::Panel());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->panel72 = (gcnew System::Windows::Forms::Panel());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->panel73 = (gcnew System::Windows::Forms::Panel());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->panel74 = (gcnew System::Windows::Forms::Panel());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->panel75 = (gcnew System::Windows::Forms::Panel());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->panel76 = (gcnew System::Windows::Forms::Panel());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->panel77 = (gcnew System::Windows::Forms::Panel());
			this->C76 = (gcnew System::Windows::Forms::Label());
			this->panel78 = (gcnew System::Windows::Forms::Panel());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->panel79 = (gcnew System::Windows::Forms::Panel());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->panel80 = (gcnew System::Windows::Forms::Panel());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->panel81 = (gcnew System::Windows::Forms::Panel());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->panel82 = (gcnew System::Windows::Forms::Panel());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->panel83 = (gcnew System::Windows::Forms::Panel());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->panel84 = (gcnew System::Windows::Forms::Panel());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->panel85 = (gcnew System::Windows::Forms::Panel());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
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
			this->panel59->SuspendLayout();
			this->panel60->SuspendLayout();
			this->panel61->SuspendLayout();
			this->panel62->SuspendLayout();
			this->panel63->SuspendLayout();
			this->panel64->SuspendLayout();
			this->panel65->SuspendLayout();
			this->panel66->SuspendLayout();
			this->panel67->SuspendLayout();
			this->panel68->SuspendLayout();
			this->panel69->SuspendLayout();
			this->panel70->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel71->SuspendLayout();
			this->panel72->SuspendLayout();
			this->panel73->SuspendLayout();
			this->panel74->SuspendLayout();
			this->panel75->SuspendLayout();
			this->panel76->SuspendLayout();
			this->panel77->SuspendLayout();
			this->panel78->SuspendLayout();
			this->panel79->SuspendLayout();
			this->panel80->SuspendLayout();
			this->panel81->SuspendLayout();
			this->panel82->SuspendLayout();
			this->panel83->SuspendLayout();
			this->panel84->SuspendLayout();
			this->panel85->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(38, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"空闲车位数量为：";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(247, 59);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &showSpaceStatusForm::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label3->Location = System::Drawing::Point(38, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(229, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"空闲车位坐标如下所示：";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(42, 192);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(543, 142);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &showSpaceStatusForm::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(38, 399);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(189, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"非空闲车位数量为：";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(247, 394);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 25);
			this->textBox3->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label4->Location = System::Drawing::Point(38, 479);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(249, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"非空闲车位坐标如下所示：";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(42, 548);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(543, 144);
			this->textBox4->TabIndex = 9;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Aqua;
			this->panel2->Controls->Add(this->label5);
			this->panel2->Location = System::Drawing::Point(791, 69);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(52, 48);
			this->panel2->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(18, 19);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 15);
			this->label5->TabIndex = 0;
			this->label5->Text = L"C01";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Aqua;
			this->pictureBox2->Location = System::Drawing::Point(1202, 441);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(643, 38);
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Aqua;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Location = System::Drawing::Point(726, 69);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(59, 48);
			this->panel1->TabIndex = 15;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &showSpaceStatusForm::panel1_Paint);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(15, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(31, 15);
			this->label6->TabIndex = 0;
			this->label6->Text = L"C00";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Aqua;
			this->panel3->Controls->Add(this->label7);
			this->panel3->Location = System::Drawing::Point(855, 69);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(59, 48);
			this->panel3->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(15, 19);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(31, 15);
			this->label7->TabIndex = 0;
			this->label7->Text = L"C02";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Aqua;
			this->panel4->Controls->Add(this->label8);
			this->panel4->Location = System::Drawing::Point(920, 69);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(59, 48);
			this->panel4->TabIndex = 17;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(15, 19);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 15);
			this->label8->TabIndex = 0;
			this->label8->Text = L"C03";
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Aqua;
			this->panel5->Controls->Add(this->label9);
			this->panel5->Location = System::Drawing::Point(988, 78);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(46, 39);
			this->panel5->TabIndex = 18;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(3, 15);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(31, 15);
			this->label9->TabIndex = 0;
			this->label9->Text = L"C04";
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Aqua;
			this->panel6->Controls->Add(this->label10);
			this->panel6->Location = System::Drawing::Point(988, 34);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(46, 50);
			this->panel6->TabIndex = 19;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(3, 15);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 15);
			this->label10->TabIndex = 0;
			this->label10->Text = L"C05";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Aqua;
			this->panel7->Controls->Add(this->label11);
			this->panel7->Location = System::Drawing::Point(1100, 78);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(46, 39);
			this->panel7->TabIndex = 20;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(3, 15);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(31, 15);
			this->label11->TabIndex = 0;
			this->label11->Text = L"C06";
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Aqua;
			this->panel8->Controls->Add(this->label12);
			this->panel8->Location = System::Drawing::Point(1100, 34);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(46, 39);
			this->panel8->TabIndex = 21;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(3, 15);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(31, 15);
			this->label12->TabIndex = 0;
			this->label12->Text = L"C07";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::Aqua;
			this->panel9->Controls->Add(this->label13);
			this->panel9->Location = System::Drawing::Point(1152, 78);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(46, 39);
			this->panel9->TabIndex = 22;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::White;
			this->label13->Location = System::Drawing::Point(3, 14);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(31, 15);
			this->label13->TabIndex = 0;
			this->label13->Text = L"C08";
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::Aqua;
			this->panel10->Controls->Add(this->label14);
			this->panel10->Location = System::Drawing::Point(1152, 34);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(46, 39);
			this->panel10->TabIndex = 23;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::White;
			this->label14->Location = System::Drawing::Point(3, 14);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(31, 15);
			this->label14->TabIndex = 0;
			this->label14->Text = L"C09";
			// 
			// panel11
			// 
			this->panel11->BackColor = System::Drawing::Color::Aqua;
			this->panel11->Controls->Add(this->label15);
			this->panel11->Location = System::Drawing::Point(1219, 78);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(46, 39);
			this->panel11->TabIndex = 24;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::White;
			this->label15->Location = System::Drawing::Point(3, 14);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(31, 15);
			this->label15->TabIndex = 0;
			this->label15->Text = L"C10";
			// 
			// panel12
			// 
			this->panel12->BackColor = System::Drawing::Color::Aqua;
			this->panel12->Controls->Add(this->label16);
			this->panel12->Location = System::Drawing::Point(1281, 78);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(46, 39);
			this->panel12->TabIndex = 25;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::White;
			this->label16->Location = System::Drawing::Point(3, 14);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(31, 15);
			this->label16->TabIndex = 0;
			this->label16->Text = L"C11";
			// 
			// panel13
			// 
			this->panel13->BackColor = System::Drawing::Color::Aqua;
			this->panel13->Controls->Add(this->label17);
			this->panel13->Location = System::Drawing::Point(1219, 34);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(46, 39);
			this->panel13->TabIndex = 26;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::White;
			this->label17->Location = System::Drawing::Point(3, 14);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(31, 15);
			this->label17->TabIndex = 0;
			this->label17->Text = L"C12";
			// 
			// panel14
			// 
			this->panel14->BackColor = System::Drawing::Color::Aqua;
			this->panel14->Controls->Add(this->label18);
			this->panel14->Location = System::Drawing::Point(1281, 34);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(46, 39);
			this->panel14->TabIndex = 27;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::White;
			this->label18->Location = System::Drawing::Point(3, 14);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(31, 15);
			this->label18->TabIndex = 0;
			this->label18->Text = L"C13";
			// 
			// panel15
			// 
			this->panel15->BackColor = System::Drawing::Color::Aqua;
			this->panel15->Controls->Add(this->label19);
			this->panel15->Location = System::Drawing::Point(1333, 34);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(46, 39);
			this->panel15->TabIndex = 28;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::White;
			this->label19->Location = System::Drawing::Point(3, 14);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(31, 15);
			this->label19->TabIndex = 0;
			this->label19->Text = L"C14";
			// 
			// panel16
			// 
			this->panel16->BackColor = System::Drawing::Color::Aqua;
			this->panel16->Controls->Add(this->label20);
			this->panel16->Location = System::Drawing::Point(1333, 78);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(46, 39);
			this->panel16->TabIndex = 29;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::Color::White;
			this->label20->Location = System::Drawing::Point(3, 14);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(31, 15);
			this->label20->TabIndex = 0;
			this->label20->Text = L"C15";
			// 
			// panel17
			// 
			this->panel17->BackColor = System::Drawing::Color::Aqua;
			this->panel17->Controls->Add(this->label21);
			this->panel17->Location = System::Drawing::Point(1385, 34);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(46, 39);
			this->panel17->TabIndex = 30;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->BackColor = System::Drawing::Color::White;
			this->label21->Location = System::Drawing::Point(3, 14);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(31, 15);
			this->label21->TabIndex = 0;
			this->label21->Text = L"C16";
			// 
			// panel18
			// 
			this->panel18->BackColor = System::Drawing::Color::Aqua;
			this->panel18->Controls->Add(this->label22);
			this->panel18->Location = System::Drawing::Point(1385, 78);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(46, 39);
			this->panel18->TabIndex = 31;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->BackColor = System::Drawing::Color::White;
			this->label22->Location = System::Drawing::Point(3, 14);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(31, 15);
			this->label22->TabIndex = 0;
			this->label22->Text = L"C17";
			// 
			// panel19
			// 
			this->panel19->BackColor = System::Drawing::Color::Aqua;
			this->panel19->Controls->Add(this->label23);
			this->panel19->Location = System::Drawing::Point(1437, 34);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(46, 39);
			this->panel19->TabIndex = 32;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->BackColor = System::Drawing::Color::White;
			this->label23->Location = System::Drawing::Point(3, 14);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(31, 15);
			this->label23->TabIndex = 0;
			this->label23->Text = L"C18";
			// 
			// panel20
			// 
			this->panel20->BackColor = System::Drawing::Color::Aqua;
			this->panel20->Controls->Add(this->label24);
			this->panel20->Location = System::Drawing::Point(1495, 34);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(46, 39);
			this->panel20->TabIndex = 33;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->BackColor = System::Drawing::Color::White;
			this->label24->Location = System::Drawing::Point(3, 14);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(31, 15);
			this->label24->TabIndex = 0;
			this->label24->Text = L"C19";
			// 
			// panel21
			// 
			this->panel21->BackColor = System::Drawing::Color::Aqua;
			this->panel21->Controls->Add(this->label25);
			this->panel21->Location = System::Drawing::Point(1437, 79);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(46, 39);
			this->panel21->TabIndex = 34;
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->BackColor = System::Drawing::Color::White;
			this->label25->Location = System::Drawing::Point(3, 14);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(31, 15);
			this->label25->TabIndex = 0;
			this->label25->Text = L"C20";
			// 
			// panel22
			// 
			this->panel22->BackColor = System::Drawing::Color::Aqua;
			this->panel22->Controls->Add(this->label26);
			this->panel22->Location = System::Drawing::Point(1495, 78);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(46, 39);
			this->panel22->TabIndex = 35;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->BackColor = System::Drawing::Color::White;
			this->label26->Location = System::Drawing::Point(3, 14);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(31, 15);
			this->label26->TabIndex = 0;
			this->label26->Text = L"C21";
			// 
			// panel23
			// 
			this->panel23->BackColor = System::Drawing::Color::Aqua;
			this->panel23->Controls->Add(this->label27);
			this->panel23->Location = System::Drawing::Point(1559, 34);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(46, 39);
			this->panel23->TabIndex = 36;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->BackColor = System::Drawing::Color::White;
			this->label27->Location = System::Drawing::Point(3, 14);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(31, 15);
			this->label27->TabIndex = 0;
			this->label27->Text = L"C22";
			// 
			// panel24
			// 
			this->panel24->BackColor = System::Drawing::Color::Aqua;
			this->panel24->Controls->Add(this->label28);
			this->panel24->Location = System::Drawing::Point(1622, 34);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(46, 39);
			this->panel24->TabIndex = 37;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->BackColor = System::Drawing::Color::White;
			this->label28->Location = System::Drawing::Point(3, 14);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(31, 15);
			this->label28->TabIndex = 0;
			this->label28->Text = L"C23";
			// 
			// panel25
			// 
			this->panel25->BackColor = System::Drawing::Color::Aqua;
			this->panel25->Controls->Add(this->label29);
			this->panel25->Location = System::Drawing::Point(1559, 78);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(46, 39);
			this->panel25->TabIndex = 38;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->BackColor = System::Drawing::Color::White;
			this->label29->Location = System::Drawing::Point(3, 14);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(31, 15);
			this->label29->TabIndex = 0;
			this->label29->Text = L"C24";
			// 
			// panel26
			// 
			this->panel26->BackColor = System::Drawing::Color::Aqua;
			this->panel26->Controls->Add(this->label30);
			this->panel26->Location = System::Drawing::Point(1622, 79);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(46, 39);
			this->panel26->TabIndex = 39;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->BackColor = System::Drawing::Color::White;
			this->label30->Location = System::Drawing::Point(3, 14);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(31, 15);
			this->label30->TabIndex = 0;
			this->label30->Text = L"C25";
			// 
			// panel27
			// 
			this->panel27->BackColor = System::Drawing::Color::Aqua;
			this->panel27->Controls->Add(this->label31);
			this->panel27->Location = System::Drawing::Point(1711, 34);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(46, 39);
			this->panel27->TabIndex = 40;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->BackColor = System::Drawing::Color::White;
			this->label31->Location = System::Drawing::Point(3, 14);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(31, 15);
			this->label31->TabIndex = 0;
			this->label31->Text = L"C26";
			// 
			// panel28
			// 
			this->panel28->BackColor = System::Drawing::Color::Aqua;
			this->panel28->Controls->Add(this->label32);
			this->panel28->Location = System::Drawing::Point(1773, 34);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(46, 39);
			this->panel28->TabIndex = 41;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->BackColor = System::Drawing::Color::White;
			this->label32->Location = System::Drawing::Point(3, 14);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(31, 15);
			this->label32->TabIndex = 0;
			this->label32->Text = L"C27";
			// 
			// panel29
			// 
			this->panel29->BackColor = System::Drawing::Color::Aqua;
			this->panel29->Controls->Add(this->label33);
			this->panel29->Location = System::Drawing::Point(1843, 34);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(46, 39);
			this->panel29->TabIndex = 42;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->BackColor = System::Drawing::Color::White;
			this->label33->Location = System::Drawing::Point(3, 14);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(31, 15);
			this->label33->TabIndex = 0;
			this->label33->Text = L"C28";
			// 
			// panel30
			// 
			this->panel30->BackColor = System::Drawing::Color::Aqua;
			this->panel30->Controls->Add(this->label34);
			this->panel30->Location = System::Drawing::Point(1843, 78);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(46, 39);
			this->panel30->TabIndex = 43;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->BackColor = System::Drawing::Color::White;
			this->label34->Location = System::Drawing::Point(3, 14);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(31, 15);
			this->label34->TabIndex = 0;
			this->label34->Text = L"C29";
			// 
			// panel31
			// 
			this->panel31->BackColor = System::Drawing::Color::Aqua;
			this->panel31->Controls->Add(this->label35);
			this->panel31->Location = System::Drawing::Point(1843, 123);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(46, 39);
			this->panel31->TabIndex = 44;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->BackColor = System::Drawing::Color::White;
			this->label35->Location = System::Drawing::Point(3, 14);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(31, 15);
			this->label35->TabIndex = 0;
			this->label35->Text = L"C30";
			// 
			// panel32
			// 
			this->panel32->BackColor = System::Drawing::Color::Aqua;
			this->panel32->Controls->Add(this->label36);
			this->panel32->Location = System::Drawing::Point(1843, 168);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(46, 39);
			this->panel32->TabIndex = 45;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->BackColor = System::Drawing::Color::White;
			this->label36->Location = System::Drawing::Point(3, 14);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(31, 15);
			this->label36->TabIndex = 0;
			this->label36->Text = L"C31";
			// 
			// panel33
			// 
			this->panel33->BackColor = System::Drawing::Color::Aqua;
			this->panel33->Controls->Add(this->label37);
			this->panel33->Location = System::Drawing::Point(1843, 213);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(46, 39);
			this->panel33->TabIndex = 46;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->BackColor = System::Drawing::Color::White;
			this->label37->Location = System::Drawing::Point(3, 14);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(31, 15);
			this->label37->TabIndex = 0;
			this->label37->Text = L"C32";
			// 
			// panel34
			// 
			this->panel34->BackColor = System::Drawing::Color::Aqua;
			this->panel34->Controls->Add(this->label38);
			this->panel34->Location = System::Drawing::Point(1843, 258);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(46, 39);
			this->panel34->TabIndex = 47;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->BackColor = System::Drawing::Color::White;
			this->label38->Location = System::Drawing::Point(3, 14);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(31, 15);
			this->label38->TabIndex = 0;
			this->label38->Text = L"C33";
			// 
			// panel35
			// 
			this->panel35->BackColor = System::Drawing::Color::Aqua;
			this->panel35->Controls->Add(this->label39);
			this->panel35->Location = System::Drawing::Point(1843, 303);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(46, 39);
			this->panel35->TabIndex = 48;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->BackColor = System::Drawing::Color::White;
			this->label39->Location = System::Drawing::Point(3, 14);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(31, 15);
			this->label39->TabIndex = 0;
			this->label39->Text = L"C34";
			// 
			// panel36
			// 
			this->panel36->BackColor = System::Drawing::Color::Aqua;
			this->panel36->Controls->Add(this->label40);
			this->panel36->Location = System::Drawing::Point(1843, 348);
			this->panel36->Name = L"panel36";
			this->panel36->Size = System::Drawing::Size(46, 39);
			this->panel36->TabIndex = 49;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->BackColor = System::Drawing::Color::White;
			this->label40->Location = System::Drawing::Point(3, 14);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(31, 15);
			this->label40->TabIndex = 0;
			this->label40->Text = L"C35";
			// 
			// panel37
			// 
			this->panel37->BackColor = System::Drawing::Color::Aqua;
			this->panel37->Controls->Add(this->label41);
			this->panel37->Location = System::Drawing::Point(1843, 396);
			this->panel37->Name = L"panel37";
			this->panel37->Size = System::Drawing::Size(46, 39);
			this->panel37->TabIndex = 50;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->BackColor = System::Drawing::Color::White;
			this->label41->Location = System::Drawing::Point(3, 14);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(31, 15);
			this->label41->TabIndex = 0;
			this->label41->Text = L"C36";
			// 
			// panel38
			// 
			this->panel38->BackColor = System::Drawing::Color::Aqua;
			this->panel38->Controls->Add(this->label42);
			this->panel38->Location = System::Drawing::Point(1843, 440);
			this->panel38->Name = L"panel38";
			this->panel38->Size = System::Drawing::Size(46, 39);
			this->panel38->TabIndex = 51;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->BackColor = System::Drawing::Color::White;
			this->label42->Location = System::Drawing::Point(3, 14);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(31, 15);
			this->label42->TabIndex = 0;
			this->label42->Text = L"C37";
			// 
			// panel39
			// 
			this->panel39->BackColor = System::Drawing::Color::Aqua;
			this->panel39->Controls->Add(this->label43);
			this->panel39->Location = System::Drawing::Point(1797, 441);
			this->panel39->Name = L"panel39";
			this->panel39->Size = System::Drawing::Size(40, 38);
			this->panel39->TabIndex = 52;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->BackColor = System::Drawing::Color::White;
			this->label43->Location = System::Drawing::Point(3, 14);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(31, 15);
			this->label43->TabIndex = 0;
			this->label43->Text = L"C38";
			// 
			// panel40
			// 
			this->panel40->BackColor = System::Drawing::Color::Aqua;
			this->panel40->Controls->Add(this->label44);
			this->panel40->Location = System::Drawing::Point(1751, 441);
			this->panel40->Name = L"panel40";
			this->panel40->Size = System::Drawing::Size(40, 38);
			this->panel40->TabIndex = 53;
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->BackColor = System::Drawing::Color::White;
			this->label44->Location = System::Drawing::Point(3, 14);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(31, 15);
			this->label44->TabIndex = 0;
			this->label44->Text = L"C39";
			// 
			// panel41
			// 
			this->panel41->BackColor = System::Drawing::Color::Aqua;
			this->panel41->Controls->Add(this->label45);
			this->panel41->Location = System::Drawing::Point(1705, 441);
			this->panel41->Name = L"panel41";
			this->panel41->Size = System::Drawing::Size(40, 38);
			this->panel41->TabIndex = 54;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->BackColor = System::Drawing::Color::White;
			this->label45->Location = System::Drawing::Point(3, 14);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(31, 15);
			this->label45->TabIndex = 0;
			this->label45->Text = L"C40";
			// 
			// panel42
			// 
			this->panel42->BackColor = System::Drawing::Color::Aqua;
			this->panel42->Controls->Add(this->label46);
			this->panel42->Location = System::Drawing::Point(1484, 441);
			this->panel42->Name = L"panel42";
			this->panel42->Size = System::Drawing::Size(40, 38);
			this->panel42->TabIndex = 55;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->BackColor = System::Drawing::Color::White;
			this->label46->Location = System::Drawing::Point(3, 14);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(31, 15);
			this->label46->TabIndex = 0;
			this->label46->Text = L"C41";
			// 
			// panel43
			// 
			this->panel43->BackColor = System::Drawing::Color::Aqua;
			this->panel43->Controls->Add(this->label47);
			this->panel43->Location = System::Drawing::Point(1530, 441);
			this->panel43->Name = L"panel43";
			this->panel43->Size = System::Drawing::Size(40, 38);
			this->panel43->TabIndex = 56;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->BackColor = System::Drawing::Color::White;
			this->label47->Location = System::Drawing::Point(3, 14);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(31, 15);
			this->label47->TabIndex = 0;
			this->label47->Text = L"C42";
			// 
			// panel44
			// 
			this->panel44->BackColor = System::Drawing::Color::Aqua;
			this->panel44->Controls->Add(this->label48);
			this->panel44->Location = System::Drawing::Point(1573, 441);
			this->panel44->Name = L"panel44";
			this->panel44->Size = System::Drawing::Size(40, 38);
			this->panel44->TabIndex = 57;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->BackColor = System::Drawing::Color::White;
			this->label48->Location = System::Drawing::Point(3, 14);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(31, 15);
			this->label48->TabIndex = 0;
			this->label48->Text = L"C43";
			// 
			// panel45
			// 
			this->panel45->BackColor = System::Drawing::Color::Aqua;
			this->panel45->Controls->Add(this->label49);
			this->panel45->Location = System::Drawing::Point(1619, 440);
			this->panel45->Name = L"panel45";
			this->panel45->Size = System::Drawing::Size(40, 38);
			this->panel45->TabIndex = 58;
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->BackColor = System::Drawing::Color::White;
			this->label49->Location = System::Drawing::Point(3, 14);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(31, 15);
			this->label49->TabIndex = 0;
			this->label49->Text = L"C44";
			// 
			// panel46
			// 
			this->panel46->BackColor = System::Drawing::Color::Aqua;
			this->panel46->Controls->Add(this->label50);
			this->panel46->Location = System::Drawing::Point(1662, 441);
			this->panel46->Name = L"panel46";
			this->panel46->Size = System::Drawing::Size(40, 38);
			this->panel46->TabIndex = 59;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->BackColor = System::Drawing::Color::White;
			this->label50->Location = System::Drawing::Point(3, 14);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(31, 15);
			this->label50->TabIndex = 0;
			this->label50->Text = L"C45";
			// 
			// panel47
			// 
			this->panel47->BackColor = System::Drawing::Color::Aqua;
			this->panel47->Controls->Add(this->label51);
			this->panel47->Location = System::Drawing::Point(1312, 441);
			this->panel47->Name = L"panel47";
			this->panel47->Size = System::Drawing::Size(40, 38);
			this->panel47->TabIndex = 60;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->BackColor = System::Drawing::Color::White;
			this->label51->Location = System::Drawing::Point(3, 14);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(31, 15);
			this->label51->TabIndex = 0;
			this->label51->Text = L"C46";
			// 
			// panel48
			// 
			this->panel48->BackColor = System::Drawing::Color::Aqua;
			this->panel48->Controls->Add(this->label52);
			this->panel48->Location = System::Drawing::Point(1355, 441);
			this->panel48->Name = L"panel48";
			this->panel48->Size = System::Drawing::Size(40, 38);
			this->panel48->TabIndex = 61;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->BackColor = System::Drawing::Color::White;
			this->label52->Location = System::Drawing::Point(3, 14);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(31, 15);
			this->label52->TabIndex = 0;
			this->label52->Text = L"C47";
			// 
			// panel49
			// 
			this->panel49->BackColor = System::Drawing::Color::Aqua;
			this->panel49->Controls->Add(this->label53);
			this->panel49->Location = System::Drawing::Point(1398, 441);
			this->panel49->Name = L"panel49";
			this->panel49->Size = System::Drawing::Size(40, 38);
			this->panel49->TabIndex = 62;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->BackColor = System::Drawing::Color::White;
			this->label53->Location = System::Drawing::Point(3, 14);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(31, 15);
			this->label53->TabIndex = 0;
			this->label53->Text = L"C48";
			// 
			// panel50
			// 
			this->panel50->BackColor = System::Drawing::Color::Aqua;
			this->panel50->Controls->Add(this->label54);
			this->panel50->Location = System::Drawing::Point(1441, 441);
			this->panel50->Name = L"panel50";
			this->panel50->Size = System::Drawing::Size(40, 38);
			this->panel50->TabIndex = 63;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->BackColor = System::Drawing::Color::White;
			this->label54->Location = System::Drawing::Point(3, 14);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(31, 15);
			this->label54->TabIndex = 0;
			this->label54->Text = L"C49";
			// 
			// panel51
			// 
			this->panel51->BackColor = System::Drawing::Color::Aqua;
			this->panel51->Controls->Add(this->label55);
			this->panel51->Location = System::Drawing::Point(1190, 441);
			this->panel51->Name = L"panel51";
			this->panel51->Size = System::Drawing::Size(33, 38);
			this->panel51->TabIndex = 64;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->BackColor = System::Drawing::Color::White;
			this->label55->Location = System::Drawing::Point(3, 14);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(31, 15);
			this->label55->TabIndex = 0;
			this->label55->Text = L"C50";
			// 
			// panel52
			// 
			this->panel52->BackColor = System::Drawing::Color::Aqua;
			this->panel52->Controls->Add(this->label56);
			this->panel52->Location = System::Drawing::Point(1226, 441);
			this->panel52->Name = L"panel52";
			this->panel52->Size = System::Drawing::Size(40, 38);
			this->panel52->TabIndex = 65;
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->BackColor = System::Drawing::Color::White;
			this->label56->Location = System::Drawing::Point(3, 14);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(31, 15);
			this->label56->TabIndex = 0;
			this->label56->Text = L"C51";
			// 
			// panel53
			// 
			this->panel53->BackColor = System::Drawing::Color::Aqua;
			this->panel53->Controls->Add(this->label57);
			this->panel53->Location = System::Drawing::Point(1269, 441);
			this->panel53->Name = L"panel53";
			this->panel53->Size = System::Drawing::Size(40, 38);
			this->panel53->TabIndex = 66;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->BackColor = System::Drawing::Color::White;
			this->label57->Location = System::Drawing::Point(3, 14);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(31, 15);
			this->label57->TabIndex = 0;
			this->label57->Text = L"C52";
			// 
			// panel54
			// 
			this->panel54->BackColor = System::Drawing::Color::Aqua;
			this->panel54->Controls->Add(this->label58);
			this->panel54->Location = System::Drawing::Point(1220, 204);
			this->panel54->Name = L"panel54";
			this->panel54->Size = System::Drawing::Size(40, 38);
			this->panel54->TabIndex = 67;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->BackColor = System::Drawing::Color::White;
			this->label58->Location = System::Drawing::Point(3, 14);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(31, 15);
			this->label58->TabIndex = 0;
			this->label58->Text = L"C53";
			// 
			// panel55
			// 
			this->panel55->BackColor = System::Drawing::Color::Aqua;
			this->panel55->Controls->Add(this->label59);
			this->panel55->Location = System::Drawing::Point(1263, 204);
			this->panel55->Name = L"panel55";
			this->panel55->Size = System::Drawing::Size(40, 38);
			this->panel55->TabIndex = 68;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->BackColor = System::Drawing::Color::White;
			this->label59->Location = System::Drawing::Point(3, 14);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(31, 15);
			this->label59->TabIndex = 0;
			this->label59->Text = L"C54";
			// 
			// panel56
			// 
			this->panel56->BackColor = System::Drawing::Color::Aqua;
			this->panel56->Controls->Add(this->label60);
			this->panel56->Location = System::Drawing::Point(1306, 204);
			this->panel56->Name = L"panel56";
			this->panel56->Size = System::Drawing::Size(40, 38);
			this->panel56->TabIndex = 69;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->BackColor = System::Drawing::Color::White;
			this->label60->Location = System::Drawing::Point(3, 14);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(31, 15);
			this->label60->TabIndex = 0;
			this->label60->Text = L"C55";
			// 
			// panel57
			// 
			this->panel57->BackColor = System::Drawing::Color::Aqua;
			this->panel57->Controls->Add(this->label61);
			this->panel57->Location = System::Drawing::Point(1352, 204);
			this->panel57->Name = L"panel57";
			this->panel57->Size = System::Drawing::Size(40, 38);
			this->panel57->TabIndex = 70;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->BackColor = System::Drawing::Color::White;
			this->label61->Location = System::Drawing::Point(3, 14);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(31, 15);
			this->label61->TabIndex = 0;
			this->label61->Text = L"C56";
			// 
			// panel58
			// 
			this->panel58->BackColor = System::Drawing::Color::Aqua;
			this->panel58->Controls->Add(this->label62);
			this->panel58->Location = System::Drawing::Point(1398, 204);
			this->panel58->Name = L"panel58";
			this->panel58->Size = System::Drawing::Size(40, 38);
			this->panel58->TabIndex = 71;
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->BackColor = System::Drawing::Color::White;
			this->label62->Location = System::Drawing::Point(3, 14);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(31, 15);
			this->label62->TabIndex = 0;
			this->label62->Text = L"C57";
			// 
			// panel59
			// 
			this->panel59->BackColor = System::Drawing::Color::Aqua;
			this->panel59->Controls->Add(this->label63);
			this->panel59->Location = System::Drawing::Point(1443, 204);
			this->panel59->Name = L"panel59";
			this->panel59->Size = System::Drawing::Size(40, 38);
			this->panel59->TabIndex = 72;
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->BackColor = System::Drawing::Color::White;
			this->label63->Location = System::Drawing::Point(3, 14);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(31, 15);
			this->label63->TabIndex = 0;
			this->label63->Text = L"C58";
			// 
			// panel60
			// 
			this->panel60->BackColor = System::Drawing::Color::Aqua;
			this->panel60->Controls->Add(this->label64);
			this->panel60->Location = System::Drawing::Point(1487, 204);
			this->panel60->Name = L"panel60";
			this->panel60->Size = System::Drawing::Size(40, 38);
			this->panel60->TabIndex = 73;
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->BackColor = System::Drawing::Color::White;
			this->label64->Location = System::Drawing::Point(3, 14);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(31, 15);
			this->label64->TabIndex = 0;
			this->label64->Text = L"C59";
			// 
			// panel61
			// 
			this->panel61->BackColor = System::Drawing::Color::Aqua;
			this->panel61->Controls->Add(this->label65);
			this->panel61->Location = System::Drawing::Point(1530, 204);
			this->panel61->Name = L"panel61";
			this->panel61->Size = System::Drawing::Size(40, 38);
			this->panel61->TabIndex = 74;
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->BackColor = System::Drawing::Color::White;
			this->label65->Location = System::Drawing::Point(3, 14);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(31, 15);
			this->label65->TabIndex = 0;
			this->label65->Text = L"C60";
			// 
			// panel62
			// 
			this->panel62->BackColor = System::Drawing::Color::Aqua;
			this->panel62->Controls->Add(this->label66);
			this->panel62->Location = System::Drawing::Point(1573, 204);
			this->panel62->Name = L"panel62";
			this->panel62->Size = System::Drawing::Size(32, 38);
			this->panel62->TabIndex = 75;
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->BackColor = System::Drawing::Color::White;
			this->label66->Location = System::Drawing::Point(3, 14);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(31, 15);
			this->label66->TabIndex = 0;
			this->label66->Text = L"C61";
			// 
			// panel63
			// 
			this->panel63->BackColor = System::Drawing::Color::Aqua;
			this->panel63->Controls->Add(this->label67);
			this->panel63->Location = System::Drawing::Point(1573, 330);
			this->panel63->Name = L"panel63";
			this->panel63->Size = System::Drawing::Size(34, 38);
			this->panel63->TabIndex = 76;
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->BackColor = System::Drawing::Color::White;
			this->label67->Location = System::Drawing::Point(3, 14);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(31, 15);
			this->label67->TabIndex = 0;
			this->label67->Text = L"C62";
			// 
			// panel64
			// 
			this->panel64->BackColor = System::Drawing::Color::Aqua;
			this->panel64->Controls->Add(this->label68);
			this->panel64->Location = System::Drawing::Point(1401, 330);
			this->panel64->Name = L"panel64";
			this->panel64->Size = System::Drawing::Size(40, 38);
			this->panel64->TabIndex = 77;
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->BackColor = System::Drawing::Color::White;
			this->label68->Location = System::Drawing::Point(3, 14);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(31, 15);
			this->label68->TabIndex = 0;
			this->label68->Text = L"C63";
			// 
			// panel65
			// 
			this->panel65->BackColor = System::Drawing::Color::Aqua;
			this->panel65->Controls->Add(this->label69);
			this->panel65->Location = System::Drawing::Point(1444, 330);
			this->panel65->Name = L"panel65";
			this->panel65->Size = System::Drawing::Size(40, 38);
			this->panel65->TabIndex = 78;
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->BackColor = System::Drawing::Color::White;
			this->label69->Location = System::Drawing::Point(3, 14);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(31, 15);
			this->label69->TabIndex = 0;
			this->label69->Text = L"C64";
			// 
			// panel66
			// 
			this->panel66->BackColor = System::Drawing::Color::Aqua;
			this->panel66->Controls->Add(this->label70);
			this->panel66->Location = System::Drawing::Point(1487, 330);
			this->panel66->Name = L"panel66";
			this->panel66->Size = System::Drawing::Size(40, 38);
			this->panel66->TabIndex = 79;
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->BackColor = System::Drawing::Color::White;
			this->label70->Location = System::Drawing::Point(3, 14);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(31, 15);
			this->label70->TabIndex = 0;
			this->label70->Text = L"C65";
			// 
			// panel67
			// 
			this->panel67->BackColor = System::Drawing::Color::Aqua;
			this->panel67->Controls->Add(this->label71);
			this->panel67->Location = System::Drawing::Point(1530, 330);
			this->panel67->Name = L"panel67";
			this->panel67->Size = System::Drawing::Size(40, 38);
			this->panel67->TabIndex = 80;
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->BackColor = System::Drawing::Color::White;
			this->label71->Location = System::Drawing::Point(3, 14);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(31, 15);
			this->label71->TabIndex = 0;
			this->label71->Text = L"C66";
			// 
			// panel68
			// 
			this->panel68->BackColor = System::Drawing::Color::Aqua;
			this->panel68->Controls->Add(this->label72);
			this->panel68->Location = System::Drawing::Point(1220, 330);
			this->panel68->Name = L"panel68";
			this->panel68->Size = System::Drawing::Size(40, 38);
			this->panel68->TabIndex = 81;
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->BackColor = System::Drawing::Color::White;
			this->label72->Location = System::Drawing::Point(3, 14);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(31, 15);
			this->label72->TabIndex = 0;
			this->label72->Text = L"C67";
			// 
			// panel69
			// 
			this->panel69->BackColor = System::Drawing::Color::Aqua;
			this->panel69->Controls->Add(this->label73);
			this->panel69->Location = System::Drawing::Point(1263, 330);
			this->panel69->Name = L"panel69";
			this->panel69->Size = System::Drawing::Size(40, 38);
			this->panel69->TabIndex = 82;
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->BackColor = System::Drawing::Color::White;
			this->label73->Location = System::Drawing::Point(3, 14);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(31, 15);
			this->label73->TabIndex = 0;
			this->label73->Text = L"C68";
			// 
			// panel70
			// 
			this->panel70->BackColor = System::Drawing::Color::Aqua;
			this->panel70->Controls->Add(this->label74);
			this->panel70->Location = System::Drawing::Point(1306, 330);
			this->panel70->Name = L"panel70";
			this->panel70->Size = System::Drawing::Size(40, 38);
			this->panel70->TabIndex = 83;
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->BackColor = System::Drawing::Color::White;
			this->label74->Location = System::Drawing::Point(3, 14);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(31, 15);
			this->label74->TabIndex = 0;
			this->label74->Text = L"C69";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(601, 34);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1288, 693);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// panel71
			// 
			this->panel71->BackColor = System::Drawing::Color::Aqua;
			this->panel71->Controls->Add(this->label75);
			this->panel71->Location = System::Drawing::Point(1349, 330);
			this->panel71->Name = L"panel71";
			this->panel71->Size = System::Drawing::Size(40, 38);
			this->panel71->TabIndex = 84;
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->BackColor = System::Drawing::Color::White;
			this->label75->Location = System::Drawing::Point(3, 14);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(31, 15);
			this->label75->TabIndex = 0;
			this->label75->Text = L"C70";
			// 
			// panel72
			// 
			this->panel72->BackColor = System::Drawing::Color::Aqua;
			this->panel72->Controls->Add(this->label76);
			this->panel72->Location = System::Drawing::Point(1579, 569);
			this->panel72->Name = L"panel72";
			this->panel72->Size = System::Drawing::Size(34, 38);
			this->panel72->TabIndex = 85;
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->BackColor = System::Drawing::Color::White;
			this->label76->Location = System::Drawing::Point(3, 14);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(31, 15);
			this->label76->TabIndex = 0;
			this->label76->Text = L"C71";
			// 
			// panel73
			// 
			this->panel73->BackColor = System::Drawing::Color::Aqua;
			this->panel73->Controls->Add(this->label77);
			this->panel73->Location = System::Drawing::Point(1616, 569);
			this->panel73->Name = L"panel73";
			this->panel73->Size = System::Drawing::Size(40, 38);
			this->panel73->TabIndex = 86;
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->BackColor = System::Drawing::Color::White;
			this->label77->Location = System::Drawing::Point(3, 14);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(31, 15);
			this->label77->TabIndex = 0;
			this->label77->Text = L"C72";
			// 
			// panel74
			// 
			this->panel74->BackColor = System::Drawing::Color::Aqua;
			this->panel74->Controls->Add(this->label78);
			this->panel74->Location = System::Drawing::Point(1656, 569);
			this->panel74->Name = L"panel74";
			this->panel74->Size = System::Drawing::Size(40, 38);
			this->panel74->TabIndex = 87;
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->BackColor = System::Drawing::Color::White;
			this->label78->Location = System::Drawing::Point(3, 14);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(31, 15);
			this->label78->TabIndex = 0;
			this->label78->Text = L"C73";
			// 
			// panel75
			// 
			this->panel75->BackColor = System::Drawing::Color::Aqua;
			this->panel75->Controls->Add(this->label79);
			this->panel75->Location = System::Drawing::Point(1696, 569);
			this->panel75->Name = L"panel75";
			this->panel75->Size = System::Drawing::Size(34, 38);
			this->panel75->TabIndex = 88;
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->BackColor = System::Drawing::Color::White;
			this->label79->Location = System::Drawing::Point(3, 14);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(31, 15);
			this->label79->TabIndex = 0;
			this->label79->Text = L"C74";
			// 
			// panel76
			// 
			this->panel76->BackColor = System::Drawing::Color::Aqua;
			this->panel76->Controls->Add(this->label80);
			this->panel76->Location = System::Drawing::Point(1579, 629);
			this->panel76->Name = L"panel76";
			this->panel76->Size = System::Drawing::Size(41, 27);
			this->panel76->TabIndex = 89;
			this->panel76->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &showSpaceStatusForm::panel76_Paint);
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->BackColor = System::Drawing::Color::MintCream;
			this->label80->Location = System::Drawing::Point(3, 3);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(31, 15);
			this->label80->TabIndex = 0;
			this->label80->Text = L"C75";
			this->label80->Click += gcnew System::EventHandler(this, &showSpaceStatusForm::label80_Click);
			// 
			// panel77
			// 
			this->panel77->BackColor = System::Drawing::Color::Aqua;
			this->panel77->Controls->Add(this->C76);
			this->panel77->Location = System::Drawing::Point(1615, 628);
			this->panel77->Name = L"panel77";
			this->panel77->Size = System::Drawing::Size(41, 28);
			this->panel77->TabIndex = 90;
			// 
			// C76
			// 
			this->C76->AutoSize = true;
			this->C76->BackColor = System::Drawing::Color::MintCream;
			this->C76->Location = System::Drawing::Point(1, 3);
			this->C76->Name = L"C76";
			this->C76->Size = System::Drawing::Size(31, 15);
			this->C76->TabIndex = 0;
			this->C76->Text = L"C76";
			this->C76->Click += gcnew System::EventHandler(this, &showSpaceStatusForm::C76_Click);
			// 
			// panel78
			// 
			this->panel78->BackColor = System::Drawing::Color::Aqua;
			this->panel78->Controls->Add(this->label81);
			this->panel78->Location = System::Drawing::Point(1650, 625);
			this->panel78->Name = L"panel78";
			this->panel78->Size = System::Drawing::Size(40, 31);
			this->panel78->TabIndex = 0;
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->BackColor = System::Drawing::Color::MintCream;
			this->label81->Location = System::Drawing::Point(3, 7);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(31, 15);
			this->label81->TabIndex = 0;
			this->label81->Text = L"C77";
			// 
			// panel79
			// 
			this->panel79->BackColor = System::Drawing::Color::Aqua;
			this->panel79->Controls->Add(this->label82);
			this->panel79->Location = System::Drawing::Point(1690, 625);
			this->panel79->Name = L"panel79";
			this->panel79->Size = System::Drawing::Size(40, 31);
			this->panel79->TabIndex = 91;
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->BackColor = System::Drawing::Color::MintCream;
			this->label82->Location = System::Drawing::Point(9, 7);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(31, 15);
			this->label82->TabIndex = 0;
			this->label82->Text = L"C78";
			this->label82->Click += gcnew System::EventHandler(this, &showSpaceStatusForm::label82_Click);
			// 
			// panel80
			// 
			this->panel80->BackColor = System::Drawing::Color::Aqua;
			this->panel80->Controls->Add(this->label83);
			this->panel80->Location = System::Drawing::Point(1751, 618);
			this->panel80->Name = L"panel80";
			this->panel80->Size = System::Drawing::Size(34, 38);
			this->panel80->TabIndex = 92;
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->BackColor = System::Drawing::Color::White;
			this->label83->Location = System::Drawing::Point(3, 14);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(31, 15);
			this->label83->TabIndex = 0;
			this->label83->Text = L"C79";
			// 
			// panel81
			// 
			this->panel81->BackColor = System::Drawing::Color::Aqua;
			this->panel81->Controls->Add(this->label84);
			this->panel81->Location = System::Drawing::Point(1797, 618);
			this->panel81->Name = L"panel81";
			this->panel81->Size = System::Drawing::Size(34, 38);
			this->panel81->TabIndex = 93;
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->BackColor = System::Drawing::Color::White;
			this->label84->Location = System::Drawing::Point(3, 14);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(31, 15);
			this->label84->TabIndex = 0;
			this->label84->Text = L"C80";
			// 
			// panel82
			// 
			this->panel82->BackColor = System::Drawing::Color::Aqua;
			this->panel82->Controls->Add(this->label85);
			this->panel82->Location = System::Drawing::Point(1843, 617);
			this->panel82->Name = L"panel82";
			this->panel82->Size = System::Drawing::Size(34, 38);
			this->panel82->TabIndex = 94;
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->BackColor = System::Drawing::Color::White;
			this->label85->Location = System::Drawing::Point(3, 14);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(31, 15);
			this->label85->TabIndex = 0;
			this->label85->Text = L"C81";
			// 
			// panel83
			// 
			this->panel83->BackColor = System::Drawing::Color::Aqua;
			this->panel83->Controls->Add(this->label86);
			this->panel83->Location = System::Drawing::Point(1751, 654);
			this->panel83->Name = L"panel83";
			this->panel83->Size = System::Drawing::Size(31, 38);
			this->panel83->TabIndex = 95;
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->BackColor = System::Drawing::Color::White;
			this->label86->Location = System::Drawing::Point(3, 14);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(31, 15);
			this->label86->TabIndex = 0;
			this->label86->Text = L"C82";
			// 
			// panel84
			// 
			this->panel84->BackColor = System::Drawing::Color::Aqua;
			this->panel84->Controls->Add(this->label87);
			this->panel84->Location = System::Drawing::Point(1797, 654);
			this->panel84->Name = L"panel84";
			this->panel84->Size = System::Drawing::Size(34, 38);
			this->panel84->TabIndex = 96;
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->BackColor = System::Drawing::Color::White;
			this->label87->Location = System::Drawing::Point(3, 14);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(31, 15);
			this->label87->TabIndex = 0;
			this->label87->Text = L"C83";
			// 
			// panel85
			// 
			this->panel85->BackColor = System::Drawing::Color::Aqua;
			this->panel85->Controls->Add(this->label88);
			this->panel85->Location = System::Drawing::Point(1843, 654);
			this->panel85->Name = L"panel85";
			this->panel85->Size = System::Drawing::Size(34, 38);
			this->panel85->TabIndex = 97;
			// 
			// label88
			// 
			this->label88->AutoSize = true;
			this->label88->BackColor = System::Drawing::Color::White;
			this->label88->Location = System::Drawing::Point(3, 14);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(31, 15);
			this->label88->TabIndex = 0;
			this->label88->Text = L"C84";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(601, 441);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(350, 256);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox3->TabIndex = 98;
			this->pictureBox3->TabStop = false;
			// 
			// showSpaceStatusForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1901, 998);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->panel85);
			this->Controls->Add(this->panel84);
			this->Controls->Add(this->panel83);
			this->Controls->Add(this->panel82);
			this->Controls->Add(this->panel81);
			this->Controls->Add(this->panel80);
			this->Controls->Add(this->panel79);
			this->Controls->Add(this->panel78);
			this->Controls->Add(this->panel77);
			this->Controls->Add(this->panel76);
			this->Controls->Add(this->panel75);
			this->Controls->Add(this->panel74);
			this->Controls->Add(this->panel73);
			this->Controls->Add(this->panel72);
			this->Controls->Add(this->panel71);
			this->Controls->Add(this->panel70);
			this->Controls->Add(this->panel69);
			this->Controls->Add(this->panel68);
			this->Controls->Add(this->panel67);
			this->Controls->Add(this->panel66);
			this->Controls->Add(this->panel65);
			this->Controls->Add(this->panel64);
			this->Controls->Add(this->panel63);
			this->Controls->Add(this->panel62);
			this->Controls->Add(this->panel61);
			this->Controls->Add(this->panel60);
			this->Controls->Add(this->panel59);
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
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"showSpaceStatusForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"查看车位状态";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
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
			this->panel59->ResumeLayout(false);
			this->panel59->PerformLayout();
			this->panel60->ResumeLayout(false);
			this->panel60->PerformLayout();
			this->panel61->ResumeLayout(false);
			this->panel61->PerformLayout();
			this->panel62->ResumeLayout(false);
			this->panel62->PerformLayout();
			this->panel63->ResumeLayout(false);
			this->panel63->PerformLayout();
			this->panel64->ResumeLayout(false);
			this->panel64->PerformLayout();
			this->panel65->ResumeLayout(false);
			this->panel65->PerformLayout();
			this->panel66->ResumeLayout(false);
			this->panel66->PerformLayout();
			this->panel67->ResumeLayout(false);
			this->panel67->PerformLayout();
			this->panel68->ResumeLayout(false);
			this->panel68->PerformLayout();
			this->panel69->ResumeLayout(false);
			this->panel69->PerformLayout();
			this->panel70->ResumeLayout(false);
			this->panel70->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel71->ResumeLayout(false);
			this->panel71->PerformLayout();
			this->panel72->ResumeLayout(false);
			this->panel72->PerformLayout();
			this->panel73->ResumeLayout(false);
			this->panel73->PerformLayout();
			this->panel74->ResumeLayout(false);
			this->panel74->PerformLayout();
			this->panel75->ResumeLayout(false);
			this->panel75->PerformLayout();
			this->panel76->ResumeLayout(false);
			this->panel76->PerformLayout();
			this->panel77->ResumeLayout(false);
			this->panel77->PerformLayout();
			this->panel78->ResumeLayout(false);
			this->panel78->PerformLayout();
			this->panel79->ResumeLayout(false);
			this->panel79->PerformLayout();
			this->panel80->ResumeLayout(false);
			this->panel80->PerformLayout();
			this->panel81->ResumeLayout(false);
			this->panel81->PerformLayout();
			this->panel82->ResumeLayout(false);
			this->panel82->PerformLayout();
			this->panel83->ResumeLayout(false);
			this->panel83->PerformLayout();
			this->panel84->ResumeLayout(false);
			this->panel84->PerformLayout();
			this->panel85->ResumeLayout(false);
			this->panel85->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	public:void find(int& free0,int& busy0)
	{
		   textBox1->Text = (free0).ToString();
		   textBox3->Text = (busy0).ToString();
		   int x; int y;
		   int index = 0;

		   FILE* fp1;
		   fp1 = fopen("查询车位坐标.txt", "r");
		   while (1){
		      fscanf(fp1, "%d", &x);
	    	  fscanf(fp1, "%d", &y);
		      if (x < 0)
			   break;
			  if (arr[x][y] == 1){
				
				  textBox2->Text += "C";
				  if (index <= 9)
				  {
					  textBox2->Text += "0";
				  }
				  textBox2->Text += index;
				  textBox2->Text += " ";
				  index++;
				  /*  textBox2->Text += "x";
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
					}*/
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
				  } if (index == 58){
					  this->panel59->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 59){
					  this->panel60->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 60){
					  this->panel61->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 61){
					  this->panel62->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 62){
					  this->panel63->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 63){
					  this->panel64->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 64){
					  this->panel65->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 65){
					  this->panel66->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 66){
					  this->panel67->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 67){
					  this->panel68->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 68){
					  this->panel69->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 69){
					  this->panel70->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 70){
					  this->panel71->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 71){
					  this->panel72->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 72){
					  this->panel73->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 73){
					  this->panel74->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 74){
					  this->panel75->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 75){
					  this->panel76->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 76){
					  this->panel77->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 77){
					  this->panel78->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 78){
					  this->panel79->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 79){
					  this->panel80->BackColor = System::Drawing::SystemColors::Desktop;
				  }
				  if (index == 80){
					  this->panel81->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 81){
					  this->panel82->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 82){
					  this->panel83->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 83){
					  this->panel84->BackColor = System::Drawing::SystemColors::Desktop;
				  } if (index == 84){
					  this->panel85->BackColor = System::Drawing::SystemColors::Desktop;
				  }

				
				  textBox4->Text += "C";
				  if (index <= 9)
				  {
					  textBox4->Text += "0";
				  }
				  textBox4->Text += index;
				  textBox4->Text += " ";
				  index++;

				 /* textBox4->Text += "x";
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
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel76_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void label80_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void C76_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label82_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};
}
