#include <type_traits>

template <typename... Types>
constexpr size_t size = (sizeof(Types) + ...);

template <typename... Types>
constexpr bool copy_construct = ((std::is_copy_constructible_v<Types>) && ...);

template <typename T>
char* allocator(char* ptr, T&& arg) {
  using T_WR = std::remove_reference<T>::type;
  new(ptr) T_WR(arg);
  ptr += sizeof(arg);
  return ptr;
}

template <size_t SIZE, typename... Types>
void allocate(void *memory, Types&&... args) requires (SIZE >= size<Types...> && copy_construct<Types...>) {
  char* ptr = (char*) memory;
  ((ptr = allocator(ptr, args)), ...);
}
