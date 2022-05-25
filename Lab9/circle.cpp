#include "circle.h"

Circle::Circle(const QPoint &_center, int _radius)
    : center(_center),
      radius(_radius)
{

}

void Circle::draw(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawEllipse(center, radius, radius);
}
