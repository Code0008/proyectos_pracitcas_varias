#pragma once
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <string>
#include <cctype>
using namespace std;


int** ruta = new int* [15];




void see_matriz() {

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << " " << ruta[i][j] << " ";
		}cout << endl;
	}
}

void make_matriz() {
	for (int i = 0; i < 15; i++) {
		ruta[i] = new int[15];
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			ruta[i][j] = 0;
		}
	}

}



void go_right(int posicionx) {
	for (int i = 0; i < 1; i++) {
		for (int j = posicionx; j < 15; j++) {
			ruta[i][j]=1;
		}
	}
}

void go_down(int posicionx, int posiciony) {
	for (int i = posicionx; i < 15; i++) {
		ruta[i][posiciony] = 1;
	}
}

void go_left(int posicionx) {
	for (int i = posicionx; i > 0; i--) {
		ruta[12][15-i] = 1;
	}
}

void go_up(int posicionx, int posiciony) {
	for (int i = posicionx; i>0 ; i--) {
		ruta[15-i][posiciony] = 1;
	}
}



void movimiento_simulado() {
	make_matriz();
	srand(time(NULL));
	char lista_movimiento[4] = { 'U', 'D', 'R', 'L' };
	int count=0;
	int pas_select = 0;
	while (count<=4) {
		int rand_select = rand() % 4;
		while (pas_select == rand_select) {
			rand_select = rand() % 4;
		}
		pas_select = rand_select;
		char select = lista_movimiento[rand_select];
		switch (toupper(select)) {
		case  'U': cout << "go up" << endl; go_up(6,6);  break;
		case 'D':cout << "go down" << endl; go_down(3,3); break;
		case 'R': cout << "go right" << endl; go_right(2); break;
		case 'L': cout << "go left" << endl; go_left(8); break;
		default: break;
		}
		see_matriz();
		count++;
		cout << "//////////////////////" << endl;
	}

}
