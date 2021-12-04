#pragma once
#include <iostream>
using namespace System::Drawing;

class Entidad {
protected:
	int x, y;
	int ancho, alto;
	int indiceX, indiceY;

public:
	Entidad() {}
	Entidad(int x, int y) {
		this->x = x;
		this->y = y;
		indiceX = 0;
		indiceY = 0;
	}
	~Entidad() {}

	int getX() { return x; }
	int getY() { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

	virtual void mover(BufferedGraphics^ buffer, Bitmap^ bmp) {};

	void dibujar (BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaSprite = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escalarPersonaje = Rectangle(x, y, (int)(ancho * 1.2), (int)(alto * 1.2));
		buffer->Graphics->DrawImage(bmp, escalarPersonaje, areaSprite, GraphicsUnit::Pixel);
	}

	Rectangle getRectangulo() {
		return Rectangle(x, y, ancho, alto);
	}
};
