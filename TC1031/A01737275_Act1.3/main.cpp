/*
Evidencia Producto Integrador

Francisco Antionio Lopez Ricardez - A0173727
Rodrigo Lopez Guerra - A01737437

Fecha de Entrega: 20/09/23

Objetivo: Recibir una base de datos de un .txt para poder plasmar los datos a un nuevo archivo de texto de manera ordenada y limitada

Reto: Hacer el programa de la manerae más eficiente posible por medio de vectores y algoritmos de búsqueda y ordenamiento.

- - - - - - - - - o

Entradas: Un archivo de texto que contenga diversas entradas de datos en el siguiente formato: 

Mes en formato de texto
Dia en formato de numero
Hora en formato de hh:mm:ss
Direccion IP en formato IP1.IP2.IP3.IP4:IP5

- - - - - - - - - o

Salida:  archivo txt que contenga de manera limitada las entradas con el mismo formato de los datos de entrada del archivo de texto, ordenados de manera descendente.
*/

//Librerías
#include "Registro.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

//Espacio de Trabajo
using namespace std;

/* Definición del constructor vacio de la clase Registro.
Parametros:
  nungún parametro
valor de retorno:
  ningun valor de retorno
Complegidad:
  n*/ 
 Registro::Registro(){
   //Variables
   mesDemos = "";
   horaDemos = "";
   minutoDemos = "";
   segundoDemos = "";
   mes = 0;
   dia = 0;
   hora = 0;
   minuto = 0;
   segundo = 0;
   tiempo = 0;
   ipDemos = "";
   ip1 = 0;
   ip2 = 0;
   ip3 = 0;
   ip4 = 0;
   puerto = 0;
   error = "error";
 }
    

/* Definición del constructor parametrizado.
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
Registro::Registro(string mesDemos_,string horaDemos_, string minutoDemos_, string segundoDemos_,int mes_, int dia_, int hora_, int minuto_, int segundo_, unsigned long long tiempo_, string ipDemos_,int ip1_, int ip2_, int ip3_ , int ip4_,  unsigned long long puerto_, string error_) {
      mesDemos = mesDemos_;
      horaDemos = horaDemos_;
      minutoDemos = minutoDemos_;
      segundoDemos = segundoDemos_;
      mes = mes_;
      dia = dia_;
      hora = hora_;
      minuto = minuto_;
      segundo = segundo_;
      tiempo = tiempo_;
      ipDemos = ipDemos_ ;
      ip1 = ip1_;
      ip2 = ip2_;
      ip3 = ip3_;
      ip4 = ip4_;
      puerto = puerto_;
      error = error_;
    }
/* función para obtener el mes en int
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor del mes */ 
    int Registro::getMes(){
      return mes;
    }
/* función para obtener el dia en int
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor del dia */ 
    int Registro::getDia(){
      return dia;
    }
/* función para obtener la hora en int
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor de la hora */ 
    int Registro::getHora(){
      return hora;
    }
/* función para obtener el tiempo en int
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor del tiempo */ 
    unsigned long long Registro::getTiempo(){
      return tiempo;
    }
/* función para obtener la primera parte del IP
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor de la primera parte de la IP */ 
    int Registro::getIp1(){
      return ip1;
    }
/* función para obtener la segunda parte del IP
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor de la segunda parte de la IP */ 
    int Registro::getIp2(){
      return ip2;
    }
/* función para obtener la tercera parte del IP
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor de la tercera parte de la IP */ 
    int Registro::getIp3(){
      return ip3;
    }
/* función para obtener la cuarta parte del IP
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor de la cuarta parte de la IP */ 
    int Registro::getIp4(){
      return ip4;
    }
/* función para obtener el puerto
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor del puerto */ 
    unsigned long long Registro::getPuerto(){
      return puerto;
    }
/* función para obtener el error obtenido
Parametros:
  ningún valor de ingreso. 
valor de retorno:
  regresa el valor del error */ 
    string Registro::getError(){
      return error;
    }
/* función que define los errores
Parametros:
  int error1: dato del error 
valor de retorno:
  ningún valor de retorno */ 
    void Registro::setError(string error1){
      error = error1;
    }
