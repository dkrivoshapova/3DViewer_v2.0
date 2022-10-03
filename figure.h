#ifndef FIGURE_H
#define FIGURE_H
#include <vector>

#include "edge.h"
#include "vertex.h"
namespace s21 {
class Figure {
 private:
  std::vector<Vertex> _vertices;
  std::vector<Edge> _edges;

 public:
  Figure(std::vector<Vertex> vertices, std::vector<Edge> edges);
  std::vector<Vertex> GetVertices();
  std::vector<Edge> GetEdges();
};
}  // namespace s21
#endif  // FIGURE_H