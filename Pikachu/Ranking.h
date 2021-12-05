#pragma once
#include "iostream"
#include "fstream"
#include "vector"
#include "Jugador.h"

class Ranking
{
private:
	vector<Jugador*> ranking;
public:
	Ranking() {}
	~Ranking() {}
	vector <Jugador*> getranking() {
		return this->ranking;
	}

	void setranking(vector<Jugador*> ranking) {
		this->ranking = ranking;
	}
	void agregar_elemento(Jugador* jugador) {
		ranking.push_back(jugador);
	}

	void guardar_partida()
	{
		ofstream file_ranking;
		file_ranking.open("Ranking.txt", ios::out);

		int cant_jugadores;
		cant_jugadores = ranking.size();

		if (file_ranking.is_open()) {
			file_ranking << cant_jugadores << endl;
			for (int i = 0; i < cant_jugadores; i++) {
				file_ranking << ranking[i]->getpuntos() << endl;
			}
		}
		file_ranking.close();
	}
	void cargar_partida() {
		ifstream file_ranking;
		file_ranking.open("Ranking.txt", ios::in);
		int cant_jugadores;
		int puntos;
		Ranking* arrTempRanking = new Ranking();

		if (file_ranking.is_open()) {
			file_ranking >> cant_jugadores;
			for (int i = 0; i < cant_jugadores; i++) {
				file_ranking >> puntos;
				Jugador* jugadorTemp = new Jugador(puntos);
				arrTempRanking->agregar_elemento(jugadorTemp);
			}

			setranking(arrTempRanking->getranking());
			file_ranking.close();
		}
	}
};
