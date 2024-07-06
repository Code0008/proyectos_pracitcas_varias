#pragma once
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <conio.h>

using namespace std;

struct Encuestado {
	int edad;
	int aprovacion;
	char departamento;
};

Encuestado* encuestados = new Encuestado[100];

int count_puno = 0, count_cajachos=0, n_encuestados;


 extern void generar_random(int n_encuestado=100) {
	n_encuestados = n_encuestado;
	srand(time(NULL));
	for (int i = 0; i < n_encuestado; i++) {
		int random = rand() % 100;
		while (true) {
			encuestados[i].edad = rand() % 83+17;
			if (encuestados[i].edad > 17 && encuestados[i].edad < 99) { break; }
		}
		encuestados[i].aprovacion = rand() % 5 + 1;
		if (random % 2 == 0) { encuestados[i].departamento = 'P'; count_puno++; }
		else if (random % 2 != 0) { encuestados[i].departamento = 'C'; count_cajachos++; }
		if(random>50 && random <100) { encuestados[i].departamento = 'L'; }
	}
}

extern void Cajachos_Punenos() {
	cout << "Participaron: " << count_puno << " Puneños"<<endl;
	cout << "Participaron: " << count_cajachos << " Cajacho" << endl;
}

extern void Ordenar_Y_Mostrar() {
	for (int i = 0; i < n_encuestados; i++) {
		int current_edad = encuestados[i].edad;
		int current_aprovacion = encuestados[i].aprovacion;
		char current_departamento = encuestados[i].departamento;
		int j = i - 1;

		while (j >= 0 && encuestados[j].edad > current_edad) {
			encuestados[j + 1].edad = encuestados[j].edad;
			encuestados[j + 1].aprovacion = encuestados[j].aprovacion;
			encuestados[j + 1].departamento = encuestados[j].departamento;
			j -= 1;
		}
		encuestados[j + 1].edad = current_edad;
		encuestados[j + 1].aprovacion = current_aprovacion;
		encuestados[j + 1].departamento = current_departamento;
	}

	cout << "Edad\t NivelSatisfac\tDepartamento";
	for (int i = n_encuestados-1; i > 0; i--) {
		cout << endl << "_____________________________________|" << endl;
		cout << encuestados[i].edad << "\t\t" << encuestados[i].aprovacion << "\t\t" << encuestados[i].departamento;
	}
}