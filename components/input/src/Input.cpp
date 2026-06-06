#include "vida/input/Input.hpp"
#include <GLFW/glfw3.h>

namespace Vida {

Input::Input(Window &window) : window(window) {
  glfwSetWindowUserPointer(window.Handle(), this);
  glfwSetKeyCallback(window.Handle(), KeyCallback);
  glfwSetMouseButtonCallback(window.Handle(), MouseButtonCallback);
  glfwSetCursorPosCallback(window.Handle(), CursorCallback);
  glfwSetScrollCallback(window.Handle(), ScrollCallback);
}

void Input::Update() {
  for (int i = 0; i < 512; i++)
    keys_previous[i] = keys_current[i];

  for (int i = 0; i < 3; i++)
    mouse_previous[i] = mouse_current[i];

  mouse_delta = mouse_pos - mouse_pos_previous;
  mouse_pos_previous = mouse_pos;
  scroll_delta = 0.0f;
}

bool Input::IsKeyDown(Key key) const {
  int k = ToGLFWKey(key);
  if (k < 0 || k >= 512)
    return false;
  return keys_current[k];
}

bool Input::IsKeyPressed(Key key) const {
  int k = ToGLFWKey(key);
  if (k < 0 || k >= 512)
    return false;
  return keys_current[k] && !keys_previous[k];
}

bool Input::IsKeyReleased(Key key) const {
  int k = ToGLFWKey(key);
  if (k < 0 || k >= 512)
    return false;
  return !keys_current[k] && keys_previous[k];
}

bool Input::IsMouseDown(MouseButton button) const {
  int b = ToGLFWButton(button);
  if (b < 0 || b >= 3)
    return false;
  return mouse_current[b];
}

bool Input::IsMousePressed(MouseButton button) const {
  int b = ToGLFWButton(button);
  if (b < 0 || b >= 3)
    return false;
  return mouse_current[b] && !mouse_previous[b];
}

bool Input::IsMouseReleased(MouseButton button) const {
  int b = ToGLFWButton(button);
  if (b < 0 || b >= 3)
    return false;
  return !mouse_current[b] && mouse_previous[b];
}

void Input::KeyCallback(GLFWwindow *w, int key, int, int action, int) {
  auto *self = static_cast<Input *>(glfwGetWindowUserPointer(w));
  if (key >= 0 && key < 512) {
    if (action == GLFW_PRESS)
      self->keys_current[key] = true;
    if (action == GLFW_RELEASE)
      self->keys_current[key] = false;
  }
}

void Input::MouseButtonCallback(GLFWwindow *w, int button, int action, int) {
  auto *self = static_cast<Input *>(glfwGetWindowUserPointer(w));
  if (button >= 0 && button < 3) {
    if (action == GLFW_PRESS)
      self->mouse_current[button] = true;
    if (action == GLFW_RELEASE)
      self->mouse_current[button] = false;
  }
}

void Input::CursorCallback(GLFWwindow *w, double x, double y) {
  auto *self = static_cast<Input *>(glfwGetWindowUserPointer(w));
  self->mouse_pos = Vec2((float)x, (float)y);
}

void Input::ScrollCallback(GLFWwindow *w, double, double y) {
  auto *self = static_cast<Input *>(glfwGetWindowUserPointer(w));
  self->scroll_delta = (float)y;
}

int Input::ToGLFWKey(Key key) {
  switch (key) {
  case Key::Space:
    return GLFW_KEY_SPACE;
  case Key::Exclamation:
    return GLFW_KEY_UNKNOWN;
  case Key::Hash:
    return GLFW_KEY_UNKNOWN;
  case Key::Apostrophe:
    return GLFW_KEY_APOSTROPHE;
  case Key::Comma:
    return GLFW_KEY_COMMA;
  case Key::Minus:
    return GLFW_KEY_MINUS;
  case Key::Period:
    return GLFW_KEY_PERIOD;
  case Key::Slash:
    return GLFW_KEY_SLASH;
  case Key::Num0:
    return GLFW_KEY_0;
  case Key::Num1:
    return GLFW_KEY_1;
  case Key::Num2:
    return GLFW_KEY_2;
  case Key::Num3:
    return GLFW_KEY_3;
  case Key::Num4:
    return GLFW_KEY_4;
  case Key::Num5:
    return GLFW_KEY_5;
  case Key::Num6:
    return GLFW_KEY_6;
  case Key::Num7:
    return GLFW_KEY_7;
  case Key::Num8:
    return GLFW_KEY_8;
  case Key::Num9:
    return GLFW_KEY_9;
  case Key::Semicolon:
    return GLFW_KEY_SEMICOLON;
  case Key::Equal:
    return GLFW_KEY_EQUAL;
  case Key::A:
    return GLFW_KEY_A;
  case Key::B:
    return GLFW_KEY_B;
  case Key::C:
    return GLFW_KEY_C;
  case Key::D:
    return GLFW_KEY_D;
  case Key::E:
    return GLFW_KEY_E;
  case Key::F:
    return GLFW_KEY_F;
  case Key::G:
    return GLFW_KEY_G;
  case Key::H:
    return GLFW_KEY_H;
  case Key::I:
    return GLFW_KEY_I;
  case Key::J:
    return GLFW_KEY_J;
  case Key::K:
    return GLFW_KEY_K;
  case Key::L:
    return GLFW_KEY_L;
  case Key::M:
    return GLFW_KEY_M;
  case Key::N:
    return GLFW_KEY_N;
  case Key::O:
    return GLFW_KEY_O;
  case Key::P:
    return GLFW_KEY_P;
  case Key::Q:
    return GLFW_KEY_Q;
  case Key::R:
    return GLFW_KEY_R;
  case Key::S:
    return GLFW_KEY_S;
  case Key::T:
    return GLFW_KEY_T;
  case Key::U:
    return GLFW_KEY_U;
  case Key::V:
    return GLFW_KEY_V;
  case Key::W:
    return GLFW_KEY_W;
  case Key::X:
    return GLFW_KEY_X;
  case Key::Y:
    return GLFW_KEY_Y;
  case Key::Z:
    return GLFW_KEY_Z;
  case Key::LeftBracket:
    return GLFW_KEY_LEFT_BRACKET;
  case Key::Backslash:
    return GLFW_KEY_BACKSLASH;
  case Key::RightBracket:
    return GLFW_KEY_RIGHT_BRACKET;
  case Key::Backtick:
    return GLFW_KEY_GRAVE_ACCENT;
  case Key::Escape:
    return GLFW_KEY_ESCAPE;
  case Key::Enter:
    return GLFW_KEY_ENTER;
  case Key::Tab:
    return GLFW_KEY_TAB;
  case Key::Backspace:
    return GLFW_KEY_BACKSPACE;
  case Key::Insert:
    return GLFW_KEY_INSERT;
  case Key::Delete:
    return GLFW_KEY_DELETE;
  case Key::Right:
    return GLFW_KEY_RIGHT;
  case Key::Left:
    return GLFW_KEY_LEFT;
  case Key::Down:
    return GLFW_KEY_DOWN;
  case Key::Up:
    return GLFW_KEY_UP;
  case Key::PageUp:
    return GLFW_KEY_PAGE_UP;
  case Key::PageDown:
    return GLFW_KEY_PAGE_DOWN;
  case Key::Home:
    return GLFW_KEY_HOME;
  case Key::End:
    return GLFW_KEY_END;
  case Key::F1:
    return GLFW_KEY_F1;
  case Key::F2:
    return GLFW_KEY_F2;
  case Key::F3:
    return GLFW_KEY_F3;
  case Key::F4:
    return GLFW_KEY_F4;
  case Key::F5:
    return GLFW_KEY_F5;
  case Key::F6:
    return GLFW_KEY_F6;
  case Key::F7:
    return GLFW_KEY_F7;
  case Key::F8:
    return GLFW_KEY_F8;
  case Key::F9:
    return GLFW_KEY_F9;
  case Key::F10:
    return GLFW_KEY_F10;
  case Key::F11:
    return GLFW_KEY_F11;
  case Key::F12:
    return GLFW_KEY_F12;
  case Key::LeftShift:
    return GLFW_KEY_LEFT_SHIFT;
  case Key::RightShift:
    return GLFW_KEY_RIGHT_SHIFT;
  case Key::LeftCtrl:
    return GLFW_KEY_LEFT_CONTROL;
  case Key::RightCtrl:
    return GLFW_KEY_RIGHT_CONTROL;
  case Key::LeftAlt:
    return GLFW_KEY_LEFT_ALT;
  case Key::RightAlt:
    return GLFW_KEY_RIGHT_ALT;
  default:
    return GLFW_KEY_UNKNOWN;
  }
}

int Input::ToGLFWButton(MouseButton button) {
  switch (button) {
  case MouseButton::Left:
    return GLFW_MOUSE_BUTTON_LEFT;
  case MouseButton::Right:
    return GLFW_MOUSE_BUTTON_RIGHT;
  case MouseButton::Middle:
    return GLFW_MOUSE_BUTTON_MIDDLE;
  default:
    return -1;
  }
}

} // namespace Vida
