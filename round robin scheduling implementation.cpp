// round robin scheduling implementation.

#include<iostream>
using namespace std;
void find_waiting_time(int processess[],int n,int bt[],int wt[],int quantam)
{
	int rem_bt[n];
	for(int i=0;i<n;i++)
	{
		rem_bt[i]=bt[i];
	}
	int t=0;
	while(1)
	{
		bool done=true;
		for(int i=0;i<n;i++)
		{
			if(rem_bt[i]>quantam)
			{
				t+=quantam;
				rem_bt[i]-=quantam;
			}
			else
			{
				t=t+rem_bt[i];
				wt[i]=t-bt[i];
				rem_bt[i]=0;
			}
		}
		if(done==true)
		break;
	}
}
void find_turn_around_time(int processess[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}
void find_avg_time(int processess[],int n,int bt[],int quantam)
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	find_waiting_time(processess,n,bt,wt,quantam);
	find_turn_around_time(processess,n,bt,wt,tat);
	cout<<"processess"<<"burst time"<<"waiting time"<<"turn around time\n";
	for(int i=0;i<n;i++)
	{
		total_wt+=wt[i];
		total_tat+=tat[i];
		cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	cout<<"average waiting time="<<(float)total_wt/(float)n;
	cout<<"average turn around time="<<(float)total_tat/(float)n;
	}
	int main()
	{
		int processess[]={1,2,3};
		int n=sizeof processess/sizeof processess[0];
		int burst_time[]={10,5,8};
		int quantam=2;
		find_avg_time(processess,n,burst_time,quantam);
		return 0;
	}
