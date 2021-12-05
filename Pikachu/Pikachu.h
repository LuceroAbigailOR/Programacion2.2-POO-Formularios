#pragma once
#include "Entidad.h"

class Pikachu : public Entidad {
private:
	int dx, dy;
	int direccion;
public:
	Pikachu(int x, int y) : Entidad(x, y) {
		dx = 5;
		dy = 5;
		ancho = 67;
		alto = 64;
		direccion = rand() % 4;
	}
	~Pikachu() {}

	void setDX(int dx) { this->dx = dx; }
	void setDY(int dy) { this->dy = dy; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaSprite = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escalarPersonaje = Rectangle(x, y, ancho, alto);
		buffer->Graphics->DrawImage(bmp, escalarPersonaje, areaSprite, GraphicsUnit::Pixel);
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		srand(time(NULL));
		switch (direccion) {
		case 0:
			if (x + dx > 0) {
				x -= dx;
				indiceY = 1;
			}
			else
				direccion = rand() % 4;
			break;

		case 1:
			if (x + dx + ancho < anchoForm) {
				x += dx;
				indiceY = 2;
			}
			else
				direccion = rand() % 4;
			break;

		case 2:
			if (y + dy > 0) {
				y -= dy;
				indiceY = 3;
			}
			else
				direccion = rand() % 4;
			break;

		case 3:
			if (y + dy + alto < altoForm ) {
				y += dy;
				indiceY = 0;
			}
			else
				direccion = rand() % 4;
			break;
		}

		indiceX++;
		if (indiceX > 3)indiceX = 0;
		dibujar(buffer, bmp);
	}
};
