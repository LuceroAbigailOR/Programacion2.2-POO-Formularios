#pragma once
using namespace System::Drawing;

class Linea {
private:
	int x, y;
	int puntoInicial, puntoFinal;

public:
	Linea(int x, int y, int puntoInicial, int puntoFinal) {
		this->x = x;
		this->y = y;
		this->puntoInicial = puntoInicial;
		this->puntoFinal = puntoFinal;
	}

	~Linea() {}

	void draw(Graphics^ g, Color color) {
		Pen^ lapicero = gcnew Pen(color, 3); //grosor 3
		g->DrawLine(lapicero, x, y, puntoInicial, puntoFinal);
	}
};
