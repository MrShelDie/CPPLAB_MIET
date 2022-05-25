#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "rectangle.h"
#include "circle.h"

#include <QWidget>
#include <QPainter>
#include <QRectF>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

};

#endif // RENDERAREA_H
