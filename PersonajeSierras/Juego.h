#pragma once
#include "Personaje.h"
#include "Disco1.h"
#include "Disco2.h"

class Juego {
private:
	Disco1* disco1;
	Disco2* disco2;
	Personaje* personaje;
public:
	Juego() {
		disco1 = new Disco1(5+rand()%600 - 5, 100);
		disco2 = new Disco2(5+rand()%600 - 5, 300);
		personaje = new Personaje(4, 4);
	}
	~Juego() {}

	void moverTodo(BufferedGraphics^ buffer, Bitmap^ bmpDisco1, Bitmap^ bmpDisco2, Bitmap^ bmpPersonaje, int anchoForm, int altoForm) {
		disco1->mover(buffer, bmpDisco1, anchoForm);
		disco2->mover(buffer, bmpDisco2, anchoForm);
		personaje->mover(buffer, bmpPersonaje, anchoForm, altoForm);
	}

	void colision() {
		if (disco1->getRectangulo().IntersectsWith(personaje->getRectangulo())) {
			//reiniciar posicion
			personaje->setX(4);
			personaje->setY(4);
			personaje->aumentarpuntos();
			//cambiar sprite
			if (personaje->getCodigo() < 7) personaje->setCodigo(personaje->getCodigo() + 1);
			else personaje->setCodigo(0);
		}

		if (disco2->getRectangulo().IntersectsWith(personaje->getRectangulo())) {
			//reiniciar posicion
			personaje->setX(4);
			personaje->setY(4);
			personaje->aumentarpuntos();
			//cambiar sprite
			if (personaje->getCodigo() < 7) personaje->setCodigo(personaje->getCodigo() + 1);
			else personaje->setCodigo(0);
		}
	}

	Personaje* getPersonaje() { return personaje; }
};
