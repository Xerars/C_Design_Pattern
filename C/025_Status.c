// Status

typedef struct _State
{
  void (*process)(void);
  struct _State* (*change_state)(void);
} State;

void normal_process(void)
{
  printf("Normal Process!\n");
}

struct _State* change_state()
{
  State* pNextState=NULL;

  pNextState=(struct _State*)malloc(sizeof(struct _State));
  assert(pNextState!=NULL);

  pNextState->process=next_process;
  pNextState->change_state=next_change_state;
  return pNextState;
}

typedef struct _Context
{
  State* pState;
  void (*change)(struct _Context* pContext);
} Context;

void context_change(struct _Context* pContext)
{
  State* pPre;
  assert(pContext!=NULL);

  pPre=pContext->pState;
  pContext->pState=pPre->change_state();
  free(pPre);
  return;
}