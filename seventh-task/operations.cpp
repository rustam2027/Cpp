#include "expression.hpp"

class Val : public Expression {
  int value_;

public:
  Val(int value) : value_(value) {}

  Expression *diff(std::string var) { return new Val(0); }

  Expression *copy() { return new Val(value_); }

  std::string print() { return std::to_string(value_); }

  ~Val() {};
};

class Var : public Expression {
  std::string variable_;

public:
  Var(std::string variable) : variable_(variable) {}

  Expression *diff(std::string var) {
    if (var == variable_) {
      return new Val(1);
    }
    return new Val(0);
  }

  Expression *copy() { return new Var(variable_); }

  std::string print() { return variable_; }

  ~Var() {};
};

class Add : public BinaryExpression {
  std::string get_sign() {
    return " + ";
  }

public:
  Add(Expression *first, Expression *second) {
    first_ = first;
    second_ = second;
  }

  Expression *diff(std::string var) {
    return new Add(first_->diff(var), second_->diff(var));
  }

  Expression *copy() { return new Add(first_->copy(), second_->copy()); }
};

class Sub : public BinaryExpression {
  std::string get_sign() {
    return " - ";
  }

public:
  Sub(Expression *first, Expression *second) {
    first_ = first;
    second_ = second;
  }

  Expression *diff(std::string var) {
    return new Sub(first_->diff(var), second_->diff(var));
  }

  Expression *copy() { return new Sub(first_->copy(), second_->copy()); }
};

class Mult : public BinaryExpression {
  std::string get_sign() {
    return " * ";
  }

public:
  Mult(Expression *first, Expression *second) {
    first_ = first;
    second_ = second;
  }

  Expression *diff(std::string var) {
    return new Add(new Mult(first_->diff(var), second_->copy()),
                   new Mult(first_->copy(), second_->diff(var)));
  }

  Expression *copy() { return new Mult(first_->copy(), second_->copy()); }
};

class Exponent : public UnaryExpression {
public:
  Exponent(Expression *degree) { first_ = degree; }

  Expression *diff(std::string var) {
    return new Mult(first_->diff(var), copy());
  }

  Expression *copy() { return new Exponent(first_->copy()); }

  std::string print() { return "e ** " + first_->print(); }
};

class Div : public BinaryExpression {
  std::string get_sign() {
    return " / ";
  }

public:
  Div(Expression *first, Expression *second) {
    first_ = first;
    second_ = second;
  }

  Expression *diff(std::string var) {
    return new Div(new Sub(new Mult(first_->diff(var), second_->copy()), new Mult(first_->copy(), second_->diff(var))), new Mult(second_->copy(), second_->copy()));
  }

  Expression *copy() { return new Div(first_->copy(), second_->copy()); }
};
