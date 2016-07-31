#include "Math/Polygon.h"

void Polygon::rotate(double originX, double originY, double angle) {
    for(auto& point : points) {
        point.rotate(originX, originY, angle);
    }
}

void Polygon::translate(double dx, double dy) {
    for(auto& point : points) {
        point.translate(dx, dy);
    }
}

void Polygon::scale(double originX, double originY, double factorX, double factorY) {
    for(auto& point : points) {
        point.scale(originX, originY, factorX, factorY);
    }
}
