#include <iostream>
#include <math.h>
#include <string>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;

/* struct empresa {
	int ano_regis = 2024;
	long long RUC=0;
	char Distrito='P';
	char tipo='P';
	int fecha_evaluacion=0;
};

struct rubro {
	int codigo=0;
	string descripcion;
	string categoria;
		
};


long long  string_to_int(string cadena_inicial) {
	// string cadena = "421";  | 124
	// string cadena = "124";  | 421
	string cadena;

	for (int i = cadena_inicial.length()-1; i>=0; i--) {
		cadena += cadena_inicial[i];
	}

	long long newe = 0; 
	char list_ints[] = {'0','1','2','3','4','5','6','7','8','9'};
	for (int i =0; i<cadena.length()  ; i++) {
		for (int j = 0; j < 10; j++) {
			if (cadena[i] == 0) {
				newe += pow(10, i+1);
				break;
			}else if (cadena[i] == list_ints[j]) {
				newe += j * (pow(10, i));
				break;
			}
		}	
	}
	return newe;
}

bool verif_existencia_RUC(empresa empresas[], long long RUC_INGRESADO, int posicion_empresa) {
	if (posicion_empresa == 0) {
		return true;
	}
	for (int i = 0; i < posicion_empresa; i++) {
		if (empresas[i].RUC == RUC_INGRESADO) {
			return false;
		}
	}
	return true;
}

bool verif_codigo_rubro(rubro  rubros[], int codigo, int posicion_rubro) {
	if (posicion_rubro == 0) {
		return true;
	}
	for (int i = 0; i < posicion_rubro; i++) {
		if (rubros[i].codigo == codigo) {
			return false;
		}
	}
	return true;
}

bool verif_distrito(char input) {
	char distrito[5] = { 'I','S','J','B','L' };
	for (int i = 0; i < 5; i++) {
		if (input == distrito[i]) {
			return true;
		}
	}
	return false;
}


void get_empresa(empresa empresas[100], int posicion_empresa) {
	string var_to_game;
	char selec;
	while (true) {
		cout << "Ingrese el RUC de la empresa" << endl;
		getline(cin, var_to_game);
		if (10000000000 <= string_to_int(var_to_game) && string_to_int(var_to_game) <= 99999999999 && verif_existencia_RUC(empresas, string_to_int(var_to_game), posicion_empresa)) {
			empresas[posicion_empresa].RUC = string_to_int(var_to_game);
			break;
		}
		cout << endl;
	}
	cout << endl;
	while (true) {
		cout << "Ingrese el distro que quiere registrar:\n Sani: I\nSanBorja: S\nJesusmari: J\n Brena:B\nCercado de lima:L" << endl;;
		selec = _getch(); selec = toupper(selec); cout << "-." << selec ;
		if (verif_distrito(selec)) {
			empresas[posicion_empresa].Distrito = selec;
			break;
		}
		cout << endl;
	}
	cout << endl;
	while (true) {
		cout << "Ingrese el tipo de empresa que quiere registrar:\nG: grande\nM: Mediana\nP: Pequena ";
		selec = _getch(); selec = toupper(selec); cout << selec << endl;
		if (selec == 'G' || selec == 'P' || selec == 'M') {
			empresas[posicion_empresa].Distrito = selec;
			break;
		}cout <<  endl;
	}
	while (true) {
		cout << "Ingrese fecha_evaluacion ";
		getline(cin, var_to_game);
		if (131 <= string_to_int(var_to_game) && string_to_int(var_to_game) <= 1231) {
			empresas[posicion_empresa].fecha_evaluacion = (int)string_to_int(var_to_game);
			break;
		} cout << endl;
	}
}

void get_rubro(rubro rubros[], int posicion_rubro) {
	string var_to_game;
	while (true) {
		cout << "Ingrese el CODIGO del rubro" << endl;
		getline(cin, var_to_game);
		if (100 <= (int)string_to_int(var_to_game) && (int)string_to_int(var_to_game) <= 1000 && verif_codigo_rubro(rubros, (int)string_to_int(var_to_game), posicion_rubro)) {
			rubros[posicion_rubro].codigo =(int)string_to_int(var_to_game);
			cout << endl;
			break;
		}
		cout << endl;
	}
	while (true) {
		cout << "Ingrese la categoria de la empresa ";
		getline(cin, var_to_game);
		if (var_to_game.length() >= 2) {
			rubros[posicion_rubro].categoria = var_to_game;
			cout << endl;
			break;
		}cout << endl;
	}
	while (true) {
		cout << "Ingrese la descripcion de la empresa ";
		getline(cin, var_to_game);
		if (var_to_game.length() >= 2) {
			rubros[posicion_rubro].descripcion = var_to_game;
			cout << endl;
			break;
		}cout << endl;
	}
}


void reporte_empresas_por_distrito(empresa  empresas[], int posicion_empresa) {
	int count_sani = 0, count_sanb = 0, count_jm = 0, count_b = 0, coutn_cl = 0;
	for (int i = 0; i < posicion_empresa; i++) {
		switch (empresas[i].Distrito)
		{
		case 'I':
			count_sani++;
			break;
		case 'S':
			count_sanb++;
			break;
		case 'J':
			count_jm++;
			break;
		case 'B':
			count_b++;
			break;
		case 'L':
			coutn_cl++;
			break;
		}
	}
	cout << "EMPRESAS EN SANI: " << count_sani << endl;
	cout << "EMPRESAS EN SAN BORJA: " << count_sanb << endl;
	cout << "EMPRESAS EN JESUS MARI: " << count_jm << endl;
	cout << "EMPRESAS EN BRENA: " << count_b << endl;
	cout << "EMPRESAS EN CERCADO DE LIMA: " << coutn_cl << endl;
}

empresa*  generar_data_empresas() {

	char distrito[5] = { 'I','S','J','B','L' };
	char tipos[3] = { 'G', 'P', 'M' };
	int anos[2] = { 2023,2024 };
	empresa* empresas = new empresa[100];
	for (int i = 0; i < 100; i++) {
		empresas[i].ano_regis = anos[rand() % 2];
		empresas[i].RUC = rand() % 10000000000 + (99999999999 - 10000000000);
		empresas[i].Distrito = distrito[rand() % 5];
		empresas[i].fecha_evaluacion = rand() % 131 + (1231 - 131);
		empresas[i].tipo = tipos[rand() % 3];
	}	

	return empresas;
}


void ver_empresas_pequenas(empresa data_empresas[]) {
	for (int i = 0; i < 100; i++) {
		if (data_empresas[i].tipo == 'P') {
			cout << "RUC: " << data_empresas[i].RUC << endl;
			cout << "Distrito: " << data_empresas[i].Distrito << endl;
			cout << "ANO DE REGISTRO: " << data_empresas[i].ano_regis << endl;
			cout << "fecha_evaluacion: " << data_empresas[i].fecha_evaluacion << endl;
			cout << "tipo: " << data_empresas[i].tipo << endl;
			cout << endl;
		}
	}
	
}
void ver_empresas_ordenadas_ascedentemente(empresa data_empresas[]) {
	char distrito[5] = { 'I','S','J','B','L' };
	for (int i = 0; i < 100; i++) {
		int current_distrito = (int)data_empresas[i].tipo;
		long long current_RUC = data_empresas[i].RUC;
		char current_tipo = data_empresas[i].tipo;
		int current_fecha = data_empresas[i].fecha_evaluacion;
		int current_ano = data_empresas[i].ano_regis;
		int j = i - 1;

		while (j >= 0 && current_distrito < (int)data_empresas[j].Distrito) {
			data_empresas[j + 1].tipo = data_empresas[j].tipo;
			data_empresas[j + 1].RUC = data_empresas[j].RUC;
			data_empresas[j + 1].fecha_evaluacion= data_empresas[j].fecha_evaluacion;
			data_empresas[j + 1].ano_regis = data_empresas[j].ano_regis;
			data_empresas[j + 1].Distrito = data_empresas[j].Distrito;
			j -= 1;
		}
		data_empresas[j + 1].tipo = current_tipo;
		data_empresas[j + 1].RUC = current_RUC;
		data_empresas[j + 1].ano_regis = current_ano;
		data_empresas[j + 1].fecha_evaluacion = current_fecha;
		data_empresas[j + 1].Distrito = (char)current_distrito;
	}
	for (int i = 100; i > 0; i--) {
		cout << "RUC: " << data_empresas[i].RUC << endl;
		cout << "Distrito: " << data_empresas[i].Distrito << endl;
		cout << "ANO DE REGISTRO: " << data_empresas[i].ano_regis << endl;
		cout << "fecha_evaluacion: " << data_empresas[i].fecha_evaluacion << endl;
		cout << "tipo: " << data_empresas[i].tipo << endl;
	}

}


int main() {
	empresa * empresas_reporte = generar_data_empresas();
	int posicion_empresa = 0;
	int posicion_rubro = 0;
	empresa* empresas = new empresa[100];
	rubro* rubros = new rubro[100];
	char selec;
	while (true) {
		cout << "BIENVENIDO AL MENU PRINCIPAL " << endl;
		cout << "1: REGISTRAR" << endl;
		cout << "2: reportes" << endl;
		selec = _getch(); 
		switch (selec)
		{
		case '1':
			while (true) {
				cout << "BIENVENIDO AL MENU REGISTRAR " << endl;
				cout << "1: EMPRESA" << endl;
				cout << "2: RUBRO" << endl;
				selec = _getch();
				switch (selec)
				{
				case '1':
					get_empresa(empresas, posicion_empresa);
					cout << "\nEMPRESA REGISTRADA EXITOSAMENTE;" << endl;
					posicion_empresa++;
					break;
				case '2':
					get_rubro(rubros, posicion_rubro);
					cout << "\nRUBRO REGISTRADA EXITOSAMENTE;" << endl;
					posicion_rubro++;
					break;
				}
				if (selec != '1' && selec != '2') {
					break;
				}
			}
			break;
		case '2':
			while (true) {
				cout << "BIENVENIDO AL MENU REGISTRAR " << endl;
				cout << "1. NUMERO DE EMPRESAS POR DISTRITO" << endl;
				cout << "2: MOSTRAR DATOS DE EMPRESAS QUE FUERON EVALUADAS EN LOS ULTIMOS DOS MESES" << endl;
				cout << "3: Mostrar un reporte de las empresas ordenadas ascendentemente por distrito" << endl;
				cout << "4: salir" << endl;
				selec = _getch();
				switch (selec)
				{
				case '1':
					reporte_empresas_por_distrito(empresas, posicion_empresa);
					break;
				case '2':
					ver_empresas_pequenas(empresas_reporte);
					break;
				case '3': 
					ver_empresas_ordenadas_ascedentemente(empresas_reporte);
					break;
				}
				if (selec == '4') {
					break;
				}
			}


			break;
		default:
			cout << "INGRESE UNA OPCION VALIDA POR FAVOR"<< endl;
			break;
		}
		cout << endl;
	}
}
long long  string_to_int(string cadena_inicial) {
	// string cadena = "421";  | 124
	// string cadena = "124";  | 421
	string cadena;

	for (int i = cadena_inicial.length() - 1; i >= 0; i--) {
		cadena += cadena_inicial[i];
	}

	long long newe = 0;
	char list_ints[] = { '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < cadena.length(); i++) {
		for (int j = 0; j < 10; j++) {
			if (cadena[i] == 0) {
				newe += pow(10, i + 1);
				break;
			}
			else if (cadena[i] == list_ints[j]) {
				newe += j * (pow(10, i));
				break;
			}
		}
	}
	return newe;
}


long long  string_to_int(string cadena_inicial) {
	// string cadena = "421";  | 124
	// string cadena = "124";  | 421
	string cadena;

	for (int i = cadena_inicial.length() - 1; i >= 0; i--) {
		cadena += cadena_inicial[i];
	}

	long long newe = 0;
	char list_ints[] = { '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < cadena.length(); i++) {
		for (int j = 0; j < 10; j++) {
			if (cadena[i] == 0) {
				newe += pow(10, i + 1);
				break;
			}
			else if (cadena[i] == list_ints[j]) {
				newe += j * (pow(10, i));
				break;
			}
		}
	}
	return newe;
}

int main() {
	int** matriz = make_data_matris();
	cout << string_to_int("2000") << endl;
}



int string_to_inter(string cadena_inicial) {
	string cadena_to_trate;
	for (int i = cadena_inicial.length() - 1; i >= 0; i--) {
		cadena_to_trate += cadena_inicial[i];
	}
	int nuevo=0;
	char list_ints[] = { '0','1','2','3','4','5','6','7','8','9' };
	for (int i = 0; i < cadena_to_trate.length(); i++) {
		for (int j = 0; j < 10; i++) {
			if (cadena_to_trate[i] == 0) {
				nuevo += pow(10, i + 1);
				break;
			}
			else if (cadena_to_trate[i] == list_ints[j]) {
				nuevo += j * (pow(10, i));
				break;
			}
		}
	}
	return nuevo;
}


void see_primos(int * data, int longitud) {

	int primos[] = { '2','3','5','7' };
	for (int i = 0; i < longitud; i+=2) {
		for (int j = 0; j < 4; j++) {
			if (char(data[i]) == primos[j]) {
			cout << "El indice " << i << " Es primo| Numero -> "<< char(data[i]) << endl;
			}		
		}
	}
}

bool is_capicua(string entry) {
	string generate_capicua;
	for (int i = entry.length() - 1; i >= 0; i--) {	generate_capicua += entry[i];}
	if (generate_capicua == entry) {return true;}
	else {return false;}
}

void see_capicuas(int * data, int longitud){
	int recorrer = longitud;
	while (recorrer > 0) {
	string current;
		if (recorrer - 5 < 0) {break;}
		for (int i = recorrer - 5; i < recorrer; i++) {current += char(data[i]);}
		if (is_capicua(current)) {cout << "Es capicua: " << current<<endl;}
		recorrer--;
	}
}

int main() {
	srand(time(NULL));
	while (true) {
		int n_data_to_trate = rand() % 15 + (45 - 15);
		int* data = new int[n_data_to_trate];
		for (int i = 0; i < n_data_to_trate; i++) {data[i] = 48 + rand() % (57 - 48);}
		see_primos(data, n_data_to_trate);
		see_capicuas(data, n_data_to_trate);
		cout << endl;
		for (int i = 0; i < n_data_to_trate; i++) {cout << " " << char(data[i]) << " ";	}
		cout << endl;
	}

}

struct cliente {
	int edad = 0;
	char sexo;
	char servicio;
	int nivel;
};

cliente * generate_cliente(int tamano){
	srand(time(NULL));
	cliente* clientes = new cliente[tamano];
	char sexos[] = { 'F', 'M' };
	char servicio[] = { 'P', 'O' , 'I'};
	for (int i = 0; i < tamano; i++) {
		clientes[i].edad = 1+ rand() % 45;
		clientes[i].sexo = sexos[rand() % 2];
		clientes[i].servicio = servicio[rand() % 2];
		clientes[i].nivel = 1 + rand() % 3;	
	}
	return clientes;
}

void see_data(cliente clientes[], int tamano) {
		for (int c = 0; c < tamano; c++) {
			cout << "| id:    " << c << setw(5)<< "|";
		}cout << endl;
		for (int j = 0; j < tamano; j++) {
			cout << "| EDAD: " << clientes[j].edad << setw(5)<<"|";
		}cout << endl;
		for (int h = 0; h < tamano; h++) {
			cout << "| Sexo:  " << clientes[h].sexo << setw(5)<<"|";
		}cout << endl;
		for (int n = 0; n < tamano; n++) {
			cout << "| Serv:  " << clientes[n].servicio << setw(5)<<"|";
		}cout << endl;
		for (int n = 0; n < tamano; n++) {
			cout << "| Nivel: " << clientes[n].nivel << setw(5) << "|";
		}cout << endl;
}

void see_min_edad(cliente clientes[], int tamano) {
	int min = INT_MAX;
	int indice = 0;
	int coincidencias=0;
	for (int i = 0; i < tamano; i++) {
		if (clientes[i].edad < min) {
			min = clientes[i].edad;
			indice = i;
		}
	}
	for (int i = 0; i < tamano; i++) {
		if (clientes[indice].edad == clientes[i].edad && indice!=i) {
			coincidencias++;
		}
	}
	cout << "El menor es: " << clientes[indice].edad << endl;
	if (coincidencias > 0) {
		cout << "Existen un total de: " << coincidencias <<" COINCIDENCIAS" << endl;
	}
	else {
		cout << "No hay coincidencias " << endl;
	}
}

void see_porcentaje_edades(cliente clientes[], int tamano) {
	int counter_menor_once = 0;
	int counter_menor_cuatrocinco = 0;

	for (int i = 0; i < tamano; i++) {
		if (clientes[i].edad <= 11 && clientes[i].servicio =='O') {
			counter_menor_once++;
		}
		if (clientes[i].edad >= 45 && (clientes[i].servicio =='P' || clientes[i].servicio=='O')) {
			counter_menor_cuatrocinco++;
		}	
	}
	if (counter_menor_cuatrocinco != 0) {
		cout << "El porcentaje de mayores de 45: " << (float)counter_menor_cuatrocinco * 100 / tamano << endl;
	}
	else {
		cout << "NO HAY PORCENTAJE MENORES 11:" << endl;
	}
	if (counter_menor_once != 0) {
		cout << "El porcentaje de menores de 11: " << (float)counter_menor_once * 100 / tamano << endl;
	}
	else {
		cout << "NO HAY PORCENTAJE MAYORES 45:" << endl;
	}
}
void promedio_edad_por_tipo_satis(cliente clientes[],int tamano) {
	int counter_nivel_tre = 0,  promedio_tre = 0;;
	int counter_nivel_dos = 0,  promedio_do = 0;
	int counter_nivel_uno = 0, promedio_uno=0;

	for (int i = 0; i < tamano; i++) {
		switch (clientes[i].nivel)
		{
		case 1:counter_nivel_uno++; promedio_uno += clientes[i].edad; break;
		case 2:counter_nivel_dos++; promedio_do += clientes[i].edad;break;
		case 3:counter_nivel_tre++;promedio_tre += clientes[i].edad;break;
		}
	}

	cout << "El promedio de nivel 1: " << promedio_uno / counter_nivel_uno << endl;
	cout << "El promedio de nivel 2: " << promedio_do / counter_nivel_dos << endl;
	cout << "El promedio de nivel 3: " << promedio_tre / counter_nivel_tre << endl;
}


void ordenador_edades(cliente clientes[], int tamano) {
	for (int i = 0; i < tamano; i++) {
		int current_edad = clientes[i].edad;
		char current_sexo = clientes[i].sexo;
		char current_servicio = clientes[i].servicio;
		int current_nivel = clientes[i].nivel;
		int j = i - 1;
		while (j >= 0 && current_edad < clientes[j].edad) {
			clientes[j + 1].sexo = clientes[j].sexo;
			clientes[j + 1].edad = clientes[j].edad;
			clientes[j + 1].servicio = clientes[j].servicio;
			clientes[j + 1].nivel = clientes[j].nivel;
			j-=1;
		}
		clientes[j + 1].sexo = current_sexo;
		clientes[j + 1].edad = current_edad;
		clientes[j + 1].servicio = current_servicio;
		clientes[j + 1].nivel = current_nivel;
	}
}



void ordenamiento_de_data_sexo(cliente clientes[], int tamano) {
	int contador_embras = 0, contador_machos = 0;

	for (int i = 0; i < tamano; i++) {
		if (clientes[i].sexo == 'M') {	contador_machos++;}
		if(clientes[i].sexo == 'F') {contador_embras++;}
	}
	cliente* mujere = new cliente[contador_embras];
	cliente* machos = new cliente[contador_machos];
	int posiciomacho = 0, posicionembra=0;
	for (int i = 0; i <tamano; i++) {
		switch (clientes[i].sexo)	{
		case 'M':
			machos[posiciomacho].edad = clientes[i].edad;
			machos[posiciomacho].servicio = clientes[i].servicio;
			machos[posiciomacho].nivel = clientes[i].nivel;
			machos[posiciomacho].sexo = clientes[i].sexo;
			posiciomacho++;
			break;
		case 'F':
			mujere[posicionembra].edad = clientes[i].edad;
			mujere[posicionembra].servicio = clientes[i].servicio;
			mujere[posicionembra].nivel = clientes[i].nivel;
			mujere[posicionembra].sexo = clientes[i].sexo;
			posicionembra++;
			break;
		}
	}
	ordenador_edades(mujere, contador_embras);
	ordenador_edades(machos, contador_machos);
	int posicion_inicial = 0, posi2=0;
	for (int i = 0; i < tamano; i++) {

		clientes[i].edad = mujere[posicion_inicial].edad;
	    clientes[i].servicio= mujere[posicion_inicial].servicio ;
		clientes[i].nivel = mujere[posicion_inicial].nivel;
		clientes[i].sexo= mujere[posicion_inicial].sexo ;
		if (posicion_inicial <= contador_embras) {
			posicion_inicial++;
		}
	}
	for (int i = posicion_inicial-1; i < tamano; i++) {
		clientes[i].edad = machos[posi2].edad;
		clientes[i].servicio = machos[posi2].servicio;
		clientes[i].nivel = machos[posi2].nivel;
		clientes[i].sexo = machos[posi2].sexo;
		if (posi2 <= contador_machos) {
			posi2++;
		}
	}

}


int main() {
	int n_clientes = 0;
	cout << "Ingrese la cantidad de clientes: " << endl;
	cin >> n_clientes;
	cliente* clientes = generate_cliente(n_clientes);
	see_data(clientes, n_clientes);
	see_min_edad(clientes, n_clientes);
	promedio_edad_por_tipo_satis(clientes, n_clientes);
	ordenamiento_de_data_sexo(clientes, n_clientes);
	see_data(clientes, n_clientes);
}*/



