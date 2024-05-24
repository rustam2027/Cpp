#include "../fourteenth-task/allocator.hpp"
#include <cstdlib>
#include <stdexcept>
#include <vector>

template <typename... Types> class Container {
private:
  char *ptr;
  std::vector<size_t> shifts;

  template <typename T> void add_shift(size_t &shift) {
    shifts.push_back(shift);
    shift += sizeof(T);
  }

  template <typename T> void del(size_t shift) {
    ((T *) (ptr + shifts.at(shift)))->~T();
  }

public:
  Container(Types&&... args) {
    ptr = (char *)std::malloc(size<Types...>);
    if (!ptr) {
      throw std::runtime_error("????");
    }
    allocate<size<Types...>, Types...>(ptr, std::forward<Types>(args)...);

    size_t shift = 0;

    (add_shift<Types>(shift), ...);
  }

  template <typename T> T &get_element(size_t index) {
    return *((T *) (ptr + shifts[index]));
  }

  ~Container() {
    size_t shift = 0;
    (del<Types>(shift++), ...);
  }
};
