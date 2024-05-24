#include <utility>
#include <iostream>

// template<typename Checker, typename First>
// int recursion(int index, Checker&& check, First&& first) {
//   if (check(first)) {
//     return index;
//   }
//   return -1;
// }

// template<typename Checker, typename First, typename... Args>
// int recursion(int index, Checker&& check, First&& first, Args&&... args) {
//   if (check(first)) {
//     return index;
//   }
//   int next_index = recursion(index + 1, std::forward<Checker>(check), std::forward<Args>(args)...);
//   return next_index;
// }

// template<typename Checker, typename... Args>
// int getIndexOfFirstMatch(Checker&& check, Args&&... args) {
//   return recursion(0, std::forward<Checker>(check), std::forward<Args>(args)...);
// }

template<typename Checker, typename... Args>
int getIndexOfFirstMatch(Checker&& check, Args&&... args) {  // Luba variant (I hate it) (I know you make me do this)
  size_t index = -1;
  size_t counter = 0;
  
  bool answ = ((check(std::forward<Args>(args)) ? (index = counter, false) : (counter++, true)) && ...);
  return index;
}


bool isEven(int n) {
    return n % 2 == 0;
}

bool isNegative(double n) {
    return n < 0;
}

int main() {
    int index = getIndexOfFirstMatch(isEven, 1, 3, 5, 8, 10);
    std::cout << "First even number is at index: " << index << std::endl;

    index = getIndexOfFirstMatch(isNegative, 3.2, 1.1, -4.5, 5.6);
    std::cout << "First negative number is at index: " << index << std::endl;

    index = getIndexOfFirstMatch(isEven, 1, 3, 5, 7, 9);
    std::cout << "First even number is at index: " << index << std::endl;

    return 0;
}

