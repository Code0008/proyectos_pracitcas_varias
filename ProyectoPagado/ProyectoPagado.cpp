#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <conio.h>
using namespace std;

struct direccion {
    string direccion_exacta;
    string distrito;
    string provincia = "Lima";
};
struct Usuarios {
    string nombre_usuario;
    int edad_usuario;
    int DNI = 0;
    char sexo;
    direccion direccion_usuario;
    string celular;
    bool sancion = false;
};
struct contenido {
    int codigo_libro; //123456
    string titulo_libro;
    bool prestado;
    char tipo;
};

bool verif_string(string texto);
bool verif_dni(string dni);
bool verif_telefono(string telefono);
bool verif_entero(string entero);
tm capture_time() {
    tm tiempo;
    time_t timestap;
    time(&timestap);
    localtime_s(&tiempo, &timestap);
    return tiempo;
}

static bool verif_dni(string dni) {
    if (dni.length() == 8) {
        if (verif_entero(dni)) {
            return true;
        }
        else { return false; }
    }else { return false; }
}

static bool verif_string(string texto) {
    bool verif = true;
    for (int i = 0; i < texto.length(); i++) {
        if (isdigit(texto[i])) { return true; }
        else { continue; }
    } return false;
}

static bool verif_telefono(string telefono) {
    if (telefono.length() < 10 && telefono.length() > 1) {
        bool verif = false;
        for (int i = 0; i < 9; i++) {
            if (isdigit(telefono[i])) { verif = true; }
            if (isdigit(telefono[i]) == false || telefono[i] == '+') { return false; }
        }return verif;
    }else { return false; }
}

static bool verif_entero(string verificar) {
    if (verificar.length() == 0) { return false; }
    bool verif = false;
    for (int i = 0; i < verificar.length(); i++) {
        if (isspace(verificar[i]) || !isprint(verificar[i])) { return false; } // '\n
        if (isdigit(verificar[i])) { verif = true; }
        else { return false; }
    }
    return verif;
}

void see_info_tratada(string** tratado) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 4; j++) {
            if (tratado[i][3] == "true") {cout << "\t";cout << tratado[i][j];}
        }
    }
}
bool verificar_codigo(contenido inventario[], string codigo) {
    for (int i = 0; i < 5; i++) {
        if (stoi(codigo) == inventario[i].codigo_libro) {inventario[i].prestado = true;return  true; break;}
    }
    return false;
}

void mirar_informacion_inventario(contenido inventario[], Usuarios* usuarios, int posicion) {
    cout << "\t\t\tCODIGO\ttitulo" << endl;
    for (int i = 0; i < 4; i++) {
        if (inventario[i].prestado == false) {cout << "\t\t\t" << inventario[i].codigo_libro << "\t" << inventario[i].titulo_libro << endl;}
    }
}

