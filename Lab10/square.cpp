#include "square.h"

void Square::draw(QPainter &painter)
{
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(pos.x(), pos.y(), sideLength, sideLength);
}

bool Square::isPointInside(const QPoint &point) const
{
    if (point.x() >= pos.x() && point.x() <= pos.x() + sideLength
            && point.y() >= pos.y() && point.y() <= pos.y() + sideLength)
        return true;
    return false;
}
