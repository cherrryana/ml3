#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point();
    Point(int x, int y);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    int x, y;
};

#endif // POINT_H
