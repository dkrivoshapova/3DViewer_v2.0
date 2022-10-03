#include "vertex.h"

namespace s21 {

Vertex::Vertex(Point position) : _position(position) {}

Point Vertex::GetPosition() { return _position; }

void Vertex::SetPosition(Point point) { _position = point; }

}  // namespace s21