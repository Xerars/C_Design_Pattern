// Abstract Factory

#include <stdio.h>

#define WHITE   1
#define RED     2

typedef struct _Apple
{
  void (*print_apple)(void);
} Apple;

typedef struct _Grape
{
  void (*print_grape)(void);
} Grape;


void print_white_apple(void)
{
  printf("White Apple\n");
}

void print_red_apple(void)
{
  printf("Red Apple\n");
}

void print_white_grape(void)
{
  printf("White Grape\n");
}

void print_red_grape(void)
{
  printf("Red Grape\n");
}

typedef struct _FruitShop
{
  Apple* (*sell_apple)(void);
  Apple* (*sell_grape)(void);
} FruitShop;

Apple* sell_white_apple(void)
{
  Apple* pApple=(Apple*)malloc(sizeof(Apple));
  assert(pApple!=NULL);

  pApple->print_apple=print_white_apple;
  return pApple;
}


Grape* sell_white_grape(void)
{
  Grape* pGrape=(Apple*)malloc(sizeof(Grape));
  assert(pGrape!=NULL);

  pGrape->print_grape=print_white_grape;
  return pGrape;
}

Apple* sell_red_apple(void)
{
  Apple* pApple=(Apple*)malloc(sizeof(Apple));
  assert(pApple!=NULL);

  pApple->print_apple=print_red_apple;
  return pApple;
}


Grape* sell_red_grape(void)
{
  Grape* pGrape=(Apple*)malloc(sizeof(Grape));
  assert(pGrape!=NULL);

  pGrape->print_grape=print_red_grape;
  return pGrape;
}



FruitShop* create_fruit_shop(int color)
{
  FruitShop* pFruitShop=(FruitShop*)malloc(sizeof(FruitShop));
  assert(pFruitShop!=NULL);

  if(color==WHITE)
  {
    pFruitShop->sell_apple=sell_white_apple;
    pFruitShop->sell_grape=sell_white_grape;
  }
  else
  {
    pFruitShop->sell_apple=sell_red_apple;
    pFruitShop->sell_grape=sell_red_grape;
  }
  return pFruitShop;
}
