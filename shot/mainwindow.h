#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>
#include <QEvent>
#include <QFocusEvent>
#include "ui_mainwindow.h"
#include "screenarea.h"

class MainWindow : public QMainWindow ,public Ui_MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    bool event(QEvent *event);

private slots:
    void onFullScreen();
    void onSelfScreen();
    void savePicture(const QPixmap &pixmape);

private:
    QPixmap screenShotPixmap;
    QPoint startPoint;
    QPoint endPoint;
    ScreenArea *myScreen;
};

#endif // MAINWINDOW_H
