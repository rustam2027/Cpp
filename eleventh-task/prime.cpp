#include <iostream>
#include <type_traits>

template <int N, int M>
struct is_prime_recursion
    : std::conditional_t<(N % M != 0), is_prime_recursion<N, M - 1>,
                         std::integral_constant<bool, false>> {};

template <int N>
struct is_prime_recursion<N, 1> : std::integral_constant<bool, true> {};

template <int N> struct is_prime : is_prime_recursion<N, N - 1> {};

template <int M>
struct prime_recursion
    : std::conditional_t<is_prime<M>::value, std::integral_constant<int, M>,
                         prime_recursion<M + 1>> {};

template <int N> struct prime : prime_recursion<prime<N - 1>::value + 1> {};

template <> struct prime<1> : std::integral_constant<int, 2> {};

int main() { std::cout << prime<5>::value << std::endl; }
