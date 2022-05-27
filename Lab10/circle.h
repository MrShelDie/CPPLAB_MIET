#ifndef CIRCLE_H
#define CIRCLE_H

#include "abstractshape.h"

class Circle : public AbstractShape
{
public:
    Circle(const QPoint &_center, int _radius);

    void draw(QPainter &painter) override;
    bool isPointInside(const QPoint &point) const override;

private:
    QPoint center;
    int   radius;
};

#endif // CIRCLE_H
