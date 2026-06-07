#pragma once

#include "vida/core/Math.hpp"
#include "vida/core/Mesh.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <string>

namespace Vida {
class Model {
public:
  Model(const std::string &path);
  explicit Model(const Mesh &mesh);

  Mat4 Transform() const {
    Mat4 t = glm::translate(Mat4(1.0f), position);
    Mat4 rx = glm::rotate(Mat4(1.0f), glm::radians(rotation.x), Vec3(1, 0, 0));
    Mat4 ry = glm::rotate(Mat4(1.0f), glm::radians(rotation.y), Vec3(0, 1, 0));
    Mat4 rz = glm::rotate(Mat4(1.0f), glm::radians(rotation.z), Vec3(0, 0, 1));
    Mat4 s = glm::scale(Mat4(1.0f), scale);
    return t * rz * ry * rx * s;
  }

  const Mesh &GetMesh() const { return mesh; }

  void Move(Vec3 pos);
  void MoveX(float x);
  void MoveY(float y);
  void MoveZ(float z);

  void Rotate(Vec3 rotation);
  void RotateX(float x);
  void RotateY(float y);
  void RotateZ(float z);

  void Rescale(Vec3 scale);
  void Rescale(float scalar);
  void RescaleX(float x);
  void RescaleY(float y);
  void RescaleZ(float z);

  Vec3 Origin() const { return position; };
  Vec3 Rotation() const { return rotation; };
  Vec3 Scale() const { return scale; };

private:
  Mesh mesh;

  Vec3 position = Vec3(0.0f);
  Vec3 rotation = Vec3(0.0f);
  Vec3 scale = Vec3(1.0f);

  friend class ModelLoader;
  friend class Renderer3D;
};

} // namespace Vida
