#include "point.h"
#include <QPainter>
#include <QPoint>

Point::Point(int x, int y)
     : x(x), y(y)
{
}

int Point::getX() const
{
    return x;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int newY)
{
    y = newY;
}

