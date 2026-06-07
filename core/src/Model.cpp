#include "vida/core/Model.hpp"
#include "vida/core/Math.hpp"
#include "vida/core/ModelLoader.hpp"

namespace Vida {
Model::Model(const std::string &path) : mesh(ModelLoader::Load(path)) {}
Model::Model(const Mesh &mesh) : mesh(mesh) {}

void Model::Move(Vec3 pos) { position = pos; }
void Model::MoveX(float x) { position.x = x; }
void Model::MoveY(float y) { position.y = y; }
void Model::MoveZ(float z) { position.z = z; };

void Model::Rotate(Vec3 rot) { rotation = rot; }
void Model::RotateX(float x) { rotation.x = x; }
void Model::RotateY(float y) { rotation.y = y; }
void Model::RotateZ(float z) { rotation.z = z; };

void Model::Rescale(Vec3 scale) { this->scale = scale; }
void Model::Rescale(float scalar) { scale += scalar; }
void Model::RescaleX(float x) { scale.x = x; };
void Model::RescaleY(float y) { scale.y = y; };
void Model::RescaleZ(float z) { scale.z = z; }
} // namespace Vida
