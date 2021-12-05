#pragma once
#include "Controller.h"

namespace S9Ejercicio1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			c = new Controller();
			g = panel1->CreateGraphics();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: 
		Controller* c;
		Graphics^ g;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnDibujar;
	private: System::Windows::Forms::ComboBox^ cbElegirFigura;
	private: System::Windows::Forms::Label^ label_ElegirFigura;
	private: System::Windows::Forms::GroupBox^ gbPosicionInicial;


	private: System::Windows::Forms::GroupBox^ gbElipse;
	private: System::Windows::Forms::GroupBox^ gbRectangulo;
	private: System::Windows::Forms::Label^ label_posicionY;
	private: System::Windows::Forms::Label^ label_posicionX;
	private: System::Windows::Forms::Label^ label_radio;
	private: System::Windows::Forms::Label^ label_areaE;

	private: System::Windows::Forms::Label^ label_lado2;
	private: System::Windows::Forms::Label^ label_lado1;
	private: System::Windows::Forms::TextBox^ tb_posicionY;
	private: System::Windows::Forms::TextBox^ tb_posicionX;
	private: System::Windows::Forms::TextBox^ tbRadio;
	private: System::Windows::Forms::Label^ label_areaR;
	private: System::Windows::Forms::TextBox^ tbLado2;
	private: System::Windows::Forms::TextBox^ tbLado1;
	private: System::Windows::Forms::Label^ label_mostrarAreaE;
	private: System::Windows::Forms::Label^ label_mostrarAreaR;
	private: System::Windows::Forms::FlowLayoutPanel^ panel1;
	private: System::Windows::Forms::GroupBox^ gbColor;
	private: System::Windows::Forms::Label^ label_Azul;

	private: System::Windows::Forms::Label^ label_Verde;

	private: System::Windows::Forms::Label^ label_Rojo;
	private: System::Windows::Forms::TextBox^ tbAzul;

	private: System::Windows::Forms::TextBox^ tbVerde;

	private: System::Windows::Forms::TextBox^ tbRojo;
	private: System::Windows::Forms::TextBox^ tbRadio2;
	private: System::Windows::Forms::Label^ label_radio2;
	private: System::Windows::Forms::GroupBox^ gbLinea;
	private: System::Windows::Forms::TextBox^ tbPuntoFinal;
	private: System::Windows::Forms::TextBox^ tbPuntoInicial;
	private: System::Windows::Forms::Label^ label_PuntoFinal;
	private: System::Windows::Forms::Label^ lable_PuntoInicial;




	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnDibujar = (gcnew System::Windows::Forms::Button());
			this->cbElegirFigura = (gcnew System::Windows::Forms::ComboBox());
			this->label_ElegirFigura = (gcnew System::Windows::Forms::Label());
			this->gbPosicionInicial = (gcnew System::Windows::Forms::GroupBox());
			this->tb_posicionY = (gcnew System::Windows::Forms::TextBox());
			this->tb_posicionX = (gcnew System::Windows::Forms::TextBox());
			this->label_posicionY = (gcnew System::Windows::Forms::Label());
			this->label_posicionX = (gcnew System::Windows::Forms::Label());
			this->gbElipse = (gcnew System::Windows::Forms::GroupBox());
			this->tbRadio2 = (gcnew System::Windows::Forms::TextBox());
			this->label_radio2 = (gcnew System::Windows::Forms::Label());
			this->label_mostrarAreaE = (gcnew System::Windows::Forms::Label());
			this->tbRadio = (gcnew System::Windows::Forms::TextBox());
			this->label_radio = (gcnew System::Windows::Forms::Label());
			this->label_areaE = (gcnew System::Windows::Forms::Label());
			this->gbRectangulo = (gcnew System::Windows::Forms::GroupBox());
			this->label_mostrarAreaR = (gcnew System::Windows::Forms::Label());
			this->label_areaR = (gcnew System::Windows::Forms::Label());
			this->tbLado2 = (gcnew System::Windows::Forms::TextBox());
			this->tbLado1 = (gcnew System::Windows::Forms::TextBox());
			this->label_lado2 = (gcnew System::Windows::Forms::Label());
			this->label_lado1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->gbColor = (gcnew System::Windows::Forms::GroupBox());
			this->tbAzul = (gcnew System::Windows::Forms::TextBox());
			this->tbVerde = (gcnew System::Windows::Forms::TextBox());
			this->tbRojo = (gcnew System::Windows::Forms::TextBox());
			this->label_Azul = (gcnew System::Windows::Forms::Label());
			this->label_Verde = (gcnew System::Windows::Forms::Label());
			this->label_Rojo = (gcnew System::Windows::Forms::Label());
			this->gbLinea = (gcnew System::Windows::Forms::GroupBox());
			this->tbPuntoFinal = (gcnew System::Windows::Forms::TextBox());
			this->tbPuntoInicial = (gcnew System::Windows::Forms::TextBox());
			this->label_PuntoFinal = (gcnew System::Windows::Forms::Label());
			this->lable_PuntoInicial = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->gbPosicionInicial->SuspendLayout();
			this->gbElipse->SuspendLayout();
			this->gbRectangulo->SuspendLayout();
			this->gbColor->SuspendLayout();
			this->gbLinea->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnDibujar);
			this->groupBox1->Controls->Add(this->cbElegirFigura);
			this->groupBox1->Controls->Add(this->label_ElegirFigura);
			this->groupBox1->Location = System::Drawing::Point(26, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1095, 58);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// btnDibujar
			// 
			this->btnDibujar->BackColor = System::Drawing::Color::Silver;
			this->btnDibujar->Location = System::Drawing::Point(346, 19);
			this->btnDibujar->Name = L"btnDibujar";
			this->btnDibujar->Size = System::Drawing::Size(715, 23);
			this->btnDibujar->TabIndex = 2;
			this->btnDibujar->Text = L"Dibujar";
			this->btnDibujar->UseVisualStyleBackColor = false;
			this->btnDibujar->Click += gcnew System::EventHandler(this, &MyForm::btnDibujar_Click);
			// 
			// cbElegirFigura
			// 
			this->cbElegirFigura->FormattingEnabled = true;
			this->cbElegirFigura->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Elipse", L"Rectangulo", L"Circulo", L"Cuadrado",
					L"Linea"
			});
			this->cbElegirFigura->Location = System::Drawing::Point(125, 22);
			this->cbElegirFigura->Name = L"cbElegirFigura";
			this->cbElegirFigura->Size = System::Drawing::Size(121, 24);
			this->cbElegirFigura->TabIndex = 1;
			this->cbElegirFigura->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cbElegirFigura_SelectedIndexChanged);
			// 
			// label_ElegirFigura
			// 
			this->label_ElegirFigura->AutoSize = true;
			this->label_ElegirFigura->Location = System::Drawing::Point(21, 22);
			this->label_ElegirFigura->Name = L"label_ElegirFigura";
			this->label_ElegirFigura->Size = System::Drawing::Size(88, 17);
			this->label_ElegirFigura->TabIndex = 0;
			this->label_ElegirFigura->Text = L"Elegir Figura";
			// 
			// gbPosicionInicial
			// 
			this->gbPosicionInicial->Controls->Add(this->tb_posicionY);
			this->gbPosicionInicial->Controls->Add(this->tb_posicionX);
			this->gbPosicionInicial->Controls->Add(this->label_posicionY);
			this->gbPosicionInicial->Controls->Add(this->label_posicionX);
			this->gbPosicionInicial->Enabled = false;
			this->gbPosicionInicial->Location = System::Drawing::Point(26, 77);
			this->gbPosicionInicial->Name = L"gbPosicionInicial";
			this->gbPosicionInicial->Size = System::Drawing::Size(246, 188);
			this->gbPosicionInicial->TabIndex = 1;
			this->gbPosicionInicial->TabStop = false;
			this->gbPosicionInicial->Text = L"Posicion Inicial";
			// 
			// tb_posicionY
			// 
			this->tb_posicionY->Location = System::Drawing::Point(125, 103);
			this->tb_posicionY->Name = L"tb_posicionY";
			this->tb_posicionY->Size = System::Drawing::Size(100, 22);
			this->tb_posicionY->TabIndex = 3;
			// 
			// tb_posicionX
			// 
			this->tb_posicionX->Location = System::Drawing::Point(125, 53);
			this->tb_posicionX->Name = L"tb_posicionX";
			this->tb_posicionX->Size = System::Drawing::Size(100, 22);
			this->tb_posicionX->TabIndex = 2;
			// 
			// label_posicionY
			// 
			this->label_posicionY->AutoSize = true;
			this->label_posicionY->Location = System::Drawing::Point(21, 103);
			this->label_posicionY->Name = L"label_posicionY";
			this->label_posicionY->Size = System::Drawing::Size(94, 17);
			this->label_posicionY->TabIndex = 1;
			this->label_posicionY->Text = L"Posicion en Y";
			// 
			// label_posicionX
			// 
			this->label_posicionX->AutoSize = true;
			this->label_posicionX->Location = System::Drawing::Point(21, 53);
			this->label_posicionX->Name = L"label_posicionX";
			this->label_posicionX->Size = System::Drawing::Size(94, 17);
			this->label_posicionX->TabIndex = 0;
			this->label_posicionX->Text = L"Posicion en X";
			// 
			// gbElipse
			// 
			this->gbElipse->Controls->Add(this->tbRadio2);
			this->gbElipse->Controls->Add(this->label_radio2);
			this->gbElipse->Controls->Add(this->label_mostrarAreaE);
			this->gbElipse->Controls->Add(this->tbRadio);
			this->gbElipse->Controls->Add(this->label_radio);
			this->gbElipse->Controls->Add(this->label_areaE);
			this->gbElipse->Enabled = false;
			this->gbElipse->Location = System::Drawing::Point(445, 77);
			this->gbElipse->Name = L"gbElipse";
			this->gbElipse->Size = System::Drawing::Size(230, 188);
			this->gbElipse->TabIndex = 2;
			this->gbElipse->TabStop = false;
			this->gbElipse->Text = L"Elipse";
			// 
			// tbRadio2
			// 
			this->tbRadio2->Location = System::Drawing::Point(80, 108);
			this->tbRadio2->Name = L"tbRadio2";
			this->tbRadio2->Size = System::Drawing::Size(96, 22);
			this->tbRadio2->TabIndex = 7;
			// 
			// label_radio2
			// 
			this->label_radio2->AutoSize = true;
			this->label_radio2->Location = System::Drawing::Point(17, 108);
			this->label_radio2->Name = L"label_radio2";
			this->label_radio2->Size = System::Drawing::Size(57, 17);
			this->label_radio2->TabIndex = 6;
			this->label_radio2->Text = L"Radio 2";
			// 
			// label_mostrarAreaE
			// 
			this->label_mostrarAreaE->AutoSize = true;
			this->label_mostrarAreaE->Location = System::Drawing::Point(77, 152);
			this->label_mostrarAreaE->Name = L"label_mostrarAreaE";
			this->label_mostrarAreaE->Size = System::Drawing::Size(135, 17);
			this->label_mostrarAreaE->TabIndex = 5;
			this->label_mostrarAreaE->Text = L"Mostrar aqui el area";
			// 
			// tbRadio
			// 
			this->tbRadio->Location = System::Drawing::Point(81, 53);
			this->tbRadio->Name = L"tbRadio";
			this->tbRadio->Size = System::Drawing::Size(100, 22);
			this->tbRadio->TabIndex = 4;
			// 
			// label_radio
			// 
			this->label_radio->AutoSize = true;
			this->label_radio->Location = System::Drawing::Point(15, 53);
			this->label_radio->Name = L"label_radio";
			this->label_radio->Size = System::Drawing::Size(57, 17);
			this->label_radio->TabIndex = 3;
			this->label_radio->Text = L"Radio 1";
			// 
			// label_areaE
			// 
			this->label_areaE->AutoSize = true;
			this->label_areaE->Location = System::Drawing::Point(17, 152);
			this->label_areaE->Name = L"label_areaE";
			this->label_areaE->Size = System::Drawing::Size(38, 17);
			this->label_areaE->TabIndex = 2;
			this->label_areaE->Text = L"Area";
			// 
			// gbRectangulo
			// 
			this->gbRectangulo->Controls->Add(this->label_mostrarAreaR);
			this->gbRectangulo->Controls->Add(this->label_areaR);
			this->gbRectangulo->Controls->Add(this->tbLado2);
			this->gbRectangulo->Controls->Add(this->tbLado1);
			this->gbRectangulo->Controls->Add(this->label_lado2);
			this->gbRectangulo->Controls->Add(this->label_lado1);
			this->gbRectangulo->Enabled = false;
			this->gbRectangulo->Location = System::Drawing::Point(681, 77);
			this->gbRectangulo->Name = L"gbRectangulo";
			this->gbRectangulo->Size = System::Drawing::Size(236, 188);
			this->gbRectangulo->TabIndex = 3;
			this->gbRectangulo->TabStop = false;
			this->gbRectangulo->Text = L"Rectangulo";
			// 
			// label_mostrarAreaR
			// 
			this->label_mostrarAreaR->AutoSize = true;
			this->label_mostrarAreaR->Location = System::Drawing::Point(88, 155);
			this->label_mostrarAreaR->Name = L"label_mostrarAreaR";
			this->label_mostrarAreaR->Size = System::Drawing::Size(130, 17);
			this->label_mostrarAreaR->TabIndex = 7;
			this->label_mostrarAreaR->Text = L"Mostar aqui el area";
			// 
			// label_areaR
			// 
			this->label_areaR->AutoSize = true;
			this->label_areaR->Location = System::Drawing::Point(24, 155);
			this->label_areaR->Name = L"label_areaR";
			this->label_areaR->Size = System::Drawing::Size(38, 17);
			this->label_areaR->TabIndex = 5;
			this->label_areaR->Text = L"Area";
			// 
			// tbLado2
			// 
			this->tbLado2->Location = System::Drawing::Point(91, 106);
			this->tbLado2->Name = L"tbLado2";
			this->tbLado2->Size = System::Drawing::Size(100, 22);
			this->tbLado2->TabIndex = 6;
			// 
			// tbLado1
			// 
			this->tbLado1->Location = System::Drawing::Point(91, 53);
			this->tbLado1->Name = L"tbLado1";
			this->tbLado1->Size = System::Drawing::Size(100, 22);
			this->tbLado1->TabIndex = 5;
			// 
			// label_lado2
			// 
			this->label_lado2->AutoSize = true;
			this->label_lado2->Location = System::Drawing::Point(24, 108);
			this->label_lado2->Name = L"label_lado2";
			this->label_lado2->Size = System::Drawing::Size(52, 17);
			this->label_lado2->TabIndex = 3;
			this->label_lado2->Text = L"Lado 2";
			// 
			// label_lado1
			// 
			this->label_lado1->AutoSize = true;
			this->label_lado1->Location = System::Drawing::Point(24, 53);
			this->label_lado1->Name = L"label_lado1";
			this->label_lado1->Size = System::Drawing::Size(52, 17);
			this->label_lado1->TabIndex = 2;
			this->label_lado1->Text = L"Lado 1";
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(26, 290);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1095, 362);
			this->panel1->TabIndex = 4;
			// 
			// gbColor
			// 
			this->gbColor->Controls->Add(this->tbAzul);
			this->gbColor->Controls->Add(this->tbVerde);
			this->gbColor->Controls->Add(this->tbRojo);
			this->gbColor->Controls->Add(this->label_Azul);
			this->gbColor->Controls->Add(this->label_Verde);
			this->gbColor->Controls->Add(this->label_Rojo);
			this->gbColor->Enabled = false;
			this->gbColor->Location = System::Drawing::Point(278, 77);
			this->gbColor->Name = L"gbColor";
			this->gbColor->Size = System::Drawing::Size(161, 188);
			this->gbColor->TabIndex = 5;
			this->gbColor->TabStop = false;
			this->gbColor->Text = L"Color";
			// 
			// tbAzul
			// 
			this->tbAzul->Location = System::Drawing::Point(74, 152);
			this->tbAzul->Name = L"tbAzul";
			this->tbAzul->Size = System::Drawing::Size(66, 22);
			this->tbAzul->TabIndex = 5;
			this->tbAzul->TextChanged += gcnew System::EventHandler(this, &MyForm::tbAzul_TextChanged);
			// 
			// tbVerde
			// 
			this->tbVerde->Location = System::Drawing::Point(74, 106);
			this->tbVerde->Name = L"tbVerde";
			this->tbVerde->Size = System::Drawing::Size(66, 22);
			this->tbVerde->TabIndex = 4;
			this->tbVerde->TextChanged += gcnew System::EventHandler(this, &MyForm::tbVerde_TextChanged);
			// 
			// tbRojo
			// 
			this->tbRojo->Location = System::Drawing::Point(74, 53);
			this->tbRojo->Name = L"tbRojo";
			this->tbRojo->Size = System::Drawing::Size(66, 22);
			this->tbRojo->TabIndex = 3;
			this->tbRojo->TextChanged += gcnew System::EventHandler(this, &MyForm::tbRojo_TextChanged);
			// 
			// label_Azul
			// 
			this->label_Azul->AutoSize = true;
			this->label_Azul->Location = System::Drawing::Point(17, 155);
			this->label_Azul->Name = L"label_Azul";
			this->label_Azul->Size = System::Drawing::Size(35, 17);
			this->label_Azul->TabIndex = 2;
			this->label_Azul->Text = L"Azul";
			// 
			// label_Verde
			// 
			this->label_Verde->AutoSize = true;
			this->label_Verde->Location = System::Drawing::Point(15, 108);
			this->label_Verde->Name = L"label_Verde";
			this->label_Verde->Size = System::Drawing::Size(46, 17);
			this->label_Verde->TabIndex = 1;
			this->label_Verde->Text = L"Verde";
			// 
			// label_Rojo
			// 
			this->label_Rojo->AutoSize = true;
			this->label_Rojo->Location = System::Drawing::Point(15, 53);
			this->label_Rojo->Name = L"label_Rojo";
			this->label_Rojo->Size = System::Drawing::Size(37, 17);
			this->label_Rojo->TabIndex = 0;
			this->label_Rojo->Text = L"Rojo";
			// 
			// gbLinea
			// 
			this->gbLinea->Controls->Add(this->tbPuntoFinal);
			this->gbLinea->Controls->Add(this->tbPuntoInicial);
			this->gbLinea->Controls->Add(this->label_PuntoFinal);
			this->gbLinea->Controls->Add(this->lable_PuntoInicial);
			this->gbLinea->Enabled = false;
			this->gbLinea->Location = System::Drawing::Point(923, 77);
			this->gbLinea->Name = L"gbLinea";
			this->gbLinea->Size = System::Drawing::Size(198, 188);
			this->gbLinea->TabIndex = 8;
			this->gbLinea->TabStop = false;
			this->gbLinea->Text = L"Linea";
			// 
			// tbPuntoFinal
			// 
			this->tbPuntoFinal->Location = System::Drawing::Point(91, 106);
			this->tbPuntoFinal->Name = L"tbPuntoFinal";
			this->tbPuntoFinal->Size = System::Drawing::Size(85, 22);
			this->tbPuntoFinal->TabIndex = 6;
			// 
			// tbPuntoInicial
			// 
			this->tbPuntoInicial->Location = System::Drawing::Point(91, 53);
			this->tbPuntoInicial->Name = L"tbPuntoInicial";
			this->tbPuntoInicial->Size = System::Drawing::Size(85, 22);
			this->tbPuntoInicial->TabIndex = 5;
			// 
			// label_PuntoFinal
			// 
			this->label_PuntoFinal->AutoSize = true;
			this->label_PuntoFinal->Location = System::Drawing::Point(24, 108);
			this->label_PuntoFinal->Name = L"label_PuntoFinal";
			this->label_PuntoFinal->Size = System::Drawing::Size(57, 17);
			this->label_PuntoFinal->TabIndex = 3;
			this->label_PuntoFinal->Text = L"Punto 2";
			// 
			// lable_PuntoInicial
			// 
			this->lable_PuntoInicial->AutoSize = true;
			this->lable_PuntoInicial->Location = System::Drawing::Point(24, 53);
			this->lable_PuntoInicial->Name = L"lable_PuntoInicial";
			this->lable_PuntoInicial->Size = System::Drawing::Size(57, 17);
			this->lable_PuntoInicial->TabIndex = 2;
			this->lable_PuntoInicial->Text = L"Punto 1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1156, 677);
			this->Controls->Add(this->gbLinea);
			this->Controls->Add(this->gbRectangulo);
			this->Controls->Add(this->gbElipse);
			this->Controls->Add(this->gbColor);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->gbPosicionInicial);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->gbPosicionInicial->ResumeLayout(false);
			this->gbPosicionInicial->PerformLayout();
			this->gbElipse->ResumeLayout(false);
			this->gbElipse->PerformLayout();
			this->gbRectangulo->ResumeLayout(false);
			this->gbRectangulo->PerformLayout();
			this->gbColor->ResumeLayout(false);
			this->gbColor->PerformLayout();
			this->gbLinea->ResumeLayout(false);
			this->gbLinea->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void cbElegirFigura_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (cbElegirFigura->SelectedItem == "Circulo" || cbElegirFigura->SelectedItem == "Elipse") {
			gbPosicionInicial->Enabled = true;
			gbColor->Enabled = true;
			gbElipse->Enabled = true;
			gbLinea->Enabled = false;
			gbRectangulo->Enabled = false;
			label_mostrarAreaE->Text = "Mostrar aqui el area";
			label_mostrarAreaR->Text = "Mostrar aqui el area";
		}

		if (cbElegirFigura->SelectedItem == "Rectangulo" || cbElegirFigura->SelectedItem == "Cuadrado") {
			gbPosicionInicial->Enabled = true;
			gbColor->Enabled = true;
			gbRectangulo->Enabled = true;
			gbElipse->Enabled = false;
			gbLinea->Enabled = false;
			label_mostrarAreaE->Text = "Mostrar aqui el area";
			label_mostrarAreaR->Text = "Mostrar aqui el area";
		}

		if (cbElegirFigura->SelectedItem == "Linea") {
			gbPosicionInicial->Enabled = true;
			gbColor->Enabled = true;
			gbLinea->Enabled = true;
			gbElipse->Enabled = false;
			gbRectangulo->Enabled = false;
			label_mostrarAreaE->Text = "Mostrar aqui el area";
			label_mostrarAreaR->Text = "Mostrar aqui el area";
		}
	}
	
