#include <QDebug>
#include <QScreen>
#include <QFileDialog>
#include <QDir>
#include <QDesktopWidget>
#include <QGuiApplication>
#include <QWidget>
#include <QCheckBox>
#include <QPalette>
#include <QPainter>
#include <QApplication>
#include <QPen>
#include "screenarea.h"

ScreenArea::ScreenArea(QWidget *parent) : QWidget(parent)
{
    setAutoFillBackground(true);
    setWindowFlags(Qt::FramelessWindowHint);
    resize(QApplication::desktop()->width(), QApplication::desktop()->height());
    setCursor(Qt::CrossCursor);

    QScreen *screen = QGuiApplication::primaryScreen(); //获取整个屏幕
    mFullPixmap = screen->grabWindow(0);
}

QPixmap ScreenArea::getFullScreen() //获取全屏
{
    hide();
    return mFullPixmap;
}

void ScreenArea::GetScreenShot()  //获取选择的区域
{
    mScreenPixmap = mFullPixmap.copy(mStartPoint.x(),mStartPoint.y(),
                                   mEndPoint.x() - mStartPoint.y(),mEndPoint.y()-mStartPoint.y());
    hide();
}

void ScreenArea::mouseMoveEvent(QMouseEvent *event)
{
    mDistance = (event->pos() - mStartPoint).manhattanLength();
    if(mDistance > QApplication::startDragDistance())  //
    {
        mEndPoint = event->pos();
        repaint();
    }
}

void ScreenArea::mousePressEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        mStartPoint = event->pos();
        repaint();
    }
}

void ScreenArea::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() & Qt::LeftButton)
    {
        mEndPoint = event->pos();
        mDistance = (event->pos() - mStartPoint).manhattanLength();
        GetScreenShot();
        repaint();
        emit echoPixmap(mScreenPixmap);
    }
}

void ScreenArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, width(), height(), mFullPixmap); //画全屏图
    if(mDistance > QApplication::startDragDistance())
    {
        QPen pen(Qt::red, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        painter.drawRect(QRect(mStartPoint, mEndPoint) ); //画用户选取的区域
    }
}
