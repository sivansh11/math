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

} // namespace math

std::ostream &operator<(std::ostream &o, const math::vec2 &v);
std::ostream &operator<(std::ostream &o, const math::vec3 &v);
std::ostream &operator<(std::ostream &o, const math::vec4 &v);

#endif // !MATH_HPP
