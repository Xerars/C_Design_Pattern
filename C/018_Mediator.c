// Mediator

typedef struct _Mediator
{
  People* man;
  People* woman;
} Mediator;

typedef struct _People
{
  Mediator* pMediator;

  void (*request)(struct _People* pPeople);
  void (*process)(struct _People* pPeople);
} People;

void man_request(struct _People* pPeople)
{
  assert(pPeople!=NULL);
  pPeople->pMediator->woman->process(pPeople->pMediator->woman);

}

void woman_request(struct _People* pPeople)
{
  assert(pPeople!=NULL);
  pPeople->pMediator->woman->process(pPeople->pMediator->man);
}