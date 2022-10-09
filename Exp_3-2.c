//PROGRAM FOR SYSTEM CALLS OF UNIX OPERATING SYSTEM(opendir,readdir,closedir).
#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/stat.h>
struct dirent *dptr;
int main(int argc, char *argv[])
{
 system("cls"); 
 char buff[100];
 struct stat stats;
 DIR *dirp;
 printf("\n\n ENTER DIRECTORY NAME");
 scanf("%s", buff);
 if((dirp=opendir(buff))==NULL||stat(buff, &stats))
 {
  printf("The given directory does not exist");
  exit(1);
 }
 while(dptr=readdir(dirp))
 {
  printf("%s\n",dptr->d_name);
 }
 closedir(dirp);
}