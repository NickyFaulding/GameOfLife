#pragma once

namespace CppCLR_WinformsProjekt {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
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
    private: System::Windows::Forms::Button^  button4;
    private: array<Button^, 2>^ b;
    private: array<int^, 2>^ oldCells;
    private: array<int^, 2>^ newCells;
    private: const int size = 20;
    private: int iterations;
    private: int speed = 1;
    private: System::Windows::Forms::Label^  label1;
    private: System::Windows::Forms::Timer^  timer1;
    private: System::Windows::Forms::Timer^  timer2;
    private:int sec = 0;
    private: System::Windows::Forms::Button^  button5;
    private: System::Windows::Forms::Button^  btnGlider;

    private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Button^  btnMove;
    private: System::Windows::Forms::Button^  btnStartContinue;
    private: System::Windows::Forms::Button^  button9;
    private: System::Windows::Forms::GroupBox^  groupBox1;
    private: System::Windows::Forms::Label^  lblIterations;
    private: System::Windows::Forms::Button^  btnRandGrid;
    private: System::Windows::Forms::Button^  btnTumbler;
    private: System::ComponentModel::IContainer^  components;
    private:


#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->btnGlider = (gcnew System::Windows::Forms::Button());
            this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->btnMove = (gcnew System::Windows::Forms::Button());
            this->btnStartContinue = (gcnew System::Windows::Forms::Button());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->lblIterations = (gcnew System::Windows::Forms::Label());
            this->btnRandGrid = (gcnew System::Windows::Forms::Button());
            this->btnTumbler = (gcnew System::Windows::Forms::Button());
            this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
            this->flowLayoutPanel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
            this->groupBox1->SuspendLayout();
            this->SuspendLayout();
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->Controls->Add(this->label1);
            this->flowLayoutPanel1->Location = System::Drawing::Point(13, 13);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(500, 500);
            this->flowLayoutPanel1->TabIndex = 0;
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
            // button4
            // 
            this->button4->Location = System::Drawing::Point(447, 602);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(75, 34);
            this->button4->TabIndex = 4;
            this->button4->Text = L"Clear Exit";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
            // 
            // timer1
            // 
            this->timer1->Interval = 1000;
            this->timer1->Tick += gcnew System::EventHandler(this, &Form1::btnStartContinue_Click);
            // 
            // button5
            // 
            this->button5->Enabled = false;
            this->button5->Location = System::Drawing::Point(13, 562);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(75, 34);
            this->button5->TabIndex = 5;
            this->button5->Text = L"10 row";
            this->button5->UseVisualStyleBackColor = true;
            this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
            // 
            // btnGlider
            // 
            this->btnGlider->Enabled = false;
            this->btnGlider->Location = System::Drawing::Point(12, 602);
            this->btnGlider->Name = L"btnGlider";
            this->btnGlider->Size = System::Drawing::Size(75, 34);
            this->btnGlider->TabIndex = 6;
            this->btnGlider->Text = L"Glider";
            this->btnGlider->UseVisualStyleBackColor = true;
            this->btnGlider->Click += gcnew System::EventHandler(this, &Form1::btnGlider_Click);
            // 
            // numericUpDown1
            // 
            this->numericUpDown1->Location = System::Drawing::Point(290, 552);
            this->numericUpDown1->Name = L"numericUpDown1";
            this->numericUpDown1->Size = System::Drawing::Size(37, 20);
            this->numericUpDown1->TabIndex = 7;
            this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(213, 554);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(71, 13);
            this->label2->TabIndex = 8;
            this->label2->Text = L"Select Speed";
            // 
            // btnMove
            // 
            this->btnMove->Enabled = false;
            this->btnMove->Location = System::Drawing::Point(184, 602);
            this->btnMove->Name = L"btnMove";
            this->btnMove->Size = System::Drawing::Size(75, 34);
            this->btnMove->TabIndex = 9;
            this->btnMove->Text = L"Move";
            this->btnMove->UseVisualStyleBackColor = true;
            this->btnMove->Click += gcnew System::EventHandler(this, &Form1::btnMove_Click);
            // 
            // btnStartContinue
            // 
            this->btnStartContinue->Enabled = false;
            this->btnStartContinue->Location = System::Drawing::Point(265, 602);
            this->btnStartContinue->Name = L"btnStartContinue";
            this->btnStartContinue->Size = System::Drawing::Size(95, 34);
            this->btnStartContinue->TabIndex = 10;
            this->btnStartContinue->Text = L"Start/Continue";
            this->btnStartContinue->UseVisualStyleBackColor = true;
            this->btnStartContinue->Click += gcnew System::EventHandler(this, &Form1::btnStartContinue_Click);
            // 
            // button9
            // 
            this->button9->Enabled = false;
            this->button9->Location = System::Drawing::Point(366, 602);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(75, 34);
            this->button9->TabIndex = 11;
            this->button9->Text = L"Stop";
            this->button9->UseVisualStyleBackColor = true;
            this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->lblIterations);
            this->groupBox1->Location = System::Drawing::Point(333, 519);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(186, 77);
            this->groupBox1->TabIndex = 12;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Iterations";
            // 
            // lblIterations
            // 
            this->lblIterations->AutoSize = true;
            this->lblIterations->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblIterations->Location = System::Drawing::Point(76, 28);
            this->lblIterations->Name = L"lblIterations";
            this->lblIterations->Size = System::Drawing::Size(23, 25);
            this->lblIterations->TabIndex = 0;
            this->lblIterations->Text = L"0";
            // 
            // btnRandGrid
            // 
            this->btnRandGrid->Enabled = false;
            this->btnRandGrid->Location = System::Drawing::Point(94, 562);
            this->btnRandGrid->Name = L"btnRandGrid";
            this->btnRandGrid->Size = System::Drawing::Size(75, 34);
            this->btnRandGrid->TabIndex = 13;
            this->btnRandGrid->Text = L"Random Grid";
            this->btnRandGrid->UseVisualStyleBackColor = true;
            this->btnRandGrid->Click += gcnew System::EventHandler(this, &Form1::btnRandGrid_Click);
            // 
            // btnTumbler
            // 
            this->btnTumbler->Enabled = false;
            this->btnTumbler->Location = System::Drawing::Point(93, 602);
            this->btnTumbler->Name = L"btnTumbler";
            this->btnTumbler->Size = System::Drawing::Size(75, 34);
            this->btnTumbler->TabIndex = 14;
            this->btnTumbler->Text = L"Tumbler";
            this->btnTumbler->UseVisualStyleBackColor = true;
            this->btnTumbler->Click += gcnew System::EventHandler(this, &Form1::btnTumbler_Click);
            // 
            // timer2
            // 
            this->timer2->Interval = 1000;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(531, 642);
            this->Controls->Add(this->btnTumbler);
            this->Controls->Add(this->btnRandGrid);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->button9);
            this->Controls->Add(this->btnStartContinue);
            this->Controls->Add(this->btnMove);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->numericUpDown1);
            this->Controls->Add(this->btnGlider);
            this->Controls->Add(this->button5);
            this->Controls->Add(this->button4);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->flowLayoutPanel1);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->flowLayoutPanel1->ResumeLayout(false);
            this->flowLayoutPanel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
        flowLayoutPanel1->Controls->Clear();
        this->b = gcnew cli::array<Button^, 2>(size, size); //creating array of buttons
        this->oldCells = gcnew cli::array<int^, 2>(size, size); //creating array to contain the current state of the cells
        this->newCells = gcnew cli::array<int^, 2>(size, size); //creating array to contain the new state of the cells
        this->iterations = 0; // initialise the itteration count when we reset the board.
        this->timer1->Interval = 1000;


        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
            {
                System::Windows::Forms::Button^ bttnsArray;
                bttnsArray = (gcnew System::Windows::Forms::Button());
                bttnsArray->Width = 25;
                bttnsArray->Height = 25;
                bttnsArray->Margin = System::Windows::Forms::Padding(0);
                bttnsArray->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
                bttnsArray->FlatAppearance->BorderSize = 0.5;
                b[i, j] = bttnsArray;
                flowLayoutPanel1->Controls->Add(bttnsArray);
                this->b[i, j]->Click += gcnew System::EventHandler(this, &Form1::buttonArray_Click);
            }
        }
        this->button5->Enabled = true;
        this->btnGlider->Enabled = true;
        this->btnMove->Enabled = true;
        this->btnRandGrid->Enabled = true;
        this->btnStartContinue->Enabled = true;
        this->button9->Enabled = true;
        this->btnTumbler->Enabled = true;

        ClearGrid();

    }

    Void buttonArray_Click(System::Object^ sender, System::EventArgs^ e) {  //button clicker
        System::Windows::Forms::Button^ buttonArray = gcnew System::Windows::Forms::Button();
        buttonArray = safe_cast<Button ^>(sender);
        if (buttonArray->BackColor == System::Drawing::SystemColors::ControlDarkDark) {
            buttonArray->BackColor = System::Drawing::SystemColors::ControlLight; //white
        }
        else {
            buttonArray->BackColor = System::Drawing::SystemColors::ControlDarkDark; //(black)
        }
    }

    private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {


        flowLayoutPanel1->Controls->Clear();

        this->label1->Text = "Bye!";
        flowLayoutPanel1->Controls->Add(label1);        

        this->timer2->Start();

        sec++;

        if (sec == 3) {
            Application::Exit();
        }
    }

    Void CheckCells() {

        CopyOldGrid();

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int HowManyNeighbours = 0;

                HowManyNeighbours = CheckNeighbours(i, j);
                CheckRules(i, j, HowManyNeighbours);
            }
        }

        DisplayNewGrid();
    }

    Void CopyOldGrid() { //makes a copy of the current grid and stores the cells as 1 or 0 depending on if they are alive or not
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {

                if (b[i, j]->BackColor == System::Drawing::SystemColors::ControlDarkDark) {
                    oldCells[i, j] = 1;
                }
                else {
                    oldCells[i, j] = 0;
                }

                newCells[i, j] = 0;
            }
        }
    }

    int CheckNeighbours(int i, int j)
    {
        int count = 0;

        for (int x = -1; x < 2; x++) {
            for (int y = -1; y < 2; y++) {
                if (b[(x + i + size) % size, (y + j + size) % size]->BackColor == System::Drawing::SystemColors::ControlDarkDark)  //wrap around edges  (0 - 1 + 20) % 20 = 19
                {
                    count++;
                }
            }
        }

        if (b[i, j]->BackColor == System::Drawing::SystemColors::ControlDarkDark) //remove the current cell from the count if it's alive
        {
            count -= 1;
        }

        return count;
    }

    Void CheckRules(int i, int j, int howManyNeighbours) {

        int HowManyNeighbours = howManyNeighbours;

        if((int)oldCells[i,j] == 0 && HowManyNeighbours == 3) //rule 1 : reproduction
        {
            newCells[i, j] = 1;//cell live
        }
        else if ((int)oldCells[i,j] == 1 && (HowManyNeighbours < 2 || HowManyNeighbours > 3)) //rule 2 and rule 3 : underpopulation & overcrowding
        {
            newCells[i, j] = 0;//cell dead

        }
        else if ((int)oldCells[i,j] == 1 && (HowManyNeighbours == 2 || HowManyNeighbours == 3)) //rule 4 : healthy cell
        {
            newCells[i, j] = oldCells[i, j];
            //do nothing cell, cell gets to keep living.
        }
    }

    Void ApplyNewGrid(int i, int j) {

        if ((int)newCells[i, j] == 1) {
            b[i,j]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        }
        else {
            b[i, j]->BackColor = System::Drawing::SystemColors::ControlLight;
        }
    }

    Void DisplayNewGrid() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                ApplyNewGrid(i, j);
            }
        }
    }

    Void ClearGrid() {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                this->b[i, j]->BackColor = System::Drawing::SystemColors::ControlLight;

            }
        }

        iterations = 0;
        lblIterations->Text = iterations.ToString();
    }

    Void Glider() {
        //small exploder pattern within the grid

        b[8, 10]->BackColor = System::Drawing::SystemColors::ControlDarkDark;

        b[9, 10]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[9, 11]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[9, 9]->BackColor = System::Drawing::SystemColors::ControlDarkDark;

        b[10, 11]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[10, 9]->BackColor = System::Drawing::SystemColors::ControlDarkDark;

        b[11, 10]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
    }

    Void Tumbler() {
        //cool looping patern

        b[5, 7]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[6, 7]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[5, 8]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[6, 8]->BackColor = System::Drawing::SystemColors::ControlDarkDark;

        b[7, 8]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[8, 8]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[9, 8]->BackColor = System::Drawing::SystemColors::ControlDarkDark;

        b[10, 7]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[10, 6]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[9, 6]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[8, 6]->BackColor = System::Drawing::SystemColors::ControlDarkDark;

        b[5, 10]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[6, 10]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[5, 11]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[6, 11]->BackColor = System::Drawing::SystemColors::ControlDarkDark;

        b[7, 10]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[8, 10]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[9, 10]->BackColor = System::Drawing::SystemColors::ControlDarkDark;

        b[10, 11]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[10, 12]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[9, 12]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
        b[8, 12]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
    }

    Void TenRow() {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if ((i == 10) && (j < 15 && j >= 5)) {
                    this->b[i, j]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
                }
            }
        }
    }

    private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
        ClearGrid();
        TenRow();
    }

    private: System::Void btnGlider_Click(System::Object^  sender, System::EventArgs^  e) {
        ClearGrid();
        Glider();
    }

    private: System::Void btnMove_Click(System::Object^  sender, System::EventArgs^  e) {
        Move();
    }
    
    Void Move() {
        CheckCells();
        iterations++;
        lblIterations->Text = iterations.ToString();
    }

    private: System::Void btnStartContinue_Click(System::Object^  sender, System::EventArgs^  e) { //hooked up to the timer ticker, runs every tick once btn is clicked

        speed = (int) numericUpDown1->Value;

        timer1->Interval = (1000 / speed) ;
        timer1->Enabled = true;
        Move();
    }

    private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) { //stops timer
        timer1->Enabled = false;
        
    }

    private: System::Void btnRandGrid_Click(System::Object^  sender, System::EventArgs^  e) { //fills all spaces randomly

        int randomNum;
        Random rand;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                randomNum = rand.Next(2);

                if (randomNum == 1) {
                    b[i, j]->BackColor = System::Drawing::SystemColors::ControlDarkDark;
                }
                else {
                    b[i, j]->BackColor = System::Drawing::SystemColors::ControlLight;
                }
            }
        }

    }

    private: System::Void btnTumbler_Click(System::Object^  sender, System::EventArgs^  e) {
        ClearGrid();
        Tumbler();
    }
};
}