void agregar_libro(contenido inventario[], string** data_usuario, string codigo, int fecha_devlucion, string proceso) {
    int indice = 0;
    for (int i = 0; i < 100; i++) {
        if (data_usuario[i][3] == "true" && data_usuario[i + 1][1] == "false") {indice = i + 1;break;}
    }
    string fecha;
    int indice_2 = 0;
    for (int i = 0; i < 4; i++) {
        if (inventario[i].codigo_libro == stoi(codigo)) {indice_2 = i; break; }
    }
   
    switch (inventario[indice_2].tipo) {case 'R': fecha = to_string(fecha_devlucion += 2);break;case 'P':fecha = to_string(fecha_devlucion += 5); break;case 'L': fecha  = to_string(fecha_devlucion += 5); break;}
    for (int j = 0; j < 4; j++) {
        switch (j) {
        case 0: data_usuario[indice][0] = codigo; break;
        case 1:data_usuario[indice][1] = proceso; break;
        case 2:data_usuario[indice][2] = fecha; break;
        case 3: data_usuario[indice][3] = "true"; break;
        default:break;
        }
    }
}
void get_prestamo_data(contenido inventario[], Usuarios* usuarios, int posicion, string** data_usuario) {
    string dni;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;
    while (true) {
        cout << "\t\t\t[!] Ingrese su DNI: " << endl;
        getline(cin, dni);
        if (dni.length() == 8) { break; }
        else { continue; }
    }
    usuarios[posicion].DNI = stoi(dni);
    mirar_informacion_inventario(inventario, usuarios, posicion);
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;
    cout << "\t\t\t[!] Ingrese el codigo del libro que va a prestarse:  " << endl;
    while (true) {
        string codigo; getline(cin, codigo);
        if (verificar_codigo(inventario, codigo)) { agregar_libro(inventario, data_usuario, codigo, capture_time().tm_mday, "prestamo"); break; }
        else {
            cout << "\t\t\t INGRESE CODIGO VALIDO" << endl;
        }
    }
    cout << "\t\t\t INVENTARIO ACTUAL DE LA BIBLIOTECA" << endl;
    mirar_informacion_inventario(inventario, usuarios, posicion);
    cout << "\t\t\t INVENTARIO ACTUAL DEL USUARIO" << endl;
    see_info_tratada(data_usuario);
    cout << endl;
}

void get_user_data(Usuarios* usuarios, int posicion) {

    cout << endl<<endl;
    while (true) {
        cout << "\t\t\t -!Ingrese el nombre de usuario: ";getline(cin, usuarios[posicion].nombre_usuario);
        if (verif_string(usuarios[posicion].nombre_usuario)) {cout << "\t INGRESO MAL EL NOMBRE DE USUARIO" << endl; }
        else { break; }
    }
    string validar;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;
    while (true) {
        cout << "\t\t\t[+]Ingrese edad del usuario: "; cin >> validar;
        if (verif_entero(validar)) { usuarios[posicion].edad_usuario = stoi(validar); break; }
        else { cout <<"\t\t\t[!] Ingrese bien su edad!\n"; }
    }
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    while (true) {
        cout << "\t\t\tIngrese su sexo: " ;
        usuarios[posicion].sexo = _getch();
        usuarios[posicion].sexo = toupper(usuarios[posicion].sexo);
        if (usuarios[posicion].sexo == 'M' || usuarios[posicion].sexo == 'F') {
            break;
        }
        else {
            cout << "\t\t\t ingrse su sexo de forma correcta" << endl;
        }
    
    }
    cout << endl;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    while (true){  cin.ignore();
        cout << "\t\t\tIngrese su direccion: ";
        getline(cin, usuarios[posicion].direccion_usuario.direccion_exacta);
        cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

        cout << "\t\t\tIngrese su distrito: ";
        getline(cin, usuarios[posicion].direccion_usuario.distrito);
        if (verif_string(usuarios[posicion].direccion_usuario.direccion_exacta) != true && verif_string(usuarios[posicion].direccion_usuario.distrito) != true && usuarios[posicion].direccion_usuario.distrito.length() >= 5)  { break; 
        }else{ cout << "\t\t\t ALGUNO DE LOS DATOS MAL INGRESAO" << endl;}
    }
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    while(true){
        cout << "\t\t\tIngrese su celular: ";
        getline(cin, usuarios[posicion].celular);
        if (verif_telefono(usuarios[posicion].celular)) {break; }else { cout << "\t\t\t INGRESE CORRECTAMENTE SU TELEFONO" << endl; }
    }
}

bool mensaje_continuar() {
    char respuesta;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    cout << "\t\t\tIngrese si desea continua: ";
    respuesta = _getch();
    if (toupper(respuesta) == 'N') { exit(0);}
    else {  return true;}
}

void make_matriz(string** matriz) {
    for (int i = 0; i < 100; i++) {
        matriz[i] = new string[4];
        matriz[i][3] = "false";
    }
}

