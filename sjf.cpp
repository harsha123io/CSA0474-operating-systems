#include<stdio.h>
int main()
{
	int pid[10],bt[10];
	int n;
	printf("Enter number of proceses : ");
	scanf("%d",&n);
	printf("Enter the Processes : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);
	}
	printf("Enter the burst times : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(bt[j]>bt[j+1])
			{
				int tempbt=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=tempbt;
				int temppid=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temppid;
			}
		}
	}
	int wt[n];
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
	int tat[n];
	for(int i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
	}
	printf("ProcessId   burstTime   Wiating Time   turn around time\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t",pid[i]);
		printf("%d\t\t",bt[i]);
		printf("%d\t\t",wt[i]);
		printf("%d\t\t",tat[i]);
		printf("\n");
	}
	float twt;
	for(int i=0;i<n;i++)
	{
		twt+=wt[i];
	}
	float ttat;
	for(int i=0;i<n;i++)
	{
		ttat+=tat[i];
	}
	float awt,atat;
	awt=twt/n;
	atat=ttat/n;
	printf("avg waiting time =%f\n",awt);
	printf("Avg Turn around time =%f",atat);
	return 0;
}