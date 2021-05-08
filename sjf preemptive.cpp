#include<iostream>
using namespace std;
void find_turn_around_time(int process[],int n,int wt[],int bt[],int tat[])
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}
void find_waiting_time(int process[],int n,int tat[],int at[],int bt[],int wt[])
{
	int i,j;
	int rt[n];
	for(i=0;i<n;i++)
	{
		rt[i]=bt[i];
	}
	int complete_exe=0,t=0,minm=INT_MAX;
	int shortest=0,finish_time;
	bool check=false;
	while(complete_exe!=n)
	{
		for(j=0;j<n;j++)
		{
			if((process[j].at<=t)&&(rt[j]<minm)&&rt[j]>0)
			{
				minm=rt[j];
				shortest=j;
				check=true;
			}
		}
		if(check==false)
		{
			t++;
			continue;
		}
		rt[shortest]--;
		minm=rt[shortest];
		if(minm==0)
		minm=INT_MAX;
		if(rt[shortest]==0)
		{
			complete++;
			check=false;
			finish_time=t+1;
			wt[shortest]=finish_time-process[shortest].bt-process[shortest].at;
			if(wt[shortest]<0)
			wt[shortest]=0;
		}
		t++;
	}
}
void find_avg_time(int process[],int n)
{
	int i;
	int wt[n],tat[n],total_wt=0,total_tat=0;
	find_waiting_time(process[],n,wt[]);
	find_turn_around_time(process[],n,wt[],tat[]);
	cout<<"process"<<"burst time"<<"waiting time"<<"turn around time\n";\
	for(i=0;i<n;i++)
	{
		total_wt=total_wt+wt[i];
		total_tat=total_tat+tat[i];
		cout<<" "<<process[i].process<<"\t\t"<<wt[i]<<"\t\t"<<p[i].bt<<"\t\t"<<tat[i]<<endl;
	
	}
	cout<<"\n average waiting time="<<(float)total_wt/(float)n;
	cout<<"\n average turn around time="<<(float)total_tat/(float)n;
}
int main()
{
	int process[]={1,2,3,4};
	int n=sizeof process/sizeof process[0];
	int burst_time[]={10,5,8,6};
	find_avg_time(process,n,burst_time);
	return 0;
}
