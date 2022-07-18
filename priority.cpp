#include<stdio.h>
#define max 10
int main()
{
	int i,j,bt[max],n,p[max],wt[max],tat[max],pr[max],total=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter no.of processes: ");
	scanf("%d",&n);
	printf("Enter burst time and priority for process");
	for(i=0;i<n;i++){
		printf("\nEnter process %d:",i+1);
		scanf("%d",&bt[i]);
		scanf("%d",&pr[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++){
		pos=i;
		for(j=i+1;j<n;j++){
			if(pr[j]<pr[pos])
			  pos=j;
		}
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++){
		wt[i]=0;
		for(j=0;j<i;j++)
		  wt[i]+=bt[j];
        total+=wt[i];
	}
	avg_wt=total/n;
	total=0;
	printf("\n\nProcess\t\tBT\t\tWT\t\tTAT");
	for(i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
		total+=tat[i];
	printf("\np%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
   }
   avg_tat=total/n;
    printf("\n \n average waiting time is:%.2f",avg_wt);
   printf("\n \n average turn around time :%.2f",avg_tat);
}
