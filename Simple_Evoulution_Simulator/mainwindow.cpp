#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->viewport->setPointerToPaintVector(&Organisms);

    Organism org1;
    org1.setXPos(0);
    org1.setYPos(0);
    org1.setColor(Qt::red);

    Genom gen1;
    gen1.setSize(1);

    org1.setGenom(gen1);

    Organisms.push_back(org1);

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

