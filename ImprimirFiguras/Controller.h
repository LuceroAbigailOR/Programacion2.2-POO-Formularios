#pragma once
#include "Elipse.h"
#include "CRectangulo.h"
#include "Linea.h"
#include <vector>

using namespace std;

class Controller {
private:
	vector<Elipse*> arrE;
	vector<CRectangulo*> arrR;
	vector<Linea*> arrL;
public:
	Controller() {}
	~Controller() {}

	void addElipse(Elipse* e) {
		arrE.push_back(e);
	}

	void addCRectangulo(CRectangulo* r) {
		arrR.push_back(r);
	}

	void addLinea(Linea* l) {
		arrL.push_back(l);
	}

	void drawEverything(Graphics^ g, Color color) {
		for each (Elipse * e in arrE) {
			e->draw(g, color);
		}

		for each (CRectangulo * r in arrR) {
			r->draw(g, color);
		}

		for each (Linea* l in arrL) {
			l->draw(g, color);
		}
	}
};
