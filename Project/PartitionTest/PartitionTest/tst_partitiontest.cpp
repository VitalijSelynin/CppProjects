#include <QString>
#include <QtTest>

class PartitionTest : public QObject
{
    Q_OBJECT

public:
    PartitionTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void Creation();
};

PartitionTest::PartitionTest()
{
}

void PartitionTest::initTestCase()
{
}

void PartitionTest::cleanupTestCase()
{
}

void PartitionTest::Creation()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(PartitionTest)

#include "tst_partitiontest.moc"
