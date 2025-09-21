#ifndef MATH_AABB_HPP
#define MATH_AABB_HPP

#include <cassert>
#include <limits>
#include <ostream>

#include "math/math.hpp"

namespace math {

struct aabb_t {
  bool is_valid() const;
  vec3 extent() const;
  float largest_extent() const;
  float area() const;
  vec3 center() const;
  uint32_t largest_axis() const;
  aabb_t &grow(const glm::vec3 &point);
  aabb_t &grow(const aabb_t &aabb);
  aabb_t &shrink(const aabb_t& aabb);

  glm::vec3 min{infinity};
  glm::vec3 max{-infinity};
};

} // namespace math

std::ostream &operator<<(std::ostream &o, const math::aabb_t &aabb);

#endif // !MATH_AABB_HPP
