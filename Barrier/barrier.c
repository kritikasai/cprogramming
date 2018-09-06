#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
pthread_barrier_t initBar;
 
void *netThread(void *arg)
{
  while(1)
  {
    printf("net started init..\n");
    sleep(1);
    printf("net initialized..\n");
    pthread_barrier_wait(&initBar);
    printf("net started executing..\n");
  }
}
void *guiThread(void *arg)
{
  while(1)
  {
    printf("gui started init..\n");
    sleep(2);
    printf("gui initialized..\n");
    pthread_barrier_wait(&initBar);
    printf("gui started executing..\n");
  }
}
void *fsThread(void *arg)
{
  while(1)
  {
    printf("file started init..\n");
    sleep(3);
    printf("file initialized..\n");
    pthread_barrier_wait(&initBar);
    printf("file started executing..\n");
  }
}

int main()
{
 pthread_t netid, guiid,fsid;
 pthread_barrier_init(&initBar,NULL,3);
 pthread_create(&netid,NULL,netThread,NULL);
 pthread_create(&guiid,NULL,guiThread,NULL);
 pthread_create(&fsid,NULL,fsThread,NULL);
 pthread_join(netid,NULL);
 pthread_join(guiid,NULL);
 pthread_join(fsid,NULL);
 pthread_barrier_destroy(&initBar);
 return 0;
}

//Without barrier

/*
batch1@cdac-Vostro-460:~/dac/cprogramming/Barrier$ ./barriernet started init..
gui started init..
file started init..
net initialized..
net started executing..
net started init..
gui initialized..
gui started executing..
gui started init..
net initialized..
net started executing..
net started init..
file initialized..
file started executing..
file started init..
net initialized..
net started executing..
net started init..
gui initialized..
gui started executing..
gui started init..
net initialized..
net started executing..
net started init..
^Z
*/

//with barrier

/*batch1@cdac-Vostro-460:~/dac/cprogramming/Barrier$ ./barrier
net started init..
gui started init..
file started init..
net initialized..
gui initialized..
file initialized..
file started executing..
file started init..
gui started executing..
gui started init..
net started executing..
net started init..
net initialized..
gui initialized..
file initialized..
file started executing..
file started init..
gui started executing..
gui started init..
net started executing..
net started init..
net initialized..
gui initialized..
file initialized..
file started executing..
file started init..
net started executing..
net started init..
gui started executing..
gui started init..
^Z
*/
