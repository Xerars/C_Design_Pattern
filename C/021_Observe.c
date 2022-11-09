// Observe

typedef struct _Object
{
  observer* pObserverList[MAX_BINDING_NUMBER];
  int number;

  void (*notify)(struct _Object* pObject);
  void (*add_observer)(observer* pObserver);
  void (*del_observer)(observer* pObserver);
} Object;

typedef struct _Observe
{
  Object* pObject;
  void (*update)(struct _Observer* pObserver);
} Observer;


void bind_observer_to_object(Observer* pObserver,Object* pObject)
{
  assert(pObserver!=NULL && pObject!=NULL);
  pObserver->pObject=pObject;
  pObject->add_observer(pObserver);
}

void unbind_observer_to_object(Observer* pObserver,Object* pObject)
{
  assert(pObserver!=NULL && pObject!=NULL);
  pObject->del_observer(observer* pObserver);
  memset(pObserver,0,sizeof(Observer));
}