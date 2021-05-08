// priority scheduling implementation.

#include<iostream>
using namespace std;
struct process
{
	int pid;
	int bt;
	int priority;
};
bool comparison(process a,process b)
{
	return (a.priority>b.priority);
}
void find_waiting_time(process proc[],int n,int wt[])
{
	wt[0]=0;
	for(int i=0;i<n;i++)
	{
		wt[i]=proc[i-1].bt+wt[i-1];
	}
}
void find_turn_around_time(process proc[],int n,int wt[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=proc[i].bt+wt[i];
	}
}
void find_avg_time(process proc[],int n)
{
	int wt[n],tat[n],total_wt=0,total_tat=0;
	find_waiting_time(proc,n,wt);
	find_turn_around_time(proc,n,wt,tat);
	cout<<"\process"<<"burst time"<<"waiting time"<<"turn around time\n";
	for(int i=0;i<n;i++)
	{
		total_wt+=wt[i];
		total_tat+=tat[i];
		cout<<" "<<proc[i].bt<<"\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	cout<<"average waiting time="<<(float)total_wt/(float)n;
	cout<<"average turn around time="<<(float)total_tat/(float)n;
}
void priority_scheduling(process proc[],int n)
{
	sort(proc,proc+n,comparison);
	cout<<"order in which process gets executed";
	for(int i=0;i<n;i++)
	cout<<proc[i].pid<<" ";
	find_avg_time(proc,n);
}
int main()
{
	process proc[]={(1,2,3),(2,4,8),(2,5,1)};
	int n=sizeof proc/sizeof proc[0];
	priority_scheduling(proc,n);
	return 0;
}
