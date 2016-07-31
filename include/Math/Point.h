#ifndef GAME_POINT_H
#define GAME_POINT_H

#include <cmath>

struct Point {
    double x;
    double y;

    Point(double x = 0, double y = 0);
    void rotate(double originX, double originY, double angle);
    void translate(double dx, double dy);
    void scale(double originX, double originY, double factorX, double factorY);
};

#endif //GAME_POINT_H
