// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);
  //void //count_pair(stack_l_t<int>);

 private: 
  T stack_;
  void operate_(const char operador);
};

int count= 0;
int max= 0;
// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
 
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      // poner código
      stack_.push(i);
      if(i%2==0) count = count +1;
      max = max +1;
      std::cout << " (es un dígito) " << i << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      // poner código
      operate_(c);
    }
  }
  // poner código
  return stack_.top();
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' ||c == '^' || c == 'r' || c == 'l' || c == 'c');
  //count_pair();
  // poner código
  int val2 = stack_.top();
  int val1;
  stack_.pop();
  if(val2%2==0){count--;}
  max--;
  // poner código
  if ( c != 'r' && c != 'l' && c != 'c')val1 = stack_.top();
  if ( c != 'r' && c != 'l' && c != 'c'){
    stack_.pop();
    if(val1%2==0){count--;}
    max--;
  }
  std::cout << "   Sacamos de la pila un operando: " << val2 << std::endl;
  if ( c != 'r' && c != 'l' && c != 'c')
  std::cout << "   Sacamos de la pila otro operando: "<< val1 << std::endl;
  
  int res;
  switch (c) {
    case '+':
        res = val1 + val2;
      break;
    // poner código resto de operadores
    case '-':
        res = val1 - val2;
      break;
    case '*':
        res = val1 * val2;
      break;
    case '/':
        res = val1 / val2;
      break;
    case '^':
        res = pow(val1,val2);
      break;
    case 'r':
        res = sqrt(val2);
      break;
    case 'l':
        res = log2(val2);
      break;
    case 'c':
        res = pow(val2,2);
      break;
      
  }

  // poner código
  std::cout << "   Metemos en la pila el resultado: " << res << std::endl;
  stack_.push(res);
  if (res%2 == 0){
    count++;
  }
  max++;
  //count_pair();
}

 
#endif  // RPNT_H_
