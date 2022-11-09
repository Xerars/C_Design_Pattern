// Singleton

/**
The trick with the singleton pattern is that 
the class constructor is a private function. 
But the constructor of the class must be created? 
How to do it? Then only use static function. 
We see that the constructor is called in static, 
it's that simple.
**/

#include <stdio.h>

typedef struct _DATA
{
  void* pData;
} DATA;

void* GetData(void)
{
  static DATA* pData=NULL;

  if(pData!=NULL)
    return pData;

  pData=(DATA*)malloc(sizeof(DATA));

  assert(pData!=NULL);
  return (void*)pData;
}