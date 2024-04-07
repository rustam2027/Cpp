#include <cstdio>
#include <iostream>
#include <cassert>
#include <iterator>

#include "operations.cpp"


int main() {
    Expression* valExpression = new Val(5);
    Expression* varExpression = new Var("x");
    Expression* addExpression = new Add(new Val(3), new Var("x"));
    Expression* subExpression = new Sub(new Var("y"), new Val(2));
    Expression* multExpression = new Mult(new Var("z"), new Val(4));
    Expression* expExpression = new Exponent(new Var("x"));
    Expression* divExpression = new Div(new Val(10), new Var("y"));

    Expression* diffVal = valExpression->diff("x");
    std::cout << diffVal->print() << std::endl;
    assert(diffVal->print() == "0");
    delete diffVal;

    Expression* diffVar = varExpression->diff("x");
    assert(diffVar->print() == "1");
    delete diffVar;

    Expression* diffAdd = addExpression->diff("x");
    assert(diffAdd->print() == "(0 + 1)");
    delete diffAdd;

    Expression* diffSub = subExpression->diff("y");
    assert(diffSub->print() == "(1 - 0)");
    delete diffSub;

    Expression* diffMult = multExpression->diff("z");
    std::cout << diffMult->print() << std::endl;
    assert(diffMult->print() == "((1 * 4) + (z * 0))");
    delete diffMult;

    Expression* diffExp = expExpression->diff("x");
    assert(diffExp->print() == "(1 * e ** x)");
    delete diffExp;

    Expression* diffDiv = divExpression->diff("y");
    std::cout << diffDiv->print() << std::endl;
    assert(diffDiv->print() == "(((0 * y) - (10 * 1)) / (y * y))");
    delete diffDiv;

    delete valExpression;
    delete varExpression;
    delete addExpression;
    delete subExpression;
    delete multExpression;
    delete expExpression;
    delete divExpression;

    std::cout << "Все тесты функции diff пройдены успешно!" << std::endl;
    

    return 0;
}
