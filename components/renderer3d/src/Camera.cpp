#include "vida/renderer3d/Camera.hpp"
#include "vida/core/Math.hpp"
#include "vida/core/Model.hpp"

namespace Vida {
Vec3 Camera::GetPos() const { return position; }
void Camera::Move(Vec3 pos) { position = pos; }

Vec3 Camera::PointingTo() const { return target; }
void Camera::PointTo(Vec3 target) { this->target = target; }
void Camera::PointTo(Model model) { target = model.Origin(); };

float Camera::GetFOV() const { return fov; }
void Camera::SetFOV(float fov) { this->fov = fov; }
} // namespace Vida
