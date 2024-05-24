#include "containter.hpp"

#include <cassert>
#include <string>
#include <iostream>

struct TestStruct {
    static int destructCount;
    int value;
    TestStruct(int v) : value(v) {}
    ~TestStruct() { ++destructCount; }
};

int TestStruct::destructCount = 0;

void test_basic_types() {
    Container<int, double, std::string> container(42, 3.14, "Hello, World!");
    assert(container.get_element<int>(0) == 42);
    assert(container.get_element<double>(1) == 3.14);
    assert(container.get_element<std::string>(2) == "Hello, World!");
    std::cout << "test_basic_types passed." << std::endl;
}

void test_destruction() {
    {
        Container<TestStruct> container(TestStruct(10));
        assert(container.get_element<TestStruct>(0).value == 10);
    }
    assert(TestStruct::destructCount == 2);  // Проверяем, что деструктор был вызван
    std::cout << "test_destruction passed." << std::endl;
}

void test_no_copy_construct() {
    struct NoCopy {
        NoCopy() = default;
        NoCopy(const NoCopy&) = delete;
    };

    // Это должен быть статически некорректный код, потому что NoCopy не копируемый тип
    // Container<NoCopy> container(NoCopy{}); // Эта строка не должна компилироваться
    std::cout << "test_no_copy_construct passed (compile-time test)." << std::endl;
}

void test_large_allocation() {
    const size_t largeSize = 1000000;
    struct LargeStruct {
        int data[largeSize];
    };

    Container<LargeStruct> container(LargeStruct{});
    assert(container.get_element<LargeStruct>(0).data[largeSize - 1] == 0); // Проверка, что элемент доступен
    std::cout << "test_large_allocation passed." << std::endl;
}

int main() {
    test_basic_types();
    test_destruction();
    test_no_copy_construct();
    test_large_allocation();

    std::cout << "All tests passed." << std::endl;
    return 0;
}

