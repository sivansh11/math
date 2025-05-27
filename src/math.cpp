#include "math/math.hpp"

std::ostream &operator<<(std::ostream &o, const math::vec2 &v) {
  o << math::to_string(v);
  return o;
}
std::ostream &operator<<(std::ostream &o, const math::vec3 &v) {
  o << math::to_string(v);
  return o;
}
std::ostream &operator<<(std::ostream &o, const math::vec4 &v) {
  o << math::to_string(v);
  return o;
}
