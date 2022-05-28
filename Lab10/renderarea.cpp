#include "renderarea.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

#include "iostream"

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
{
    const QBrush    brush(Qt::black, Qt::SolidPattern);
    const QPen      pen(Qt::black, Qt::SolidPattern);

    shapes.emplace_back(new Circle(QPoint(100, 40), 10, brush, pen));
    shapes.emplace_back(new Square(QPoint(180, 200), 30, brush, pen));
    shapes.emplace_back(new Triangle(
        { QPoint(220, 130), QPoint(240, 130), QPoint(360, 420) },
        brush, pen
    ));

    QWidget::setMouseTracking(true);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter painter(this);

    for (const auto &item : shapes)
        (*item).draw(painter);
}

void RenderArea::mouseMoveEvent(QMouseEvent *event)
{
    for (const auto &item : shapes) {
        if (item->isPointInside(event->pos()))
            item->setPenColor(Qt::red);
        else
            item->setPenColor(Qt::black);
    }
    update();
}

void RenderArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton) {
        for (const auto &item : shapes) {
            if (item->isPointInside(event->pos()))
                (*item).print();
        }
    }
}
