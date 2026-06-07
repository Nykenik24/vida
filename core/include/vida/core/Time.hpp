#pragma once

#include <chrono>

namespace Vida {
namespace Time {
float Delta();
void UpdateDelta();

class Timer {
public:
  Timer(float duration)
      : duration(duration), timestamp(std::chrono::steady_clock::now()) {};
  Timer(Timer &&) = default;
  Timer(const Timer &) = default;
  Timer &operator=(Timer &&) = default;
  Timer &operator=(const Timer &) = default;
  ~Timer() = default;

  bool Done() {
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration<float>(now - timestamp).count() >= duration) {
      timestamp = now;
      return true;
    }

    return false;
  }

  float Elapsed() const {
    return std::chrono::duration<float>(std::chrono::steady_clock::now() -
                                        timestamp)
        .count();
  };

  void SetDuration(float duration) { this->duration = duration; };

private:
  float duration;
  std::chrono::time_point<std::chrono::steady_clock> timestamp;
};
} // namespace Time
} // namespace Vida
