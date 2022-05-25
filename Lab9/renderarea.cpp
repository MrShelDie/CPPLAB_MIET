#include "renderarea.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
{
    shapes.emplace_back(new Circle(QPoint(100, 40), 10));
    shapes.emplace_back(new Square(QPoint(180, 200), 30));
    shapes.emplace_back(new Triangle({
        QPoint(220, 130),
        QPoint(240, 130),
        QPoint(360, 420),
    }));
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter painter(this);

    for (const auto &item : shapes)
        (*item).draw(painter);
}
