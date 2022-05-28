#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "abstractshape.h"

#include <QWidget>
#include <QMouseEvent>
#include <memory>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    std::list<std::shared_ptr<AbstractShape>> shapes;
    std::shared_ptr<AbstractShape> clickedShape;
    QPoint clickedShapePos;

signals:

};

#endif // RENDERAREA_H
