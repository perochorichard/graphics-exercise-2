#pragma once

namespace PrimitiveDrawTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ToolWindow
	/// </summary>
	public ref class ToolWindow : public System::Windows::Forms::Form
	{
	public:
		static bool InvertColors;

		ToolWindow(void)
		{
			InitializeComponent();

			InvertColors = checkBoxInvertColors->Checked;
		}
	private: 
		System::Windows::Forms::TrackBar^ trackBarY;
		System::Windows::Forms::TrackBar^ trackBarU;
		System::Windows::Forms::TrackBar^ trackBarV;
		System::Windows::Forms::Label^ labelY;
		System::Windows::Forms::Label^ labelU;
		System::Windows::Forms::Label^ labelV;
		System::Windows::Forms::Label^ labelYPercent;
		System::Windows::Forms::Label^ labelUPercent;
		System::Windows::Forms::Label^ labelVPercent;
		System::Windows::Forms::CheckBox^ checkBoxInvertColors;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ToolWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->checkBoxInvertColors = (gcnew System::Windows::Forms::CheckBox());
			this->trackBarY = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarU = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarV = (gcnew System::Windows::Forms::TrackBar());
			this->labelY = (gcnew System::Windows::Forms::Label());
			this->labelU = (gcnew System::Windows::Forms::Label());
			this->labelV = (gcnew System::Windows::Forms::Label());
			this->labelYPercent = (gcnew System::Windows::Forms::Label());
			this->labelUPercent = (gcnew System::Windows::Forms::Label());
			this->labelVPercent = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarU))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarV))->BeginInit();
			this->SuspendLayout();
			// 
			// checkBoxInvertColors
			// 
			this->checkBoxInvertColors->AutoSize = true;
			this->checkBoxInvertColors->Location = System::Drawing::Point(12, 176);
			this->checkBoxInvertColors->Name = L"checkBoxInvertColors";
			this->checkBoxInvertColors->Size = System::Drawing::Size(85, 17);
			this->checkBoxInvertColors->TabIndex = 0;
			this->checkBoxInvertColors->Text = L"Invert Colors";
			this->checkBoxInvertColors->UseVisualStyleBackColor = true;			// 
			// trackBarY
			// 
			this->trackBarY->Location = System::Drawing::Point(24, 23);
			this->trackBarY->Maximum = 200;
			this->trackBarY->Name = L"trackBarY";
			this->trackBarY->Size = System::Drawing::Size(512, 45);
			this->trackBarY->TabIndex = 1;
			this->trackBarY->Value = 100;
			this->trackBarY->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarY_Scroll);
			// 
			// trackBarU
			// 
			this->trackBarU->Location = System::Drawing::Point(24, 74);
			this->trackBarU->Maximum = 200;
			this->trackBarU->Name = L"trackBarU";
			this->trackBarU->Size = System::Drawing::Size(512, 45);
			this->trackBarU->TabIndex = 2;
			this->trackBarU->Value = 100;
			this->trackBarU->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarU_Scroll);
			// 
			// trackBarV
			// 
			this->trackBarV->Location = System::Drawing::Point(24, 125);
			this->trackBarV->Maximum = 200;
			this->trackBarV->Name = L"trackBarV";
			this->trackBarV->Size = System::Drawing::Size(512, 45);
			this->trackBarV->TabIndex = 3;
			this->trackBarV->Value = 100;
			this->trackBarV->Scroll += gcnew System::EventHandler(this, &ToolWindow::trackBarV_Scroll);
			// 
			// labelY
			// 
			this->labelY->AutoSize = true;
			this->labelY->Location = System::Drawing::Point(12, 35);
			this->labelY->Name = L"labelY";
			this->labelY->Size = System::Drawing::Size(14, 13);
			this->labelY->TabIndex = 4;
			this->labelY->Text = L"Y";
			// 
			// labelU
			// 
			this->labelU->AutoSize = true;
			this->labelU->Location = System::Drawing::Point(12, 86);
			this->labelU->Name = L"labelU";
			this->labelU->Size = System::Drawing::Size(15, 13);
			this->labelU->TabIndex = 5;
			this->labelU->Text = L"U";
			// 
			// labelV
			// 
			this->labelV->AutoSize = true;
			this->labelV->Location = System::Drawing::Point(12, 134);
			this->labelV->Name = L"labelV";
			this->labelV->Size = System::Drawing::Size(14, 13);
			this->labelV->TabIndex = 6;
			this->labelV->Text = L"V";
			// 
			// labelYPercent
			// 
			this->labelYPercent->AutoSize = true;
			this->labelYPercent->Location = System::Drawing::Point(542, 35);
			this->labelYPercent->Name = L"labelYPercent";
			this->labelYPercent->Size = System::Drawing::Size(33, 13);
			this->labelYPercent->TabIndex = 7;
			this->labelYPercent->Text = L"100%";
			// 
			// labelUPercent
			// 
			this->labelUPercent->AutoSize = true;
			this->labelUPercent->Location = System::Drawing::Point(542, 86);
			this->labelUPercent->Name = L"labelUPercent";
			this->labelUPercent->Size = System::Drawing::Size(33, 13);
			this->labelUPercent->TabIndex = 8;
			this->labelUPercent->Text = L"100%";
			// 
			// labelVPercent
			// 
			this->labelVPercent->AutoSize = true;
			this->labelVPercent->Location = System::Drawing::Point(542, 134);
			this->labelVPercent->Name = L"labelVPercent";
			this->labelVPercent->Size = System::Drawing::Size(33, 13);
			this->labelVPercent->TabIndex = 9;
			this->labelVPercent->Text = L"100%";
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(595, 261);
			this->Controls->Add(this->labelVPercent);
			this->Controls->Add(this->labelUPercent);
			this->Controls->Add(this->labelYPercent);
			this->Controls->Add(this->labelV);
			this->Controls->Add(this->labelU);
			this->Controls->Add(this->labelY);
			this->Controls->Add(this->trackBarV);
			this->Controls->Add(this->trackBarU);
			this->Controls->Add(this->trackBarY);
			this->Controls->Add(this->checkBoxInvertColors);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"ToolWindow";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarU))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void checkBoxInvertColors_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		InvertColors = checkBoxInvertColors->Checked;
	}
	private: System::Void trackBarY_Scroll(System::Object^ sender, System::EventArgs^ e) {
		labelYPercent->Text = String::Format("{0}%", trackBarY->Value);
	}
	private: System::Void trackBarU_Scroll(System::Object^ sender, System::EventArgs^ e) {
		labelUPercent->Text = String::Format("{0}%", trackBarU->Value);
	}
	private: System::Void trackBarV_Scroll(System::Object^ sender, System::EventArgs^ e) {
		labelVPercent->Text = String::Format("{0}%", trackBarV->Value);
	}
};
}
