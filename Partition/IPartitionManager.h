///////////////////////////////////////////////////////////////////////////////////////////////////
//  IPartitionManager.h
//  Implementation of the Interface IPartitionManager
//  Created on:      24-Sep-2017 14:20:02
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(IPARTITIONMANAGER_H)
#define IPARTITIONMANAGER_H

#include "IAllocStrategy.h"

class IPartitionManager
{

public:
  IPartitionManager()
  {
  }

  virtual ~IPartitionManager()
  {
  }

  virtual void* GetBlock(unsigned int size)          = 0;
  virtual void RetBlock(void* addr)                  = 0;
  virtual void SetStrategy(IAllocStrategy* strategy) = 0;
};
#endif // !defined(IPARTITIONMANAGER_H)
