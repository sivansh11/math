#include "math/utilies.hpp"

namespace math {

std::vector<math::aabb_t> aabbs_from_triangles(
    const std::vector<math::triangle_t>& triangles) {
  std::vector<aabb_t> aabbs;
  for (const auto& triangle : triangles) {
    aabbs.push_back(triangle.aabb());
  }
  return aabbs;
}

}  // namespace math
