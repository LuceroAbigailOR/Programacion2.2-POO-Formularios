#pragma once
#include "Pikachu.h"
#include "Pokeball.h"
#include "Superball.h"
#include "Masterball.h"
#include "Ultraball.h"
#include <vector>
using namespace std;

class Juego {
private:
	Pikachu* pikachu;
	vector<Pokeball*> ArrPokeball;
	vector<Superball*> ArrSuperball;
	vector <Masterball*> ArrMasterball;
	vector<Ultraball*> ArrUltraball;
	bool pausa;
	int puntos, reloj;
	int contPokeball, contUltraball, contSuperball, contMasterball;

public:
	Juego() {}
	Juego(int x, int y, int cPokeball, int cUltraball, int cSuperball, int cMasterball) {
		pikachu = new Pikachu(x, y);
		puntos = reloj = 0;
		pausa = false; 
		contPokeball = cPokeball;
		contUltraball = cUltraball;
		contSuperball = cSuperball;
		contMasterball = cMasterball;
	}
	~Juego() {}

	void AgregarObjetoPokeball(int codigo) {
		switch (codigo) {
		case 0:
			if (contPokeball > 0) {
				ArrPokeball.push_back(new Pokeball(20 + rand() % 600 - 20, 20 + rand() % 400 - 20));
				contPokeball--;
			}
			break;
		case 1:
			if (contMasterball > 0) { 
				ArrMasterball.push_back(new Masterball(20 + rand() % 600 - 20, 20 + rand() % 400 - 20));
				contMasterball--;
			}
			break;
		case 2:
			if (contUltraball > 0) {
				ArrUltraball.push_back(new Ultraball(20 + rand() % 600 - 20, 20 + rand() % 400 - 20));
				contUltraball--;
			}
			break;
		case 3:
			if (contSuperball > 0) { 
				ArrSuperball.push_back(new Superball(20 + rand() % 600 - 20, 20 + rand() % 400 - 20)); 
				contSuperball--;
			}
			break;
		}
	}

	void AgregarPokeball(int x, int y, int dy, int ancho, int alto) {
		ArrPokeball.push_back(new Pokeball(x,y,dy,ancho,alto));
		contPokeball--;
	}

	void AgregarSuperball(int x, int y, int dx, int dy, int ancho, int alto) {
		ArrSuperball.push_back(new Superball(x, y, dx, dy, ancho, alto));
		contSuperball--;
	}

	void AgregarUltraball(int x, int y, int dx, int dy, int ancho, int alto) {
		ArrUltraball.push_back(new Ultraball(x, y, dx, dy, ancho, alto));
		contUltraball--;
	}

	void AgregarMasterball(int x, int y, int dx, int dy, int ancho, int alto) {
		ArrMasterball.push_back(new Masterball(x, y, dx, dy, ancho, alto));
		contMasterball--;
	}

	void borrarTodosLosArreglos() { 
		ArrPokeball.clear(); 
		ArrSuperball.clear();
		ArrUltraball.clear();
		ArrMasterball.clear();
		//reiniciar contadores
		contPokeball = 10;
		contUltraball = 3;
		contSuperball = 4;
		contMasterball = 1;
	}

