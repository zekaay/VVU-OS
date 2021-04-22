#include <iostream>
#include <cstdio>
#include <conio.h>

using namespace std;

//Firstfit
void firstfit(){
int frag[25],b[25],f[25],i,j,nb,nf,temp,highest=0;
static int bf[25],ff[25];

cout<<"Memory Management Scheme - First Fit"<<endl;
cout<<"Enter the number of blocks:"<<endl;
cin>>nb;
cout<<"Enter the number of files:"<<endl;
cin>>nf;
cout<<"Enter the size of the blocks:"<<endl;
for(i=1;i<=nb;i++)
{
cout<<"Block"<<i<<":";
cin>>b[i];
}
cout<<"Enter the size of the files :"<<endl;
for(i=1;i<=nf;i++)
{
cout<<"File"<<i<<":";
cin>>f[i];
}
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
 {
if(bf[j]!=1)

 {
temp=b[j]-f[i];
 if(temp>=0)
if(highest<temp)
 {
 ff[i]=j;
highest=temp;
 }
 }
 }
 frag[i]=highest;
 bf[ff[i]]=1;
 highest=0;
}
cout<<"\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement"<<endl;
for(i=1;i<=nf;i++){

cout<<"\n"<<i<<"\t\t"<<f[i]<<"\t\t"<<ff[i]<<"\t\t"<<b[ff[i]]<<"\t\t"<<frag[i];

}
}


//Bestfit
void bestfit(){

int frag[25],b[25],f[25],i,j,nb,nf,temp=0,lowest=10000;
static int bf[25],ff[25];
cout<<"Memory Management Scheme - Best Fit"<<endl;
cout<<"Enter the number of blocks:"<<endl;
cin>>nb;
cout<<"Enter the number of files:"<<endl;
cin>>nf;
cout<<"Enter the size of the blocks:"<<endl;

for(i=1;i<=nb;i++){
cout<<"Block"<<i<<":";
cin>>b[i];
}

cout<<"Enter the size of the files :"<<endl;
for(i=1;i<=nf;i++)
{
cout<<"File"<<i<<":";
cin>>f[i];
}

for(i=1;i<=nf;i++)
{
 for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i];
if(temp>=0){

if(lowest>temp)
{
ff[i]=j;
lowest=temp;
}
}
}
}

 frag[i]=lowest;
 bf[ff[i]]=1;
 lowest=10000;
}

cout<<"\nFile No\tFile Size \tBlock No\tBlock Size\tFragment"<<endl;
for(i=1;i<=nf && ff[i]!=0;i++){
cout<<"\n"<<i<<"\t\t"<<f[i]<<"\t\t"<<ff[i]<<"\t\t"<<b[ff[i]]<<"\t\t"<<frag[i];
}
}

//Worst Fit
void worstfit()
{



int frag[25],b[25],f[25],i,j,nb,nf,temp;
static int bf[25],ff[25];
cout<<"Memory Management Scheme - Worst Fit"<<endl;
cout<<"Memory Management Scheme - First Fit"<<endl;
cout<<"Enter the number of blocks:"<<endl;
cin>>nb;
cout<<"Enter the number of files:"<<endl;
cin>>nf;
cout<<"Enter the size of the blocks:"<<endl;
for(i=1;i<=nb;i++)
{
cout<<"Block"<<i<<":";
cin>>b[i];
}
cout<<"Enter the size of the files :-"<<endl;
for(i=1;i<=nf;i++)
{
cout<<"File"<<i<<":";
cin>>f[i];
}
for(i=1;i<=nf;i++)
{
 for(j=1;j<=nb;j++)
 {
if(bf[j]!=1)
 {
temp=b[j]-f[i];
if(temp>=0)
 {
ff[i]=j;
break;
 }
 }
 }

 frag[i]=temp;
bf[ff[i]]=1;
}
cout<<"\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement"<<endl;
for(i=1;i<=nf;i++){

cout<<"\n"<< i<<"\t\t"<< f[i]<<"\t\t"<< ff[i]<<"\t\t"<< b[ff[i]]<<"\t\t"<< frag[i];
}

}

