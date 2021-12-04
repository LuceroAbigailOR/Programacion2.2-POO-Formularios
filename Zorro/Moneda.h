#pragma once
#include "Entidad.h"

class Moneda : public Entidad {
public:
	Moneda(int x, int y) : Entidad(x, y) {
		ancho = 40; //diametro del circulo
		alto = 40; //diametro del circulo
	}
	~Moneda() {}

	void dibujar(BufferedGraphics^ buffer) {
		SolidBrush^ b = gcnew SolidBrush(Color::Yellow);
		buffer->Graphics->FillEllipse(b, x, y, ancho, alto);
	}
};
