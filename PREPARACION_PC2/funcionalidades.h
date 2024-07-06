#pragma once
#include <iostream>
#include <stdio.h>
#include <ctime>

struct Alumno {
    int tema;
    int puntaje;
};
Alumno* alumnos = new Alumno[30];

using namespace std;
int promedio = 0;
extern void GenerarMostrarDatos() {
    srand(time(NULL));
    for (int i = 0; i < 30; i++) {
        alumnos[i].tema = rand() % 3+1;
        alumnos[i].puntaje = rand() % 50;
        promedio += alumnos[i].puntaje;{{} }
    }
    for (int i = 0; i < 30; i++) {
        cout << endl;
        cout << "Alumno: " << i + 1 << endl << "tema: " << alumnos[i].tema << endl << "Puntaje: " << alumnos[i].puntaje << endl;
        cout << "________________";
    }

}

extern void Lista_EncimaDelPromedio() {
    promedio = promedio / 30;
    cout << "---LISTA ALUMNOS ENCIMA DEL PROEMDIO--";
    cout << endl;
    for (int i = 0; i < 30; i++) {
        if (alumnos[i].puntaje >= promedio) {
            cout << endl;
            cout << "Alumno: " << i + 1 << endl << "Tema: " << alumnos[i].tema << endl << "Nota: " << alumnos[i].puntaje;
            cout <<endl<< "__________";
        }
    }
}

extern void Devuelve_Mayor() {
    for (int i = 0; i < 30; i++) {
        int current = alumnos[i].puntaje;
        int tema = alumnos[i].tema;
        int j = i - 1;

        while (j >= 0 && alumnos[j].puntaje > current) {
            alumnos[j + 1].puntaje = alumnos[j].puntaje;
            alumnos[j + 1].tema = alumnos[j].tema;
            j -= 1;
        }   

        alumnos[j + 1].tema = tema;
        alumnos[j + 1].puntaje = current;
    }cout << endl;
    cout << "Puntaje\tTema";
    for (int i = 29; i > 0; i--) {
        cout << endl << "_____________" << endl;
        cout << alumnos[i].puntaje <<"\t    " << alumnos[i].tema;
    
    }


}