// Interator

#include <stdio.h>

typedef struct _Container
{
  int *pData;
  int size;
  int length;

  Interator* (*create_new_interator)(struct _Container* pContainer);
  int (*get_first)(struct _Container* pContainer);
  int (*get_last)(struct _Container* pContainer);
} Container;



typedef struct _Interator
{
  void* pVector;
  int index;

  int (*get_first)(struct _Interator* pInterator);
  int (*get_last)(struct _Interator* pInterator);
} Interator;

int vector_get_first(struct _Container* pContainer)
{
  assert(pContainer!=NULL);
  return pContainer->pData[0];
}

int vector_get_last(struct _Container* pContainer)
{
  assert(pContainer!=NULL);
  return pContainer->pData[pContainer->size-1];
}

int vector_interator_get_first(struct _Interator* pInterator)
{
  Container* pContainer;
  assert(pInterator!=NULL && pInterator->pVector!=NULL);
  pContainer=(struct _Container*)(pInterator->pVector);
  return pContainer->get_first(pContainer);
}

int vector_interator_get_last(struct _Interator* pInterator)
{
  Container* pContainer;
  assert(pInterator!=NULL && pInterator->pVector!=NULL);
  pContainer=(struct _Container*)(pInterator->pVector);
  return pContainer->get_last(pContainer);
}