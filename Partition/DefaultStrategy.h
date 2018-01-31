///////////////////////////////////////////////////////////
//  DefaultStrategy.h
//  Implementation of the Class DefaultStrategy
//  Created on:      24-Sep-2017 14:20:04
//  Original author: Vitalij
///////////////////////////////////////////////////////////

#if !defined(DEFAULTSTRATEGY_H)
#define DEFAULTSTRATEGY_H

#include "AllocStrategy.h"

class DefaultStrategy : public AllocStrategy
{

public:
  DefaultStrategy();
  virtual ~DefaultStrategy();

  virtual void* GetBlock(unsigned int size);
};
#endif // !defined(DEFAULTSTRATEGY_H)
