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
#include "rational_t.hpp"

/**
 * @brief Constructor that initializes private atributes from class rational_t
 * @param[in] n: numerator
 * @param[in] d: denominator
 */
rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}
// pauta de estilo Vertical Whitespace: el menor número de líneas de separación

// Numerator Getter
int rational_t::GetNum() const {
  return num_;
}

// Denominator Getter
int rational_t::GetDen() const {
  return den_;
}

// Numerator Setter
void rational_t::SetNum(const int n) {
  num_ = n;
}

// Denominator Setter
void rational_t::SetDen(const int d) {
  assert(d != 0);
  den_ = d;
}

bool rational_t::is_positive() {
  int num = GetNum();
  int den = GetDen();
  if ((num >= 0 && den >= 0) || (num <= 0 && den <= 0)) {
    return true;
  }
  return false;
}

/**
 * @brief Method that get the value in real number of the rational object
 * 
 * @return double: value in real number
 */
double rational_t::Value() const { 
  return double(GetNum()) / GetDen();
}

/**
 * @brief Compares two rational numbers equality
 * 
 * @param r: rational to check
 * @param precision: epsilon error
 * @return true if they are equal
 * @return false if they are not equal
 */
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  return fabs(Value() - r.Value()) < precision;
}

/**
 * @brief Compares two rational numbers
 * 
 * @param r: rational to check 
 * @param precision: epsilon error
 * @return true if the first rational is greater
 * @return false if the second rational is greater
 */
bool rational_t::is_greater(const rational_t& r, const double precision) const{
  return Value() - r.Value() > precision;
}

/**
 * @brief Compares two rational numbers
 * 
 * @param r: rational to check 
 * @param precision: epsilon error
 * @return true if the first rational is less
 * @return false if the second rational is less
 */
bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.Value() - Value() > precision;
}

// operaciones
/**
 * @brief Computes Sum of two rationals
 * 
 * @param r: rational to operate 
 * @return rational_t: result of sum
 */
rational_t rational_t::add(const rational_t& r) {
  return rational_t(GetNum() * r.GetDen() + r.GetNum() * GetDen(), GetDen() * r.GetDen());
}

/**
 * @brief Computes substraction of two rationals
 * 
 * @param r 
 * @return rational_t: result of substraction
 */
rational_t rational_t::substract(const rational_t& r) {
  int subs_num {-r.GetNum()};
  return rational_t(GetNum() * r.GetDen() + subs_num * GetDen(), GetDen() * r.GetDen());
}

/**
 * @brief Computes multiplication of two rationals
 * 
 * @param r: rational to operate 
 * @return rational_t: result of multiplication
 */
rational_t rational_t::multiply(const rational_t& r) {
  return rational_t(GetNum() * r.GetNum(), GetDen() * r.GetDen());
}

/**
 * @brief Computes division of two rationals
 * 
 * @param r: rational to operate  
 * @return rational_t: result of division
 */
rational_t rational_t::divide(const rational_t& r) {
  return rational_t(GetNum() * r.GetDen(), GetDen() * r.GetNum());
}

// E/S
/**
 * @brief Prints a rational number
 * 
 * @param os: output stream
 */
void rational_t::write(ostream& os) const {
  os << GetNum() << "/" << GetDen() << "=" << Value() << endl;
}

/**
 * @brief Receive a rational number
 * 
 * @param is: input stream
 */
void rational_t::read(istream& is) {
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}