///////////////////////////////////////////////////////////
//  IPartition.h
//  Implementation of the Interface IPartition
//  Created on:      24-Sep-2017 14:20:02
//  Original author: Vitalij
///////////////////////////////////////////////////////////

#if !defined(IPARTITION_H)
#define IPARTITION_H

class IPartition
{

public:
  IPartition() {}

  virtual ~IPartition() {}

  virtual void*        GetBlock()        = 0;
  virtual unsigned int GetBlockSize()    = 0;
  virtual void         RetBlock(void* p) = 0;
};
#endif // !defined(IPARTITION_H)
