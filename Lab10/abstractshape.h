#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QPainter>
#include <QPoint>

class AbstractShape
{
public:
    virtual void draw(QPainter &painter) = 0;
//    virtual void setColor(enum Qt::GlobalColor) = 0;
    virtual bool isPointInside(const QPoint &point) const = 0;

//private:
//    enum Qt::GlobalColor ;
};

#endif // ABSTRACTSHAPE_H
