///////////////////////////////////////////////////////////////////////////////////////////////////
//  DefaultStrategy.cpp
//  Implementation of the Class DefaultStrategy
//  Created on:      24-Sep-2017 14:20:04
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "DefaultStrategy.h"

DefaultStrategy::DefaultStrategy()
{
}

DefaultStrategy::~DefaultStrategy()
{
}

void*
DefaultStrategy::GetBlock(unsigned int size)
{
  (void)size;
  return nullptr;
}
