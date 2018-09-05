#include <unistd.h>
#include<stdio.h>
int main()
{
printf("Before exec() \n");

//to load new binary file, the rest will not be executed after exec()
execl("/bin/ls","/bin/ls","-a","-l",NULL);
printf("After exec()");
return 0;
}

/*
batch1@cdac-Vostro-460:~/dac/cprogramming/exec$ gcc execdemo.c -o execdemo && ./execdemo
Before exec() 
total 24
drwxrwxr-x  2 batch1 batch1 4096 Sep  5 08:38 .
drwxrwxr-x 12 batch1 batch1 4096 Sep  5 08:29 ..
-rwxrwxr-x  1 batch1 batch1 8712 Sep  5 08:38 execdemo
-rw-rw-r--  1 batch1 batch1  229 Sep  5 08:38 execdemo.c
*/