void get_devolucion_data(contenido* inventario, string** infotratada, Usuarios* usuarios, int posicion) {

    if (usuarios[posicion].DNI == 0) {
        string dni;
        while (true) {
            cout << "\t\t\t-------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t[!] Ingrese su DNI: " << endl; getline(cin, dni);
            if (dni.length() == 8) { break;} else { continue; }
        }
        usuarios[posicion].DNI = stoi(dni);
    }
    string codigo;
    while (true) {
        cout << "\t\t\t-------------------------------------------------------------------------------" << endl;
        cout << "\t\t\tINGRESE EL CODIGO DEL LIBRO: ";getline(cin, codigo);
        if (codigo.length()>= 5) {
            agregar_libro(inventario, infotratada, codigo, 0, "devolucion");
            break;}
        else { continue; }
    }
    char tipo_libro;
    int dia_que_paso;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    while(true){
        cout << "\n\t\t\tINGRESE TIPO DE LIBRO: ";
        tipo_libro = _getch(); cout << endl;
        tipo_libro = toupper(tipo_libro);
        if (tipo_libro == 'R' || tipo_libro == 'L' || tipo_libro == 'P') {switch (tipo_libro){case 'R':dia_que_paso = 5;break;case 'L':dia_que_paso = 5; break;case 'P':dia_que_paso = 2;break; }break; }
    }
    string mes;
    int mes_i;
    int dia_i;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    while (true) {
        cout << "\n\t\t\tINGRESE EL MES QUE PRESTO ";
        cin >> mes;
        if (verif_entero(mes)) {
            if (stoi(mes) <= capture_time().tm_mon + 1) {
                mes_i = stoi(mes);
                break;
            }
            else {
                cout << "\t\t\t INGRESO MAL MES" << endl;
            }
            
        }else {
            cout << "\t\t\t INGRESO MAL EL MES" << endl;
        }
    }
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    while (true) {
        cout << "\n\t\t\tINGRESE EL DIA QUE PRESTO ";
        cin >> mes;
        if (verif_entero(mes)) {
            if (stoi(mes) <= capture_time().tm_yday) {
                dia_i = stoi(mes);
                break;
            }
            else {
                cout << "\t\t\t INGRESO MAL EL DIA" << endl;
            }
        }
        else {
            cout << "\t\t\t INGRESO MAL EL DIA" << endl;
        }
    }
    int total = (mes_i*6)-(30-dia_i);
    if (capture_time().tm_yday <= total+dia_que_paso) {
        cout << "\t\t\t GRACIAS POR DEVOLVER A TIEMPO!" << endl;
        
    }
    else {
        usuarios[posicion].sancion;
        cout << "\t\t\t TIENES SANCION MARRON!" << endl;

    }

    see_info_tratada(infotratada);
    cout << endl;
    
}


