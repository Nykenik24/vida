#pragma once

#include "vida/Color.hpp"
#include "vida/Vector.hpp"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <string>

namespace Vida {

class Renderer {
public:
  Renderer(std::string title, Vector2f size);
  Renderer(const Renderer &) = delete;
  Renderer &operator=(const Renderer &) = delete;
  Renderer(Renderer &&) = default;
  Renderer &operator=(Renderer &&) = default;
  ~Renderer();

  void DrawDot(Vector2f pos, ColorRGBA color = {}, float size = 5.0f);
  void DrawLine(Vector2f a, Vector2f b, ColorRGBA color = {},
                float width = 1.0f);

private:
  void InitShaders();

  int windowId = 0;
  GLuint shaderProgram = 0;
  GLuint vao = 0;
  GLuint vbo = 0;
  Vector2f windowSize;

  static inline bool shouldClose = false;

  void BeginFrame();
  void EndFrame();
  bool ShouldClose() const { return shouldClose; }

  friend class Engine;
};

} // namespace Vida
