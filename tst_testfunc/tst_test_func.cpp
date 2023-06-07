
#include <QtTest>
#include "../examtest/func_for_server.h"
//#include "../examtest/mytcpserver.h"

// add necessary includes here

class test_func : public QObject
{
    Q_OBJECT

public:
    test_func();
    ~test_func();

private slots:
    void test_case1();

};

test_func::test_func()
{

}

test_func::~test_func()
{

}

void test_func::test_case1()
{
    QStringList params = { "2","1 2 3 4 5"};
    QCOMPARE(sort(params),"4 5 2 3 1");

    QStringList params1 = { "3","1 2 3 4 5"};
    QCOMPARE(sort(params1),"4 2 1 3 5");

    QStringList params2 = { "5","1 2 3 4 5"};
    QCOMPARE(sort(params2),"5 1 2 3 4");

    QStringList params3 = { "7","1 2 3 4 5"};
    QCOMPARE(sort(params3),"2 1 3 5 4");

    QStringList params4 = { "1","1 2 3 4 5"};
    QCOMPARE(sort(params4),"2 3 1 4 5");

    QStringList params5 = { "6","1 2 3 4 5"};
    QCOMPARE(sort(params5),"5 4 3 2 1");

    QStringList params6 = { "4","5 8 4 1 2"};
    QCOMPARE(sort(params6),"5 2 1 4 8");

    QStringList params7 = { "8","5 8 4 1 2"};
    QCOMPARE(sort(params7),"2 1 8 4 5");

    QStringList params8 = { "3","5 8 4 1 2"};
    QCOMPARE(sort(params8),"1 4 2 8 5");

    QStringList params9 = { "2","5 8 4 1 2"};
    QCOMPARE(sort(params9),"8 5 4 1 2");

}


QTEST_APPLESS_MAIN(test_func)

#include "tst_test_func.moc"
