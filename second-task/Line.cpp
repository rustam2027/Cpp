#include <cmath>
#include <iostream>
#include <cassert>

typedef struct {
  double x;
  double y;
} Point;

class Line {
public:
  double coefficient;
  double free;

  Line() = default;

  Line(const Point &p1, const Point &p2) {
    this->coefficient = (double)(p2.y - p1.y) / (p2.x - p1.x);
    this->free = p1.y - this->coefficient * p1.x;
  }

  Line(const Point &p, double coefficient) {
    this->coefficient = coefficient;
    this->free = p.y - this->coefficient * p.x;
  }

  Point intersect(Line *other) {
    if (this->coefficient == other->coefficient) {
      return Point{INFINITY, INFINITY};
    }
    Point intersection;
    intersection.x =
        (other->free - this->free) / (this->coefficient - other->coefficient);
    intersection.y = this->coefficient * intersection.x;
    return intersection;
  }

  Line perpendicular(const Point &point) {
    if (coefficient == 0) {
      return Line(point, INFINITY);
    }
    if (coefficient == INFINITY) {
      return Line(point, 0);
    }
    Line result = Line(point, -1 / this->coefficient);
    return result;
  }
};

void testIntersect() {
    Line l1 = Line(Point{2, 2}, Point{0, 0});
    Line l2 = Line(Point{1.5, 0}, 4);

    Point intersection = l1.intersect(&l2);
    assert(intersection.x == 2 && intersection.y == 2);
}

void testPerpendicular() {
    Line l1 = Line(Point{2, 1}, Point{0, 0});
    Line perpendicularLine = l1.perpendicular(Point{1, 1});
    assert(perpendicularLine.coefficient == -2);
    assert(perpendicularLine.free == 3);
}

void testConstructors() {
    Line l1 = Line(Point{2, 1}, Point{0, 0});
    assert(l1.coefficient == 0.5);
    assert(l1.free == 0);

    Line l2 = Line(Point{0, 2}, -1);
    assert(l2.coefficient == -1);
    assert(l2.free == 2);
}

int main() {
    testIntersect();
    testPerpendicular();
    testConstructors();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}

