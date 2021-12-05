#pragma once
#include "Triangulo.h"
#include <vector>

using namespace std;

class Controller {
private:
	vector<Triangulo*> arregloT;
public:
	Controller() {}
	~Controller() {}

	vector<Triangulo*> getArregloT() {
		return this->arregloT;
	}
	
	void addTriangulo() {
		arregloT.push_back(new Triangulo(10, 40, 40, 50, 50, 10));
	}

	void moverFiguras(Graphics^ gr) {
		for (int i = 0; i < arregloT.size(); i++) {
			arregloT[i]->mover(gr);
		}
	}
};
