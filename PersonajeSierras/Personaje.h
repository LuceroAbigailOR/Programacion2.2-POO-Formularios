#pragma once
#include "Entidad.h"
enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha };

class Personaje : public Entidad {
private:
	int dx, dy;
	int codigo;
	int puntos;
	Direcciones ultimaTecla;

public:
	Direcciones direccion;
	Personaje(int x, int y) : Entidad(x, y) {
		dx = dy = 0;
		codigo = 0;
		puntos = 0;
		ultimaTecla = Abajo;
		direccion = Ninguna;
		ancho = 24; //287 entre 12
		alto = 24; //192 entre 8
	}
	~Personaje() {}

	int getCodigo() { return codigo; }
	int getPuntos() { return puntos; }
	void setCodigo(int codigo) { this->codigo = codigo; }

	void aumentarpuntos() { puntos++; }
	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (codigo) {
		case 0:
			mover0(buffer, bmp, anchoform, altoform);
			break;
		case 1:
			mover1(buffer, bmp, anchoform, altoform);
			break;
		case 2:
			mover2(buffer, bmp, anchoform, altoform);
			break;
		case 3:
			mover3(buffer, bmp, anchoform, altoform);
			break;
		case 4:
			mover4(buffer, bmp, anchoform, altoform);
			break;
		case 5:
			mover5(buffer, bmp, anchoform, altoform);
			break;
		case 6:
			mover6(buffer, bmp, anchoform, altoform);
			break;
		case 7:
			mover7(buffer, bmp, anchoform, altoform);
			break;
		}
		x += dx;
		y += dy;
		dibujar(buffer, bmp);
	}
	
	void mover0(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			indiceY = 3;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -15;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			indiceY = 0;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 15; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			indiceY = 1;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -15; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			indiceY = 2;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 15; //Traslado hacia la derecha en X
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
	}
	void mover1(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			indiceY = 3;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -15;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			indiceY = 0;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 15; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			indiceY = 1;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -15; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			indiceY = 2;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 15; //Traslado hacia la derecha en X
			dy = 0;
			ultimaTecla = Derecha;
			break;

		case Ninguna:
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case Arriba:
				indiceX = 3;
				indiceY = 3;
				break;
			case Abajo:
				indiceX = 3;
				indiceY = 0;
				break;
			case Izquierda:
				indiceX = 3;
				indiceY = 1;
				break;
			case Derecha:
				indiceX = 3;
				indiceY = 2;
				break;
			}
			break;
		}
	}
	void mover2(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			indiceY = 3;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -15;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			indiceY = 0;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 15; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			indiceY = 1;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -15; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			indiceY = 2;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 15; //Traslado hacia la derecha en X
			dy = 0;
			ultimaTecla = Derecha;
			break;

		case Ninguna:
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case Arriba:
				indiceX = 6;
				indiceY = 3;
				break;
			case Abajo:
				indiceX = 6;
				indiceY = 0;
				break;
			case Izquierda:
				indiceX = 6;
				indiceY = 1;
				break;
			case Derecha:
				indiceX = 6;
				indiceY = 2;
				break;
			}
			break;
		}
	}
	void mover3(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			indiceY = 3;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -15;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			indiceY = 0;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 15; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			indiceY = 1;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -15; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			indiceY = 2;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 15; //Traslado hacia la derecha en X
			dy = 0;
			ultimaTecla = Derecha;
			break;

		case Ninguna:
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case Arriba:
				indiceX = 9;
				indiceY = 3;
				break;
			case Abajo:
				indiceX = 9;
				indiceY = 0;
				break;
			case Izquierda:
				indiceX = 9;
				indiceY = 1;
				break;
			case Derecha:
				indiceX = 9;
				indiceY = 2;
				break;
			}
			break;
		}
	}
	void mover4(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			indiceY = 7;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -15;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			indiceY = 4;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 15; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			indiceY = 5;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -15; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			if (indiceX >= 0 && indiceX < 2) { indiceX++; }
			else indiceX = 0;
			indiceY = 6;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 15; //Traslado hacia la derecha en X
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
				indiceY = 7;
				break;
			case Abajo:
				indiceX = 0;
				indiceY = 4;
				break;
			case Izquierda:
				indiceX = 0;
				indiceY = 5;
				break;
			case Derecha:
				indiceX = 0;
				indiceY = 6;
				break;
			}
			break;
		}
	}
	void mover5(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			indiceY = 7;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -15;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			indiceY = 4;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 15; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			indiceY = 5;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -15; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			if (indiceX >= 3 && indiceX < 5) { indiceX++; }
			else indiceX = 3;
			indiceY = 6;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 15; //Traslado hacia la derecha en X
			dy = 0;
			ultimaTecla = Derecha;
			break;

		case Ninguna:
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case Arriba:
				indiceX = 3;
				indiceY = 7;
				break;
			case Abajo:
				indiceX = 3;
				indiceY = 4;
				break;
			case Izquierda:
				indiceX = 3;
				indiceY = 5;
				break;
			case Derecha:
				indiceX = 3;
				indiceY = 6;
				break;
			}
			break;
		}
	}
	void mover6(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			indiceY = 7;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -15;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			indiceY = 4;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 15; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			indiceY = 5;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -15; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			if (indiceX >= 6 && indiceX < 8) { indiceX++; }
			else indiceX = 6;
			indiceY = 6;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 15; //Traslado hacia la derecha en X
			dy = 0;
			ultimaTecla = Derecha;
			break;

		case Ninguna:
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case Arriba:
				indiceX = 6;
				indiceY = 7;
				break;
			case Abajo:
				indiceX = 6;
				indiceY = 4;
				break;
			case Izquierda:
				indiceX = 6;
				indiceY = 5;
				break;
			case Derecha:
				indiceX = 6;
				indiceY = 6;
				break;
			}
			break;
		}
	}
	void mover7(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoform, int altoform) {
		switch (direccion) //Animacion de la imagen
		{
		case Arriba:
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			indiceY = 7;
			if (y + dy <= 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = -15;//Movimiento hacia arriba en Y
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Abajo:
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			indiceY = 4;
			if (y + dy < 3 || y + alto + dy > altoform - 3) dy *= -1;
			else dy = 15; //Movimiento hacia abajo en Y
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			indiceY = 5;
			if (x + dx < 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = -15; //Movimiento hacia la izquierda en X
			dy = 0;
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			if (indiceX >= 9 && indiceX < 11) { indiceX++; }
			else indiceX = 9;
			indiceY = 6;
			if (x + dx <= 3 || x + ancho + dx > anchoform - 3) dx *= -1;
			else dx = 15; //Traslado hacia la derecha en X
			dy = 0;
			ultimaTecla = Derecha;
			break;

		case Ninguna:
			dx = 0;
			dy = 0;
			switch (ultimaTecla)
			{
			case Arriba:
				indiceX = 9;
				indiceY = 7;
				break;
			case Abajo:
				indiceX = 9;
				indiceY = 4;
				break;
			case Izquierda:
				indiceX = 9;
				indiceY = 5;
				break;
			case Derecha:
				indiceX = 9;
				indiceY = 6;
				break;
			}
			break;
		}
	}
};
