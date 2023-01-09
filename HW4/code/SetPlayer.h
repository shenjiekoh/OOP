#pragma once
#include "TickTacToe.h"

namespace HW04 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SetPlayer
	/// </summary>
	public ref class SetPlayer : public System::Windows::Forms::Form
	{
	public:
		SetPlayer(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SetPlayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox_Player1;
	private: System::Windows::Forms::TextBox^ textBox_Player2;
	private: System::Windows::Forms::Button^ buttonOK;
	private: System::Windows::Forms::Button^ buttonReset;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RadioButton^ player1ButtonX;
	private: System::Windows::Forms::RadioButton^ player1ButtonO;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::RadioButton^ player2ButtonX;
	private: System::Windows::Forms::RadioButton^ player2ButtonO;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		String^ player1Name = String::Empty;	// 玩家1名字
		String^ player2Name = String::Empty;	// 玩家2名字
		bool player1IsO = true;	// 玩家1是不是O (true:O false:X)
		bool player2IsO = true;	// 玩家2是不是O (true:O false:X)

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox_Player1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Player2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonReset = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->player1ButtonX = (gcnew System::Windows::Forms::RadioButton());
			this->player1ButtonO = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->player2ButtonX = (gcnew System::Windows::Forms::RadioButton());
			this->player2ButtonO = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->Location = System::Drawing::Point(128, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(333, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Welcome to Tick-Tac-Toe!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(45, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"輸入名字:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(50, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(54, 22);
			this->label3->TabIndex = 2;
			this->label3->Text = L"玩家1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(50, 189);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(54, 22);
			this->label4->TabIndex = 3;
			this->label4->Text = L"玩家2";
			// 
			// textBox_Player1
			// 
			this->textBox_Player1->Location = System::Drawing::Point(108, 141);
			this->textBox_Player1->Name = L"textBox_Player1";
			this->textBox_Player1->Size = System::Drawing::Size(160, 22);
			this->textBox_Player1->TabIndex = 4;
			this->textBox_Player1->TextChanged += gcnew System::EventHandler(this, &SetPlayer::textBox_Player1_TextChanged);
			// 
			// textBox_Player2
			// 
			this->textBox_Player2->Location = System::Drawing::Point(108, 187);
			this->textBox_Player2->Name = L"textBox_Player2";
			this->textBox_Player2->Size = System::Drawing::Size(160, 22);
			this->textBox_Player2->TabIndex = 5;
			this->textBox_Player2->TextChanged += gcnew System::EventHandler(this, &SetPlayer::textBox_Player2_TextChanged);
			// 
			// buttonOK
			// 
			this->buttonOK->Enabled = false;
			this->buttonOK->Location = System::Drawing::Point(134, 300);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(145, 39);
			this->buttonOK->TabIndex = 10;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &SetPlayer::buttonOK_Click);
			// 
			// buttonReset
			// 
			this->buttonReset->Location = System::Drawing::Point(321, 300);
			this->buttonReset->Name = L"buttonReset";
			this->buttonReset->Size = System::Drawing::Size(145, 39);
			this->buttonReset->TabIndex = 11;
			this->buttonReset->Text = L"Reset";
			this->buttonReset->UseVisualStyleBackColor = true;
			this->buttonReset->Click += gcnew System::EventHandler(this, &SetPlayer::buttonReset_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->player1ButtonX);
			this->panel1->Controls->Add(this->player1ButtonO);
			this->panel1->Location = System::Drawing::Point(423, 134);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(110, 29);
			this->panel1->TabIndex = 12;
			// 
			// player1ButtonX
			// 
			this->player1ButtonX->AutoSize = true;
			this->player1ButtonX->Location = System::Drawing::Point(49, 5);
			this->player1ButtonX->Name = L"player1ButtonX";
			this->player1ButtonX->Size = System::Drawing::Size(38, 21);
			this->player1ButtonX->TabIndex = 1;
			this->player1ButtonX->Text = L"X";
			this->player1ButtonX->UseVisualStyleBackColor = true;
			// 
			// player1ButtonO
			// 
			this->player1ButtonO->AutoSize = true;
			this->player1ButtonO->Checked = true;
			this->player1ButtonO->Location = System::Drawing::Point(3, 5);
			this->player1ButtonO->Name = L"player1ButtonO";
			this->player1ButtonO->Size = System::Drawing::Size(40, 21);
			this->player1ButtonO->TabIndex = 0;
			this->player1ButtonO->TabStop = true;
			this->player1ButtonO->Text = L"O";
			this->player1ButtonO->UseVisualStyleBackColor = true;
			this->player1ButtonO->CheckedChanged += gcnew System::EventHandler(this, &SetPlayer::player1ButtonO_CheckedChanged);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->player2ButtonX);
			this->panel2->Controls->Add(this->player2ButtonO);
			this->panel2->Location = System::Drawing::Point(423, 180);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(110, 29);
			this->panel2->TabIndex = 13;
			// 
			// player2ButtonX
			// 
			this->player2ButtonX->AutoSize = true;
			this->player2ButtonX->Location = System::Drawing::Point(49, 5);
			this->player2ButtonX->Name = L"player2ButtonX";
			this->player2ButtonX->Size = System::Drawing::Size(38, 21);
			this->player2ButtonX->TabIndex = 1;
			this->player2ButtonX->Text = L"X";
			this->player2ButtonX->UseVisualStyleBackColor = true;
			// 
			// player2ButtonO
			// 
			this->player2ButtonO->AutoSize = true;
			this->player2ButtonO->Checked = true;
			this->player2ButtonO->Location = System::Drawing::Point(3, 5);
			this->player2ButtonO->Name = L"player2ButtonO";
			this->player2ButtonO->Size = System::Drawing::Size(40, 21);
			this->player2ButtonO->TabIndex = 0;
			this->player2ButtonO->TabStop = true;
			this->player2ButtonO->Text = L"O";
			this->player2ButtonO->UseVisualStyleBackColor = true;
			this->player2ButtonO->CheckedChanged += gcnew System::EventHandler(this, &SetPlayer::player2ButtonO_CheckedChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(320, 140);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 18);
			this->label5->TabIndex = 14;
			this->label5->Text = L"玩家1請選擇";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(320, 185);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 18);
			this->label6->TabIndex = 15;
			this->label6->Text = L"玩家2請選擇";
			// 
			// SetPlayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 433);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->buttonReset);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->textBox_Player2);
			this->Controls->Add(this->textBox_Player1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"SetPlayer";
			this->Text = L"Welcome";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonOK_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// 點OK進入遊戲主畫面，依照兩位玩家輸入的名字和選擇建立主畫面
		TickTacToe^ dlg = gcnew TickTacToe(player1Name, player1IsO, player2Name, player2IsO);
		dlg->ShowDialog();
	}
	private: System::Void buttonReset_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// 點Reset重設玩家資訊
		textBox_Player1->Text = String::Empty;
		textBox_Player2->Text = String::Empty;
		player1ButtonO->Checked = true;
		player2ButtonO->Checked = true;
	}
	private: System::Void player1ButtonO_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// 如果玩家1選擇O，playeriIsO為true，否則為false
		if (player1ButtonO->Checked == true)
			player1IsO = true;
		else
			player1IsO = false;
		// 兩位玩家選擇不同角色時，才開放點擊OK按鈕
		if (player1IsO != player2IsO)
			buttonOK->Enabled = true;
		else
			buttonOK->Enabled = false;
	}
	private: System::Void player2ButtonO_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// 如果玩家2選擇O，playeriIsO為true，否則為false
		if (player2ButtonO->Checked == true)
			player2IsO = true;
		else
			player2IsO = false;
		// 兩位玩家選擇不同角色時，才開放點擊OK按鈕
		if (player1IsO != player2IsO)
			buttonOK->Enabled = true;
		else
			buttonOK->Enabled = false;
	}
	private: System::Void textBox_Player1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// 把玩家1輸入的名字存到player1Name
		player1Name = textBox_Player1->Text;
	}
	private: System::Void textBox_Player2_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		// 把玩家2輸入的名字存到player1Name
		player2Name = textBox_Player2->Text;
	}
	};
}