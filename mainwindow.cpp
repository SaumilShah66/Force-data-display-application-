#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "mythread.h"
#include <dos.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&con,&counter::thread_signal_object, this,&MainWindow::change);
    con.moveToThread(&worker);
    connect(this,&MainWindow::start_thread, &con,&counter::run);
    //QObject::connect(&mthread,SIGNAL(thread_signal()), this,SLOT(change()));
}

MainWindow::~MainWindow()
{
    delete ui;
    worker.quit();
    worker.wait();
}

void MainWindow::on_clear_button_clicked()
{
    qDebug() << "Clicked button";
    emit start_thread();
    worker.start();
    //QThread::sleep(1);
    ui->lcd->display(0);
}

void MainWindow::on_b2_clicked()
{

    ui->lcd->display(0);
    con.shall_read = false;
}

void MainWindow::change(QString st)
{
//    qDebug()<<st;
    ui->lcd->display(st);
}
