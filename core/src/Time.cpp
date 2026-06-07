#include "vida/core/Time.hpp"
#include <chrono>

using Clock = std::chrono::steady_clock;
auto last_frame = Clock::now();
static float dt = 0;

namespace Vida {
namespace Time {
float Delta() { return dt; }
void UpdateDelta() {
  auto now = Clock::now();
  dt = std::chrono::duration<float>(now - last_frame).count();
  last_frame = now;
}
} // namespace Time
} // namespace Vida
