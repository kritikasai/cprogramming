#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  printf("Process PID : %d\n ", getpid());
  printf("Parent PID : %d\n",getppid());
  return 0;
}
