#include "mythread.h"
#include <QtCore>
#include <QDebug>
#include<dos.h>

MyThread::MyThread()
{

}

void MyThread::run()
{
    for (int i=0;i<=10;i++) {
    qDebug() << "run";
    emit thread_signal();
    sleep(1);
    sleep(1);
    }

}
