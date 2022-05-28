#ifndef ABSTRACTSHAPE_H
#define ABSTRACTSHAPE_H

#include <QPainter>
#include <QPoint>
#include <QColor>
#include <QBrush>
#include <QPen>

class AbstractShape
{
public:
    AbstractShape(QBrush &_brush, QPen &_pen) : brush(_brush), pen(_pen) {};

    virtual void print() = 0;
    virtual void draw(QPainter &painter) = 0;
    virtual void move(const QPoint &offset) = 0;
    virtual bool isPointInside(const QPoint &point) const = 0;

    void setBrushColor(enum Qt::GlobalColor color) { brush.setColor(color); };
    void setPenColor(enum Qt::GlobalColor color)   { pen.setColor(color);   };

protected:
    QBrush  brush;
    QPen    pen;
};

#endif // ABSTRACTSHAPE_H
