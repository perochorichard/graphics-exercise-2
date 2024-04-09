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

		static bool moveLightValue;
		static bool resetLightPositionValue;
		static int specularStrengthValue;
		static int specularColorRValue;
		static int specularColorGValue;
		static int specularColorBValue;
		static bool colorByPositionValue;
		static bool resetTeapotPositionValue;
		static bool moveCubesToSphereValue;

		ToolWindow(void)
		{
			InitializeComponent();
			moveLightValue = rb_MoveLight->Checked;
			resetLightPositionValue = false;
			specularStrengthValue = tb_SpecularStrength->Value;
			specularColorRValue = tb_SpecularColor_R->Value;
			specularColorGValue = tb_SpecularColor_G->Value;
			specularColorBValue = tb_SpecularColor_B->Value;
			colorByPositionValue = rb_ColorByPosition->Checked;
			resetTeapotPositionValue = false;
			moveCubesToSphereValue = rb_MoveCubesToSphere->Checked;
		}

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
	private: System::Windows::Forms::RadioButton^ rb_MoveLight;
	private: System::Windows::Forms::RadioButton^ rb_ColorByPosition;
	private: System::Windows::Forms::RadioButton^ rb_MoveCubesToSphere;
	private: System::Windows::Forms::TrackBar^ tb_SpecularStrength;
	private: System::Windows::Forms::Button^ btn_ResetLightPosition;
	private: System::Windows::Forms::Button^ btn_ResetTeapotPosition;
	private: System::Windows::Forms::TrackBar^ tb_SpecularColor_R;
	private: System::Windows::Forms::TrackBar^ tb_SpecularColor_G;
	private: System::Windows::Forms::TrackBar^ tb_SpecularColor_B;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ lbl_SpecularStrength;
	private: System::Windows::Forms::Label^ lbl_R;
	private: System::Windows::Forms::Label^ lbl_G;
	private: System::Windows::Forms::Label^ lbl_B;





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
			this->rb_MoveLight = (gcnew System::Windows::Forms::RadioButton());
			this->rb_ColorByPosition = (gcnew System::Windows::Forms::RadioButton());
			this->rb_MoveCubesToSphere = (gcnew System::Windows::Forms::RadioButton());
			this->tb_SpecularStrength = (gcnew System::Windows::Forms::TrackBar());
			this->tb_SpecularColor_R = (gcnew System::Windows::Forms::TrackBar());
			this->btn_ResetLightPosition = (gcnew System::Windows::Forms::Button());
			this->btn_ResetTeapotPosition = (gcnew System::Windows::Forms::Button());
			this->tb_SpecularColor_G = (gcnew System::Windows::Forms::TrackBar());
			this->tb_SpecularColor_B = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lbl_SpecularStrength = (gcnew System::Windows::Forms::Label());
			this->lbl_R = (gcnew System::Windows::Forms::Label());
			this->lbl_G = (gcnew System::Windows::Forms::Label());
			this->lbl_B = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_SpecularStrength))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_SpecularColor_R))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_SpecularColor_G))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_SpecularColor_B))->BeginInit();
			this->SuspendLayout();
			// 
			// rb_MoveLight
			// 
			this->rb_MoveLight->AutoSize = true;
			this->rb_MoveLight->Checked = true;
			this->rb_MoveLight->Location = System::Drawing::Point(24, 21);
			this->rb_MoveLight->Name = L"rb_MoveLight";
			this->rb_MoveLight->Size = System::Drawing::Size(78, 17);
			this->rb_MoveLight->TabIndex = 0;
			this->rb_MoveLight->TabStop = true;
			this->rb_MoveLight->Text = L"Move Light";
			this->rb_MoveLight->UseVisualStyleBackColor = true;
			this->rb_MoveLight->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::rb_MoveLight_CheckedChanged);
			// 
			// rb_ColorByPosition
			// 
			this->rb_ColorByPosition->AutoSize = true;
			this->rb_ColorByPosition->Location = System::Drawing::Point(24, 306);
			this->rb_ColorByPosition->Name = L"rb_ColorByPosition";
			this->rb_ColorByPosition->Size = System::Drawing::Size(104, 17);
			this->rb_ColorByPosition->TabIndex = 1;
			this->rb_ColorByPosition->Text = L"Color By Position";
			this->rb_ColorByPosition->UseVisualStyleBackColor = true;
			this->rb_ColorByPosition->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::rb_ColorByPosition_CheckedChanged);
			// 
			// rb_MoveCubesToSphere
			// 
			this->rb_MoveCubesToSphere->AutoSize = true;
			this->rb_MoveCubesToSphere->Location = System::Drawing::Point(24, 375);
			this->rb_MoveCubesToSphere->Name = L"rb_MoveCubesToSphere";
			this->rb_MoveCubesToSphere->Size = System::Drawing::Size(138, 17);
			this->rb_MoveCubesToSphere->TabIndex = 2;
			this->rb_MoveCubesToSphere->Text = L"Move Cubes To Sphere";
			this->rb_MoveCubesToSphere->UseVisualStyleBackColor = true;
			this->rb_MoveCubesToSphere->CheckedChanged += gcnew System::EventHandler(this, &ToolWindow::rb_MoveCubesToSphere_CheckedChanged);
			// 
			// tb_SpecularStrength
			// 
			this->tb_SpecularStrength->Location = System::Drawing::Point(151, 81);
			this->tb_SpecularStrength->Maximum = 128;
			this->tb_SpecularStrength->Minimum = 1;
			this->tb_SpecularStrength->Name = L"tb_SpecularStrength";
			this->tb_SpecularStrength->Size = System::Drawing::Size(381, 45);
			this->tb_SpecularStrength->TabIndex = 3;
			this->tb_SpecularStrength->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->tb_SpecularStrength->Value = 4;
			this->tb_SpecularStrength->Scroll += gcnew System::EventHandler(this, &ToolWindow::tb_SpecularStrength_Scroll);
			// 
			// tb_SpecularColor_R
			// 
			this->tb_SpecularColor_R->Location = System::Drawing::Point(151, 150);
			this->tb_SpecularColor_R->Maximum = 300;
			this->tb_SpecularColor_R->Name = L"tb_SpecularColor_R";
			this->tb_SpecularColor_R->Size = System::Drawing::Size(381, 45);
			this->tb_SpecularColor_R->TabIndex = 4;
			this->tb_SpecularColor_R->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->tb_SpecularColor_R->Value = 100;
			this->tb_SpecularColor_R->Scroll += gcnew System::EventHandler(this, &ToolWindow::tb_SpecularColor_R_Scroll);
			// 
			// btn_ResetLightPosition
			// 
			this->btn_ResetLightPosition->AutoSize = true;
			this->btn_ResetLightPosition->Location = System::Drawing::Point(44, 44);
			this->btn_ResetLightPosition->Name = L"btn_ResetLightPosition";
			this->btn_ResetLightPosition->Size = System::Drawing::Size(111, 23);
			this->btn_ResetLightPosition->TabIndex = 5;
			this->btn_ResetLightPosition->Text = L"Reset Light Position";
			this->btn_ResetLightPosition->UseVisualStyleBackColor = true;
			this->btn_ResetLightPosition->Click += gcnew System::EventHandler(this, &ToolWindow::btn_ResetLightPosition_Click);
			// 
			// btn_ResetTeapotPosition
			// 
			this->btn_ResetTeapotPosition->AutoSize = true;
			this->btn_ResetTeapotPosition->Location = System::Drawing::Point(44, 329);
			this->btn_ResetTeapotPosition->Name = L"btn_ResetTeapotPosition";
			this->btn_ResetTeapotPosition->Size = System::Drawing::Size(122, 23);
			this->btn_ResetTeapotPosition->TabIndex = 6;
			this->btn_ResetTeapotPosition->Text = L"Reset Teapot Position";
			this->btn_ResetTeapotPosition->UseVisualStyleBackColor = true;
			this->btn_ResetTeapotPosition->Click += gcnew System::EventHandler(this, &ToolWindow::btn_ResetTeapotPosition_Click);
			// 
			// tb_SpecularColor_G
			// 
			this->tb_SpecularColor_G->Location = System::Drawing::Point(151, 201);
			this->tb_SpecularColor_G->Maximum = 300;
			this->tb_SpecularColor_G->Name = L"tb_SpecularColor_G";
			this->tb_SpecularColor_G->Size = System::Drawing::Size(381, 45);
			this->tb_SpecularColor_G->TabIndex = 7;
			this->tb_SpecularColor_G->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->tb_SpecularColor_G->Value = 100;
			this->tb_SpecularColor_G->Scroll += gcnew System::EventHandler(this, &ToolWindow::tb_SpecularColor_G_Scroll);
			// 
			// tb_SpecularColor_B
			// 
			this->tb_SpecularColor_B->Location = System::Drawing::Point(151, 252);
			this->tb_SpecularColor_B->Maximum = 300;
			this->tb_SpecularColor_B->Name = L"tb_SpecularColor_B";
			this->tb_SpecularColor_B->Size = System::Drawing::Size(381, 45);
			this->tb_SpecularColor_B->TabIndex = 8;
			this->tb_SpecularColor_B->TickStyle = System::Windows::Forms::TickStyle::Both;
			this->tb_SpecularColor_B->Value = 100;
			this->tb_SpecularColor_B->Scroll += gcnew System::EventHandler(this, &ToolWindow::tb_SpecularColor_B_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(43, 93);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Specular Strength";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(43, 163);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Specular Color";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(130, 163);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(15, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"R";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(130, 214);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(15, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"G";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(131, 267);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(14, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"B";
			// 
			// lbl_SpecularStrength
			// 
			this->lbl_SpecularStrength->AutoSize = true;
			this->lbl_SpecularStrength->Location = System::Drawing::Point(538, 93);
			this->lbl_SpecularStrength->Name = L"lbl_SpecularStrength";
			this->lbl_SpecularStrength->Size = System::Drawing::Size(13, 13);
			this->lbl_SpecularStrength->TabIndex = 14;
			this->lbl_SpecularStrength->Text = L"4";
			// 
			// lbl_R
			// 
			this->lbl_R->AutoSize = true;
			this->lbl_R->Location = System::Drawing::Point(540, 163);
			this->lbl_R->Name = L"lbl_R";
			this->lbl_R->Size = System::Drawing::Size(28, 13);
			this->lbl_R->TabIndex = 15;
			this->lbl_R->Text = L"1.00";
			// 
			// lbl_G
			// 
			this->lbl_G->AutoSize = true;
			this->lbl_G->Location = System::Drawing::Point(540, 214);
			this->lbl_G->Name = L"lbl_G";
			this->lbl_G->Size = System::Drawing::Size(28, 13);
			this->lbl_G->TabIndex = 16;
			this->lbl_G->Text = L"1.00";
			// 
			// lbl_B
			// 
			this->lbl_B->AutoSize = true;
			this->lbl_B->Location = System::Drawing::Point(540, 267);
			this->lbl_B->Name = L"lbl_B";
			this->lbl_B->Size = System::Drawing::Size(28, 13);
			this->lbl_B->TabIndex = 17;
			this->lbl_B->Text = L"1.00";
			// 
			// ToolWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(587, 421);
			this->Controls->Add(this->lbl_B);
			this->Controls->Add(this->lbl_G);
			this->Controls->Add(this->lbl_R);
			this->Controls->Add(this->lbl_SpecularStrength);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tb_SpecularColor_B);
			this->Controls->Add(this->tb_SpecularColor_G);
			this->Controls->Add(this->btn_ResetTeapotPosition);
			this->Controls->Add(this->btn_ResetLightPosition);
			this->Controls->Add(this->tb_SpecularColor_R);
			this->Controls->Add(this->tb_SpecularStrength);
			this->Controls->Add(this->rb_MoveCubesToSphere);
			this->Controls->Add(this->rb_ColorByPosition);
			this->Controls->Add(this->rb_MoveLight);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"ToolWindow";
			this->Text = L"ToolWindow";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_SpecularStrength))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_SpecularColor_R))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_SpecularColor_G))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tb_SpecularColor_B))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void rb_MoveLight_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	moveLightValue = rb_MoveLight->Checked;
}
private: System::Void rb_ColorByPosition_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	colorByPositionValue = rb_ColorByPosition->Checked;
}
private: System::Void rb_MoveCubesToSphere_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	moveCubesToSphereValue = rb_MoveCubesToSphere->Checked;
}

