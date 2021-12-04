#pragma once
#include "Entidad.h"

class Disco2 : public Entidad {
private:
	int dx;
public:
	Disco2() {}
	Disco2(int x, int y) : Entidad(x, y) {
		dx = 15;
		ancho = 52;
		alto = 49;
	}
	~Disco2() {}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm) {
		if (indiceX >= 0 && indiceX < 2) { indiceX++; }
		else indiceX = 0;
		if (x + dx < 1 || x + ancho + dx > anchoForm - 1) x = 0;
		else x += dx;
		dibujar(buffer, bmp);
	}
};
