/*To write a C program to enter a list of processes, their CPU burst times, arrival times
and display/print the Gantt chart for Round Robin*/
#include <stdio.h>
struct process{ 
  int pid,done,vis,at,bt,ct,tat,wt,st,rt;
}p[100],temp;
int f=-1,r=-1,q[100],rq[100],m=0;
void add(int a)
{
  if(f==-1)
  f++;
  r++;
  q[r]=a;
}
int fetch()
{
  if(f==r)
  {
   int k=f;
   f=-1;
   r=-1;
   return q[k];
  }
 return q[f++];
}
void rr(struct process a[100],int n,int tq)
{ 
  int i,j,k,flag,pc=0,time=0,z=0,tot=0,time0;
  float avgtat=0,avgwt=0;
  for (i=0;i<n-1;i++)
    for (j=0;j<n-i-1;j++)
      if (a[j].at>a[j+1].at)
        {
          temp=a[j];
          a[j]=a[j + 1];
          a[j+1]=temp;
        }
  printf("\nGantt Chart\n");
  while(pc<n)
  {
    for(i=0;i<n;i++)
    {
     flag=0;
     if(r==-1 && a[i].at<=time && a[i].vis==0)
     {
      add(i);
      rq[m++]=a[i].pid;
      flag=1;
      a[i].vis=1;
     }
     else if(r!=-1)
     {
      k=fetch();
      if(z!=0)
      {
        printf("%d - %d -> NULL\n",time-z,time);
        z=0;
      } 
      if(a[k].rt<=tq && a[k].done==0)
      {
       time0=time;
       time+=a[k].rt;
       a[k].rt=0;
       pc++;
       a[k].done=1;
       a[k].ct=time;
       a[k].tat=a[k].ct-a[k].at;
       a[k].wt=a[k].tat-a[k].bt;
       avgtat+=a[k].tat;
       avgwt+=a[k].wt;
      }
      else if(a[k].rt>tq)
      {
       time0=time;
       time+=tq;
       a[k].rt-=tq;
      }
      printf("%d - %d -> P%d\n",time0,time,a[k].pid);
      for(j=i;j<n;j++)
       if(a[j].at<=time && a[j].vis==0)
       {
        add(j);
        rq[m++]=a[j].pid;
        a[j].vis=1;
       } 
      if(a[k].rt>0)
      {
        add(k);
       rq[m++]=a[k].pid;
      }
      flag=1;
     }
    if(flag==0)
    {
     z++;
     time++;
    }  
   }
 }
 printf("\nReady Queue\n"); 
 for(i=0;i<m;i++)
  {
    printf(" P%d ",rq[i]);
  }
  avgtat/=n;
  avgwt/=n;
    
  for(i=0;i<n-1;i++)
    for(j=0;j<n-i-1;j++)
      if(a[j].pid>a[j+1].pid)
       {
         temp=a[j];
         a[j]=a[j + 1];
         a[j+1]=temp;
       }
  printf("\n+-----+--------------+------------+-----------------+-----------------+--------------+\n");
  printf("| PID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |\n");
  printf("+-----+--------------+------------+-----------------+-----------------+--------------+\n");    
  for(i=0;i<n;i++)
  {
   printf("%6d        %2d            %2d            %2d               %2d             %2d\n",a[i].pid,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt);
  }
  printf("\nAvg TAT : %f", avgtat);
  printf("\nAvg WT  : %f\n", avgwt);
}     
int main()
{
    int n,i,tq;
    printf("Enter the no. of Processes : ");
    scanf("%d",&n);
    printf("Enter the Arrival Time and Burst Time : \n");
    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;
        p[i].done=0;
        p[i].vis=0;
        printf("Process %d\n", p[i].pid);
        printf("Arrival Time : ");
        scanf("%d",&p[i].at);
        printf("Burst Time : ");
        scanf("%d",&p[i].bt);
        p[i].rt=p[i].bt;
    }
    printf("Enter the Time Quantum : ");
    scanf("%d",&tq);
    rr(p,n,tq);
    return 0;
}
