#include<stdio.h>
#include<pthread.h>

int count=0;
pthread_mutex_t countMutex= PTHREAD_MUTEX_INITIALIZER;
 
void *incthread(void *arg)
{
  while(1)
  {
   pthread_mutex_lock(&countMutex);
   count++;
   printf("Inc: %d\n",count);
   pthread_mutex_unlock(&countMutex);
  }
}
void *decthread(void *arg)
{
  while(1)
  {
   pthread_mutex_lock(&countMutex);
   count--;
   printf("Dec: %d\n",count);
   pthread_mutex_unlock(&countMutex);
  }
}

int main()
{
 pthread_t incid, decid;
 pthread_create(&incid,NULL,incthread,NULL);
 pthread_create(&decid,NULL,decthread,NULL);
 pthread_join(incid,NULL);
 pthread_join(decid,NULL);
 pthread_mutex_destroy(&countMutex);
 return 0;
}

