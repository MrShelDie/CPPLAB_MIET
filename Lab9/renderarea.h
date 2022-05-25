#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "circle.h"
#include "square.h"
#include "triangle.h"

#include <QWidget>
#include <QPainter>
#include <QRectF>
#include <memory>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::list<std::unique_ptr<AbstractShape>>   shapes;

signals:

};

#endif // RENDERAREA_H
