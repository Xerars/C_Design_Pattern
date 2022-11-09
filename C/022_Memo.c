// Memo

typedef struct _Action
{
  int type;
  struct _Action* next;

  void* pData;
  void (*process)(void* pData);
} Action;

typedef restore(struct _Organizer* pOrganizer)
{
  Action* pHead;
  assert(pOrganizer!=NULL);

  pHead=pOrganizer->pActionHead;
  pHead->process(pHead->pData);
  pOrganizer->pActionHead=pHead->next;
  pOrganizer->numver--;
  free(pHead);
  return;
}