tm capture_time() {
	time_t timestamp= time(NULL);
	tm tiempo;
	localtime_s(&tiempo, &timestamp);
	return tiempo;
}

int** data() {
	int** data = new int* [50];
	for(int i=0;i<50; i++){
		data[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			switch (j)
			{
			case 2:
				while (true) {
					data[i][j] = 1 + rand() % capture_time().tm_min;
					if (data[i][j]<=30) {
						break;
					}
				}
				break;
			default:
				data[i][j] = 1 + rand() % 3;
					break;
			}
		}
	}
	return data;
}

void mayor_numero_de_llamadas(int ** data) {
	int maximo = 0, indice=0;
	for (int i = 0; i < 50; i++) {
			if (data[i][1] > maximo) {
				maximo = data[i][1];
				indice = i;
			}
	}
	cout << "La oficina: " << data[indice][0] << " y ";
	for (int i = 0; i < 50; i++) {
		if (data[i][1] == maximo) {
			cout << " " << data[i][0] << " ";
		}
	}cout << endl;
	cout << "Tienen el mayor numero de llamadas" << endl;
}

int main(){
	int** informacion_call_center = data();

}

long long string_to_int(string cadena_inicial) {

	string cadena_a_jugar;
	for (int i = cadena_inicial.length() - 1; i >= 0; i--) {
		cadena_a_jugar += cadena_inicial[i];
	}
	char enteros[] = { '0','1','2','3','4','5','6','7','8','9' };
	long long entero = 0;
	for (int i = 0; i < cadena_a_jugar.length(); i++) {
		for (int j = 0; j < 10; j++) {
			if (cadena_a_jugar[i] == 0) {
				entero += (pow(10, i + 1));
				break;
			}
			else if (cadena_a_jugar[i] == enteros[j]) {
				entero += j * (pow(10, i));
				break;
			}
		}
	}
	return entero;
}

