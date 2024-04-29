#include <stdexcept>
#include <iostream>

template <int K> class Counter {
  static int count;

public:
  Counter() {
    count++;
    if (count >= K) {
      throw std::runtime_error("Too many instances!!");
    }
  }

  ~Counter() { count--; }
};

template <int K>
int Counter<K>::count = 0;

class Trash : Counter<3> {
  int trash_;

public:
  Trash(int trash) { trash_ = trash; }

  int get_trash() { return 'T'; }
};

struct Test {
  void test_1() {
    Trash t_1(1);
    Trash t_2(1);
    try {
      Trash t_3(1);
    } catch (std::runtime_error& r) {
      std::cout << r.what() << std::endl;
    }
  }
};

int main() {
  Test t;
  t.test_1();
}
