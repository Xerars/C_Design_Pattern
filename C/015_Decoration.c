// Decoration

typedef struct _Object
{
  struct _Object* prev;
  void (*decorate)(struct _Object* pObject);
} Object;

void decorate(struct _Object* pObject)
{
  assert(pObject!=NULL);

  if(pObject->prev!=NULL)
    pObject->prev->decorate(pObject->prev);

  printf("Normal Decorate!\n");
}