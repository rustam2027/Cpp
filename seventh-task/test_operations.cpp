#include <iostream>
#include <cassert>
#include "operations.cpp"

void testDiffVal() {
    Expression* valExpression = new Val(5);
    Expression* diffVal = valExpression->diff("x");
    assert(diffVal->print() == "0");
    std::cout << "Тест для Val::diff пройден успешно" << std::endl;
    delete diffVal;
    delete valExpression;
}

void testDiffVar() {
    Expression* varExpression = new Var("x");
    Expression* diffVar = varExpression->diff("x");
    assert(diffVar->print() == "1");
    std::cout << "Тест для Var::diff пройден успешно" << std::endl;
    delete diffVar;
    delete varExpression;
}

void testDiffAdd() {
    Expression* addExpression = new Add(new Val(3), new Var("x"));
    Expression* diffAdd = addExpression->diff("x");
    assert(diffAdd->print() == "(0 + 1)");
    std::cout << "Тест для Add::diff пройден успешно" << std::endl;
    delete diffAdd;
    delete addExpression;
}

void testDiffSub() {
    Expression* subExpression = new Sub(new Var("y"), new Val(2));
    Expression* diffSub = subExpression->diff("y");
    assert(diffSub->print() == "(1 - 0)");
    std::cout << "Тест для Sub::diff пройден успешно" << std::endl;
    delete diffSub;
    delete subExpression;
}

void testDiffMult() {
    Expression* multExpression = new Mult(new Var("z"), new Val(4));
    Expression* diffMult = multExpression->diff("z");
    assert(diffMult->print() == "((1 * 4) + (z * 0))");
    std::cout << "Тест для Mult::diff пройден успешно" << std::endl;
    delete diffMult;
    delete multExpression;
}

void testDiffExponent() {
    Expression* expExpression = new Exponent(new Var("x"));
    Expression* diffExp = expExpression->diff("x");
    assert(diffExp->print() == "(1 * e ** x)");
    std::cout << "Тест для Exponent::diff пройден успешно" << std::endl;
    delete diffExp;
    delete expExpression;
}

void testDiffDiv() {
    Expression* divExpression = new Div(new Val(10), new Var("y"));
    Expression* diffDiv = divExpression->diff("y");
    assert(diffDiv->print() == "(((0 * y) - (10 * 1)) / (y * y))");
    std::cout << "Тест для Div::diff пройден успешно" << std::endl;
    delete diffDiv;
    delete divExpression;
}

int main() {
    testDiffVal();
    testDiffVar();
    testDiffAdd();
    testDiffSub();
    testDiffMult();
    testDiffExponent();
    testDiffDiv();

    std::cout << "Все тесты функции diff пройдены успешно!" << std::endl;

    return 0;
}
