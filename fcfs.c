#include <stdio.h>
int main(){
int n,i;
float totwt=0,tottat=0;
//Taking input for number of processes
printf("Enter the number of process: ");
scanf("%d",&n);
char pn[n][10];
int arr[n],bur[n],star[n],finish[n],wt[n],tat[n];
//Input for process names, arrival time, and burst time
for(i=0;i<n;i++){
printf("Enter Process Name, Arrival Time, Burst Time for Process %d: ",i+1);
scanf("%s %d %d",pn[i],&arr[i],&bur[i]);
}
//Calculating Start, Waiting Time, Turnaround Time, Finish Time
star[0]=arr[0];
wt[0]=0;
finish[0]=star[0]+bur[0];
tat[0]=finish[0]-arr[0];
for(i=1;i<n;i++){
star[i]=finish[i-1]>arr[i] ? finish[i-1] : arr[i];
wt[i]=star[i]-arr[i];
finish[i]=star[i]+bur[i];
tat[i]=finish[i]-arr[i];
}
//Displaying results
printf("\nPName\tArrTime\tBurTime\tStart\tWT\tTAT\tFinish");
for(i=0;i<n;i++){
printf("\n%s\t%6d\t%6d\t%6d\t%6d\t%6d\t%6d",pn[i],arr[i],bur[i],star[i],wt[i],tat[i],finish[i]);
totwt+=wt[i];
tottat+=tat[i];
}
//Calculating and printing avg WT and TAT
printf("\n\nAverage Waiting Time:%.2f",totwt/n);
printf("\nAverage Turnaround Time:%.2f\n",tottat/n);
return 0;
}
