#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
{

}

void RenderArea::paintEvent(QPaintEvent *event)
{
    (void)event;

    QPainter painter(this);
    Rectangle rect(QRectF(10, 10, 10, 10));
    rect.draw(painter);
}
