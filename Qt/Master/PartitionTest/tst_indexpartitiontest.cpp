///////////////////////////////////////////////////////////////////////////////////////////////////
//  tst_indexpartitiontest.cpp
//  Implementation of developer tests for the IndexPartitionClass
//  Created on:      24-Sep-2017 14:20:04
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <QString>
#include <QtTest>

#include "IndexPartition.h"

class IndexPartitionTest : public QObject
{
  Q_OBJECT

public:
  IndexPartitionTest();

private:
  void CreationTestImplementation(const unsigned int blocksize, const unsigned int nrOfBlocks);
  void WriteTestImplementation(const unsigned int blocksize, const unsigned int nrOfBlocks);

private Q_SLOTS:
  void initTestCase();
  void cleanupTestCase();
  void Creation();
  void CheckMaxBlocks();
  void CheckWriteBlocks();
  void CheckDeleteBlocks();
  void DeleteMoreBlocks();
  void CheckBlocksFromOtherMemoryPartition();
  void CheckUnalignedPointer();
  void ReverseDeleteBlocks();
  void CheckBlockSize();
  void CheckZeroNrOfBlocks();
  void CheckZeroBlockSize();
  void CheckUnevenBlocksize();
  void CheckMaxBLockSize();
  void CheckBlockSizeHighLimit();
  void CheckNrOfBlocksHighLimit();
  void CheckNrOfBlocksHighValue();
  void CheckBlocksizeHighValue();
};

void
IndexPartitionTest::DeleteMoreBlocks()
{
  const unsigned int blocksize  = 4;
  const unsigned int nrOfBlocks = 10;

  try
  {
    IPartition* partition    = new IndexPartition(blocksize, nrOfBlocks);
    void* pArray[nrOfBlocks] = {0};

    // get the half of possible blocks
    for (unsigned int i = 0; i < nrOfBlocks / 2; i++)
    {
      pArray[i] = partition->GetBlock();
    }

    // delete all blocks
    for (unsigned int i = nrOfBlocks - 1; i > 0; i--)
    {
      partition->RetBlock(pArray[i]);
    }

    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Execption within test case");
  }
}

void
IndexPartitionTest::CheckBlocksFromOtherMemoryPartition()
{
  // TODO: Test Implementation
  QFAIL("Not implemented");
}

void
IndexPartitionTest::CheckUnalignedPointer()
{
  // TODO: Test Implementation
  QFAIL("Not implemented");
}

void
IndexPartitionTest::ReverseDeleteBlocks()
{
  const unsigned int blocksize  = 4;
  const unsigned int nrOfBlocks = 10;

  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);
    void* pArray[nrOfBlocks];

    // get all blocks
    for (unsigned int i = 0; i < nrOfBlocks; i++)
    {
      pArray[i] = partition->GetBlock();
    }

    // delete all blocks
    for (unsigned int i = nrOfBlocks - 1; i > 0; i--)
    {
      partition->RetBlock(pArray[i]);
    }

    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Execption within test case");
  }
}

void
IndexPartitionTest::CheckBlockSize()
{
  const unsigned int blocksize  = 4;
  const unsigned int nrOfBlocks = 10;

  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);

    auto result = partition->GetBlockSize();
    QVERIFY2(blocksize == result, "Blocksize not equal");

    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Execption within test case");
  }
}

void
IndexPartitionTest::CheckZeroNrOfBlocks()
{
  const unsigned int blocksize  = 4;
  const unsigned int nrOfBlocks = 0;

  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);
    void* block;

    block = partition->GetBlock();
    partition->RetBlock(block);

    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Execption within test case");
  }
}

void
IndexPartitionTest::CheckZeroBlockSize()
{
  const unsigned int blocksize  = 0;
  const unsigned int nrOfBlocks = 10;

  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);
    void* pArray[nrOfBlocks];

    // get all blocks
    for (unsigned int i = 0; i < nrOfBlocks; i++)
    {
      pArray[i] = partition->GetBlock();
    }

    // delete all blocks
    for (unsigned int i = 0; i < nrOfBlocks; i++)
    {
      partition->RetBlock(pArray[i]);
    }

    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Execption within test case");
  }
}

void
IndexPartitionTest::CheckUnevenBlocksize()
{
  const unsigned int blocksize  = 3;
  const unsigned int nrOfBlocks = 10;

  WriteTestImplementation(blocksize, nrOfBlocks);
}

void
IndexPartitionTest::CheckMaxBLockSize()
{
  const unsigned int blocksize  = std::numeric_limits<unsigned int>::max();
  const unsigned int nrOfBlocks = 2;

  WriteTestImplementation(blocksize, nrOfBlocks);
}

