#pragma once
using namespace System::Drawing;

class Elipse { //Circulo
private:
	int x, y;
	int radio, radio2;

public:
	Elipse(int x, int y, int radio, int radio2) {
		this->x = x;
		this->y = y;
		this->radio = radio;
		this->radio2 = radio2;
	}

	~Elipse() {}

	void draw(Graphics^ g, Color color) {
		SolidBrush^ b = gcnew SolidBrush(color);
		g->FillEllipse(b, x, y, 2 * radio, 2 * radio2);
	}

	double getArea() {
		return 3.14 * radio * radio2; //area es pi por radio al cuadrado
	}
};
