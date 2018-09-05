#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
pid_t id;
printf("Before fork:%d %d\n",getpid(),getppid());
id=fork();
if(0==id)
   printf("child process %d %d %d\n",getpid(),getppid(),id);
else
  printf("parent process\n");
  
return 0;
}

/*
batch1@cdac-Vostro-460:~/dac/cprogramming/fork2$ gcc -c demofork2.c
batch1@cdac-Vostro-460:~/dac/cprogramming/fork2$ gcc -o demofork2 demofork2.o
batch1@cdac-Vostro-460:~/dac/cprogramming/fork2$ ./demofork2
Before fork:3298 2816
parent process
child process 3299 3298 0
*/
