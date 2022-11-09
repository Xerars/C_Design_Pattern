// Prototype

class data
{
public:
  data(){}
  virtual ~data(){}
  virtual class data* copy()=0;
};


class data_A:public data
{
public:
  data_A() {}
  ~data_A(){}

  class data* copy(void)
  {
    return new data_A();
  }
};


class data_B:public data
{
public:
  data_B() {}
  ~data_B(){}

  class data* copy(void)
  {
    return new data_B();
  }
};


//Use
class data* clone(class data* pData)
{
  return pData->copy();
}