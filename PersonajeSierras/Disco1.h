#pragma once
#include "Entidad.h"

class Disco1 : public Entidad {
private:
	int dx;
public:
	Disco1() {}
	Disco1(int x, int y) : Entidad(x, y) {
		dx = 15;
		ancho = 51;
		alto = 59;
	}
	~Disco1() {}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm) {
		if (indiceX >= 0 && indiceX < 4) { indiceX++; }
		else indiceX = 0;
		if (x + dx < 1 || x + ancho + dx > anchoForm - 1) x = 0;
		else x += dx;
		dibujar(buffer, bmp);
	}
};
