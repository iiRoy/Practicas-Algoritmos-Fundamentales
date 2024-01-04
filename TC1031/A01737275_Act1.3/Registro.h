#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include <string>
using namespace std;


/* Definición los valores de la Clase Registro.
Parametros:
    string mesDemos: variable que guarda el string del mes para luego imprimirlo en la salida.
    string horaDemos: guarda el string de la hora para luego imprimirlo en la salida.
    string minutoDemos: guarda el string de los minutos para luego imrpimirlos en la salida.
    string segundoDemos: guarda el string de los segundos para luego imprimirlo en la salida.
    int mes: mes del registro como variable entera int (entero).
    int dia: dia del registro como variable entera int (entero).
    int hora: hora del registro como variable entera int (entero).
    int minuto: hora del registro como variable entera int (entero).
    int segundo: segundos del registro como variable entera int (entero).
    unsigned long long tiempo: la suma de la varible hora, minuto y segundo convertidos en segundos.
    string ipDemos: variable que guardael string del IP para luego imprimirlo en la salida.
    int ip1: primer valor de la IP guardada como variable entera int (entero).
    int ip2: segundo valor del IP  guardada como variable entera int (entero).
    int ip3: tercer valor de la IP guardada como variable entera int (entero).
    int ip4; cuarto valor de la IP guardada como variable entera int (entero).
    unsigned long long puerto: puerto de la IP guardada como variable entera int.(entero)
    string error: error de registro guardado como variable string.
valor de retorno:
  ningun valor de retorno*/ 
class Registro {
protected:
    string mesDemos;
    string horaDemos;
    string minutoDemos;
    string segundoDemos;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    unsigned long long tiempo;
    string ipDemos;
    int ip1;
    int ip2;
    int ip3;
    int ip4;
    unsigned long long puerto;
    string error;
public:
    Registro();
    Registro(string,string,string,string, int, int, int,int, int, unsigned long long,string, int,int,int,int,unsigned long long, string);
    int getMes();
    int getDia();
    int getHora();
    unsigned long long getTiempo();
    int getIp1();
    int getIp2();
    int getIp3();
    int getIp4();
    unsigned long long getPuerto();
    string getError();
    void setError(string);
    void setMeses(string);
    void setMesesInt(int);
    void setDia(string);
    void setTiempo(string);
    void setIps(string);
    void imprimirRegistro();
    bool operator>(const Registro &) const; 
    bool operator<(const Registro &) const; 
    bool operator<=(const Registro &) const; 
    bool operator>=(const Registro &) const; 
};


#endif