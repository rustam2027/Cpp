#include "Treap.cpp"
#include <iostream>

class Test {
public:
  void test_start() {
    TreapNode *test = new TreapNode(15, 4);
    test->insert(12, 8);

    std::cout << test->getKey() << std::endl;
    test = test->remove(15);

    std::cout << test->getKey() << std::endl;
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

  void test_second() {
    TreapNode* treap = new TreapNode(50, 5);

    treap = treap->insert(30, 3);
    treap = treap->insert(70, 7);
    treap = treap->insert(20, 2);

    
  }
};

int main() {
  Test test;
  test.test_first();
  test.test_start();
  return 0;
}
