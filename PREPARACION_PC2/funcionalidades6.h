
#include<iostream>
#include <ctime>


using namespace std;

int capture_time() {
	tm timepo;
	time_t timestamp;
	int sec;
	time(&timestamp);
	localtime_s(&timepo, &timestamp);
	sec = timepo.tm_sec;
	return sec;
}
int  capture_time() {
	time_t ahora = time(0);
	return ahora;
}

struct Banco_Cliente {
	int cliente_id;
	char tipo_cliente;
	int numero_tramites;
	int tiempo_tramite;

};

Banco_Cliente* clientes = new Banco_Cliente[50];

int count_tramites;

void Generar_Datos() {
	srand(time(NULL));
	int inicio, finale, rand1;
	for (int i = 0; i < 50; i++) {
		rand1 = rand();
		clientes[i].cliente_id = i;
		inicio = capture_time();
		if (rand1 % 2 == 0) { clientes[i].tipo_cliente = 'V'; }
		else { clientes[i].tipo_cliente = 'N'; }
		clientes[i].numero_tramites = rand() % 5+1;
		finale = capture_time();
		clientes[i].tiempo_tramite = finale - inicio;
	}
}

void max_time() {
	int maximo = 0, indice = 0;
	for (int i = 0; i < 50; i++) {
		if (maximo < clientes[i].tiempo_tramite) {
			maximo = clientes[i].tiempo_tramite;
			indice = i;
		}
	}
	cout << "El cliente que tuvo el maximo timepo en ventallia fue " << clientes[indice].cliente_id << endl;
}


void ordenar_base_al_tramite() {
	for (int i = 0; i < 50; i++) {
		int current_numero_tramite_game = clientes[i].numero_tramites;
		int current_id = clientes[i].cliente_id;
		char current_tipo_cliente = clientes[i].tipo_cliente;
		int current_tiempo_tramite = clientes[i].tiempo_tramite;
		int j = i - 1;

		while (j >= 0 && clientes[j].numero_tramites > current_numero_tramite_game) {
			clientes[j + 1].cliente_id = clientes[i].cliente_id;
			clientes[j + 1].numero_tramites = clientes[j].numero_tramites;
			clientes[j + 1].tipo_cliente = clientes[j].tipo_cliente;
			clientes[j + 1].tiempo_tramite = clientes[j].tiempo_tramite;
			j -= 1;
		}
		clientes[j + 1].cliente_id = current_id;
		clientes[j + 1].numero_tramites = current_numero_tramite_game;
		clientes[j + 1].tipo_cliente = current_tipo_cliente;
		clientes[j + 1].tiempo_tramite = current_tiempo_tramite;
	}
	cout << "ID\tNUMERO_TRAMITE\tTIPO_CLIENTE\tTIEMPO_CLIENTE"<<endl;
	for (int i = 0; i < 50; i++) {
		cout << clientes[i].cliente_id << "\t" << clientes[i].numero_tramites << " \t\t" << clientes[i].tipo_cliente << "\t\t" << clientes[i].tiempo_tramite << endl;
	}
}