int** data_and_see_data(int rows, int column) {
	int** data = new int* [rows];
	for (int i = 0; i < rows; i++) {
		data[i] = new int[column];
		for (int j = 0; j < column; j++) {
			data[i][j] = 48 + rand() % (57 - 48 + 1);
			cout << char(data[i][j]) << " ";
		}cout << endl;
	}
	return data;
}

void locate_numero(string numero, int** data, int rows, int columns) {
	int contador = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (j + 2 > columns) {
				break;
			}
			if (data[i][j] == numero[0] && data[i][j + 1] == numero[1] && data[i][j + 2] == numero[2]) {
				contador++;
			}
		}

	}
	cout << "El numero tiene : " << contador << " Coincidencias" << endl;
}
int main() {
	int rows, columns; string numero;
	while (true) {
		cout << "Ingrese filas: "; cin >> rows; cout << endl;
		cout << "Ingrese columnas: "; cin >> columns; cout << endl;
		if (rows > 0 && rows <= 100 && columns > 0 && columns <= 100) {
			break;
		}
	}
	cin.ignore();
	int** data = data_and_see_data(rows, columns);
	while (true) {
		cout << "Ingrese numero: "; getline(cin, numero); cout << endl;
		if (int(string_to_int(numero)) > 99 && int(string_to_int(numero)) < 999) {
			break;
		}
	}
	locate_numero(numero, data, rows, columns);
	exit(1);
}