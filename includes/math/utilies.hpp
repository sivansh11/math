#ifndef MATH_UTILITIES_HPP
#define MATH_UTILITIES_HPP

#include <vector>

#include "math/triangle.hpp"
#include "math/aabb.hpp"

namespace math {

std::vector<math::aabb_t> aabbs_from_triangles(
    const std::vector<math::triangle_t>& triangles);

}

#endif
