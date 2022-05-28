#ifndef CIRCLE_H
#define CIRCLE_H

#include "abstractshape.h"

class Circle : public AbstractShape
{
public:
    Circle(const QPoint &_center, int _radius, QBrush _brush, QPen _pen)
        : AbstractShape(_brush, _pen), center(_center), radius(_radius) {};

    void print() override;
    void draw(QPainter &painter) override;
    void move(const QPoint &offset) override { center += offset; };
    bool isPointInside(const QPoint &point) const override;

private:
    QPoint  center;
    int     radius;
};

#endif // CIRCLE_H
