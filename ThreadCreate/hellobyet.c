#include<stdio.h>
#include<pthread.h>
void * hellothread(void *arg)
{
  printf("Hello\n");
}
void * byethread(void *arg)
{
  printf("Bye\n");
}

int main()
{
 pthread_t hid, bid;
 pthread_create(&hid,NULL,hellothread,NULL);
 pthread_create(&bid,NULL,byethread,NULL);
 pthread_join(hid,NULL);
 pthread_join(bid,NULL);
 return 0;
}

