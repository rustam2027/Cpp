#include "expression.hpp"

class Val : public Expression {
  float value_;

public:
  Val(float value) : value_(value) {}

  Expression *diff(std::string var) { return new Val(0); }

  Expression* copy() {
    return new Val(value_);
  }
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

  Expression* copy() {
    return new Var(variable_);
  }
};

class Add : public BinaryExpression {
public:
  Add(Expression *first, Expression *second) {
    first_ = first;
    second_ = second;
  }

  Expression *diff(std::string var) {
    return new Add(first_->diff(var), second_->diff(var));
  }

  Expression* copy() {
    return new Add(first_->copy(), second_->copy());
  }
};

class Sub : public BinaryExpression {
public:
  Sub(Expression *first, Expression *second) {
    first_ = first;
    second_ = second;
  }

  Expression *diff(std::string var) {
    return new Sub(first_->diff(var), second_->diff(var));
  }

  Expression* copy() {
    return new Sub(first_->copy(), second_->copy());
  }
};

class Mult : public BinaryExpression {
public:
  Mult(Expression *first, Expression *second) {
    first_ = first;
    second_ = second;
  }

  Expression *diff(std::string var) {
    return new Add(new Mult(first_->diff(var), second_),
                   new Mult(first_, second_->diff(var)));
  }

  Expression* copy() {
    return new Mult(first_->copy(), second_->copy());
  }
};

class Exponent : public BinaryExpression {
public:
  Exponent(Expression *base, Val *degree) {
    first_ = base;
    second_ = degree;
  }

  Expression *diff(std::string var) { return new Mult(second_->copy(), new Exponent(first_->copy(), new Sub(second_, new Val(1))));}

  Expression* copy() {return new Exponent(first_->copy(), second_->copy());}
};

class Div : public BinaryExpression {
public:
  Div(Expression *first, Expression *second) {
    first_ = first;
    second_ = second;
  }

  Expression *diff(std::string var) {
    return new Div(first_->diff(var), second_->diff(var));
  }
};

