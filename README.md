# LP_EvaluadordeExpresiones
Proyecto de Lenguajes de Programación "Evaluador de Expresiones"
Este proyecto fue realizado en C++ con el proposito de ser presentado en la clase de Lenguajes de Programacion que curso.

Es un programa de consola que toma como entrada una expresion aritmetica en forma infija y el algoritmo convierte esta entrada a una expresion postfija, para su evaluación. 
Para realizar esta conversion se tienen en cuenta varias reglas, PEMDAS. 
Al tener nuestra expresion postfija se procede a evaluar. Recorremos el resultado obtenido y cuando se encuentra un operador tales como ('+','-','*','/','%','^') se toman los dos digitos anteriores a este operador y se realiza la operacion que dicta el operador actual. Este resultado se almacena en la misma posicion del operador y se continua con la evaluacion hasta haber recorrido toda la expresion postfija. 
Por ultimo se muestra este resultado en pantalla. 

El programa utiliza la metodologia TDD, Test Driven Development, al usar test cases para su validación.

Por ultimo, se utilizaron features de C++11, C++14, C++17, siendo un total de 4 features por version con un total de 12 features entre todas. 
