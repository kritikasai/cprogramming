#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int count=0;
sem_t countsem;
 
void *incthread(void *arg)
{
  while(1)
  {
   sem_wait(&countsem);
   count++;
   printf("Inc: %d\n",count);
   sem_post(&countsem);
  }
}
void *decthread(void *arg)
{
  while(1)
  {
   sem_wait(&countsem);
   count--;
   printf("Dec: %d\n",count);
   sem_post(&countsem);
  }
}

int main()
{
 pthread_t incid, decid;
 sem_init(&countsem, 0,1);
 pthread_create(&incid,NULL,incthread,NULL);
 pthread_create(&decid,NULL,decthread,NULL);
 pthread_join(incid,NULL);
 pthread_join(decid,NULL);
 sem_destroy(&countsem);
 return 0;
}

