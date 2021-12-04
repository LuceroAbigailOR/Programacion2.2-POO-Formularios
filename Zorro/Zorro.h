#pragma once
#include "Entidad.h"
enum Direcciones { Abajo, Arriba, Izquierda, Derecha };

class Zorro : public Entidad {
private:
	int  dx, dy;
	int indiceX, indiceY;
	int color;
	Direcciones ultimaTecla;
	int cambioColor;
	int codigo;

public:
	Direcciones direccion;
	Zorro(int x, int y) : Entidad(x, y) {
		ultimaTecla = Abajo;
		dx = 0;
		dy = 0;
		ancho = 48; //576 entre 12
		alto = 48; // 384 entre 12
		color = 1 + rand() % 9 - 1; // 8 colores de zorro random
		cambioColor = 0;
		direccion = Abajo;
	}
	~Zorro() {}

	int getDX() { return dx; }
	int getDY() { return dy; }
	int getColor() { return color; }
	int getCambioColor() { return cambioColor; }
	void setCambioColor(int v) { cambioColor = v; }
	void setColor(int v) { color = v; }
	void setDX(int v) { dx = v; }
	void setDY(int v) { dy = v; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaSprite = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escalarPersonaje = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		buffer->Graphics->DrawImage(bmp, escalarPersonaje, areaSprite, GraphicsUnit::Pixel);
		x += dx;
		y += dy;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (color) {
		case 1:
			moverZorroGrisClaro(buffer, bmp, anchoForm, altoForm);
			break;
		case 2:
			moverZorroNaranjaClaro(buffer, bmp, anchoForm, altoForm);
			break;
		case 3:
			moverZorroMarronClaro(buffer, bmp, anchoForm, altoForm);
			break;
		case 4:
			moverZorroAmarillo(buffer, bmp, anchoForm, altoForm);
			break;
		case 5:
			moverZorroNaranjaOscuro(buffer, bmp, anchoForm, altoForm);
			break;
		case 6:
			moverZorroBlanco(buffer, bmp, anchoForm, altoForm);
			break;
		case 7:
			moverZorroGrisOscuro(buffer, bmp, anchoForm, altoForm);
			break;
		case 8:
			moverZorroMarronOscuro(buffer, bmp, anchoForm, altoForm);
			break;
		}
	}

	void moverZorroGrisClaro(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 3;
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 0;
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 1;
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 2;
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;
		}
		dibujar(buffer, bmp);
	}

	void moverZorroNaranjaOscuro(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 3;
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 0;
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 1;
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 2;
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;
		}
		dibujar(buffer, bmp);
	}

	void moverZorroBlanco(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 3;
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 0;
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 1;
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 2;
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;
		}
		dibujar(buffer, bmp);
	}

	void moverZorroNaranjaClaro(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 3;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 0;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 1;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 2;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;
		}
		dibujar(buffer, bmp);
	}

	void moverZorroGrisOscuro(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 7;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 4;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 5;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 6;
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;
		}
		dibujar(buffer, bmp);
	}

	void moverZorroMarronOscuro(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 7;
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 4;
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 5;
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 6;
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;
		}
		dibujar(buffer, bmp);
	}
	
	void moverZorroMarronClaro(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 7;
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 4;
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 5;
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 6;
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;
		}
		dibujar(buffer, bmp);
	}

	void moverZorroAmarillo(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			indiceY = 7;
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			dy = -10;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			indiceY = 4;
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			dy = 10; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 5;
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			dx = -10; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 6;
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			dx = 10; //Traslado hacia arriba en Y
			dy = 0;
			ultimaTecla = Derecha;
			break;
		}
		dibujar(buffer, bmp);
	}

	void movimientoIndependiente(int anchoForm, int altoForm) {
		if (x + dx < 5 || x + dx + ancho > anchoForm -5) {
			if (direccion == Direcciones::Derecha) {
				direccion = Direcciones::Izquierda;
			}
			else {
				direccion = Direcciones::Derecha;
			}
			color = 1 + rand()% 9 -1;
			cambioColor++;
		}
		if (y + dy < 5 || y + dy + alto > altoForm -5) {
			if (direccion == Direcciones::Arriba) {
				direccion = Direcciones::Abajo;
			}
			else {
				direccion = Direcciones::Arriba;
			}
			color = 1 + rand() % 9 - 1;
			cambioColor++;
		}
	}

};
