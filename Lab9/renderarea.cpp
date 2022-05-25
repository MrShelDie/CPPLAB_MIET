#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
{

}

void RenderArea::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter painter(this);

    Rectangle rect(QRectF(70, 10, 70, 10));
    rect.draw(painter);

    Circle circ(QRectF(180, 180, 180, 180));
    circ.draw(painter);
}
