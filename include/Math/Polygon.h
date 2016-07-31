#ifndef GAME_POLYGON_H
#define GAME_POLYGON_H

#include <vector>
#include "Point.h"

struct Polygon {
    std::vector<Point> points;

    void rotate(double originX, double originY, double angle);
    void scale(double originX, double originY, double factorX, double factorY);
    void translate(double dx, double dy);
};

#endif //GAME_POLYGON_H