private: System::Void btnDibujar_Click(System::Object^ sender, System::EventArgs^ e) {
	if (cbElegirFigura->SelectedItem == "Circulo" || cbElegirFigura->SelectedItem == "Elipse") {
		Elipse* e = new Elipse(Convert::ToInt32(tb_posicionX->Text), Convert::ToInt32(tb_posicionY->Text), Convert::ToInt32(tbRadio->Text), Convert::ToInt32(tbRadio2->Text));
		c->addElipse(e);
		label_mostrarAreaE->Text = Convert::ToString(e->getArea());
	}

	if (cbElegirFigura->SelectedItem == "Rectangulo" || cbElegirFigura->SelectedItem == "Cuadrado") {
		CRectangulo* r = new CRectangulo(Convert::ToInt32(tb_posicionX->Text), Convert::ToInt32(tb_posicionY->Text), Convert::ToInt32(tbLado1->Text), Convert::ToInt32(tbLado2->Text));
		c->addCRectangulo(r);
		label_mostrarAreaR->Text = Convert::ToString(r->getArea());
	}

	if (cbElegirFigura->SelectedItem == "Linea") {
		Linea* l = new Linea(Convert::ToInt32(tb_posicionX->Text), Convert::ToInt32(tb_posicionY->Text), Convert::ToInt32(tbPuntoInicial->Text), Convert::ToInt32(tbPuntoFinal->Text));
		c->addLinea(l);
	}

	g->Clear(Color::White);

	Color color = Color::FromArgb(Convert::ToInt32(tbRojo->Text), Convert::ToInt32(tbVerde->Text), Convert::ToInt32(tbAzul->Text));
	c->drawEverything(g, color);
}

private: System::Void tbRojo_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (tbRojo->Text != "" && tbVerde->Text != "" && tbAzul->Text != "") {
		btnDibujar->BackColor = Color::FromArgb(Convert::ToInt32(tbRojo->Text), Convert::ToInt32(tbVerde->Text), Convert::ToInt32(tbAzul->Text));
	}
}

private: System::Void tbVerde_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (tbRojo->Text != "" && tbVerde->Text != "" && tbAzul->Text != "") {
		btnDibujar->BackColor = Color::FromArgb(Convert::ToInt32(tbRojo->Text), Convert::ToInt32(tbVerde->Text), Convert::ToInt32(tbAzul->Text));
	}
}

private: System::Void tbAzul_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (tbRojo->Text != "" && tbVerde->Text != "" && tbAzul->Text != "") {
		btnDibujar->BackColor = Color::FromArgb(Convert::ToInt32(tbRojo->Text), Convert::ToInt32(tbVerde->Text), Convert::ToInt32(tbAzul->Text));
	}
}

};
}
