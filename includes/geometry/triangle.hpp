#ifndef GEOMETRY_TRIANGLE_HPP
#define GEOMETRY_TRIANGLE_HPP

#include "geometry/aabb.hpp"

namespace geometry {

struct triangle_t {
  aabb_t aabb() const { return aabb_t{}.grow(v0).grow(v1).grow(v2); }
  glm::vec3 center() const { return (v0 + v1 + v2) / 3.f; }
  glm::vec3 v0, v1, v2;
};

} // namespace geometry

#endif // !TRIANGLE_HPP
