#pragma once
#include <conio.h>
#include <iostream>
#include <ctime>
#include "time.h"
#include "Juego.h"

using namespace std;

namespace Ejercicio3PC2 {

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
	private:
		Juego* j;
		int ncarreras, contador; 
		System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ lblTiempo;
	private: System::Windows::Forms::Label^ lblTiempo2;
	private: System::Windows::Forms::Label^ lblMeta;
		   Bitmap^ imgjugador;
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			j = new Juego();
			imgjugador = gcnew Bitmap("Tortuga.jfif");
			ncarreras = 1;
			contador = 0;
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
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblTiempo = (gcnew System::Windows::Forms::Label());
			this->lblTiempo2 = (gcnew System::Windows::Forms::Label());
			this->lblMeta = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// lblTiempo
			// 
			this->lblTiempo->AutoSize = true;
			this->lblTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo->Location = System::Drawing::Point(430, 21);
			this->lblTiempo->Name = L"lblTiempo";
			this->lblTiempo->Size = System::Drawing::Size(0, 25);
			this->lblTiempo->TabIndex = 0;
			// 
			// lblTiempo2
			// 
			this->lblTiempo2->AutoSize = true;
			this->lblTiempo2->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTiempo2->Location = System::Drawing::Point(294, 21);
			this->lblTiempo2->Name = L"lblTiempo2";
			this->lblTiempo2->Size = System::Drawing::Size(93, 23);
			this->lblTiempo2->TabIndex = 1;
			this->lblTiempo2->Text = L"Tiempo:";
			// 
			// lblMeta
			// 
			this->lblMeta->AutoSize = true;
			this->lblMeta->Location = System::Drawing::Point(830, 74);
			this->lblMeta->Name = L"lblMeta";
			this->lblMeta->Size = System::Drawing::Size(11, 612);
			this->lblMeta->TabIndex = 2;
			this->lblMeta->Text = L"|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n"
				L"|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|\r\n|";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 742);
			this->Controls->Add(this->lblMeta);
			this->Controls->Add(this->lblTiempo2);
			this->Controls->Add(this->lblTiempo);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		//Fondo al formulario
		buffer->Graphics->Clear(Color::White);
		int ancho, alto;
		ancho = g->VisibleClipBounds.Width;
		alto = g->VisibleClipBounds.Height;
		buffer->Graphics->DrawImage(imgjugador, ancho / 2, alto / 2, 0, 0);
		//Renderizado
		lblTiempo->Text = Convert::ToString(contador);
		j->moverTodo(buffer, imgjugador);
		if (ncarreras > 4) {
			timer1->Enabled = false;
			buffer->Graphics->Clear(Color::White);
			MessageBox::Show("Tortuga 1" + ": " + j->getArreglo()[0]->getvictorias() + "\n" +
							"Tortuga 2" + ": " + j->getArreglo()[1]->getvictorias() + "\n" +
							"Tortuga 3" + ": " + j->getArreglo()[2]->getvictorias() + "\n" );
		}
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}

	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (j->sillegaronTodos() == true) {
			timer2->Enabled = false;
		}
		contador++;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Space:
			if (j->sillegaronTodos()==true){
				j->again(); ncarreras++;
				contador = 0;
				timer2->Enabled = true;
			}
			break;
		}
	}
};
}
