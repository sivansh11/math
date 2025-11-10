#include "math/math.hpp"
#include <format>
#include <iostream>

int main() {
  math::vec3 v{1, 2, 3};
  std::cout << std::format("{}", v) << '\n';

}
