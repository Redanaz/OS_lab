#include <stdio.h>
int main(){
int i,j,n,temp;
int pno[10],bt[10],wt[10],tt[10];
float sum=0,at=0;
//Taking number of processes
printf("\n Enter the number of processes:");
scanf("%d",&n);
//Taking Burst Time
printf("\n Enter the burst time for each process:\n");
for(i=0;i<n;i++){
printf("Process %d: ",i+1);
scanf("%d",&bt[i]);
pno[i]=i+1;//Assign process number
}
//Sorting by BT(SJF scheduling)
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(bt[i]>bt[j]){
//Swap BT
temp=bt[i];
bt[i]=bt[j];
bt[j]=temp;
//Swap pno
temp=pno[i];
pno[i]=pno[j];
pno[j]=temp;
}
}
}
//Calculate WT
wt[0]=0;
for(i=1;i<n;i++){
wt[i]=bt[i-1]+wt[i-1];
sum+=wt[i];
}
//Calculate TAT
printf("\n Process No\t Burst Time\t Waiting Time\t Turnaround Time\n");
for(i=0;i<n;i++){
tt[i]=bt[i]+wt[i];
at+=tt[i];
printf("\n P%d\t\t%d\t\t%d\t\t%d",pno[i],bt[i],wt[i],tt[i]);
}
printf("\n\n\t Average Waiting Time:%.2f",sum/n);
printf("\n\t Average Turnaroud Time:%.2f\n",at/n);
return 0;
}
