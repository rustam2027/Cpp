#include <string>

struct Expression {
  virtual Expression *diff(std::string var) = 0;
  virtual Expression *copy() = 0;
  virtual ~Expression() {};
  virtual std::string print() = 0;
};

class BinaryExpression : public Expression {
protected:
  Expression *first_;
  Expression *second_;
public:
  ~BinaryExpression() {
    delete first_;
    delete second_;
  }
};

class UnaryExpression : public Expression {
protected:
  Expression *first_;
public:
  ~UnaryExpression() {
    delete first_;
  }
};
