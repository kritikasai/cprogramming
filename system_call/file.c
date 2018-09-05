#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
int main()
{
  int fd,res;
  fd=open("ofile.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR| S_IXUSR);
  if(-1==fd)
  {
   perror("error in opening");
   }
  else
  {
  res=write(fd,"Hello wWorld",14);
      if(res==-1)
      {
      perror("Error in write");
      }
      else
      {
      printf("File contains %d bytes\n",res);
      }
  close(fd);
  }
  return 0;
}
