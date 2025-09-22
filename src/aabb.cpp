#include "math/aabb.hpp"

namespace math {

bool aabb_t::is_valid() const {
  return min != glm::vec3{infinity} && max != glm::vec3{-infinity};
}
glm::vec3 aabb_t::extent() const {
  assert(is_valid());
  return max - min;
}
float aabb_t::largest_extent() const {
  const glm::vec3 e = extent();
  return glm::max(e.x, glm::max(e.y, e.z));
}
float aabb_t::area() const {
  assert(is_valid());
  const glm::vec3 e = extent();
  return (e.x * e.y + e.y * e.z + e.z * e.x) * 2.f;
}
glm::vec3 aabb_t::center() const {
  assert(is_valid());
  return (max + min) / 2.f;
}
uint32_t aabb_t::largest_axis() const {
  const glm::vec3 e = extent();
  uint32_t axis = 0;
  if (e[0] < e[1]) axis = 1;
  if (e[axis] < e[2]) axis = 2;
  return axis;
}
aabb_t &aabb_t::grow(const glm::vec3 &point) {
  min = glm::min(min, point);
  max = glm::max(max, point);
  return *this;
}
aabb_t &aabb_t::grow(const aabb_t &aabb) {
  min = glm::min(min, aabb.min);
  max = glm::max(max, aabb.max);
  return *this;
}
aabb_t &aabb_t::shrink(const aabb_t& aabb) {
  min = glm::max(min, aabb.min);
  max = glm::min(max, aabb.max);
  return *this;
}

} // namespace math

std::ostream &operator<<(std::ostream &o, const math::aabb_t &aabb) {
  o << "aabb:\n\tmin: " << glm::to_string(aabb.min)
    << "\n\tmax: " << glm::to_string(aabb.max);
  return o;
}
