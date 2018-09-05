#include<stdio.h>
#include<pthread.h>

int count;
 
void *incthread(void *arg)
{
  while(1)
  {
   count++;
   printf("Inc: %d\n",count);
  }
}
void *decthread(void *arg)
{
  while(1)
  {
   count--;
   printf("Dec: %d\n",count);
  }
}

int main()
{
 pthread_t incid, decid;
 pthread_create(&incid,NULL,incthread,NULL);
 pthread_create(&decid,NULL,decthread,NULL);
 pthread_join(incid,NULL);
 pthread_join(decid,NULL);
 return 0;
}

