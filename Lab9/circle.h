#ifndef CIRCLE_H
#define CIRCLE_H

#include "abstractshape.h"

class Circle : public AbstractShape
{
public:
    Circle(const QRectF &_rect);

    virtual void draw(QPainter &painter) override;

private:
    QRectF  rect;
};

#endif // CIRCLE_H
