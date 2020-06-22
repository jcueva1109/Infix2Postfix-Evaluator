
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>	//Para usar auto
#include <math.h>		//Para la potencia
#include <string>
#include <vector>
using namespace std;

struct Nodo {

	string dato;
	Nodo* siguiente;

};

//Esto es una feature
template <class T>
constexpr T pi = T(3.1415926535897932385L);	//Variable Template

Nodo* pila = NULL;
string* arreglo;
vector <string> holi;
auto t = 0;					//Feature

//Funciones de la pila
void agregarPila(Nodo*&, string);
string sacarPila(Nodo*&, string&);
void imprimirElementos(Nodo*&);

//Funciones AUX
void ingresarExpresion();
void Validaciones();
void expresionesPostfijas();
void evaluarPostfijas();
int String2int(string, string, int);
string int2String(int);		//Feature

int main()
{
	
	//Entrada del usuario
	ingresarExpresion();
	//Validar la expresion
	Validaciones();
	//Convertir de infija a postfija
	expresionesPostfijas();
	//Evaluar expresion postfija
	evaluarPostfijas();

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
		cout << temp->dato << " -> ";
		temp = temp->siguiente;
	}

}

void ingresarExpresion() {

	cout << "Ingrese dimension: ";
	cin >> t;
	arreglo = new string[t];

	//Ingresar expresion
	for (int i = 0; i < t; i++) {
		cout << "Ingrese un valor para [" << i << "]";
		cin >> arreglo[i];
	}

	system("cls");

	//Mostrar expresion
	cout << "El contenido del arreglo es: ";
	for (int i = 0; i < t; i++) {
		cout << arreglo[i];
	}
	cout << endl;

}

void Validaciones() {

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

	}
	cout << endl;

}

void expresionesPostfijas() {

	//Agregar a la pila
	
	string omitir[10];		//Aqui agrego el parentesis izquierdo que omito
	
	//Llenamos el arreglo y la pila
	for (int i = 0; i < t; i++) {

		//Agregamos los operadores a la pila
		if (arreglo[i] == "+" || arreglo[i] == "-" || arreglo[i] == "*" || arreglo[i] == "/" || arreglo[i] == "%" || arreglo[i] == "(" || arreglo[i] == "^") {
			agregarPila(pila, arreglo[i]);
		}
		else {		//Agregamos los numeros al arreglo
			if (arreglo[i] != ")") {
				holi.push_back(arreglo[i]);
			}
		}

		//Botamos el parentesis izquierdo!!
		if (arreglo[i] == ")") {

			do {
				holi.push_back(sacarPila(pila, arreglo[i]));
				omitir[i] = sacarPila(pila, arreglo[i]);
				break;
			} while (arreglo[i] != "(");

		}

	}
	
	//Vaciamos la pila
	for (int i = 0; i < holi.size(); i++) {
		if (pila != NULL) {

			holi.push_back(sacarPila(pila, arreglo[i]));

		}
	}
	
	cout << "Imprimiendo resultado final..." << endl;
	for (int dim = 0; dim < holi.size(); dim++) {
		cout << "[" << dim << "]" << holi[dim] << endl;
	}

}

void evaluarPostfijas() {
	
	cout << endl;
	auto i = 0;
	auto resultado = 0.0;
	string x = " ", y = " ", salida = " ";

	do {

		if (holi[i] == "+") {

			x = sacarPila(pila, holi[i]);
			y = sacarPila(pila, holi[i]);
			resultado = String2int(x, y, 1);
			salida = int2String(resultado);
			cout << "El resultado es : " << salida << endl;
			agregarPila(pila, salida);
			
		}
		else if (holi[i] == "-") {
			
			x = sacarPila(pila, holi[i]);
			y = sacarPila(pila, holi[i]);
			resultado = String2int(x, y, 2);
			salida = int2String(resultado);
			cout << "El resultado es : " << salida << endl;
			agregarPila(pila, salida);

		}
		else if (holi[i] == "*") {
			
			x = sacarPila(pila, holi[i]);
			y = sacarPila(pila, holi[i]);
			resultado = String2int(x, y, 3);
			salida = int2String(resultado);
			cout << "El resultado es : " << salida << endl;
			agregarPila(pila, salida);

		}
		else if (holi[i] == "/") {

			x = sacarPila(pila, holi[i]);
			y = sacarPila(pila, holi[i]);
			resultado = String2int(x, y, 4);
			salida = int2String(resultado);
			cout << "El resultado es : " << salida << endl;
			agregarPila(pila, salida);
		}
		else if (holi[i] == "^") {

			x = sacarPila(pila, holi[i]);
			y = sacarPila(pila, holi[i]);
			resultado = String2int(x, y, 6);
			salida = int2String(resultado);
			cout << "El resultado es : " << salida << endl;
			agregarPila(pila, salida);

		}
		else {
			agregarPila(pila, holi[i]);
		}
		
		i++;	//No borrar esta linea

	} while (i < holi.size());

}

int String2int(string x, string y, int operacion) {

	auto a = 0, j = 0, resultado = 0;
	a = stoi(x);		//Parsear string a int
	j = stoi(y);		//Parsear string a int

	try {

		switch (operacion) {

		case 1:		//Es una suma
			resultado = a + j;
			break;
		case 2:		//Es una resta
			resultado = j - a;
			break;
		case 3:		//Es una multiplicacion
			resultado = a * j;
			break;
		case 4:		//Es una division
			resultado = j / a;
			break;
		case 5:		//Es un modulo
			resultado = 0;
			break;
		case 6:		//Es una potencia
			resultado = pow(j,a);
			break;
		default:
			resultado = 0;
			break;
		}

	}
	catch (invalid_argument const& e) {
		cout << "Bad input: invalid_argument thrown" << '\n';
	}
	catch (out_of_range const& e) {
		cout << "Integer overflow: out_of_range thrown" << '\n';
	}

	return resultado;

}

string int2String(int n) {

	auto s = to_string(n);		//feature
	return s;
}