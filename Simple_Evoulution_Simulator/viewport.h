#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QFrame>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QKeyEvent>


class Viewport : public QFrame
{
    Q_OBJECT

private:
    QColor background_color;

protected:
    virtual void paintEvent(QPaintEvent*);

public:
    explicit Viewport(QWidget *parent = nullptr);

signals:

};

#endif // VIEWPORT_H