private: System::Void tb_SpecularStrength_Scroll(System::Object^ sender, System::EventArgs^ e) {
	specularStrengthValue = tb_SpecularStrength->Value;
	lbl_SpecularStrength->Text = specularStrengthValue.ToString();
}
private: System::Void tb_SpecularColor_R_Scroll(System::Object^ sender, System::EventArgs^ e) {
	specularColorRValue = tb_SpecularColor_R->Value;
	lbl_R->Text = ((float)specularColorRValue / 100).ToString();
}
private: System::Void tb_SpecularColor_G_Scroll(System::Object^ sender, System::EventArgs^ e) {
	specularColorGValue = tb_SpecularColor_G->Value;
	lbl_G->Text = ((float)specularColorGValue / 100).ToString();
}
private: System::Void tb_SpecularColor_B_Scroll(System::Object^ sender, System::EventArgs^ e) {
	specularColorBValue = tb_SpecularColor_B->Value;
	lbl_B->Text = ((float)specularColorBValue / 100).ToString();
}

private: System::Void btn_ResetLightPosition_Click(System::Object^ sender, System::EventArgs^ e) {
	resetLightPositionValue = true;
}
private: System::Void btn_ResetTeapotPosition_Click(System::Object^ sender, System::EventArgs^ e) {
	resetTeapotPositionValue = true;
}
};
}
