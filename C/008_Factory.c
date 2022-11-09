// Factory

#include <stdio.h>

#define LEATHER_TYPE  0X01
#define RUBBER_TYPE   0x02

typedef struct _Shoe
{
  int type;
  void (*print_shoe)(struct _Shoe*);
} Shoe;

void print_leather_shoe(struct _Shoe* pShoe)
{
  assert(pShoe!=NULL);
  printf("This is a Leather Shoe!\n");
}

void print_rubber_shoe(struct _Shoe* pShoe)
{
  assert(pShoe!=NULL);
  printf("This is a Rubber Shoe!\n");
}

Shoe* manufacture_new_shoe(int type)
{
  assert(LEATHER_TYPE == type || RUBBER_TYPE == type);

  Shoe* pShoe=(Shoe*)malloc(sizeof(Shoe));
  assert(pShoe!=NULL);

  memset(pShoe,0,sizeof(Shoe));

  if(type==LEATHER_TYPE)
  {
    pShoe->type=LEATHER_TYPE;
    pShoe->print_shoe=print_leather_shoe;
  }
  else
  {
    pShoe->type=RUBBER_TYPE;
    pShoe->print_shoe=print_leather_shoe;
  }

  return pShoe;
}