// Miércoles 23 de Noviembre del 2023
// Integrantes:
//   * Rodrigo López Guerra A01737437

// Librerías
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Espacio de Trabajo
using namespace std;

// Estructura conjunto
struct registro {
    string value;
    string mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    string red;
    string subred;
    int dominio;
    int ordenador;
    int puerto;
    string falla;

    registro() {}

    // Obtener mes
    int numMes(string) {
        // Función que asigna un número a cada mes para facilitar la comparación
        // Entradas: Ninguna
        // Salidas: Entero representando el mes (1-12)
        // Complejidad: O(1) - Operaciones constantes
        if (mes == "Jan") return 1;
        if (mes == "Feb") return 2;
        if (mes == "Mar") return 3;
        if (mes == "Apr") return 4;
        if (mes == "May") return 5;
        if (mes == "Jun") return 6;
        if (mes == "Jul") return 7;
        if (mes == "Aug") return 8;
        if (mes == "Sep") return 9;
        if (mes == "Oct") return 10;
        if (mes == "Nov") return 11;
        if (mes == "Dec") return 12;
        return 0;
    }

    // Sobrecarga de Operador
    bool operator<(const registro& next) {
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

    string leerRedCompleta() {
        // Función que devuelve la información de la red en formato red.subred
        // Entradas: Ninguna
        // Salidas: String con la información de la red
        // Complejidad: O(1) - Operaciones constantes
        string redCompleta = red + "." + subred;
        return redCompleta;
    }

    string leerIp() {
        // Función que devuelve la dirección IP completa en formato red.subred.dominio.ordenador
        // Entradas: Ninguna
        // Salidas: String con la dirección IP completa
        // Complejidad: O(1) - Operaciones constantes
        string redCompleta = red + "." + subred;
        string host = to_string(dominio) + "." + to_string(ordenador);
        string ip = redCompleta + "." + host;
        return ip;
    }

    // Constructor para inicializar un registro
    registro(string val, string m, int d, int h, int min, int s, string r, string subr, int dom, int ord, int p, string f)
            : value(val), mes(m), dia(d), hora(h), minuto(min), segundo(s), red(r), subred(subr), dominio(dom),
              ordenador(ord), puerto(p), falla(f) {}
};

// Estructura conjunto
struct conjunto {
    string ip;
    int accesos = 0;
    vector<string> ipDiffs;
};

// Funciones

int particion(vector<registro>& values, int left, int right) {
    // Nombre de función: particion
    // Descripción: Escoge un dato pivote para comparar con el posArrto de datos.
    // Entrada: Vector válido y elementos izquierdo y derecho.
    // Salida: Un número entero.
    // Precondición: Ninguna.
    // Postcondición: Ninguna.
    // Grado de Complejidad: O(n) Lineal.
    int pivotposArr = left + (right - left) / 2;
    registro pivotValue = values[pivotposArr];
    int i = left, j = right;
    registro temp;
    while (i <= j) {
        while (values[i] < pivotValue) {
            i++;
        }
        while (pivotValue < values[j]) {
            j--;
        }
        if (i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<registro>& values, int left, int right) {
    // Nombre de función: quicksort
    // Descripción: Ordena los elementos con el método de quicksort.
    // Entrada: Vector válido y elementos izquierdo y derecho.
    // Salida: Ninguna.
    // Precondición: Ninguna.
    // Postcondición: Estructura de datos ordenada.
    // Grado de Complejidad: O(n) Lineal.
    if (left < right) {
        int pivotposArr = particion(values, left, right);
        quicksort(values, left, pivotposArr - 1);
        quicksort(values, pivotposArr, right);
    }
}

int calcularHash(int red) {
    // Nombre de función: calcularHash
    // Descripción: Calcula el hash para el dominio específico.
    // Entrada: 2 valores enteros.
    // Salida: Entero.
    // Precondición: Vector válido y ordenado.
    // Postcondición: Posición para agregar al arreglo.
    // Grado de Complejidad: O(n) Lineal.
    long long int posArr = red;
    return (posArr * posArr) % 32749;
}

void insertar(conjunto* data, conjunto *arr[]){
    // Nombre de función: insertar
    // Descripción: Inserta valores en la tabla hash.
    // Entrada: Apuntador a objeto de estructura conjunto y arreglo tipo conjunto.
    // Salida: Ninguna.
    // Precondición: Ninguna.
    // Postcondición: Inserción en la tabla hash.
    // Grado de Complejidad: O(n) Lineal.
    string ip1;
    stringstream X(data->ip);
    getline(X, ip1, '.');

    int Postarr = calcularHash(stoi(ip1));
    while(arr[Postarr] != NULL){
        Postarr++;
        if(Postarr > 32748){
            Postarr %= 32749;
        }
    }
    arr[Postarr] = data;
}

void print(conjunto* data) {
    // Nombre de función: print
    // Descripción: Imprime los valores de la ip requeridos.
    // Entrada: Apuntador a objeto tipo conjunto.
    // Salida: Ninguna.
    // Precondición: Ninguna.
    // Postcondición: Ninguna.
    // Grado de Complejidad: O(n) Lineal.
    cout << data->ip << endl;
    cout << data->accesos << endl;
    cout << data->ipDiffs.size() << endl;
    for (int j = 0; j < data->ipDiffs.size(); j++) {
        cout << data->ipDiffs[j] << endl;
    }
}

void search(string data, conjunto* arr[]){
    // Nombre de función: search
    // Descripción: Busca la entrada del dominio en la tabla hash.
    // Entrada: Vector válido y string.
    // Salida: Ninguna.
    // Precondición: Ninguna.
    // Postcondición: Tabla hash creada.
    // Grado de Complejidad: O(1) Constante.
    string ip1, ip2;
    stringstream X(data);
    getline(X, ip1, '.');
    getline(X, ip2);

    int cont = 0;
    int posArr = calcularHash(stoi(ip1));

    while(cont < 32749 && arr[posArr] != NULL){
        cont++;
        if(data == arr[posArr]->ip){
            print(arr[posArr]);
        }
        posArr++;
        if(posArr > 32748){
            posArr %= 32749;
        }
    }
}

// Función main
int main() {
    vector<registro> vect;
    ifstream file("bitacora2.txt");
    ifstream file2("bitacora2.txt");
    string dominio;
    string value, mes, dia, hora, minuto, segundo, red, subred, Elementoinio, ordenador, puerto, falla;

    while (getline(file2, value)) {
        getline(file, mes, ' ');
        getline(file, dia, ' ');
        getline(file, hora, ':');
        getline(file, minuto, ':');
        getline(file, segundo, ' ');
        getline(file, red, '.');
        getline(file, subred, '.');
        getline(file, Elementoinio, '.');
        getline(file, ordenador, ':');
        getline(file, puerto, ' ');
        getline(file, falla);

        vect.push_back(registro(value, mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo), red, subred, stoi(Elementoinio), stoi(ordenador), stoi(puerto), falla));
    }

    quicksort(vect, 0, vect.size() - 1);

    conjunto* arr[32749] = {};
    conjunto* data;
    int tamanio = 0;

    // Se reemplazaron los índices por la función de hash
    data = new conjunto;
    data->ip = vect[0].leerRedCompleta();
    data->accesos++;
    data->ipDiffs.push_back(vect[0].leerIp());
    insertar(data, arr);
    tamanio++;

    for (int i = 1; i < vect.size(); i++) {
            if (tamanio < 32749) {
                if (vect[i].leerRedCompleta() == vect[i - 1].leerRedCompleta()) {
                    data->accesos++;
                    if (vect[i].leerIp() != vect[i - 1].leerIp()) {
                        data->ipDiffs.push_back(vect[i].leerIp());
                    }
                } else {
                    data = new conjunto;
                    data->ip = vect[i].leerRedCompleta();
                    data->accesos++;
                    data->ipDiffs.push_back(vect[i].leerIp());
                    insertar(data, arr);
                    tamanio++;
                }
            } else {
                cout << "Tabla llena, imposible meter más datos\n";
                return 0;
            }
        }



        int m;
        string Elementos;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> Elementos;
            search(Elementos, arr);
        cout << endl;
    }

    return 0;
}