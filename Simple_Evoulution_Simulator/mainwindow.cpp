#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->viewport->setPointerToPaintVector(&Organisms);

    timer = new QTimer(this);
    timer->setInterval(0);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(everyTickSlot()));
}


void MainWindow::everyTickSlot()
{
    ui->viewport->update();
}



MainWindow::~MainWindow()
{
    delete ui;
}

