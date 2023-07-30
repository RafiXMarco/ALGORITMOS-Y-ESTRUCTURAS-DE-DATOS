// AUTOR: Marco Napierski
// FECHA: 18.04.2022
// EMAIL: alu0101469317@ull.edu.es 
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// 

#ifndef SLLPOLYNOMIAL_H_
#define SLLPOLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "pair_t.h"
#include "sll_t.h"
#include "vector_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;  // Campo data_ de SllPolynomial
typedef sll_node_t<pair_double_t> SllPolyNode;  // Nodos de SllPolynomial

// Clase para polinomios basados en listas simples de pares
class SllPolynomial : public sll_t<pair_double_t> {
 public:
  // constructores
  SllPolynomial(void) : sll_t() {};
  SllPolynomial(const vector_t<double>&, const double = EPS);

  // destructor
  ~SllPolynomial() {};

  // E/S
  void Write(std::ostream& = std::cout) const;
  
  // operaciones
  double Eval(const double) const;
  bool IsEqual(const SllPolynomial&, const double = EPS) const;
  void Sum(const SllPolynomial&, SllPolynomial&, const double = EPS);
  void Modificacion(SllPolynomial&);
};


bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

// FASE II
// constructor
SllPolynomial::SllPolynomial(const vector_t<double>& v, const double eps) {
  // poner el código aquí  

  for (int i = v.get_size(); i > 0; i--) {
    if(IsNotZero(v.get_val(i-1))) {
      push_front(new SllPolyNode(pair_double_t(v.get_val(i -1),i-1))); 
    }
  }
}


// E/S
void SllPolynomial::Write(std::ostream& os) const {
  os << "[ ";
  bool first{true};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    if (val > 0)
      os << (!first ? " + " : "") << val;
    else
      os << (!first ? " - " : "-") << fabs(val);
    os << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
    aux = aux->get_next();
  }
  os << " ]" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const SllPolynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

// FASE III
// Evaluación de un polinomio representado por lista simple
double SllPolynomial::Eval(const double x) const {
  double result{0.0};
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    int inx{aux->get_data().get_inx()};
    double val{aux->get_data().get_val()};
    aux = aux->get_next();
    result = result + val*(pow(x,inx));
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por listas simples
bool SllPolynomial::IsEqual(const SllPolynomial& sllpol,
			    const double eps) const {
  bool differents = false;
  // poner el código aquí
  SllPolyNode* aux1{get_head()};
  SllPolyNode* aux2{sllpol.get_head()};
  while (aux1 != NULL || aux1 != NULL) {
    int inx1{aux1->get_data().get_inx()};
    int inx2{aux2->get_data().get_inx()};
    double val1{aux1->get_data().get_val()};
    double val2{aux2->get_data().get_val()};
    if((inx1 != inx2 )&&(val1 != val2 )) {
      differents = true;
      break;
    }
    aux1 = aux1->get_next();
    aux2 = aux2->get_next();
  }
  return !differents;
}

// FASE IV
// Generar nuevo polinomio suma del polinomio invocante mas otro polinomio
void SllPolynomial::Sum(const SllPolynomial& sllpol,
			SllPolynomial& sllpolsum,
			const double eps) {
  // poner el código aquí
  vector_t<double> v;
  int medida = 0;
  int medida2 = 0;
  int medida3 = 0;
  SllPolyNode* aux{get_head()};
  while (aux != NULL) {
    medida2 = aux->get_data().get_inx();
    aux = aux->get_next();
  }
  SllPolyNode* aux2{sllpol.get_head()};
  while (aux2 != NULL) {
    medida3 = aux2->get_data().get_inx();
    aux2 = aux2->get_next();
  }
  /////////////////////
  medida = std::max(medida2,medida3);
  v.resize(medida + 1);
  /////////////////////
  aux = get_head();
  while (aux != NULL) {
    v[aux->get_data().get_inx()] = aux->get_data().get_val();
    aux = aux->get_next();
  }
  aux2 = sllpol.get_head();
  while (aux2 != NULL) {
    v[aux2->get_data().get_inx()] = aux2->get_data().get_val() + v[aux2->get_data().get_inx()];
    aux2 = aux2->get_next();
  }
  ////////////////////////////
  for (int i = v.get_size(); i > 0; i--) {
    if(IsNotZero(v.get_val(i-1))) {
      sllpolsum.push_front(new SllPolyNode(pair_double_t(v.get_val(i -1),i-1))); 
    }
  }
}
// MODIFICACION
void SllPolynomial::Modificacion(SllPolynomial& modi) {
  vector_t<double> v;
  SllPolyNode* aux{get_head()};
  int medida = 0;
  while (aux != NULL) {
    medida = aux->get_data().get_inx();
    aux = aux->get_next();
  }
  v.resize(medida + 1);
  aux = get_head();
  while (aux != NULL) {
    int inx = aux->get_data().get_inx();
    if (inx % 2 != 0) {
      v[aux->get_data().get_inx()] = aux->get_data().get_val();
    }
    aux = aux->get_next();
  }
  for (int i = v.get_size(); i > 0; i--) {
    if(IsNotZero(v.get_val(i-1))) {
      modi.push_front(new SllPolyNode(pair_double_t(v.get_val(i -1),i-1))); 
    }
  }
}


#endif  // SLLPOLYNOMIAL_H_
