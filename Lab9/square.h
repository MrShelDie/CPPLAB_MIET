#ifndef SQUARE_H
#define SQUARE_H

#include "abstractshape.h"

class Square : public AbstractShape
{
public:
    Square(const QPoint &_pos, int _size);

    virtual void draw(QPainter &painter);

private:
    QPoint  pos;
    int     size;
};

#endif // SQUARE_H
