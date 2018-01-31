///////////////////////////////////////////////////////////
//  IndexPartition.h
//  Implementation of the Class IndexPartition
//  Created on:      24-Sep-2017 14:19:59
//  Original author: Vitalij
///////////////////////////////////////////////////////////

#if !defined(INDEXPARTITION_H)
#define INDEXPARTITION_H

#include "IPartition.h"

class IndexPartition : public IPartition
{

private:
  const unsigned int blocksize;
  const unsigned int nrOfBlocks;
  unsigned int       firstIndex;
  unsigned int*      memstart;
  unsigned int       endSymbol;
  unsigned int       unitsPerBlock;

public:
  IndexPartition(const unsigned int blocksize, const unsigned int nrOfBlocks);
  virtual ~IndexPartition();

  virtual void*        GetBlock();
  virtual unsigned int GetBlockSize();
  virtual void         RetBlock(void* p);
};
#endif // !defined(INDEXPARTITION_H)
