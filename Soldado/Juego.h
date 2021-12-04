#pragma once
#include "Bomba.h"
#include "Soldado.h"
#include <vector>

using namespace std;
class Juego {
private:
	Jugador* jugador;
	vector<Bomba*> arrbombas;
	int cont;
public:
	Juego() {
		jugador = new Jugador(4, 4);
		agregarBomba();
	}
	~Juego() {}

	void agregarBomba() {
		Bomba* _b = new Bomba();
		arrbombas.push_back(_b);
	}

	void insertarBombas() {
		if (cont<10) { //10 bombas
			agregarBomba();
			cont++;
		}
	}

	void moverTodo(Graphics^ gr, BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		for (unsigned int i = 0; i < arrbombas.size(); i++) {
			arrbombas[i]->mover(buffer);
		}

		jugador->mover(buffer, bmp, anchoform, altoform);
	}

	void colision() {
		for (unsigned int i = 0; i < arrbombas.size(); i++) {
			if (jugador->getRectangle().IntersectsWith(arrbombas[i]->getRectangle())) {
				jugador->setx(4);
				jugador->sety(4);
				arrbombas[i]->setdy(arrbombas[i]->getdy()*-1);
			}
		}
	}

	Jugador* getJugador() { return jugador; }
	vector<Bomba*> getArreglo() { return this->arrbombas; }
};
