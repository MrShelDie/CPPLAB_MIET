#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "abstractshape.h"

#include <QMenu>
#include <QWidget>
#include <QMouseEvent>
#include <memory>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

public slots:
    void sDeleteShape() { pShapes.remove(pClickedShape); };

protected:
    void paintEvent(QPaintEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    std::shared_ptr<AbstractShape> getShapeByPoint(const QPoint &p);
    void highlightShapeByPoint(const QPoint &p);

private:
    std::list<std::shared_ptr<AbstractShape>> pShapes;

    std::shared_ptr<AbstractShape> pClickedShape;
    QPoint lastMousePos;

    std::unique_ptr<QMenu> pMenu;

};

#endif // RENDERAREA_H