void grafico_barras_ultimos_semestres() {
    srand(time(NULL));
    string meses[7] = { "enero", "febrero", "marzo", "abril ", "mayo", "junio" };
    string meses_dos[] = { "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };
    int** data = new int* [7];
    for (int i = 0; i < 7; i++) {
        data[i] = new int[2];
        data[i][0] = rand() % 1000 +(1000-100);
        data[i][1] = rand() % 1000 + (1000 - 100);
    }
    // cada columna un semestre
    char selec;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    cout << "\n\t\t\t QUE SEMESTRE DESEA VER " << endl;
    cout << "\t\t\t [1] primer semestre" << endl;
    cout << "\t\t\t [2] segundo semestre" << endl;
    while (true)
    {
        selec = _getch();
        if (selec == '1' || selec == '2') {
            break;
        }else {cout << "\t\t\t INGRESE UNA SELECCION VALIDA " << endl;}
    }
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    switch (selec)
    {
    case '1':
        cout << "\t\t\t Informacion primer semestre " << endl;
        for (int i = 0; i < 6; i++) {
            cout << "\t\t\t"<<meses[i] << "-->";
            for (int k = 0; k < data[i][0] / 100; k++) {
                cout << "*";
            }  cout << endl;
        } 
  
        break;
    case '2': 
          cout << "\t\t\t Informacion primer semestre " << endl;
        for (int i = 0; i < 6; i++) {
            cout << "\t\t\t" << meses_dos[i] << "-->";
            for (int k = 0; k < data[i][1] / 100; k++) {
                cout << "*";
            }cout << endl;
        }
        break;
    }

    

}

void reporte_porcentaje_prestamos_por_tipo() {
    int** matriz = new int*[3];
    int total_suma = 0;
    int caractere[] = { 82, 80, 76 };
    for (int i = 0; i < 3; i++) {
        matriz[i] = new int[2];
        matriz[i][0] = caractere[0];
        matriz[i][1] = rand() % 4000 + (4000-1000);
        total_suma += matriz[i][1];
    }
    for (int i = 0; i < 3; i++) {           // algoritmo de ordenamiento insertion sort 
        int current_data = matriz[i][1];
        int caracter_current = matriz[i][0] ;
        int j = i - 1;

        while (j >= 0 && matriz[j + 1][1] > current_data) {
            matriz[j + 1][1] = matriz[j][1];
            matriz[j + 1][0] = matriz[j][0];
            j -= 1;
        }
        matriz[j + 1][1] = current_data;
        matriz[j + 1][0] = caracter_current;
    }
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 3; i++) {
        switch (matriz[i][0])
        {
        case 76:
            cout << "\t\t\t El porcentaje de prestado libro es: " << matriz[i][1] * 100 / total_suma <<"%" << endl;
            break;
        case 82: 
            cout << "\t\t\t El porcentaje de prestado revistas  es: " << matriz[i][1] * 100 / total_suma << "%" << endl;
            break;
        case 80:
            cout << "\t\t\t El porcentaje de prestado periodico es: " << matriz[i][1] * 100 / total_suma << "%" << endl;
            break;
        default:
            break;
        }
    
    }

}


void datos_publicaciones_pendintes_devolucion() {
    int** matriz = new int* [50];
    int caractere[] = { 82, 80, 76 };
    int contador_p = 0, contador_l = 0, contador_r = 0;
    for (int i = 0; i < 50; i++) {
        matriz[i] = new int[4];
        matriz[i][0] = caractere[rand() % 3];
        switch (matriz[i][0])
        {
        case 80:  contador_p++; break;
        case 82:  contador_r++; break;
        case 76: contador_l++; break;
        }

        matriz[i][1] = rand() % 1 + (capture_time().tm_yday - 1);
        matriz[i][2] = rand() % 1 + (matriz[i][1]);
        matriz[i][3] = rand() % 24000 + (24999 - 24000);
    }
    for (int i = 0; i < 50; i++) {
        int current_day_prestado = matriz[i][2];
        int current_day_devuelto = matriz[i][1];
        int current_codigo_publi = matriz[i][3];
        int curent_caracter = matriz[i][0];
        int j = i - 1;
        while (j >= 0 && matriz[j + 1][2] > current_day_prestado)
        {
            matriz[j + 1][2] = matriz[j][2];
            matriz[j + 1][1] = matriz[j][1];
            matriz[j + 1][3] = matriz[j][3];
            matriz[j + 1][0] = matriz[j][0];
            j -= 1;

        }
        matriz[j + 1][2] = current_day_prestado;
        matriz[j + 1][1] = current_day_devuelto;
        matriz[j + 1][3] = current_codigo_publi;
        matriz[j + 1][0] = curent_caracter;
    }
    cout << "\t\t\t [!] INGRESE EL TIPO DE PUBLICACION QUE QUIERES VER " << endl;

    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 4; j++) {
            switch (matriz[i][0]){
            case 80:cout << "Periodico " << endl;break;
            case 82: cout << "Revista " << endl; break;
            case 76: cout << "libro" << endl; break;
            }
            cout <<"\t\t\tCodigo: "<< matriz[i][3] << endl;
            cout << "\t\t\t___________________________" << endl;
        }
    }
}

