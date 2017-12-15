#ifndef SCREENAREA_H
#define SCREENAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QPoint>
#include <QPixmap>
#include <QPaintEvent>

class ScreenArea : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenArea(QWidget *parent = 0);
    QPixmap getFullScreen();
    void GetScreenShot(); //���ػ�ȡ�Ľ�������


signals:
    void echoPixmap(QPixmap pixmap);

protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QPixmap mScreenPixmap;
    QPixmap mFullPixmap;
    QPoint mStartPoint;
    QPoint mEndPoint;
    int mDistance;
};

#endif // SCREENAREA_H
