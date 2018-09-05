#include<stdio.h>
#include <unistd.h>

int main()
{
  pid_t id;
  printf("before fork.. %d %d\n",getpid(),getppid());
  id=fork();
  if(0==id)
  {
    
    printf("Child process.. %d %d %d\n",getpid(),getppid(),id);
  }
  else
  {
  printf("before sleep..\n");
  sleep(8);
  printf("Parent Process.. %d %d %d\n",getpid(),getppid(),id);
  }
  return 0;
}

/*
batch1@cdac-Vostro-460:~/dac/cprogramming/zombieProcess$ gcc zombiedemo.c -o zombiedemo && ./zombiedemo
before fork.. 5237 4705
Parent Process.. 5237 4705 5238
before sleep..
batch1@cdac-Vostro-460:~/dac/cprogramming/zombieProcess$ Child process.. 5238 1300

*/

/*batch1@cdac-Vostro-460:~/dac/cprogramming/zombieProcess$ gcc zombiedemo.c -o zombiedemo && ./zombiedemo
before fork.. 5260 4705
before sleep..
Child process.. 5261 5260 0
Parent Process.. 5260 4705 5261
*/
