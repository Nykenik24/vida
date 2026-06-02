#pragma once

class Vector2 {
public:
  Vector2(int x, int y) : x(x), y(y) {};
  Vector2(Vector2 &&) = default;
  Vector2(const Vector2 &) = default;
  Vector2 &operator=(Vector2 &&) = default;
  Vector2 &operator=(const Vector2 &) = default;
  ~Vector2() = default;

  int x, y;
};

class Vector2f {
public:
  Vector2f(float x, float y) : x(x), y(y) {};
  Vector2f(Vector2f &&) = default;
  Vector2f(const Vector2f &) = default;
  Vector2f &operator=(Vector2f &&) = default;
  Vector2f &operator=(const Vector2f &) = default;
  ~Vector2f() = default;

  float x, y;
};

class Vector3 {
public:
  Vector3(int x, int y, int z) : x(x), y(y), z(z) {};
  Vector3(Vector3 &&) = default;
  Vector3(const Vector3 &) = default;
  Vector3 &operator=(Vector3 &&) = default;
  Vector3 &operator=(const Vector3 &) = default;
  ~Vector3() = default;

  int x, y, z;
};

class Vector3f {
public:
  Vector3f(float x, float y, float z) : x(x), y(y), z(z) {};
  Vector3f(Vector3f &&) = default;
  Vector3f(const Vector3f &) = default;
  Vector3f &operator=(Vector3f &&) = default;
  Vector3f &operator=(const Vector3f &) = default;
  ~Vector3f() = default;

  float x, y, z;
};
