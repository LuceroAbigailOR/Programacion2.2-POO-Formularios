#pragma once
#include <conio.h>
#include "Juego.h"
#include "time.h"

namespace Ejercicio2PC2 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
  
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: 
		System::Windows::Forms::Timer^ timer2;
		Juego* j;
		int contador;

		//Bitmaps
		Bitmap^ imgjugador;

	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			j = new Juego();
			contador = 0;

			//bitmaps
			imgjugador = gcnew Bitmap("Soldado.png");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			this->timer2->Enabled = true;
			this->timer2->Interval = 2000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 455);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		
		//Fondo al formulario
		buffer->Graphics->Clear(Color::White);
		int ancho, alto;
		ancho = g->VisibleClipBounds.Width;
		alto = g->VisibleClipBounds.Height;

		//Renderizado
		j->moverTodo(g, buffer, imgjugador, ancho, alto);
		j->colision();
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			j->getJugador()->direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			j->getJugador()->direccion = Direcciones::Derecha;
			break;
		case Keys::Up:
			j->getJugador()->direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			j->getJugador()->direccion = Direcciones::Abajo;
			break;
		}

	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		j->getJugador()->direccion = Direcciones::Ninguna;
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (contador < 10) { //10 bombas
			j->agregarBomba();
			contador++;
		}
		else
			if (contador == 10) {
				this->timer2->Enabled = false;
			}
	}
};
}
