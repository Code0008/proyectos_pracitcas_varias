#pragma once
#include<iostream>
#include <ctime>
#include <string>

using namespace std;




// u202412000
// 0123456789
struct alumno {
	string codigo;
	int numero_creditos;
	int promeido_acumulado;
};

alumno* alumnos = new alumno[50];

void generar_datos(int n_alumnos=50) {
	for (int i = 0; i < n_alumnos; i++) {
		alumnos[i].codigo.append("u20241");
		alumnos[i].codigo.append(to_string(rand() % 9000+1000));
		alumnos[i].numero_creditos = rand() % 30;
		alumnos[i].promeido_acumulado = rand() % 20;
	}
	cout << "|Codioalumno\tCreditos\tPormedio\tAprobado\tVerifCreditos"<< endl;
	for (int i = 0; i < n_alumnos; i++) {
		cout <<endl << "____________________________________________________________________________________" << endl;
		cout << "|" << alumnos[i].codigo << "|\t  " << alumnos[i].numero_creditos << "\t\t " << alumnos[i].promeido_acumulado;
		if (alumnos[i].promeido_acumulado >= 13) { cout << "\t\t|Aprobado|"; }
		else { cout << "\t\t|Desaprobado|"; }
		if (alumnos[i].numero_creditos > 5) { cout << "\t|MAS DE 15 CREDITOS|"; }

	}
}

