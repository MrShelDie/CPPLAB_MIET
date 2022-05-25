#include "circle.h"

Circle::Circle(const QRectF &_rect)
    : rect(_rect)
{

}

void Circle::draw(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawEllipse(rect);
}
