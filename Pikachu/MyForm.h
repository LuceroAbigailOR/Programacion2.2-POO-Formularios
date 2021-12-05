#pragma once
#include "Juego.h"
#include "Configuracion.h"
#include "Ranking.h"
#include "Jugador.h"
#include "iostream"
namespace SimulacroExamenFinal {
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
		Ranking* ranking;
		Configuracion* file;
		Bitmap^ fondo;
		Bitmap^ imgPikachu;
		Bitmap^ imgPokeball;
		Bitmap^ imgSuperball;
		Bitmap^ imgMasterball;
		Bitmap^ imgUltraball;
		int tiempo;

	private: System::Windows::Forms::Timer^ TemporizadorJuego;

	public:
		MyForm(void)
		{
			srand(time(NULL));
			InitializeComponent();
			//Configuracion
			file = new Configuracion();
			file->leerInformacion();

			//Ranking
			ranking = new Ranking();

			//Otros
			j = new Juego(file->getX(), file->getY(), file->getcontPokeball(), file->getcontUltraball(), file->getcontSuperball(), file->getcontMasterball());
			fondo = gcnew Bitmap("FondoSimulacro.png");
			imgPikachu = gcnew Bitmap("Pikachu.png");
			imgPokeball = gcnew Bitmap("Pokeball.png");
			imgSuperball = gcnew Bitmap("Superball.png");
			imgMasterball = gcnew Bitmap("Masterball.png");
			imgUltraball = gcnew Bitmap("Ultraball.png");
			tiempo = 0;
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
		System::Windows::Forms::Timer^ timerJuego;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timerJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->TemporizadorJuego = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timerJuego
			// 
			this->timerJuego->Enabled = true;
			this->timerJuego->Tick += gcnew System::EventHandler(this, &MyForm::timerJuego_Tick);
			// 
			// TemporizadorJuego
			// 
			this->TemporizadorJuego->Enabled = true;
			this->TemporizadorJuego->Interval = 1000;
			this->TemporizadorJuego->Tick += gcnew System::EventHandler(this, &MyForm::TemporizadorJuego_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 653);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"JUEGO";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timerJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);

		int ancho, alto;
		ancho = (int)g->VisibleClipBounds.Width;
		alto = (int)g->VisibleClipBounds.Height;

		buffer->Graphics->DrawImage(fondo, 0, 0, ancho, alto);
		//Colisiones
		j->colisionTodosPokeball();
		j->colisionPikachuTodosPokeball();
		j->colisionMasterballLimite();

		j->dibujar(buffer);
		buffer->Graphics->DrawString("TIEMPO: " + tiempo + "/100", gcnew Drawing::Font("Goudy Stout", 11), Brushes::Black, 45, 10);
		j->moverTodo(buffer, imgPikachu, imgPokeball, imgSuperball, imgMasterball, imgUltraball, ancho, alto);

		buffer->Render(g);

		delete buffer;
		delete espacio;
		delete g;

