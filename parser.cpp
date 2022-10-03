#include "parser.h"

namespace s21 {

void Parser::ParseVertex() {
  std::vector<double> numbers = split(_line);
  if (numbers.size() != 3) throw std::invalid_argument("Wrong file structure!");
  _vertices.push_back(Vertex(Point(numbers[0], numbers[1], numbers[2])));
}

void Parser::ParseEdge() {
  std::vector<double> numbers = split(_line);
  for (size_t i = 0; i < numbers.size() - 1; i++) {
    _edges.push_back(Edge(numbers[i], numbers[i + 1]));
  }
  _edges.push_back(Edge(numbers[numbers.size() - 1], numbers[0]));
}

void Parser::ParseFile(std::string fileName) {
  std::ifstream fout(fileName);
  if (!fout.is_open()) throw std::invalid_argument("Wrong file name!");
  while (fout) {
    std::string line;
    getline(fout, line);
    _line = line;
    DetermineType();
  }
}

void Parser::DetermineType() {
  if (_line.length() > 2 && _line[1] == ' ') {
    if (_line[0] == 'v') {
      ParseVertex();
    } else if (_line[0] == 'f') {
      ParseEdge();
    }
  }
}

std::vector<Vertex> Parser::GetVertices() { return _vertices; }
std::vector<Edge> Parser::GetEdges() { return _edges; }

std::vector<double> split(std::string line) {
  std::regex e("[0-9]*[.,]?[0-9]+(?:[eE][-+]?[0-9]+)?");
  std::regex_iterator<std::string::iterator> rit(line.begin(), line.end(), e);
  std::regex_iterator<std::string::iterator> rend;
  std::vector<double> valixan;
  double value = 0.0;
  for (; rit != rend; ++rit) {
    value = convertToNumber(rit->str());
    valixan.push_back(value);
  }
  return valixan;
}

double convertToNumber(std::string number) {
  std::string::size_type sz;
  double num = std::stod(number, &sz);
  return num;
}

}  // namespace s21