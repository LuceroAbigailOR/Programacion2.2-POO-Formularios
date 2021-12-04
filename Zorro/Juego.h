#pragma once
#include "Zorro.h"
#include "Moneda.h"
#include <vector>

using namespace std;
class Juego {
private:
	Zorro* jugador;
	vector<Moneda*> arrmonedas;
	int contMonedasDesaparecidas;
	bool fin;

public:
	Juego() {
		jugador = new Zorro(10 + rand()% 400-10, 10 + rand() % 200 - 10); //posicion random
		agregarMoneda();
		contMonedasDesaparecidas = 0;
		fin = false;
	}
	~Juego() {}

	void agregarMoneda() {
		for (int i = 0; i < 15; i++) {
			Moneda* _m = new Moneda(10 + rand() % 400 - 10, 10 + rand() % 200 - 10); //posicion random
			arrmonedas.push_back(_m);
		}
		
	}

	void moverTodo(Graphics^ gr, BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		for (unsigned int i = 0; i < arrmonedas.size(); i++) {
			arrmonedas[i]->dibujar(buffer); //solo se dibuja, no tiene movimiento
		}

		jugador->movimientoIndependiente(anchoform, altoform);
		jugador->mover(buffer, bmp, anchoform, altoform);
	}

	void colision() {
		for (unsigned int i = 0; i < arrmonedas.size(); i++) {
			if (jugador->getRectangle().IntersectsWith(arrmonedas[i]->getRectangle())) {
				jugador->setDX(jugador->getDX()*-1);
				jugador->setDY(jugador->getDY()*-1);
			}
		}
	}

	void eliminarMonedas() {
		arrmonedas.erase(arrmonedas.begin()); //la moneda se elimina del arreglo
		contMonedasDesaparecidas++;
	}

	int cantidadMonedasDesaparecidas() {
		return contMonedasDesaparecidas;
	}

	bool FinDelJuego() {
		if (contMonedasDesaparecidas == 15) fin = true;
		else
			fin = false;
		return fin;
	}

	Zorro* getJugador() { return jugador; }
	vector<Moneda*> getArreglo() { return this->arrmonedas; }
};
