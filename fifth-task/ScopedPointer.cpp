#include <cassert>
#include <iostream>

template <typename T> class ScopedPointerShallow {
private:
  T *ptr;

public:
  ScopedPointerShallow(T *p) : ptr(p) {}

  ~ScopedPointerShallow() { delete ptr; }

  ScopedPointerShallow(ScopedPointerShallow &other) : ptr(other.ptr) { other.ptr = nullptr;}

  ScopedPointerShallow &operator=(const ScopedPointerShallow &other) {
    if (this == &other) {
      return *this;
    }
    delete ptr;
    ptr = other.ptr;
    other.ptr = nullptr;
  }

  T *get() { return ptr; }
};

template <typename T> class ScopedPointerDeep {
private:
  T *ptr;

public:
  ScopedPointerDeep(T *p) : ptr(p) {}

  ~ScopedPointerDeep() { delete ptr; }

  ScopedPointerDeep(const ScopedPointerDeep &other) { ptr = new T(*other.ptr); }

  ScopedPointerDeep &operator=(const ScopedPointerDeep &other) {
    if (this != &other) {
      return *this;
    }
    delete ptr;
    ptr = new T(*other.ptr);
  }

  ScopedPointerDeep &operator=(ScopedPointerDeep &&other) {
    if (this == &other) {
      return *this;
    }
    delete ptr;
    ptr = other.ptr;
    other.ptr = nullptr;
    return *this;
  }

  T *get() { return ptr; }
};

void test_1() {
  int *shared_data = new int(10);
  ScopedPointerShallow<int> sps1(shared_data);
  ScopedPointerShallow<int> sps2 = sps1;

  assert(*shared_data == 10);
  *sps2.get() = 20;
  assert(*shared_data == 20);

  int *shared_deep_data = new int(100);
  ScopedPointerDeep<int> spd1(shared_deep_data);
  ScopedPointerDeep<int> spd2 = spd1;

  assert(*shared_deep_data == 100);
  *spd2.get() = 200;
  assert(*shared_deep_data == 100);

  std::cout << "Тест 1 пройден успешно!" << std::endl;
}

void test_2() {
    int* shared_deep_data = new int(100);
    ScopedPointerDeep<int> spd1(shared_deep_data);

    assert(*shared_deep_data == 100);

    int* new_data = new int(200);
    ScopedPointerDeep<int> spd2(new_data);

    assert(*new_data == 200);

    spd1 = std::move(spd2);

    assert(spd2.get() == nullptr);
    assert(*spd1.get() == 200);

    std::cout << "Тест 2 пройден успешно!" << std::endl;
}


int main() {
  test_1();
  test_2();
}


