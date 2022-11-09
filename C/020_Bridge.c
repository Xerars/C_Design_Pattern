// Bridge

#define MEAT_TYPE   1

typedef struct _MetaDumpling
{
  void (*make)(void);
} MetaDumpling;

typedef struct _NormalDumpling
{
  void (*make)(void);
} NormalDumpling;


typedef struct _DumplingRequest
{
  int type;
  void* pDumpling;
} DumplingRequest;

void buy_dumpling(DumplingRequest* pDumplingRequest)
{
  assert(pDumplingRequest!=NULL);
  if(MEAT_TYPE==pDumplingRequest->tpye)
    return (MetaDumpling*)(pDumplingRequest->pDumpling)->make();
  else
    return (NormalDumpling*)(pDumplingRequest->pDumpling)->make();
}