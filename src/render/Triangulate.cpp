#include "vida/render/Triangulate.hpp"
#include "vida/Vector.hpp"
#include <cmath>
#include <optional>
#include <poly2tri/poly2tri.h>

namespace Vida {

static float Cross2D(Vector2f o, Vector2f a, Vector2f b) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

static bool NearlyEqual(float a, float b, float eps = 0.01f) {
  return std::fabs(a - b) < eps;
}

static bool SegmentsIntersect(Vector2f a, Vector2f b, Vector2f c, Vector2f d) {
  float d1 = Cross2D(c, d, a);
  float d2 = Cross2D(c, d, b);
  float d3 = Cross2D(a, b, c);
  float d4 = Cross2D(a, b, d);

  if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
      ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
    return true;

  return false;
}

std::optional<std::string>
ValidatePolygon(const std::vector<Vector2f> &points) {
  int n = points.size();

  if (n < 3)
    return "Polygon must have at least 3 points (got " + std::to_string(n) +
           ")";

  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (NearlyEqual(points[i].x, points[j].x) &&
          NearlyEqual(points[i].y, points[j].y))
        return "Duplicate points at index " + std::to_string(i) + " and " +
               std::to_string(j);

  for (int i = 0; i < n; i++) {
    Vector2f a = points[i], b = points[(i + 1) % n];
    for (int j = i + 2; j < n; j++) {
      if (i == 0 && j == n - 1)
        continue;
      Vector2f c = points[j], d = points[(j + 1) % n];
      if (SegmentsIntersect(a, b, c, d))
        return "Edges " + std::to_string(i) + "-" + std::to_string(i + 1) +
               " and " + std::to_string(j) + "-" + std::to_string(j + 1) +
               " intersect";
    }
  }

  return std::nullopt;
}

std::vector<Vector3> Triangulate(const std::vector<Vector2f> &points) {
  if (auto err = ValidatePolygon(points)) {
    fprintf(stderr, "Triangulate error: %s\n", err->c_str());
    return {};
  }

  std::vector<p2t::Point *> polyline;
  polyline.reserve(points.size());
  for (auto &p : points)
    polyline.push_back(new p2t::Point(p.x, p.y));

  p2t::CDT cdt(polyline);
  cdt.Triangulate();

  auto triangles = cdt.GetTriangles();

  std::vector<Vector3> result;
  result.reserve(triangles.size());
  for (auto *tri : triangles) {
    int indices[3];
    for (int i = 0; i < 3; i++) {
      p2t::Point *pt = tri->GetPoint(i);
      for (int j = 0; j < (int)points.size(); j++) {
        if (NearlyEqual(points[j].x, pt->x) &&
            NearlyEqual(points[j].y, pt->y)) {
          indices[i] = j;
          break;
        }
      }
    }
    result.push_back(Vector3(indices[0], indices[1], indices[2]));
  }

  for (auto *p : polyline)
    delete p;
  return result;
}

} // namespace Vida
