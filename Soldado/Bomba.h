#pragma once
#include <iostream>

using namespace System::Drawing;

class Bomba {
private: 
	int x, y;
	int dy, radio;
public:
	Bomba() {
		dy = 3;
		radio = 20;
		x = rand()% 700 + 10;
		y = rand()% 300 + 3;
	}

	~Bomba() {}

	int getX() { return x; }
	int getY() { return y; }
	int getdy() { return dy; }

	void setdy(int dy) { this->dy = dy; }

	void dibujar(BufferedGraphics^ buffer) {
		SolidBrush^ b = gcnew SolidBrush(Color::Blue);
		buffer->Graphics->FillEllipse(b, x, y, radio*2, radio*2);
	}

	void mover(BufferedGraphics^ buffer) {
		if (y + dy < 1 || y + dy + radio*2 > buffer->Graphics->VisibleClipBounds.Height) dy *= -1;
		y += dy;
		dibujar(buffer);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, radio*2, radio*2);
	}
};
