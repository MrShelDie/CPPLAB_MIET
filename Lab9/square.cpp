#include "square.h"

Square::Square(const QPoint &_pos, int _size)
    : pos(_pos),
      size(_size)
{

}

void Square::draw(QPainter &painter)
{
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter.drawRect(pos.x(), pos.y(), size, size);
}
