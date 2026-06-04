#pragma once

namespace Vida {
class ColorRGBA {
public:
  ColorRGBA(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {};
  ColorRGBA(int r, int g, int b) : r(r), g(g), b(b), a(255) {};
  ColorRGBA() : r(255), g(255), b(255), a(255) {};
  ColorRGBA(ColorRGBA &&) = default;
  ColorRGBA(const ColorRGBA &) = default;
  ColorRGBA &operator=(ColorRGBA &&) = default;
  ColorRGBA &operator=(const ColorRGBA &) = default;
  ~ColorRGBA() = default;

  int r, g, b, a;
};

extern ColorRGBA Black;
extern ColorRGBA Red;
extern ColorRGBA Green;
extern ColorRGBA Blue;
} // namespace Vida
