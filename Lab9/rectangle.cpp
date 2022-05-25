#include "rectangle.h"

Rectangle::Rectangle(const QRectF &_rect)
    : rect(_rect)
{

}

void Rectangle::draw(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawRect(rect);
}
