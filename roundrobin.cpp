#include<stdio.h>
int main()
{
	
	int i,j,n,t,max,wt[10],bu[10],tat[10],ct[10];
	float awt=0,att=0,temp=0;
	printf("enter no.of processes:");
	scanf("%d",&n);
	printf("Enter burst time for processes: \n");
	for(i=0;i<n;i++){
		printf("P%d: ",i+1);
		scanf("%d",&bu[i]);
		ct[i]=bu[i];
	}
	printf("Enter size of timeslice: ");
	scanf("%d",&t);
	max=bu[0];
	for(i=1;i<n;i++)
	{
		if(max<bu[i])
		  max=bu[i];
	}
	for(j=0;j<(max/t)+1;j++)
	for(i=0;i<n;i++)
		if(bu[i]<=t)
		{
			tat[i]=temp+bu[i];
			temp=temp+bu[i];
			bu[i]=0;
		}
		else{
			bu[i]=bu[i]-t;
			temp=temp+t;
		}
	for(i=0;i<n;i++){
		wt[i]=tat[i]-ct[i];
		att+=tat[i];
		awt+=wt[i];
	}
	printf("\n Average waiting time is: %f",att/n);
	printf("\n Average waiting time is: %f",awt/n);
	printf("\nProcess\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\n",i+1,ct[i],wt[i],tat[i]);
	}
}
