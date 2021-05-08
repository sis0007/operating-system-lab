#include<iostream>
using namespace std;
void find_waiting_time(int process[],int n,int bt[],int wt[])
{
	int i;
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
}
void find_turn_around_time(int process[],int n,int wt[],int bt[],int tat[])
{
	int i;
    for(i=0;i<=n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}	
}
void find_average_time(int process[],int n,int bt[])
{
	int i;
	int wt[n],tat[n],total_wt=0,total_tat=0;
	find_waiting_time(process,n,bt,wt);
	find_turn_around_time(process,n,bt,wt,tat);
	cout<<"process"<<"burst time"<<"waiting time"<<"turn around time\n";
	for(i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		cout<<" "<<i+1<<"\t\t"<<bt[i]<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	cout<<"average waiting time="<<(float)total_wt/(float)n;
	cout<<"average turn around time="<<(float)total_tat/(float)n;
}
int main()
{
	int process[]={1,2,3,4};
	int n=sizeof process/sizeof process[0];
	int burst_time[]={10,5,8,6};
	find_average_time(process,n,burst_time);
	return 0;
}
