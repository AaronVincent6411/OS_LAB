#include<iostream>

using namespace std;

class process
 {
   public:
    int pid;
    float at,bt,ct,pr,tat,wt;
 }p,t;

void priority()
 {
   process p[10];
   int n,i,j;
   float avgtat=0.0,avgwt=0.0;
   cout<<"Enter the no of process"<<endl;
   cin>>n;
   cout<<"Start entering the arrival time, priority and burst time"<<endl;
   for(i=0;i<n;i++)
    {
      cout<<"Process:"<<i+1<<endl;
      p[i].pid=i+1;
      cout<<"Arrival Time:";
      cin>>p[i].at;
      cout<<"Burst Time:";
      cin>>p[i].bt;
      cout<<"Priority:";
      cin>>p[i].pr;
    }
   for(i=0;i<n;i++)
    for(j=0;j<n-1;j++)
     if(p[j].at>p[j+1].at)
      {
        t=p[j];
        p[j]=p[j+1];
        p[j+1]=t;
      }
   p[0].ct=p[0].bt;
   for(i=0;i<n-1;i++)
    for(j=1;j<n-1;j++)
     if(p[j].pr>p[j+1].pr)
      {
        t=p[j];
        p[j]=p[j+1];
        p[j+1]=t;
      }
   for(i=1;i<n;i++)
    p[i].ct=p[i-1].ct+p[i].bt;
   for(i=0;i<n;i++)
    {
      p[i].tat=p[i].ct-p[i].at;
      avgtat+=p[i].tat;
    }
   for(i=0;i<n;i++)
    {
      p[i].wt=p[i].tat-p[i].bt;
      avgwt+=p[i].wt;
    }
   cout<<"Process\t\tAT\t\tBT\t\tPR\t\tCT\t\tTAT\t\tWT"<<endl;
   for(i=0;i<n;i++)
    cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].pr<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wt<<endl;
   cout<<"Average TAT="<<avgtat/n<<endl;
   cout<<"Average WT="<<avgwt/n<<endl;
 }

int main()
 {
   priority();
   return(0);
 }
