#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPoint>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Rect *rect = nullptr;
    QMessageBox msgBox;
    QPoint qpoint;
    qpoint.setX(event -> x());
    qpoint.setY(event -> y());

    int maxX = 0, maxY = 0, minX = 0, minY = 0;

    if (k == 0)
    {
        rect = new Rect(event -> x(), event -> y(), 0, 0);
        rects[k] = rect;
        maxX = rects[k] -> getX1();
        maxY = rects[k] -> getY1();
    }

    if (k == 1)
    {
        rects[k-1] -> setX2(event -> x());
        rects[k-1] -> setY2(event -> y());
        minX = rects[k-1] -> getX2();
        minY = rects[k-1] -> getY2();
        repaint();
    }

    k++;

    if (k > 2)
    {

        if ((rects[0] -> getX1()) - (rects[0] -> getX2()) < 0)
        {
            maxX = rects[0] -> getX2();
            minX = rects[0] -> getX1();
        }

        if ((rects[0] -> getY1()) - (rects[0] -> getY2()) < 0)
        {
            maxY = rects[0] -> getY2();
            minY = rects[0] -> getY1();
        }

        if (qpoint.x() > maxX || qpoint.x() < minX || qpoint.y() > maxY || qpoint.y() < minY)
            msgBox.setText("Не попал");

        else msgBox.setText("Попал");
        msgBox.exec();
    }
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    rects[0] -> draw(&painter);
}

