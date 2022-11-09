// Explain

#define DIGITAL_TYPE    1
#define LETTER_TYPE     2
#define BOTTOM_TYPE     3

typedef struct _Interpret
{
  int type;
  void* (*process)(void *pData,int* type,int* result);
} Interpret;


void* digital_process(void* pData,int* type,int* result)
{
  char* str;
  assert(pData!=NULL && type!=NULL && result!=NULL);

  str=(char*)pData;

  while(*str>'0' && *str<='9')
    str++;

  if(*str=='0')
  {
    *result=TRUE;
    return NULL;
  }

  if(*str=='_')
  {
    *result=TRUE;
    *type=BOTTOM_TYPE;
    return str;
  }

  if(*str>='a' && *str<='z' ||*str>='A' && *str<='Z')
  {
    *result=TRUE;
    *type=LETTER_TYPE;
    return str;
  }

  *result=FALSE;
  return NULL;
}


void* digital_process(void* pData,int* type,int* result)
{
  char* str;
  assert(pData!=NULL && type!=NULL && result!=NULL);

  str=(char*)pData;

  while(*str>'0' && *str<='9')
    str++;

  if(*str=='\0')
  {
    *result=TRUE;
    return NULL;
  }

  if(*str=='_')
  {
    *result=TRUE;
    *type=BOTTOM_TYPE;
    return str;
  }

  if(*str>='a' && *str<='z' ||*str>='A' && *str<='Z')
  {
    *result=TRUE;
    *type=LETTER_TYPE;
    return str;
  }

  *result=FALSE;
  return NULL;
}



void* letter_process(void* pData,int* type,int* result)
{
  char* str;
  assert(pData!=NULL && type!=NULL && result!=NULL);

  str=(char*)pData;

  while(*str>'0' && *str<='9')
    str++;

  if(*str=='\0')
  {
    *result=TRUE;
    return NULL;
  }

  if(*str=='_')
  {
    *result=TRUE;
    *type=BOTTOM_TYPE;
    return str;
  }

  if(*str>='0' && *str<='9')
  {
    *result=TRUE;
    *type=DIGITAL_TYPE;
    return str;
  }

  *result=FALSE;
  return NULL;
}

void* bottom_process(void* pData,int* type,int* result)
{
  char* str;
  assert(pData!=NULL && type!=NULL && result!=NULL);

  str=(char*)pData;

  while(*str>'0' && *str<='9')
    str++;

  if(*str=='\0')
  {
    *result=TRUE;
    return NULL;
  }

  if(*str=='_')
  {
    *result=TRUE;
    *type=BOTTOM_TYPE;
    return str;
  }

  if(*str>='a' && *str<='z' ||*str>='A' && *str<='Z')
  {
    *result=TRUE;
    *type=LETTER_TYPE;
    return str;
  }

  if(*str>='0' && *str<='9')
  {
    *result=TRUE;
    *type=DIGITAL_TYPE;
    return str;
  }

  *result=FALSE;
  return NULL;
}