// Chain of Responsibility

#include <stdio.h>

typedef struct _Leader
{
  struct _Leader* next;
  int account;

  int (*request)(struct _Leader* pLeader,int num);
} Leader;

void set_account(struct _Leader* pLeader,int account)
{
  assert(pLeader!=NULL);
  pLeader->account=account;
  return;
}


void set_next_leader(struct _Leader* pLeader,struct _Leader* next)
{
  assert(pLeader!=NULL && next!=NULL);
  pLeader->next=next;
  return;
}

int request_for_manager(struct _Leader* pLeader,int num)
{
  assert(pLeader!=NULL && num!=0);

  if(num<10000)
    return 1;
  else if(pLeader->next)
    return pLeader->next->request(pLeader->next,num);
  else
    return 0;
}