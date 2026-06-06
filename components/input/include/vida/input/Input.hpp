#pragma once

#include "vida/core/Key.hpp"
#include "vida/core/Math.hpp"
#include "vida/core/MouseButton.hpp"
#include "vida/window/Window.hpp"

namespace Vida {

class Input {
public:
  explicit Input(Window &window);

  Input(const Input &) = delete;
  Input &operator=(const Input &) = delete;

  void Update();

  bool IsKeyDown(Key key) const;
  bool IsKeyPressed(Key key) const;
  bool IsKeyReleased(Key key) const;

  bool IsMouseDown(MouseButton button) const;
  bool IsMousePressed(MouseButton button) const;
  bool IsMouseReleased(MouseButton button) const;
  Vec2 MousePosition() const { return mouse_pos; }
  Vec2 MouseDelta() const { return mouse_delta; }
  float ScrollDelta() const { return scroll_delta; };

private:
  Window &window;

  bool keys_current[512] = {};
  bool keys_previous[512] = {};

  bool mouse_current[3] = {};
  bool mouse_previous[3] = {};

  Vec2 mouse_pos = Vec2(0.0f);
  Vec2 mouse_delta = Vec2(0.0f);
  Vec2 mouse_pos_previous = Vec2(0.0f);
  float scroll_delta = 0.0f;

  static void KeyCallback(GLFWwindow *window, int key, int scancode, int action,
                          int mods);
  static void MouseButtonCallback(GLFWwindow *window, int button, int action,
                                  int mods);
  static void CursorCallback(GLFWwindow *window, double x, double y);
  static void ScrollCallback(GLFWwindow *w, double, double y);

  static int ToGLFWKey(Key key);
  static int ToGLFWButton(MouseButton button);
};

} // namespace Vida