/* función que trasnforma los meses de string a ints
Parametros:
  int mes_: dato del mes 
valor de retorno:
  el mes regresado en int */ 
    void Registro::setMeses(string mes1){
      mesDemos = mes1;
      if (mes1 == "Jan")
        mes = 1;
      else if (mes1 == "Feb")
        mes = 2;
      else if (mes1 == "Mar")
        mes = 3;
      else if (mes1 == "Apr")
        mes = 4;
      else if (mes1 == "May")
        mes = 5;
      else if (mes1 == "Jun")
        mes = 6;
      else if (mes1 == "Jul")
        mes = 7;
      else if (mes1 == "Aug")
        mes = 8;
      else if (mes1 == "Sep")
        mes = 9;
      else if (mes1 == "Oct")
        mes = 10;      
      else if (mes1 == "Nov")
        mes = 11;      
      else if (mes1 == "Dec")
        mes = 12;      
    }
/* función que recibe el dato del mes como un int y lo guarda en una variable, en otra variable lo guarda convertido en una variable de tipo string.
Parametros:
  int mes_: dato del mes 
valor de retorno:
  nungún valor de retorno */ 
    void Registro::setMesesInt(int mes_) {
      mes = mes_;
      mesDemos = to_string(mes_);
    }
/* función que recibe el dato del dia como string  y lo guarda en una variable convirtiendo el string en un entero.
Parametros:
  string dia1: dato del día. 
valor de retorno:
  nungún valor de retorno */ 
    void Registro::setDia(string dia1){
      dia = stoi(dia1);
    }
/* función que recibe una cadena de strings con el formato HH:MM:SS la cual por medio de un ciclo extrae el valor de la hora, los minutos y los segundos guardandolos en sus respectivas variables de tipo string para luego guardar los mismos datos pero en varibales de tipo entero.
Parametros:
  string hora1: cadena de strings con el formato HH:MM:SS
valor de retorno:
  nungún valor de retorno */ 
    void Registro::setTiempo(string hora1){
      unsigned long long hora_en_segundos;
      unsigned long long minutos_en_segundos;
      string separador = "";
      vector<string> contenedor;
      for(int c : hora1) {
        if (c == ':') {
          contenedor.push_back(separador);
          separador = "";
        }
        else {
          separador += c;
        }
      }
      contenedor.push_back(separador);
      horaDemos = contenedor[0];
      minutoDemos = contenedor[1];
      segundoDemos = contenedor[2];
      hora = stoll(horaDemos);
      minuto = stoll(minutoDemos);
      segundo = stoll(segundoDemos);
      hora_en_segundos = hora*3600;
      minutos_en_segundos = minuto*60;
      tiempo = segundo + hora_en_segundos + minutos_en_segundos;
      
    }
/* función que recibe una cadena de strings con el formato NNN.N.NN.NN:NNN guardando la cadena en una variable y lugo la cual por medio de un ciclo extrae el valor de la ip después de cada punto guardandose en total 4 partes de la ip y el puerto guardandolos en varibales de tipo entero.
Parametros:
  string ip: cadena de strings con el formato HH:MM:SS
valor de retorno:
  nungún valor de retorno */ 
    void Registro::setIps(string ip) {
      vector<int> recopilador;
      ipDemos = ip;
      string separador = "";
      for(int c : ip) {
        if (c!=':' && c!='.') {
          separador += c;
        }
        else {
          recopilador.push_back(stoi(separador));
          separador = "";
        }
      }
      recopilador.push_back(stoi(separador));
      ip1 = recopilador[0];
      ip2 = recopilador[1];
      ip3 = recopilador[2];
      ip4 = recopilador[3];
      puerto = recopilador[4];
    }
