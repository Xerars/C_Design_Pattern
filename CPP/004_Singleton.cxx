// Singleton

#include <string.h>
#include <assert.h>

class object
{
public:
  static class object* pObject;

  static object* create_new_object(void)
  {
    if(pObject!=NULL)
      return pObject;

    pObject=new object();
    assert(pObject!=NULL);
    return pObject;
  }


private:
  object();     //Constructor
  ~object();    //DeConstructor
};

class object* object::pObject=NULL;


//Main Code
int main(void)
{
  object* pGlobal=object::create_new_object();
  return 1;
}