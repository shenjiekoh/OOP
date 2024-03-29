#pragma once
#include "Result.h"

namespace HW04 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TickTacToe
	/// </summary>
	public ref class TickTacToe : public System::Windows::Forms::Form
	{
	public:
		TickTacToe(String^ name1, bool isO1, String^ name2, bool isO2)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			// 如果玩家沒有輸入名字，預設名字為玩家1/玩家2
			if (name1 == String::Empty)
				player1Name = L"玩家1";
			else
				player1Name = name1;
			if (name2 == String::Empty)
				player2Name = L"玩家2";
			else
				player2Name = name2;
			// 存取兩個玩家的角色
			player1IsO = isO1;
			player2IsO = isO2;
			// 先手玩家按鈕顯示文字改為玩家名字
			player1Button->Text = player1Name;
			player2Button->Text = player2Name;
			whoseTurn = 1;	// 預設玩家1先手
			hasWinner = false;	// 預設沒有贏家
			// 設定按鈕陣列內容
			bts = gcnew array<Button^ >{Button11, Button12, Button13, Button21, Button22,
				Button23, Button31, Button32, Button33};
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TickTacToe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBoxFirstMove;
	protected:
	private: System::Windows::Forms::RadioButton^ player2Button;
	private: System::Windows::Forms::RadioButton^ player1Button;
	private: System::Windows::Forms::Button^ startStopButton;
	private: System::Windows::Forms::Label^ timeLabel;
	private: System::Windows::Forms::Button^ Button11;
	private: System::Windows::Forms::Button^ Button12;
	private: System::Windows::Forms::Button^ Button13;
	private: System::Windows::Forms::Button^ Button21;
	private: System::Windows::Forms::Button^ Button22;
	private: System::Windows::Forms::Button^ Button23;
	private: System::Windows::Forms::Button^ Button31;
	private: System::Windows::Forms::Button^ Button32;
	private: System::Windows::Forms::Button^ Button33;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::StatusStrip^ statusStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ playerNameStatusLabel;
	private: System::Windows::Forms::ToolStripStatusLabel^ mouseLocationStatusLabel;
	private: System::Windows::Forms::Timer^ timer1;

		   String^ player1Name;	// 玩家1名字
		   String^ player2Name;	// 玩家2名字
		   bool player1IsO;	// 玩家1是不是O (true:O false:X)
		   bool player2IsO;	// 玩家2是不是O (true:O false:X)
		   int whoseTurn;	// 現在輪到誰？(1:玩家1 2:玩家2)
		   DateTime startTime;	// 開始遊玩時間
		   bool hasWinner;	// 有贏家產生？
		   array<Button^>^ bts;	// 九宮格按鈕組成的array

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->groupBoxFirstMove = (gcnew System::Windows::Forms::GroupBox());
			   this->player2Button = (gcnew System::Windows::Forms::RadioButton());
			   this->player1Button = (gcnew System::Windows::Forms::RadioButton());
			   this->startStopButton = (gcnew System::Windows::Forms::Button());
			   this->timeLabel = (gcnew System::Windows::Forms::Label());
			   this->Button11 = (gcnew System::Windows::Forms::Button());
			   this->Button12 = (gcnew System::Windows::Forms::Button());
			   this->Button13 = (gcnew System::Windows::Forms::Button());
			   this->Button21 = (gcnew System::Windows::Forms::Button());
			   this->Button22 = (gcnew System::Windows::Forms::Button());
			   this->Button23 = (gcnew System::Windows::Forms::Button());
			   this->Button31 = (gcnew System::Windows::Forms::Button());
			   this->Button32 = (gcnew System::Windows::Forms::Button());
			   this->Button33 = (gcnew System::Windows::Forms::Button());
			   this->statusStrip = (gcnew System::Windows::Forms::StatusStrip());
			   this->playerNameStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			   this->mouseLocationStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->groupBoxFirstMove->SuspendLayout();
			   this->statusStrip->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // groupBoxFirstMove
			   // 
			   this->groupBoxFirstMove->Controls->Add(this->player2Button);
			   this->groupBoxFirstMove->Controls->Add(this->player1Button);
			   this->groupBoxFirstMove->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->groupBoxFirstMove->Location = System::Drawing::Point(550, 33);
			   this->groupBoxFirstMove->Name = L"groupBoxFirstMove";
			   this->groupBoxFirstMove->Size = System::Drawing::Size(200, 100);
			   this->groupBoxFirstMove->TabIndex = 0;
			   this->groupBoxFirstMove->TabStop = false;
			   this->groupBoxFirstMove->Text = L"先手玩家";
			   // 
			   // player2Button
			   // 
			   this->player2Button->AutoSize = true;
			   this->player2Button->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->player2Button->Location = System::Drawing::Point(19, 61);
			   this->player2Button->Name = L"player2Button";
			   this->player2Button->Size = System::Drawing::Size(65, 22);
			   this->player2Button->TabIndex = 1;
			   this->player2Button->TabStop = true;
			   this->player2Button->Text = L"玩家2";
			   this->player2Button->UseVisualStyleBackColor = true;
			   // 
			   // player1Button
			   // 
			   this->player1Button->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->player1Button->Location = System::Drawing::Point(19, 33);
			   this->player1Button->Name = L"player1Button";
			   this->player1Button->Size = System::Drawing::Size(104, 24);
			   this->player1Button->TabIndex = 0;
			   this->player1Button->TabStop = true;
			   this->player1Button->Text = L"玩家1";
			   this->player1Button->UseVisualStyleBackColor = true;
			   // 
			   // startStopButton
			   // 
			   this->startStopButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			   this->startStopButton->Location = System::Drawing::Point(545, 361);
			   this->startStopButton->Name = L"startStopButton";
			   this->startStopButton->Size = System::Drawing::Size(212, 47);
			   this->startStopButton->TabIndex = 1;
			   this->startStopButton->Text = L"Start";
			   this->startStopButton->UseVisualStyleBackColor = true;
			   this->startStopButton->Click += gcnew System::EventHandler(this, &TickTacToe::startStopButton_Click);
			   // 
			   // timeLabel
			   // 
			   this->timeLabel->AutoSize = true;
			   this->timeLabel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->timeLabel->Font = (gcnew System::Drawing::Font(L"Consolas", 16));
			   this->timeLabel->Location = System::Drawing::Point(545, 446);
			   this->timeLabel->Name = L"timeLabel";
			   this->timeLabel->Size = System::Drawing::Size(212, 34);
			   this->timeLabel->TabIndex = 2;
			   this->timeLabel->Text = L"00:00:00.0000";
			   // 
			   // Button11
			   // 
			   this->Button11->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button11->Enabled = false;
			   this->Button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button11->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->Button11->Location = System::Drawing::Point(30, 30);
			   this->Button11->Name = L"Button11";
			   this->Button11->Size = System::Drawing::Size(150, 150);
			   this->Button11->TabIndex = 3;
			   this->Button11->UseVisualStyleBackColor = false;
			   this->Button11->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button11->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // Button12
			   // 
			   this->Button12->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button12->Enabled = false;
			   this->Button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button12->Location = System::Drawing::Point(180, 30);
			   this->Button12->Name = L"Button12";
			   this->Button12->Size = System::Drawing::Size(150, 150);
			   this->Button12->TabIndex = 4;
			   this->Button12->UseVisualStyleBackColor = false;
			   this->Button12->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button12->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // Button13
			   // 
			   this->Button13->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button13->Enabled = false;
			   this->Button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button13->Location = System::Drawing::Point(330, 30);
			   this->Button13->Name = L"Button13";
			   this->Button13->Size = System::Drawing::Size(150, 150);
			   this->Button13->TabIndex = 5;
			   this->Button13->UseVisualStyleBackColor = false;
			   this->Button13->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button13->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // Button21
			   // 
			   this->Button21->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button21->Enabled = false;
			   this->Button21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button21->Location = System::Drawing::Point(30, 180);
			   this->Button21->Name = L"Button21";
			   this->Button21->Size = System::Drawing::Size(150, 150);
			   this->Button21->TabIndex = 6;
			   this->Button21->UseVisualStyleBackColor = false;
			   this->Button21->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button21->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // Button22
			   // 
			   this->Button22->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button22->Enabled = false;
			   this->Button22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button22->Location = System::Drawing::Point(180, 180);
			   this->Button22->Name = L"Button22";
			   this->Button22->Size = System::Drawing::Size(150, 150);
			   this->Button22->TabIndex = 7;
			   this->Button22->UseVisualStyleBackColor = false;
			   this->Button22->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button22->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // Button23
			   // 
			   this->Button23->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button23->Enabled = false;
			   this->Button23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button23->Location = System::Drawing::Point(330, 180);
			   this->Button23->Name = L"Button23";
			   this->Button23->Size = System::Drawing::Size(150, 150);
			   this->Button23->TabIndex = 8;
			   this->Button23->UseVisualStyleBackColor = false;
			   this->Button23->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button23->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // Button31
			   // 
			   this->Button31->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button31->Enabled = false;
			   this->Button31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button31->Location = System::Drawing::Point(30, 330);
			   this->Button31->Name = L"Button31";
			   this->Button31->Size = System::Drawing::Size(150, 150);
			   this->Button31->TabIndex = 9;
			   this->Button31->UseVisualStyleBackColor = false;
			   this->Button31->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button31->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // Button32
			   // 
			   this->Button32->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button32->Enabled = false;
			   this->Button32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button32->Location = System::Drawing::Point(180, 330);
			   this->Button32->Name = L"Button32";
			   this->Button32->Size = System::Drawing::Size(150, 150);
			   this->Button32->TabIndex = 10;
			   this->Button32->UseVisualStyleBackColor = false;
			   this->Button32->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button32->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // Button33
			   // 
			   this->Button33->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->Button33->Enabled = false;
			   this->Button33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 60));
			   this->Button33->Location = System::Drawing::Point(330, 330);
			   this->Button33->Name = L"Button33";
			   this->Button33->Size = System::Drawing::Size(150, 150);
			   this->Button33->TabIndex = 11;
			   this->Button33->UseVisualStyleBackColor = false;
			   this->Button33->Click += gcnew System::EventHandler(this, &TickTacToe::Button_Click);
			   this->Button33->MouseHover += gcnew System::EventHandler(this, &TickTacToe::Button_MouseHover);
			   // 
			   // statusStrip
			   // 
			   this->statusStrip->ImageScalingSize = System::Drawing::Size(20, 20);
			   this->statusStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->playerNameStatusLabel,
					   this->mouseLocationStatusLabel
			   });
			   this->statusStrip->Location = System::Drawing::Point(0, 531);
			   this->statusStrip->Name = L"statusStrip";
			   this->statusStrip->Size = System::Drawing::Size(782, 22);
			   this->statusStrip->TabIndex = 13;
			   this->statusStrip->Text = L"statusStrip";
			   // 
			   // playerNameStatusLabel
			   // 
			   this->playerNameStatusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->playerNameStatusLabel->Name = L"playerNameStatusLabel";
			   this->playerNameStatusLabel->Size = System::Drawing::Size(0, 16);
			   // 
			   // mouseLocationStatusLabel
			   // 
			   this->mouseLocationStatusLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 9, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->mouseLocationStatusLabel->Name = L"mouseLocationStatusLabel";
			   this->mouseLocationStatusLabel->Size = System::Drawing::Size(0, 16);
			   // 
			   // timer1
			   // 
			   this->timer1->Interval = 1;
			   this->timer1->Tick += gcnew System::EventHandler(this, &TickTacToe::timer1_Tick);
			   // 
			   // TickTacToe
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(782, 553);
			   this->Controls->Add(this->timeLabel);
			   this->Controls->Add(this->statusStrip);
			   this->Controls->Add(this->Button33);
			   this->Controls->Add(this->Button32);
			   this->Controls->Add(this->Button31);
			   this->Controls->Add(this->Button23);
			   this->Controls->Add(this->Button22);
			   this->Controls->Add(this->Button21);
			   this->Controls->Add(this->Button13);
			   this->Controls->Add(this->Button12);
			   this->Controls->Add(this->Button11);
			   this->Controls->Add(this->startStopButton);
			   this->Controls->Add(this->groupBoxFirstMove);
			   this->Name = L"TickTacToe";
			   this->Text = L"Tick-Tac-Toe";
			   this->MouseHover += gcnew System::EventHandler(this, &TickTacToe::TickTacToe_MouseHover);
			   this->groupBoxFirstMove->ResumeLayout(false);
			   this->groupBoxFirstMove->PerformLayout();
			   this->statusStrip->ResumeLayout(false);
			   this->statusStrip->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void startStopButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (startStopButton->Text == "Start")
		{
			// 如果點擊按鈕時為Start，開始遊戲，將按鈕名字改為Stop
			startStopButton->Text = "Stop";
			// 暫時關閉先手玩家radioButton選擇功能
			player1Button->Enabled = false;
			player2Button->Enabled = false;
			// 開放點選九宮格
			for each (Button ^ b in bts)
				b->Enabled = true;
			// 記錄遊戲開始的時間，並啟動timer開始計時
			startTime = DateTime::Now;
			timer1->Start();
		}
		else
		{
			// 如果點擊按鈕時為Stop，停止遊戲，將按鈕名字改為Start
			startStopButton->Text = "Start";
			// 重新開放先手玩家radioButton選擇功能
			player1Button->Enabled = true;
			player2Button->Enabled = true;
			// 關閉九宮格
			for each (Button ^ b in bts)
				b->Enabled = false;
			// 停止計時，將計時label文字歸零
			timer1->Stop();
			timeLabel->Text = L"00:00:00.0000";
		}
		// 點按鈕時清空九宮格內容
		for each (Button ^ b in bts)
			b->Text = String::Empty;

		if (player1Button->Checked == true)	// 如果是玩家1先手，輪到玩家1點選九宮格，並且在statusStrip顯示玩家1名字
		{
			whoseTurn = 1;
			playerNameStatusLabel->Text = player1Button->Text;
		}
		else	// 如果是玩家2先手，輪到玩家2點選九宮格，並且在statusStrip顯示玩家2名字
		{
			whoseTurn = 2;
			playerNameStatusLabel->Text = player2Button->Text;
		}

	}
	private: System::Void Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ b = safe_cast<Button^>(sender);	// 先接收玩家點選哪個九宮格按鈕
		
		if (whoseTurn == 1 && b->Text == String::Empty)
		{
			// 此時為玩家1點選，並且按鈕上面是空字串時，填入O或X
			if (player1IsO)
				b->Text = L"O";
			else
				b->Text = L"X";
		}
		else if (whoseTurn == 2 && b->Text == String::Empty)
		{
			// 此時為玩家2點選，並且按鈕上面是空字串時，填入O或X
			if (player2IsO)
				b->Text = L"O";
			else
				b->Text = L"X";
		}
		CheckWinner();	// 點擊後判斷是否有贏家出現
		if (hasWinner)
		{
			// 有人贏了，停止計時，將開始/停止按鈕改回Start，重新開放選擇先手玩家，並且把九宮格點選功能關閉
			timer1->Stop();
			startStopButton->Text = "Start";
			player1Button->Enabled = true;
			player2Button->Enabled = true;
			for each (Button ^ b in bts)
				b->Enabled = false;

			String^ winnerName;
			if (whoseTurn == 1)	// 如果是玩家1點選之後獲勝，則贏家為玩家1，否則贏家為玩家2，保存贏家名字
				winnerName = player1Button->Text;
			else
				winnerName = player2Button->Text;
			// 根據贏家名字和遊戲時長建立結果視窗
			Result^ dlg = gcnew Result(winnerName, timeLabel->Text);	
			dlg->ShowDialog();
		}
		else
			if (CheckTie())	// 沒有贏家情況1:雙方平手
			{
				// 平手時，處理方式與有人獲勝時相同，但建立結果視窗時贏家名字為空字串
				timer1->Stop();
				startStopButton->Text = "Start";
				player1Button->Enabled = true;
				player2Button->Enabled = true;
				for each (Button ^ b in bts)
					b->Enabled = false;
				Result^ dlg = gcnew Result(String::Empty, timeLabel->Text);
				dlg->ShowDialog();
			}
			else
			{	// 沒有贏家情況2:還沒有人贏
				if (whoseTurn == 1)	// 若此時是玩家1點選九宮格，更改satatusStrip文字，輪到玩家2
				{
					playerNameStatusLabel->Text = player2Button->Text;
					whoseTurn = 2;
				}
				else
				{	// 若此時是玩家2點選九宮格，更改satatusStrip文字，輪到玩家1
					playerNameStatusLabel->Text = player1Button->Text;
					whoseTurn = 1;
				}
			}
	}
		   void CheckWinner()	// 檢查是否有人獲勝
		   {
			   // 若任意橫向/縱向/斜向的按鈕文字相同，則代表有人成功連線獲勝
			   if (Button11->Text != String::Empty && Button11->Text == Button12->Text &&
				   Button12->Text == Button13->Text)
				   hasWinner = true;
			   else if (Button21->Text != String::Empty && Button21->Text == Button22->Text &&
				   Button22->Text == Button23->Text)
				   hasWinner = true;
			   else if (Button31->Text != String::Empty && Button31->Text == Button32->Text &&
				   Button32->Text == Button33->Text)
				   hasWinner = true;
			   else if (Button11->Text != String::Empty && Button11->Text == Button21->Text &&
				   Button21->Text == Button31->Text)
				   hasWinner = true;
			   else if (Button12->Text != String::Empty && Button12->Text == Button22->Text &&
				   Button22->Text == Button32->Text)
				   hasWinner = true;
			   else if (Button13->Text != String::Empty && Button13->Text == Button23->Text &&
				   Button23->Text == Button33->Text)
				   hasWinner = true;
			   else if (Button11->Text != String::Empty && Button11->Text == Button22->Text &&
				   Button22->Text == Button33->Text)
				   hasWinner = true;
			   else if (Button13->Text != String::Empty && Button13->Text == Button22->Text &&
				   Button22->Text == Button31->Text)
				   hasWinner = true;
			   else
				   hasWinner = false;
		   }
		   bool CheckTie()	// 檢查是否平手
		   {
			   // 如果九宮格中有按鈕沒有顯示文字(未點選)，不算平手
			   for each (Button ^ b in bts)
				   if (b->Text == String::Empty)
					   return false;
			   // 如果按鈕全部被點選過但是沒有贏家，則雙方平手
			   if (!hasWinner)
				   return true;
			   else
				   return false;
		   }
	private: System::Void Button_MouseHover(System::Object^ sender, System::EventArgs^ e)
	{
		Button^ b = safe_cast<Button^>(sender);	// 先接收鼠標停在哪個九宮格按鈕上面
		String^ bName = b->Name;	// 按鈕名字
		String^ x = bName->Substring(bName->Length - 2, 1);	// 按鈕名字最後第二個字為x座標
		String^ y = bName->Substring(bName->Length - 1);	// 按鈕名字最後一個字為y座標
		String^ str = L"滑鼠目前位置:(" + x + L", " + y + L")";	// 組合xy座標生成顯示字串
		mouseLocationStatusLabel->Text = str;	// 顯示滑鼠座標字串
	}
	private: System::Void TickTacToe_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		mouseLocationStatusLabel->Text = String::Empty;	// 滑鼠停留在九宮格以外地方時不顯示字串
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		TimeSpan^ elapsedTime = DateTime::Now - startTime;	// 計算當時遊戲時長
		timeLabel->Text = elapsedTime->ToString("hh\\:mm\\:ss\\.ffff");	// 顯示遊戲時長訊息
	}
	};
}
