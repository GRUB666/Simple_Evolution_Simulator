#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QFrame>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QKeyEvent>

#include "organism.h"


class Viewport : public QFrame
{
    Q_OBJECT

private:
    QColor background_color;
    QVector<Organism> *ToPaintVector;

protected:
    virtual void paintEvent(QPaintEvent*);

public:
    explicit Viewport(QWidget *parent = nullptr);

    void setPointerToPaintVector(QVector<Organism> *value);

    ~Viewport();

signals:

};

#endif // VIEWPORT_H
