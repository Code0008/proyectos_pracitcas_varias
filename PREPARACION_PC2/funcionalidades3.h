#pragma once
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <conio.h>

using namespace std;


struct alumno {
	char resp_gripe;
	char resp_tos;
	int peso;
};

alumno* estudiante = new alumno[20];

int n_alumns, count_gripe = 0, count_tos = 0;

extern void genera_y_muestra(int n_alumnos=20) {
	srand(time(NULL));
	for (int i = 0; i < n_alumnos; i++) {
		int var_to_game = rand(), game = rand();
		estudiante[i].peso = rand() % 31 + 30;
		if (var_to_game % 2 == 0) { estudiante[i].resp_gripe = 'S'; count_gripe++; }
		if (var_to_game % 2 != 0) { estudiante[i].resp_gripe = 'N'; }
		if (game % 2 == 0) { estudiante[i].resp_tos = 'S'; count_tos++; }
		if (game % 2 != 0) { estudiante[i].resp_tos = 'N'; }

	}
	n_alumns = n_alumnos;
}

extern void porcentaje_gripe() {
	cout <<"Porcentaje en relacion a los que tienen gripe: " << count_gripe / ((double)n_alumns / 100);
}
extern void porcentaje_tos() {
	cout << "Porcentaje en relacion a los que tienen tos: " << count_tos / ((double)n_alumns / 100);
}

extern void promedio_pesos_enfermos() {
	int promedio_pesos = 0;
	for (int i = 0; i < n_alumns; i++) {
		if (estudiante[i].resp_gripe == 'S' || estudiante[i].resp_tos == 'S') {
			promedio_pesos += estudiante[i].peso;
		}
	}
	cout << "El promedio del peso de los alumnos enfermos es: " << promedio_pesos/ n_alumns << endl;
}



extern void listado_ordenado() {
	int current_peso = 0;
	char current_resp_gripe;
	char current_resp_tos;

	for (int i = 0; i < n_alumns; i++) {
		current_peso = estudiante[i].peso;
		current_resp_gripe = estudiante[i].resp_gripe;
		current_resp_tos = estudiante[i].resp_tos;
		int j = i - 1;

		while (j >= 0 && estudiante[j].peso > current_peso) {
			estudiante[j + 1].peso = estudiante[j].peso;
			estudiante[j + 1].resp_gripe = estudiante[j].resp_gripe;
			estudiante[j + 1].resp_tos = estudiante[j].resp_tos;
			j -= 1;
		}
		estudiante[j + 1].peso = current_peso;
		estudiante[j + 1].resp_tos = current_resp_tos;
		estudiante[j + 1].resp_gripe = current_resp_gripe;
	}
	cout << "|Peso\tGripe\tTos |";
	for (int i = n_alumns-1; i >= 0; i--) {
		cout <<endl<< "|-------------------|" << endl;
		cout <<"|" << estudiante[i].peso << "\t" << estudiante[i].resp_gripe << "\t" << estudiante[i].resp_tos << "   |";

	}
}