///////////////////////////////////////////////////////////
//  AllocStrategy.h
//  Implementation of the Class AllocStrategy
//  Created on:      24-Sep-2017 14:20:04
//  Original author: Vitalij
///////////////////////////////////////////////////////////

#if !defined(ALLOCSTRATEGY_H)
#define ALLOCSTRATEGY_H

#include "IAllocStrategy.h"
#include "IPartition.h"

class AllocStrategy : public IAllocStrategy
{

public:
  AllocStrategy();
  virtual ~AllocStrategy();

  virtual void* GetBlock(unsigned int size) = 0;
  virtual void  RetBlock(void* addr);
  virtual void  setContext(IPartition* partition, unsigned int nrOfPartitions);

protected:
  unsigned int nrOfPartitions;
  IPartition*  partition;
};
#endif // !defined(ALLOCSTRATEGY_H)
