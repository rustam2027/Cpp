#include <cassert>

#include "BST.cpp"


void test_1() {
    BSTNode<int> *root = new BSTNode<int>(10);
    root->insert(5);
    root->insert(15);
    root->insert(2);
    root->insert(7);
    root->insert(12);
    root->insert(20);

    int arr [] = {2, 5, 7, 10, 12, 15, 20};

    auto iter = root->begin();
    int counter = 0;
    while (iter != root->end()) {
        assert((*iter)->key == arr[counter]);
        ++iter;
        ++counter;
    }
    std::cout << "TEST_1 PASSED" << std::endl;
}

void test_2() {
    BSTNode<int> *root = new BSTNode<int>(10);
    root->insert(5);
    root->insert(15);
    root->insert(2);
    root->insert(7);
    root->insert(12);
    root->insert(20);

    int arr [] = {2, 5, 7,10, 12, 15, 20};

    auto iter = root->begin();
    int counter = 0;
    while (iter != root->end()) {
        assert((*iter++)->key == arr[counter++]);
    }
    std::cout << "TEST_2 PASSED" << std::endl;
}

void test_3() {
    BSTNode<int> *root = new BSTNode<int>(1);
    root->insert(2);
    root->insert(3);
    root->insert(4);
    root->insert(5);
    root->insert(6);
    root->insert(7);

    int arr [] = {1, 2, 3, 4, 5, 6, 7};

    auto iter = root->begin();
    int counter = 0;
    while (iter != root->end()) {
        assert((*iter++)->key == arr[counter++]);
    }
    std::cout << "TEST_3 PASSED" << std::endl;
}


void test_4() {
    BSTNode<int> *root = new BSTNode<int>(7);
    root->insert(6);
    root->insert(5);
    root->insert(4);
    root->insert(3);
    root->insert(2);
    root->insert(1);

    int arr [] = {1, 2, 3, 4, 5, 6, 7};

    auto iter = root->begin();
    int counter = 0;
    while (iter != root->end()) {
        assert((*iter++)->key == arr[counter++]);
    }
    std::cout << "TEST_4 PASSED" << std::endl;
}

void test_5() {
    BSTNode<int> *root = new BSTNode<int>(7);
    root->insert(1);
    root->insert(6);
    root->insert(2);
    root->insert(5);
    root->insert(3);
    root->insert(4);

    int arr [] = {1, 2, 3, 4, 5, 6, 7};

    auto iter = root->begin();
    int counter = 0;
    while (iter != root->end()) {
        assert((*iter++)->key == arr[counter++]);
    }
    std::cout << "TEST_5 PASSED" << std::endl;
}

void test_6() {
    BSTNode<int> *root = new BSTNode<int>(7);
    root->insert(1);
    root->insert(6);
    root->insert(2);
    root->insert(5);
    root->insert(3);
    root->insert(4);

    int arr [] = {1, 2, 3, 4, 5, 6, 7};
    int counter = 0;

    for (auto iter : *root) {
        assert(iter->key == arr[counter++]);
    }
    
    std::cout << "TEST_6 PASSED" << std::endl;
}


int main() {
  test_1();
  test_2();
  test_3();
  test_4();
  test_5();
  test_6();
}

