#pragma once

#include "vida/core/Math.hpp"
#include "vida/core/Model.hpp"

namespace Vida {
class Camera {
public:
  Vec3 GetPos() const;
  void Move(Vec3 pos);

  Vec3 PointingTo() const;
  void PointTo(Vec3 target);
  void PointTo(Model model);

  float GetFOV() const;
  void SetFOV(float fov);

  Mat4 ViewMatrix() const;
  Mat4 ProjectionMatrix(int width, int height) const;

private:
  Vec3 position = Vec3(0.0f, 0.0f, 5.0f);
  Vec3 target = Vec3(0.0f, 0.0f, 0.0f);
  float fov = 45.0f;
  bool orthographic = false;

  friend class Renderer3D;
  friend class Renderer2D;
};
} // namespace Vida
