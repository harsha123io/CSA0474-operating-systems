#include<stdio.h>
int main()
{
	int pid[10];
	int bt[10];
	int pr[10];
	int n;
	printf("Enter number of process : ");
	scanf("%d",&n);
	printf("Enter the processes : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pid[i]);
	}
	printf("Enter the burst time : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	printf("Enter the prorities : ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pr[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(pr[j]>pr[j+1])
			{
				int tempbt=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=tempbt;
				
				int temppid=pid[j];
				pid[j]=pid[j+1];
				pid[j+1]=temppid;
				
				int temppr=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temppr;
			}
		}
	}
	int wt[n];
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
	}
	int tat[n];
	for(int i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
	}
	printf("Process Id   burst time   prority   waiting time   turn around time\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t",pid[i]);
		printf("%d\t\t",bt[i]);
		printf("%d\t\t",pr[i]); 0002  
		printf("%d\t\t",wt[i]);
		printf("%d\t\t",tat[i]);
		printf("\n");
	}
	int twt=0,ttat=0;
	for(int i=0;i<n;i++)
	{
		twt+=wt[i];
		ttat+=tat[i];
	}
	float awt,atat;
	awt=twt/n;
	atat=ttat/n;
	printf("Average waiting time =%f\n",awt);
	printf("Average turn around time =%f",atat);
	return 0;
} 