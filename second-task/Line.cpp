#include <cmath>
#include <iostream>
#include <cassert>
#include <ostream>

struct Point {
  double x;
  double y;
};

struct Line {
  double coefficient;
  double free;

  Line(): coefficient(0), free(0) {} ;

  Line(const Point &p1, const Point &p2) {
    this->coefficient = (double)(p2.y - p1.y) / (p2.x - p1.x);
    this->free = p1.y - this->coefficient * p1.x;
  }

  Line(const Point &p, double coefficient) {
    this->coefficient = coefficient;
    this->free = p.y - this->coefficient * p.x;
  }

  Point intersect(const Line &other) {
    if (coefficient == other.coefficient) {
      return Point{INFINITY, INFINITY};
    }
    Point intersection;
    intersection.x =
        (other.free - free) / (coefficient - other.coefficient);
    intersection.y = coefficient * intersection.x;
    return intersection;
  }

  Line perpendicular(const Point &point) {
    if (coefficient == 0) {
      return {point, INFINITY};
    }
    if (coefficient == INFINITY) {
      return {point, 0};
    }
    return {point, -1 / this->coefficient};
  }
};

void testIntersect() {
    Line l1 = Line(Point{2, 2}, Point{0, 0});
    Line l2 = Line(Point{1.5, 0}, 4);

    Point intersection = l1.intersect(l2);
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

void testParallel() {
  Line l1 = Line({2, 1}, 2);
  Line l2 = Line({3, 1}, 2);

  Point p = l1.intersect(l2);

  std::cout << p.x << " " << p.y << std::endl;
}

int main() {
    testIntersect();
    testPerpendicular();
    testConstructors();
    testParallel();

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}

