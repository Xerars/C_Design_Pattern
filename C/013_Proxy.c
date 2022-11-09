// Proxy

#include <stdio.h>

typedef struct _PC_Client
{
  void (*request)(void);
} PC_Client;


void ftp_request(void)
{
  printf("request from ftp!\n");
}

void http_request(void)
{
  printf("request from http!\n");
}

void smtp_request(void)
{
  printf("request from smtp!\n");
}


typedef struct _Proxy
{
  PC_Client* pClient;
} Proxy;

void process(Proxy* pProxy)
{
  assert(pProxy!=NULL);
  pProxy->pClient->request();
}