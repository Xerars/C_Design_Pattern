// Template
#include <iostream>
#include <cstdlib>

using namespace std;


template <typename type>
int compare(type a,type b)
{
  return a>b?1:0;
}

class basic
{
public:
  basic(){}
  virtual ~basic(){}
  virtual void step1(){}
  virtual void step2(){}

  void process()
  {
    step1();
    step2();
  }
};

class data_A:public basic
{
public:
  data_A(){}
  ~data_A(){}

  void step1()
  {
    printf("Step 1 in data_A\n");
  }

  void step1()
  {
    printf("Step 2 in data_A\n");
  }
};
