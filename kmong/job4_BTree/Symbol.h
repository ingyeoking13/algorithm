//Do NOT MODIFY THIS FILE.

#ifndef PJT2_SYMBOL_H
#define PJT2_SYMBOL_H

#include <iostream>

using namespace std;

class Symbol {

public:

  /*
   * The three possible types of symbols.
   */
  enum SymbolType { constant, variable, symbol_operator };

  /*
   * The four possible operators that we use. Notice that they
   * are integer operators.
   */
  enum Operator { addition, subtraction, multiplication, division };

  /*
   * Default constructor that does nothing.
   */
  Symbol() {}

  /*
   * Construct a symbol by parsing a symbol.
   */
  Symbol(string s);

  /*
   * Construct a constant symbol of an integer.
   *
   * c - an integer
   */
  Symbol(int c);

  /*
   * Return the type of this symbol.
   *
   * return the type of this symbol
   */
  SymbolType getSymbolType() const {
    return _type;
  }

  /*
   * Check whether this symbol is a constant symbol.
   *
   * return true if this symbol is a constant symbol
   */
  bool isConstant() const {
    return _type == constant;
  }

  /*
   * Check whether this symbol is a variable symbol.
   *
   * return true if this symbol is a variable symbol
   */
  bool isVariable() const {
    return _type == variable;
  }

  /*
   * Check whether this symbol is an operator symbol.
   *
   * return true if this symbol is an operator symbol
   */
  bool isOperator() const {
    return _type == symbol_operator;
  }

  /*
   * Check whether this symbol is equal to another symbol.
   *
   * sym - another symbol
   * return true if this symbol is equal to another symbol
   */
  bool operator==(const Symbol& sym) const;


  /*
   * Return the integer value of the constant if this is a constant symbol.
   *
   * return the integer value of this constant
   */
  int getConstant() const {
    if (_type != constant) throw runtime_error("Not a getConstant.");
    return _constant;
  }

  /*
   * Return the string of the variable if this is a variable symbol.
   *
   * return the string of this variable
   */
  string getVariable() const {
    if (_type != variable) throw runtime_error("Not a getVariable.");
    return _variable;
  }

  /*
   * Return the type of the operator if this is an operator symbol.
   *
   * return the type of the operator of this operator symbol
   */
  Operator getOperator() const {
    if (_type != symbol_operator) throw runtime_error("Not an operator.");
    return _operator;
  }

  /*
   * Use this operator symbol to perform a computation.
   *
   * v1 - the first operand
   * v2 - the second operand
   * return the result of the computation
   */
  int compute(int v1, int v2);

  friend ostream& operator<<(ostream &out, const Symbol &p);
  friend ostream& operator<<(ostream &out, const Symbol::Operator &p);

private:

  SymbolType _type;
  int _constant;
  string _variable;
  Operator _operator;
};

#endif //PJT2_SYMBOL_H
