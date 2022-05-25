#ifndef RENDERAREA_H
#define RENDERAREA_H

#include "abstractshape.h"

#include <QWidget>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    std::vector<std::unique_ptr<AbstractShape>>   shapes;

signals:

};

#endif // RENDERAREA_H
