#include<stdio.h>
#include<pthread.h>
void * crthread(void *arg)
{
  printf("Thread created..\n");
}

int main()
{
 pthread_t tid;
 pthread_create(&tid,NULL,crthread,NULL);
 pthread_join(tid,NULL);
 return 0;
}


/*batch1@cdac-Vostro-460:~/dac/cprogramming/ThreadCreate$ gcc -c crthread.cbatch1@cdac-Vostro-460:~/dac/cprogramming/ThreadCreate$ gcc -o crthread crthread.o -lpthread
batch1@cdac-Vostro-460:~/dac/cprogramming/ThreadCreate$ ./crthread
Thread created..
*/
