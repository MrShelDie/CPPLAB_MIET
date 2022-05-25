#include "triangle.h"

Triangle::Triangle(const std::array<QPoint, 3> &_points)
    : points(_points)
{

}

void Triangle::draw(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawPolygon(points.data() , points.size());
}
