/*
// Act 4.3 - Actividad Integral de Grafos (Evidencia Competencia)
// Descripción: Función principal que realiza las siguientes tareas:
//   1. Lee datos del archivo "bitacora2.txt" y los almacena en un vector de registros.
//   2. Ordena el vector de registros usando el algoritmo quicksort.
//   3. Crea un grafo dirigido a partir de los registros, calculando grados de salida.
//   4. Determina y muestra la red con mayor cantidad de hosts registrados.
//   5. Determina y muestra los hosts con mayor incidencia.
// Entradas: Ninguna.
// Salidas: Resultados impresos en la consola.
// Complejidad Mejor Caso: No aplica.
// Complejidad Peor Caso: Depende de la cantidad de registros y la eficiencia del algoritmo de ordenamiento.
// Miércoles 23 de Noviembre del 2023
// Integrantes:
//   * Rodrigo López Guerra A01737437
*/

// Librerías
#include <iostream>
#include <fstream>
#include <vector>

//Espacio de Trabajo
using namespace std;

// Estructura conjunto
struct Registro {
    string value;
    string mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    int red;
    int subred;
    int dominio;
    int ordenador;
    int puerto;
    string falla;

    Registro() {}

    // Obtener mes
    int numMes(string){
        // Función que asigna un número a cada mes para facilitar la comparación
        // Entradas: Ninguna
        // Salidas: Entero representando el mes (1-12)
        // Complejidad: O(1) - Operaciones constantes
        if(mes == "Jan") return 1;
        if(mes == "Feb") return 2;
        if(mes == "Mar") return 3;
        if(mes == "Apr") return 4;
        if(mes == "May") return 5;
        if(mes == "Jun") return 6;
        if(mes == "Jul") return 7;
        if(mes == "Aug") return 8;
        if(mes == "Sep") return 9;
        if(mes == "Oct") return 10;
        if(mes == "Nov") return 11;
        if(mes == "Dec") return 12;
        return 0;
    }

