#ifndef MATH_RANDOM_HPP
#define MATH_RANDOM_HPP

#include <random>

#include "math/math.hpp"

namespace math {

struct random_t {
  float random_float() { return distribution(generator); }

  template <length_t L, typename T = float, qualifier Q = defaultp>
  constexpr math::vec<L, T, Q> random_vec() {
    math::vec<L, T, Q> v{};
    for (int32_t axis = 0; axis < L; axis++) {
      v[axis] = random_float();
    }
    return v;
  }

  std::uniform_real_distribution<float> distribution{0.f, 1.f};
  std::mt19937                          generator{};
};

}  // namespace math

#endif
