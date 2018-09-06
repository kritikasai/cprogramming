#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int a,b,sum;
sem_t semInput2Proc, semProc2Input;
 
void *inputThread(void *arg)
{
  while(1)
  {
   sem_wait(&semProc2Input);
   printf("\nEnter a & b :");
   scanf("%d %d",&a,&b);
   sem_post(&semInput2Proc);
  }
}
void *processingThread(void *arg)
{
  while(1)
  {
   sem_wait(&semInput2Proc);
   sum=a+b;
   printf("\nSum: %d",sum);
   sem_post(&semProc2Input);
  }
}

int main()
{
 pthread_t ipid, pid;
 sem_init(&semInput2Proc, 0,0);
 sem_init(&semProc2Input, 0,1);
 pthread_create(&ipid,NULL,inputThread,NULL);
 pthread_create(&pid,NULL,processingThread,NULL);
 pthread_join(ipid,NULL);
 pthread_join(pid,NULL);
 sem_destroy(&semInput2Proc);
 sem_destroy(&semProc2Input);
 return 0;
}

/*
batch1@cdac-Vostro-460:~/dac/cprogramming/Signaling_semaphor$ gcc -c sig_semaphore.c
batch1@cdac-Vostro-460:~/dac/cprogramming/Signaling_semaphor$ gcc -o sig_semaphore sig_semaphore.o -lpthread
batch1@cdac-Vostro-460:~/dac/cprogramming/Signaling_semaphor$ ./sig_semaphore

Enter a & b :2 3

Sum: 5
Enter a & b :

*/