    // Sobrecarga de Operador
    bool operator<(const Registro& next) {
        // Función que compara dos registros para ordenarlos según la jerarquía especificada
        // Entradas: Registro a comparar (next)
        // Salidas: Booleano indicando si el registro actual es menor que el próximo
        // Complejidad: O(1) - Operaciones constantes
        if (red < next.red) return true;
        else if (red == next.red) {
            if (subred < next.subred) return true;
            else if (subred == next.subred) {
                if (dominio < next.dominio) return true;
                else if (dominio == next.dominio) {
                    if (ordenador < next.ordenador) return true;
                    else if(ordenador == next.ordenador) {
                        if (puerto < next.puerto) return true;
                        else if(puerto == next.puerto) {
                            if (numMes(mes) < numMes(next.mes)) return true;
                            else if (numMes(mes) == numMes(next.mes)){
                                if (dia < next.dia) return true;
                                else if (dia == next.dia){
                                    if (hora < next.hora) return true;
                                    else if (hora == next.hora){
                                        if (minuto < next.minuto) return true;
                                        else if (minuto == next.minuto){
                                            if (segundo < next.segundo) return true;
                                            else if (segundo == next.segundo){
                                                if(falla < next.falla) return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }

    string leerHost(){
        // Función que devuelve la información del host en formato dominio.ordenador
        // Entradas: Ninguna
        // Salidas: String con la información del host
        // Complejidad: O(1) - Operaciones constantes
        string host = to_string(dominio) +"." + to_string(ordenador);
        return host;
    }

    string leerRedCompleta(){
        // Función que devuelve la información de la red en formato red.subred
        // Entradas: Ninguna
        // Salidas: String con la información de la red
        // Complejidad: O(1) - Operaciones constantes
        string redCompleta = to_string(red) + "." + to_string(subred);
        return redCompleta;
    }

    string leerIp(){
        // Función que devuelve la dirección IP completa en formato red.subred.dominio.ordenador
        // Entradas: Ninguna
        // Salidas: String con la dirección IP completa
        // Complejidad: O(1) - Operaciones constantes
        string redCompleta = to_string(red) + "." + to_string(subred);
        string host = to_string(dominio) +"." + to_string(ordenador);
        string ip = redCompleta + "." + host;
        return ip;
    }

    // Constructor para inicializar un registro
    Registro(string val, string m, int d, int h, int min, int s, int r, int subr, int dom, int ord, int p, string f)
            : value(val), mes(m), dia(d), hora(h), minuto(min), segundo(s), red(r), subred(subr), dominio(dom),
              ordenador(ord), puerto(p), falla(f) {}
};


// Estructura conjunto
struct conjunto{
    string ip;
    int gradoSalir = 0;
    vector<conjunto*> registrar;
    conjunto* down = NULL;
};

// Funciones
int partition(vector<Registro> &values, int left, int right) {
    // Función que elige un pivote para comparar con el resto de datos y particiona el vector en dos partes
    // Entradas: Vector válido y elementos izquierdo y derecho
    // Salidas: Número entero
    // Complejidad Mejor Caso: O(n) - Lineal
    // Complejidad Peor Caso: O(n^2) - Cuadrática, aunque en este código se utiliza un enfoque de partición de Hoare para mitigar esto
    int pivotIndex = left + (right - left) / 2;
    Registro pivotValue = values[pivotIndex];
    int i = left, j = right;
    Registro temp;
    while(i <= j) {
        while(values[i] < pivotValue) {
            i++;
        }
        while(pivotValue < values[j]  ) {
            j--;
        }
        if(i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}


void quicksort(vector<Registro> &values, int left, int right) {
    // Función que ordena los elementos con el método de quicksort
    // Entradas: Vector válido y elementos izquierdo y derecho
    // Salidas: Nada
    // Complejidad Mejor Caso: O(n log n) - Lineal
    // Complejidad Peor Caso: O(n^2) - Cuadrática
    if(left < right) {
        int pivotIndex = partition(values, left, right);
        quicksort(values, left, pivotIndex - 1);
        quicksort(values, pivotIndex, right);
    }
}

// Función main
int main(){
    vector <Registro> nodos;
    ifstream file("bitacora2.txt");
    ifstream file2("bitacora2.txt");

    string value, mes, dia, hora, minuto, segundo, red, subred, dominio, ordenador,puerto,falla;
    while(getline (file2, value)){
        getline (file, mes, ' ');
        getline (file, dia, ' ');
        getline (file, hora, ':');
        getline (file, minuto, ':');
        getline (file, segundo, ' ');
        getline (file, red, '.');
        getline (file, subred, '.');
        getline (file, dominio, '.');
        getline (file, ordenador, ':');
        getline (file, puerto, ' ');
        getline (file, falla);
        nodos.push_back(Registro(value, mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo), stoi(red),
                                 stoi(subred), stoi(dominio), stoi(ordenador), stoi(puerto), falla));
    }

    // Llama a quicksort pasando el vector de registros
    quicksort(nodos, 0, nodos.size() - 1);

    struct conjunto* root, *host, *restante;

    // Creación del grafo: Se crea el grafo, en donde se relacionan los nodos correspondientes y se definen sus grados de salida
    if(nodos.empty()){
        return 0;
    }
    else{
        if(!nodos.empty()){
            restante = new conjunto();
            restante -> ip = nodos[0].leerIp();
            host = new conjunto;
            host->ip = nodos[0].leerHost();
            host->gradoSalir++;
            host->registrar.push_back(restante);
            root = new struct conjunto();
            root->ip = nodos[0].leerRedCompleta();
            root->gradoSalir++;
            root->registrar.push_back(host);

            struct conjunto* current = root;

            for(int i = 1; i < nodos.size(); i++){
                if(nodos[i].leerRedCompleta() == nodos[i - 1].leerRedCompleta()){
                    if(nodos[i].leerHost() == nodos[i - 1].leerHost()){
                        restante = new conjunto();
                        restante -> ip = nodos[i].leerIp();
                        host->gradoSalir++;
                        host->registrar.push_back(restante);
                    }
                    else{
                        current->gradoSalir++;
                        restante = new conjunto;
                        restante -> ip = nodos[i].leerIp();
                        host = new conjunto;
                        host->ip = nodos[i].leerHost();
                        host->gradoSalir++;
                        host->registrar.push_back(restante);
                        current->registrar.push_back(host);
                    }
                }
                else{
                    restante = new conjunto;
                    restante -> ip = nodos[i].leerIp();
                    current->down = new struct conjunto();
                    current = current->down;
                    host = new conjunto;
                    host->ip = nodos[i].leerHost();
                    host->gradoSalir++;
                    host->registrar.push_back(restante);
                    current->ip = nodos[i].leerRedCompleta();
                    current->gradoSalir++;
                    current->registrar.push_back(host);
                }
            }
        }


        struct conjunto *current = root;

        int max = 0, maxH = 0;

        struct conjunto *maxRoot = root, *printRoot = root, *maxHost = root, *printH = root;


        while(maxRoot != NULL){
            if (maxRoot->gradoSalir > max)
                max = maxRoot -> gradoSalir;
            maxRoot = maxRoot->down;
        }

        while(printRoot != NULL){
            if(max == printRoot -> gradoSalir)
                cout<<printRoot->ip<<endl;
            printRoot = printRoot -> down;
        }

        cout<<"\n";

        while(maxHost != NULL){
            for(int i=0;i < maxHost->registrar.size(); i++ )
                if((maxHost -> registrar[i])->gradoSalir > maxH)
                    maxH = (maxHost -> registrar[i])->gradoSalir;
            maxHost = maxHost->down;
        }

        while(printH!= NULL){
            for(int i=0;i < printH->registrar.size(); i++ )
                if((printH -> registrar[i])->gradoSalir == maxH)
                    cout << ((printH -> registrar[i])->registrar[0])->ip << endl;
            printH = printH -> down;
        }
    }
    return 0;
}

