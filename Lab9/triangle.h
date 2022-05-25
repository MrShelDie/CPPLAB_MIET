#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "abstractshape.h"

#include <array>

class Triangle : public AbstractShape
{
public:
    Triangle(const std::array<QPoint, 3> &_points);

    virtual void draw(QPainter &painter);

private:
    std::array<QPoint, 3>   points;
};

#endif // TRIANGLE_H
