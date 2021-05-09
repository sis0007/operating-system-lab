#include<iostream>
using namespace std;

void findWaitingTime(int processes[],int n,int bt[],int wt[],int at[],int ct[])
{

	wt[0]=0;
	
	for(int i=0;i<n;i++)
	{	
		wt[i]=ct[i]-bt[i]-at[i];
		
	}
}

void findTurnAroundTime(int processes[],int n,int bt[],int wt[],int tat[],int at[],int ct[])
{
	tat[0]=21;
	for(int i=1;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		
		
	}
}


void findAverageTime(int processes[],int n,int bt[],int at[])
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	
	int ct[4];
	ct[0]=bt[0];
	
	for(int i=1;i<4;i++)
	{	
		ct[i]=bt[i]+ct[i-1];
	}
	
	findWaitingTime(processes,n,bt,wt,at,ct);
	
	findTurnAroundTime(processes,n,bt,wt,tat,at,ct);
	
	cout<<"processes "<<"Burst time "<<" waiting time "<<" turn around time"<<"\n";
	
	for(int i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		cout<<"\t"<<i+1<<"      "<<bt[i]<<"       "<<wt[i]<<"        "<<tat[i]<<"\n";
			
	}
	
	
	cout<<"average waiting time "<<total_wt/4.0<<" \n";
	cout<<"average turn around time "<<total_tat/4.0;
}

int main()
{
	int processes[]={1,2,3,4};
	int n=sizeof processes/sizeof processes[0];
	
	int burst_time[]={19,23,2,6};
	int arrivalTime[]={2,3,1,6};
	
	findAverageTime(processes,n,burst_time,arrivalTime);
	
	return 0;
	
}

