///////////////////////////////////////////////////////////////////////////////////////////////////
//  IndexPartition.cpp
//  Implementation of the Class IndexPartition
//  Created on:      24-Sep-2017 14:19:59
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "IndexPartition.h"
#include <limits>
#include <stdlib.h>

IndexPartition::IndexPartition(const unsigned int blocksize, const unsigned int nrOfBlocks)
    : blocksize(blocksize)
    , nrOfBlocks(nrOfBlocks)
    , firstIndex(0)
    , memstart(nullptr)
    , endSymbol(std::numeric_limits<unsigned int>::max())
    , unitsPerBlock(0)
{
  const unsigned int maxValue = std::numeric_limits<unsigned int>::max() / sizeof(unsigned int);

  if ((0 != blocksize) && (maxValue >= blocksize))
  {
    if ((0 != nrOfBlocks) && (maxValue >= nrOfBlocks))
    {
      const unsigned int offset = 1; // TODO: Why is an offset necessary?
      unitsPerBlock =
          ((unsigned int)blocksize + sizeof(unsigned int) - offset) / sizeof(unsigned int);

      unsigned int num = unitsPerBlock * sizeof(unsigned int);
      memstart         = static_cast<unsigned int*>(calloc(num, nrOfBlocks));

      if (nullptr != memstart)
      {
        unsigned int index = 0;
        for (unsigned int i = 0; i < nrOfBlocks - 1; ++i, index += unitsPerBlock)
        {
          memstart[index] = index + unitsPerBlock;
        }

        memstart[index] = endSymbol;
      }
    }
  }
}

IndexPartition::~IndexPartition()
{
  free(memstart);
}

void*
IndexPartition::GetBlock()
{
  void* returnValue = nullptr;

  if ((endSymbol != firstIndex) && (nullptr != memstart))
  {
    returnValue = &memstart[firstIndex];
    firstIndex  = memstart[firstIndex];
  }

  return returnValue;
}

unsigned int
IndexPartition::GetBlockSize()
{
  return blocksize;
}

void
IndexPartition::RetBlock(void* p)
{
  // TODO: Alignment of p must be checked
  if ((p >= memstart) && (p < memstart + (unitsPerBlock * nrOfBlocks)))
  {
    if (nullptr != p)
    {
      unsigned int* pBlock = static_cast<unsigned int*>(p);
      *pBlock              = firstIndex;
      firstIndex           = pBlock - memstart;
    }
  }
}