void lectores_rango_edad(int ano) {
    int years[] = { 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024 };

    int** matriz = new int* [8];
    for (int i = 0; i < 8; i++) {
        matriz[i] = new int[4];
        matriz[i][0] = years[i];
        matriz[i][1] = rand() % 20000 + (29999 - 2000);
        matriz[i][2] = rand() % 20000 + (29999 - 2000);
        matriz[i][3] = rand() % 20000 + (29999 - 2000);
    }
    int indice = 0;
    for (int j = 0; j < 8; j++) {
        if (matriz[j][0] == ano) {
            indice = j;
            break;
        }
    }    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    for (int j = 1; j < 4; j++) {
        switch (j)
        {
        case 1:
            cout << "\t\t\tRANGO DE 18-30: " << matriz[indice][j]<< endl; break;
        case 2:
            cout << "\t\t\tRANGO DE 30-60: " << matriz[indice][j]<< endl; break;
        case 3:
            cout << "\t\t\tRANGO DE 60-100: " << matriz[indice][j]<<endl; break;
        default:
            break;
        }
    
    }

}

void ingresar_reportes(Usuarios* usuario, int posicion) {
    char selec;
    cout << endl;
    cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

    while (true) {
    cout << "\t\t\t [A] GRAFICO DE BARRAS EN LOS ULTIMOS DOS SEMESTRES " << endl;
    cout << "\t\t\t [B] REPORTE PORCENTAJE DE PRESTAMOS POR TIPO DE PUBLICACION " << endl;
    cout << "\t\t\t [C] LISTADO DE DATOS DE LAS PUBLICACIONES PENDIENTES DE DEVOLUCION " << endl;
    cout << "\t\t\t [D] LECTORES POR RANGO DE EDAD " << endl;
 
        selec = _getch();
        selec = toupper(selec);
        if (selec == 'A' || selec == 'B' || selec == 'C' || selec == 'D') {
            break;
        } else {cout << "\t\t\t INGRESE UNA SELECCION VALIDA " << endl;}
    }
    switch (selec)
    {
    case 'A': grafico_barras_ultimos_semestres();
        break;
    case 'B':reporte_porcentaje_prestamos_por_tipo(); break;
    case 'C':datos_publicaciones_pendintes_devolucion(); break;
    case 'D':
        int ano;
        while (true)
        {
            cout << "\t\t\t [B] INGRESE EL AÑO QUEQUIERE VER ";
            cin >> ano;
            if (verif_entero(to_string(ano))) {
                if (ano >= 2017 && ano <= 2024) { break; }
                else{
                    cout << "\t INGRESE UNA SELECCION VALIDA " << endl;
                }
            }
        }
        lectores_rango_edad(ano); break;
    default:
        break;
    }
}



int main(){
    contenido inventario[4]{{202412, "FORBES", false, 'R'},{202411, "DON QUIJOTE", false, 'L'},{202416, "Perukistano", false, 'P'},{202415, "LOCAZO", false, 'R'},};
    Usuarios* usuarios = new Usuarios[100];
    string** informacion_tratada = new string * [100];
    make_matriz(informacion_tratada);
    int posicion = 0;char selec;
    get_user_data(usuarios, posicion);
    while (true) {
        cout << "\t\t\t-------------------------------------------------------------------------------" << endl;

        cout << "\t\t\t [A] Prestamo" << endl;
        cout << "\t\t\t [B] Devolucion" << endl;
        cout << "\t\t\t [C] REPORTES" << endl;
        cout << "\t\t\tIngrese procesoa ejecutar:";  selec = _getch(); selec = toupper(selec);
        switch (selec){
        case 'A': cout << endl; get_prestamo_data(inventario, usuarios, posicion, informacion_tratada); break;
        case 'B':
            if (usuarios[posicion].sancion != true) {get_devolucion_data(inventario, informacion_tratada, usuarios, posicion);}
            else { break; }break;
        case 'C':
            ingresar_reportes(usuarios, posicion);
            break;
        }
        if (mensaje_continuar()) {
            cout << endl;continue;
        }
    }
}