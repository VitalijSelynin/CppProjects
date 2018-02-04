///////////////////////////////////////////////////////////////////////////////////////////////////
//  MutexLockPartition.h
//  Implementation of the Class MutexLockPartition
//  Created on:      14-Okt-2017 20:31:57
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(MUTEXLOCKPARTITION_H)
#define MUTEXLOCKPARTITION_H

#include "PartitionDecorator.h"
#include <mutex>

class MutexLockPartition : public PartitionDecorator
{

public:
  MutexLockPartition(IPartition* partition);
  virtual ~MutexLockPartition();

  virtual void* GetBlock();
  virtual unsigned int GetBlockSize();
  virtual void RetBlock(void* p);

private:
  std::mutex mutex;
};
#endif // !defined(MUTEXLOCKPARTITION_H)
