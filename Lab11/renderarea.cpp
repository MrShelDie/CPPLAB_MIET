#include "renderarea.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"

RenderArea::RenderArea(QWidget *parent)
    : QWidget{parent}
{
    const QBrush    brush(Qt::black, Qt::SolidPattern);
    const QPen      pen(Qt::black, Qt::SolidPattern);

    pShapes.emplace_back(new Circle(QPoint(100, 40), 10, brush, pen));
    pShapes.emplace_back(new Square(QPoint(180, 200), 30, brush, pen));
    pShapes.emplace_back(new Triangle(
        { QPoint(220, 130), QPoint(240, 130), QPoint(360, 420) },
        brush, pen
    ));

    QWidget::setMouseTracking(true);

    pMenu = std::unique_ptr<QMenu>(new QMenu(this));
    pMenu->addAction("Удалить", this, SLOT(sDeleteShape()));
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    (void)event;
    QPainter painter(this);

    for (auto it = pShapes.rbegin(); it != pShapes.rend(); ++it)
        (*it)->draw(painter);
}

void RenderArea::mouseMoveEvent(QMouseEvent *event)
{
    highlightShapeByPoint(event->pos());

    if ((event->buttons() & Qt::LeftButton) && pClickedShape)
        pClickedShape->move(event->pos() - lastMousePos);

    lastMousePos = event->pos();
    update();
}

void RenderArea::mousePressEvent(QMouseEvent *event)
{
    pClickedShape = getShapeByPoint(event->pos());

    if (event->button() == Qt::MiddleButton && pClickedShape)
        pClickedShape->print();
    else if (event->button() == Qt::RightButton && pClickedShape) {
        pMenu->exec(QCursor::pos());
    }
}

void RenderArea::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && pClickedShape) {
        pClickedShape.reset();
    }
}

std::shared_ptr<AbstractShape>
RenderArea::getShapeByPoint(const QPoint &p)
{
    for (const auto &pShape : pShapes) {
        if (pShape->isPointInside(p)) {
            pClickedShape = pShape;
            return pShape;
        }
    }
    return nullptr;
}

void RenderArea::highlightShapeByPoint(const QPoint &p)
{
    bool isShapeHighlighted = false;
    for (const auto &item : pShapes) {
        if (item->isPointInside(p) && !isShapeHighlighted) {
            item->setPenColor(Qt::red);
            isShapeHighlighted = true;
        }
        else
            item->setPenColor(Qt::black);
    }
}
