#ifndef SQUARE_H
#define SQUARE_H

#include "abstractshape.h"

class Square : public AbstractShape
{
public:
    Square(const QPoint &_pos, int _size);

    void draw(QPainter &painter) override;
    bool isPointInside(const QPoint &point) const override;

private:
    QPoint  pos;
    int     size;
};

#endif // SQUARE_H
