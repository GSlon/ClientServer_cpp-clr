#pragma once

#include "Server.h"

namespace PPOlaba4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for ServerForm
	/// </summary>
	public ref class ServerForm : public System::Windows::Forms::Form
	{
	public:
		ServerForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			server = gcnew Server();


			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  IPlabel;
	protected:

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  Portlabel;
	private: System::Windows::Forms::RichTextBox^  richTextBox;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->IPlabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Portlabel = (gcnew System::Windows::Forms::Label());
			this->richTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"IP";
			// 
			// IPlabel
			// 
			this->IPlabel->AutoSize = true;
			this->IPlabel->Location = System::Drawing::Point(60, 25);
			this->IPlabel->Name = L"IPlabel";
			this->IPlabel->Size = System::Drawing::Size(0, 13);
			this->IPlabel->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(293, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(26, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Port";
			// 
			// Portlabel
			// 
			this->Portlabel->AutoSize = true;
			this->Portlabel->Location = System::Drawing::Point(348, 25);
			this->Portlabel->Name = L"Portlabel";
			this->Portlabel->Size = System::Drawing::Size(0, 13);
			this->Portlabel->TabIndex = 3;
			// 
			// richTextBox
			// 
			this->richTextBox->Location = System::Drawing::Point(12, 55);
			this->richTextBox->Name = L"richTextBox";
			this->richTextBox->ReadOnly = true;
			this->richTextBox->Size = System::Drawing::Size(462, 194);
			this->richTextBox->TabIndex = 4;
			this->richTextBox->Text = L"";
			// 
			// ServerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(499, 261);
			this->Controls->Add(this->richTextBox);
			this->Controls->Add(this->Portlabel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->IPlabel);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(515, 300);
			this->MinimumSize = System::Drawing::Size(515, 300);
			this->Name = L"ServerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Server";
			this->Load += gcnew System::EventHandler(this, &ServerForm::ServerForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: Server ^server;

	private: System::Void ServerForm_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		pair<IPAddress^, int>^ data;

		try
		{
			data = server->Connect();
		}
		catch (Exception ^e)
		{
			MessageBox::Show(e->Message);
			this->Close();
		}
		
		this->IPlabel->Text = data->first->ToString();
		this->Portlabel->Text = data->second.ToString();

		this->richTextBox->Text = "The server has been started.\n";
		this->richTextBox->Text += "Waiting for clients.\n";
		
		Thread ^wait = gcnew Thread(%server->WaitClient);
		wait->Start(); //запускаем поток
	}
};
}
