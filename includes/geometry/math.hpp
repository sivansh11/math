#ifndef GEOMETRY_MATH_HPP
#define GEOMETRY_MATH_HPP

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>

namespace geometry {

using namespace glm;

static constexpr float infinity = std::numeric_limits<float>::max();

} // namespace geometry

#endif // !GEOMETRY_MATH_HPP