//Paging Technique
void paging()
{
		int ms, ps, nop, np, rempages, i, j, x, y, pa, offset;
	int s[10], fno[10][20];
cout<<"Paging Technique"<<endl;
	cout << "\nEnter the memory size -- ";
	cin >> ms;

	cout << "\nEnter the page size -- ";
	cin >> ps;

	nop = ms/ps;
	cout << "\nThe no. of pages available in memory are -- " << nop;
	cout << "\nEnter number of processes -- ";
	cin >> np;

	rempages = nop;
	for(i = 1; i <= np; i++)
	{
		cout << "\nEnter no. of pages required for p[" << i << "]-- ";
		cin >> s[i];

		if(s[i] > rempages)
		{
			cout << "\nMemory is Full";
			break;
		}

		rempages = rempages - s[i];

		cout << "\nEnter pagetable for p[" << i << "]-- ";
		for(j = 0; j < s[i]; j++)
			cin >> fno[i][j];
	}

	cout <<"\nEnter Logical Address to find Physical Address ";
	cout <<"\nEnter process no. and pagenumber and offset -- ";
	cin >> x >> y >> offset;

	if(x > np || y >= s[i] || offset >= ps)
		cout << "\nInvalid Process or Page Number or offset";
	else
	{
		pa = fno[x][y] * ps + offset;
		cout << "\nThe Physical Address is -- " << pa;
	}

}

//FirstCome FirstServe (FCFS)
void FCFS()
{
		int burst[20], wait[20], trntime[20], i, num_pro;
	float waitavg, trntimeavg;
	int pro[20], k, temp;

	cout << "\n\t\t\t------First Come First Serve (FCFS)------\n";
	cout << "\nEnter the number of processes -- ";
	cin >> num_pro;

	for(i = 0; i < num_pro; i++)
	{
		cout << "\nEnter Burst Time for Process " << i << "-- ";
		cin >> burst[i];
	}

	wait[0] = waitavg = 0;
	trntime[0] = trntimeavg = burst[0];

	for(i = 1; i < num_pro; i++)
	{
		wait[i] = wait[i-1] +burst[i-1];
		trntime[i] = trntime[i-1] +burst[i];
		waitavg = waitavg + wait[i];
		trntimeavg = trntimeavg + trntime[i];
	}
	cout << "\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n";

	for(i = 0; i < num_pro; i++)
	cout << "\n\t P" << i << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << trntime[i] << endl;
	cout << "\nAverage Waiting Time -- " << waitavg << endl;
	cout << "\nAverage Turnaround Time -- " << trntimeavg << endl;
}

