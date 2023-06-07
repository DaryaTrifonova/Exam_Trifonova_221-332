#ifndef FUNC_FOR_SERVER_H
#define FUNC_FOR_SERVER_H
#include <QTcpSocket>
#include <QByteArray>
#include <QString>
#include <QList>
#include <QStringList>
#include <QDebug>
#include <QPointF>
#include <QtCore/QPointF>
#include <QtCore/QStringList>
#include <QtCore/QVector>
QByteArray parsing(QString str);

void heapify(QList<int> arr, int i, int m);

QByteArray sort(QStringList arr1, QString step);

#endif // FUNC_FOR_SERVER_H
