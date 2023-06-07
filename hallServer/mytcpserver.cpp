
#include "mytcpserver.h"

mytcpserver::~mytcpserver()
{
    mTcpServer->close();
    server_status = 0;
}

mytcpserver::mytcpserver(QObject *parent) : QObject(parent)
{
    mTcpServer = new QTcpServer(this);
    connect(mTcpServer, &QTcpServer::newConnection, this, &mytcpserver::slotNewConnection);

    if (!mTcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() << "server is not started";
    } else {
        server_status = 1;
        qDebug() << "server is started";
    }
}

void mytcpserver::slotNewConnection()
{
    qDebug() << "client connected";
    if (server_status == 1) {
        QTcpSocket* curr_mTcpSocket = mTcpServer->nextPendingConnection();
        connect(curr_mTcpSocket, &QTcpSocket::readyRead, this, &mytcpserver::slotServerRead);
        connect(curr_mTcpSocket, &QTcpSocket::disconnected, this, &mytcpserver::slotClientDisconnected);
        mTcpSocket.push_back(curr_mTcpSocket);
    }
}

void mytcpserver::slotServerRead()
{
    QByteArray array;
    QTcpSocket* curr_mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    qDebug() << "То, что в сокете до отправки в массив: " << curr_mTcpSocket->peek(curr_mTcpSocket->bytesAvailable());

    if (curr_mTcpSocket->bytesAvailable() > 0) {
        array.clear();
        array = curr_mTcpSocket->readAll();
        qDebug() << "Массив после считывания из сокета: " << array;
        QString task = QString::fromUtf8(array);
        qDebug() << task;
        QByteArray response = parsing(task);
        qDebug() << response;
        curr_mTcpSocket->write(response);
        qDebug() << "Правильно: " << curr_mTcpSocket->peek(curr_mTcpSocket->bytesAvailable());
    }
}

void mytcpserver::slotClientDisconnected()
{
    QTcpSocket* curr_mTcpSocket = qobject_cast<QTcpSocket*>(sender());
    curr_mTcpSocket->close();
    curr_mTcpSocket->deleteLater();
}
