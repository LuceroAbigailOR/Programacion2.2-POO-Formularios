#pragma once
#include <array>

using namespace System::Drawing;

class Triangulo {
private:
	int x0, y0;
	int x1, y1;
	int x2, y2;
	int dy;
	bool visible;
public:
	Triangulo() {
		x0 = y0 = x1 = y1 = x2 = y2 = dy = 0;
		visible = false;
	};
	Triangulo(int x0, int y0, int x1, int y1, int x2, int y2) {
		this->x0 = x0;
		this->y0 = y0;
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		dy = 2;
		visible = false;
	}
	~Triangulo() {}

	void mover(Graphics^ gr) {

		borrar(gr);

		if ((y0 + dy <1) || (y0 + dy  >gr->VisibleClipBounds.Height)) dy *= -1;
		if ((y1 + dy <1) || (y1 + dy  >gr->VisibleClipBounds.Height)) dy *= -1;
		if ((y2 + dy <1) || (y2 + dy  >gr->VisibleClipBounds.Height)) dy *= -1;

		y0 += dy;
		y1 += dy;
		y2 += dy;

		dibujar(gr);
	}

	void dibujar(Graphics^ gr) {
		gr->DrawLine(gcnew Pen(Color::Black), x0, y0, x1, y1);
		gr->DrawLine(gcnew Pen(Color::Black), x1, y1, x2, y2);
		gr->DrawLine(gcnew Pen(Color::Black), x2, y2, x0, y0);
	}

	void borrar(Graphics^ gr) {
		gr->DrawLine(gcnew Pen(Color::Red), x0, y0, x1, y1);
		gr->DrawLine(gcnew Pen(Color::Red), x1, y1, x2, y2);
		gr->DrawLine(gcnew Pen(Color::Red), x2, y2, x0, y0);
	}

	int getx() { return this->x0; }
	int gety() { return this->y0; }
	void setvisible(int visible) { this->visible = visible; }
	void isVisible() {}
};
