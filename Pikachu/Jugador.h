#pragma once
using namespace std;
class Jugador
{
private:
	int puntos;
public:
	Jugador() {
		puntos = 0;
	}
	Jugador(int puntos) {
		this->puntos = puntos;
	}
	~Jugador() {}
	int getpuntos() { return puntos; }
	void setpuntos(int puntos) { this->puntos = puntos; }
};
