#pragma once

namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            //
            //TODO: Konstruktorcode hier hinzufügen.
            //
        }

    protected:
        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
    protected:
    private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::Button^  button2;
    private: System::Windows::Forms::Button^  button3;
    private: System::Windows::Forms::Button^  button4;
    private: array<Button^, 2>^ b;
    private: const int size = 20;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Timer^  timer1;
    private:int sec;
    private: System::ComponentModel::IContainer^  components;
    private:
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>


#pragma region Windows Form Designer generated code
        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->flowLayoutPanel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->Controls->Add(this->label1);
            this->flowLayoutPanel1->Location = System::Drawing::Point(13, 13);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(500, 500);
            this->flowLayoutPanel1->TabIndex = 0;
            this->flowLayoutPanel1->WrapContents = false;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(3, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(35, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"label1";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(13, 519);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 37);
            this->button1->TabIndex = 1;
            this->button1->Text = L"Load Board";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
            // 
            // button2
            // 
            this->button2->Enabled = false;
            this->button2->Location = System::Drawing::Point(94, 518);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 38);
            this->button2->TabIndex = 2;
            this->button2->Text = L"Fill with Number";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
            // 
            // button3
            // 
            this->button3->Enabled = false;
            this->button3->Location = System::Drawing::Point(175, 518);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(75, 38);
            this->button3->TabIndex = 3;
            this->button3->Text = L"Fill Board (even)";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
            // 
            // button4
            // 
            this->button4->Location = System::Drawing::Point(256, 518);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(75, 38);
            this->button4->TabIndex = 4;
            this->button4->Text = L"Clear Exit";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
            // 
            // timer1
            // 
            this->timer1->Interval = 1000;
            this->timer1->Tick += gcnew System::EventHandler(this, &Form1::button4_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(531, 589);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button3);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->flowLayoutPanel1);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->flowLayoutPanel1->ResumeLayout(false);
            this->flowLayoutPanel1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
        flowLayoutPanel1->Controls->Clear();
        this->b = gcnew cli::array<Button^, 2>(size, size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
            {
                System::Windows::Forms::Button^ bttnsArray;
                bttnsArray = (gcnew System::Windows::Forms::Button());
                bttnsArray->Width = 25;
                bttnsArray->Height = 25;
                bttnsArray->Margin = System::Windows::Forms::Padding(0);
                b[i, j] = bttnsArray;
                flowLayoutPanel1->Controls->Add(bttnsArray);
                this->b[i, j]->Click += gcnew System::EventHandler(this, &Form1::buttonArray_Click);
            }
        }
        this->button2->Enabled = true;
        this->button3->Enabled = true;

    }
             Void buttonArray_Click(System::Object^ sender, System::EventArgs^ e) {
                 System::Windows::Forms::Button^ buttonArray = gcnew System::Windows::Forms::Button();
                 buttonArray = safe_cast<Button ^>(sender);
                 buttonArray->BackColor = System::Drawing::SystemColors::MenuText; //(black)
             }
    private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
    
             for (int i = 0; i < size; i++)
             {
                 for (int j = 0; j < size; j++)
                 {
                     if ((i + j) % 2 == 0) {
                         this->b[i, j]->Text = System::Convert::ToString("@");

                     }
                     else {
                         this->b[i, j]->Text = System::Convert::ToString("8");
                     }
                 }
             }
    }

    private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if ((i + j) % 2 == 0) {
                    this->b[i, j]->BackColor = System::Drawing::SystemColors::MenuText;
                }
                else {
                    //this->Text = System::Convert::ToString("");
                    this->b[i, j]->BackColor = System::Drawing::SystemColors::ControlLight;
                }
            }
        }
    }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
    
    
    flowLayoutPanel1->Controls->Clear();
       
    this->label1->Text = "Bye!";
    flowLayoutPanel1->Controls->Add(label1);

    this->timer1->Start();
    sec++;

    if (sec == 3) {
        Application::Exit();
    }
}
};
}
