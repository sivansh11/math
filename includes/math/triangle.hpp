#ifndef MATH_TRIANGLE_HPP
#define MATH_TRIANGLE_HPP

#include <ostream>

#include "math/aabb.hpp"

namespace math {

struct triangle_t {
  aabb_t aabb() const { return aabb_t{}.grow(v0).grow(v1).grow(v2); }
  vec3   center() const { return (v0 + v1 + v2) / 3.f; }
  float  area() const;
  vec3   normal() const;
  std::pair<math::aabb_t, math::aabb_t> split(uint32_t axis,
                                              float    position) const;
  vec3                                  v0, v1, v2;
};

}  // namespace math

std::ostream &operator<<(std::ostream &o, const math::triangle_t &triangle);

#endif  // !MATH_TRIANGLE_HPP
