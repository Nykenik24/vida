#include "vida/render/Renderer.hpp"
#include "vida/Vector.hpp"
#include <string>

namespace Vida {
Renderer::Renderer(std::string title, Vector2 size) {
  static bool initialized = false;
  if (!initialized) {
    int argc = 0;
    glutInit(&argc, nullptr);
    initialized = true;
  }
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(static_cast<int>(size.x), static_cast<int>(size.y));
  windowId = glutCreateWindow(title.c_str());

  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  glutDisplayFunc([] {});

  glutCloseFunc([] { Renderer::shouldClose = true; });
}

Renderer::~Renderer() {
  if (windowId != 0)
    glutDestroyWindow(windowId);
}

void Renderer::BeginFrame() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::EndFrame() {
  glutSwapBuffers();
  glutMainLoopEvent();
}

void Renderer::SetWindowTitle(std::string title) {
  glutSetWindowTitle(title.c_str());
}

void Renderer::SetWindowSize(Vector2 size) {
  glutReshapeWindow(size.x, size.y);
}

void Renderer::SetWindowPos(Vector2 pos) { glutPositionWindow(pos.x, pos.y); }
} // namespace Vida
