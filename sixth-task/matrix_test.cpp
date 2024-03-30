#include "matrix.cpp"
#include <assert.h>
#include <iostream>

void testAdditionOperator() {
  matrix mat1(2);
  mat1[0][0] = 1;
  mat1[0][1] = 2;
  mat1[1][0] = 3;
  mat1[1][1] = 4;

  matrix mat2(2);
  mat2[0][0] = 2;
  mat2[0][1] = 3;
  mat2[1][0] = 4;
  mat2[1][1] = 5;

  matrix result = mat1 + mat2;

  // Проверяем результат сложения
  assert(result[0][0] == 3);
  assert(result[0][1] == 5);
  assert(result[1][0] == 7);
  assert(result[1][1] == 9);
}

void testMultiplicationOperator() {
  matrix mat1(2); // Создаем матрицу 2x2
  mat1[0][0] = 1;
  mat1[0][1] = 2;
  mat1[1][0] = 3;
  mat1[1][1] = 4;

  matrix mat2(2); // Создаем вторую матрицу 2x2
  mat2[0][0] = 2;
  mat2[0][1] = 3;
  mat2[1][0] = 4;
  mat2[1][1] = 5;

  matrix result = mat1 * mat2; // Выполняем умножение матриц

  // Проверяем результат умножения
  assert(result[0][0] == 10);
  assert(result[0][1] == 13);
  assert(result[1][0] == 22);
  assert(result[1][1] == 29);
}

void testCompoundAdditionOperator() {
  matrix mat1(2); // Создаем матрицу 2x2
  mat1[0][0] = 1;
  mat1[0][1] = 2;
  mat1[1][0] = 3;
  mat1[1][1] = 4;

  matrix mat2(2); // Создаем вторую матрицу 2x2
  mat2[0][0] = 2;
  mat2[0][1] = 3;
  mat2[1][0] = 4;
  mat2[1][1] = 5;

  mat1 += mat2; // Выполняем операцию сложения с присваиванием

  // Проверяем результат сложения с присваиванием
  assert(mat1[0][0] == 3);
  assert(mat1[0][1] == 5);
  assert(mat1[1][0] == 7);
  assert(mat1[1][1] == 9);
}

void testCompoundMultiplicationOperator() {
  matrix mat1(2); // Создаем матрицу 2x2
  mat1[0][0] = 1;
  mat1[0][1] = 2;
  mat1[1][0] = 3;
  mat1[1][1] = 4;

  matrix mat2(2); // Создаем вторую матрицу 2x2
  mat2[0][0] = 2;
  mat2[0][1] = 3;
  mat2[1][0] = 4;
  mat2[1][1] = 5;

  mat1 *= mat2; // Выполняем операцию умножения с присваиванием

  // Проверяем результат умножения с присваиванием
  assert(mat1[0][0] == 10);
  assert(mat1[0][1] == 13);
  assert(mat1[1][0] == 22);
  assert(mat1[1][1] == 29);
}

void testCompoundMultiplicationByConstant() {
  matrix mat(2); // Создаем матрицу 2x2
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[1][0] = 3;
  mat[1][1] = 4;

  double constant = 2.5; // Константа для умножения

  mat *= constant; // Умножаем матрицу на константу

  // Проверяем результат умножения на константу
  assert(mat[0][0] == 2.5);
  assert(mat[0][1] == 5);
  assert(mat[1][0] == 7.5);
  assert(mat[1][1] == 10);
}

void testMultiplicationByConstantLeft() {
  matrix mat(2); // Создаем матрицу 2x2
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[1][0] = 3;
  mat[1][1] = 4;

  double constant = 2.5; // Константа для умножения

  matrix result = mat * constant; // Умножаем матрицу на константу

  // Проверяем результат умножения на константу
  assert(result[0][0] == 2.5);
  assert(result[0][1] == 5);
  assert(result[1][0] == 7.5);
  assert(result[1][1] == 10);
}

void testMultiplicationByConstantRight() {
  matrix mat(2); // Создаем матрицу 2x2
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[1][0] = 3;
  mat[1][1] = 4;

  double constant = 2.5; // Константа для умножения

  matrix result = constant * mat; // Умножаем матрицу на константу

  // Проверяем результат умножения на константу
  assert(result[0][0] == 2.5);
  assert(result[0][1] == 5);
  assert(result[1][0] == 7.5);
  assert(result[1][1] == 10);
}

void testConstructorFromVector() {
  std::vector<double> vec;
  vec.push_back(2);
  vec.push_back(3);

  matrix mat = matrix(vec);

  assert(mat[0][0] == 2);
  assert(mat[0][1] == 0);
  assert(mat[1][0] == 0);
  assert(mat[1][1] == 3);
}

void testSumElements() {
  matrix mat(2); // Создаем матрицу 2x2
  mat[0][0] = 1;
  mat[0][1] = 2;
  mat[1][0] = 3;
  mat[1][1] = 4;

  assert((double) mat == 10);
}

void testEqualityOperator() {
    matrix mat1(2); // Создаем матрицу 2x2
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    matrix mat2(2); // Создаем вторую матрицу 2x2 и копируем значения из mat1
    mat2[0][0] = mat1[0][0];
    mat2[0][1] = mat1[0][1];
    mat2[1][0] = mat1[1][0];
    mat2[1][1] = mat1[1][1];

    // Проверяем оператор равенства
    assert(mat1 == mat2); // mat1 и mat2 должны быть равны
}

void testInequalityOperator() {
    matrix mat1(2); // Создаем матрицу 2x2
    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    matrix mat2(2); // Создаем вторую матрицу 2x2, но с другими значениями
    mat2[0][0] = 2;
    mat2[0][1] = 3;
    mat2[1][0] = 4;
    mat2[1][1] = 5;

    // Проверяем оператор неравенства
    assert(mat1 != mat2); // mat1 и mat2 не должны быть равны
}


int main() {
  testAdditionOperator();
  testCompoundAdditionOperator();

  testMultiplicationOperator();

  testCompoundMultiplicationOperator();
  testCompoundMultiplicationByConstant();

  testMultiplicationByConstantLeft();
  testMultiplicationByConstantRight();

  testConstructorFromVector();

  testSumElements();

  testEqualityOperator();
  testInequalityOperator();

  // Все тесты были успешно выполнены
  std::cout << "Все тесты пройдены успешно!" << std::endl;

  return 0;
}
