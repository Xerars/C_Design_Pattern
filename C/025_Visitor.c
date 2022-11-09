// Visitor

typedef struct _Tofu
{
  int type;
  void (*eat)(struct _Visitor* pVisitor,struct _Tofu* pTofu);
} Tofu;

typedef struct _Visit
{
  int region;
  void (*process)(struct _Tofu* pTofu,struct _Visitor* pVisitor);
} Visitor;

void eat(struct _Visitor* pVisitor,struct _Tofu *pTofu)
{
  assert(pVisitor!=NULL && pTofu!=NULL);
  pVisitor->process(pTofu,pVisitor);

}

void process(struct _Tofu* pTofu,struct _Visitor* pVisitor)
{
  assert(pVisitor!=NULL && pTofu!=NULL);
  if(pTofu->type==SPICY_FOOD && pVisitor->region==WEST || 
     pTofu->type==STRONG_SMELL_FOOD && pVisitor->region==EAST)
  {
    printf("I Like this Food!\n");
    return;
  }
  printf("I Hate this Food\n");
}