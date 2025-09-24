#include "math/aabb.hpp"

namespace math {

bool aabb_t::is_valid() const {
  return min != vec3{infinity} && max != vec3{-infinity};
}
vec3 aabb_t::extent() const {
  assert(is_valid());
  return max - min;
}
float aabb_t::largest_extent() const {
  const vec3 e = extent();
  return math::max(e.x, math::max(e.y, e.z));
}
float aabb_t::area() const {
  assert(is_valid());
  const vec3 e = extent();
  return (e.x * e.y + e.y * e.z + e.z * e.x) * 2.f;
}
vec3 aabb_t::center() const {
  assert(is_valid());
  return (max + min) / 2.f;
}
uint32_t aabb_t::largest_axis() const {
  const vec3 e    = extent();
  uint32_t   axis = 0;
  if (e[0] < e[1]) axis = 1;
  if (e[axis] < e[2]) axis = 2;
  return axis;
}
bool aabb_t::intersects(const aabb_t &aabb) const {
  return min.x < aabb.max.x && min.y < aabb.max.y && min.z < aabb.max.z &&
         max.x > aabb.min.x && max.y > aabb.min.y && max.z > aabb.min.z;
}
aabb_t &aabb_t::grow(const vec3 &point) {
  min = math::min(min, point);
  max = math::max(max, point);
  return *this;
}
aabb_t &aabb_t::grow(const aabb_t &aabb) {
  min = math::min(min, aabb.min);
  max = math::max(max, aabb.max);
  return *this;
}
aabb_t &aabb_t::shrink(const aabb_t &aabb) {
  min = math::max(min, aabb.min);
  max = math::min(max, aabb.max);
  return *this;
}

}  // namespace math

std::ostream &operator<<(std::ostream &o, const math::aabb_t &aabb) {
  o << "aabb:\n\tmin: " << to_string(aabb.min)
    << "\n\tmax: " << to_string(aabb.max);
  return o;
}
