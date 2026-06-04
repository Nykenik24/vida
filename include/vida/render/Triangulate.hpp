#pragma once
#include "vida/Vector.hpp"
#include <vector>

namespace Vida {

std::vector<Vector3> Triangulate(const std::vector<Vector2f> &points);

} // namespace Vida
