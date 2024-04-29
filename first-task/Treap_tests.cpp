#include "Treap.cpp"
#include <__config>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include <string>

class Test {
public:
  void test_start() {
    TreapNode<int> *test = new TreapNode<int>(15, 4);
    test->insert(12, 8);

    test = test->remove(15);

    test->remove(12);
  };

  void test_first() {
    TreapNode<int> *treap = new TreapNode<int>(50, 5);

    treap = treap->insert(30, 3);
    treap = treap->insert(70, 7);
    treap = treap->insert(20, 2);

    TreapNode<int>::TreapPair splitResult = treap->split(40);
    TreapNode<int>* L = splitResult.left;
    TreapNode<int> *R = splitResult.right;

    delete L;
    delete R;
  };

  void testSplit() {
    TreapNode<int> *treap = new TreapNode<int>(50, 5);
    treap = treap->insert(30, 3);
    treap = treap->insert(70, 7);
    treap = treap->insert(20, 2);

    TreapNode<int>::TreapPair splitResult = treap->split(40);
    TreapNode<int> *L = splitResult.left;
    TreapNode<int> *R = splitResult.right;

    assert(L->getKey() < 40 && R->getKey() > 40);
    delete L;
    delete R;
  }

  void testMerge() {
    TreapNode<int> *treap = new TreapNode<int>(50, 5);
    TreapNode<int> *treap2 = new TreapNode<int>(60, 6);

    TreapNode<int> *mergedTreap = treap->merge(treap2);

    assert(mergedTreap->getKey() == 50);
    delete mergedTreap;
  }

  void testInsert() {
    TreapNode<int> *treap = new TreapNode<int>(50, 5);
    TreapNode<int> *insertedTreap = treap->insert(30, 3);

    assert(insertedTreap->getRight()->getKey() == 50);
    delete insertedTreap;
  }

  void testRemove() {
    TreapNode<int> *treap = new TreapNode<int>(50, 5);
    treap = treap->insert(30, 3);
    treap = treap->insert(70, 7);

    TreapNode<int> *afterRemoval = treap->remove(30);

    assert(afterRemoval->getKey() != 30);
    delete afterRemoval;
  }

  void testCopyConstructor1() {
    TreapNode<int> *treap1 = new TreapNode<int>(50, 5);
    treap1 = treap1->insert(20, 2);
    treap1 = treap1->insert(70, 7);

    TreapNode<int> *treap2 = new TreapNode<int>(*treap1);

    treap2 = treap2->remove(20);
    assert(treap1->getKey() == 20);
    assert(treap2->getKey() == 50);

    delete treap1;
    delete treap2;
  }

  void testCopyConstructor2() {
    TreapNode<int> *treap1 = new TreapNode<int>(50, 5);
    treap1 = treap1->insert(20, 2);
    treap1 = treap1->insert(70, 7);

    TreapNode<int> *treap2 = new TreapNode<int>(*treap1);

    treap2 = treap2->remove(50);
    assert(treap1->getRight()->getKey() == 50);
    assert(treap2->getRight()->getKey() == 70);

    delete treap1;
    delete treap2;
  }

  void testCopyOperator1() {
    TreapNode<int> *treap1 = new TreapNode<int>(50, 5);
    treap1 = treap1->insert(20, 2);
    treap1 = treap1->insert(70, 7);

    TreapNode<int> *treap2 = new TreapNode<int>(10, 1);

    *treap2 = *treap1;

    treap2 = treap2->remove(20);
    assert(treap1->getKey() == 20);
    assert(treap2->getKey() == 50);

    delete treap1;
    delete treap2;
  }

  void testCopyOperator2() {
    TreapNode<int> *treap1 = new TreapNode<int>(50, 5);
    treap1 = treap1->insert(20, 2);
    treap1 = treap1->insert(70, 7);

    TreapNode<int> *treap2 = new TreapNode<int>(10, 1);

    *treap2 = *treap1;

    treap2 = treap2->remove(50);
    assert(treap1->getRight()->getKey() == 50);
    assert(treap2->getRight()->getKey() == 70);

    delete treap1;
    delete treap2;
  }

  void testCopyOperator3() {
    TreapNode<int> *treap1 = new TreapNode<int>(50, 5);
    treap1 = treap1->insert(20, 2);
    treap1 = treap1->insert(70, 7);

    *treap1 = *treap1;
    delete treap1;
  }

  void testCopyOperator4() {
    TreapNode<int> *treap1 = new TreapNode<int>(50, 5);
    treap1 = treap1->insert(20, 2);
    treap1 = treap1->insert(70, 7);

    TreapNode<int> treap2 = std::move(*treap1);

    assert(treap1->getLeft() == nullptr);
    assert(treap1->getRight() == nullptr);

    delete treap1;

    assert(treap2.getKey() == 20);
    assert(treap2.getRight()->getKey() == 50);
    assert(treap2.getRight()->getRight()->getKey() == 70);
  }

  void testCopyOperator5() {
    TreapNode<int> *treap1 = new TreapNode<int>(50, 5);
    treap1 = treap1->insert(20, 2);
    treap1 = treap1->insert(70, 7);

    TreapNode<int> treap2 = TreapNode<int>(20, 2);
    treap2 = std::move(*treap1);

    assert(treap1->getLeft() == nullptr);
    assert(treap1->getRight() == nullptr);

    delete treap1;

    assert(treap2.getKey() == 20);
    assert(treap2.getRight()->getKey() == 50);
    assert(treap2.getRight()->getRight()->getKey() == 70);
  }

  void test_template() {
    TreapNode<std::string> *treap = new TreapNode<std::string>("50", 5);

    treap = treap->insert("30", 3);
    treap = treap->insert("70", 7);
    treap = treap->insert("20", 2);

    TreapNode<std::string>::TreapPair splitResult = treap->split("40");
    TreapNode<std::string>* L = splitResult.left;
    TreapNode<std::string> *R = splitResult.right;

    delete L;
    delete R;
  }

};

int main() {
  Test test;
  test.test_first();
  test.test_start();
  test.testInsert();
  test.testMerge();
  test.testRemove();
  test.testSplit();
  test.testCopyConstructor1();
  test.testCopyConstructor2();
  test.testCopyOperator1();
  test.testCopyOperator2();
  test.testCopyOperator3();
  test.testCopyOperator4();
  test.testCopyOperator5();
  test.test_template();

  return 0;
}
