#include "viewport.h"

Viewport::Viewport(QWidget *parent) : QFrame(parent)
{
    background_color = QColor(163, 145, 145);
}

void Viewport::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setWindow(-width()/2, height()/2, width(), -height());//Декартова система координат

    p.setBrush(QBrush(background_color, Qt::SolidPattern));
    p.setPen(QPen(Qt::red, 1, Qt::SolidLine)); // Настройки рисования
    p.drawRect(QRect(QPoint(-width()/2, height()/2), QPoint(width()/2-2, -height()/2)));//Фон
}


