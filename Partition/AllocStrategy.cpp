///////////////////////////////////////////////////////////////////////////////////////////////////
//  AllocStrategy.cpp
//  Implementation of the Class AllocStrategy
//  Created on:      24-Sep-2017 14:20:04
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "AllocStrategy.h"

AllocStrategy::AllocStrategy()
{
}

AllocStrategy::~AllocStrategy()
{
}

void
AllocStrategy::RetBlock(void* addr)
{
  (void)addr;
}

void
AllocStrategy::setContext(IPartition* partition, unsigned int nrOfPartitions)
{
  (void)partition;
  (void)nrOfPartitions;
}
