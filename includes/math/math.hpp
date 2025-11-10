#ifndef MATH_HPP
#define MATH_HPP

#include <ostream>

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>

namespace math {

using namespace glm;

static constexpr float infinity = std::numeric_limits<float>::max();

}  // namespace math

template <math::length_t L, typename T, math::qualifier Q>
std::ostream &operator<<(std::ostream &o, const math::vec<L, T, Q> &v) {
  o << math::to_string(v);
  return o;
}
template <math::length_t C, math::length_t R, typename T, math::qualifier Q>
std::ostream &operator<<(std::ostream &o, const math::mat<C, R, T, Q> &v) {
  o << math::to_string(v);
  return o;
}

#endif  // !MATH_HPP
