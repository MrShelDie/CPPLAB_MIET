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

private:
    std::list<std::unique_ptr<AbstractShape>>   shapes;

signals:

};

#endif // RENDERAREA_H
