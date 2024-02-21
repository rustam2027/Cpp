#include "Treap.cpp"
#include <algorithm>
#include <iostream>
#include <cassert>
#include <ostream>

class Test {
public:
  void test_start() {
    TreapNode *test = new TreapNode(15, 4);
    test->insert(12, 8);

    test = test->remove(15);

    test->remove(12);
  };

  void test_first() {
    TreapNode *treap = new TreapNode(50, 5);

    treap = treap->insert(30, 3);
    treap = treap->insert(70, 7);
    treap = treap->insert(20, 2);

    TreapNode::treapPair splitResult = treap->split(40);
    TreapNode *L = splitResult.left;
    TreapNode *R = splitResult.right;

    delete L;
    delete R;
  };

  void testSplit() {
      TreapNode* treap = new TreapNode(50, 5);
      treap = treap->insert(30, 3);
      treap = treap->insert(70, 7);
      treap = treap->insert(20, 2);

      TreapNode::treapPair splitResult = treap->split(40);
      TreapNode* L = splitResult.left;
      TreapNode* R = splitResult.right;

      assert(L->getKey() < 40 && R->getKey() > 40);
      delete L;
      delete R;
  }

  void testMerge() {
      TreapNode* treap = new TreapNode(50, 5);
      TreapNode* treap2 = new TreapNode(60, 6);

      TreapNode* mergedTreap = treap->merge(treap2);

      assert(mergedTreap->getKey() == 50);
      delete mergedTreap;
  }

  void testInsert() {
      TreapNode* treap = new TreapNode(50, 5);
      TreapNode* insertedTreap = treap->insert(30, 3);

      assert(insertedTreap->getRight()->getKey() == 50);
      delete insertedTreap;
  }

  void testRemove() {
      TreapNode* treap = new TreapNode(50, 5);
      treap = treap->insert(30, 3);
      treap = treap->insert(70, 7);
    
      TreapNode* afterRemoval = treap->remove(30);

      assert(afterRemoval->getKey() != 30);
      delete afterRemoval;
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
  return 0;
}
