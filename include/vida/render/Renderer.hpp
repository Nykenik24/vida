#pragma once

#include "vida/Vector.hpp"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <string>

namespace Vida {

class Renderer {
public:
  Renderer(std::string title, Vector2 size);
  Renderer(const Renderer &) = delete;
  Renderer &operator=(const Renderer &) = delete;
  Renderer(Renderer &&) = default;
  Renderer &operator=(Renderer &&) = default;
  ~Renderer();

  void SetWindowTitle(std::string title);
  void SetWindowSize(Vector2 size);
  void SetWindowPos(Vector2 pos);

private:
  int windowId = 0;
  static inline bool shouldClose = false;

  void BeginFrame();
  void EndFrame();
  bool ShouldClose() const { return shouldClose; }

  friend class Engine;
};

} // namespace Vida
