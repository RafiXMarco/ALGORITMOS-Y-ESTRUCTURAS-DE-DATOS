/** AUTOR: Marco Napierski
 * FECHA: 21/02/2022
 * EMAIL: alu0101469317@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 *PRÁCTICA Nº: 1
 *COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
              "C++ Programming Style Guidelines"
              https://geosoft.no/development/cppstyle.html
*/
// pauta de estilo Comment Style: comentarios multilínea usando "/* */"
#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

#define EPSILON 1e-6

using namespace std;

class rational_t {
  // pautas de estilo Declaration Order: primero "public", luego "protected" y después "private", omitir las vacías.
 public:
  // FASE I
  rational_t(const int = 0, const int = 1); // Constructor
  ~rational_t() {} // Destructor  
  // pauta de estilo Vertical Whitespace: el menor número de líneas de separación
  int GetNum() const; // Getter
  int GetDen() const; // Getter
  void SetNum(const int); // Setter
  void SetDen(const int); // Setter
  double Value(void) const;  // Método que devuelve el valor real del objeto racional pasado por parámetro
  // FASE II
  bool is_equal(const rational_t& r, const double precision = EPSILON) const;
  bool is_greater(const rational_t& r, const double precision = EPSILON) const;
  bool is_less(const rational_t& r, const double precision = EPSILON) const;
  // FASE III
  rational_t add(const rational_t& r);
  rational_t substract(const rational_t& r);
  rational_t multiply(const rational_t& r);
  rational_t divide(const rational_t& r);
  void write(ostream& = cout) const;  // Método para la extracción por pantalla del objeto racional
  void read(istream& = cin);  // Método para la inserción o lectura del teclado de entrada del objeto racional
  // pauta de estilo Access Control: hacer miembros no constantes de clase privados

  bool is_positive();

 private:
  // pauta de estilo Class Data Members: nombre de los atributos seguido de "_"
  int num_, den_; // Atributos privados
};
