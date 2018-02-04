///////////////////////////////////////////////////////////////////////////////////////////////////
//  PartitionManager.cpp
//  Implementation of the Class PartitionManager
//  Created on:      24-Sep-2017 14:20:01
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "PartitionManager.h"

PartitionManager::PartitionManager()
{
}

PartitionManager::~PartitionManager()
{
}

void*
PartitionManager::GetBlock(unsigned int size)
{
  (void)size;
  return nullptr;
}

void
PartitionManager::RetBlock(void* addr)
{
  (void)addr;
}

void
PartitionManager::SetStrategy(IAllocStrategy* strategy)
{
  (void)strategy;
}
