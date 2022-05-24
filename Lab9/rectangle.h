#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "abstractshape.h"

class Rectangle : public AbstractShape
{
public:
    Rectangle(const QRectF &rect);

    virtual void draw(QPainter &painter) override;

private:
    QRectF  rect;
};

#endif // RECTANGLE_H