//SJF
void SJF()
{
	int burst[20], wait[20], trntime[20], i, num_pro;
	float waitavg, trntimeavg;
	int pro[20], k, temp;

	cout << "\n\t\t\t------Shortest Job First(SJF)------\n";
	cout << "\nEnter the number of processes -- ";
	cin >> num_pro;

	for(i = 0; i < num_pro; i++)
	{
		pro[i] = i;
		cout << "Enter the burst time for process " << i << "-- ";
		cin >> burst[i];
	}

	for(i = 0; i < num_pro; i++)
		for(k = i + 1; k < num_pro; k++)
			if(burst[i] > burst[k])
			{
				temp = burst[i];
				burst[i] = burst[k];
				burst[k] = temp;

				temp = pro[i];
				pro[i] = pro[k];
				pro[k] = temp;
			}

	wait[0] = waitavg = 0;
	trntime[0] = trntimeavg = burst[0];
	for(i = 1; i < num_pro; i++)
	{
		wait[i] = wait[i-1] + burst[i-1];
		trntime[i] = trntime[i-1] + burst[i];
		waitavg = waitavg + wait[i];
		trntimeavg = trntimeavg + trntime[i];
	}

	cout << "\n\tPROCESS \tBURST TIME \tWAITING TIME \tTURNAROUND TIME\n";
	for (i = 0; i < num_pro; i++)
		cout << "\n\t\tP" << pro[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << trntime[i];

	cout << "\nAverage Waiting Time --" << waitavg << endl;
	cout << "\nAverage Turnaround Time --" << trntime << endl;

}

//Round Robin
void roundrobin()
{
		int i, j, num_pro, burst_t[10], wait_t[10], trnarndt[10], time, ct[10], max;
	float awt = 0, att = 0, temp = 0;

	cout << "\n\t\t\t------Round Robin CPU Scheduling Algorithm------\n" << endl;
	cout << "Enter the number of processes -- ";
	cin >> num_pro;

	for (i = 0; i < num_pro; i++)
	{
		cout << "\nEnter burst time for process " << i+1 << " -- ";
		cin >> burst_t[i];
		ct[i] = burst_t[i];
	}

	cout << "\nEnter the size of time slice -- ";
	cin >> time;

	max = burst_t[0];

	for (i = 1; i < num_pro; i++)
		for (i = 1; i < num_pro; i++)
			if (max < burst_t[i])
				max = burst_t[i];

	for (j = 0; j < (max/time) + 1; j++)
		for (i = 0; i < num_pro; i++)
			if (burst_t[i] != 0)
				if (burst_t[i] <= time)
				{
					trnarndt[i] = temp + burst_t[i];
					temp = temp + burst_t[i];
					burst_t[i] = 0;
				}

				else
				{
					burst_t[i] = burst_t[i] - time;
					temp = temp + time;
				}

	for (i = 0; i < num_pro; i++)
	{
		wait_t[i] = trnarndt[i] - ct[i];
		att += trnarndt[i];
		awt += wait_t[i];
	}

	cout << "\nThe Average Turnaround time is -- " << att << endl;
	cout << "The Average Waiting time is -- " << awt << endl;
	cout << "\n\tPROCESS \tBURST TIME \tWAITING TIME \tTURNAROUND TIME\n";

	for (i = 0; i < num_pro; i++)
		cout << "\t" << i + 1 << "\t\t" << ct[i] << "\t\t" << wait_t[i] << "\t\t" << trnarndt[i] << "\n";

}

//Priority
void priority()
{
	int burst[20], wait[20], trntime[20], i, num_pro;
	float waitavg, trntimeavg;
	int pro[20], k, temp, prior[20];

	cout << "\n\t\t\t------Priority CPU Scheduling Algorithm------\n" << endl;
	cout << "Enter the number of processes --- ";
	cin >> num_pro;

	for (i = 0; i < num_pro; i++)
	{
		pro[i] = i;
		cout << "Enter the Burst Time & Priority of Process " << i << " --- ";
		cin >> burst[i] >> prior[i];
	}

	for (i = 0; i < num_pro; i++)
		for (k = 0; k < num_pro; k++)
			if (prior[i] > prior[k])
			{
				temp = pro[i];
				pro[i] = pro[k];
				pro[k] = temp;

				temp = burst[i];
				burst[i] = burst[k];
				prior[k] = temp;
			}

	waitavg = wait[0] = 0;
	trntimeavg = trntime[0] = burst[0];

	for (i = 0; i < num_pro; i++)
	{
		wait[i] = wait[i - 1] + burst[i - 1];
		trntime[i] = trntime[i - 1] + burst[i - 1];

		waitavg = waitavg + wait[i];
		trntimeavg = trntimeavg + trntime[i];
	}

	cout << "\nPROCESS \t\tPRIORITY \tBURST TIME \tWAITING TIME \tTURNAROUND TIME";
	for (i = 0; i < num_pro; i++)
	{
		cout  << "\n" << pro[i] << "\t\t\t" << prior[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" << trntime[i];
	}

	cout << "\nAverage Wait Time is --- " << waitavg << endl;
	cout << "Average Turnaround Time is --- " << trntimeavg;

	}

//Multi-level Queue Scheduling Algorithm
void multilevel()
{
	int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
float wtavg, tatavg;

cout<<"Enter the number of processes --- "<<endl;
cin>>n;
for(i=0;i<n;i++)
{
p[i] = i;
cout<<"Enter the Burst Time of Process  --- "<<i<<endl;
cin>>bt[i];
cout<<"System/User Process (0/1) ? --- "<<endl;
cin>>su[i];
}

for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(su[i] > su[k])
{
temp=p[i];
p[i]=p[k];
p[k]=temp;
temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=su[i];
su[i]=su[k];
su[k]=temp;
}
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
cout<<"\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME"<<endl;
for(i=0;i<n;i++)
cout<<"\n"<<p[i]<<"\t\t"<<su[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i];
cout<<"\nAverage Waiting Time is --- "<<wtavg/n<<endl;
cout<<"\nAverage Turnaround Time is --- "<<tatavg/n<<endl;

}



int main()
{
    int ma,bs,ef,nob,nop,mp[10],tif=0;
    int i,p=0;
    int choice;
    int temp,n=0;
    char ch ='y';

    /**Allowing the user to choose the type of memory technique he or she wants to use***/

    cout<<"Please choose the type of memory management technique you would like to use"<<endl;

    cout<<"1.Multiprogramming with a fixed number of tasks\t\t\t"<<endl;
    cout<<"2.Multiprogramming with a variable number of tasks\t\t\t"<<endl;
	cout<<"3.FirstFit Method\t\t\t"<<endl;
	cout<<"4.BestFit Method\t\t\t"<<endl;
	cout<<"5.WorstFit Method\t\t\t"<<endl;
	cout<<"6.Paging Technique Of Memory Management\t\t\t"<<endl;
	cout<<"7.FCFS(FirstComeFirstServe) CPU SCHEDULING ALGORITHM\t\t\t"<<endl;
	cout<<"8.SJF(ShortestJobFirst) CPU SCHEDULING ALGORITHM\t\t\t"<<endl;
	cout<<"9.ROUND ROBIN CPU SCHEDULING ALGORITHM\t\t\t"<<endl;
	cout<<"10.PRIORITY CPU SCHEDULING ALGORITHM\t\t\t"<<endl;
	cout<<"11.Multi-level Queue Scheduling Algorithm\t\t\t"<<endl;


    cout<<"\nChoose the Memory Management Technique: ";
    cin>>choice;


    /**Displaying and accepting input from the user with regards to the memory available,
    the block size***/

    if (choice==1)
        {
        cout<<"Enter the memory available(In Bytes): ";
        cin>> ma;

        cout<<"Enter the block size(In Bytes): ";
        cin>>bs;


        /**** Processing Equations****/

        nob=ma/bs;
        ef = ma -nob*bs;

        cout<<"Enter the number of processes (In Bytes): ";
        cin>>nop;

        /***A loop to determine the number of processes that can be in a block of memory****/

        for (i=0; i<nop; i++)
           {
             cout<<"Enter memory required to be processed " <<i+1<<endl;
             cin>>mp[i];
           }

           cout<<"\nNumber of blocks available in memory "<<nob;


        /***Displaying a table that shows the process,memory required,memory allocated and the fragmentation.***/

           cout<<"\nProcess\tMemory Required\t Allocated\tInternal Fragmentation";
           for(i=0; i<nop && p<nob; i++)
            {
               cout<< "\n" << i+1 << "\t\t" << mp[i];
                if(mp[i] > bs){
                    cout<<"\t\tNO\t\t---";
            }
                    else
                {
                      cout<<"\t\tYES\t\t " << bs-mp[i];
                       tif = tif + bs-mp[i];
                        p++;
                    }
                }

           if(i<nop)
            {
                    cout<<"\n\nMemory is Full, Remaining Processes cannot be accommodated" <<endl;
                    cout<<"\n\nTotal Internal Fragmentation is " << tif;
                    cout<<"\nTotal External Fragmentation is " << ef;
           }
        }

            else

                /***** Choice 2 displays the MVT management technique*****/

       if (choice==2){

           cout<<"Enter the total memory available"<<endl;
           cin>>ma;
           temp=ma;
           for(i=0;ch=='y';i++,n++)
            {
              cout<<("\nEnter memory for required process")<<endl;
              cin>>mp[i];
              if (mp[i]<= temp)
                {
                  cout<<"\nMemory allocated for process " <<i+1<<endl;
                temp=temp-mp[i];
              }
              else{

               cout<<"Memory is full"<<endl;
               break;

              }


                cout<<"\nDo you want to continue(y/n)"<<endl;
                cin>>ch;
            }

                cout<<"Total memory available---" <<ma<<endl;

               cout<<"\n\n\tPROCESS\t\t MEMORY ALLOCATED "<<endl;
               for(i=0; i<n;i++){
                     cout<<"\n\t"<<i+1<<"\t\t\t"<<mp[i]<<endl;
               }
                cout<<"\n\nTotal Memory Allocated is " <<ma-temp<<endl;
                cout<<"\nTotal External Fragmentation is " <<temp<<endl;

       }
       if (choice ==3){
       	firstfit();
	   }

	    if (choice==4){
	    	bestfit();
		}

		if (choice==5){
			worstfit();
		}

		if (choice==6){
			paging();
		}

		if (choice==7){
			FCFS();
		}

		if (choice==8){
			SJF();
		}

		if (choice==9){
			roundrobin();
		}

		if (choice==10){
			priority();
		}

		if (choice==11){
			multilevel();
		}

    return 0;
        }