		if (tiempo == 100) { //100 segundos
			this->timerJuego->Enabled = false;
			Jugador* jugador = new Jugador(j->getPuntos());
			ranking->agregar_elemento(jugador);
			ranking->guardar_partida();
			ranking->cargar_partida();
			
			MessageBox::Show("SE ACABO EL TIEMPO" + "\n" +
							 "Puntos: " + j->getPuntos() + "\n" +
							 "[El ranking esta en el archivo texto Ranking]");
			this->Close();
		}
	}

	private: void guardarPartida() {
		ofstream file_partida;
		file_partida.open("Partida.txt", ios::out);
		int contPokeball, contUltraball, contSuperball, contMasterball;
		int puntos;
		contPokeball = j->getArregloP().size();
		contUltraball = j->getArregloU().size();
		contSuperball = j->getArregloS().size();
		contMasterball = j->getArregloM().size();
		puntos = j->getPuntos();

		if (file_partida.is_open() == true) {
			file_partida << puntos << endl;
			file_partida << contPokeball << endl;
			for (int i = 0; i < contPokeball; i++) {
				file_partida << j->getArregloP()[i]->getX() << endl;
				file_partida << j->getArregloP()[i]->getY() << endl;
				file_partida << j->getArregloP()[i]->getDY() << endl;
				file_partida << j->getArregloP()[i]->getAncho() << endl;
				file_partida << j->getArregloP()[i]->getAlto() << endl;
			}

			file_partida << contUltraball << endl;
			for (int i = 0; i < contUltraball; i++) {
				file_partida << j->getArregloU()[i]->getX() << endl;
				file_partida << j->getArregloU()[i]->getY() << endl;
				file_partida << j->getArregloU()[i]->getDX() << endl;
				file_partida << j->getArregloU()[i]->getDY() << endl;
				file_partida << j->getArregloU()[i]->getAncho() << endl;
				file_partida << j->getArregloU()[i]->getAlto() << endl;
			}

			file_partida << contSuperball << endl;
			for (int i = 0; i < contSuperball; i++) {
				file_partida << j->getArregloS()[i]->getX() << endl;
				file_partida << j->getArregloS()[i]->getY() << endl;
				file_partida << j->getArregloS()[i]->getDX() << endl;
				file_partida << j->getArregloS()[i]->getDY() << endl;
				file_partida << j->getArregloS()[i]->getAncho() << endl;
				file_partida << j->getArregloS()[i]->getAlto() << endl;
			}

			file_partida << contMasterball << endl;
			for (int i = 0; i < contMasterball; i++) {
				file_partida << j->getArregloM()[i]->getX() << endl;
				file_partida << j->getArregloM()[i]->getY() << endl;
				file_partida << j->getArregloM()[i]->getDX() << endl;
				file_partida << j->getArregloM()[i]->getDY() << endl;
				file_partida << j->getArregloM()[i]->getAncho() << endl;
				file_partida << j->getArregloM()[i]->getAlto() << endl;
			}

			file_partida.close();
			MessageBox::Show("PARTIDA GUARDADA" +
				"\nPokeballs: " + contPokeball +
				"\nSuperballs: " + contSuperball +
				"\nUltraballs: " + contUltraball +
				"\nMasterballs: " + contMasterball);
		}
	}

	private: void cargarPartida() {
		ifstream file_partida;
		file_partida.open("Partida.txt", ios::in);
		int contPokeball, contUltraball, contSuperball, contMasterball;
		int xP, yP, anchoP, altoP, dyP;
		int xU, yU, anchoU, altoU, dxU, dyU;
		int xS, yS, anchoS, altoS, dxS, dyS;
		int xM, yM, anchoM, altoM, dxM, dyM;
		int puntos;

		if (file_partida.is_open() == true) {
			j->borrarTodosLosArreglos();

			file_partida >> puntos;
			file_partida >> contPokeball;
			for (int i = 0; i < contPokeball; i++) {
				file_partida >> xP;
				file_partida >> yP;
				file_partida >> dyP;
				file_partida >> anchoP;
				file_partida >> altoP;
				j->AgregarPokeball(xP, yP, dyP, anchoP, altoP);
			}

			file_partida >> contUltraball;
			for (int i = 0; i < contUltraball; i++) {
				file_partida >> xU;
				file_partida >> yU;
				file_partida >> dxU;
				file_partida >> dyU;
				file_partida >> anchoU;
				file_partida >> altoU;
				j->AgregarUltraball(xU, yU, dxU, dyU, anchoU, altoU);
			}

			file_partida >> contSuperball;
			for (int i = 0; i < contSuperball; i++) {
				file_partida >> xS;
				file_partida >> yS;
				file_partida >> dxS;
				file_partida >> dyS;
				file_partida >> anchoS;
				file_partida >> altoS;
				j->AgregarSuperball(xS, yS, dxS, dyS, anchoS, altoS);
			}

			file_partida >> contMasterball;
			for (int i = 0; i < contMasterball; i++) {
				file_partida >> xM;
				file_partida >> yM;
				file_partida >> dxM;
				file_partida >> dyM;
				file_partida >> anchoM;
				file_partida >> altoM;
				j->AgregarMasterball(xM, yM, dxM, dyM, anchoM, altoM);
			}

			j->setPuntos(puntos);
			file_partida.close();
			MessageBox::Show("PARTIDA CARGADA" +
				"\nPokeballs: " + contPokeball +
				"\nSuperballs: " + contSuperball +
				"\nUltraballs: " + contUltraball +
				"\nMasterballs: " + contMasterball);
		}


	}
	private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		srand(time(NULL));
		int r = rand() % 4;
		switch (e->KeyChar)
		{
		case 'B': 
			j->AgregarObjetoPokeball(r);
			break;
		case 'P':
			if (j->getPausa() == false) { j->setPausa(true); }
			else j->setPausa(false);
			break;
		case 'S':
			guardarPartida();
			break;
		case 'L':
			cargarPartida();
		default:
			break;
		}

	}
	private: System::Void TemporizadorJuego_Tick(System::Object^ sender, System::EventArgs^ e) {
		if(j->getPausa()==false) tiempo++;
	}
};
}
