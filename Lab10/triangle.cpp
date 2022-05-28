#include "triangle.h"

#include <QPointF>

void Triangle::draw(QPainter &painter)
{
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawPolygon(points.data() , points.size());
}

bool Triangle::isPointInside(const QPoint &P) const
{
    /* Determines whether a point is in a triangle by the vector method.
     * https://www.youtube.com/watch?v=HYAgJN3x4GA */

    float Ax = points[0].x();
    float Ay = points[0].y();

    float Bx = points[1].x();
    float By = points[1].y();

    float Cx = points[2].x();
    float Cy = points[2].y();

    float Px = P.x();
    float Py = P.y();

    float w1 = (Ax * (Cy - Ay) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay))
            / ((By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay));

    float w2 = (Py - Ay - w1 * (By - Ay)) / (Cy - Ay);

    if (w1 >= 0 && w2 >= 0 && w1 + w2 < 1)
        return true;
    return false;
}

