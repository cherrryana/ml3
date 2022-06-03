#include "rect.h"
#include <QPainter>

Rect::Rect(int x1, int y1, int x2, int y2)
    : x1(x1), y1(y1), x2(x2), y2(y2)
{

}

int Rect::getX1() const
{
    return x1;
}

void Rect::setX1(int value)
{
    x1 = value;
}

int Rect::getY1() const
{
    return y1;
}

void Rect::setY1(int value)
{
    y1 = value;
}

int Rect::getX2() const
{
    return x2;
}

void Rect::setX2(int value)
{
    x2 = value;
}

int Rect::getY2() const
{
    return y2;
}

void Rect::setY2(int value)
{
    y2 = value;
}


void Rect::draw(QPainter *painter)
{
    painter -> drawLine(x1, y1, x1, y2);
    painter -> drawLine(x1, y1, x2, y1);
    painter -> drawLine(x2, y1, x2, y2);
    painter -> drawLine(x1, y2, x2, y2);
}

