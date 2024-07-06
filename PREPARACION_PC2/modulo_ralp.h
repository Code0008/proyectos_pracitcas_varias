#include <ctime>
#include <iostream>

using namespace std;

extern void tamano_pene() {


	srand(time(NULL));
	cout << "Le mite: " << rand() % 5<<endl;
}

extern void estetica() {
	cout << '_' * 23;

}
/*#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
using namespace std;

/*int arr[] = {5534,7123,8342,4,34,23,213,123,342};
int n = sizeof(arr) / sizeof(arr[0]);



int main() {
	for (int i = 0; i < n; i++) {
		int current = arr[i];
		int j = i - 1;

		while (j>=0 && arr[j]>current) {
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = current;
	}
	for (int i = 0; i < n; i++) { cout << arr[i] << " "; }

	int max = INT_MAX,indice;
	for (int i = 0; i < n; i++) {
		if (arr[i] < max) {
			max = arr[i];
			indice = i;
		}
	}
	cout << arr[indice];
}*/


/*class Student {
private:
	string name;
	int edad;
	double nota;
public:
	Student(string name_c, int edad_c, double nota_c=NULL) { // __init__
		this->name = name_c;
		this->edad = edad_c;
		this->setNota(nota_c);
	}

	inline bool aprobado();
	inline void __str__() { cout << "Nombre: " << this->name << endl << "Edad: " << this->edad << endl << "Nota: " << this->nota; }
	inline void __str__() const { cout << "Nombre: " << this->name << endl << "Edad: " << this->edad << endl << "Nota: " << this->nota; } // se ejecutara 
																													// Cuando el objeto sea constante


	inline ~Student() { /*destructor cout << "Destruido objeto" <<endl; }

	string getNombre() { return this->name; }
	int getEdad() { return this->edad; }
	double getNota() { return this->nota; }
	
	void setNota(double nota){
		if (nota) {this->nota = nota;}else { this->nota = NULL; }
	}
};

inline bool Student::aprobado(){if (nota >= 5) {return true;}else { return false;}};


int main() {
	Student Estudiante1("Peruano", 2);
	Estudiante1.__str__(); cout << endl;
	const Student Estudiante2("Perukistano", 31232);
	Estudiante2.__str__(); cout << endl;
}



int nproveedores = 0;
int* provedores = new int[nproveedores]; int promedio;


void ingresar_datos() {
	cout << "Ingrse el numero de proveedores " << endl; cin >> nproveedores;
	for (int i = 0; i < nproveedores; i++) {
		cout << "Ingrese el monto: "; cin >> provedores[i];
		promedio += provedores[i];
	}
}

void calcular_promedio() {
	promedio = promedio / nproveedores;
}


int mayor_compras() {
	int max = 0, min = 0, indice = 0;
	for (int i = 0; i < nproveedores; i++) {
		if (provedores[i] > max) {
			max = provedores[i];
			indice = i;
		}
	}
	return indice;
}

int menor_compras() {
	int min = INT_MAX, indice = 0;
	for (int i = 0; i < nproveedores; i++) {
		if (provedores[i] < min) {
			min = provedores[i];
			indice = i;
		}
	}
	return indice;
}

void ordenamiento_tipo_sort() {
	int current = 0, j = 0;
	for (int i = 0; i < nproveedores; i++) {
		current = provedores[i];
		j = i - 1;

		while (j >= 0 && provedores[j] > current) {
			provedores[j + 1] = provedores[j];
			j -= 1;
		}

		provedores[j + 1] = current;
	}
}

void mostrar_datos() {
	for (int i = 0; i < nproveedores; i++) {
		cout << " [" << provedores[i] << "] ";
	}
}


int main() {
	ingresar_datos(); calcular_promedio();
	cout << "Prmedio: " << promedio << endl;
	cout << "Mayor compras: " << provedores[mayor_compras()] << endl;
	cout << "Menor compras: " << provedores[menor_compras()] << endl;
	ordenamiento_tipo_sort();
	mostrar_datos();
}*/
/*#include <iostream>
#include <stdio.h>
#include "modulo_ralp.h"
#include <string>
#include <conio.h>
using namespace std;


struct direccion {
	string direccion;
	string distrito;
	string provincia;
};

int ntrabajadores, promedio = 0;
struct trabajador {
	string nombre;
	int edad;
	char sexo;
	direccion inforacion_direccion;
	int venta;
} trabajadores[100]; 



void registrar_trabajador() {
	for (int i = 0; i < ntrabajadores; i++) {
		cout << "Registrar Nombre: " << endl; getline(cin, trabajadores[i].nombre); cin.ignore(); 
		cout << "Registrar edad: " << endl; cin >> trabajadores[i].edad; cin.ignore();
		cout << "Registrar sexo: " << endl; cin >> trabajadores[i].sexo; cin.ignore();
		cout << "Registrar direccion: " << endl; getline(cin, trabajadores[i].inforacion_direccion.direccion);  cin.ignore();
		cout << "Registrar distrito: " << endl; getline(cin, trabajadores[i].inforacion_direccion.distrito); cin.ignore();
		cout << "Registrar provincia: " << endl; getline(cin, trabajadores[i].inforacion_direccion.provincia);  cin.ignore();
		cout << "Registrar venta: " << endl; cin >> trabajadores[i].venta; cin.ignore();
		promedio += trabajadores[i].venta;
	}
}

void venta_promedio() {
	cout << "El promedio: " << promedio / ntrabajadores << endl;
}

void venta_mayor() {
	int mayor = 0, indice=0;
	for (int i = 0; i < ntrabajadores; i++) {
		if (trabajadores[i].venta > mayor) {
			mayor = trabajadores[i].venta;
			indice = i;
		}
	}
	cout << "EL QUE TIENE LA MAYOR VENTA ES: " << trabajadores[indice].nombre; 
}

void venta_menor() {
	int menor = INT_MAX, indice = 0;
	for (int i = 0; i < ntrabajadores; i++) {
		if (trabajadores[i].venta < menor) {
			menor = trabajadores[i].venta;
			indice = i;
		}
	}
	cout << "EL QUE TIENE LA menor VENTA ES: " << trabajadores[indice].nombre;
}

void ordenar_edad() {
	int* edades = new int[ntrabajadores];

	for (int i = 0; i < ntrabajadores; i++) {
		edades[i] = trabajadores[i].edad;
	}

	int current = 0;
	int j;
	for (int i = 0; i < ntrabajadores; i++) {
		current = edades[i];
		j = i - 1;

		while (j >= 0 && edades[j] > current) {
			edades[j + 1] = edades[j];
			j -= 1;
		}

		edades[j + 1] = current;
	}

	for (int i = ntrabajadores-1; i > 0; i--) {
		cout << " [" << edades[i] << "] ";
	}
}

void mostrar_datos() {
	cout << endl;
	for (int i = 0; i < ntrabajadores; i++) {
		cout << "-----TRABAJADOR: "<<i+1<< "-----"<< endl;
		cout << "Nombre: "<< trabajadores[i].nombre << endl;
		cout << "Edad: " << trabajadores[i].edad << endl;
		cout << "Sexo: " << trabajadores[i].sexo << endl;
		cout << "Direccion: " << trabajadores[i].inforacion_direccion.direccion << endl;
		cout << "distrito: " << trabajadores[i].inforacion_direccion.distrito << endl;
		cout << "provincia: " << trabajadores[i].inforacion_direccion.provincia << endl;
		cout << "Venta: " << trabajadores[i].venta << endl;
	}
}


int main() {
	cout << "Ingrese el numero de trabajadores: "; cin >> ntrabajadores; cin.ignore(); cout << endl;
	registrar_trabajador();cout << endl;
	venta_promedio();cout << endl;
	venta_mayor();cout << endl;
	venta_menor(); cout << endl;
	ordenar_edad();cout << endl;
	mostrar_datos();
	return 0;
}*/