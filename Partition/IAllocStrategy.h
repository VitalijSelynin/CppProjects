///////////////////////////////////////////////////////////
//  IAllocStrategy.h
//  Implementation of the Interface IAllocStrategy
//  Created on:      24-Sep-2017 14:20:03
//  Original author: Vitalij
///////////////////////////////////////////////////////////

#if !defined(IALLOCSTRATEGY_H)
#define IALLOCSTRATEGY_H

#include "IPartition.h"

class IAllocStrategy
{

public:
  IAllocStrategy() {}

  virtual ~IAllocStrategy() {}

  virtual void* GetBlock(unsigned int size)                                    = 0;
  virtual void  RetBlock(void* addr)                                           = 0;
  virtual void  setContext(IPartition* partition, unsigned int nrOfPartitions) = 0;
};
#endif // !defined(IALLOCSTRATEGY_H)
