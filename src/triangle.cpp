#include "math/triangle.hpp"

#include "math/math.hpp"

namespace math {

float triangle_t::area() const {
  math::vec3 e1 = v1 - v0;
  math::vec3 e2 = v2 - v0;
  return math::length(math::cross(e1, e2)) * 0.5f;
}

vec3 triangle_t::normal() const {
  const vec3 edge1 = v1 - v0;
  const vec3 edge2 = v2 - v0;
  vec3       n     = cross(edge1, edge2);
  return normalize(n);
}

math::vec3 split_edge(const math::vec3 a, const math::vec3 b, uint32_t axis,
                      float position) {
  float t = (position - a[axis]) / (b[axis] - a[axis]);
  return a + t * (b - a);
}

std::pair<math::aabb_t, math::aabb_t> triangle_t::split(uint32_t axis,
                                                        float position) const {
  math::aabb_t l_aabb{}, r_aabb{};

  bool q0 = v0[axis] <= position;
  bool q1 = v1[axis] <= position;
  bool q2 = v2[axis] <= position;

  if (q0)
    l_aabb.grow(v0);
  else
    r_aabb.grow(v0);
  if (q1)
    l_aabb.grow(v1);
  else
    r_aabb.grow(v1);
  if (q2)
    l_aabb.grow(v2);
  else
    r_aabb.grow(v2);

  if (q0 ^ q1) {
    math::vec3 m = split_edge(v0, v1, axis, position);
    l_aabb.grow(m);
    r_aabb.grow(m);
  }
  if (q1 ^ q2) {
    math::vec3 m = split_edge(v1, v2, axis, position);
    l_aabb.grow(m);
    r_aabb.grow(m);
  }
  if (q2 ^ q0) {
    math::vec3 m = split_edge(v2, v0, axis, position);
    l_aabb.grow(m);
    r_aabb.grow(m);
  }

  return {l_aabb, r_aabb};
}

}  // namespace math

std::ostream &operator<<(std::ostream &o, const math::triangle_t &triangle) {
  o << "triangle(.v0=" << triangle.v0 << "), .v1=" << triangle.v1
    << "), .v2=" << triangle.v2 << ")";
  return o;
}
