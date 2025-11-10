#ifndef MATH_HPP
#define MATH_HPP

#include <ostream>
#include <format>

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

template <math::length_t L, typename T, math::qualifier Q>
struct std::formatter<math::vec<L, T, Q>> {
  template <typename parse_context_t>
  constexpr auto parse(parse_context_t &ctx) {
    return ctx.begin();
  }
  template <typename format_context_t>
  auto format(const math::vec<L, T, Q> &v, format_context_t &ctx) const {
    return std::format_to(ctx.out(), "{}", math::to_string(v));
  }
};

template <math::length_t C, math::length_t R, typename T, math::qualifier Q>
struct std::formatter<math::mat<C, R, T, Q>> {
  template <typename parse_context_t>
  constexpr auto parse(parse_context_t &ctx) {
    return ctx.begin();
  }
  template <typename format_context_t>
  auto format(const math::mat<C, R, T, Q> &v, format_context_t &ctx) const {
    return std::format_to(ctx.out(), "{}", math::to_string(v));
  }
};

#endif  // !MATH_HPP
