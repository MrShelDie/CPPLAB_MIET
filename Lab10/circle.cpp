#include "circle.h"

#include <cmath>

void Circle::draw(QPainter &painter)
{
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawEllipse(center, radius, radius);
}

bool Circle::isPointInside(const QPoint &point) const
{
    return radius >= std::sqrt(
        std::pow(point.x() - center.x(), 2)
        + std::pow(point.y() - center.y(), 2));
}
