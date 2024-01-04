/*
Act 2.3 -  Actividad Integral estructura de datos lineales (Evidencia Competencia)
Descripcion: Escribir un programa que lean un archivo bitacora.txt que almacena cada linea de registro en una lista doblemente ligada, 
posteriormente ordenará esta lista mediante la comparacion de ip en forma numerica. Pedirá al usuario dos ip que definiran el rango
de donde se imprimiran los registros correspondientes, ademas en un archivo SortedData.txt el programa mostrará los registros ordenados de forma ascendente. 

Jueves 15 de octubre del 2023
Integrantes:
 * Emiliano Sánchez Dominguez A01736342
 * Cynthia Amador Santiago A01737854
 * Rodrigo López Guerra A01737437
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Estructura para almacenar una entrada de registro
struct Registro {
        string mes_Str; // Mes en texto
        int mes;        // Mes en entero
        int dia;        // Día
        string tiempo;  // Hora
        string ip;      // Dirección IP
        string mensaje; // Mensaje de registro
        //Sobrecarga de operador para comparar dos registros, si a < b.
        bool operator | (const Registro& ip2) const {
            string num1_ip, num2_ip, num3_ip, num4_ip, puerto;
            istringstream str_ip(ip);
            getline(str_ip, num1_ip,'.');
            getline(str_ip, num2_ip,'.');
            getline(str_ip, num3_ip,'.');
            getline(str_ip, num4_ip,':');
            getline(str_ip, puerto,':');
            string num1_ip2, num2_ip2, num3_ip2, num4_ip2, puerto2;
            istringstream str_ip_2(ip2.ip);
            getline(str_ip_2, num1_ip2,'.'); //Extraer los componentes de la direccion IP del segundo registro
            getline(str_ip_2, num2_ip2,'.');
            getline(str_ip_2, num3_ip2,'.');
            getline(str_ip_2, num4_ip2,':');
            getline(str_ip_2, puerto2);

            // Compara los componentes de las direcciones IP numéricamente
            // Complejidad: O(1)
            if (stoi(num1_ip) != stoi(num1_ip2)) {
                return stoi(num1_ip) < stoi(num1_ip2);
            }
            else if (stoi(num2_ip) != stoi(num2_ip2)) {
                return stoi(num2_ip) < stoi(num2_ip2);
            }
            else if (stoi(num3_ip) != stoi(num3_ip2)) {
                return stoi(num3_ip) < stoi(num3_ip2);
            }
            else if (stoi(num4_ip) != stoi(num4_ip2)) {
                return stoi(num4_ip) < stoi(num4_ip2);
            }
            else if (stoi(puerto) != stoi(puerto2)) {
                return stoi(puerto) < stoi(puerto2);
            }
            return false;//Si los registros son iguales
        }

};

// Estructura para representar un nodo en la lista
struct Nodo {
    Registro registro;
    Nodo* siguiente; // Puntero al siguiente registro
    Nodo* anterior;  // Puntero al registro anterior
};

// Función para insertar un nuevo registro al final de la lista
// Recibe el pauntador de cabeza y cola a la lista y el registro que se va a insertar
// No retorna valor
// Complejidad: O(1)
void insertarRegistro(Nodo*& cabeza, Nodo*& cola, const Registro& nuevoRegistro) {
    Nodo* nuevoNodo = new Nodo; //crear un nodo y asigna su direccion a nuevoNodo
    nuevoNodo -> registro = nuevoRegistro;
    nuevoNodo -> siguiente = NULL;
    nuevoNodo -> anterior = cola;
    if (cabeza == NULL) {
        cabeza = nuevoNodo;
    } else {
        cola -> siguiente = nuevoNodo;
    }
    cola = nuevoNodo;
}

// Función para liberar la memoria ocupada por la lista doblemente ligada
// Recibe el apuntador a la cabeza de la lista.
// No retorna valor
// Complejidad: O(n)
void liberarLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* siguiente = actual -> siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Función para particionar la lista doblemente ligada
// REcibe el apuntador al inicio y al fin de la paricion a realizar.
// Devuelve el apunador del pivote. 
// Complejidad: O(n)
Nodo* particion(Nodo* inicio, Nodo* fin){
    Registro pivote = fin -> registro;
    Nodo* i = inicio -> anterior;

    for (Nodo* j = inicio; j != fin; j = j -> siguiente) {
        // Comparar primero por la dirección IP de forma numérica en orden descendente
        if (j -> registro | pivote) {
            if (i == NULL) {
                i = inicio;
            } else {
                i = i -> siguiente;
            }
            swap(i -> registro, j -> registro);
        }
        // En caso de que las direcciones IP coincidan, comparar por fecha y hora
        else if (j->registro.ip == pivote.ip) {
            if (j -> registro.mes < pivote.mes || (j -> registro.mes == pivote.mes && j -> registro.dia < pivote.dia) ||
                (j -> registro.mes == pivote.mes && j -> registro.dia == pivote.dia && j -> registro.tiempo < pivote.tiempo)) {
                if (i == NULL) {
                    i = inicio;
                } else {
                    i = i->siguiente;
                }
                swap(i -> registro, j -> registro);
            }
        }
    }
    if (i == NULL) {
        i = inicio;
    } else {
        i = i->siguiente;
    }
    swap(i->registro, fin->registro);
    return i;
}

// Función Quick Sort para lista doblemente ligada
// Recibe el apuntador a la cabeza y cola de la lista. 
// Complejidad (PEOR): O(n^2)
// Complejidad (MEJOR): O(n log n)
void quickSort(Nodo* inicio, Nodo* fin) {
    if  (fin != NULL && inicio != fin && inicio != fin->siguiente){
        Nodo* pivote = particion(inicio, fin);
        quickSort(inicio, pivote->anterior);
        quickSort(pivote->siguiente, fin);
    }
}


// Funcion para obtener el indice de un mes a partir de su nombre
// Recibe el string del mes del registro
// Devuelve el entero correspondiente. 
// Complejidad: O(1)
int obtenerIndiceMes(const string& mes) {
    static const string meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; ++i) {
        if (mes == meses[i]) {
            return i + 1;
        }
    }
    return -1; // Mes no encontrado
}

//Funcion para buscar un nodo en la lista basado en una direccion IP
// Recibe el apuntador a la cabeza de la lista y el registro temporal que se realizó en el main en donde esta la ip a buscar. 
// Devuelve el apuntador al nodo en donde se encuentra la ip o uno cercano. 
//Complejidad: O(n)
Nodo* BuscarNodo(Nodo* head, Registro ip2){
    Nodo* nodoIP_buscar = head;
    while (nodoIP_buscar -> siguiente != NULL && nodoIP_buscar-> registro | ip2) { //Uso de operador sobrecargado
        nodoIP_buscar = nodoIP_buscar -> siguiente;
    }
    if (nodoIP_buscar -> registro.ip == ip2.ip){
        return nodoIP_buscar;
    }
    else{
        return nodoIP_buscar -> anterior;
    }

}

//Funcion para imprimir un registro en la consola
// Recibe el registro a imprimir
// No retorna valor. 
// Complejidad: O(1)
void imprimeRegistro(Registro linea){
    if (linea.mes_Str.empty() || linea.dia <= 0 || linea.mes <= 0 || linea.tiempo.empty() || linea.ip.empty() || linea.mensaje.empty()) {
        cout << "Registro no válido" << endl;
    } else {
        cout << linea.mes_Str << " " << linea.dia << " " << linea.tiempo << " " << linea.ip << " " << linea.mensaje << endl;
    }
}

// Función para escribir registros en el rango
// REcibe los apuntadores de inicio y fin correspondientes a los nodos que delimitan el rango a imprimir. 
// Complejidad: O(n)
void escribirRegistrosEnRango(Nodo* inicio, Nodo* fin) {
    Nodo* actual = fin;
    while (actual != inicio->anterior) {
        Registro linea = actual -> registro;
        imprimeRegistro(linea);
        actual = actual -> anterior;
    }
}

// Función para imprimir una lista ligada de manera ascendente en un archivo de salida
// Recibe el apuntador a head de la lista.
// No retorna ningun valor. 
// Complejidad: O(n)
void imprimeAscendente(Nodo* head){
    ofstream outfile("SortedData.txt");
    struct Nodo* tmp = head;
    while (tmp != NULL){
        Registro linea = tmp -> registro;
        outfile << linea.mes_Str << " " << linea.dia << " " << linea.tiempo << " " << linea.ip << " " << linea.mensaje << endl;
        tmp = tmp -> siguiente;
    }
};

//Funcion para imprimir una lista ligada de manera descendente
// Recibe el apuntador a la cola de la lista.
// No retorna ningun valor. 
// Complejidad: O(n)
void imprimeDescendente(Nodo* cola){
    ofstream outfile("SortedData.txt");
    struct Nodo* tmp = cola;
    while (tmp != NULL){
        imprimeRegistro(tmp -> registro);
        tmp = tmp -> anterior;
    }
};

//Complejidad promedio: O(n log n)
int main(){
    Nodo* cabeza = NULL;
    Nodo* cola = NULL;
    ifstream file("bitacora.txt");
    string line;

    while (getline(file, line)) {
        istringstream conjunto(line);
        Registro linea;
        conjunto >> linea.mes_Str >> linea.dia >> linea.tiempo >> linea.ip;
        getline(conjunto, linea.mensaje);
        linea.mes = obtenerIndiceMes(linea.mes_Str);
        insertarRegistro(cabeza, cola, linea);
    }
    // Llamada a la función quickSort
    quickSort(cabeza, cola);


    string primeraIP, segundaIP;
    cin >> primeraIP;
    cin >> segundaIP;

    //Se crea dos registros con los las ips a buscar para poder aprovechar la sobrecarga del operador en la estructura registro.
    Registro linea_for_ip1;
    Registro linea_for_ip2;
    linea_for_ip1.ip = primeraIP;
    linea_for_ip2.ip = segundaIP;

    Nodo* nodo_1_ip = BuscarNodo(cabeza, linea_for_ip1);
    Nodo* nodo_2_ip = BuscarNodo(cabeza, linea_for_ip2);

    if (nodo_1_ip -> registro | nodo_2_ip -> registro){
        escribirRegistrosEnRango(nodo_1_ip, nodo_2_ip);
    }
    else{
        escribirRegistrosEnRango(nodo_2_ip, nodo_1_ip);
    }

    // Desplegar registros en el rango de fechas
    imprimeAscendente(cabeza);
    //imprimeDescendente(cola);

    // Liberar la memoria ocupada por la lista doblemente ligada
    liberarLista(cabeza);

    return 0;
}