void
IndexPartitionTest::CheckBlockSizeHighLimit()
{
  const unsigned int blocksize  = std::numeric_limits<unsigned int>::max() / 4;
  const unsigned int nrOfBlocks = 2;

  WriteTestImplementation(blocksize, nrOfBlocks);
}

void
IndexPartitionTest::CheckNrOfBlocksHighLimit()
{
  const unsigned int blocksize  = 4;
  const unsigned int nrOfBlocks = std::numeric_limits<unsigned int>::max() / 4;

  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);
    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Creation execption");
  }
}

void
IndexPartitionTest::CheckNrOfBlocksHighValue()
{
  const unsigned int blocksize  = 4;
  const unsigned int nrOfBlocks = 60000;

  WriteTestImplementation(blocksize, nrOfBlocks);
}

void
IndexPartitionTest::CheckBlocksizeHighValue()
{
  const unsigned int blocksize  = std::numeric_limits<unsigned int>::max() / 64;
  const unsigned int nrOfBlocks = 8;

  WriteTestImplementation(blocksize, nrOfBlocks);
}

void
IndexPartitionTest::CheckDeleteBlocks()
{
  const unsigned int blocksize  = 4;
  const unsigned int nrOfBlocks = 12;

  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);
    void* pArray[nrOfBlocks];

    // get all blocks
    for (unsigned int i = 0; i < nrOfBlocks; i++)
    {
      pArray[i] = partition->GetBlock();
    }

    // delete all blocks
    for (unsigned int i = 0; i < nrOfBlocks; i++)
    {
      partition->RetBlock(pArray[i]);
    }

    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Execption within test case");
  }
}

void
IndexPartitionTest::CreationTestImplementation(
    const unsigned int blocksize, const unsigned int nrOfBlocks)
{
  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);
    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Exeption during test execution");
  }
}

void
IndexPartitionTest::CheckWriteBlocks()
{
  const unsigned int blocksize  = 8;
  const unsigned int nrOfBlocks = 10;

  WriteTestImplementation(blocksize, nrOfBlocks);
}

void
IndexPartitionTest::WriteTestImplementation(
    const unsigned int blocksize, const unsigned int nrOfBlocks)
{
  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);
    void** pArray         = new void*[nrOfBlocks];

    // get all blocks
    for (unsigned int i = 0; i < nrOfBlocks; i++)
    {
      pArray[i] = partition->GetBlock();

      if (nullptr != pArray[i])
      {
        *((unsigned int*)pArray[i]) = (unsigned int)i;
      }
    }

    // check values
    for (unsigned int i = 0; i < nrOfBlocks; i++)
    {
      // write values to the memory
      if (nullptr != pArray[i])
      {
        QVERIFY2(*((unsigned int*)pArray[i]) == i, "Values are not equal");
      }
    }

    // try to allocate more blocks
    void* fault = partition->GetBlock();

    if (nullptr != fault)
    {
      QFAIL("Nullpointer not received");
    }

    delete[] pArray;
    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Execption within test case");
  }
}

IndexPartitionTest::IndexPartitionTest()
{
}

void
IndexPartitionTest::initTestCase()
{
}

void
IndexPartitionTest::cleanupTestCase()
{
}

void
IndexPartitionTest::Creation()
{
  unsigned int blocksize  = 4;
  unsigned int nrOfBlocks = 10;
  CreationTestImplementation(blocksize, nrOfBlocks);

  blocksize  = 8;
  nrOfBlocks = 10;
  CreationTestImplementation(blocksize, nrOfBlocks);

  blocksize  = 100;
  nrOfBlocks = 20;
  CreationTestImplementation(blocksize, nrOfBlocks);
}

void
IndexPartitionTest::CheckMaxBlocks()
{
  const unsigned int blocksize  = sizeof(unsigned int);
  const unsigned int nrOfBlocks = 10;

  try
  {
    IPartition* partition = new IndexPartition(blocksize, nrOfBlocks);
    void* pArray[nrOfBlocks];

    // get all blocks
    for (unsigned int i = 0; i < nrOfBlocks; i++)
    {
      pArray[i]                                = partition->GetBlock();
      *(static_cast<unsigned int*>(pArray[i])) = 0;
    }

    // try to allocate more blocks
    void* fault = partition->GetBlock();

    if (nullptr != fault)
    {
      QFAIL("Nullpointer not received");
    }

    delete partition;
  }
  catch (const std::exception&)
  {
    QFAIL("Execption within test case");
  }
}

QTEST_APPLESS_MAIN(IndexPartitionTest)

#include "tst_indexpartitiontest.moc"
