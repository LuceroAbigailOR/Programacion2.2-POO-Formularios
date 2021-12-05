#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace System;
using namespace std;

class Configuracion {
private:
	ofstream EscribirArchivo;
	ifstream LeerArchivo;
	string texto;

	int x, y;
	int contPokeball, contUltraball, contSuperball, contMasterball;

public:
	Configuracion() {}
	~Configuracion() {}

	void leerInformacion() {
		LeerArchivo.open("configuracion.txt", ios::in);

		if (LeerArchivo.fail()) {
			LeerArchivo.close();

			EscribirArchivo.open("configuracion.txt", ios::out); //Creates the new txt
			EscribirArchivo << "200" << endl; //x
			EscribirArchivo << "150" << endl; //y
			EscribirArchivo << "10" << endl;  //contPokeball
			EscribirArchivo << "3" << endl;   //contUltraball
			EscribirArchivo << "4" << endl;   //contSuperball
			EscribirArchivo << "1" << endl;   //contMasterball
			EscribirArchivo.close();

			LeerArchivo.open("configuracion.txt", ios::in);
		}

		getline(LeerArchivo, texto); x = atoi(texto.c_str());
		getline(LeerArchivo, texto); y = atoi(texto.c_str());
		getline(LeerArchivo, texto); contPokeball = atoi(texto.c_str());
		getline(LeerArchivo, texto); contUltraball = atoi(texto.c_str());
		getline(LeerArchivo, texto); contSuperball = atoi(texto.c_str());
		getline(LeerArchivo, texto); contMasterball = atoi(texto.c_str());

		LeerArchivo.close();
	}

	int getX() { return x; }
	int getY() { return y; }
	int getcontPokeball() { return contPokeball; }
	int getcontUltraball() { return contUltraball; }
	int getcontSuperball() { return contSuperball; }
	int getcontMasterball() { return contMasterball; }

};
