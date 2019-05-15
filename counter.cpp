#include "counter.h"

counter::counter(QObject *parent) : QObject(parent)
{

}

void counter::setup()
{
    ard.setPortName(comport);
//    ard.open(QSerialPort::ReadWrite);
    ard.setBaudRate(QSerialPort::Baud9600);
    ard.setDataBits(QSerialPort::Data8);
    ard.setFlowControl(QSerialPort::NoFlowControl);
    ard.setParity(QSerialPort::NoParity);
    ard.setStopBits(QSerialPort::OneStop);
    ard.setReadBufferSize(400);
}

void counter::run()
{
    this->setup();
   ard.open(QSerialPort::ReadWrite);
    if(ard.isOpen())
    {
        qDebug() << "Connected";
        shall_read = true;
        c=0;
        while(shall_read)
            {
//            ard.write("?/r/n");
//            qDebug() << ard.waitForBytesWritten(10);
//            qDebug() << ard.bytesAvailable();
//            qDebug() << ard.waitForReadyRead();
            ard.waitForReadyRead();
            QThread::msleep(10);
            if (ard.bytesAvailable()>=16)
                    {
                        data = ard.readLine();
                        if(data[5]=='A' || data[5]=='@')
                        {
                            data.chop(2);
                            data.remove(0,6);
                            present = data.toInt();
                            send_data = QString::number(present);
                          qDebug() << send_data;
                        }
                        else
                        {
                            data.chop(2);
                            data.remove(0,6);
                            present = data.toInt()*(-1);
                            send_data = QString::number(present);
                          qDebug() << send_data;
                        }
                        emit thread_signal_object(send_data);
                    }
            }
    }
    else{
        qDebug() << "Not connected" ;
    }
    qDebug() << "Stopped";
//    ard.close();

}
