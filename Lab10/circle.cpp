#include "circle.h"

#include <cmath>

Circle::Circle(const QPoint &_center, int _radius)
    : center(_center),
      radius(_radius)
{

}

void Circle::draw(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.setPen(QPen(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(center, radius, radius);
}

bool Circle::isPointInside(const QPoint &point) const
{
    return radius >= std::sqrt(
                std::pow(point.x() - center.x(), 2)
                + std::pow(point.y() - center.y(), 2));
}