/* función que imprime el registro
Parametros:
  ninguno
valor de retorno:
  impresión de los registros */ 
    void Registro::imprimirRegistro(){
      cout << mesDemos << " " << dia << " " << horaDemos << ":"<< minutoDemos << ":" << segundoDemos << " " << ipDemos << " "<< error << endl;
    }

    //Sobrecarga de operadores
    bool Registro::operator>(const Registro &R1) const {
      if (mes > R1.mes) {
        return true; 
      }
      else if (mes == R1.mes) {
        if(dia > R1.dia) {
          return true;
        }
        else if (dia == R1.dia) {
          if (tiempo > R1.tiempo) {
            return true;
          }
          else if(tiempo == R1.tiempo) {
            if(ip1 > R1.ip1){
              return true;
            }
            else if(ip1 == R1.ip1) {
              
              if(ip2 > R1.ip2) {
                return true;
              }
              else if(ip2 == R1.ip2) {
                if(ip3 > R1.ip3) {
                  return true;
                }
                else if(ip3 == R1.ip3) {
                  if(ip4 > R1.ip4) {
                    return true;
                  }
                  else if(ip4 == R1.ip4){
                    if (puerto > R1.puerto) {
                      return true;
                    }
                    else if (puerto == R1.puerto){
                      return false;
                    }
                      
                    else {
                      return false;
                    }
                  }  
                  else {
                    return false;
                  }
                }
                else {
                  return false;
                }
              }
              else {
                return false;
              }
            }
            else {
              return false;
            }
          }
          else {
            return false;
          }
        }
        else {
          return false;
        }
      }
      else {
        return false; 
      }
    }
    bool Registro::operator<(const Registro &R1) const{
            if (mes < R1.mes) {
        return true; 
      }
      else if (mes == R1.mes) {
        if(dia < R1.dia) {
          return true;
        }
        else if (dia == R1.dia) {
          if (tiempo < R1.tiempo) {
            return true;
          }
          else if(tiempo == R1.tiempo) {
            if(ip1 < R1.ip1){
              return true;
            }
            else if(ip1==R1.ip1) {
              
              if(ip2<R1.ip2) {
                return true;
              }
              else if(ip2==R1.ip2) {
                if(ip3<R1.ip3){
                  return true;
                }
                else if(ip3==R1.ip3) {
                  if(ip4<R1.ip4) {
                    return true;
                  }
                  else if(ip4==R1.ip4) {
                    if (puerto<R1.puerto) {
                      return true;
                    }
                    else if (puerto==R1.puerto) {
                      return false;
                    }
                      
                    else {
                      return false;
                    }
                  }  
                  else {
                    return false;
                  }
                }
                else {
                  return false;
                }
              }
              else {
                return false;
              }
            }
            else {
              return false;
            }
          }
          else {
            return false;
          }
        }
        else {
          return false;
        }
      }
      else {
        return false; 
      }
    }
    bool Registro::operator<=(const Registro &R1) const {
            if (mes < R1.mes) {
        return true; 
      }
      else if (mes == R1.mes) {
        if(dia<R1.dia) {
          return true;
        }
        else if (dia == R1.dia) {
          if (tiempo < R1.tiempo) {
            return true;
          }
          else if(tiempo == R1.tiempo) {
            if(ip1 < R1.ip1){
              return true;
            }
            else if(ip1 == R1.ip1) {
              
              if(ip2 < R1.ip2) {
                return true;
              }
              else if(ip2 == R1.ip2) {
                if(ip3 < R1.ip3){
                  return true;
                }
                else if(ip3 == R1.ip3) {
                  if(ip4 < R1.ip4) {
                    return true;
                  }
                  else if(ip4==R1.ip4) {
                    if (puerto < R1.puerto) {
                      return true;
                    }
                    else if (puerto == R1.puerto) {
                      return true;
                    }
                      
                    else {
                      return false;
                    }
                  }  
                  else {
                    return false;
                  }
                }
                else {
                  return false;
                }
              }
              else {
                return false;
              }
            }
            else {
              return false;
            }
          }
          else {
            return false;
          }
        }
        else {
          return false;
        }
      }
      else {
        return false; 
      }
    }

    bool Registro::operator>=(const Registro &R1) const {
      if (mes > R1.mes) {
        return true; 
      }
      else if (mes == R1.mes) {
        if(dia > R1.dia) {
          return true;
        }
        else if (dia == R1.dia) {
          if (tiempo > R1.tiempo) {
            return true;
          }
          else if(tiempo == R1.tiempo) {
            if(ip1 > R1.ip1){
              return true;
            }
            else if(ip1 == R1.ip1) {
              
              if(ip2 > R1.ip2) {
                return true;
              }
              else if(ip2 == R1.ip2) {
                if(ip3 > R1.ip3){
                  return true;
                }
                else if(ip3 == R1.ip3) {
                  if(ip4 > R1.ip4) {
                    return true;
                  }
                  else if(ip4 == R1.ip4) {
                    if (puerto > R1.puerto) {
                      return true;
                    }
                    else if (puerto == R1.puerto) {
                      return true;
                    }
                      
                    else {
                      return false;
                    }
                  }  
                  else {
                    return false;
                  }
                }
                else {
                  return false;
                }
              }
              else {
                return false;
              }
            }
            else {
              return false;
            }
          }
          else {
            return false;
          }
        }
        else {
          return false;
        }
      }
      else {
        return false; 
      }
    }


