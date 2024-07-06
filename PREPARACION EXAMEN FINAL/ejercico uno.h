#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
using namespace std;

struct rubro {
	int codigo=0;
	string descripcion;
	string categoria;
};
struct empresa {
	long long RUC;
	char Distrito;
	char tipo;
	int fecha_evaluacion;
};


bool valid_distrito(char selec) {
	char distritos[5] = { 'I', 'S', 'J', 'B', 'L' };
	for (int i = 0; i < 5; i++) { 
		if (distritos[i] == selec) {
			return true;
		}
	}
	return false;
}

bool valid_rubro_code(rubro rubros[], int codigo_rubro) {
	for (int i = 0; i < 100; i++) {
		if (codigo_rubro == rubros[i].codigo) {
			return false;
		}
	}
	return true;
}
bool valid_ruc_empresa(empresa empresas[], long long RUC) {
	for (int i = 0; i < 100; i++) {
		if (empresas[i].RUC == RUC) {
			return false;
		}
	}
	return true;
}

void get_data_empresa(empresa empresas[], int indide_empresa) {
	long long to_valid = 0;
	while (cin >> to_valid) {
		cout << "Ingrese el RUC de su empresa " << endl;

		if (to_valid >= 10000000000 && to_valid <= 99999999999) {
			break;
		}
		else {
			cout << "RUC MAL INGRESADOP..." << endl;
		}

	}
	char empresa_seleccion;
	while (true) {
		cout << "Ingrese el tipo de empresa: \nP: Pequeña\nM: Mediana\nG: Grande" << endl;
		empresa_seleccion = _getch();
		empresa_seleccion = toupper(empresa_seleccion);
		if (empresa_seleccion == 'G' || empresa_seleccion == 'M' || empresa_seleccion == 'P') {
			break;
		}
		else {
			cout << "TIPO EMPRESA MAL INGRESADO..." << endl;

		}

	}
	char distrito_entry;
	while (true) {
		cout << "Ingrese el tipo de empresa: \nI:San isidro \nS: San Borja \nJ: Jesus Maria\n B: Brena \n L: Cercado de lima" << endl;
		distrito_entry = _getch();
		distrito_entry = toupper(distrito_entry);
		if (valid_distrito(distrito_entry)) {
			break;
		}
		else {
			cout << "DISTRITO MAL INGRESADO..." << endl;

		}
	}




}


void get_data_rubro(rubro rubros[], int indice_rubro) {

	int codigo;
	while (true)
	{
		cout << "Ingrese el codigo " << endl;
		if (codigo >= 100 && codigo <= 1000) {

			break;
		}
		else {
			cout << "DISTRITO MAL EL CODIGO DE RUBRO..." << endl;

		}
	}
	string texto;
	while (true) {
		cout << "Ingrese la descripcion del rubro " << endl;
		getline(cin, texto);
		if (texto.length() > 1) {
			rubros[]
		}
	}


}

void call_solucion() {
	int indice_agregar_empresa = 0;
	int indice_agregar_rebro = 0;
	empresa* empresas = new empresa[100];
	rubro* rubros = new rubro[100];
	get_data_empresa(empresas, indice_agregar_empresa);
	get_data_rubro(rubros, indice_agregar_rebro);



}