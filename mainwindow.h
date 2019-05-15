#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<iostream>
#include <QObject>
#include "counter.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void start_thread();

private slots:
    void on_clear_button_clicked();
    void on_b2_clicked();
    void change(QString);

private:
    Ui::MainWindow *ui;
    counter con;
    QThread worker;

};

#endif // MAINWINDOW_H
