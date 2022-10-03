#ifndef VERTEX_H
#define VERTEX_H

#include "temp.h"
namespace s21 {
class Vertex {
 public:
  Vertex(Point position);
  ~Vertex();

 private:
  Point _position;

 public:
  Point GetPosition();
  void SetPosition(Point point);
};
}  // namespace s21
#endif  // VERTEX_H
