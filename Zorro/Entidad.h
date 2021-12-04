#pragma once
#include <iostream>
using namespace System::Drawing;

class Entidad {
protected:
	int x, y, ancho, alto;

public:
	Entidad(int x, int y) {
		this->x = x;
		this->y = y;
	}
	~Entidad() {}

	int getX() { return x; }
	int getY() { return y; }
	void setX(int v) { x = v; }
	void setY(int v) { y = v; }

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
