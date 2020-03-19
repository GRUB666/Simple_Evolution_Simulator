#include "viewport.h"

Viewport::Viewport(QWidget *parent) : QFrame(parent)
{
    background_color = QColor(108, 100, 135);
}

void Viewport::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setWindow(-width()/2, height()/2, width(), -height());//Декартова система координат

    p.setBrush(QBrush(background_color, Qt::SolidPattern));
    p.setPen(QPen(Qt::black, 1, Qt::SolidLine)); // Настройки рисования
    p.drawRect(QRect(QPoint(-width()/2, height()/2), QPoint(width()/2-2, -height()/2)));//Фон




    if(ToPaintVector != nullptr)
    {
        for(auto &var : *ToPaintVector)
        {
            p.setBrush(QBrush(var.getColor(), Qt::SolidPattern));
            p.drawEllipse(var.getXPos() - var.getGenom().getSize()/2, var.getYPos() - var.getGenom().getSize()/2, var.getGenom().getSize(), var.getGenom().getSize());
        }
    }
}

void Viewport::setPointerToPaintVector(QVector<Organism> *value)
{
    ToPaintVector = value;
}


Viewport::~Viewport()
{
    delete ToPaintVector;
}


