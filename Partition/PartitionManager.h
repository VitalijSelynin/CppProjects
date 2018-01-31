///////////////////////////////////////////////////////////
//  PartitionManager.h
//  Implementation of the Class PartitionManager
//  Created on:      24-Sep-2017 14:20:01
//  Original author: Vitalij
///////////////////////////////////////////////////////////

#if !defined(PARTITIONMANAGER_H)
#define PARTITIONMANAGER_H

#include "IAllocStrategy.h"
#include "IPartitionManager.h"

class PartitionManager : public IPartitionManager
{

public:
  PartitionManager();
  virtual ~PartitionManager();
  IAllocStrategy* m_IAllocStrategy;

  virtual void* GetBlock(unsigned int size);
  virtual void  RetBlock(void* addr);
  virtual void  SetStrategy(IAllocStrategy* strategy);
};
#endif // !defined(PARTITIONMANAGER_H)
