#include<iostream>

using namespace std;

class process
 {
   public:
     float at,bt,ct,tat,wt;
 }p[10],t;

void fcfs()
 {
    process p[10];
    int n,i;
    float avgtat=0.0,avgwt=0.0;
    cout<<"Enter the number of process"<<endl;
    cin>> n;
    cout<<"Start entering the arrival and burst time"  <<endl;
    for(i=0;i<n;i++)
     {
       cout<<"Process:"<<i+1<<endl;
       cout<<"Arrival Time:";
       cin>>p[i].at;
       cout<<endl;
       cout<<"Burst Time:";
       cin>>p[i].bt;
       cout<<endl;
     }
    for(i=0;i<n;i++)
     {
       for(int j=0;j<n-1;j++)
        {
          if(p[j].at>p[j+1].at)
           {
             t=p[j];
             p[j]=p[j+1];
             p[j+1]=t;
           }
        }
     }
    cout<<"Process\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT"<<endl;
    p[0].ct=p[0].bt;
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
    for(i=0;i<n;i++)
     cout<<i+1<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].ct<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wt<<endl;
    cout<<"Average TAT="<<avgtat/n<<endl;
    cout<<"Average WT="<<avgwt/n<<endl;
 }

int main()
 {
   fcfs();
   return(0);
 }
