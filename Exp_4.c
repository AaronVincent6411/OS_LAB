//C programs for IO system calls of Linux OS(open,read,write).
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
 system("cls"); 
 int fd;
 char buf[14];
 fd = open("myfile.txt",O_CREAT | O_WRONLY);
 if( fd == -1)
 {
  printf("\n couldn't create file and open the file");
  exit(0);
 }
 write(fd,"Hello World!\n",13);
 close(fd);
 fd = open("myfile.txt",O_RDONLY);
 if( fd == -1)
 {
  printf("\n couldn't open file and read the file");
  exit(1);
 }
 read(fd,buf, 13);
 //buf[13]='\0';
 close(fd);
 printf("%s\n",buf);
 return 0;
}