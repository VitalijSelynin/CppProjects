///////////////////////////////////////////////////////////////////////////////////////////////////
//  PartitionDecorator.h
//  Implementation of the Class PartitionDecorator
//  Created on:      14-Okt-2017 20:31:55
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(PARTITIONDECORATOR_H)
#define PARTITIONDECORATOR_H

#include "IPartition.h"

class PartitionDecorator : public IPartition
{

public:
  virtual ~PartitionDecorator();

protected:
  IPartition* pPartition;

  PartitionDecorator(IPartition* partition);
};
#endif // !defined(PARTITIONDECORATOR_H)
