#pragma once

namespace HW04 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Result
	/// </summary>
	public ref class Result : public System::Windows::Forms::Form
	{
	public:
		Result(String^ winner, String^ time)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			if (winner != String::Empty)	// 贏家名字不是空字串時，顯示贏家名字訊息
				resultLabel->Text = L"遊戲結束！" + winner + L"獲勝";
			else
				resultLabel->Text = L"遊戲結束！雙方戰成平手！";
			timeLabel->Text = L"共用時" + time;	// 顯示遊戲時長
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Result()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ resultLabel;
	protected:
	private: System::Windows::Forms::Label^ timeLabel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->resultLabel = (gcnew System::Windows::Forms::Label());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// resultLabel
			// 
			this->resultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultLabel->Location = System::Drawing::Point(50, 50);
			this->resultLabel->Name = L"resultLabel";
			this->resultLabel->Size = System::Drawing::Size(300, 20);
			this->resultLabel->TabIndex = 0;
			this->resultLabel->Text = L"resultLabel";
			this->resultLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// timeLabel
			// 
			this->timeLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->timeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeLabel->Location = System::Drawing::Point(100, 92);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(200, 20);
			this->timeLabel->TabIndex = 1;
			this->timeLabel->Text = L"timeLabel";
			this->timeLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Result
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 153);
			this->Controls->Add(this->timeLabel);
			this->Controls->Add(this->resultLabel);
			this->Name = L"Result";
			this->Text = L"Game Over";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