	void dibujar(BufferedGraphics^ buffer) {
		buffer->Graphics->DrawString("PUNTOS: " + puntos, gcnew Font("Goudy Stout", 12), Brushes::Black, 500, 10);
		buffer->Graphics->DrawString("MOCHILA: " + (contPokeball + contMasterball + contUltraball + contSuperball) + "/18", gcnew Font("Goudy Stout", 11), Brushes::Black, 250, 10);
	}
	void moverTodo(BufferedGraphics^ buffer, Bitmap^ imgPikachu, Bitmap^ imgPokeball, Bitmap^ imgSuperball, Bitmap^ imgMasterball, Bitmap^ imgUltraball, int anchoform, int altoform) {
		if (pausa == false) {
			pikachu->mover(buffer, imgPikachu, anchoform, altoform);
			for (unsigned int i = 0; i < ArrPokeball.size(); i++) {
				ArrPokeball[i]->mover(buffer, imgPokeball, altoform);
			}
			for (unsigned int i = 0; i < ArrMasterball.size(); i++) {
				ArrMasterball[i]->mover(buffer, imgMasterball, anchoform, altoform);
			}
			for (unsigned int i = 0; i < ArrUltraball.size(); i++) {
				ArrUltraball[i]->mover(buffer, imgUltraball, anchoform, altoform);
			}
			for (unsigned int i = 0; i < ArrSuperball.size(); i++) {
				ArrSuperball[i]->mover(buffer, imgSuperball, anchoform, altoform);
			}
		}
		else
		{
			pikachu->dibujar(buffer, imgPikachu);
			for (unsigned int i = 0; i < ArrPokeball.size(); i++) {
				ArrPokeball[i]->dibujar(buffer, imgPokeball);
			}
			for (unsigned int i = 0; i < ArrMasterball.size(); i++) {
				ArrMasterball[i]->dibujar(buffer, imgMasterball);
			}
			for (unsigned int i = 0; i < ArrUltraball.size(); i++) {
				ArrUltraball[i]->dibujar(buffer, imgUltraball);
			}
			for (unsigned int i = 0; i < ArrSuperball.size(); i++) {
				ArrSuperball[i]->dibujar(buffer, imgSuperball);
			}
		}

	}

	void colisionMasterballLimite() {
		for (unsigned int i = 0; i < ArrMasterball.size(); i++) {
			if (ArrMasterball[i]->getPikachuAtrapado() == true) {
				puntos += 100;
				pikachu->setX(5 + rand() % 401 - 5);
				pikachu->setY(5 + rand() % 301 - 5);
				pikachu->setDX(1 + rand() % 10 - 1);
				pikachu->setDY(1 + rand() % 10 - 1);
				ArrMasterball[i]->setPikachuAtrapado(false);
			}
		}
	}

	void colisionPikachuTodosPokeball() {
		for (unsigned int i = 0; i < ArrPokeball.size(); i++)
		{
			if (ArrPokeball[i]->getRectangulo().IntersectsWith(pikachu->getRectangulo())) {
				puntos += 100;
				pikachu->setX(5 + rand() % 401 - 5);
				pikachu->setY(5 + rand() % 301 - 5);
				pikachu->setDX(1 + rand()% 10 - 1);
				pikachu->setDY(1 + rand()% 10 - 1);
			}
		}

		for (unsigned int i = 0; i < ArrSuperball.size(); i++)
		{
			if (ArrSuperball[i]->getRectangulo().IntersectsWith(pikachu->getRectangulo())) {
				puntos += 100;
				pikachu->setX(5 + rand() % 401 - 5);
				pikachu->setY(5 + rand() % 301 - 5);
				pikachu->setDX(1 + rand() % 10 - 1);
				pikachu->setDY(1 + rand() % 10 - 1);
			}
		}

		for (unsigned int i = 0; i < ArrMasterball.size(); i++)
		{
			if (ArrMasterball[i]->getRectangulo().IntersectsWith(pikachu->getRectangulo())) {
				puntos += 100;
				pikachu->setX(5 + rand() % 401 - 5);
				pikachu->setY(5 + rand() % 301 - 5);
				pikachu->setDX(1 + rand() % 10 - 1);
				pikachu->setDY(1 + rand() % 10 - 1);
			}
		}

		for (unsigned int i = 0; i < ArrUltraball.size(); i++)
		{
			if (ArrUltraball[i]->getRectangulo().IntersectsWith(pikachu->getRectangulo())) {
				puntos += 100;
				pikachu->setX(5 + rand() % 401 - 5);
				pikachu->setY(5 + rand() % 301 - 5);
				pikachu->setDX(1 + rand() % 10 - 1);
				pikachu->setDY(1 + rand() % 10 - 1);
			}
		}
	}

