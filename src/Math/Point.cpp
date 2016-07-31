#include "Math/Point.h"

void Point::rotate(double originX, double originY, double angle) {
    translate(-originX, -originY);
    double c = std::cos(angle);
    double s = std::sin(angle);
    x = x * c - y * s;
    y = x * s + y * c;
    translate(originX, originY);
}

void Point::translate(double dx, double dy) {
    x += dx;
    y += dy;
}

void Point::scale(double originX, double originY, double factorX, double factorY) {
    translate(-originX, -originY);
    x *= factorX;
    y *= factorY;
    translate(originX, originY);
}

Point::Point(double x, double y) : x(x), y(y) {}
