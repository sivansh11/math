#ifndef GEOMETRY_AABB_HPP
#define GEOMETRY_AABB_HPP

#include <cassert>
#include <limits>
#include <ostream>

#include "geometry/math.hpp"

namespace geometry {

struct aabb_t {
  bool is_valid() const;
  vec3 extent() const;
  float area() const;
  vec3 center() const;
  aabb_t &grow(const glm::vec3 &point);
  aabb_t &grow(const aabb_t &aabb);

  glm::vec3 min{infinity};
  glm::vec3 max{-infinity};
};

} // namespace geometry

std::ostream &operator<<(std::ostream &o, const geometry::aabb_t &aabb);

#endif // !GEOMETRY_AABB_HPP
