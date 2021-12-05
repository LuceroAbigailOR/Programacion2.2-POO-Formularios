#pragma once
using namespace System::Drawing;

class CRectangulo { //Cuadrado
private:
	int x, y;
	int lado1, lado2;

public:
	CRectangulo(int x, int y, int lado1, int lado2) {
		this->x = x;
		this->y = y;
		this->lado1 = lado1;
		this->lado1 = lado2;
	}

	~CRectangulo() {}

	void draw(Graphics^ g, Color color) {
		SolidBrush^ b = gcnew SolidBrush(color);
		g->FillRectangle(b, x, y, lado1, lado2);
	}

	double getArea() {
		return lado1 * lado2; //area es base por altura
	}
};
