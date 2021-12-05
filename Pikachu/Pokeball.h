#pragma once
#include "Entidad.h"

class Pokeball : public Entidad {
private:
	int dy;
public:
	Pokeball() {}

	Pokeball(int x, int y) : Entidad(x, y) {
		dy = 2;
		ancho = 59;
		alto = 56;
	}

	Pokeball(int x, int y, int dy, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->dy = dy;
		this->ancho = ancho;
		this->alto = alto;
		indiceX = 0;
		indiceY = 0;
	}

	int getDY() { return dy; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaSprite = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escalarPersonaje = Rectangle(x, y, (int) (ancho*0.5), (int)(alto*0.5));
		buffer->Graphics->DrawImage(bmp, escalarPersonaje, areaSprite, GraphicsUnit::Pixel);

		indiceX++;
		if (indiceX == 2) indiceX = 0;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bm, int altoForm) {
		if (y + dy < 0 || y + dy + alto > altoForm) dy *= -1;
		y += dy;

		dibujar(buffer,bm);
	}
};
