/*To write a C program to enter a list of processes, their CPU burst times, arrival times
and display/print the Gantt chart for Shortest Job First(SJFs)*/
#include <stdio.h>
struct process{ 
  int pid,done,at,bt,ct,tat,wt,st;
} p[100],temp;
void sjf(struct process a[100],int n)
{ 
  int i,j,flag,time=0,z=0;
  float avgtat=0,avgwt=0;
  for (i=0;i<n-1;i++)
    for (j=0;j<n-i-1;j++)
      if (a[j].bt>a[j+1].bt)
        {
          temp=a[j];
          a[j]=a[j + 1];
          a[j+1]=temp;
        }
  printf("\nGantt Chart\n");
  for(i=0;i<n;)
  { 
    flag=0;
    for(j=0;j<n;j++)
    { 
     if(a[j].at<=time && a[j].done==0)
      {   
        if(z!=0)
         {
           printf("%d - %d -> NULL\n",time-z,time);
           z=0;
         }
        a[j].st=time;
        time+=a[j].bt;
        a[j].ct=time;
        a[j].tat=a[j].ct-a[j].at;
        a[j].wt=a[j].tat-a[j].bt;
        avgtat+=a[j].tat;
        avgwt+=a[j].wt;
        a[j].done=1;
        flag=1;
        i++;
        printf("%d - %d -> P%d\n",a[j].st,a[j].ct,a[j].pid);
      }
    }
    if(flag==0)
    {
     z++;
     time++;
    } 
  }
  avgtat/=n;
  avgwt/=n;
  for (i=0;i<n-1;i++)
    for (j=0;j<n-i-1;j++)
      if (a[j].pid>a[j+1].pid)
       {
         temp=a[j];
         a[j]=a[j + 1];
         a[j+1]=temp;
       }   
  printf("+-----+--------------+------------+-----------------+-----------------+--------------+\n");
  printf("| PID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
  printf("+-----+--------------+------------+-----------------+-----------------+--------------+\n");   
  for(i=0;i<n;i++)
  {
   printf("%6d        %2d             %2d           %2d              %2d               %2d\n",a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
  }

  printf("\nAvg TAT : %f", avgtat);
  printf("\nAvg WT  : %f\n", avgwt);
}
int main()
{
    int n,i;
    printf("Enter the no. of Proceses : ");
    scanf("%d",&n);
    printf("Enter the Arrival Time and Burst Time : \n");
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        p[i].done=0;
        printf("Process %d\n", p[i].pid);
        printf("Arrival Time : ");
        scanf("%d",&p[i].at);
        printf("Burst Time : ");
        scanf("%d",&p[i].bt);
    }
    sjf(p,n);
    return 0;
}