/* las funciones ubicacion_pivote y quicksort en conjunto ordenan un vector con objetos de tipo registro usando el metodo de ordenamiento de quicksort.
parametros:
  datos: vector el cual contiene los objetos de tipo registro a ordenar
  inicio: inicio del vector
  fin: el tamaño del vector menos 1
valor de retorno:
  de ubicacion_pivote:  int apuntador: regresa la ubicación del pivote actual
  de quicksort: (ningún valor de retorno)
complejidad:
  peor caso: n^2
  caso promedio: O (n log n) */ 
int ubicacion_pivote(vector<Registro>&datos,int inicio, int fin) {
  Registro pivote;
  Registro aux;
  pivote = datos[fin];
  int apuntador;
  apuntador = inicio;

  for(int i = inicio;i < fin;i++) {
    if(datos[i] <= pivote){
      aux = datos[i];
      datos[i] = datos[apuntador];
      datos[apuntador] = aux;
      apuntador++;
    }
  }
  aux = datos[fin];
  datos[fin] = datos[apuntador];
  datos[apuntador] = aux;
  return apuntador;
}

void quicksort(vector<Registro>&datos, int inicio, int fin) {
  if(inicio < fin){
    int pivote = ubicacion_pivote(datos, inicio,fin);
    quicksort(datos, inicio, (pivote-1));
    quicksort(datos,(pivote+1),fin);
  }
}

/* lectura del archivo txt que contiene los registros y salida a un txt delimitada por el usuario.
Parametros:
  nungún parametro
valor de retorno:
  0: se regresa un cero para saber que el programa terminó correctamente de ejecutarse*/ 
int main(){
  //Definición de Variables y Vectores
  vector<string> datos;
  vector<string> presentacion;
  vector<Registro> registros;
  Registro limiteinf;
  Registro limitesup;
  int identificador_de_datos;
  int contador;
  int inicio;
  int fin;
  int limiteMes;
  string dia_busqueda;
  string separador;
  separador = "";
  contador = 0;
  identificador_de_datos = 0;

//Lectura de la base de datos
ifstream infile("bitacora.txt");
string line;

//Creación de vectores por medio de espacios 
while (getline(infile, line)) {
  contador = 0;
  separador = "";
  
  for (int c:line) {
    if (c == ' ' && contador<4) {
      datos.push_back(separador);
      separador = "";
      contador++;
    }
    else {
      separador += c;
    }
  } 
  datos.push_back(separador);
}
  
  Registro prueba;
  int contadorRegistro;
  contadorRegistro = 0;
  for(int i = 0;i< datos.size()/5;i++) {
    prueba.setMeses(datos[contadorRegistro]);
    prueba.setDia(datos[contadorRegistro + 1]);
    prueba.setTiempo(datos[contadorRegistro + 2]);
    prueba.setIps(datos[contadorRegistro + 3]);
    prueba.setError(datos[contadorRegistro + 4]);
    registros.push_back(prueba);
    contadorRegistro += 5;
  }
  inicio = 0;
  fin = registros.size()-1;
  quicksort(registros, inicio, fin);

  // inicia busqueda de limites //
  cin >> limiteMes;
  limiteinf.setMesesInt(limiteMes);
  cin >> dia_busqueda;
  limiteinf.setDia(dia_busqueda);
  cin >> limiteMes;
  limitesup.setMesesInt(limiteMes);
  cin >> dia_busqueda;
  limitesup.setDia(dia_busqueda);
  ofstream salida("sorted.txt");
  streambuf* respaldo = std::cout.rdbuf(salida.rdbuf());
  
  for(int i=0; i<registros.size();i++) {
    if((registros[i].getMes() > limitesup.getMes()) || (registros[i].getMes() == limitesup.getMes() && registros[i].getDia() > limitesup.getDia()))  {
      break;
    }

    if((registros[i].getMes() > limiteinf.getMes()) || (registros[i].getMes() == limiteinf.getMes() && registros[i].getDia() >= limiteinf.getDia())) {
     registros[i].imprimirRegistro(); 
    } 
    
  }  
  cout.rdbuf(respaldo);
  salida.close();

return 0;

}
