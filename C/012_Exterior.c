// Exterior

#include <stdio.h>
typedef struct _FoodSteet
{
  void (*eat)(void);
} FoodStreet;


void eat(void)
{
  printf("Eat Here!\n");
}

typedef struct _ShopSteet
{
  void (*buy)(void);
} ShopStreet;


void buy(void)
{
  printf("Buy Here!\n");
}

typedef struct _BookStreet
{
  void (*read)(void);
} BookStreet;

void read(void)
{
  printf("Read Here!\n");
}

typedef struct _Plaza
{
  FoodStreet* pFoodStreet;
  ShopStreet* pShopStreet;
  BookStreet* pBookSteeet;
  void (*play)(struct _Plaza* pPlaza);
} Plaza;

void play(struct _Plaza* pPlaza)
{
  assert(pPlaza!=NULL);

  pPlaza->pFoodStreet->eat();
  pPlaza->pShopStreet->buy();
  pPlaza->pBookSteeet->read();
}