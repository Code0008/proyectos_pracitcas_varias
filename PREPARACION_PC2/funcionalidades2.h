#pragma once
#include <iostream>
#include <stdio.h>
#include <ctime>

using namespace std;

struct elector {
	int eleccion;
	int edad;
};

elector* electores = new elector[100];
int voto_a = 0, voto_b = 0, viciado = 0, n_electore;

extern void generar_datos(int n_electores=100) {
	srand(time(NULL));
	for (int i = 0; i < n_electores; i++) {
		electores[i].edad = rand() % 82 + 18;
		electores[i].eleccion = rand() % 3+1;
		switch (electores[i].eleccion)
		{
		case 1: voto_a++; break;
		case 2: voto_b++; break;
		case 3: viciado++; break;
		default:break;
		}
	}
	n_electore = n_electores;
	cout << "Votantes de A: " << voto_a << endl;
	cout <<"Votantes de B: " << voto_b << endl;
	cout << "Viciados: " << viciado << endl;
}


extern void mas_longevo() {
	int maximo = 0, indice = 0;
	for (int i = 0; i < n_electore; i++) {
		if (electores[i].edad > maximo) {
			maximo = electores[i].edad;
			indice = i;
		}
	}

	cout << "El elector mas vieejo tiene la edad de: " << electores[indice].edad << endl;
}
