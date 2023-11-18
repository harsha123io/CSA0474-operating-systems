#include<stdio.h>
int main()
{
	int pid[10];
	int bt[10];
	int n;
	printf("Enter number of processes : ");
	scanf("%d",&n);
	printf("Enter the processes : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);
	}
	printf("Enter the busrt times : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	int wt[n],i;
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
	int tat[n];
	for(i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
	}
	printf("ProcessID  BurstTime  WaitingTime  TurnAroundTime\n");
	float twt=0.0,ttat=0.0;
	for(i=0;i<n;i++)
	{
		printf("%d\t\t",pid[i]);
		printf("%d\t\t",bt[i]);
		printf("%d\t\t",wt[i]);
		printf("%d\t\t",tat[i]);
		printf("\n");
		twt+=wt[i];
		ttat+=tat[i];
	}
	float awt,atat;
	awt=twt/n;
	atat=ttat/n;
	printf("Average Waiting Time = %f\n",awt);
	printf("Average Turn Arround Time=%f\n",atat);
	return 0;
}