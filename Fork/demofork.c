#include <unistd.h>
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{fork();
printf("Before fork:%d\n",getpid());

printf("After fork:%d\n",getpid());
  return 0;
}

/*batch1@cdac-Vostro-460:~/dac/cprogramming/Fork$ gcc -c demofork.c
batch1@cdac-Vostro-460:~/dac/cprogramming/Fork$ gcc -o demofork demofork.o
batch1@cdac-Vostro-460:~/dac/cprogramming/Fork$ ./demofork
Before fork:2957
After fork:2957
After fork:2958
*/

/*
batch1@cdac-Vostro-460:~/dac/cprogramming/Fork$ gcc -c demofork.c
batch1@cdac-Vostro-460:~/dac/cprogramming/Fork$ gcc -o demofork demofork.o
batch1@cdac-Vostro-460:~/dac/cprogramming/Fork$ ./demofork
Before fork:2979
After fork:2979
Before fork:2980
After fork:2980
*/
