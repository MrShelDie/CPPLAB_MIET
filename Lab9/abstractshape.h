#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QPainter>

class AbstractShape
{
public:
    virtual void draw(QPainter &painter) = 0;
};

#endif // ABSTRACTSHAPE_H
