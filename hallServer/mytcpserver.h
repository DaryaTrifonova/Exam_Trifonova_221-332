
#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtNetwork>
#include <QByteArray>
#include <QDebug>
#include <QList>
#include "func_for_server.h"


class mytcpserver : public QObject
{
    Q_OBJECT
public:
    explicit mytcpserver(QObject *parent = nullptr);
    ~mytcpserver();
public slots:
    void slotNewConnection();
    void slotClientDisconnected();

    void slotServerRead();
private:
    QTcpServer * mTcpServer;
    QList<QTcpSocket*> mTcpSocket;
    int server_status;
};

#endif // MYTCPSERVER_H
