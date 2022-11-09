// Prototype

/**
The prototype mode is essentially a copy of the current data. 
Like a conjuration, one pigeon becomes two pigeons, 
two pigeons become three pigeons, and so on. 
In the process of change, we do not need to consider the specific data type. 
why? Because different data has its own copy type, 
and each copy function is a virtual function.
**/

#include <stdio.h>

typedef struct _DATA
{
  struct _DATA* (*copy)(struct _pDATA* pData);
} DATA;


struct _DATA* data_copy_A(struct _DATA *pData)
{
  DATA* pResult=(DATA*)malloc(sizeof(DATA));
  assert(pResult!=NULL);
  memmove(pResult,pData,sizeof(DATA));
  return pResult;
}


DATA data_A={data_copy_A};


struct _DATA* clone(struct _DATA* pData)
{
  return pData->copy(pData);
}