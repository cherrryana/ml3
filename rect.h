#ifndef RECT_H
#define RECT_H

class QPainter;
class Rect
{
public:
    Rect();
    Rect(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0);

    int getX1() const;
    void setX1(int value);

    int getY1() const;
    void setY1(int value);

    int getX2() const;
    void setX2(int value);

    int getY2() const;
    void setY2(int value);

    void draw(QPainter *painter);


private:
    int x1, y1, x2, y2;
};

#endif // RECT_H
