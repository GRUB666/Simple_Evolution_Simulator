#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PI 3.14159265

#include <QMainWindow>
#include <QTimer>

#include "organism.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QVector<Object> Objects;
    QTimer *timer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void EvolutionCalc();

private:
    Ui::MainWindow *ui;

public slots:
    void everyTickSlot();
};
#endif // MAINWINDOW_H
