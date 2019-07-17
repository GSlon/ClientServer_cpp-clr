#pragma once

#include "Client.h"
#include <cliext/algorithm>
#include <cliext/utility>

namespace PPOlaba4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace cliext;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			client = gcnew Client();
			dataGrid->Columns->Add("1","");
			dataGrid->Rows[0]->Cells["1"]->Value = "0";
			dataGrid->AllowUserToAddRows = false;
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menu;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  IPtext;
	private: System::Windows::Forms::TextBox^  Porttext;
	private: System::Windows::Forms::Button^  Conn;
	private: System::Windows::Forms::DataGridView^  dataGrid;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  Numtext;
	private: System::Windows::Forms::Button^  Countbutton;
	private: System::Windows::Forms::NumericUpDown^  Columns;
	private: System::Windows::Forms::NumericUpDown^  Rows;



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
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->IPtext = (gcnew System::Windows::Forms::TextBox());
			this->Porttext = (gcnew System::Windows::Forms::TextBox());
			this->Conn = (gcnew System::Windows::Forms::Button());
			this->dataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Numtext = (gcnew System::Windows::Forms::TextBox());
			this->Countbutton = (gcnew System::Windows::Forms::Button());
			this->Columns = (gcnew System::Windows::Forms::NumericUpDown());
			this->Rows = (gcnew System::Windows::Forms::NumericUpDown());
			this->menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Columns))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Rows))->BeginInit();
			this->SuspendLayout();
			// 
			// menu
			// 
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(484, 24);
			this->menu->TabIndex = 0;
			this->menu->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(103, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 257);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"IP";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(231, 257);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Port";
			// 
			// IPtext
			// 
			this->IPtext->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->IPtext->Location = System::Drawing::Point(35, 254);
			this->IPtext->Name = L"IPtext";
			this->IPtext->Size = System::Drawing::Size(160, 20);
			this->IPtext->TabIndex = 3;
			this->IPtext->Text = L"192.168.56.1";
			// 
			// Porttext
			// 
			this->Porttext->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Porttext->Location = System::Drawing::Point(272, 254);
			this->Porttext->Name = L"Porttext";
			this->Porttext->Size = System::Drawing::Size(100, 20);
			this->Porttext->TabIndex = 4;
			this->Porttext->Text = L"8001";
			// 
			// Conn
			// 
			this->Conn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->Conn->Location = System::Drawing::Point(397, 254);
			this->Conn->Name = L"Conn";
			this->Conn->Size = System::Drawing::Size(75, 20);
			this->Conn->TabIndex = 5;
			this->Conn->Text = L"connect";
			this->Conn->UseVisualStyleBackColor = true;
			this->Conn->Click += gcnew System::EventHandler(this, &MyForm::Conn_Click);
			// 
			// dataGrid
			// 
			this->dataGrid->AllowUserToOrderColumns = true;
			this->dataGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGrid->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid->Location = System::Drawing::Point(12, 27);
			this->dataGrid->Name = L"dataGrid";
			this->dataGrid->Size = System::Drawing::Size(355, 220);
			this->dataGrid->TabIndex = 6;
			this->dataGrid->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGrid_CellValueChanged);
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(394, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(47, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Number:";
			// 
			// Numtext
			// 
			this->Numtext->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Numtext->Location = System::Drawing::Point(397, 170);
			this->Numtext->Name = L"Numtext";
			this->Numtext->Size = System::Drawing::Size(56, 20);
			this->Numtext->TabIndex = 8;
			// 
			// Countbutton
			// 
			this->Countbutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Countbutton->Location = System::Drawing::Point(397, 206);
			this->Countbutton->Name = L"Countbutton";
			this->Countbutton->Size = System::Drawing::Size(75, 20);
			this->Countbutton->TabIndex = 9;
			this->Countbutton->Text = L"Count";
			this->Countbutton->UseVisualStyleBackColor = true;
			this->Countbutton->Click += gcnew System::EventHandler(this, &MyForm::Countbutton_Click);
			// 
			// Columns
			// 
			this->Columns->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Columns->Location = System::Drawing::Point(403, 27);
			this->Columns->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Columns->Name = L"Columns";
			this->Columns->ReadOnly = true;
			this->Columns->Size = System::Drawing::Size(50, 20);
			this->Columns->TabIndex = 12;
			this->Columns->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->Columns->ValueChanged += gcnew System::EventHandler(this, &MyForm::Columns_ValueChanged);
			// 
			// Rows
			// 
			this->Rows->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->Rows->Location = System::Drawing::Point(403, 53);
			this->Rows->Name = L"Rows";
			this->Rows->ReadOnly = true;
			this->Rows->Size = System::Drawing::Size(50, 20);
			this->Rows->TabIndex = 13;
			this->Rows->ValueChanged += gcnew System::EventHandler(this, &MyForm::Rows_ValueChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 286);
			this->Controls->Add(this->Rows);
			this->Controls->Add(this->Columns);
			this->Controls->Add(this->Countbutton);
			this->Controls->Add(this->Numtext);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGrid);
			this->Controls->Add(this->Conn);
			this->Controls->Add(this->Porttext);
			this->Controls->Add(this->IPtext);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menu);
			this->MainMenuStrip = this->menu;
			this->MinimumSize = System::Drawing::Size(500, 325);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Client";
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Columns))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Rows))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//private: ServerForm ^servForm;
	private: Client ^client;

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Close();
	}

	private: System::Void Conn_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			client->Connect(IPtext->Text, Convert::ToInt32(Porttext->Text));
		}
		catch (Exception ^e)
		{
			MessageBox::Show(e->Message);
		}
	}

	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		OpenFileDialog ^openDi = gcnew OpenFileDialog();
		if (openDi->ShowDialog() == System::Windows::Forms::DialogResult::Cancel)
		{
			return;
		}

		array<String^> ^data = File::ReadAllLines(openDi->FileName);
		
		if (data->Length == 0)
			return;

		try
		{
			this->ChangeDataGridView(data);
		}
		catch (Exception ^e)
		{
			MessageBox::Show(e->Message);
			return;
		}
		catch (const std::exception &e)
		{
			MessageBox::Show(Convert::ToString(e.what()));
			return;
		}
	}

	private: System::Void Countbutton_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (!client->IsConnected())
		{
			MessageBox::Show("no server connection");
			return;
		}

		if (Convert::ToInt32(Rows->Value) == 0)
		{
			MessageBox::Show("matrix is empty");
			return;
		}

		Int32 num = 0;
		try
		{
			num = Convert::ToInt32(Numtext->Text);
		}
		catch (Exception ^e)
		{
			MessageBox::Show(e->Message);
			return;
		}

		try
		{
			this->WorkwithServer();
		}
		catch (Exception ^e)
		{
			MessageBox::Show(e->Message);
			return;
		}
	}

	private: System::Void Columns_ValueChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (dataGrid->ColumnCount == Convert::ToInt32(Columns->Value))
			return;
		else
			if (dataGrid->ColumnCount < Convert::ToInt32(Columns->Value))
			{
				dataGrid->Columns->Add("1", "");
			}
			else
			{
				dataGrid->Columns->RemoveAt(dataGrid->Columns->Count - 1);
			}

		this->UpdateDataGridView();
	}

	private: System::Void Rows_ValueChanged(System::Object^  sender, System::EventArgs^  e) 
	{
		if (dataGrid->RowCount == Convert::ToInt32(Rows->Value))
			return;
		else
			if (dataGrid->RowCount < Convert::ToInt32(Rows->Value))
			{
				dataGrid->Rows->Add();
			}
			else
			{
				dataGrid->Rows->RemoveAt(dataGrid->Rows->Count - 1);
			}

		this->UpdateDataGridView();
	}

	private: System::Void dataGrid_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		try
		{
			Convert::ToInt32(dataGrid->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
		}
		catch (Exception ^ex)
		{
			dataGrid->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value = "0";
		}
	}

	private: Void UpdateDataGridView()
	{
		int rCount = dataGrid->RowCount;
		int cCount = dataGrid->ColumnCount;
		for (int i = 0; i < rCount; i++)
			for (int j = 0; j < cCount; j++)
			{
				if (Convert::ToString(dataGrid->Rows[i]->Cells[j]->Value) == "")
				{
					dataGrid->Rows[i]->Cells[j]->Value = "0";
				}
			}
	}

	private: Void ChangeDataGridView(array<String^> ^data)
	{
		vector<array<String^>^> ^SplitData = gcnew vector<array<String^>^>(0);
		
		for (int i = 0; i < data->Length; i++)
			SplitData->push_back(data[i]->Split(' '));

		dataGrid->Rows->Clear();
		dataGrid->Columns->Clear();

		int newRowCnt = data->Length, newColCnt = SplitData[0]->Length;

		for (int i = 0; i < newColCnt; i++)
			dataGrid->Columns->Add("1", "");

		int j = 0, i = 0;
		for each (array<String^>^ cols in SplitData)
		{
			dataGrid->Rows->Add();
			for each (String^ str in cols)
			{
				dataGrid->Rows[j]->Cells[i++]->Value = str;
			}
			
			++j;
			i = 0;
		}
		
		this->UpdateDataGridView();
	
		Rows->Value = newRowCnt;
		Columns->Value = newColCnt;
	}

	private: Void WorkwithServer()
	{
		String ^str = "";
		int countCol = Convert::ToInt32(Columns->Value);
		
		for (int i = 0; i < countCol; i++)
			str += dataGrid->Rows[0]->Cells[i]->Value->ToString() + " ";

		client->Write(str + Numtext->Text);		// отправляем в виде "первая строка " + "число N"
		//Threading::Thread::Sleep(300);			// ждем ответа от сервера

		// получаем ответ от сервера
		str = client->Read();
		if (str == "True")
		{
			this->DeleteE(Numtext->Text);
		}
		else
			if (str == "False")
			{
				MessageBox::Show(this->MaxE(Numtext->Text));
			}
			else
				MessageBox::Show("invalid server result");
	}

	private: Void DeleteE(String ^E)
	{
		int rCount = dataGrid->RowCount;
		int cCount = dataGrid->ColumnCount;
		for (int i = 0; i < rCount; i++)
			for (int j = 0; j < cCount; j++)
			{
				if (Convert::ToString(dataGrid->Rows[i]->Cells[j]->Value) == E)
				{
					dataGrid->Rows[i]->Cells[j]->Value = "0";
				}
			}
	}

	private: String^ MaxE(String ^E)
	{
		String ^result = "";
		int iE = Convert::ToInt32(E), counter = 0, save = 0, index = 0;

		int rCount = dataGrid->RowCount;
		int cCount = dataGrid->ColumnCount;
		for (int i = 0; i < rCount; i++)
		{
			counter = 0;
			
			for (int j = 0; j < cCount; j++)
			{
				if (Convert::ToInt32(dataGrid->Rows[i]->Cells[j]->Value) < iE)
				{
					++counter;
				}
			}
			result += Convert::ToString(i) + "str = " + Convert::ToString(counter) + "; ";

			if (save < counter)
			{
				save = counter;
				index = i;
			}
		}

		return result + "\n" + "record: " + Convert::ToString(index) + "str";
	}
};
}