	void colisionTodosPokeball() {
		if (ArrPokeball.size()>0 && ArrSuperball.size()>0){
			for (unsigned int i = 0; i < ArrPokeball.size(); i++) {
				for (unsigned int j = 0; j < ArrSuperball.size(); j++) {
					if (ArrPokeball[i]->getRectangulo().IntersectsWith(ArrSuperball[j]->getRectangulo())) {
						ArrPokeball.erase(ArrPokeball.begin() + i);
						ArrSuperball.erase(ArrSuperball.begin() + j);
					}
				}
			}
		}
		
		if (ArrPokeball.size() > 0 && ArrMasterball.size() > 0) {
			for (unsigned int i = 0; i < ArrPokeball.size(); i++) {
				for (unsigned int j = 0; j < ArrMasterball.size(); j++) {
					if (ArrPokeball[i]->getRectangulo().IntersectsWith(ArrMasterball[j]->getRectangulo())) {
						ArrPokeball.erase(ArrPokeball.begin() + i);
						ArrMasterball.erase(ArrMasterball.begin() + j);
					}
				}
			}
		}
		
		if (ArrPokeball.size() > 0 && ArrUltraball.size() > 0) {
			for (unsigned int i = 0; i < ArrPokeball.size(); i++) {
				for (unsigned int j = 0; j < ArrUltraball.size(); j++) {
					if (ArrPokeball[i]->getRectangulo().IntersectsWith(ArrUltraball[j]->getRectangulo())) {
						ArrPokeball.erase(ArrPokeball.begin() + i);
						ArrUltraball.erase(ArrUltraball.begin() + j);
					}
				}
			}
		}

		if (ArrSuperball.size() > 0 && ArrMasterball.size() > 0) {
			for (unsigned int i = 0; i < ArrSuperball.size(); i++) {
				for (unsigned int j = 0; j < ArrMasterball.size(); j++) {
					if (ArrSuperball[i]->getRectangulo().IntersectsWith(ArrMasterball[j]->getRectangulo())) {
						ArrSuperball.erase(ArrSuperball.begin() + i);
						ArrMasterball.erase(ArrMasterball.begin() + j);
					}
				}
			}
		}

		if (ArrSuperball.size()>0 && ArrUltraball.size()>0) {
			for (unsigned int i = 0; i < ArrSuperball.size(); i++) {
				for (unsigned int j = 0; j < ArrUltraball.size(); j++) {
					if (ArrSuperball[i]->getRectangulo().IntersectsWith(ArrUltraball[j]->getRectangulo())) {
						ArrSuperball.erase(ArrSuperball.begin() + i);
						ArrUltraball.erase(ArrUltraball.begin() + j);
					}
				}
			}
		}

		if (ArrMasterball.size() > 0 && ArrUltraball.size() > 0) {
			for (unsigned int i = 0; i < ArrMasterball.size(); i++) {
				for (unsigned int j = 0; j < ArrUltraball.size(); j++) {
					if (ArrMasterball[i]->getRectangulo().IntersectsWith(ArrUltraball[j]->getRectangulo())) {
						ArrMasterball.erase(ArrMasterball.begin() + i);
						ArrUltraball.erase(ArrUltraball.begin() + j);
					}
				}
			}
		}
	}

	vector<Pokeball*> getArregloP() { return this->ArrPokeball; }
	vector<Masterball*> getArregloM() { return this->ArrMasterball; }
	vector<Superball*> getArregloS() { return this->ArrSuperball; }
	vector<Ultraball*> getArregloU() { return this->ArrUltraball; }
	int getPuntos() { return puntos; }
	bool getPausa() { return pausa; }
	void setPausa(bool pausa) { this->pausa = pausa; }
	void setPuntos(int puntos) { this->puntos = puntos; }
};
