#include "circle.h"

#include <cmath>
#include <QTextStream>

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

void Circle::print()
{
    QTextStream out(stdout);

    out << "Center: (" << center.x() << "; " << center.y() << ")\n"
        << "Radius: " << radius << "\n\n";
}
