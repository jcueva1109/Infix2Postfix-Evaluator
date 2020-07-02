#include <iostream>
#include <stdio.h>
#include <typeinfo.h>	//Para usar auto
#include <math.h>		//Para la potencia
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Nodo {

	string dato;
	Nodo* siguiente;
	Nodo() : siguiente(nullptr) {}	//Feature de C++11

};

//Feature de C++17
namespace X {

	string bienvenida = "Bienvenido a mi proyecto!";
	string despedida = "Hasta Pronto!";
}

//Feature de C++14
template <class T>
inline T pi = T(3.14'159'265'358'979'323'85L);		//Feature de C++14
//Feature de C++17

//Feature de C++14
template <class J>
inline J e = J(2.718'281'828'459'045'235'360);		//Feature de C++14
//Feature de C++17

//Feature de C++17
template<typename ...Args>
void print(Args&& ... args) {
	(std::cout << ... << args) << '\n';
}

Nodo* pila = nullptr;			//Feature de C++11	
string* arreglo;
vector <string> holi;
auto t = 0;					//Feature de C++11
auto expected = "";
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
double String2int(string, string, int);
string int2String(double);
bool checkInput(string);
bool checkMod(int, double);

//Funciones AUX2
int precedenceValue(string);
int checkPrecedence(string, string);
int isOpeningBracket(string);
int isClosingBracket(string);
int isNumber(string);
int isOperator(string);
void reset();

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

	while (opcion != 3) {

		cout << X::bienvenida << endl;
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
			cout << "9. 30 + 15 - 25" << endl;	//funciona
			cout << "10. 100 / 0" << endl;			//no funciona
			cout << "11. pi(15)^2" << endl;
			cout << "12. Valor Euler" << endl;
			cout << "13. j+2+3" << endl;
			cin >> tc;

			switch (tc) {
			case 1:
				testCase1();
				//Feature de C++17
				[[fallthrough]] ;	//Probando test case
				break;
			case 2:
				testCase2();
				[[fallthrough]] ;	//Probando test case
				break;
			case 3:
				testCase3();
				[[fallthrough]] ;	//Probando test case
				break;
			case 4:
				testCase4();
				[[fallthrough]] ;	//Probando test case
				break;
			case 5:
				testCase5();
				[[fallthrough]] ;	//Probando test case
				break;
			case 6:
				testCase6();
				[[fallthrough]] ;	//Probando test case
				break;
			case 7:
				testCase7();
				[[fallthrough]] ;	//Probando test case
				break;
			case 8:
				testCase8();
				[[fallthrough]] ;	//Probando test case
				break;
			case 9:
				testCase9();
				[[fallthrough]] ;	//Probando test case
				break;
			case 10:
				testCase10();
				[[fallthrough]] ;	//Probando test case
				break;
			case 11:
				testCase11();
				[[fallthrough]] ;	//Probando test case
				break;
			case 12:
				testCase12();
				[[fallthrough]] ;	//Probando test case
				break;
			case 13:
				testCase13();
				[[fallthrough]] ;	//Probando test case
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
				reset();

			}

			break;
		case 3:
			cout << X::despedida << endl;
			break;
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
	auto error = false, error2 = false, error3 = false, error4 = false;

	while (i < t) {

		//Validar que cierre el parentesis
		//Contar cuantos parentesis izquierdos hay, y preguntar si hay la misma cantidad de parentesis derechos 
		if (arreglo[i] == "(")
			izquierdo++;

		if (arreglo[i] == ")")
			derecho++;

		//Validar que no divida entre 0
		if ((arreglo[i] == "/" || arreglo[i] == "%") && (arreglo[i -1] == "0" || arreglo[i+1] == "0") && (i != t - 1)){
			error = true;
		}

		//Validar expresion infija incorrecta
		if ((t - 1) == i) {
			if (arreglo[i] == "+" || arreglo[i] == "-" || arreglo[i] == "*" ||arreglo[i] == "/" || arreglo[i] == "%" || arreglo[i] == "^") {
				error2 = true;
			}
		}

		//Validar caracteres no permitidos
		if (arreglo[i] == "+" || arreglo[i] == "-" || arreglo[i] == "*" || arreglo[i] == "/" || arreglo[i] == "%" || arreglo[i] == "^" || arreglo[i] == "pi" || arreglo[i] == "(" || arreglo[i] == ")" || arreglo[i] == "e") {

		}
		else {

			if (checkInput(arreglo[i]) == true) {
				error3 = true;
			}
			else {

				int modx = stoi(arreglo[i]);
				double mody = stod(arreglo[i]);

				if (checkMod(modx, mody) == false) {
					error4 = true;
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

	if (error3 == true) {
		cout << "Introdujiste un caracter invalido!" << endl;
		error404 = true;
	}

	/*if (error4 == true) {
		cout << "No puedes realizar estar operacion con puntos flotantes!" << endl;
		error404 = true;
	}*/

	if (izquierdo > derecho) {
		cout << "Olvidaste cerrar el parentesis izquierdo '('!" << endl;
		error404 = true;
	}

}

void expresionesPostfijas() {

	auto i = 0;
	auto myString = string();
	stack<string> string_stack;

	for (i = 0; i < t; i++) {		//recorremos individualmente las posiciones

		myString = arreglo[i];	//temp_storage

		if (isOpeningBracket(myString)) {	//Si es un parentesis izquierdo, entra a la pila
			string_stack.push(myString);	
		}
		//Esta cerrando el parentesis
		else if (isClosingBracket(myString)) {

			//1. saca los elementos hasta que se encuentre el parentesis izquierdo
			while (!isOpeningBracket(string_stack.top())){

				holi.push_back(string_stack.top());
				string_stack.pop();
				if (string_stack.empty())	break;

			}

			//2. Sacando el parentesis izquierdo
			if (!string_stack.empty()) {
				string_stack.pop();
			}

		}//Si es un numero lo agregamos al resultado
		else if (isNumber(myString)) {
			holi.push_back(myString);
		}
		else if (isOperator(myString)) {

			if (string_stack.empty() || isOpeningBracket(string_stack.top())) {
				string_stack.push(myString);
				continue;
			}

			//Revisamos precedencia
			if (checkPrecedence(myString, string_stack.top())) {
				string_stack.push(myString);
			}
			else {

				while (!isOpeningBracket(string_stack.top())) {

					holi.push_back(string_stack.top());
					string_stack.pop();
					if (string_stack.empty())	break;

				}

				string_stack.push(myString);

			}

		}
		else {

			if (myString == "e") {
				holi.push_back(myString);
			}
			else if (myString == "pi") {
				holi.push_back(myString);
			}
			else {	//Si es un caracter invalido
				cout << "Ingresaste un caracter invalido!!" << endl;
			}
		}

	}	

	//Vaciamos la pila
	while (!string_stack.empty()) {

		holi.push_back(string_stack.top());
		string_stack.pop();

	}

	//Feature de C++17
	cout << "Imprimiendo resultado final..." << endl;
	for (int dim = 0; dim < holi.size(); dim++) {
		print("[" ,dim,"] ",holi[dim]);
	}

}

void evaluarPostfijas() {

	cout << endl;
	auto i = 0;
	auto resultado = 0.0;
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

double String2int(string x, string y, int operacion) {

	auto x1 = string();
	auto y1 = string();

	if (x == "e") {
		x1 = "2.718'281'828'459'045'235'360";
	}
	else if (x == "pi") {
		x1 = "3.141'592'653'589'793'2385";
	}
	else {
		x1 = x;
	}

	if (y == "e") {
		y1 = "2.718'281'828'459'045'235'360";
	}
	else if (y == "pi") {
		y1 = "3.141'592'653'589'793'2385";
	}
	else {
		y1 = y;
	}

	auto xx = stod(x1);
	auto yy = stod(y1);
	auto r = xx - xx;
	int xxx = xx;
	int yyy = yy;

	try {

		switch (operacion) {
		case 1:
			r = xx + yy;
			break;
		case 2:
			r = yy - xx;
			break;
		case 3:
			r = xx * yy;
			break;
		case 4:
			r = yy / xx;
			break;
		case 5:
			r = yyy % xxx;
			break;
		case 6:
			r = pow(yy, xx);
			break;
		default:
			r = 0;
			break;

		}

	}
	catch (invalid_argument const& e) {
		cout << "Bad input: invalid_argument thrown" << '\n';
	}
	catch (out_of_range const& e) {
		cout << "Integer overflow: out_of_range thrown" << '\n';
	}
	return r;
}

string int2String(double n) {

	string s = string();		//Feature de C++11
	s = to_string(n);		
	return s;
}

//Feature de C++14 Lambda Function
//[[deprecated]]
auto int2String2 = [](double n) {

	string s = string();
	s = to_string(n);
	return s;

};

bool checkInput(string x) {

	try {
		int numero = stod(x);
	}
	catch (const invalid_argument & e) {
		return true;
	}
	catch (const out_of_range & e) {
		return true;
	}

	return false;
}

bool checkMod(int x, double y) {

	if (x == y) {
		return false;
	}
	else {
		return true;
	}

}

/*Give the precedence value of the character or operator*/
int precedenceValue(string x) {

	if (x == "^") {
		return 3;
	}
	else if (x == "*" || x == "/" || x == "%") {
		return 2;
	}
	else if (x == "+" || x == "-") {
		return 1;
	}
	else {
		return 0;
	}

}

/*If precedence of the first operator is greater than other then return true else return false*/
int checkPrecedence(string fx, string sy) {
	return (precedenceValue(fx) > precedenceValue(sy));
}

//Check wether the given character is an opening bracket or not
int isOpeningBracket(string x) {
	return (x == "(");
}

//Check wether the given character is a closing bracket or not
int isClosingBracket(string x) {
	return (x == ")");
}

//Check whether the given character is a number or not
int isNumber(string x) {
	
	int numero = 0;

	try {
		numero = stoi(x);
	}
	catch (const invalid_argument & e) {
		return 0;
	}
	catch (const out_of_range & e) {
		return 0;
	}

	return numero;

}

//Check wether the character is operator or not
int isOperator(string x) {

	return (x == "+" || x == "-" || x == "*" || x == "/" || x == "^");

}

void reset() {

	

}

void testCase1() {

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
	expresionesPostfijas();
	expected = "16.000000";
	evaluarPostfijas();
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
	expected = "7.000000";
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
	expected = "9.000000";
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
	expected = "1.000000";
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
	expected = "8.000000";
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
	expected = "2.000000";
	evaluarPostfijas();

}

void testCase9() {

	t = 5;
	arreglo = new string[t];

	arreglo[0] = "30";
	arreglo[1] = "+";
	arreglo[2] = "15";
	arreglo[3] = "-";
	arreglo[4] = "25";

	//Validaciones();
	expresionesPostfijas();
	expected = "20.000000";
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

	cout << pi<double> * pow(15, 2) << endl;

}

void testCase12() {

	cout << "El valor de euler es de: " << e<long double> << endl;

}

void testCase13(){

	t = 5;
	arreglo = new string[t];

	arreglo[0] = "j";
	arreglo[1] = "+";
	arreglo[2] = "2";
	arreglo[3] = "+";
	arreglo[4] = "3";
	Validaciones();

	if (error404 == true) {
		
	}
	else {

		expresionesPostfijas();
		expected = "error!";
		evaluarPostfijas();

	}
}
