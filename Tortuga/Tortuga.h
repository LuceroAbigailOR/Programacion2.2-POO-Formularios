#pragma once
#include <iostream>
#include <conio.h>
using namespace System::Drawing;

class Tortuga {
private:
	int x, y, dx, dy, alto, ancho;
	int indiceX, indiceY;

	bool TerminoCarrera;
	int puesto;
	int victorias;

public:
	Tortuga() {}
	Tortuga(int y) {
		this->y = y;
		x = 1;
		dx = rand()% 10 + 5;
		dy = 0;
		ancho = 145; //590 entre 3
		alto = 157; //470 entre 4
		indiceX = indiceY = 0;
		TerminoCarrera = false;
		puesto = 0;
		victorias = 0;
	}
	~Tortuga() {};

	int getX() { return x; }
	int getvictorias() { return victorias; }
	bool getTerminoCarrera() { return TerminoCarrera; }
	int getpuesto() { return puesto; }

	void setX(int x) { this->x = x; }
	void setdx(int dx) { this->dx = dx; }
	void setTerminoCarrera(bool TerminoCarrera) { this->TerminoCarrera = TerminoCarrera; }
	void setpuesto(int puesto) { this->puesto = puesto; }

	void aumentarVictorias() { victorias++; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaSprite = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escalarPersonaje = Rectangle(x, y, ancho / 3, alto /3);
		buffer->Graphics->DrawImage(bmp, escalarPersonaje, areaSprite, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp) {
		if (x + dx + ancho < 700) {
			for (int i = 0; i < 3; i++) {
				indiceY = i;
				if (indiceX >= 0 && indiceX < 4) { indiceX++; }
				else indiceX = 0;
				dibujar(buffer, bmp);
			}
		}
		else
			if (x + dx + ancho >= 700)
				TerminoCarrera = true;
			else
			TerminoCarrera = false;
	}
};
