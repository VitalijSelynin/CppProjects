///////////////////////////////////////////////////////////
//  MutexLockPartition.cpp
//  Implementation of the Class MutexLockPartition
//  Created on:      14-Okt-2017 20:31:57
//  Original author: Vitalij
///////////////////////////////////////////////////////////

#include "MutexLockPartition.h"

MutexLockPartition::MutexLockPartition(IPartition* partition)
    : PartitionDecorator(partition)
{
}

MutexLockPartition::~MutexLockPartition()
{
}

void*
MutexLockPartition::GetBlock()
{
  std::lock_guard<std::mutex> guard(mutex);
  return pPartition->GetBlock();
}

unsigned int
MutexLockPartition::GetBlockSize()
{
  return pPartition->GetBlockSize();
}

void
MutexLockPartition::RetBlock(void* p)
{
  std::lock_guard<std::mutex> guard(mutex);
  return pPartition->RetBlock(p);
}
