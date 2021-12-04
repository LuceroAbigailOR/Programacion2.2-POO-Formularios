#pragma once
#include "Tortuga.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Juego {
private:
	vector<Tortuga*> arrtortugas;
	int cont, N;
	bool llegaronTodos;
public:
	Juego() {
		N = 3 + rand()% (7 - 3); //numeros random entre 3 y 6
		cont = 0;
		llegaronTodos = false;
		agregarTortuga();
	}
	~Juego() {}

	void agregarTortuga() {
		for (int i = 1; i <= N; i++) {
			Tortuga* _t = new Tortuga(i*70);//i*20 es la posicion y de la tortuga
			arrtortugas.push_back(_t);
		}
	}

	void moverTodo(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (unsigned int i = 0; i < arrtortugas.size(); i++) {
			if (arrtortugas[i]->getTerminoCarrera() == true) {
				arrtortugas[i]->setpuesto(++cont);
				if (arrtortugas[i]->getpuesto() == 1)arrtortugas[i]->aumentarVictorias();
			}
			else
				arrtortugas[i]->mover(buffer, bmp);
		}
	}

	void again() {
		for (unsigned int i = 0; i < arrtortugas.size(); i++) {
			arrtortugas[i]->setX(0);
			arrtortugas[i]->setdx(rand()%10+5);
			arrtortugas[i]->setTerminoCarrera(false);
			arrtortugas[i]->setpuesto(0);
		}
		cont = 0;
	}

	bool sillegaronTodos() {
		int llegaron = 0;
		for (unsigned int i = 0; i < arrtortugas.size(); i++) {
			if (arrtortugas[i]->getTerminoCarrera() == true) llegaron++;
		}

		if (llegaron == arrtortugas.size()) llegaronTodos = true;
		else
			llegaronTodos = false;
		return llegaronTodos;
	}
	vector<Tortuga*> getArreglo() { return this->arrtortugas; }
};
