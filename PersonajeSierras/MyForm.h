#pragma once
#include "Juego.h"
namespace Ejercicio1W14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		Juego* j;
		Bitmap^ imgPersonaje;
		Bitmap^ imgDisco1;
		Bitmap^ imgDisco2;

	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			j = new Juego();
			imgPersonaje = gcnew Bitmap("Personaje.png");
			imgDisco1 = gcnew Bitmap("Disco1.png");
			imgDisco2 = gcnew Bitmap("Disco2.png");
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: 
		System::Windows::Forms::Timer^ timerJuego;
		System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timerJuego
			// 
			this->timerJuego->Enabled = true;
			this->timerJuego->Tick += gcnew System::EventHandler(this, &MyForm::timerJuego_Tick);
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 653);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JUEGO";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::DarkBlue);
		int ancho, alto;
		ancho = (int)g->VisibleClipBounds.Width;
		alto = (int)g->VisibleClipBounds.Height;

		j->colision();
		j->moverTodo(buffer, imgDisco1, imgDisco2, imgPersonaje, ancho, alto);

		buffer->Render(g);

		delete buffer;
		delete espacio;
		delete g;
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			j->getPersonaje()->direccion = Direcciones::Izquierda;
			break;
		case Keys::Right:
			j->getPersonaje()->direccion = Direcciones::Derecha;
			break;
		case Keys::Up:
			j->getPersonaje()->direccion = Direcciones::Arriba;
			break;
		case Keys::Down:
			j->getPersonaje()->direccion = Direcciones::Abajo;
			break;
		}
	}

	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		j->getPersonaje()->direccion = Direcciones::Ninguna;
	}
};
}
