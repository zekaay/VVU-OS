#include <iostream>

using namespace std;

int main()
{
    //pronumb = number of processes
    //Waitime= waiting time
    //tat= turnaround time

    int Pronumb,i,j,bt[20],wt[20];
    int Burst[20],Waitime[20],tat[20],avgwt=0,avgtat=0;
    cout<<"Enter total number of processes:";
    cin>>Pronumb;

    //display and accept burst time
    cout<<"\nEnter Burst Time of the Process \n";
    for(i=0;i<Pronumb;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>Burst[i];
    }

       //1st process=0
    Waitime[0]=0;

    //Wait time
    for(i=1;i<Pronumb;i++)
    {
        Waitime[i]=0;
        for(j=0;j<i;j++)
            Waitime[i]+=bt[j];
    }

    cout<<"\nProcess\t\tBurst Time\tTurnaround Time\tWaiting Time";

    //Turnaround
    for(i=0;i<Pronumb;i++)
    {
        tat[i]=bt[i]+wt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<bt[i]<<"\t\t"<<Waitime[i]<<"\t\t"<<tat[i];
    }

    avgwt/=i;
    avgtat/=i;
    cout<<"\n\nAverage Waiting Time is:"<<avgwt;
    cout<<"\nAverage Turnaround Time is:"<<avgtat;

    return 0;
}
