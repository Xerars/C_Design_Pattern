// Composite
#include <stdio.h>

typedef struct _NODE
{
  void *pData;
  struct _NODE* left;
  struct _NODE* right;
} NODE;


typedef struct _Object
{
  struct _Object** ppObject;
  int Number;
  void (*operate)(struct _Object* pObject);
} Object;


void operate_of_parent(struct _Object* pObject)
{
  int index;
  assert(pObject!=NULL);
  assert(pObject->ppObject && pObject->Number!=0);

  for(index=0;index<pObject->Number;index++)
    pObject->ppObject[index]->operate(pObject->ppObject[index]);
}

void operate_of_child(struct _Object* pObject)
{
  assert(pObject!=NULL);
  printf("Child Node!\n");
}

void process(struct _Object* pObject)
{
  assert(pObject!=NULL);
  pObject->operate(pObject);
}