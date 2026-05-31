#include "vida2d/time/time.hpp"
#include "vida2d.hpp"

namespace Vida2D {
namespace Time {
double GetDelta() { return Context::GetInstance().dt; }
} // namespace Time
} // namespace Vida2D
