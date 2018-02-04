///////////////////////////////////////////////////////////////////////////////////////////////////
//  PartitionDecorator.cpp
//  Implementation of the Class PartitionDecorator
//  Created on:      14-Okt-2017 20:31:55
//  Original author: Vitalij
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "PartitionDecorator.h"

PartitionDecorator::~PartitionDecorator()
{
}

PartitionDecorator::PartitionDecorator(IPartition* partition) : pPartition(partition)
{
}
