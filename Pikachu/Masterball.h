#pragma once
#include "Entidad.h"

class Masterball : public Entidad {
private:
	int dx, dy;
	bool PikachuAtrapado;
	int contLimite;
public:
	Masterball() {}

	Masterball(int x, int y) : Entidad (x,y) {
		dx = 4;
		dy = 4;
		ancho = 92;
		alto = 82;
		PikachuAtrapado = false;
		contLimite = 0;
	}

	Masterball(int x, int y, int dx, int dy, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->ancho = ancho;
		this->alto = alto;
		indiceX = 0;
		indiceY = 0;
		PikachuAtrapado = false;
		contLimite = 0;
	}

	int getDX() { return dx; }
	int getDY() { return dy; }
	bool getPikachuAtrapado() { return PikachuAtrapado; }
	void setPikachuAtrapado(bool PikachuAtrapado) { this->PikachuAtrapado = PikachuAtrapado; }

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaSprite = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle escalarPersonaje = Rectangle(x, y, (int)(ancho * 0.3), (int)(alto * 0.3));
		buffer->Graphics->DrawImage(bmp, escalarPersonaje, areaSprite, GraphicsUnit::Pixel);

		indiceX++;
		if (indiceX == 2) indiceX = 0;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp, int anchoForm, int altoForm) {
		if (x + dx < 0 || x + dx + ancho > anchoForm) { 
			dx *= -1; 
			if (contLimite < 2) {
				contLimite++;
			}
			else {
				if (contLimite == 2) { //3 veces colisiono con el limite
					PikachuAtrapado = true;
					contLimite = 0;
				}
			}
		}

		if (y + dy <0 || y + dy + alto > altoForm) { 
			dy *= -1; 
			if (contLimite < 2) {
				contLimite++;
			}
			else {
				if (contLimite == 2) { //3 veces colisiono con el limite
					PikachuAtrapado = true;
					contLimite = 0;
				}
			}
		}
		x += dx;
		y += dy;

		dibujar(buffer, bmp);
	}
};
