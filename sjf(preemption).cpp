#include<stdio.h>
struct process
{
int WT,AT,BT,TAT;
};
struct process a[10];
int main()
{
int n,i,temp[10];
int count=0,t=0,short_p=0;
float total_WT=0,total_TAT=0,avg_WT,avg_TAT;
printf("Enter number of process: ");
scanf("%d",&n);
printf("enter arrival time and burst time for the process\n");
printf("AT\tBT\n");
for(i=0;i<n;i++){
scanf("%d%d",&a[i].AT,&a[i].BT);
temp[i]=a[i].BT;
}
a[9].BT=10000;
for(t=0;count!=n;t++){
short_p=9;
for(i=0;i<n;i++){
if(a[i].BT<a[short_p].BT&&(a[i].AT<=t&&a[i].BT>0))
{
short_p=i;
}
}
a[short_p].BT=a[short_p].BT-1;
if(a[short_p].BT==0){
count++;
a[short_p].WT=t+1-a[short_p].AT-temp[short_p];
a[short_p].TAT=t+1-a[short_p].AT;
total_WT=total_WT+a[short_p].WT;
total_TAT=total_TAT+a[short_p].TAT;
}
}
avg_WT=total_WT/n;
avg_TAT=total_TAT/n;
printf("ID\tWT\tTAT \n");
for(i=0;i<n;i++){
printf("%d\t%d\t%d\n",i+1,a[i].WT,a[i].TAT);
}
printf("average waiting time of the process is :%f \n",avg_WT);
printf("average turn around time of the process is :%f\n",avg_TAT);
}

