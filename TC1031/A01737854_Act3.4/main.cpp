/*
Act 3.4 - En esta actividad se trabajó con BST, donde se abre el archivo de entrada que será el archivo bitácora.txt. 
Se agregan todos los accesos por IP y se almcenan en una estructura tipo BST dónde la llave será la IP en orden numérico (el valor más pequeño sería 0.0.0.0:0). 
El nodo contiene toda la información del acceso, incluyendo la fecha, hora y mensaje de error. 
En caso de tener dos registros con la misma IP, el segundo criterio de desempate es la fecha, y luego la hora de acceso.
Posteriormente se encuentan las cinco IPs más altas y despliegue toda la información del acceso, usando el formato del archivo bitacora.txt 


Sábado 04 de Noviembre del 2023
Integrantes:
 * Emiliano Sánchez Dominguez A01736342
 * Cynthia Amador Santiago A01737854
 * Rodrigo López Guerra A01737437 
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

using namespace std;


struct Registro {
        string mes_Str; // Mes en texto
        int mes;        // Mes en entero
        int dia;        // Día
        string tiempo;  // Hora
        string ip;      // Dirección IP
        string mensaje; // Mensaje de registro
        //Sobrecarga de operador para comparar dos registros, si a < b. 
        bool operator | (const Registro& ip2) const {
            string ipNum1,ipNum2,ipNum3,ipNum4, puerto;
            istringstream strIp(ip);
            getline(strIp,ipNum1,'.');
            getline(strIp,ipNum2,'.'); 
            getline(strIp,ipNum3,'.');
            getline(strIp,ipNum4,':');
            getline(strIp,puerto,':');  
            string ip2Num1,ip2Num2,ip2Num3,ip2Num4, puerto2;
            istringstream strIp2(ip2.ip);
            getline(strIp2,ip2Num1,'.');
            getline(strIp2,ip2Num2,'.'); 
            getline(strIp2,ip2Num3,'.');
            getline(strIp2,ip2Num4,':');
            getline(strIp2,puerto2);
            
            if (stoi(ipNum1) != stoi(ip2Num1)) {
                return stoi(ipNum1) < stoi(ip2Num1);
            }
            else if (stoi(ipNum2) != stoi(ip2Num2)) {
                return stoi(ipNum2) < stoi(ip2Num2);
            }
            else if (stoi(ipNum3) != stoi(ip2Num3)) {
                return stoi(ipNum3) < stoi(ip2Num3);
            }
            else if (stoi(ipNum4) != stoi(ip2Num4)) {
                return stoi(ipNum4) < stoi(ip2Num4);
            }
            else if (stoi(puerto) != stoi(puerto2)) {
                return stoi(puerto) < stoi(puerto2);
            }
            else if (mes != ip2.mes){
                return mes < ip2.mes;
            }
            else if (dia != ip2.dia){
                return dia < ip2.dia;
            }
            else if (tiempo != ip2.tiempo){
                return tiempo < ip2.tiempo;
            }
            return false;              
        }
    
};

struct TreeNode {
    Registro registro;
    TreeNode* left;
    TreeNode* right;
    TreeNode* ancestro;
};

// Función para insertar un nuevo nodo en la posicion correspondiente en el BST
// Recibe el apuntador a la raiz del BST Y el dato entero que se va a insertar
// No retorna valor
// Complejidad: O(n) donde n es la altura del arbol ingresados si el arbol esta mal balanceado,
// o puede tener una complejidad puede ser logaritmica dado que la altura es el logaritmo de los datos
// Si el arbol esta balanceado. 
void insertarNodo(TreeNode*& root, Registro registro) {
    TreeNode* newNode = new TreeNode;
    newNode -> registro = registro;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> ancestro = NULL;
    //SI este es primer elemento
    if (root == nullptr) {
        root = newNode;
        newNode -> ancestro = NULL;
        return;
    }
    TreeNode* current = root;
    TreeNode* parent = NULL;

    while (current != nullptr) {
        parent = current;
        if (registro | current->registro) {
            current = current->left;
        } else if (current->registro | registro) {
            current = current->right;
        } else {
            // Si el valor ya existe en el árbol, eliminaria el nodo creado.
            delete newNode; // Elimina el nuevo nodo, ya que el valor es repetido
            return;
        }
    }
    if (registro | parent->registro) {
        parent->left = newNode;
    } else{
        parent->right = newNode;
    }
    newNode -> ancestro = parent;
}
//Funcion para obtener un numero numero entero correspondiente al mes del registro.
//Rescibe el string del registro. 
//Devuelve el valor entero correspondiente.  
//Complejidad O(m) donde m es el numero de mes que corresponde al registro. 
int obtenerIndiceMes(const string& mes) {
    static const string meses[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; ++i) {
        if (mes == meses[i]) {
            return i + 1;
        }
    }
    return -1; // Mes no encontrado
}

//Funcion para imprimir en la salida estandar el registro con el formato especificado. 
//Recibe el registro a imprimir
//No devuelve valor. 
//Complejidad O(1)
void imprimeRegistro(Registro linea){
    if (linea.mes_Str.empty() || linea.dia <= 0 || linea.mes <= 0 || linea.tiempo.empty() || linea.ip.empty() || linea.mensaje.empty()) {
        cout << "Registro no válido" << endl;
    } else {
        cout << linea.mes_Str << " " << linea.dia << " " << linea.tiempo << " " << linea.ip << " " << linea.mensaje << endl;
    }
}

//Funcion para imrpirmir los 5 registros mas grandes. 
//Recibe le apuntador a la raiz del BST
//No devuleve nada. 
//Complejidad O(n) en el peor caso en donde recorra todos los elementos del arbol hasta encontrar el mas grande.
//Pero la complejidad en el mejor caso seria O(5 log n)
void imprimecinco(TreeNode* root){
    stack<TreeNode*> pilaNodo;
    TreeNode* actual = root;
    int contador = 0;

    while (actual != NULL || !pilaNodo.empty() && contador < 5) {
        while (actual != NULL) {
            pilaNodo.push(actual);  
            actual = actual->right;
        }

        actual = pilaNodo.top();
        pilaNodo.pop();

        imprimeRegistro(actual->registro);
        contador++;
        actual = actual->left;
    }
}

// Función eliminar todos los nodos del arbol. 
// Recibe el apuntador a la raiz del BST Y el dato entero que se va a imprimir el nivel. 
// No retorna valor. 
// Complejidad: O(n) donde n es la cantidad de nodos del BST. 

void eliminar_arbol(TreeNode* root) {
    if (root == nullptr) {
        return; // Si el árbol está vacío, no hay nada que eliminar.
    }

    // Elimina los subárboles izquierdo y derecho
    eliminar_arbol(root->left);
    eliminar_arbol(root->right);

    // Libera la memoria del nodo actual
    delete root;
}

int main(){
    TreeNode* root = NULL;

    // Insertar elementos en el BST
    ifstream file("bitacora.txt");
    string line;

    while (getline(file, line)) {
        istringstream conjunto(line);
        Registro linea;
        conjunto >> linea.mes_Str >> linea.dia >> linea.tiempo >> linea.ip;
        getline(conjunto, linea.mensaje);
        linea.mes = obtenerIndiceMes(linea.mes_Str);
        insertarNodo(root, linea);
    }

    imprimecinco(root);
    eliminar_arbol(root);

    return 0;

};