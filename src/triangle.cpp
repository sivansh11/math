#include "math/triangle.hpp"

std::ostream &operator<<(std::ostream &o, const math::triangle_t &triangle) {
  o << "triangle(.v0=" << triangle.v0 << "), .v1=" << triangle.v1
    << "), .v2=" << triangle.v2 << ")";
  return o;
}
