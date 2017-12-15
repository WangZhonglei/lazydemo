#include <QScreen>
#include <QFileDialog>
#include <QDir>
#include <QDesktopWidget>
#include <QGuiApplication>
#include <QDebug>
#include <QWidget>
#include <QCheckBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("½ØÍ¼¾«Áé"));
    setWindowFlags(Qt::WindowStaysOnTopHint | (windowFlags()& ~Qt::WindowMaximizeButtonHint& ~Qt::WindowMinimizeButtonHint));
    setFixedSize(120,200);
    myScreen = new ScreenArea;
    connect(myScreen,SIGNAL(echoPixmap(QPixmap)),SLOT(savePicture(QPixmap)));
    connect(fullBtn,SIGNAL(clicked(bool)),SLOT(onFullScreen()));
    connect(selfBtn,SIGNAL(clicked(bool)),SLOT(onSelfScreen()));
}

MainWindow::~MainWindow()
{
    delete myScreen;
}

bool MainWindow::event(QEvent *event)
{
    if(event->type() == QEvent::WindowActivate)
    {
        setWindowOpacity(1);
    }
    else if(event->type() == QEvent::WindowDeactivate)
    {
        setWindowOpacity(0.3);
    }
    return QMainWindow::event(event);
}

void MainWindow::onFullScreen()
{
    if(checkBox->isChecked())
    {
        hide();
    }
    myScreen->show();
    screenShotPixmap = myScreen->getFullScreen();
    savePicture(screenShotPixmap);
}

void MainWindow::onSelfScreen()
{
    if(checkBox->isChecked())
    {
        hide();
    }
    myScreen->show();
}

void MainWindow::savePicture(const QPixmap &pixmap)
{
    QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("±£´æÍ¼Æ¬"),
                                                    QDir::currentPath()+ "/untitled.png",
                                                    tr("Images (*.png *.xpm *.jpg)"));
    pixmap.save(fileName);
}
