#pragma once
#include "Entidad.h"

class Superball : public Entidad {
private:
	int dx, dy;
public:
	Superball() {}

	Superball(int x, int y) : Entidad(x, y) {
		dx = 3;
		dy = 3;
		ancho = 92;
		alto = 82;
	}

	Superball(int x, int y, int dx, int dy, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->ancho = ancho;
		this->alto = alto;
		indiceX = 0;
		indiceY = 0;
	}

	int getDX() { return dx; }
	int getDY() { return dy; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaSprite = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escalarPersonaje = Rectangle(x, y, (int)(ancho * 0.3), (int)(alto * 0.3));
		buffer->Graphics->DrawImage(bmp, escalarPersonaje, areaSprite, GraphicsUnit::Pixel);

		indiceX++;
		if (indiceX == 2) indiceX = 0;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		if (x + dx <0 || x + dx + ancho > anchoForm) dx *= -1;
		if (y + dy <0 || y + dy + alto > altoForm) dy *= -1;
		x += dx;
		y += dy;

		dibujar(buffer, bmp);
	}
};
