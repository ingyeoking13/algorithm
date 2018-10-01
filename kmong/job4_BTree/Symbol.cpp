//Do NOT MODIFY THIS FILE.


#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include "Symbol.h"

using namespace std;

Symbol::Symbol(string s) {
  if (s == "+") {
    _type = Symbol::symbol_operator;
    _operator = Symbol::addition;
  } else
  if (s == "-") {
    _type = Symbol::symbol_operator;
    _operator = Symbol::subtraction;
  } else
  if (s == "*") {
    _type = Symbol::symbol_operator;
    _operator = Symbol::multiplication;
  } else
  if (s == "/") {
    _type = Symbol::symbol_operator;
    _operator = Symbol::division;
  } else
  if (('0' <= s[0] && s[0] <= '9') || (s[0] == '-')) {
    _type = Symbol::constant;
    _constant = atoi(s.c_str());
  } else
  if (('a' <= s[0] && s[0] <= 'z') || ('A' <= s[0] && s[0] <= 'Z')) {
    _type = Symbol::variable;
    _variable = s;
  } else {
    throw runtime_error("Unknown symbol");
  }
}

Symbol::Symbol(int c) {
  _type = Symbol::constant;
  _constant = c;
}

bool Symbol::operator==(const Symbol& sym) const {
  if (_type != sym._type) return false;
  switch(_type) {
    case Symbol::constant:
      return _constant == sym._constant;
    case Symbol::variable:
      return _variable == sym._variable;
    case Symbol::symbol_operator:
      return _operator == sym._operator;
  }
}

int Symbol::compute(int v1, int v2) {
  if (_type != symbol_operator) throw runtime_error("Not an operator.");
  switch(_operator) {
    case Symbol::addition:
      return v1 + v2;
    case Symbol::subtraction:
      return v1 - v2;
    case Symbol::multiplication:
      return v1 * v2;
    case Symbol::division:
      if (v2 == 0) throw runtime_error("Divide by zero");
      return v1 / v2;
  }
}

ostream& operator<< (ostream &out, const Symbol &s) {
  switch(s._type) {
    case Symbol::constant:
      out << s._constant;
      break;
    case Symbol::variable:
      out << s._variable;
      break;
    case Symbol::symbol_operator:
      out << s._operator;
      break;
  }
  return out;
}

ostream& operator<< (ostream &out, const Symbol::Operator &s) {
  switch(s) {
    case Symbol::addition:
      out << "+";
      break;
    case Symbol::subtraction:
      out << "-";
      break;
    case Symbol::multiplication:
      out << "*";
      break;
    case Symbol::division:
      out << "/";
      break;
  }
  return out;
}


