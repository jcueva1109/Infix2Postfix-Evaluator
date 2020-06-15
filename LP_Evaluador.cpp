
#include <iostream>
#include <typeinfo.h>	//Para usar auto
#include <string>
using namespace std;

struct Nodo {

	string dato;
	Nodo* siguiente;

};

//Funciones de la pila
void agregarPila(Nodo*&, string);
string sacarPila(Nodo*&, string&);
void imprimirElementos(Nodo*&);
void destruirPila(Nodo*&);

int main()
{

	int t;
	cout << "Ingrese dimension: ";
	cin >> t;
	string* arreglo;
	arreglo = new string[t];
	string operadores[10] = { "+", "-", "*", "/", "%", "pi", "e", "^", "(", ")" };

	for (int i = 0; i < t; i++) {
		cout << "Ingrese un valor para [" << i << "]";
		cin >> arreglo[i];
	}

	cout << "El contenido del arreglo es: ";
	for (int i = 0; i < t; i++) {
		cout << arreglo[i];
	}
	
	cout << endl;
	//Validaciones
	for (int i = 0; i < t; i++) {

		if (arreglo[i] == "+" && arreglo[i + 1] == "+") {
			cout << "error1!" << endl;
		}
		else if (arreglo[i] == "-" && arreglo[i + 1] == "-") {
			cout << "error2!" << endl;
		}if (arreglo[i] == "/" && arreglo[i + 1] == "/") {
			cout << "error3!" << endl;
		}
		else if (arreglo[i] == "*" && arreglo[i + 1] == "*") {
			cout << "error4!" << endl;
		}if (arreglo[i] == "%" && arreglo[i + 1] == "%") {
			cout << "error5!" << endl;
		}
		/*else if (arreglo[i] != "+" || arreglo[i] != "-" || arreglo[i] != "*" || arreglo[i] != "/" || arreglo[i] != "%") {
			cout << "error6!" << endl;
		}*/

		if (arreglo[i] == operadores[i]) {
			cout << "Caracter valido!" << endl;
		}
		else {
			cout << "Caracter Invalido!" << endl;
		}

	}
	cout << endl;
	//Agregar a la pila
	Nodo* pila = NULL;
	string resultado[10];	//Aqui se van a ir agregando los valores que no vayan a la pila

	for (int i = 0; i < t; i++) {

		//Agregamos los operadores a la pila
		if (arreglo[i] == "+" || arreglo[i] == "-" || arreglo[i] == "*" || arreglo[i] == "/" || arreglo[i] == "%" || arreglo[i] == "(") {
			agregarPila(pila, arreglo[i]);
		}
		else if (arreglo[i] == ")") {
			
			resultado[i] = sacarPila(pila, arreglo[i]);	//ESTOS QUE VOY SACANDO NO LOS ELIMINO, LOS METO A RESULTADO!!

			/*
			
			-> Posible solucion al problema del (
			-> Es hacer un ciclo dentro de este if que me recorra otra vez el arreglo
			-> en busca de ese PUTO ( y que cuando lo encuentre lo saque

			*/
			//Posible solucion!
			/*
			while (arreglo[i] != "(") {
				resultado[i] = sacarPila(pila, arreglo[i]);
			}
			*/

		}
		else {		//Agregamos los numeros al arreglo
			resultado[i] = arreglo[i];		//AQUI SOLO TIENEN QUE IR NUMEROS KBRON! 
		}

	}

	/*
	ACLARANDO DUDAS
	UN PARENTESIS IZQUIERDO ES: (
	UN PARENTESIS DERECHO ES:	)
	
	*/

	//Verificar Resultado/Pila
	cout << "Mostrar lo que tiene la pila: ";
	imprimirElementos(pila);
	cout << endl;
	cout << "Mostrar el resultado: " << endl;
	for (int i = 0; i < t; i++) {

		if (resultado[i] != " ") {
			cout << "[" << i << "]" << resultado[i] << endl;
		}
	}

	system("pause > null");
	return 0;

}

void agregarPila(Nodo*& pila, string n) {

	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;

}

string sacarPila(Nodo*& pila, string& n) {

	Nodo* temp = pila;
	n = temp->dato;
	pila = temp->siguiente;
	//delete temp;
	return temp->dato;

}

void imprimirElementos(Nodo*& pila) {

	Nodo* temp;
	temp = pila;

	while (temp != NULL) {
		cout << temp->dato << "-> ";
		temp = temp->siguiente;
	}

}

void destruirPila(Nodo*& pila) {

	Nodo* temp;

	while (pila != NULL) {

		temp = pila;
		pila = temp->siguiente;
		delete(temp);

	}

}