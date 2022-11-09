// Adapter

class voltage_12v
{
public:
  voltage_12v(){}
  virtual ~voltage_12v(){}
  virtual void request(){}
};


class v220_to_v12
{
public:
  v220_to_v12(){}
  ~v220_to_v12(){}
  void voltage_transform_process(){}
};

class adapter:public voltage_12v
{
  v220_to_v12* pAdaptee;

public:
  adapter(){}
  ~adapter(){}

  void request(void)
  {
    pAdaptee->voltage_transform_process();
  }
}