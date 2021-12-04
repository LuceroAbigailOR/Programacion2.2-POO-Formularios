#pragma once
using namespace System::Drawing;
enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha };

class Jugador {
private:
	int x, y, dx, dy, alto, ancho;
	int indiceX, indiceY;
	Direcciones ultimaTecla;

public:
	Direcciones direccion;
	Jugador() {}
	Jugador(int x, int y) {
		this->x = x;
		this->y = y;
		dx = dy = 10;
		ultimaTecla = Abajo;
		direccion = Ninguna;
		ancho = 60; //180 entre 3
		alto = 61; //240 entre 4
		indiceX = 0;
		indiceY = 0;
	}
	~Jugador() {}

	int getX() { return x; }
	int getY() { return y; }

	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaSprite = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escalarPersonaje = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		buffer->Graphics->DrawImage(bmp, escalarPersonaje, areaSprite, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 3;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 0;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 1;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 2;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;

		case Ninguna:
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case Arriba:
				indiceX = 0;
				indiceY = 3;
				break;
			case Abajo:
				indiceX = 0;
				indiceY = 0;
				break;
			case Izquierda:
				indiceX = 0;
				indiceY = 1;
				break;
			case Derecha:
				indiceX = 0;
				indiceY = 2;
				break;
			}
			break;
		}
		dibujar(buffer, bmp);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
