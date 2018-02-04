#include <QtTest>

// add necessary includes here

class Creation : public QObject
{
    Q_OBJECT

public:
    Creation();
    ~Creation();

private slots:
    void test_case1();

};

Creation::Creation()
{

}

Creation::~Creation()
{

}

void Creation::test_case1()
{

}

QTEST_APPLESS_MAIN(Creation)

#include "tst_creation.moc"
