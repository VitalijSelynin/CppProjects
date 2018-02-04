#include <QString>
#include <QtTest>

class IndexPartitionTest : public QObject
{
    Q_OBJECT

public:
    IndexPartitionTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void Creation();
};

IndexPartitionTest::IndexPartitionTest()
{
}

void IndexPartitionTest::initTestCase()
{
}

void IndexPartitionTest::cleanupTestCase()
{
}

void IndexPartitionTest::Creation()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(IndexPartitionTest)

#include "tst_indexpartitiontest.moc"
