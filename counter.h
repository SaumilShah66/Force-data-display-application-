#ifndef COUNTER_H
#define COUNTER_H
#include <QDebug>
#include <dos.h>
#include <QObject>
#include <QThread>
#include <QSerialPort>
class counter : public QObject
{
    Q_OBJECT
public:
    explicit counter(QObject *parent = nullptr);
    void setup();
    bool shall_read = true;
    long c=0;
    QString send_this;
signals:
    void thread_signal_object(QString);

public slots:
    void run();

private:
    QSerialPort ard;
    QString comport = "COM4";
    QString data;
    signed int present;
    QString send_data;
};

#endif // COUNTER_H
