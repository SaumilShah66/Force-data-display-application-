#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QtCore>
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run();

signals:
    void thread_signal();
};

#endif // MYTHREAD_H
