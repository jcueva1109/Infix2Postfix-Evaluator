
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>	//Para usar auto
#include <math.h>		//Para la potencia
#include <string>
#include <vector>
using namespace std;

struct Nodo {

	string dato;
	Nodo* siguiente = nullptr;	//Feature de C++11

};

//Esto es una feature de C++14
template <class T>
constexpr T pi = T(3.1415926535897932385L);	//Variable Template

template <class J>
constexpr J e = J(2.718281828459045235360);

Nodo* pila = nullptr;			//Feature de C++11
string* arreglo;
vector <string> holi;
auto t = 0;					//Feature de C++11
auto expected = " ";
auto error404 = false;

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
string int2String(int);
bool checkInput(string);

//TEST CASES
void testCase1();
void testCase2();
void testCase3();
void testCase4();
void testCase5();
void testCase6();
void testCase7();
void testCase8();
void testCase9();
void testCase10();
void testCase11();
void testCase12();
void testCase13();

int main()
{

	auto opcion = 0, tc = 0;

	cout << "Bienvenido!" << endl;
	cout << "Que quieres hacer?" << endl;
	cout << "1. Correr test cases" << endl;
	cout << "2. Ejecutar programa" << endl;
	cout << "3. Salir" << endl;
	cin >> opcion;

	switch (opcion) {
	case 1:

		cout << "Selecciona el test case a ejecutar: " << endl;
		cout << "1. 10+(1+2)*2" << endl;		//funciona
		cout << "2. 1+2*3" << endl;			//funciona
		cout << "3. (1+2)*3" << endl;			//funciona
		cout << "4. 10+5+" << endl;			//no funciona
		cout << "5. 4%3" << endl;				//funciona
		cout << "6. (10+20+30" << endl;		//no funciona
		cout << "7. 2^3" << endl;				//funciona
		cout << "8. 1000/500" << endl;			//funciona
		cout << "9. 500 - 400 + 100" << endl;	//funciona
		cout << "10. 100 / 0" << endl;			//no funciona
		cout << "11. pi(15)^2" << endl;
		cout << "12. Valor Euler" << endl;
		cout << "13. j+2+3" << endl;
		cin >> tc;

		switch (tc) {
		case 1:
			testCase1();	
		break;
		case 2:
			testCase2();
		break;
		case 3:
			testCase3();
			break;
		case 4:
			testCase4();
			break;
		case 5:
			testCase5();
			break;
		case 6:
			testCase6();
		break;
		case 7:
			testCase7();
			break;
		case 8:
			testCase8();
			break;
		case 9:
			testCase9();
			break;
		case 10:
			testCase10();
			break;
		case 11:
			testCase11();
			break;
		case 12:
			testCase12();
			break;
		case 13:
			testCase13();
			break;
		}
		break;
		case 2:

			ingresarExpresion();
			Validaciones();

			if (error404 == true) {
			
			}
			else {
				expresionesPostfijas();
				evaluarPostfijas();
			}

			break;
	case 3:
		cout << "Hasta pronto!" << endl;
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
	cout << endl;

}

void Validaciones() {

	cout << "El contenido del arreglo es: ";
	for (int i = 0; i < t; i++) {
		cout << arreglo[i];
	}
	cout << endl;

	//Validaciones
	int i = 0, pos = 0, pos2 = 0, izquierdo = 0, derecho = 0;
	auto error = false, error2 = false;

	while (i < t){

		//Validar que no divida entre 0
		if (arreglo[i] == "/" || arreglo[i] == "%" && arreglo[i + 1] == "0") {
			error = true;
		}

		//Validar que cierre el parentesis
		//Contar cuantos parentesis izquierdos hay, y preguntar si hay la misma cantidad de parentesis derechos 
		if (arreglo[i] == "(")
			izquierdo++;

		if (arreglo[i] == ")")
			derecho++;

		//Validar expresion infija incorrecta y que no termine con un operador
		if ((t-1) == i){
			if(arreglo[i] == "+" || arreglo[i] == "-" || arreglo[i] == "*" || arreglo[i] == "/" || arreglo[i] == "%" || arreglo[i] == "^" || arreglo[i] == "pi") {
				error2 = true;
			}
			else {

				if (checkInput(arreglo[i]) == true) {
					error404 = true;
				}

			}
		}

		i++;	//no borrar esta linea
	}

	if (error == true) {
		cout << "No puedes realizar una division entre 0!" << endl;
		error404 = true;
	}

	if (error2 == true) {
		cout << "No puedes terminar una expresion con un operador!" << endl;
		error404 = true;
	}

	if (izquierdo > derecho) {
		cout << "Olvidaste cerrar el parentesis izquierdo '('!" << endl;
		error404 = true;
	}

	if (error404 == false) {
		cout << "Introdujiste un caracter invalido!" << endl;
	}
}

void expresionesPostfijas() {

	string omitir[10];		//Aqui agrego el parentesis izquierdo que omito
	
	//Llenamos el arreglo y la pila
	for (int i = 0; i < t; i++) {

		//Agregamos los operadores a la pila
		if (arreglo[i] == "(" || arreglo[i] == "^" || arreglo[i] == "*" || arreglo[i] == "/" || arreglo[i] == "%" || arreglo[i] == "+" || arreglo[i] == "-" || arreglo[i] == "pi") {
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
	auto i = 0, resultado = 0;
	string x = " ", y = " ", salida = " ";

	do {

		if (holi[i] == "^") {

			x = sacarPila(pila, holi[i]);
			y = sacarPila(pila, holi[i]);
			resultado = String2int(x, y, 6);
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
		else if (holi[i] == "%") {

			x = sacarPila(pila, holi[i]);
			y = sacarPila(pila, holi[i]);
			resultado = String2int(x, y, 5);
			salida = int2String(resultado);
			cout << "El resultado es : " << salida << endl;
			agregarPila(pila, salida);
		}
		else if (holi[i] == "+") {

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
		else if (holi[i] == "pi") {

			x = sacarPila(pila, holi[i]);
			y = sacarPila(pila, holi[i]);
			resultado = String2int(x, y, 0);
			salida = int2String(resultado);
			cout << "El resultado es : " << salida << endl;
			agregarPila(pila, salida);

		}
		else {
			agregarPila(pila, holi[i]);
		}
		
		i++;	//No borrar esta linea

	} while (i < holi.size());

	cout << endl;
	cout << "Expected: " << expected << endl;
	cout << "Found: " << salida << endl;

	if (salida == expected) {
		cout << "Test Case exitoso!" << endl;
		cout << endl;
	}
	else {
		cout << "Test case fallido!" << endl;
	}
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
			resultado = j % a;
			break;
		case 6:		//Es una potencia
			resultado = pow(j,a);
			break;
		case 7:		//pi
			resultado = 0;
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

bool checkInput(string x) {

	try {
		int numero = stoi(x);
	}
	catch (const invalid_argument& e) {
		return true;
	}
	catch (const out_of_range& e) {
		return true;
	}

	return false;
}

//Test Cases
/*
			cout << "1. 10+(1+2)*2" << endl;		//funciona
			cout << "2. 1+2*3" << endl;			//funciona
			cout << "3. (1+2)*3" << endl;			//funciona
			cout << "4. 10+5+" << endl;			//no funciona
			cout << "5. 4%3" << endl;				//funciona
			cout << "6. (10+20+30" << endl;		//no funciona
			cout << "7. 2^3" << endl;				//funciona
			cout << "8. 1000/500" << endl;			//funciona
			cout << "9. 500 - 400 + 100" << endl;	//funciona
			cout << "10. 100 / 0" << endl;			//no funciona
			cout << "11. pi(15)^2" << endl;
			cout << "12. e			<< endl;
			cout << "13. Caracter Invalido
*/

void testCase1(){

	t = 9;
	arreglo = new string[t];

	//Ingresar expresion
	arreglo[0] = "10";
	arreglo[1] = "+";
	arreglo[2] = "(";
	arreglo[3] = "1";
	arreglo[4] = "+";
	arreglo[5] = "2";
	arreglo[6] = ")";
	arreglo[7] = "*";
	arreglo[8] = "2";

	//Validamos el arreglo
	Validaciones();

	if (!error404) {

		expresionesPostfijas();
		expected = "16";
		evaluarPostfijas();
	}
}

void testCase2() {

	t = 5;
	arreglo = new string[t];

	//Ingresar expresion
	arreglo[0] = "1";
	arreglo[1] = "+";
	arreglo[2] = "2";
	arreglo[3] = "*";
	arreglo[4] = "3";
	//Validamos el arreglo
	//Validaciones();
	expresionesPostfijas();
	expected = "7";
	evaluarPostfijas();

}

void testCase3() {

	t = 7;
	arreglo = new string[t];

	arreglo[0] = "(";
	arreglo[1] = "1";
	arreglo[2] = "+";
	arreglo[3] = "2";
	arreglo[4] = ")";
	arreglo[5] = "*";
	arreglo[6] = "3";

	//Validaciones();
	expresionesPostfijas();
	expected = "9";
	evaluarPostfijas();

}

void testCase4() {

	t = 4;
	arreglo = new string[t];

	arreglo[0] = "10";
	arreglo[1] = "+";
	arreglo[2] = "5";
	arreglo[3] = "+";

	Validaciones();
	if (error404 == true) {

	}
	else {

		expresionesPostfijas();
		expected = "error!";
		evaluarPostfijas();

	}
}

void testCase5() {

	t = 3;
	arreglo = new string[t];

	arreglo[0] = "4";
	arreglo[1] = "%";
	arreglo[2] = "3";
	
	//Validaciones();
	expresionesPostfijas();
	expected = "1";
	evaluarPostfijas();

}

void testCase6() {

	t = 6;
	arreglo = new string[t];

	arreglo[0] = "(";
	arreglo[1] = "10";
	arreglo[2] = "+";
	arreglo[3] = "20";
	arreglo[4] = "+";
	arreglo[5] = "30";

	Validaciones();

	if (error404 == true) {

	}
	else {

		expresionesPostfijas();
		expected = "error!";
		evaluarPostfijas();

	}

}

void testCase7() {
	
	t = 3;
	arreglo = new string[t];

	arreglo[0] = "2";
	arreglo[1] = "^";
	arreglo[2] = "3";

	//Validaciones();
	expresionesPostfijas();
	expected = "8";
	evaluarPostfijas();

}

void testCase8() {

	t = 3;
	arreglo = new string[t];

	arreglo[0] = "1000";
	arreglo[1] = "/";
	arreglo[2] = "500";

	//Validaciones();
	expresionesPostfijas();
	expected = "2";
	evaluarPostfijas();

}

void testCase9() {

	t = 5;
	arreglo = new string[t];

	arreglo[0] = "500";
	arreglo[1] = "-";
	arreglo[2] = "400";
	arreglo[3] = "+";
	arreglo[4] = "100";

	//Validaciones();
	expresionesPostfijas();
	expected = "0";
	evaluarPostfijas();

}

void testCase10() {

	t = 3;
	arreglo = new string[t];

	arreglo[0] = "100";
	arreglo[1] = "/";
	arreglo[2] = "0";

	Validaciones();

	if (error404 == true) {

	}
	else {

		expresionesPostfijas();
		expected = "error!";
		evaluarPostfijas();

	}

}

void testCase11() {

	cout << "El resultado es de: " <<pi<double> * pow(15, 2);	
}

void testCase12() {

	cout << "El valor de euler es de: " << e<long double> << endl;

}

void testCase13() {

	t = 5;
	arreglo = new string[t];

	arreglo[0] = "j";
	arreglo[1] = "+";
	arreglo[2] = "2";
	arreglo[3] = "+";
	arreglo[4] = "3";
	Validaciones();

	if (error404 == false) {
		
	}
	else {

		expresionesPostfijas();
		expected = "error!";
		evaluarPostfijas();

	}

}