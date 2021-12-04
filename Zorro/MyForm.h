#pragma once
#include "Juego.h"
namespace SimulacroPC2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	private:
		int contador;
		Juego* j;
		Bitmap^ imgjugador;
	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			j = new Juego;
			contador = 0;
			//bitmaps
			imgjugador = gcnew Bitmap("Zorro.png");
		}

	protected:
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

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->timer2->Interval = 4000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(982, 455);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (contador < 15) { //10 bombas
			j->eliminarMonedas();
			contador++;
		}
		else
			if (contador == 15) {
				this->timer2->Enabled = false;
			}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		//Fondo al formulario
		buffer->Graphics->Clear(Color::LightGreen);
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
		if (j->FinDelJuego() == true) {
			this->timer1->Enabled = false;
			MessageBox::Show("Reporte: " + "\n" + j->getJugador()->getCambioColor());
			this->Close();
		}
	}
	private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		switch (e->KeyChar)
		{
		case 'B':
			j->getJugador()->setColor(1);
			j->getJugador()->setCambioColor(j->getJugador()->getCambioColor() + 1);
			break;
		case 'V':
			j->getJugador()->setColor(2);
			j->getJugador()->setCambioColor(j->getJugador()->getCambioColor() + 1);
			break;
		case 'Z':
			j->getJugador()->setColor(3);
			j->getJugador()->setCambioColor(j->getJugador()->getCambioColor() + 1);
			break;
		case 'A':
			j->getJugador()->setColor(4);
			j->getJugador()->setCambioColor(j->getJugador()->getCambioColor() + 1);
			break;
		}
	}
};
}
