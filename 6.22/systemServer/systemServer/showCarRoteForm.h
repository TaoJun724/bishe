#pragma once
#include<string>
#include<iostream>
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
	/// showCarRoteForm 摘要
	/// </summary>
	public ref class showCarRoteForm : public System::Windows::Forms::Form
	{
	public:
		showCarRoteForm(void)
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
		~showCarRoteForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;

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
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Label^  label12;
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
	private: System::Windows::Forms::Panel^  panel24;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::Panel^  panel23;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Panel^  panel22;
	private: System::Windows::Forms::Label^  label26;
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
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Panel^  panel60;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Panel^  panel61;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Panel^  panel62;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Panel^  panel63;
private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Panel^  panel64;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Panel^  panel65;
private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Panel^  panel66;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Panel^  panel67;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Panel^  panel68;
private: System::Windows::Forms::Label^  label70;

private: System::Windows::Forms::Panel^  panel69;
private: System::Windows::Forms::Label^  label71;
private: System::Windows::Forms::Panel^  panel70;
private: System::Windows::Forms::Label^  label72;
private: System::Windows::Forms::Panel^  panel71;
private: System::Windows::Forms::Label^  label73;
private: System::Windows::Forms::Panel^  panel72;
private: System::Windows::Forms::Label^  label74;
private: System::Windows::Forms::Panel^  panel73;
private: System::Windows::Forms::Label^  label75;
private: System::Windows::Forms::Panel^  panel74;
private: System::Windows::Forms::Label^  label76;
private: System::Windows::Forms::Panel^  panel75;
private: System::Windows::Forms::Label^  label77;
private: System::Windows::Forms::Panel^  panel76;
private: System::Windows::Forms::Label^  label78;
private: System::Windows::Forms::Panel^  panel77;
private: System::Windows::Forms::Label^  label79;
private: System::Windows::Forms::Panel^  panel78;
private: System::Windows::Forms::Label^  label80;
private: System::Windows::Forms::Panel^  panel79;
private: System::Windows::Forms::Label^  label81;
private: System::Windows::Forms::Panel^  panel80;
private: System::Windows::Forms::Label^  label82;
private: System::Windows::Forms::Panel^  panel81;
private: System::Windows::Forms::Label^  label83;
private: System::Windows::Forms::Panel^  panel82;
private: System::Windows::Forms::Label^  label84;
private: System::Windows::Forms::Panel^  panel83;
private: System::Windows::Forms::Label^  label85;
private: System::Windows::Forms::Panel^  panel84;
private: System::Windows::Forms::Label^  label86;
private: System::Windows::Forms::Panel^  panel85;
private: System::Windows::Forms::Label^  label87;
private: System::Windows::Forms::Panel^  panel86;
private: System::Windows::Forms::Label^  label88;
private: System::Windows::Forms::Panel^  panel87;
private: System::Windows::Forms::Label^  label89;
private: System::Windows::Forms::Panel^  panel88;
private: System::Windows::Forms::Label^  label90;
private: System::Windows::Forms::Panel^  panel89;
private: System::Windows::Forms::Label^  label91;
private: System::Windows::Forms::Panel^  panel90;
private: System::Windows::Forms::Label^  label92;
private: System::Windows::Forms::Panel^  panel91;
private: System::Windows::Forms::Label^  label93;
private: System::Windows::Forms::Panel^  panel92;
private: System::Windows::Forms::Label^  label94;
private: System::Windows::Forms::Panel^  panel93;
private: System::Windows::Forms::Label^  label95;
private: System::Windows::Forms::Panel^  panel94;
private: System::Windows::Forms::Label^  label96;
private: System::Windows::Forms::Panel^  panel95;
private: System::Windows::Forms::Label^  label97;
private: System::Windows::Forms::Panel^  panel96;
private: System::Windows::Forms::Label^  label98;
private: System::Windows::Forms::Panel^  panel97;
private: System::Windows::Forms::Label^  label99;
private: System::Windows::Forms::Panel^  panel98;
private: System::Windows::Forms::Label^  label100;
private: System::Windows::Forms::Panel^  panel99;
private: System::Windows::Forms::Label^  label101;
private: System::Windows::Forms::Panel^  panel100;
private: System::Windows::Forms::Label^  label102;
private: System::Windows::Forms::Panel^  panel101;
private: System::Windows::Forms::Label^  label103;
private: System::Windows::Forms::Panel^  panel102;
private: System::Windows::Forms::Label^  label104;
private: System::Windows::Forms::Panel^  panel103;
private: System::Windows::Forms::Label^  label105;
private: System::Windows::Forms::Panel^  panel104;
private: System::Windows::Forms::Label^  label106;
private: System::Windows::Forms::Panel^  panel105;
private: System::Windows::Forms::Label^  label107;
private: System::Windows::Forms::Panel^  panel106;
private: System::Windows::Forms::Label^  label108;
private: System::Windows::Forms::Panel^  panel107;
private: System::Windows::Forms::Label^  label109;
private: System::Windows::Forms::Panel^  panel108;
private: System::Windows::Forms::Label^  label110;
private: System::Windows::Forms::Panel^  panel109;
private: System::Windows::Forms::Label^  label111;
private: System::Windows::Forms::Panel^  panel110;
private: System::Windows::Forms::Label^  label112;
private: System::Windows::Forms::Panel^  panel111;
private: System::Windows::Forms::Label^  label113;
private: System::Windows::Forms::Panel^  panel112;
private: System::Windows::Forms::Label^  label114;
private: System::Windows::Forms::Panel^  panel113;
private: System::Windows::Forms::Label^  label115;
private: System::Windows::Forms::Panel^  panel114;
private: System::Windows::Forms::Label^  label116;
private: System::Windows::Forms::Panel^  panel115;
private: System::Windows::Forms::Label^  label117;
private: System::Windows::Forms::Panel^  panel116;
private: System::Windows::Forms::Label^  label118;
private: System::Windows::Forms::Panel^  panel117;
private: System::Windows::Forms::Label^  label119;
private: System::Windows::Forms::Panel^  panel118;
private: System::Windows::Forms::Label^  label120;
private: System::Windows::Forms::Panel^  panel119;
private: System::Windows::Forms::Label^  label121;
private: System::Windows::Forms::Panel^  panel120;
private: System::Windows::Forms::Label^  label122;
private: System::Windows::Forms::Panel^  panel121;
private: System::Windows::Forms::Label^  label123;
private: System::Windows::Forms::Panel^  panel122;
private: System::Windows::Forms::Label^  label124;
private: System::Windows::Forms::Panel^  panel123;
private: System::Windows::Forms::Label^  label125;
private: System::Windows::Forms::Panel^  panel124;
private: System::Windows::Forms::Label^  label126;
private: System::Windows::Forms::Panel^  panel125;
private: System::Windows::Forms::Label^  label127;
private: System::Windows::Forms::Panel^  panel126;
private: System::Windows::Forms::Label^  label128;
private: System::Windows::Forms::Panel^  panel127;
private: System::Windows::Forms::Label^  label129;
private: System::Windows::Forms::Panel^  panel128;
private: System::Windows::Forms::Label^  label130;
private: System::Windows::Forms::Panel^  panel129;
private: System::Windows::Forms::Label^  label131;
private: System::Windows::Forms::Panel^  panel130;
private: System::Windows::Forms::Label^  label132;
private: System::Windows::Forms::Panel^  panel131;
private: System::Windows::Forms::Label^  label133;
private: System::Windows::Forms::Panel^  panel132;
private: System::Windows::Forms::Label^  label134;
private: System::Windows::Forms::Panel^  panel133;
private: System::Windows::Forms::Label^  label135;
private: System::Windows::Forms::Panel^  panel134;
private: System::Windows::Forms::Label^  label136;
private: System::Windows::Forms::Panel^  panel135;
private: System::Windows::Forms::Label^  label137;
private: System::Windows::Forms::Panel^  panel136;
private: System::Windows::Forms::Label^  label138;
private: System::Windows::Forms::Panel^  panel137;
private: System::Windows::Forms::Label^  label139;
private: System::Windows::Forms::Panel^  panel138;
private: System::Windows::Forms::Label^  label140;
private: System::Windows::Forms::Panel^  panel139;
private: System::Windows::Forms::Label^  label141;
private: System::Windows::Forms::Panel^  panel140;
private: System::Windows::Forms::Label^  label142;
private: System::Windows::Forms::Panel^  panel141;
private: System::Windows::Forms::Label^  label143;
private: System::Windows::Forms::Panel^  panel142;
private: System::Windows::Forms::Label^  label144;
private: System::Windows::Forms::Panel^  panel143;
private: System::Windows::Forms::Label^  label145;
private: System::Windows::Forms::Panel^  panel144;
private: System::Windows::Forms::Label^  label146;
private: System::Windows::Forms::Panel^  panel145;
private: System::Windows::Forms::Label^  label147;
private: System::Windows::Forms::Panel^  panel146;
private: System::Windows::Forms::Label^  label148;
private: System::Windows::Forms::Panel^  panel147;
private: System::Windows::Forms::Label^  label149;
private: System::Windows::Forms::Panel^  panel148;
private: System::Windows::Forms::Label^  label150;
private: System::Windows::Forms::Panel^  panel149;
private: System::Windows::Forms::Label^  label151;
private: System::Windows::Forms::Panel^  panel150;
private: System::Windows::Forms::Label^  label152;
private: System::Windows::Forms::Panel^  panel151;
private: System::Windows::Forms::Label^  label153;
private: System::Windows::Forms::Panel^  panel152;
private: System::Windows::Forms::Label^  label154;
private: System::Windows::Forms::Panel^  panel153;
private: System::Windows::Forms::Label^  label155;
private: System::Windows::Forms::Panel^  panel154;
private: System::Windows::Forms::Label^  label156;
private: System::Windows::Forms::Panel^  panel155;
private: System::Windows::Forms::Label^  label157;
private: System::Windows::Forms::Panel^  panel156;
private: System::Windows::Forms::Label^  label158;
private: System::Windows::Forms::Panel^  panel157;
private: System::Windows::Forms::Label^  label159;
private: System::Windows::Forms::Panel^  panel158;
private: System::Windows::Forms::Label^  label160;
private: System::Windows::Forms::Panel^  panel159;
private: System::Windows::Forms::Label^  label161;
private: System::Windows::Forms::Panel^  panel160;
private: System::Windows::Forms::Label^  label162;
private: System::Windows::Forms::Panel^  panel161;
private: System::Windows::Forms::Label^  C76;
private: System::Windows::Forms::Panel^  panel162;
private: System::Windows::Forms::Label^  label163;
private: System::Windows::Forms::Panel^  panel163;
private: System::Windows::Forms::Label^  label164;
private: System::Windows::Forms::PictureBox^  pictureBox1;
private: System::Windows::Forms::Panel^  panel164;
private: System::Windows::Forms::Label^  label165;
private: System::Windows::Forms::Panel^  panel165;
private: System::Windows::Forms::Label^  label166;
private: System::Windows::Forms::Panel^  panel166;
private: System::Windows::Forms::Label^  label167;
private: System::Windows::Forms::Panel^  panel167;
private: System::Windows::Forms::Label^  label168;
private: System::Windows::Forms::Panel^  panel168;
private: System::Windows::Forms::Label^  label169;
private: System::Windows::Forms::Panel^  panel169;
private: System::Windows::Forms::Label^  label170;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(showCarRoteForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
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
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
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
			this->panel24 = (gcnew System::Windows::Forms::Panel());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->panel23 = (gcnew System::Windows::Forms::Panel());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->panel22 = (gcnew System::Windows::Forms::Panel());
			this->label26 = (gcnew System::Windows::Forms::Label());
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel60 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel61 = (gcnew System::Windows::Forms::Panel());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->panel62 = (gcnew System::Windows::Forms::Panel());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->panel63 = (gcnew System::Windows::Forms::Panel());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->panel64 = (gcnew System::Windows::Forms::Panel());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->panel65 = (gcnew System::Windows::Forms::Panel());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->panel66 = (gcnew System::Windows::Forms::Panel());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->panel67 = (gcnew System::Windows::Forms::Panel());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->panel68 = (gcnew System::Windows::Forms::Panel());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->panel69 = (gcnew System::Windows::Forms::Panel());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->panel70 = (gcnew System::Windows::Forms::Panel());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->panel71 = (gcnew System::Windows::Forms::Panel());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->panel72 = (gcnew System::Windows::Forms::Panel());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->panel73 = (gcnew System::Windows::Forms::Panel());
			this->label75 = (gcnew System::Windows::Forms::Label());
			this->panel74 = (gcnew System::Windows::Forms::Panel());
			this->label76 = (gcnew System::Windows::Forms::Label());
			this->panel75 = (gcnew System::Windows::Forms::Panel());
			this->label77 = (gcnew System::Windows::Forms::Label());
			this->panel76 = (gcnew System::Windows::Forms::Panel());
			this->label78 = (gcnew System::Windows::Forms::Label());
			this->panel77 = (gcnew System::Windows::Forms::Panel());
			this->label79 = (gcnew System::Windows::Forms::Label());
			this->panel78 = (gcnew System::Windows::Forms::Panel());
			this->label80 = (gcnew System::Windows::Forms::Label());
			this->panel79 = (gcnew System::Windows::Forms::Panel());
			this->label81 = (gcnew System::Windows::Forms::Label());
			this->panel80 = (gcnew System::Windows::Forms::Panel());
			this->label82 = (gcnew System::Windows::Forms::Label());
			this->panel81 = (gcnew System::Windows::Forms::Panel());
			this->label83 = (gcnew System::Windows::Forms::Label());
			this->panel82 = (gcnew System::Windows::Forms::Panel());
			this->label84 = (gcnew System::Windows::Forms::Label());
			this->panel83 = (gcnew System::Windows::Forms::Panel());
			this->label85 = (gcnew System::Windows::Forms::Label());
			this->panel84 = (gcnew System::Windows::Forms::Panel());
			this->label86 = (gcnew System::Windows::Forms::Label());
			this->panel85 = (gcnew System::Windows::Forms::Panel());
			this->label87 = (gcnew System::Windows::Forms::Label());
			this->panel86 = (gcnew System::Windows::Forms::Panel());
			this->label88 = (gcnew System::Windows::Forms::Label());
			this->panel87 = (gcnew System::Windows::Forms::Panel());
			this->label89 = (gcnew System::Windows::Forms::Label());
			this->panel88 = (gcnew System::Windows::Forms::Panel());
			this->label90 = (gcnew System::Windows::Forms::Label());
			this->panel89 = (gcnew System::Windows::Forms::Panel());
			this->label91 = (gcnew System::Windows::Forms::Label());
			this->panel90 = (gcnew System::Windows::Forms::Panel());
			this->label92 = (gcnew System::Windows::Forms::Label());
			this->panel91 = (gcnew System::Windows::Forms::Panel());
			this->label93 = (gcnew System::Windows::Forms::Label());
			this->panel92 = (gcnew System::Windows::Forms::Panel());
			this->label94 = (gcnew System::Windows::Forms::Label());
			this->panel93 = (gcnew System::Windows::Forms::Panel());
			this->label95 = (gcnew System::Windows::Forms::Label());
			this->panel94 = (gcnew System::Windows::Forms::Panel());
			this->label96 = (gcnew System::Windows::Forms::Label());
			this->panel95 = (gcnew System::Windows::Forms::Panel());
			this->label97 = (gcnew System::Windows::Forms::Label());
			this->panel96 = (gcnew System::Windows::Forms::Panel());
			this->label98 = (gcnew System::Windows::Forms::Label());
			this->panel97 = (gcnew System::Windows::Forms::Panel());
			this->label99 = (gcnew System::Windows::Forms::Label());
			this->panel98 = (gcnew System::Windows::Forms::Panel());
			this->label100 = (gcnew System::Windows::Forms::Label());
			this->panel99 = (gcnew System::Windows::Forms::Panel());
			this->label101 = (gcnew System::Windows::Forms::Label());
			this->panel100 = (gcnew System::Windows::Forms::Panel());
			this->label102 = (gcnew System::Windows::Forms::Label());
			this->panel101 = (gcnew System::Windows::Forms::Panel());
			this->label103 = (gcnew System::Windows::Forms::Label());
			this->panel102 = (gcnew System::Windows::Forms::Panel());
			this->label104 = (gcnew System::Windows::Forms::Label());
			this->panel103 = (gcnew System::Windows::Forms::Panel());
			this->label105 = (gcnew System::Windows::Forms::Label());
			this->panel104 = (gcnew System::Windows::Forms::Panel());
			this->label106 = (gcnew System::Windows::Forms::Label());
			this->panel105 = (gcnew System::Windows::Forms::Panel());
			this->label107 = (gcnew System::Windows::Forms::Label());
			this->panel106 = (gcnew System::Windows::Forms::Panel());
			this->label108 = (gcnew System::Windows::Forms::Label());
			this->panel107 = (gcnew System::Windows::Forms::Panel());
			this->label109 = (gcnew System::Windows::Forms::Label());
			this->panel108 = (gcnew System::Windows::Forms::Panel());
			this->label110 = (gcnew System::Windows::Forms::Label());
			this->panel109 = (gcnew System::Windows::Forms::Panel());
			this->label111 = (gcnew System::Windows::Forms::Label());
			this->panel110 = (gcnew System::Windows::Forms::Panel());
			this->label112 = (gcnew System::Windows::Forms::Label());
			this->panel111 = (gcnew System::Windows::Forms::Panel());
			this->label113 = (gcnew System::Windows::Forms::Label());
			this->panel112 = (gcnew System::Windows::Forms::Panel());
			this->label114 = (gcnew System::Windows::Forms::Label());
			this->panel113 = (gcnew System::Windows::Forms::Panel());
			this->label115 = (gcnew System::Windows::Forms::Label());
			this->panel114 = (gcnew System::Windows::Forms::Panel());
			this->label116 = (gcnew System::Windows::Forms::Label());
			this->panel115 = (gcnew System::Windows::Forms::Panel());
			this->label117 = (gcnew System::Windows::Forms::Label());
			this->panel116 = (gcnew System::Windows::Forms::Panel());
			this->label118 = (gcnew System::Windows::Forms::Label());
			this->panel117 = (gcnew System::Windows::Forms::Panel());
			this->label119 = (gcnew System::Windows::Forms::Label());
			this->panel118 = (gcnew System::Windows::Forms::Panel());
			this->label120 = (gcnew System::Windows::Forms::Label());
			this->panel119 = (gcnew System::Windows::Forms::Panel());
			this->label121 = (gcnew System::Windows::Forms::Label());
			this->panel120 = (gcnew System::Windows::Forms::Panel());
			this->label122 = (gcnew System::Windows::Forms::Label());
			this->panel121 = (gcnew System::Windows::Forms::Panel());
			this->label123 = (gcnew System::Windows::Forms::Label());
			this->panel122 = (gcnew System::Windows::Forms::Panel());
			this->label124 = (gcnew System::Windows::Forms::Label());
			this->panel123 = (gcnew System::Windows::Forms::Panel());
			this->label125 = (gcnew System::Windows::Forms::Label());
			this->panel124 = (gcnew System::Windows::Forms::Panel());
			this->label126 = (gcnew System::Windows::Forms::Label());
			this->panel125 = (gcnew System::Windows::Forms::Panel());
			this->label127 = (gcnew System::Windows::Forms::Label());
			this->panel126 = (gcnew System::Windows::Forms::Panel());
			this->label128 = (gcnew System::Windows::Forms::Label());
			this->panel127 = (gcnew System::Windows::Forms::Panel());
			this->label129 = (gcnew System::Windows::Forms::Label());
			this->panel128 = (gcnew System::Windows::Forms::Panel());
			this->label130 = (gcnew System::Windows::Forms::Label());
			this->panel129 = (gcnew System::Windows::Forms::Panel());
			this->label131 = (gcnew System::Windows::Forms::Label());
			this->panel130 = (gcnew System::Windows::Forms::Panel());
			this->label132 = (gcnew System::Windows::Forms::Label());
			this->panel131 = (gcnew System::Windows::Forms::Panel());
			this->label133 = (gcnew System::Windows::Forms::Label());
			this->panel132 = (gcnew System::Windows::Forms::Panel());
			this->label134 = (gcnew System::Windows::Forms::Label());
			this->panel133 = (gcnew System::Windows::Forms::Panel());
			this->label135 = (gcnew System::Windows::Forms::Label());
			this->panel134 = (gcnew System::Windows::Forms::Panel());
			this->label136 = (gcnew System::Windows::Forms::Label());
			this->panel135 = (gcnew System::Windows::Forms::Panel());
			this->label137 = (gcnew System::Windows::Forms::Label());
			this->panel136 = (gcnew System::Windows::Forms::Panel());
			this->label138 = (gcnew System::Windows::Forms::Label());
			this->panel137 = (gcnew System::Windows::Forms::Panel());
			this->label139 = (gcnew System::Windows::Forms::Label());
			this->panel138 = (gcnew System::Windows::Forms::Panel());
			this->label140 = (gcnew System::Windows::Forms::Label());
			this->panel139 = (gcnew System::Windows::Forms::Panel());
			this->label141 = (gcnew System::Windows::Forms::Label());
			this->panel140 = (gcnew System::Windows::Forms::Panel());
			this->label142 = (gcnew System::Windows::Forms::Label());
			this->panel141 = (gcnew System::Windows::Forms::Panel());
			this->label143 = (gcnew System::Windows::Forms::Label());
			this->panel142 = (gcnew System::Windows::Forms::Panel());
			this->label144 = (gcnew System::Windows::Forms::Label());
			this->panel143 = (gcnew System::Windows::Forms::Panel());
			this->label145 = (gcnew System::Windows::Forms::Label());
			this->panel144 = (gcnew System::Windows::Forms::Panel());
			this->label146 = (gcnew System::Windows::Forms::Label());
			this->panel145 = (gcnew System::Windows::Forms::Panel());
			this->label147 = (gcnew System::Windows::Forms::Label());
			this->panel146 = (gcnew System::Windows::Forms::Panel());
			this->label148 = (gcnew System::Windows::Forms::Label());
			this->panel147 = (gcnew System::Windows::Forms::Panel());
			this->label149 = (gcnew System::Windows::Forms::Label());
			this->panel148 = (gcnew System::Windows::Forms::Panel());
			this->label150 = (gcnew System::Windows::Forms::Label());
			this->panel149 = (gcnew System::Windows::Forms::Panel());
			this->label151 = (gcnew System::Windows::Forms::Label());
			this->panel150 = (gcnew System::Windows::Forms::Panel());
			this->label152 = (gcnew System::Windows::Forms::Label());
			this->panel151 = (gcnew System::Windows::Forms::Panel());
			this->label153 = (gcnew System::Windows::Forms::Label());
			this->panel152 = (gcnew System::Windows::Forms::Panel());
			this->label154 = (gcnew System::Windows::Forms::Label());
			this->panel153 = (gcnew System::Windows::Forms::Panel());
			this->label155 = (gcnew System::Windows::Forms::Label());
			this->panel154 = (gcnew System::Windows::Forms::Panel());
			this->label156 = (gcnew System::Windows::Forms::Label());
			this->panel155 = (gcnew System::Windows::Forms::Panel());
			this->label157 = (gcnew System::Windows::Forms::Label());
			this->panel156 = (gcnew System::Windows::Forms::Panel());
			this->label158 = (gcnew System::Windows::Forms::Label());
			this->panel157 = (gcnew System::Windows::Forms::Panel());
			this->label159 = (gcnew System::Windows::Forms::Label());
			this->panel158 = (gcnew System::Windows::Forms::Panel());
			this->label160 = (gcnew System::Windows::Forms::Label());
			this->panel159 = (gcnew System::Windows::Forms::Panel());
			this->label161 = (gcnew System::Windows::Forms::Label());
			this->panel160 = (gcnew System::Windows::Forms::Panel());
			this->label162 = (gcnew System::Windows::Forms::Label());
			this->panel161 = (gcnew System::Windows::Forms::Panel());
			this->C76 = (gcnew System::Windows::Forms::Label());
			this->panel162 = (gcnew System::Windows::Forms::Panel());
			this->label163 = (gcnew System::Windows::Forms::Label());
			this->panel163 = (gcnew System::Windows::Forms::Panel());
			this->label164 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel164 = (gcnew System::Windows::Forms::Panel());
			this->label165 = (gcnew System::Windows::Forms::Label());
			this->panel165 = (gcnew System::Windows::Forms::Panel());
			this->label166 = (gcnew System::Windows::Forms::Label());
			this->panel166 = (gcnew System::Windows::Forms::Panel());
			this->label167 = (gcnew System::Windows::Forms::Label());
			this->panel167 = (gcnew System::Windows::Forms::Panel());
			this->label168 = (gcnew System::Windows::Forms::Label());
			this->panel168 = (gcnew System::Windows::Forms::Panel());
			this->label169 = (gcnew System::Windows::Forms::Label());
			this->panel169 = (gcnew System::Windows::Forms::Panel());
			this->label170 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel8->SuspendLayout();
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
			this->panel24->SuspendLayout();
			this->panel23->SuspendLayout();
			this->panel22->SuspendLayout();
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
			this->panel86->SuspendLayout();
			this->panel87->SuspendLayout();
			this->panel88->SuspendLayout();
			this->panel89->SuspendLayout();
			this->panel90->SuspendLayout();
			this->panel91->SuspendLayout();
			this->panel92->SuspendLayout();
			this->panel93->SuspendLayout();
			this->panel94->SuspendLayout();
			this->panel95->SuspendLayout();
			this->panel96->SuspendLayout();
			this->panel97->SuspendLayout();
			this->panel98->SuspendLayout();
			this->panel99->SuspendLayout();
			this->panel100->SuspendLayout();
			this->panel101->SuspendLayout();
			this->panel102->SuspendLayout();
			this->panel103->SuspendLayout();
			this->panel104->SuspendLayout();
			this->panel105->SuspendLayout();
			this->panel106->SuspendLayout();
			this->panel107->SuspendLayout();
			this->panel108->SuspendLayout();
			this->panel109->SuspendLayout();
			this->panel110->SuspendLayout();
			this->panel111->SuspendLayout();
			this->panel112->SuspendLayout();
			this->panel113->SuspendLayout();
			this->panel114->SuspendLayout();
			this->panel115->SuspendLayout();
			this->panel116->SuspendLayout();
			this->panel117->SuspendLayout();
			this->panel118->SuspendLayout();
			this->panel119->SuspendLayout();
			this->panel120->SuspendLayout();
			this->panel121->SuspendLayout();
			this->panel122->SuspendLayout();
			this->panel123->SuspendLayout();
			this->panel124->SuspendLayout();
			this->panel125->SuspendLayout();
			this->panel126->SuspendLayout();
			this->panel127->SuspendLayout();
			this->panel128->SuspendLayout();
			this->panel129->SuspendLayout();
			this->panel130->SuspendLayout();
			this->panel131->SuspendLayout();
			this->panel132->SuspendLayout();
			this->panel133->SuspendLayout();
			this->panel134->SuspendLayout();
			this->panel135->SuspendLayout();
			this->panel136->SuspendLayout();
			this->panel137->SuspendLayout();
			this->panel138->SuspendLayout();
			this->panel139->SuspendLayout();
			this->panel140->SuspendLayout();
			this->panel141->SuspendLayout();
			this->panel142->SuspendLayout();
			this->panel143->SuspendLayout();
			this->panel144->SuspendLayout();
			this->panel145->SuspendLayout();
			this->panel146->SuspendLayout();
			this->panel147->SuspendLayout();
			this->panel148->SuspendLayout();
			this->panel149->SuspendLayout();
			this->panel150->SuspendLayout();
			this->panel151->SuspendLayout();
			this->panel152->SuspendLayout();
			this->panel153->SuspendLayout();
			this->panel154->SuspendLayout();
			this->panel155->SuspendLayout();
			this->panel156->SuspendLayout();
			this->panel157->SuspendLayout();
			this->panel158->SuspendLayout();
			this->panel159->SuspendLayout();
			this->panel160->SuspendLayout();
			this->panel161->SuspendLayout();
			this->panel162->SuspendLayout();
			this->panel163->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel164->SuspendLayout();
			this->panel165->SuspendLayout();
			this->panel166->SuspendLayout();
			this->panel167->SuspendLayout();
			this->panel168->SuspendLayout();
			this->panel169->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label1->Location = System::Drawing::Point(44, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(229, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"请输入查看的小车编号：";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Window;
			this->button1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button1->ForeColor = System::Drawing::SystemColors::MenuText;
			this->button1->Location = System::Drawing::Point(175, 133);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 45);
			this->button1->TabIndex = 1;
			this->button1->Text = L"查询";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &showCarRoteForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(279, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(44, 199);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(169, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"所查小车位置为：";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(279, 199);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 25);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &showCarRoteForm::textBox2_TextChanged);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(622, 500);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(505, 252);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 11;
			this->pictureBox2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Yellow;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Location = System::Drawing::Point(574, 36);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(118, 52);
			this->panel1->TabIndex = 12;
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
			this->panel2->Location = System::Drawing::Point(574, 94);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(67, 96);
			this->panel2->TabIndex = 13;
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
			this->panel3->Location = System::Drawing::Point(647, 94);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(45, 52);
			this->panel3->TabIndex = 14;
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
			this->panel4->Location = System::Drawing::Point(647, 152);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(135, 38);
			this->panel4->TabIndex = 15;
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
			this->panel5->Location = System::Drawing::Point(698, 96);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(84, 50);
			this->panel5->TabIndex = 16;
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
			this->panel6->Location = System::Drawing::Point(788, 152);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(77, 38);
			this->panel6->TabIndex = 17;
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
			this->panel7->Location = System::Drawing::Point(788, 94);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(77, 50);
			this->panel7->TabIndex = 18;
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
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::Yellow;
			this->panel9->Controls->Add(this->label13);
			this->panel9->Location = System::Drawing::Point(871, 94);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(125, 50);
			this->panel9->TabIndex = 20;
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
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Yellow;
			this->panel8->Controls->Add(this->label12);
			this->panel8->Location = System::Drawing::Point(871, 152);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(125, 38);
			this->panel8->TabIndex = 21;
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
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::Yellow;
			this->panel10->Controls->Add(this->label14);
			this->panel10->Location = System::Drawing::Point(1006, 36);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(51, 26);
			this->panel10->TabIndex = 22;
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
			this->panel11->Location = System::Drawing::Point(1006, 68);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(51, 30);
			this->panel11->TabIndex = 23;
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
			this->panel12->Location = System::Drawing::Point(1006, 150);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(87, 43);
			this->panel12->TabIndex = 24;
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
			this->panel13->Location = System::Drawing::Point(1006, 97);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(87, 47);
			this->panel13->TabIndex = 25;
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
			this->panel14->Location = System::Drawing::Point(1099, 152);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(108, 38);
			this->panel14->TabIndex = 26;
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
			this->panel15->Location = System::Drawing::Point(1099, 97);
			this->panel15->Name = L"panel15";
			this->panel15->Size = System::Drawing::Size(108, 52);
			this->panel15->TabIndex = 27;
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
			this->panel16->Location = System::Drawing::Point(1213, 152);
			this->panel16->Name = L"panel16";
			this->panel16->Size = System::Drawing::Size(121, 38);
			this->panel16->TabIndex = 28;
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
			this->panel17->Location = System::Drawing::Point(1213, 94);
			this->panel17->Name = L"panel17";
			this->panel17->Size = System::Drawing::Size(121, 52);
			this->panel17->TabIndex = 29;
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
			this->panel18->Location = System::Drawing::Point(1340, 152);
			this->panel18->Name = L"panel18";
			this->panel18->Size = System::Drawing::Size(167, 38);
			this->panel18->TabIndex = 30;
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
			this->panel19->Location = System::Drawing::Point(1340, 94);
			this->panel19->Name = L"panel19";
			this->panel19->Size = System::Drawing::Size(167, 50);
			this->panel19->TabIndex = 31;
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
			this->panel20->Location = System::Drawing::Point(1513, 152);
			this->panel20->Name = L"panel20";
			this->panel20->Size = System::Drawing::Size(139, 38);
			this->panel20->TabIndex = 32;
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
			this->panel21->Location = System::Drawing::Point(1513, 94);
			this->panel21->Name = L"panel21";
			this->panel21->Size = System::Drawing::Size(139, 50);
			this->panel21->TabIndex = 33;
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
			// panel24
			// 
			this->panel24->BackColor = System::Drawing::Color::Yellow;
			this->panel24->Controls->Add(this->label28);
			this->panel24->Location = System::Drawing::Point(1655, 94);
			this->panel24->Name = L"panel24";
			this->panel24->Size = System::Drawing::Size(136, 95);
			this->panel24->TabIndex = 35;
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
			// panel23
			// 
			this->panel23->BackColor = System::Drawing::Color::Yellow;
			this->panel23->Controls->Add(this->label27);
			this->panel23->Location = System::Drawing::Point(1690, 187);
			this->panel23->Name = L"panel23";
			this->panel23->Size = System::Drawing::Size(53, 190);
			this->panel23->TabIndex = 36;
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
			// panel22
			// 
			this->panel22->BackColor = System::Drawing::Color::Yellow;
			this->panel22->Controls->Add(this->label26);
			this->panel22->Location = System::Drawing::Point(1621, 383);
			this->panel22->Name = L"panel22";
			this->panel22->Size = System::Drawing::Size(170, 76);
			this->panel22->TabIndex = 37;
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
			// panel25
			// 
			this->panel25->BackColor = System::Drawing::Color::Yellow;
			this->panel25->Controls->Add(this->label29);
			this->panel25->Location = System::Drawing::Point(1746, 187);
			this->panel25->Name = L"panel25";
			this->panel25->Size = System::Drawing::Size(45, 190);
			this->panel25->TabIndex = 38;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->BackColor = System::Drawing::Color::Yellow;
			this->label29->Location = System::Drawing::Point(3, 12);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(31, 15);
			this->label29->TabIndex = 0;
			this->label29->Text = L"R24";
			// 
			// panel26
			// 
			this->panel26->BackColor = System::Drawing::Color::Yellow;
			this->panel26->Controls->Add(this->label30);
			this->panel26->Location = System::Drawing::Point(1430, 383);
			this->panel26->Name = L"panel26";
			this->panel26->Size = System::Drawing::Size(191, 38);
			this->panel26->TabIndex = 39;
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
			this->panel27->Location = System::Drawing::Point(1289, 383);
			this->panel27->Name = L"panel27";
			this->panel27->Size = System::Drawing::Size(141, 38);
			this->panel27->TabIndex = 40;
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
			this->panel28->Location = System::Drawing::Point(1162, 383);
			this->panel28->Name = L"panel28";
			this->panel28->Size = System::Drawing::Size(121, 38);
			this->panel28->TabIndex = 41;
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
			this->panel29->Location = System::Drawing::Point(1079, 313);
			this->panel29->Name = L"panel29";
			this->panel29->Size = System::Drawing::Size(77, 108);
			this->panel29->TabIndex = 42;
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
			this->panel30->Location = System::Drawing::Point(1079, 199);
			this->panel30->Name = L"panel30";
			this->panel30->Size = System::Drawing::Size(77, 116);
			this->panel30->TabIndex = 43;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->BackColor = System::Drawing::Color::Yellow;
			this->label34->Location = System::Drawing::Point(23, 41);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(31, 15);
			this->label34->TabIndex = 0;
			this->label34->Text = L"R29";
			// 
			// panel31
			// 
			this->panel31->BackColor = System::Drawing::Color::Yellow;
			this->panel31->Controls->Add(this->label35);
			this->panel31->Location = System::Drawing::Point(1430, 427);
			this->panel31->Name = L"panel31";
			this->panel31->Size = System::Drawing::Size(191, 32);
			this->panel31->TabIndex = 44;
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
			this->panel32->Location = System::Drawing::Point(1289, 427);
			this->panel32->Name = L"panel32";
			this->panel32->Size = System::Drawing::Size(139, 32);
			this->panel32->TabIndex = 45;
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
			this->panel33->Location = System::Drawing::Point(1162, 427);
			this->panel33->Name = L"panel33";
			this->panel33->Size = System::Drawing::Size(121, 32);
			this->panel33->TabIndex = 46;
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
			this->panel34->Location = System::Drawing::Point(1006, 427);
			this->panel34->Name = L"panel34";
			this->panel34->Size = System::Drawing::Size(150, 32);
			this->panel34->TabIndex = 47;
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
			// panel35
			// 
			this->panel35->BackColor = System::Drawing::Color::Yellow;
			this->panel35->Controls->Add(this->label39);
			this->panel35->Location = System::Drawing::Point(1006, 313);
			this->panel35->Name = L"panel35";
			this->panel35->Size = System::Drawing::Size(67, 108);
			this->panel35->TabIndex = 48;
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
			this->panel36->Location = System::Drawing::Point(1006, 199);
			this->panel36->Name = L"panel36";
			this->panel36->Size = System::Drawing::Size(65, 116);
			this->panel36->TabIndex = 49;
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
			this->panel37->Location = System::Drawing::Point(901, 196);
			this->panel37->Name = L"panel37";
			this->panel37->Size = System::Drawing::Size(47, 78);
			this->panel37->TabIndex = 50;
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
			this->panel38->Location = System::Drawing::Point(954, 196);
			this->panel38->Name = L"panel38";
			this->panel38->Size = System::Drawing::Size(46, 78);
			this->panel38->TabIndex = 51;
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
			this->panel39->Location = System::Drawing::Point(901, 280);
			this->panel39->Name = L"panel39";
			this->panel39->Size = System::Drawing::Size(47, 79);
			this->panel39->TabIndex = 52;
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
			this->panel40->Location = System::Drawing::Point(954, 280);
			this->panel40->Name = L"panel40";
			this->panel40->Size = System::Drawing::Size(46, 79);
			this->panel40->TabIndex = 53;
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
			this->panel41->Location = System::Drawing::Point(901, 365);
			this->panel41->Name = L"panel41";
			this->panel41->Size = System::Drawing::Size(47, 99);
			this->panel41->TabIndex = 54;
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
			this->panel42->Location = System::Drawing::Point(954, 365);
			this->panel42->Name = L"panel42";
			this->panel42->Size = System::Drawing::Size(46, 99);
			this->panel42->TabIndex = 55;
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
			this->panel43->Location = System::Drawing::Point(1243, 653);
			this->panel43->Name = L"panel43";
			this->panel43->Size = System::Drawing::Size(57, 87);
			this->panel43->TabIndex = 56;
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
			this->panel44->Location = System::Drawing::Point(1243, 565);
			this->panel44->Name = L"panel44";
			this->panel44->Size = System::Drawing::Size(57, 82);
			this->panel44->TabIndex = 57;
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
			this->panel45->Location = System::Drawing::Point(1310, 554);
			this->panel45->Name = L"panel45";
			this->panel45->Size = System::Drawing::Size(120, 42);
			this->panel45->TabIndex = 58;
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
			this->panel46->Location = System::Drawing::Point(1430, 554);
			this->panel46->Name = L"panel46";
			this->panel46->Size = System::Drawing::Size(98, 45);
			this->panel46->TabIndex = 59;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->BackColor = System::Drawing::Color::Yellow;
			this->label50->Location = System::Drawing::Point(16, 18);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(31, 15);
			this->label50->TabIndex = 0;
			this->label50->Text = L"R45";
			// 
			// panel47
			// 
			this->panel47->BackColor = System::Drawing::Color::Yellow;
			this->panel47->Controls->Add(this->label51);
			this->panel47->Location = System::Drawing::Point(1530, 554);
			this->panel47->Name = L"panel47";
			this->panel47->Size = System::Drawing::Size(98, 45);
			this->panel47->TabIndex = 60;
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
			this->panel48->Location = System::Drawing::Point(1634, 554);
			this->panel48->Name = L"panel48";
			this->panel48->Size = System::Drawing::Size(82, 45);
			this->panel48->TabIndex = 61;
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
			this->panel49->Location = System::Drawing::Point(1686, 605);
			this->panel49->Name = L"panel49";
			this->panel49->Size = System::Drawing::Size(44, 68);
			this->panel49->TabIndex = 62;
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
			this->panel50->Location = System::Drawing::Point(1736, 605);
			this->panel50->Name = L"panel50";
			this->panel50->Size = System::Drawing::Size(44, 68);
			this->panel50->TabIndex = 63;
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->BackColor = System::Drawing::Color::Yellow;
			this->label54->Location = System::Drawing::Point(7, 26);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(31, 15);
			this->label54->TabIndex = 0;
			this->label54->Text = L"R49";
			// 
			// panel51
			// 
			this->panel51->BackColor = System::Drawing::Color::Yellow;
			this->panel51->Controls->Add(this->label55);
			this->panel51->Location = System::Drawing::Point(1786, 569);
			this->panel51->Name = L"panel51";
			this->panel51->Size = System::Drawing::Size(51, 104);
			this->panel51->TabIndex = 64;
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
			this->panel52->Location = System::Drawing::Point(1722, 518);
			this->panel52->Name = L"panel52";
			this->panel52->Size = System::Drawing::Size(102, 45);
			this->panel52->TabIndex = 65;
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
			this->panel53->Location = System::Drawing::Point(1534, 518);
			this->panel53->Name = L"panel53";
			this->panel53->Size = System::Drawing::Size(182, 30);
			this->panel53->TabIndex = 66;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->BackColor = System::Drawing::Color::Yellow;
			this->label57->Location = System::Drawing::Point(47, 12);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(31, 15);
			this->label57->TabIndex = 0;
			this->label57->Text = L"R52";
			// 
			// panel54
			// 
			this->panel54->BackColor = System::Drawing::Color::Yellow;
			this->panel54->Controls->Add(this->label58);
			this->panel54->Location = System::Drawing::Point(1433, 518);
			this->panel54->Name = L"panel54";
			this->panel54->Size = System::Drawing::Size(89, 30);
			this->panel54->TabIndex = 67;
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
			this->panel55->Location = System::Drawing::Point(1310, 518);
			this->panel55->Name = L"panel55";
			this->panel55->Size = System::Drawing::Size(117, 30);
			this->panel55->TabIndex = 68;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->BackColor = System::Drawing::Color::Yellow;
			this->label59->Location = System::Drawing::Point(32, 0);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(31, 15);
			this->label59->TabIndex = 0;
			this->label59->Text = L"R54";
			// 
			// panel56
			// 
			this->panel56->BackColor = System::Drawing::Color::Yellow;
			this->panel56->Controls->Add(this->label60);
			this->panel56->Location = System::Drawing::Point(1171, 518);
			this->panel56->Name = L"panel56";
			this->panel56->Size = System::Drawing::Size(122, 45);
			this->panel56->TabIndex = 69;
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
			this->panel57->Location = System::Drawing::Point(1171, 565);
			this->panel57->Name = L"panel57";
			this->panel57->Size = System::Drawing::Size(67, 176);
			this->panel57->TabIndex = 70;
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
			this->panel58->Location = System::Drawing::Point(1171, 747);
			this->panel58->Name = L"panel58";
			this->panel58->Size = System::Drawing::Size(130, 30);
			this->panel58->TabIndex = 71;
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
			// panel59
			// 
			this->panel59->BackColor = System::Drawing::Color::Pink;
			this->panel59->Controls->Add(this->label3);
			this->panel59->Location = System::Drawing::Point(1433, 605);
			this->panel59->Name = L"panel59";
			this->panel59->Size = System::Drawing::Size(47, 78);
			this->panel59->TabIndex = 72;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Pink;
			this->label3->Location = System::Drawing::Point(10, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 15);
			this->label3->TabIndex = 0;
			this->label3->Text = L"E04";
			// 
			// panel60
			// 
			this->panel60->BackColor = System::Drawing::Color::Pink;
			this->panel60->Controls->Add(this->label4);
			this->panel60->Location = System::Drawing::Point(1481, 605);
			this->panel60->Name = L"panel60";
			this->panel60->Size = System::Drawing::Size(47, 78);
			this->panel60->TabIndex = 73;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Pink;
			this->label4->Location = System::Drawing::Point(10, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 15);
			this->label4->TabIndex = 0;
			this->label4->Text = L"E05";
			// 
			// panel61
			// 
			this->panel61->BackColor = System::Drawing::Color::Pink;
			this->panel61->Controls->Add(this->label63);
			this->panel61->Location = System::Drawing::Point(1433, 683);
			this->panel61->Name = L"panel61";
			this->panel61->Size = System::Drawing::Size(47, 57);
			this->panel61->TabIndex = 74;
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->BackColor = System::Drawing::Color::Pink;
			this->label63->Location = System::Drawing::Point(10, 30);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(31, 15);
			this->label63->TabIndex = 0;
			this->label63->Text = L"E06";
			// 
			// panel62
			// 
			this->panel62->BackColor = System::Drawing::Color::Pink;
			this->panel62->Controls->Add(this->label64);
			this->panel62->Location = System::Drawing::Point(1481, 684);
			this->panel62->Name = L"panel62";
			this->panel62->Size = System::Drawing::Size(47, 57);
			this->panel62->TabIndex = 75;
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->BackColor = System::Drawing::Color::Pink;
			this->label64->Location = System::Drawing::Point(10, 30);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(31, 15);
			this->label64->TabIndex = 0;
			this->label64->Text = L"E07";
			// 
			// panel63
			// 
			this->panel63->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel63->Controls->Add(this->label65);
			this->panel63->Location = System::Drawing::Point(1306, 605);
			this->panel63->Name = L"panel63";
			this->panel63->Size = System::Drawing::Size(40, 78);
			this->panel63->TabIndex = 76;
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label65->Location = System::Drawing::Point(6, 30);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(31, 15);
			this->label65->TabIndex = 0;
			this->label65->Text = L"T12";
			// 
			// panel64
			// 
			this->panel64->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel64->Controls->Add(this->label66);
			this->panel64->Location = System::Drawing::Point(1351, 605);
			this->panel64->Name = L"panel64";
			this->panel64->Size = System::Drawing::Size(40, 78);
			this->panel64->TabIndex = 77;
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label66->Location = System::Drawing::Point(3, 30);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(31, 15);
			this->label66->TabIndex = 0;
			this->label66->Text = L"T13";
			// 
			// panel65
			// 
			this->panel65->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel65->Controls->Add(this->label67);
			this->panel65->Location = System::Drawing::Point(1387, 605);
			this->panel65->Name = L"panel65";
			this->panel65->Size = System::Drawing::Size(40, 78);
			this->panel65->TabIndex = 78;
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label67->Location = System::Drawing::Point(6, 30);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(31, 15);
			this->label67->TabIndex = 0;
			this->label67->Text = L"T14";
			// 
			// panel66
			// 
			this->panel66->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel66->Controls->Add(this->label68);
			this->panel66->Location = System::Drawing::Point(1307, 684);
			this->panel66->Name = L"panel66";
			this->panel66->Size = System::Drawing::Size(40, 57);
			this->panel66->TabIndex = 79;
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label68->Location = System::Drawing::Point(8, 16);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(31, 15);
			this->label68->TabIndex = 0;
			this->label68->Text = L"T15";
			// 
			// panel67
			// 
			this->panel67->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel67->Controls->Add(this->label69);
			this->panel67->Location = System::Drawing::Point(1351, 683);
			this->panel67->Name = L"panel67";
			this->panel67->Size = System::Drawing::Size(40, 57);
			this->panel67->TabIndex = 80;
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label69->Location = System::Drawing::Point(1, 19);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(31, 15);
			this->label69->TabIndex = 0;
			this->label69->Text = L"T16";
			// 
			// panel68
			// 
			this->panel68->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel68->Controls->Add(this->label70);
			this->panel68->Location = System::Drawing::Point(1390, 683);
			this->panel68->Name = L"panel68";
			this->panel68->Size = System::Drawing::Size(40, 57);
			this->panel68->TabIndex = 81;
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label70->Location = System::Drawing::Point(3, 19);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(31, 15);
			this->label70->TabIndex = 0;
			this->label70->Text = L"T17";
			// 
			// panel69
			// 
			this->panel69->BackColor = System::Drawing::Color::Pink;
			this->panel69->Controls->Add(this->label71);
			this->panel69->Location = System::Drawing::Point(798, 352);
			this->panel69->Name = L"panel69";
			this->panel69->Size = System::Drawing::Size(47, 58);
			this->panel69->TabIndex = 82;
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->BackColor = System::Drawing::Color::Pink;
			this->label71->Location = System::Drawing::Point(3, 22);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(31, 15);
			this->label71->TabIndex = 0;
			this->label71->Text = L"E00";
			// 
			// panel70
			// 
			this->panel70->BackColor = System::Drawing::Color::Pink;
			this->panel70->Controls->Add(this->label72);
			this->panel70->Location = System::Drawing::Point(848, 352);
			this->panel70->Name = L"panel70";
			this->panel70->Size = System::Drawing::Size(47, 58);
			this->panel70->TabIndex = 83;
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->BackColor = System::Drawing::Color::Pink;
			this->label72->Location = System::Drawing::Point(3, 22);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(31, 15);
			this->label72->TabIndex = 0;
			this->label72->Text = L"E01";
			// 
			// panel71
			// 
			this->panel71->BackColor = System::Drawing::Color::Pink;
			this->panel71->Controls->Add(this->label73);
			this->panel71->Location = System::Drawing::Point(798, 411);
			this->panel71->Name = L"panel71";
			this->panel71->Size = System::Drawing::Size(47, 48);
			this->panel71->TabIndex = 84;
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->BackColor = System::Drawing::Color::Pink;
			this->label73->Location = System::Drawing::Point(3, 22);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(31, 15);
			this->label73->TabIndex = 0;
			this->label73->Text = L"E02";
			// 
			// panel72
			// 
			this->panel72->BackColor = System::Drawing::Color::Pink;
			this->panel72->Controls->Add(this->label74);
			this->panel72->Location = System::Drawing::Point(848, 411);
			this->panel72->Name = L"panel72";
			this->panel72->Size = System::Drawing::Size(47, 48);
			this->panel72->TabIndex = 85;
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->BackColor = System::Drawing::Color::Pink;
			this->label74->Location = System::Drawing::Point(3, 22);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(31, 15);
			this->label74->TabIndex = 0;
			this->label74->Text = L"E03";
			// 
			// panel73
			// 
			this->panel73->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel73->Controls->Add(this->label75);
			this->panel73->Location = System::Drawing::Point(1568, 193);
			this->panel73->Name = L"panel73";
			this->panel73->Size = System::Drawing::Size(48, 81);
			this->panel73->TabIndex = 86;
			// 
			// label75
			// 
			this->label75->AutoSize = true;
			this->label75->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label75->Location = System::Drawing::Point(10, 30);
			this->label75->Name = L"label75";
			this->label75->Size = System::Drawing::Size(31, 15);
			this->label75->TabIndex = 0;
			this->label75->Text = L"T00";
			// 
			// panel74
			// 
			this->panel74->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel74->Controls->Add(this->label76);
			this->panel74->Location = System::Drawing::Point(1612, 193);
			this->panel74->Name = L"panel74";
			this->panel74->Size = System::Drawing::Size(40, 81);
			this->panel74->TabIndex = 87;
			// 
			// label76
			// 
			this->label76->AutoSize = true;
			this->label76->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label76->Location = System::Drawing::Point(3, 29);
			this->label76->Name = L"label76";
			this->label76->Size = System::Drawing::Size(31, 15);
			this->label76->TabIndex = 0;
			this->label76->Text = L"T01";
			// 
			// panel75
			// 
			this->panel75->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel75->Controls->Add(this->label77);
			this->panel75->Location = System::Drawing::Point(1650, 193);
			this->panel75->Name = L"panel75";
			this->panel75->Size = System::Drawing::Size(43, 81);
			this->panel75->TabIndex = 88;
			// 
			// label77
			// 
			this->label77->AutoSize = true;
			this->label77->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label77->Location = System::Drawing::Point(3, 30);
			this->label77->Name = L"label77";
			this->label77->Size = System::Drawing::Size(31, 15);
			this->label77->TabIndex = 0;
			this->label77->Text = L"T02";
			// 
			// panel76
			// 
			this->panel76->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel76->Controls->Add(this->label78);
			this->panel76->Location = System::Drawing::Point(1650, 299);
			this->panel76->Name = L"panel76";
			this->panel76->Size = System::Drawing::Size(40, 78);
			this->panel76->TabIndex = 89;
			// 
			// label78
			// 
			this->label78->AutoSize = true;
			this->label78->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label78->Location = System::Drawing::Point(2, 32);
			this->label78->Name = L"label78";
			this->label78->Size = System::Drawing::Size(31, 15);
			this->label78->TabIndex = 0;
			this->label78->Text = L"T03";
			// 
			// panel77
			// 
			this->panel77->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel77->Controls->Add(this->label79);
			this->panel77->Location = System::Drawing::Point(1612, 299);
			this->panel77->Name = L"panel77";
			this->panel77->Size = System::Drawing::Size(40, 78);
			this->panel77->TabIndex = 90;
			// 
			// label79
			// 
			this->label79->AutoSize = true;
			this->label79->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label79->Location = System::Drawing::Point(6, 30);
			this->label79->Name = L"label79";
			this->label79->Size = System::Drawing::Size(31, 15);
			this->label79->TabIndex = 0;
			this->label79->Text = L"T04";
			// 
			// panel78
			// 
			this->panel78->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel78->Controls->Add(this->label80);
			this->panel78->Location = System::Drawing::Point(1568, 299);
			this->panel78->Name = L"panel78";
			this->panel78->Size = System::Drawing::Size(48, 78);
			this->panel78->TabIndex = 91;
			// 
			// label80
			// 
			this->label80->AutoSize = true;
			this->label80->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label80->Location = System::Drawing::Point(10, 30);
			this->label80->Name = L"label80";
			this->label80->Size = System::Drawing::Size(31, 15);
			this->label80->TabIndex = 0;
			this->label80->Text = L"T05";
			// 
			// panel79
			// 
			this->panel79->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel79->Controls->Add(this->label81);
			this->panel79->Location = System::Drawing::Point(798, 196);
			this->panel79->Name = L"panel79";
			this->panel79->Size = System::Drawing::Size(40, 65);
			this->panel79->TabIndex = 92;
			// 
			// label81
			// 
			this->label81->AutoSize = true;
			this->label81->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label81->Location = System::Drawing::Point(3, 27);
			this->label81->Name = L"label81";
			this->label81->Size = System::Drawing::Size(31, 15);
			this->label81->TabIndex = 0;
			this->label81->Text = L"T06";
			// 
			// panel80
			// 
			this->panel80->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel80->Controls->Add(this->label82);
			this->panel80->Location = System::Drawing::Point(848, 196);
			this->panel80->Name = L"panel80";
			this->panel80->Size = System::Drawing::Size(40, 65);
			this->panel80->TabIndex = 93;
			// 
			// label82
			// 
			this->label82->AutoSize = true;
			this->label82->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label82->Location = System::Drawing::Point(3, 27);
			this->label82->Name = L"label82";
			this->label82->Size = System::Drawing::Size(31, 15);
			this->label82->TabIndex = 0;
			this->label82->Text = L"T07";
			// 
			// panel81
			// 
			this->panel81->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel81->Controls->Add(this->label83);
			this->panel81->Location = System::Drawing::Point(799, 260);
			this->panel81->Name = L"panel81";
			this->panel81->Size = System::Drawing::Size(40, 55);
			this->panel81->TabIndex = 94;
			// 
			// label83
			// 
			this->label83->AutoSize = true;
			this->label83->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label83->Location = System::Drawing::Point(6, 20);
			this->label83->Name = L"label83";
			this->label83->Size = System::Drawing::Size(31, 15);
			this->label83->TabIndex = 0;
			this->label83->Text = L"T08";
			// 
			// panel82
			// 
			this->panel82->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel82->Controls->Add(this->label84);
			this->panel82->Location = System::Drawing::Point(848, 260);
			this->panel82->Name = L"panel82";
			this->panel82->Size = System::Drawing::Size(40, 42);
			this->panel82->TabIndex = 95;
			// 
			// label84
			// 
			this->label84->AutoSize = true;
			this->label84->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label84->Location = System::Drawing::Point(6, 20);
			this->label84->Name = L"label84";
			this->label84->Size = System::Drawing::Size(31, 15);
			this->label84->TabIndex = 0;
			this->label84->Text = L"T09";
			// 
			// panel83
			// 
			this->panel83->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel83->Controls->Add(this->label85);
			this->panel83->Location = System::Drawing::Point(798, 304);
			this->panel83->Name = L"panel83";
			this->panel83->Size = System::Drawing::Size(40, 42);
			this->panel83->TabIndex = 96;
			// 
			// label85
			// 
			this->label85->AutoSize = true;
			this->label85->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label85->Location = System::Drawing::Point(6, 20);
			this->label85->Name = L"label85";
			this->label85->Size = System::Drawing::Size(31, 15);
			this->label85->TabIndex = 0;
			this->label85->Text = L"T10";
			// 
			// panel84
			// 
			this->panel84->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel84->Controls->Add(this->label86);
			this->panel84->Location = System::Drawing::Point(848, 308);
			this->panel84->Name = L"panel84";
			this->panel84->Size = System::Drawing::Size(40, 42);
			this->panel84->TabIndex = 97;
			// 
			// label86
			// 
			this->label86->AutoSize = true;
			this->label86->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label86->Location = System::Drawing::Point(6, 20);
			this->label86->Name = L"label86";
			this->label86->Size = System::Drawing::Size(31, 15);
			this->label86->TabIndex = 0;
			this->label86->Text = L"T11";
			// 
			// panel85
			// 
			this->panel85->BackColor = System::Drawing::Color::Aqua;
			this->panel85->Controls->Add(this->label87);
			this->panel85->Location = System::Drawing::Point(698, 40);
			this->panel85->Name = L"panel85";
			this->panel85->Size = System::Drawing::Size(59, 48);
			this->panel85->TabIndex = 98;
			// 
			// label87
			// 
			this->label87->AutoSize = true;
			this->label87->BackColor = System::Drawing::Color::Aqua;
			this->label87->Location = System::Drawing::Point(15, 19);
			this->label87->Name = L"label87";
			this->label87->Size = System::Drawing::Size(31, 15);
			this->label87->TabIndex = 0;
			this->label87->Text = L"C00";
			// 
			// panel86
			// 
			this->panel86->BackColor = System::Drawing::Color::Aqua;
			this->panel86->Controls->Add(this->label88);
			this->panel86->Location = System::Drawing::Point(763, 40);
			this->panel86->Name = L"panel86";
			this->panel86->Size = System::Drawing::Size(52, 48);
			this->panel86->TabIndex = 99;
			// 
			// label88
			// 
			this->label88->AutoSize = true;
			this->label88->BackColor = System::Drawing::Color::Cyan;
			this->label88->Location = System::Drawing::Point(3, 19);
			this->label88->Name = L"label88";
			this->label88->Size = System::Drawing::Size(31, 15);
			this->label88->TabIndex = 0;
			this->label88->Text = L"C01";
			// 
			// panel87
			// 
			this->panel87->BackColor = System::Drawing::Color::Aqua;
			this->panel87->Controls->Add(this->label89);
			this->panel87->Location = System::Drawing::Point(821, 40);
			this->panel87->Name = L"panel87";
			this->panel87->Size = System::Drawing::Size(59, 48);
			this->panel87->TabIndex = 100;
			// 
			// label89
			// 
			this->label89->AutoSize = true;
			this->label89->BackColor = System::Drawing::Color::Aqua;
			this->label89->Location = System::Drawing::Point(15, 19);
			this->label89->Name = L"label89";
			this->label89->Size = System::Drawing::Size(31, 15);
			this->label89->TabIndex = 0;
			this->label89->Text = L"C02";
			// 
			// panel88
			// 
			this->panel88->BackColor = System::Drawing::Color::Aqua;
			this->panel88->Controls->Add(this->label90);
			this->panel88->Location = System::Drawing::Point(886, 41);
			this->panel88->Name = L"panel88";
			this->panel88->Size = System::Drawing::Size(59, 48);
			this->panel88->TabIndex = 101;
			// 
			// label90
			// 
			this->label90->AutoSize = true;
			this->label90->BackColor = System::Drawing::Color::Cyan;
			this->label90->Location = System::Drawing::Point(15, 19);
			this->label90->Name = L"label90";
			this->label90->Size = System::Drawing::Size(31, 15);
			this->label90->TabIndex = 0;
			this->label90->Text = L"C03";
			// 
			// panel89
			// 
			this->panel89->BackColor = System::Drawing::Color::Aqua;
			this->panel89->Controls->Add(this->label91);
			this->panel89->Location = System::Drawing::Point(951, 49);
			this->panel89->Name = L"panel89";
			this->panel89->Size = System::Drawing::Size(46, 40);
			this->panel89->TabIndex = 102;
			// 
			// label91
			// 
			this->label91->AutoSize = true;
			this->label91->BackColor = System::Drawing::Color::Cyan;
			this->label91->Location = System::Drawing::Point(3, 15);
			this->label91->Name = L"label91";
			this->label91->Size = System::Drawing::Size(31, 15);
			this->label91->TabIndex = 0;
			this->label91->Text = L"C04";
			// 
			// panel90
			// 
			this->panel90->BackColor = System::Drawing::Color::Aqua;
			this->panel90->Controls->Add(this->label92);
			this->panel90->Location = System::Drawing::Point(951, 4);
			this->panel90->Name = L"panel90";
			this->panel90->Size = System::Drawing::Size(46, 40);
			this->panel90->TabIndex = 103;
			// 
			// label92
			// 
			this->label92->AutoSize = true;
			this->label92->BackColor = System::Drawing::Color::Cyan;
			this->label92->Location = System::Drawing::Point(3, 2);
			this->label92->Name = L"label92";
			this->label92->Size = System::Drawing::Size(31, 15);
			this->label92->TabIndex = 0;
			this->label92->Text = L"C05";
			// 
			// panel91
			// 
			this->panel91->BackColor = System::Drawing::Color::Aqua;
			this->panel91->Controls->Add(this->label93);
			this->panel91->Location = System::Drawing::Point(1063, 49);
			this->panel91->Name = L"panel91";
			this->panel91->Size = System::Drawing::Size(46, 39);
			this->panel91->TabIndex = 104;
			// 
			// label93
			// 
			this->label93->AutoSize = true;
			this->label93->BackColor = System::Drawing::Color::Cyan;
			this->label93->Location = System::Drawing::Point(3, 15);
			this->label93->Name = L"label93";
			this->label93->Size = System::Drawing::Size(31, 15);
			this->label93->TabIndex = 0;
			this->label93->Text = L"C06";
			// 
			// panel92
			// 
			this->panel92->BackColor = System::Drawing::Color::Aqua;
			this->panel92->Controls->Add(this->label94);
			this->panel92->Location = System::Drawing::Point(1063, 4);
			this->panel92->Name = L"panel92";
			this->panel92->Size = System::Drawing::Size(46, 39);
			this->panel92->TabIndex = 105;
			// 
			// label94
			// 
			this->label94->AutoSize = true;
			this->label94->BackColor = System::Drawing::Color::Cyan;
			this->label94->Location = System::Drawing::Point(3, 15);
			this->label94->Name = L"label94";
			this->label94->Size = System::Drawing::Size(31, 15);
			this->label94->TabIndex = 0;
			this->label94->Text = L"C07";
			// 
			// panel93
			// 
			this->panel93->BackColor = System::Drawing::Color::Aqua;
			this->panel93->Controls->Add(this->label95);
			this->panel93->Location = System::Drawing::Point(1116, 49);
			this->panel93->Name = L"panel93";
			this->panel93->Size = System::Drawing::Size(46, 39);
			this->panel93->TabIndex = 106;
			// 
			// label95
			// 
			this->label95->AutoSize = true;
			this->label95->BackColor = System::Drawing::Color::Cyan;
			this->label95->Location = System::Drawing::Point(3, 14);
			this->label95->Name = L"label95";
			this->label95->Size = System::Drawing::Size(31, 15);
			this->label95->TabIndex = 0;
			this->label95->Text = L"C08";
			// 
			// panel94
			// 
			this->panel94->BackColor = System::Drawing::Color::Aqua;
			this->panel94->Controls->Add(this->label96);
			this->panel94->Location = System::Drawing::Point(1115, 4);
			this->panel94->Name = L"panel94";
			this->panel94->Size = System::Drawing::Size(46, 39);
			this->panel94->TabIndex = 107;
			// 
			// label96
			// 
			this->label96->AutoSize = true;
			this->label96->BackColor = System::Drawing::Color::Cyan;
			this->label96->Location = System::Drawing::Point(3, 14);
			this->label96->Name = L"label96";
			this->label96->Size = System::Drawing::Size(31, 15);
			this->label96->TabIndex = 0;
			this->label96->Text = L"C09";
			// 
			// panel95
			// 
			this->panel95->BackColor = System::Drawing::Color::Aqua;
			this->panel95->Controls->Add(this->label97);
			this->panel95->Location = System::Drawing::Point(1184, 50);
			this->panel95->Name = L"panel95";
			this->panel95->Size = System::Drawing::Size(46, 39);
			this->panel95->TabIndex = 108;
			// 
			// label97
			// 
			this->label97->AutoSize = true;
			this->label97->BackColor = System::Drawing::Color::Cyan;
			this->label97->Location = System::Drawing::Point(3, 14);
			this->label97->Name = L"label97";
			this->label97->Size = System::Drawing::Size(31, 15);
			this->label97->TabIndex = 0;
			this->label97->Text = L"C10";
			// 
			// panel96
			// 
			this->panel96->BackColor = System::Drawing::Color::Aqua;
			this->panel96->Controls->Add(this->label98);
			this->panel96->Location = System::Drawing::Point(1236, 49);
			this->panel96->Name = L"panel96";
			this->panel96->Size = System::Drawing::Size(46, 39);
			this->panel96->TabIndex = 109;
			// 
			// label98
			// 
			this->label98->AutoSize = true;
			this->label98->BackColor = System::Drawing::Color::Cyan;
			this->label98->Location = System::Drawing::Point(3, 14);
			this->label98->Name = L"label98";
			this->label98->Size = System::Drawing::Size(31, 15);
			this->label98->TabIndex = 0;
			this->label98->Text = L"C11";
			// 
			// panel97
			// 
			this->panel97->BackColor = System::Drawing::Color::Aqua;
			this->panel97->Controls->Add(this->label99);
			this->panel97->Location = System::Drawing::Point(1184, 4);
			this->panel97->Name = L"panel97";
			this->panel97->Size = System::Drawing::Size(46, 39);
			this->panel97->TabIndex = 110;
			// 
			// label99
			// 
			this->label99->AutoSize = true;
			this->label99->BackColor = System::Drawing::Color::Aqua;
			this->label99->Location = System::Drawing::Point(3, 14);
			this->label99->Name = L"label99";
			this->label99->Size = System::Drawing::Size(31, 15);
			this->label99->TabIndex = 0;
			this->label99->Text = L"C12";
			// 
			// panel98
			// 
			this->panel98->BackColor = System::Drawing::Color::Aqua;
			this->panel98->Controls->Add(this->label100);
			this->panel98->Location = System::Drawing::Point(1237, 4);
			this->panel98->Name = L"panel98";
			this->panel98->Size = System::Drawing::Size(46, 39);
			this->panel98->TabIndex = 111;
			// 
			// label100
			// 
			this->label100->AutoSize = true;
			this->label100->BackColor = System::Drawing::Color::Cyan;
			this->label100->Location = System::Drawing::Point(3, 14);
			this->label100->Name = L"label100";
			this->label100->Size = System::Drawing::Size(31, 15);
			this->label100->TabIndex = 0;
			this->label100->Text = L"C13";
			// 
			// panel99
			// 
			this->panel99->BackColor = System::Drawing::Color::Aqua;
			this->panel99->Controls->Add(this->label101);
			this->panel99->Location = System::Drawing::Point(1289, 4);
			this->panel99->Name = L"panel99";
			this->panel99->Size = System::Drawing::Size(46, 39);
			this->panel99->TabIndex = 112;
			// 
			// label101
			// 
			this->label101->AutoSize = true;
			this->label101->BackColor = System::Drawing::Color::Aqua;
			this->label101->Location = System::Drawing::Point(3, 14);
			this->label101->Name = L"label101";
			this->label101->Size = System::Drawing::Size(31, 15);
			this->label101->TabIndex = 0;
			this->label101->Text = L"C14";
			// 
			// panel100
			// 
			this->panel100->BackColor = System::Drawing::Color::Aqua;
			this->panel100->Controls->Add(this->label102);
			this->panel100->Location = System::Drawing::Point(1289, 50);
			this->panel100->Name = L"panel100";
			this->panel100->Size = System::Drawing::Size(46, 39);
			this->panel100->TabIndex = 113;
			// 
			// label102
			// 
			this->label102->AutoSize = true;
			this->label102->BackColor = System::Drawing::Color::Cyan;
			this->label102->Location = System::Drawing::Point(3, 14);
			this->label102->Name = L"label102";
			this->label102->Size = System::Drawing::Size(31, 15);
			this->label102->TabIndex = 0;
			this->label102->Text = L"C15";
			// 
			// panel101
			// 
			this->panel101->BackColor = System::Drawing::Color::Aqua;
			this->panel101->Controls->Add(this->label103);
			this->panel101->Location = System::Drawing::Point(1344, 4);
			this->panel101->Name = L"panel101";
			this->panel101->Size = System::Drawing::Size(46, 39);
			this->panel101->TabIndex = 114;
			// 
			// label103
			// 
			this->label103->AutoSize = true;
			this->label103->BackColor = System::Drawing::Color::Cyan;
			this->label103->Location = System::Drawing::Point(3, 14);
			this->label103->Name = L"label103";
			this->label103->Size = System::Drawing::Size(31, 15);
			this->label103->TabIndex = 0;
			this->label103->Text = L"C16";
			// 
			// panel102
			// 
			this->panel102->BackColor = System::Drawing::Color::Aqua;
			this->panel102->Controls->Add(this->label104);
			this->panel102->Location = System::Drawing::Point(1346, 50);
			this->panel102->Name = L"panel102";
			this->panel102->Size = System::Drawing::Size(46, 39);
			this->panel102->TabIndex = 115;
			// 
			// label104
			// 
			this->label104->AutoSize = true;
			this->label104->BackColor = System::Drawing::Color::Cyan;
			this->label104->Location = System::Drawing::Point(3, 14);
			this->label104->Name = L"label104";
			this->label104->Size = System::Drawing::Size(31, 15);
			this->label104->TabIndex = 0;
			this->label104->Text = L"C17";
			// 
			// panel103
			// 
			this->panel103->BackColor = System::Drawing::Color::Aqua;
			this->panel103->Controls->Add(this->label105);
			this->panel103->Location = System::Drawing::Point(1400, 4);
			this->panel103->Name = L"panel103";
			this->panel103->Size = System::Drawing::Size(46, 39);
			this->panel103->TabIndex = 116;
			// 
			// label105
			// 
			this->label105->AutoSize = true;
			this->label105->BackColor = System::Drawing::Color::Cyan;
			this->label105->Location = System::Drawing::Point(3, 14);
			this->label105->Name = L"label105";
			this->label105->Size = System::Drawing::Size(31, 15);
			this->label105->TabIndex = 0;
			this->label105->Text = L"C18";
			// 
			// panel104
			// 
			this->panel104->BackColor = System::Drawing::Color::Aqua;
			this->panel104->Controls->Add(this->label106);
			this->panel104->Location = System::Drawing::Point(1452, 4);
			this->panel104->Name = L"panel104";
			this->panel104->Size = System::Drawing::Size(46, 39);
			this->panel104->TabIndex = 117;
			// 
			// label106
			// 
			this->label106->AutoSize = true;
			this->label106->BackColor = System::Drawing::Color::Aqua;
			this->label106->Location = System::Drawing::Point(3, 14);
			this->label106->Name = L"label106";
			this->label106->Size = System::Drawing::Size(31, 15);
			this->label106->TabIndex = 0;
			this->label106->Text = L"C19";
			// 
			// panel105
			// 
			this->panel105->BackColor = System::Drawing::Color::Aqua;
			this->panel105->Controls->Add(this->label107);
			this->panel105->Location = System::Drawing::Point(1401, 51);
			this->panel105->Name = L"panel105";
			this->panel105->Size = System::Drawing::Size(46, 38);
			this->panel105->TabIndex = 118;
			// 
			// label107
			// 
			this->label107->AutoSize = true;
			this->label107->BackColor = System::Drawing::Color::Cyan;
			this->label107->Location = System::Drawing::Point(3, 14);
			this->label107->Name = L"label107";
			this->label107->Size = System::Drawing::Size(31, 15);
			this->label107->TabIndex = 0;
			this->label107->Text = L"C20";
			// 
			// panel106
			// 
			this->panel106->BackColor = System::Drawing::Color::Aqua;
			this->panel106->Controls->Add(this->label108);
			this->panel106->Location = System::Drawing::Point(1453, 50);
			this->panel106->Name = L"panel106";
			this->panel106->Size = System::Drawing::Size(46, 39);
			this->panel106->TabIndex = 119;
			// 
			// label108
			// 
			this->label108->AutoSize = true;
			this->label108->BackColor = System::Drawing::Color::Cyan;
			this->label108->Location = System::Drawing::Point(3, 14);
			this->label108->Name = L"label108";
			this->label108->Size = System::Drawing::Size(31, 15);
			this->label108->TabIndex = 0;
			this->label108->Text = L"C21";
			// 
			// panel107
			// 
			this->panel107->BackColor = System::Drawing::Color::Aqua;
			this->panel107->Controls->Add(this->label109);
			this->panel107->Location = System::Drawing::Point(1513, 4);
			this->panel107->Name = L"panel107";
			this->panel107->Size = System::Drawing::Size(46, 39);
			this->panel107->TabIndex = 120;
			// 
			// label109
			// 
			this->label109->AutoSize = true;
			this->label109->BackColor = System::Drawing::Color::Cyan;
			this->label109->Location = System::Drawing::Point(3, 14);
			this->label109->Name = L"label109";
			this->label109->Size = System::Drawing::Size(31, 15);
			this->label109->TabIndex = 0;
			this->label109->Text = L"C22";
			// 
			// panel108
			// 
			this->panel108->BackColor = System::Drawing::Color::Aqua;
			this->panel108->Controls->Add(this->label110);
			this->panel108->Location = System::Drawing::Point(1581, 4);
			this->panel108->Name = L"panel108";
			this->panel108->Size = System::Drawing::Size(46, 39);
			this->panel108->TabIndex = 121;
			// 
			// label110
			// 
			this->label110->AutoSize = true;
			this->label110->BackColor = System::Drawing::Color::Cyan;
			this->label110->Location = System::Drawing::Point(3, 14);
			this->label110->Name = L"label110";
			this->label110->Size = System::Drawing::Size(31, 15);
			this->label110->TabIndex = 0;
			this->label110->Text = L"C23";
			// 
			// panel109
			// 
			this->panel109->BackColor = System::Drawing::Color::Aqua;
			this->panel109->Controls->Add(this->label111);
			this->panel109->Location = System::Drawing::Point(1513, 51);
			this->panel109->Name = L"panel109";
			this->panel109->Size = System::Drawing::Size(46, 39);
			this->panel109->TabIndex = 122;
			// 
			// label111
			// 
			this->label111->AutoSize = true;
			this->label111->BackColor = System::Drawing::Color::Cyan;
			this->label111->Location = System::Drawing::Point(3, 14);
			this->label111->Name = L"label111";
			this->label111->Size = System::Drawing::Size(31, 15);
			this->label111->TabIndex = 0;
			this->label111->Text = L"C24";
			// 
			// panel110
			// 
			this->panel110->BackColor = System::Drawing::Color::Aqua;
			this->panel110->Controls->Add(this->label112);
			this->panel110->Location = System::Drawing::Point(1581, 52);
			this->panel110->Name = L"panel110";
			this->panel110->Size = System::Drawing::Size(46, 38);
			this->panel110->TabIndex = 123;
			// 
			// label112
			// 
			this->label112->AutoSize = true;
			this->label112->BackColor = System::Drawing::Color::Cyan;
			this->label112->Location = System::Drawing::Point(3, 14);
			this->label112->Name = L"label112";
			this->label112->Size = System::Drawing::Size(31, 15);
			this->label112->TabIndex = 0;
			this->label112->Text = L"C25";
			// 
			// panel111
			// 
			this->panel111->BackColor = System::Drawing::Color::Aqua;
			this->panel111->Controls->Add(this->label113);
			this->panel111->Location = System::Drawing::Point(1663, 4);
			this->panel111->Name = L"panel111";
			this->panel111->Size = System::Drawing::Size(46, 39);
			this->panel111->TabIndex = 124;
			// 
			// label113
			// 
			this->label113->AutoSize = true;
			this->label113->BackColor = System::Drawing::Color::Cyan;
			this->label113->Location = System::Drawing::Point(3, 14);
			this->label113->Name = L"label113";
			this->label113->Size = System::Drawing::Size(31, 15);
			this->label113->TabIndex = 0;
			this->label113->Text = L"C26";
			// 
			// panel112
			// 
			this->panel112->BackColor = System::Drawing::Color::Aqua;
			this->panel112->Controls->Add(this->label114);
			this->panel112->Location = System::Drawing::Point(1728, 4);
			this->panel112->Name = L"panel112";
			this->panel112->Size = System::Drawing::Size(46, 39);
			this->panel112->TabIndex = 125;
			// 
			// label114
			// 
			this->label114->AutoSize = true;
			this->label114->BackColor = System::Drawing::Color::Cyan;
			this->label114->Location = System::Drawing::Point(3, 14);
			this->label114->Name = L"label114";
			this->label114->Size = System::Drawing::Size(31, 15);
			this->label114->TabIndex = 0;
			this->label114->Text = L"C27";
			// 
			// panel113
			// 
			this->panel113->BackColor = System::Drawing::Color::Aqua;
			this->panel113->Controls->Add(this->label115);
			this->panel113->Location = System::Drawing::Point(1786, 5);
			this->panel113->Name = L"panel113";
			this->panel113->Size = System::Drawing::Size(46, 39);
			this->panel113->TabIndex = 126;
			// 
			// label115
			// 
			this->label115->AutoSize = true;
			this->label115->BackColor = System::Drawing::Color::Cyan;
			this->label115->Location = System::Drawing::Point(3, 14);
			this->label115->Name = L"label115";
			this->label115->Size = System::Drawing::Size(31, 15);
			this->label115->TabIndex = 0;
			this->label115->Text = L"C28";
			// 
			// panel114
			// 
			this->panel114->BackColor = System::Drawing::Color::Aqua;
			this->panel114->Controls->Add(this->label116);
			this->panel114->Location = System::Drawing::Point(1786, 49);
			this->panel114->Name = L"panel114";
			this->panel114->Size = System::Drawing::Size(46, 39);
			this->panel114->TabIndex = 127;
			// 
			// label116
			// 
			this->label116->AutoSize = true;
			this->label116->BackColor = System::Drawing::Color::Cyan;
			this->label116->Location = System::Drawing::Point(3, 14);
			this->label116->Name = L"label116";
			this->label116->Size = System::Drawing::Size(31, 15);
			this->label116->TabIndex = 0;
			this->label116->Text = L"C29";
			// 
			// panel115
			// 
			this->panel115->BackColor = System::Drawing::Color::Aqua;
			this->panel115->Controls->Add(this->label117);
			this->panel115->Location = System::Drawing::Point(1792, 109);
			this->panel115->Name = L"panel115";
			this->panel115->Size = System::Drawing::Size(44, 39);
			this->panel115->TabIndex = 128;
			// 
			// label117
			// 
			this->label117->AutoSize = true;
			this->label117->BackColor = System::Drawing::Color::Cyan;
			this->label117->Location = System::Drawing::Point(3, 14);
			this->label117->Name = L"label117";
			this->label117->Size = System::Drawing::Size(31, 15);
			this->label117->TabIndex = 0;
			this->label117->Text = L"C30";
			// 
			// panel116
			// 
			this->panel116->BackColor = System::Drawing::Color::Aqua;
			this->panel116->Controls->Add(this->label118);
			this->panel116->Location = System::Drawing::Point(1791, 164);
			this->panel116->Name = L"panel116";
			this->panel116->Size = System::Drawing::Size(46, 39);
			this->panel116->TabIndex = 129;
			// 
			// label118
			// 
			this->label118->AutoSize = true;
			this->label118->BackColor = System::Drawing::Color::Cyan;
			this->label118->Location = System::Drawing::Point(3, 14);
			this->label118->Name = L"label118";
			this->label118->Size = System::Drawing::Size(31, 15);
			this->label118->TabIndex = 0;
			this->label118->Text = L"C31";
			// 
			// panel117
			// 
			this->panel117->BackColor = System::Drawing::Color::Aqua;
			this->panel117->Controls->Add(this->label119);
			this->panel117->Location = System::Drawing::Point(1793, 214);
			this->panel117->Name = L"panel117";
			this->panel117->Size = System::Drawing::Size(46, 39);
			this->panel117->TabIndex = 130;
			// 
			// label119
			// 
			this->label119->AutoSize = true;
			this->label119->BackColor = System::Drawing::Color::Cyan;
			this->label119->Location = System::Drawing::Point(3, 14);
			this->label119->Name = L"label119";
			this->label119->Size = System::Drawing::Size(31, 15);
			this->label119->TabIndex = 0;
			this->label119->Text = L"C32";
			// 
			// panel118
			// 
			this->panel118->BackColor = System::Drawing::Color::Aqua;
			this->panel118->Controls->Add(this->label120);
			this->panel118->Location = System::Drawing::Point(1792, 259);
			this->panel118->Name = L"panel118";
			this->panel118->Size = System::Drawing::Size(46, 39);
			this->panel118->TabIndex = 131;
			// 
			// label120
			// 
			this->label120->AutoSize = true;
			this->label120->BackColor = System::Drawing::Color::Cyan;
			this->label120->Location = System::Drawing::Point(3, 14);
			this->label120->Name = L"label120";
			this->label120->Size = System::Drawing::Size(31, 15);
			this->label120->TabIndex = 0;
			this->label120->Text = L"C33";
			// 
			// panel119
			// 
			this->panel119->BackColor = System::Drawing::Color::Aqua;
			this->panel119->Controls->Add(this->label121);
			this->panel119->Location = System::Drawing::Point(1793, 310);
			this->panel119->Name = L"panel119";
			this->panel119->Size = System::Drawing::Size(46, 39);
			this->panel119->TabIndex = 132;
			// 
			// label121
			// 
			this->label121->AutoSize = true;
			this->label121->BackColor = System::Drawing::Color::Cyan;
			this->label121->Location = System::Drawing::Point(3, 14);
			this->label121->Name = L"label121";
			this->label121->Size = System::Drawing::Size(31, 15);
			this->label121->TabIndex = 0;
			this->label121->Text = L"C34";
			// 
			// panel120
			// 
			this->panel120->BackColor = System::Drawing::Color::Aqua;
			this->panel120->Controls->Add(this->label122);
			this->panel120->Location = System::Drawing::Point(1793, 365);
			this->panel120->Name = L"panel120";
			this->panel120->Size = System::Drawing::Size(46, 39);
			this->panel120->TabIndex = 133;
			// 
			// label122
			// 
			this->label122->AutoSize = true;
			this->label122->BackColor = System::Drawing::Color::Cyan;
			this->label122->Location = System::Drawing::Point(3, 14);
			this->label122->Name = L"label122";
			this->label122->Size = System::Drawing::Size(31, 15);
			this->label122->TabIndex = 0;
			this->label122->Text = L"C35";
			// 
			// panel121
			// 
			this->panel121->BackColor = System::Drawing::Color::Aqua;
			this->panel121->Controls->Add(this->label123);
			this->panel121->Location = System::Drawing::Point(1793, 415);
			this->panel121->Name = L"panel121";
			this->panel121->Size = System::Drawing::Size(46, 39);
			this->panel121->TabIndex = 134;
			// 
			// label123
			// 
			this->label123->AutoSize = true;
			this->label123->BackColor = System::Drawing::Color::Cyan;
			this->label123->Location = System::Drawing::Point(3, 14);
			this->label123->Name = L"label123";
			this->label123->Size = System::Drawing::Size(31, 15);
			this->label123->TabIndex = 0;
			this->label123->Text = L"C36";
			// 
			// panel122
			// 
			this->panel122->BackColor = System::Drawing::Color::Aqua;
			this->panel122->Controls->Add(this->label124);
			this->panel122->Location = System::Drawing::Point(1793, 460);
			this->panel122->Name = L"panel122";
			this->panel122->Size = System::Drawing::Size(46, 39);
			this->panel122->TabIndex = 135;
			// 
			// label124
			// 
			this->label124->AutoSize = true;
			this->label124->BackColor = System::Drawing::Color::Aqua;
			this->label124->Location = System::Drawing::Point(3, 14);
			this->label124->Name = L"label124";
			this->label124->Size = System::Drawing::Size(31, 15);
			this->label124->TabIndex = 0;
			this->label124->Text = L"C37";
			// 
			// panel123
			// 
			this->panel123->BackColor = System::Drawing::Color::Aqua;
			this->panel123->Controls->Add(this->label125);
			this->panel123->Location = System::Drawing::Point(1752, 465);
			this->panel123->Name = L"panel123";
			this->panel123->Size = System::Drawing::Size(40, 38);
			this->panel123->TabIndex = 136;
			// 
			// label125
			// 
			this->label125->AutoSize = true;
			this->label125->BackColor = System::Drawing::Color::Cyan;
			this->label125->Location = System::Drawing::Point(3, 14);
			this->label125->Name = L"label125";
			this->label125->Size = System::Drawing::Size(31, 15);
			this->label125->TabIndex = 0;
			this->label125->Text = L"C38";
			// 
			// panel124
			// 
			this->panel124->BackColor = System::Drawing::Color::Aqua;
			this->panel124->Controls->Add(this->label126);
			this->panel124->Location = System::Drawing::Point(1709, 465);
			this->panel124->Name = L"panel124";
			this->panel124->Size = System::Drawing::Size(40, 38);
			this->panel124->TabIndex = 137;
			// 
			// label126
			// 
			this->label126->AutoSize = true;
			this->label126->BackColor = System::Drawing::Color::Cyan;
			this->label126->Location = System::Drawing::Point(3, 14);
			this->label126->Name = L"label126";
			this->label126->Size = System::Drawing::Size(31, 15);
			this->label126->TabIndex = 0;
			this->label126->Text = L"C39";
			// 
			// panel125
			// 
			this->panel125->BackColor = System::Drawing::Color::Aqua;
			this->panel125->Controls->Add(this->label127);
			this->panel125->Location = System::Drawing::Point(1663, 465);
			this->panel125->Name = L"panel125";
			this->panel125->Size = System::Drawing::Size(40, 38);
			this->panel125->TabIndex = 138;
			// 
			// label127
			// 
			this->label127->AutoSize = true;
			this->label127->BackColor = System::Drawing::Color::Aqua;
			this->label127->Location = System::Drawing::Point(3, 14);
			this->label127->Name = L"label127";
			this->label127->Size = System::Drawing::Size(31, 15);
			this->label127->TabIndex = 0;
			this->label127->Text = L"C40";
			// 
			// panel126
			// 
			this->panel126->BackColor = System::Drawing::Color::Aqua;
			this->panel126->Controls->Add(this->label128);
			this->panel126->Location = System::Drawing::Point(1464, 465);
			this->panel126->Name = L"panel126";
			this->panel126->Size = System::Drawing::Size(40, 38);
			this->panel126->TabIndex = 139;
			// 
			// label128
			// 
			this->label128->AutoSize = true;
			this->label128->BackColor = System::Drawing::Color::Cyan;
			this->label128->Location = System::Drawing::Point(3, 14);
			this->label128->Name = L"label128";
			this->label128->Size = System::Drawing::Size(31, 15);
			this->label128->TabIndex = 0;
			this->label128->Text = L"C41";
			// 
			// panel127
			// 
			this->panel127->BackColor = System::Drawing::Color::Aqua;
			this->panel127->Controls->Add(this->label129);
			this->panel127->Location = System::Drawing::Point(1504, 465);
			this->panel127->Name = L"panel127";
			this->panel127->Size = System::Drawing::Size(40, 38);
			this->panel127->TabIndex = 140;
			// 
			// label129
			// 
			this->label129->AutoSize = true;
			this->label129->BackColor = System::Drawing::Color::Cyan;
			this->label129->Location = System::Drawing::Point(3, 14);
			this->label129->Name = L"label129";
			this->label129->Size = System::Drawing::Size(31, 15);
			this->label129->TabIndex = 0;
			this->label129->Text = L"C42";
			// 
			// panel128
			// 
			this->panel128->BackColor = System::Drawing::Color::Aqua;
			this->panel128->Controls->Add(this->label130);
			this->panel128->Location = System::Drawing::Point(1544, 465);
			this->panel128->Name = L"panel128";
			this->panel128->Size = System::Drawing::Size(40, 38);
			this->panel128->TabIndex = 141;
			// 
			// label130
			// 
			this->label130->AutoSize = true;
			this->label130->BackColor = System::Drawing::Color::Cyan;
			this->label130->Location = System::Drawing::Point(3, 14);
			this->label130->Name = L"label130";
			this->label130->Size = System::Drawing::Size(31, 15);
			this->label130->TabIndex = 0;
			this->label130->Text = L"C43";
			// 
			// panel129
			// 
			this->panel129->BackColor = System::Drawing::Color::Aqua;
			this->panel129->Controls->Add(this->label131);
			this->panel129->Location = System::Drawing::Point(1581, 465);
			this->panel129->Name = L"panel129";
			this->panel129->Size = System::Drawing::Size(40, 38);
			this->panel129->TabIndex = 142;
			// 
			// label131
			// 
			this->label131->AutoSize = true;
			this->label131->BackColor = System::Drawing::Color::Cyan;
			this->label131->Location = System::Drawing::Point(3, 14);
			this->label131->Name = L"label131";
			this->label131->Size = System::Drawing::Size(31, 15);
			this->label131->TabIndex = 0;
			this->label131->Text = L"C44";
			// 
			// panel130
			// 
			this->panel130->BackColor = System::Drawing::Color::Aqua;
			this->panel130->Controls->Add(this->label132);
			this->panel130->Location = System::Drawing::Point(1621, 465);
			this->panel130->Name = L"panel130";
			this->panel130->Size = System::Drawing::Size(40, 38);
			this->panel130->TabIndex = 143;
			// 
			// label132
			// 
			this->label132->AutoSize = true;
			this->label132->BackColor = System::Drawing::Color::Cyan;
			this->label132->Location = System::Drawing::Point(3, 14);
			this->label132->Name = L"label132";
			this->label132->Size = System::Drawing::Size(31, 15);
			this->label132->TabIndex = 0;
			this->label132->Text = L"C45";
			// 
			// panel131
			// 
			this->panel131->BackColor = System::Drawing::Color::Aqua;
			this->panel131->Controls->Add(this->label133);
			this->panel131->Location = System::Drawing::Point(1306, 465);
			this->panel131->Name = L"panel131";
			this->panel131->Size = System::Drawing::Size(40, 38);
			this->panel131->TabIndex = 144;
			// 
			// label133
			// 
			this->label133->AutoSize = true;
			this->label133->BackColor = System::Drawing::Color::Cyan;
			this->label133->Location = System::Drawing::Point(3, 14);
			this->label133->Name = L"label133";
			this->label133->Size = System::Drawing::Size(31, 15);
			this->label133->TabIndex = 0;
			this->label133->Text = L"C46";
			// 
			// panel132
			// 
			this->panel132->BackColor = System::Drawing::Color::Aqua;
			this->panel132->Controls->Add(this->label134);
			this->panel132->Location = System::Drawing::Point(1352, 465);
			this->panel132->Name = L"panel132";
			this->panel132->Size = System::Drawing::Size(40, 38);
			this->panel132->TabIndex = 145;
			// 
			// label134
			// 
			this->label134->AutoSize = true;
			this->label134->BackColor = System::Drawing::Color::Cyan;
			this->label134->Location = System::Drawing::Point(3, 14);
			this->label134->Name = L"label134";
			this->label134->Size = System::Drawing::Size(31, 15);
			this->label134->TabIndex = 0;
			this->label134->Text = L"C47";
			// 
			// panel133
			// 
			this->panel133->BackColor = System::Drawing::Color::Aqua;
			this->panel133->Controls->Add(this->label135);
			this->panel133->Location = System::Drawing::Point(1392, 465);
			this->panel133->Name = L"panel133";
			this->panel133->Size = System::Drawing::Size(40, 38);
			this->panel133->TabIndex = 146;
			// 
			// label135
			// 
			this->label135->AutoSize = true;
			this->label135->BackColor = System::Drawing::Color::Cyan;
			this->label135->Location = System::Drawing::Point(3, 14);
			this->label135->Name = L"label135";
			this->label135->Size = System::Drawing::Size(31, 15);
			this->label135->TabIndex = 0;
			this->label135->Text = L"C48";
			// 
			// panel134
			// 
			this->panel134->BackColor = System::Drawing::Color::Aqua;
			this->panel134->Controls->Add(this->label136);
			this->panel134->Location = System::Drawing::Point(1430, 465);
			this->panel134->Name = L"panel134";
			this->panel134->Size = System::Drawing::Size(40, 38);
			this->panel134->TabIndex = 147;
			// 
			// label136
			// 
			this->label136->AutoSize = true;
			this->label136->BackColor = System::Drawing::Color::Cyan;
			this->label136->Location = System::Drawing::Point(3, 14);
			this->label136->Name = L"label136";
			this->label136->Size = System::Drawing::Size(31, 15);
			this->label136->TabIndex = 0;
			this->label136->Text = L"C49";
			// 
			// panel135
			// 
			this->panel135->BackColor = System::Drawing::Color::Aqua;
			this->panel135->Controls->Add(this->label137);
			this->panel135->Location = System::Drawing::Point(1190, 465);
			this->panel135->Name = L"panel135";
			this->panel135->Size = System::Drawing::Size(33, 38);
			this->panel135->TabIndex = 148;
			// 
			// label137
			// 
			this->label137->AutoSize = true;
			this->label137->BackColor = System::Drawing::Color::Cyan;
			this->label137->Location = System::Drawing::Point(3, 14);
			this->label137->Name = L"label137";
			this->label137->Size = System::Drawing::Size(31, 15);
			this->label137->TabIndex = 0;
			this->label137->Text = L"C50";
			// 
			// panel136
			// 
			this->panel136->BackColor = System::Drawing::Color::Aqua;
			this->panel136->Controls->Add(this->label138);
			this->panel136->Location = System::Drawing::Point(1229, 465);
			this->panel136->Name = L"panel136";
			this->panel136->Size = System::Drawing::Size(40, 38);
			this->panel136->TabIndex = 149;
			// 
			// label138
			// 
			this->label138->AutoSize = true;
			this->label138->BackColor = System::Drawing::Color::Cyan;
			this->label138->Location = System::Drawing::Point(3, 14);
			this->label138->Name = L"label138";
			this->label138->Size = System::Drawing::Size(31, 15);
			this->label138->TabIndex = 0;
			this->label138->Text = L"C51";
			// 
			// panel137
			// 
			this->panel137->BackColor = System::Drawing::Color::Aqua;
			this->panel137->Controls->Add(this->label139);
			this->panel137->Location = System::Drawing::Point(1269, 465);
			this->panel137->Name = L"panel137";
			this->panel137->Size = System::Drawing::Size(40, 38);
			this->panel137->TabIndex = 150;
			// 
			// label139
			// 
			this->label139->AutoSize = true;
			this->label139->BackColor = System::Drawing::Color::Cyan;
			this->label139->Location = System::Drawing::Point(3, 14);
			this->label139->Name = L"label139";
			this->label139->Size = System::Drawing::Size(31, 15);
			this->label139->TabIndex = 0;
			this->label139->Text = L"C52";
			// 
			// panel138
			// 
			this->panel138->BackColor = System::Drawing::Color::Aqua;
			this->panel138->Controls->Add(this->label140);
			this->panel138->Location = System::Drawing::Point(1162, 193);
			this->panel138->Name = L"panel138";
			this->panel138->Size = System::Drawing::Size(40, 38);
			this->panel138->TabIndex = 151;
			// 
			// label140
			// 
			this->label140->AutoSize = true;
			this->label140->BackColor = System::Drawing::Color::Cyan;
			this->label140->Location = System::Drawing::Point(3, 14);
			this->label140->Name = L"label140";
			this->label140->Size = System::Drawing::Size(31, 15);
			this->label140->TabIndex = 0;
			this->label140->Text = L"C53";
			// 
			// panel139
			// 
			this->panel139->BackColor = System::Drawing::Color::Aqua;
			this->panel139->Controls->Add(this->label141);
			this->panel139->Location = System::Drawing::Point(1208, 193);
			this->panel139->Name = L"panel139";
			this->panel139->Size = System::Drawing::Size(40, 38);
			this->panel139->TabIndex = 152;
			// 
			// label141
			// 
			this->label141->AutoSize = true;
			this->label141->BackColor = System::Drawing::Color::Cyan;
			this->label141->Location = System::Drawing::Point(3, 14);
			this->label141->Name = L"label141";
			this->label141->Size = System::Drawing::Size(31, 15);
			this->label141->TabIndex = 0;
			this->label141->Text = L"C54";
			// 
			// panel140
			// 
			this->panel140->BackColor = System::Drawing::Color::Aqua;
			this->panel140->Controls->Add(this->label142);
			this->panel140->Location = System::Drawing::Point(1253, 193);
			this->panel140->Name = L"panel140";
			this->panel140->Size = System::Drawing::Size(40, 38);
			this->panel140->TabIndex = 153;
			// 
			// label142
			// 
			this->label142->AutoSize = true;
			this->label142->BackColor = System::Drawing::Color::Cyan;
			this->label142->Location = System::Drawing::Point(3, 14);
			this->label142->Name = L"label142";
			this->label142->Size = System::Drawing::Size(31, 15);
			this->label142->TabIndex = 0;
			this->label142->Text = L"C55";
			// 
			// panel141
			// 
			this->panel141->BackColor = System::Drawing::Color::Aqua;
			this->panel141->Controls->Add(this->label143);
			this->panel141->Location = System::Drawing::Point(1299, 193);
			this->panel141->Name = L"panel141";
			this->panel141->Size = System::Drawing::Size(40, 38);
			this->panel141->TabIndex = 154;
			// 
			// label143
			// 
			this->label143->AutoSize = true;
			this->label143->BackColor = System::Drawing::Color::Cyan;
			this->label143->Location = System::Drawing::Point(3, 14);
			this->label143->Name = L"label143";
			this->label143->Size = System::Drawing::Size(31, 15);
			this->label143->TabIndex = 0;
			this->label143->Text = L"C56";
			// 
			// panel142
			// 
			this->panel142->BackColor = System::Drawing::Color::Aqua;
			this->panel142->Controls->Add(this->label144);
			this->panel142->Location = System::Drawing::Point(1346, 194);
			this->panel142->Name = L"panel142";
			this->panel142->Size = System::Drawing::Size(40, 38);
			this->panel142->TabIndex = 155;
			// 
			// label144
			// 
			this->label144->AutoSize = true;
			this->label144->BackColor = System::Drawing::Color::Cyan;
			this->label144->Location = System::Drawing::Point(3, 14);
			this->label144->Name = L"label144";
			this->label144->Size = System::Drawing::Size(31, 15);
			this->label144->TabIndex = 0;
			this->label144->Text = L"C57";
			// 
			// panel143
			// 
			this->panel143->BackColor = System::Drawing::Color::Aqua;
			this->panel143->Controls->Add(this->label145);
			this->panel143->Location = System::Drawing::Point(1389, 193);
			this->panel143->Name = L"panel143";
			this->panel143->Size = System::Drawing::Size(40, 38);
			this->panel143->TabIndex = 156;
			// 
			// label145
			// 
			this->label145->AutoSize = true;
			this->label145->BackColor = System::Drawing::Color::Cyan;
			this->label145->Location = System::Drawing::Point(3, 14);
			this->label145->Name = L"label145";
			this->label145->Size = System::Drawing::Size(31, 15);
			this->label145->TabIndex = 0;
			this->label145->Text = L"C58";
			// 
			// panel144
			// 
			this->panel144->BackColor = System::Drawing::Color::Cyan;
			this->panel144->Controls->Add(this->label146);
			this->panel144->Location = System::Drawing::Point(1433, 193);
			this->panel144->Name = L"panel144";
			this->panel144->Size = System::Drawing::Size(40, 38);
			this->panel144->TabIndex = 157;
			// 
			// label146
			// 
			this->label146->AutoSize = true;
			this->label146->BackColor = System::Drawing::Color::Cyan;
			this->label146->Location = System::Drawing::Point(3, 14);
			this->label146->Name = L"label146";
			this->label146->Size = System::Drawing::Size(31, 15);
			this->label146->TabIndex = 0;
			this->label146->Text = L"C59";
			// 
			// panel145
			// 
			this->panel145->BackColor = System::Drawing::Color::Aqua;
			this->panel145->Controls->Add(this->label147);
			this->panel145->Location = System::Drawing::Point(1482, 194);
			this->panel145->Name = L"panel145";
			this->panel145->Size = System::Drawing::Size(40, 38);
			this->panel145->TabIndex = 158;
			// 
			// label147
			// 
			this->label147->AutoSize = true;
			this->label147->BackColor = System::Drawing::Color::Cyan;
			this->label147->Location = System::Drawing::Point(3, 14);
			this->label147->Name = L"label147";
			this->label147->Size = System::Drawing::Size(31, 15);
			this->label147->TabIndex = 0;
			this->label147->Text = L"C60";
			// 
			// panel146
			// 
			this->panel146->BackColor = System::Drawing::Color::Aqua;
			this->panel146->Controls->Add(this->label148);
			this->panel146->Location = System::Drawing::Point(1528, 193);
			this->panel146->Name = L"panel146";
			this->panel146->Size = System::Drawing::Size(32, 38);
			this->panel146->TabIndex = 159;
			// 
			// label148
			// 
			this->label148->AutoSize = true;
			this->label148->BackColor = System::Drawing::Color::Aqua;
			this->label148->Location = System::Drawing::Point(3, 14);
			this->label148->Name = L"label148";
			this->label148->Size = System::Drawing::Size(31, 15);
			this->label148->TabIndex = 0;
			this->label148->Text = L"C61";
			// 
			// panel147
			// 
			this->panel147->BackColor = System::Drawing::Color::Aqua;
			this->panel147->Controls->Add(this->label149);
			this->panel147->Location = System::Drawing::Point(1528, 343);
			this->panel147->Name = L"panel147";
			this->panel147->Size = System::Drawing::Size(34, 38);
			this->panel147->TabIndex = 160;
			// 
			// label149
			// 
			this->label149->AutoSize = true;
			this->label149->BackColor = System::Drawing::Color::Cyan;
			this->label149->Location = System::Drawing::Point(3, 14);
			this->label149->Name = L"label149";
			this->label149->Size = System::Drawing::Size(31, 15);
			this->label149->TabIndex = 0;
			this->label149->Text = L"C62";
			// 
			// panel148
			// 
			this->panel148->BackColor = System::Drawing::Color::Aqua;
			this->panel148->Controls->Add(this->label150);
			this->panel148->Location = System::Drawing::Point(1344, 343);
			this->panel148->Name = L"panel148";
			this->panel148->Size = System::Drawing::Size(43, 38);
			this->panel148->TabIndex = 161;
			// 
			// label150
			// 
			this->label150->AutoSize = true;
			this->label150->BackColor = System::Drawing::Color::Aqua;
			this->label150->Location = System::Drawing::Point(3, 14);
			this->label150->Name = L"label150";
			this->label150->Size = System::Drawing::Size(31, 15);
			this->label150->TabIndex = 0;
			this->label150->Text = L"C63";
			// 
			// panel149
			// 
			this->panel149->BackColor = System::Drawing::Color::Aqua;
			this->panel149->Controls->Add(this->label151);
			this->panel149->Location = System::Drawing::Point(1390, 343);
			this->panel149->Name = L"panel149";
			this->panel149->Size = System::Drawing::Size(40, 38);
			this->panel149->TabIndex = 162;
			// 
			// label151
			// 
			this->label151->AutoSize = true;
			this->label151->BackColor = System::Drawing::Color::Cyan;
			this->label151->Location = System::Drawing::Point(3, 14);
			this->label151->Name = L"label151";
			this->label151->Size = System::Drawing::Size(31, 15);
			this->label151->TabIndex = 0;
			this->label151->Text = L"C64";
			// 
			// panel150
			// 
			this->panel150->BackColor = System::Drawing::Color::Aqua;
			this->panel150->Controls->Add(this->label152);
			this->panel150->Location = System::Drawing::Point(1436, 343);
			this->panel150->Name = L"panel150";
			this->panel150->Size = System::Drawing::Size(44, 38);
			this->panel150->TabIndex = 163;
			// 
			// label152
			// 
			this->label152->AutoSize = true;
			this->label152->BackColor = System::Drawing::Color::Aqua;
			this->label152->Location = System::Drawing::Point(3, 14);
			this->label152->Name = L"label152";
			this->label152->Size = System::Drawing::Size(31, 15);
			this->label152->TabIndex = 0;
			this->label152->Text = L"C65";
			// 
			// panel151
			// 
			this->panel151->BackColor = System::Drawing::Color::Aqua;
			this->panel151->Controls->Add(this->label153);
			this->panel151->Location = System::Drawing::Point(1486, 343);
			this->panel151->Name = L"panel151";
			this->panel151->Size = System::Drawing::Size(40, 38);
			this->panel151->TabIndex = 164;
			// 
			// label153
			// 
			this->label153->AutoSize = true;
			this->label153->BackColor = System::Drawing::Color::Cyan;
			this->label153->Location = System::Drawing::Point(3, 14);
			this->label153->Name = L"label153";
			this->label153->Size = System::Drawing::Size(31, 15);
			this->label153->TabIndex = 0;
			this->label153->Text = L"C66";
			// 
			// panel152
			// 
			this->panel152->BackColor = System::Drawing::Color::Aqua;
			this->panel152->Controls->Add(this->label154);
			this->panel152->Location = System::Drawing::Point(1162, 339);
			this->panel152->Name = L"panel152";
			this->panel152->Size = System::Drawing::Size(40, 38);
			this->panel152->TabIndex = 165;
			// 
			// label154
			// 
			this->label154->AutoSize = true;
			this->label154->BackColor = System::Drawing::Color::Aqua;
			this->label154->Location = System::Drawing::Point(3, 14);
			this->label154->Name = L"label154";
			this->label154->Size = System::Drawing::Size(31, 15);
			this->label154->TabIndex = 0;
			this->label154->Text = L"C67";
			// 
			// panel153
			// 
			this->panel153->BackColor = System::Drawing::Color::Aqua;
			this->panel153->Controls->Add(this->label155);
			this->panel153->Location = System::Drawing::Point(1208, 339);
			this->panel153->Name = L"panel153";
			this->panel153->Size = System::Drawing::Size(40, 38);
			this->panel153->TabIndex = 166;
			// 
			// label155
			// 
			this->label155->AutoSize = true;
			this->label155->BackColor = System::Drawing::Color::Aqua;
			this->label155->Location = System::Drawing::Point(3, 14);
			this->label155->Name = L"label155";
			this->label155->Size = System::Drawing::Size(31, 15);
			this->label155->TabIndex = 0;
			this->label155->Text = L"C68";
			// 
			// panel154
			// 
			this->panel154->BackColor = System::Drawing::Color::Aqua;
			this->panel154->Controls->Add(this->label156);
			this->panel154->Location = System::Drawing::Point(1253, 339);
			this->panel154->Name = L"panel154";
			this->panel154->Size = System::Drawing::Size(40, 38);
			this->panel154->TabIndex = 167;
			// 
			// label156
			// 
			this->label156->AutoSize = true;
			this->label156->BackColor = System::Drawing::Color::Aqua;
			this->label156->Location = System::Drawing::Point(3, 14);
			this->label156->Name = L"label156";
			this->label156->Size = System::Drawing::Size(31, 15);
			this->label156->TabIndex = 0;
			this->label156->Text = L"C69";
			// 
			// panel155
			// 
			this->panel155->BackColor = System::Drawing::Color::Aqua;
			this->panel155->Controls->Add(this->label157);
			this->panel155->Location = System::Drawing::Point(1298, 339);
			this->panel155->Name = L"panel155";
			this->panel155->Size = System::Drawing::Size(40, 38);
			this->panel155->TabIndex = 168;
			// 
			// label157
			// 
			this->label157->AutoSize = true;
			this->label157->BackColor = System::Drawing::Color::Aqua;
			this->label157->Location = System::Drawing::Point(3, 14);
			this->label157->Name = L"label157";
			this->label157->Size = System::Drawing::Size(31, 15);
			this->label157->TabIndex = 0;
			this->label157->Text = L"C70";
			// 
			// panel156
			// 
			this->panel156->BackColor = System::Drawing::Color::Cyan;
			this->panel156->Controls->Add(this->label158);
			this->panel156->Location = System::Drawing::Point(1534, 612);
			this->panel156->Name = L"panel156";
			this->panel156->Size = System::Drawing::Size(34, 38);
			this->panel156->TabIndex = 169;
			// 
			// label158
			// 
			this->label158->AutoSize = true;
			this->label158->BackColor = System::Drawing::Color::Cyan;
			this->label158->Location = System::Drawing::Point(3, 14);
			this->label158->Name = L"label158";
			this->label158->Size = System::Drawing::Size(31, 15);
			this->label158->TabIndex = 0;
			this->label158->Text = L"C71";
			// 
			// panel157
			// 
			this->panel157->BackColor = System::Drawing::Color::Aqua;
			this->panel157->Controls->Add(this->label159);
			this->panel157->Location = System::Drawing::Point(1572, 612);
			this->panel157->Name = L"panel157";
			this->panel157->Size = System::Drawing::Size(40, 38);
			this->panel157->TabIndex = 170;
			// 
			// label159
			// 
			this->label159->AutoSize = true;
			this->label159->BackColor = System::Drawing::Color::Cyan;
			this->label159->Location = System::Drawing::Point(3, 14);
			this->label159->Name = L"label159";
			this->label159->Size = System::Drawing::Size(31, 15);
			this->label159->TabIndex = 0;
			this->label159->Text = L"C72";
			// 
			// panel158
			// 
			this->panel158->BackColor = System::Drawing::Color::Aqua;
			this->panel158->Controls->Add(this->label160);
			this->panel158->Location = System::Drawing::Point(1612, 612);
			this->panel158->Name = L"panel158";
			this->panel158->Size = System::Drawing::Size(40, 38);
			this->panel158->TabIndex = 171;
			// 
			// label160
			// 
			this->label160->AutoSize = true;
			this->label160->BackColor = System::Drawing::Color::Cyan;
			this->label160->Location = System::Drawing::Point(3, 14);
			this->label160->Name = L"label160";
			this->label160->Size = System::Drawing::Size(31, 15);
			this->label160->TabIndex = 0;
			this->label160->Text = L"C73";
			// 
			// panel159
			// 
			this->panel159->BackColor = System::Drawing::Color::Aqua;
			this->panel159->Controls->Add(this->label161);
			this->panel159->Location = System::Drawing::Point(1652, 612);
			this->panel159->Name = L"panel159";
			this->panel159->Size = System::Drawing::Size(34, 38);
			this->panel159->TabIndex = 172;
			// 
			// label161
			// 
			this->label161->AutoSize = true;
			this->label161->BackColor = System::Drawing::Color::Cyan;
			this->label161->Location = System::Drawing::Point(3, 14);
			this->label161->Name = L"label161";
			this->label161->Size = System::Drawing::Size(31, 15);
			this->label161->TabIndex = 0;
			this->label161->Text = L"C74";
			// 
			// panel160
			// 
			this->panel160->BackColor = System::Drawing::Color::Aqua;
			this->panel160->Controls->Add(this->label162);
			this->panel160->Location = System::Drawing::Point(1530, 687);
			this->panel160->Name = L"panel160";
			this->panel160->Size = System::Drawing::Size(41, 27);
			this->panel160->TabIndex = 173;
			// 
			// label162
			// 
			this->label162->AutoSize = true;
			this->label162->BackColor = System::Drawing::Color::Aqua;
			this->label162->Location = System::Drawing::Point(3, 3);
			this->label162->Name = L"label162";
			this->label162->Size = System::Drawing::Size(31, 15);
			this->label162->TabIndex = 0;
			this->label162->Text = L"C75";
			// 
			// panel161
			// 
			this->panel161->BackColor = System::Drawing::Color::Aqua;
			this->panel161->Controls->Add(this->C76);
			this->panel161->Location = System::Drawing::Point(1572, 687);
			this->panel161->Name = L"panel161";
			this->panel161->Size = System::Drawing::Size(41, 28);
			this->panel161->TabIndex = 174;
			// 
			// C76
			// 
			this->C76->AutoSize = true;
			this->C76->BackColor = System::Drawing::Color::Cyan;
			this->C76->Location = System::Drawing::Point(1, 3);
			this->C76->Name = L"C76";
			this->C76->Size = System::Drawing::Size(31, 15);
			this->C76->TabIndex = 0;
			this->C76->Text = L"C76";
			// 
			// panel162
			// 
			this->panel162->BackColor = System::Drawing::Color::Aqua;
			this->panel162->Controls->Add(this->label163);
			this->panel162->Location = System::Drawing::Point(1612, 684);
			this->panel162->Name = L"panel162";
			this->panel162->Size = System::Drawing::Size(40, 31);
			this->panel162->TabIndex = 175;
			// 
			// label163
			// 
			this->label163->AutoSize = true;
			this->label163->BackColor = System::Drawing::Color::Cyan;
			this->label163->Location = System::Drawing::Point(3, 7);
			this->label163->Name = L"label163";
			this->label163->Size = System::Drawing::Size(31, 15);
			this->label163->TabIndex = 0;
			this->label163->Text = L"C77";
			// 
			// panel163
			// 
			this->panel163->BackColor = System::Drawing::Color::Aqua;
			this->panel163->Controls->Add(this->label164);
			this->panel163->Location = System::Drawing::Point(1650, 681);
			this->panel163->Name = L"panel163";
			this->panel163->Size = System::Drawing::Size(40, 31);
			this->panel163->TabIndex = 176;
			// 
			// label164
			// 
			this->label164->AutoSize = true;
			this->label164->BackColor = System::Drawing::Color::Aqua;
			this->label164->Location = System::Drawing::Point(9, 7);
			this->label164->Name = L"label164";
			this->label164->Size = System::Drawing::Size(31, 15);
			this->label164->TabIndex = 0;
			this->label164->Text = L"C78";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(574, -1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1263, 797);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// panel164
			// 
			this->panel164->BackColor = System::Drawing::Color::Aqua;
			this->panel164->Controls->Add(this->label165);
			this->panel164->Location = System::Drawing::Point(1696, 676);
			this->panel164->Name = L"panel164";
			this->panel164->Size = System::Drawing::Size(34, 38);
			this->panel164->TabIndex = 177;
			// 
			// label165
			// 
			this->label165->AutoSize = true;
			this->label165->BackColor = System::Drawing::Color::Cyan;
			this->label165->Location = System::Drawing::Point(3, 14);
			this->label165->Name = L"label165";
			this->label165->Size = System::Drawing::Size(31, 15);
			this->label165->TabIndex = 0;
			this->label165->Text = L"C79";
			// 
			// panel165
			// 
			this->panel165->BackColor = System::Drawing::Color::Aqua;
			this->panel165->Controls->Add(this->label166);
			this->panel165->Location = System::Drawing::Point(1740, 679);
			this->panel165->Name = L"panel165";
			this->panel165->Size = System::Drawing::Size(34, 38);
			this->panel165->TabIndex = 178;
			// 
			// label166
			// 
			this->label166->AutoSize = true;
			this->label166->BackColor = System::Drawing::Color::Cyan;
			this->label166->Location = System::Drawing::Point(3, 14);
			this->label166->Name = L"label166";
			this->label166->Size = System::Drawing::Size(31, 15);
			this->label166->TabIndex = 0;
			this->label166->Text = L"C80";
			// 
			// panel166
			// 
			this->panel166->BackColor = System::Drawing::Color::Aqua;
			this->panel166->Controls->Add(this->label167);
			this->panel166->Location = System::Drawing::Point(1790, 677);
			this->panel166->Name = L"panel166";
			this->panel166->Size = System::Drawing::Size(34, 38);
			this->panel166->TabIndex = 179;
			// 
			// label167
			// 
			this->label167->AutoSize = true;
			this->label167->BackColor = System::Drawing::Color::Cyan;
			this->label167->Location = System::Drawing::Point(3, 14);
			this->label167->Name = L"label167";
			this->label167->Size = System::Drawing::Size(31, 15);
			this->label167->TabIndex = 0;
			this->label167->Text = L"C81";
			// 
			// panel167
			// 
			this->panel167->BackColor = System::Drawing::Color::Aqua;
			this->panel167->Controls->Add(this->label168);
			this->panel167->Location = System::Drawing::Point(1699, 714);
			this->panel167->Name = L"panel167";
			this->panel167->Size = System::Drawing::Size(31, 29);
			this->panel167->TabIndex = 180;
			// 
			// label168
			// 
			this->label168->AutoSize = true;
			this->label168->BackColor = System::Drawing::Color::Cyan;
			this->label168->Location = System::Drawing::Point(3, 5);
			this->label168->Name = L"label168";
			this->label168->Size = System::Drawing::Size(31, 15);
			this->label168->TabIndex = 0;
			this->label168->Text = L"C82";
			// 
			// panel168
			// 
			this->panel168->BackColor = System::Drawing::Color::Aqua;
			this->panel168->Controls->Add(this->label169);
			this->panel168->Location = System::Drawing::Point(1740, 720);
			this->panel168->Name = L"panel168";
			this->panel168->Size = System::Drawing::Size(34, 23);
			this->panel168->TabIndex = 181;
			// 
			// label169
			// 
			this->label169->AutoSize = true;
			this->label169->BackColor = System::Drawing::Color::Cyan;
			this->label169->Location = System::Drawing::Point(0, 5);
			this->label169->Name = L"label169";
			this->label169->Size = System::Drawing::Size(31, 15);
			this->label169->TabIndex = 0;
			this->label169->Text = L"C83";
			// 
			// panel169
			// 
			this->panel169->BackColor = System::Drawing::Color::Aqua;
			this->panel169->Controls->Add(this->label170);
			this->panel169->Location = System::Drawing::Point(1791, 714);
			this->panel169->Name = L"panel169";
			this->panel169->Size = System::Drawing::Size(34, 29);
			this->panel169->TabIndex = 182;
			// 
			// label170
			// 
			this->label170->AutoSize = true;
			this->label170->BackColor = System::Drawing::Color::Cyan;
			this->label170->Location = System::Drawing::Point(3, 5);
			this->label170->Name = L"label170";
			this->label170->Size = System::Drawing::Size(31, 15);
			this->label170->TabIndex = 0;
			this->label170->Text = L"C84";
			// 
			// showCarRoteForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1854, 782);
			this->Controls->Add(this->panel169);
			this->Controls->Add(this->panel168);
			this->Controls->Add(this->panel167);
			this->Controls->Add(this->panel166);
			this->Controls->Add(this->panel165);
			this->Controls->Add(this->panel164);
			this->Controls->Add(this->panel163);
			this->Controls->Add(this->panel162);
			this->Controls->Add(this->panel161);
			this->Controls->Add(this->panel160);
			this->Controls->Add(this->panel159);
			this->Controls->Add(this->panel158);
			this->Controls->Add(this->panel157);
			this->Controls->Add(this->panel156);
			this->Controls->Add(this->panel155);
			this->Controls->Add(this->panel154);
			this->Controls->Add(this->panel153);
			this->Controls->Add(this->panel152);
			this->Controls->Add(this->panel151);
			this->Controls->Add(this->panel150);
			this->Controls->Add(this->panel149);
			this->Controls->Add(this->panel148);
			this->Controls->Add(this->panel147);
			this->Controls->Add(this->panel146);
			this->Controls->Add(this->panel145);
			this->Controls->Add(this->panel144);
			this->Controls->Add(this->panel143);
			this->Controls->Add(this->panel142);
			this->Controls->Add(this->panel141);
			this->Controls->Add(this->panel140);
			this->Controls->Add(this->panel139);
			this->Controls->Add(this->panel138);
			this->Controls->Add(this->panel137);
			this->Controls->Add(this->panel136);
			this->Controls->Add(this->panel135);
			this->Controls->Add(this->panel134);
			this->Controls->Add(this->panel133);
			this->Controls->Add(this->panel132);
			this->Controls->Add(this->panel131);
			this->Controls->Add(this->panel130);
			this->Controls->Add(this->panel129);
			this->Controls->Add(this->panel128);
			this->Controls->Add(this->panel127);
			this->Controls->Add(this->panel126);
			this->Controls->Add(this->panel125);
			this->Controls->Add(this->panel124);
			this->Controls->Add(this->panel123);
			this->Controls->Add(this->panel122);
			this->Controls->Add(this->panel121);
			this->Controls->Add(this->panel120);
			this->Controls->Add(this->panel119);
			this->Controls->Add(this->panel118);
			this->Controls->Add(this->panel117);
			this->Controls->Add(this->panel116);
			this->Controls->Add(this->panel115);
			this->Controls->Add(this->panel114);
			this->Controls->Add(this->panel113);
			this->Controls->Add(this->panel112);
			this->Controls->Add(this->panel111);
			this->Controls->Add(this->panel110);
			this->Controls->Add(this->panel109);
			this->Controls->Add(this->panel108);
			this->Controls->Add(this->panel107);
			this->Controls->Add(this->panel106);
			this->Controls->Add(this->panel105);
			this->Controls->Add(this->panel104);
			this->Controls->Add(this->panel103);
			this->Controls->Add(this->panel102);
			this->Controls->Add(this->panel101);
			this->Controls->Add(this->panel100);
			this->Controls->Add(this->panel99);
			this->Controls->Add(this->panel98);
			this->Controls->Add(this->panel97);
			this->Controls->Add(this->panel96);
			this->Controls->Add(this->panel95);
			this->Controls->Add(this->panel94);
			this->Controls->Add(this->panel93);
			this->Controls->Add(this->panel92);
			this->Controls->Add(this->panel91);
			this->Controls->Add(this->panel90);
			this->Controls->Add(this->panel89);
			this->Controls->Add(this->panel88);
			this->Controls->Add(this->panel87);
			this->Controls->Add(this->panel86);
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
			this->Controls->Add(this->panel22);
			this->Controls->Add(this->panel23);
			this->Controls->Add(this->panel24);
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
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"showCarRoteForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"小车位置坐标";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &showCarRoteForm::showCarRoteForm_Load);
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
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
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
			this->panel24->ResumeLayout(false);
			this->panel24->PerformLayout();
			this->panel23->ResumeLayout(false);
			this->panel23->PerformLayout();
			this->panel22->ResumeLayout(false);
			this->panel22->PerformLayout();
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
			this->panel86->ResumeLayout(false);
			this->panel86->PerformLayout();
			this->panel87->ResumeLayout(false);
			this->panel87->PerformLayout();
			this->panel88->ResumeLayout(false);
			this->panel88->PerformLayout();
			this->panel89->ResumeLayout(false);
			this->panel89->PerformLayout();
			this->panel90->ResumeLayout(false);
			this->panel90->PerformLayout();
			this->panel91->ResumeLayout(false);
			this->panel91->PerformLayout();
			this->panel92->ResumeLayout(false);
			this->panel92->PerformLayout();
			this->panel93->ResumeLayout(false);
			this->panel93->PerformLayout();
			this->panel94->ResumeLayout(false);
			this->panel94->PerformLayout();
			this->panel95->ResumeLayout(false);
			this->panel95->PerformLayout();
			this->panel96->ResumeLayout(false);
			this->panel96->PerformLayout();
			this->panel97->ResumeLayout(false);
			this->panel97->PerformLayout();
			this->panel98->ResumeLayout(false);
			this->panel98->PerformLayout();
			this->panel99->ResumeLayout(false);
			this->panel99->PerformLayout();
			this->panel100->ResumeLayout(false);
			this->panel100->PerformLayout();
			this->panel101->ResumeLayout(false);
			this->panel101->PerformLayout();
			this->panel102->ResumeLayout(false);
			this->panel102->PerformLayout();
			this->panel103->ResumeLayout(false);
			this->panel103->PerformLayout();
			this->panel104->ResumeLayout(false);
			this->panel104->PerformLayout();
			this->panel105->ResumeLayout(false);
			this->panel105->PerformLayout();
			this->panel106->ResumeLayout(false);
			this->panel106->PerformLayout();
			this->panel107->ResumeLayout(false);
			this->panel107->PerformLayout();
			this->panel108->ResumeLayout(false);
			this->panel108->PerformLayout();
			this->panel109->ResumeLayout(false);
			this->panel109->PerformLayout();
			this->panel110->ResumeLayout(false);
			this->panel110->PerformLayout();
			this->panel111->ResumeLayout(false);
			this->panel111->PerformLayout();
			this->panel112->ResumeLayout(false);
			this->panel112->PerformLayout();
			this->panel113->ResumeLayout(false);
			this->panel113->PerformLayout();
			this->panel114->ResumeLayout(false);
			this->panel114->PerformLayout();
			this->panel115->ResumeLayout(false);
			this->panel115->PerformLayout();
			this->panel116->ResumeLayout(false);
			this->panel116->PerformLayout();
			this->panel117->ResumeLayout(false);
			this->panel117->PerformLayout();
			this->panel118->ResumeLayout(false);
			this->panel118->PerformLayout();
			this->panel119->ResumeLayout(false);
			this->panel119->PerformLayout();
			this->panel120->ResumeLayout(false);
			this->panel120->PerformLayout();
			this->panel121->ResumeLayout(false);
			this->panel121->PerformLayout();
			this->panel122->ResumeLayout(false);
			this->panel122->PerformLayout();
			this->panel123->ResumeLayout(false);
			this->panel123->PerformLayout();
			this->panel124->ResumeLayout(false);
			this->panel124->PerformLayout();
			this->panel125->ResumeLayout(false);
			this->panel125->PerformLayout();
			this->panel126->ResumeLayout(false);
			this->panel126->PerformLayout();
			this->panel127->ResumeLayout(false);
			this->panel127->PerformLayout();
			this->panel128->ResumeLayout(false);
			this->panel128->PerformLayout();
			this->panel129->ResumeLayout(false);
			this->panel129->PerformLayout();
			this->panel130->ResumeLayout(false);
			this->panel130->PerformLayout();
			this->panel131->ResumeLayout(false);
			this->panel131->PerformLayout();
			this->panel132->ResumeLayout(false);
			this->panel132->PerformLayout();
			this->panel133->ResumeLayout(false);
			this->panel133->PerformLayout();
			this->panel134->ResumeLayout(false);
			this->panel134->PerformLayout();
			this->panel135->ResumeLayout(false);
			this->panel135->PerformLayout();
			this->panel136->ResumeLayout(false);
			this->panel136->PerformLayout();
			this->panel137->ResumeLayout(false);
			this->panel137->PerformLayout();
			this->panel138->ResumeLayout(false);
			this->panel138->PerformLayout();
			this->panel139->ResumeLayout(false);
			this->panel139->PerformLayout();
			this->panel140->ResumeLayout(false);
			this->panel140->PerformLayout();
			this->panel141->ResumeLayout(false);
			this->panel141->PerformLayout();
			this->panel142->ResumeLayout(false);
			this->panel142->PerformLayout();
			this->panel143->ResumeLayout(false);
			this->panel143->PerformLayout();
			this->panel144->ResumeLayout(false);
			this->panel144->PerformLayout();
			this->panel145->ResumeLayout(false);
			this->panel145->PerformLayout();
			this->panel146->ResumeLayout(false);
			this->panel146->PerformLayout();
			this->panel147->ResumeLayout(false);
			this->panel147->PerformLayout();
			this->panel148->ResumeLayout(false);
			this->panel148->PerformLayout();
			this->panel149->ResumeLayout(false);
			this->panel149->PerformLayout();
			this->panel150->ResumeLayout(false);
			this->panel150->PerformLayout();
			this->panel151->ResumeLayout(false);
			this->panel151->PerformLayout();
			this->panel152->ResumeLayout(false);
			this->panel152->PerformLayout();
			this->panel153->ResumeLayout(false);
			this->panel153->PerformLayout();
			this->panel154->ResumeLayout(false);
			this->panel154->PerformLayout();
			this->panel155->ResumeLayout(false);
			this->panel155->PerformLayout();
			this->panel156->ResumeLayout(false);
			this->panel156->PerformLayout();
			this->panel157->ResumeLayout(false);
			this->panel157->PerformLayout();
			this->panel158->ResumeLayout(false);
			this->panel158->PerformLayout();
			this->panel159->ResumeLayout(false);
			this->panel159->PerformLayout();
			this->panel160->ResumeLayout(false);
			this->panel160->PerformLayout();
			this->panel161->ResumeLayout(false);
			this->panel161->PerformLayout();
			this->panel162->ResumeLayout(false);
			this->panel162->PerformLayout();
			this->panel163->ResumeLayout(false);
			this->panel163->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel164->ResumeLayout(false);
			this->panel164->PerformLayout();
			this->panel165->ResumeLayout(false);
			this->panel165->PerformLayout();
			this->panel166->ResumeLayout(false);
			this->panel166->PerformLayout();
			this->panel167->ResumeLayout(false);
			this->panel167->PerformLayout();
			this->panel168->ResumeLayout(false);
			this->panel168->PerformLayout();
			this->panel169->ResumeLayout(false);
			this->panel169->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 int carindex = System::Convert::ToInt32(textBox1->Text);
				 if (carindex <= 3){
					 carindex -= 1;
				 }
				 else{
					 carindex -= 4;
				 }
				 int z; int v;
				 int tmp = 0;
				 FILE* fp1;
				 fp1 = fopen("查询车位坐标.txt", "r");
				 while (1){
					 fscanf(fp1, "%d", &z);
					 fscanf(fp1, "%d", &v);
					 if (z < 0)
						 break;
					 if (arr[z][v] == 1){
						 tmp++;
					 }
					 else{
						 if (tmp == 0){
							 this->panel85->BackColor = System::Drawing::SystemColors::Desktop;
						 }if (tmp == 1){
							 this->panel86->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 2){
							 this->panel87->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 3){
							 this->panel88->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 4){
							 this->panel89->BackColor = System::Drawing::SystemColors::Desktop;
						 }if (tmp == 5){
							 this->panel90->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 6){
							 this->panel91->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 7){
							 this->panel92->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 8){
							 this->panel93->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 9){
							 this->panel94->BackColor = System::Drawing::SystemColors::Desktop;
						 }  if (tmp == 10){
							 this->panel95->BackColor = System::Drawing::SystemColors::Desktop;
						 }if (tmp == 11){
							 this->panel96->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 12){
							 this->panel97->BackColor = System::Drawing::SystemColors::Desktop;
						 }  if (tmp == 13){
							 this->panel98->BackColor = System::Drawing::SystemColors::Desktop;
						 }if (tmp == 14){
							 this->panel99->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 15){
							 this->panel100->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 16){
							 this->panel101->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 17){
							 this->panel102->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 18){
							 this->panel103->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 19){
							 this->panel104->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 20){
							 this->panel105->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 21){
							 this->panel106->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 22){
							 this->panel107->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 23){
							 this->panel108->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 24){
							 this->panel109->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 25){
							 this->panel110->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 26){
							 this->panel111->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 27){
							 this->panel112->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 28){
							 this->panel113->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 29){
							 this->panel114->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 30){
							 this->panel115->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 31){
							 this->panel116->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 32){
							 this->panel117->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 33){
							 this->panel118->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 34){
							 this->panel119->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 35){
							 this->panel120->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 36){
							 this->panel121->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 37){
							 this->panel122->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 38){
							 this->panel123->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 39){
							 this->panel124->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 40){
							 this->panel125->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 41){
							 this->panel126->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 42){
							 this->panel127->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 43){
							 this->panel128->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 44){
							 this->panel129->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 45){
							 this->panel130->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 46){
							 this->panel131->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 47){
							 this->panel132->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 48){
							 this->panel133->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 49){
							 this->panel134->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 50){
							 this->panel135->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 51){
							 this->panel136->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 52){
							 this->panel137->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 53){
							 this->panel138->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 54){
							 this->panel139->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 55){
							 this->panel140->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 56){
							 this->panel141->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 57){
							 this->panel142->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 58){
							 this->panel143->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 59){
							 this->panel144->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 60){
							 this->panel145->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 61){
							 this->panel146->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 62){
							 this->panel147->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 63){
							 this->panel148->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 64){
							 this->panel149->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 65){
							 this->panel150->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 66){
							 this->panel151->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 67){
							 this->panel152->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 68){
							 this->panel153->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 69){
							 this->panel154->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 70){
							 this->panel155->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 71){
							 this->panel156->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 72){
							 this->panel157->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 73){
							 this->panel158->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 74){
							 this->panel159->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 75){
							 this->panel160->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 76){
							 this->panel161->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 77){
							 this->panel162->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 78){
							 this->panel163->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 79){
							 this->panel164->BackColor = System::Drawing::SystemColors::Desktop;
						 }
						 if (tmp == 80){
							 this->panel165->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 81){
							 this->panel166->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 82){
							 this->panel167->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 83){
							 this->panel168->BackColor = System::Drawing::SystemColors::Desktop;
						 } if (tmp == 84){
							 this->panel169->BackColor = System::Drawing::SystemColors::Desktop;
						 }
						 tmp++;
					 }
				 }
				 fclose(fp1);




				int car =  System::Convert::ToInt32(textBox1->Text);
				int x = 0; int y = 0;
				//A区小车
				for (int i = 0; i < carVectA.size(); i++)
				{
					if (carVectA[i].index == car)
					{
						//充电区内
						for (int j = 0; j < aEle.size(); j++)
						{
							if (arr[aEle[j].x][aEle[j].y] == 3)
							{
								if (j == 0){
									this->panel69->BackColor = System::Drawing::Color::Pink;
								}if (j == 1){
									this->panel70->BackColor = System::Drawing::Color::Pink;
								}if (j == 2){
									this->panel71->BackColor = System::Drawing::Color::Pink;
								}if (j == 3){
									this->panel72->BackColor = System::Drawing::Color::Pink;
								}
							}
						}
						for (int j = 0; j < aEle.size(); j++)
						{
							if (strcmp(carVectA[i].position.c_str(), aEle[j].index0.c_str()) == 0)
							{
								if (j == 0){
									this->panel69->BackColor = System::Drawing::SystemColors::Desktop;
								}if (j == 1){
									this->panel70->BackColor = System::Drawing::SystemColors::Desktop;
								}if (j == 2){
									this->panel71->BackColor = System::Drawing::SystemColors::Desktop;
								}if (j == 3){
									this->panel72->BackColor = System::Drawing::SystemColors::Desktop;
								}
								textBox2->Text = "";
								//x = aEle[j].x; y = aEle[j].y;
								textBox2->Text += "E";
								textBox2->Text += "0";
								textBox2->Text += j;
							}
						}
						//便道内
						for (int index = 0; index < aLine.size(); index++)
						{
							if (arr[aLine[index].x][aLine[index].y] == 2)
							{
								if (index == 0){
									this->panel1->BackColor = System::Drawing::Color::Yellow;
								}if (index == 1){
									this->panel2->BackColor = System::Drawing::Color::Yellow;
								} if (index == 2){
									this->panel3->BackColor = System::Drawing::Color::Yellow;
								} if (index == 3){
									this->panel4->BackColor = System::Drawing::Color::Yellow;
								} if (index == 4){
									this->panel5->BackColor = System::Drawing::Color::Yellow;
								}if (index == 5){
									this->panel6->BackColor = System::Drawing::Color::Yellow;
								} if (index == 6){
									this->panel7->BackColor = System::Drawing::Color::Yellow;
								} if (index == 7){
									this->panel8->BackColor = System::Drawing::Color::Yellow;
								} if (index == 8){
									this->panel9->BackColor = System::Drawing::Color::Yellow;
								} if (index == 9){
									this->panel10->BackColor = System::Drawing::Color::Yellow;
								}  if (index == 10){
									this->panel11->BackColor = System::Drawing::Color::Yellow;
								}if (index == 11){
									this->panel12->BackColor = System::Drawing::Color::Yellow;
								} if (index == 12){
									this->panel13->BackColor = System::Drawing::Color::Yellow;
								}  if (index == 13){
									this->panel14->BackColor = System::Drawing::Color::Yellow;
								}if (index == 14){
									this->panel15->BackColor = System::Drawing::Color::Yellow;
								} if (index == 15){
									this->panel16->BackColor = System::Drawing::Color::Yellow;
								} if (index == 16){
									this->panel17->BackColor = System::Drawing::Color::Yellow;
								} if (index == 17){
									this->panel18->BackColor = System::Drawing::Color::Yellow;
								} if (index == 18){
									this->panel19->BackColor = System::Drawing::Color::Yellow;
								} if (index == 19){
									this->panel20->BackColor = System::Drawing::Color::Yellow;
								} if (index == 20){
									this->panel21->BackColor = System::Drawing::Color::Yellow;
								} if (index == 21){
									this->panel22->BackColor = System::Drawing::Color::Yellow;
								} if (index == 22){
									this->panel23->BackColor = System::Drawing::Color::Yellow;
								} if (index == 23){
									this->panel24->BackColor = System::Drawing::Color::Yellow;
								} if (index == 24){
									this->panel25->BackColor = System::Drawing::Color::Yellow;
								} if (index == 25){
									this->panel26->BackColor = System::Drawing::Color::Yellow;
								} if (index == 26){
									this->panel27->BackColor = System::Drawing::Color::Yellow;
								} if (index == 27){
									this->panel28->BackColor = System::Drawing::Color::Yellow;
								} if (index == 28){
									this->panel29->BackColor = System::Drawing::Color::Yellow;
								} if (index == 29){
									this->panel30->BackColor = System::Drawing::Color::Yellow;
								} if (index == 30){
									this->panel31->BackColor = System::Drawing::Color::Yellow;
								} if (index == 31){
									this->panel32->BackColor = System::Drawing::Color::Yellow;
								} if (index == 32){
									this->panel33->BackColor = System::Drawing::Color::Yellow;
								} if (index == 33){
									this->panel34->BackColor = System::Drawing::Color::Yellow;
								} if (index == 34){
									this->panel35->BackColor = System::Drawing::Color::Yellow;
								} if (index == 35){
									this->panel36->BackColor = System::Drawing::Color::Yellow;
								} if (index == 36){
									this->panel37->BackColor = System::Drawing::Color::Yellow;
								} if (index == 37){
									this->panel38->BackColor = System::Drawing::Color::Yellow;
								} if (index == 38){
									this->panel39->BackColor = System::Drawing::Color::Yellow;
								} if (index == 39){
									this->panel40->BackColor = System::Drawing::Color::Yellow;
								} if (index == 40){
									this->panel41->BackColor = System::Drawing::Color::Yellow;
								} if (index == 41){
									this->panel42->BackColor = System::Drawing::Color::Yellow;
								}
							}
						}
						for (int index = 0; index < aLine.size(); index++)
						{
							if (strcmp(carVectA[i].position.c_str(), aLine[index].index0.c_str()) == 0)
							{
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
								} 
								//x = aLine[j].x; y = aLine[j].y;
								textBox2->Text = "";
								textBox2->Text += "R";
								if (index <= 9){
									textBox2->Text += "0";
								}
								textBox2->Text += index;
							}
						}
						//停靠区
						
						//for (int j = 0; j < aPark1.size(); j++)
						//{
						//	if (arr[aPark1[j].x][aPark1[j].y] == 4)
						//	{
								
						//		if (j == 0){
									this->panel79->BackColor = System::Drawing::Color::LimeGreen;
						//		}if (j == 1){
									this->panel80->BackColor = System::Drawing::Color::LimeGreen;
						//		}if (j == 2){
									this->panel81->BackColor = System::Drawing::Color::LimeGreen;
						//		}if (j == 3){
									this->panel82->BackColor = System::Drawing::Color::LimeGreen;
						//		}if (j == 4){
									this->panel83->BackColor = System::Drawing::Color::LimeGreen;
						//		}if (j == 5){
									this->panel84->BackColor = System::Drawing::Color::LimeGreen;
						//		}
						//	}
					//	}
					//	for (int j = 0; j < aPark2.size(); j++)
					//	{
					//		if (arr[aPark2[j].x][aPark2[j].y] == 4)
					//		{
					//			if (j == 0)
					//			{
									this->panel73->BackColor = System::Drawing::Color::LimeGreen;
					//			}if (j == 1)
					///			{
									this->panel74->BackColor = System::Drawing::Color::LimeGreen;
					//			}if (j == 2)
					//			{
									this->panel75->BackColor = System::Drawing::Color::LimeGreen;
					//			}if (j == 3)
					//			{
									this->panel76->BackColor = System::Drawing::Color::LimeGreen;
					//			}if (j == 4)
					//			{
									this->panel77->BackColor = System::Drawing::Color::LimeGreen;
					//			}if (j == 5)
					//			{
									this->panel78->BackColor = System::Drawing::Color::LimeGreen;
					//			}
					//		}
				//		}
						for (int j = 0; j < aPark1.size(); j++)
						{
							if (strcmp(carVectA[i].position.c_str(), aPark1[j].index0.c_str()) == 0)
							{
								if (carindex == 0)
								{
									this->panel79->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 1)
								{
									this->panel80->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 2)
								{
									this->panel81->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 3)
								{
									this->panel82->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 4)
								{
									this->panel83->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 5)
								{
									this->panel84->BackColor = System::Drawing::SystemColors::Desktop;
								}
								
								//x = aPark1[j].x; y = aPark1[j].y;
								textBox2->Text = "";
								int ret = (j + 6);
								textBox2->Text += "T";
								if (ret <= 9){
									textBox2->Text += "0";
								}
								textBox2->Text += ret;
							}
						}
						for (int j = 0; j < aPark2.size(); j++)
						{

							if (strcmp(carVectA[i].position.c_str(), aPark2[j].index0.c_str()) == 0)
							{
								if (carindex == 0)
								{
									this->panel73->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 1)
								{
									this->panel74->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 2)
								{
									this->panel75->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 3)
								{
									this->panel76->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 4)
								{
									this->panel77->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 5)
								{
									this->panel78->BackColor = System::Drawing::SystemColors::Desktop;
								}
							//x = aPark2[j].x; y = aPark2[j].y;
								textBox2->Text = "";
								textBox2->Text += "T";
								textBox2->Text += "0";
								textBox2->Text += j;
							}
						}
						//车位
						for (int j = 0; j < aSpace.size(); j++)
						{
							if (strcmp(carVectA[i].position.c_str(), aSpace[j].index0.c_str()) == 0)
							{
								//x = aSpace[j].x; y = aSpace[j].y;
								textBox2->Text = "";
								textBox2->Text += "C";
								if (j <= 9){
									textBox2->Text += "0";
								}
								textBox2->Text += j;
							}
						}
					}
				}
				//B区小车
				for (int i = 0; i < carVectB.size(); i++)
				{
					if (carVectB[i].index == car)
					{
						//充电区内
						for (int j = 0; j < bEle.size(); j++)
						{
							if (arr[bEle[j].x][bEle[j].y] == 3)
							{
								if (j == 0){
									this->panel59->BackColor = System::Drawing::Color::Pink;
								}if (j == 0){
									this->panel60->BackColor = System::Drawing::Color::Pink;
								}if (j == 0){
									this->panel61->BackColor = System::Drawing::Color::Pink;
								}if (j == 0){
									this->panel62->BackColor = System::Drawing::Color::Pink;
								}
							}
						}
						for (int j = 0; j < bEle.size(); j++)
						{
							if (strcmp(carVectB[i].position.c_str(), bEle[j].index0.c_str()) == 0)
							{
								if (j == 0){
									this->panel59->BackColor = System::Drawing::SystemColors::Desktop;
								}if (j == 0){
									this->panel60->BackColor = System::Drawing::SystemColors::Desktop;
								}if (j == 0){
									this->panel61->BackColor = System::Drawing::SystemColors::Desktop;
								}if (j == 0){
									this->panel62->BackColor = System::Drawing::SystemColors::Desktop;
								}
								//x = bEle[j].x; y = bEle[j].y;
								textBox2->Text = "";
								textBox2->Text += "E";
								textBox2->Text += "0";
								int ret = (j + 4);
								textBox2->Text += ret;
							}
						}
						//便道内
						for (int index = 0; index < bLine.size(); index++)
						{
							if (arr[bLine[index].x][bLine[index].y] == 2)
							{
								if (index == 0){
									this->panel43->BackColor = System::Drawing::Color::Yellow;
								} if (index == 1){
									this->panel44->BackColor = System::Drawing::Color::Yellow;
								} if (index == 2){
									this->panel45->BackColor = System::Drawing::Color::Yellow;
								} if (index == 3){
									this->panel46->BackColor = System::Drawing::Color::Yellow;
								} if (index == 4){
									this->panel47->BackColor = System::Drawing::Color::Yellow;
								} if (index == 5){
									this->panel48->BackColor = System::Drawing::Color::Yellow;
								} if (index == 6){
									this->panel49->BackColor = System::Drawing::Color::Yellow;
								} if (index == 7){
									this->panel50->BackColor = System::Drawing::Color::Yellow;
								} if (index == 8){
									this->panel51->BackColor = System::Drawing::Color::Yellow;
								} if (index == 9){
									this->panel52->BackColor = System::Drawing::Color::Yellow;
								} if (index == 10){
									this->panel53->BackColor = System::Drawing::Color::Yellow;
								} if (index == 11){
									this->panel54->BackColor = System::Drawing::Color::Yellow;
								} if (index == 12){
									this->panel55->BackColor = System::Drawing::Color::Yellow;
								} if (index == 13){
									this->panel56->BackColor = System::Drawing::Color::Yellow;
								} if (index == 14){
									this->panel57->BackColor = System::Drawing::Color::Yellow;
								} if (index == 15){
									this->panel58->BackColor = System::Drawing::Color::Yellow;
								}
							}
						}
						for (int index = 0; index < bLine.size(); index++)
						{
							if (strcmp(carVectB[i].position.c_str(), bLine[index].index0.c_str()) == 0)
							{
								if (index == 0){
									this->panel43->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 1){
									this->panel44->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 2){
									this->panel45->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 3){
									this->panel46->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 4){
									this->panel47->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 5){
									this->panel48->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 6){
									this->panel49->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 7){
									this->panel50->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 8){
									this->panel51->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 9){
									this->panel52->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 10){
									this->panel53->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 11){
									this->panel54->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 12){
									this->panel55->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 13){
									this->panel56->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 14){
									this->panel57->BackColor = System::Drawing::SystemColors::Desktop;
								} if (index == 15){
									this->panel58->BackColor = System::Drawing::SystemColors::Desktop;
								}
								//x = bLine[j].x; y = bLine[j].y;
								textBox2->Text = "";
								textBox2->Text += "R";
								int ret = (index + 42);
								textBox2->Text += ret;
							}
						}
						//停靠区

						//for (int j = 0; j < bPark.size(); j++)
						//{
						//	if (arr[bPark[j].x][bPark[j].y] == 4)
						//	{
						//		if (j == 0){
								this->panel63->BackColor = System::Drawing::Color::LimeGreen;
						//		}if (j == 1){
								this->panel64->BackColor = System::Drawing::Color::LimeGreen;
						//	   }if (j == 2){
								this->panel65->BackColor = System::Drawing::Color::LimeGreen;
						//	   }if (j == 3){
								this->panel66->BackColor = System::Drawing::Color::LimeGreen;
						//	  }if (j == 4){
								this->panel67->BackColor = System::Drawing::Color::LimeGreen;
						//	   }if (j == 5){
								this->panel68->BackColor = System::Drawing::Color::LimeGreen;
						//	   }
						//	}
						//}

						for (int j = 0; j < bPark.size(); j++)
						{
							if (strcmp(carVectB[i].position.c_str(), bPark[j].index0.c_str()) == 0)
							{
								if (carindex == 0){
									this->panel63->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 1){
									this->panel64->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 2){
									this->panel65->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 3){
									this->panel66->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 4){
									this->panel67->BackColor = System::Drawing::SystemColors::Desktop;
								}if (carindex == 5){
									this->panel68->BackColor = System::Drawing::SystemColors::Desktop;
								}
								//x = bPark[j].x; y = bPark[j].y;
								textBox2->Text = "";
								textBox2->Text += "T";
								int ret = (j + 12);
								textBox2->Text += ret;
							}
						}
						//车位
						for (int j = 0; j < bSpace.size(); j++)
						{
							if (strcmp(carVectB[i].position.c_str(), bSpace[j].index0.c_str()) == 0)
							{
								//x = bSpace[j].x; y = bSpace[j].y;
								textBox2->Text = "";
								textBox2->Text += "C";
								int ret = (j + 71);
								textBox2->Text += ret;
							}
						}
					}
				}
			/*	MessageBox::Show(x.ToString(),"查询小车的位置横坐标为");
				MessageBox::Show(y.ToString(),"查询小车的位置纵坐标为");*/
			
				//MessageBox::Show("查询小车的位置横坐标为" + x +"查询小车位置的纵坐标为" + y);
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void showCarRoteForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
