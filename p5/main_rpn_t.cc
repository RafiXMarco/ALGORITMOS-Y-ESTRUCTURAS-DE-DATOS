// AUTOR: MARCO NAPIESRKI
// FECHA: 9.
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Programa principal para probar la calculadora de expresiones 
//              en notaión polaca inversa (RPN, Reverse Polish Notation)
// COMPILACIÓN: g++ main_rpn_t.cc -o main_rpn_t
// EJECUCIÓN:
//   ./main_rpn_t < data_rpn_t_1.txt
//   ./main_rpn_t < data_rpn_t_2.txt
//   ./main_rpn_t < data_rpn_t_3.txt

// Compilar con:
// 

#include <iostream>

#include "stack_l_t.h"
#include "queue_l_t.h"
#include "rpn_t.h"

using namespace std;

int main(void) {
  rpn_t<stack_l_t<int>> calculadora;
  queue_l_t<char> cola;
	
  while (!cin.eof()) 	{
    cin >> ws; // lee los espacios en blanco, que dan problemas
    if (!cin.eof()) {
      char c;
      cin >> c;
      cola.push(c);
    }
  }

  //cout << "Expresión a evaluar: ";	
  //cola.write();

  //int r = calculadora.evaluate(cola);
  //cout << "Resultado: " << r << endl;

stack_l_t<int> a;
  a.push(1);
  a.push(2);
  a.push(3);
  a.push(4);
  a.push(5);
  cout << a.count();
  return 0;

  

}

