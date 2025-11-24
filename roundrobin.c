#include <stdio.h>
//Define the process structure
struct process{
int burst,wait,comp,f;
}p[20];
int main(){
int n,i,j,totalwait=0,totalturn=0,quantum,flag=1,time=0;
//Take the user input
printf("\n Enter the number of processes:");
scanf("%d",&n);
printf("\n Enter the time in quantum (in ms): ");
scanf("%d",&quantum);
for(i=0;i<n;i++){
printf("Enter the burst time (in ms) for Process #%d:",i+1);
scanf("%d",&p[i].burst);
p[i].f=1;//Mark process as unfinished
p[i].comp=0;//Initialize completed time to 0
}
//Print the execution order table
printf("\n Order of Execution\n");
printf("Process\tStarting TimetEnding Time\tRemainig Time\n");
//Round robin logic
while(flag==1){
flag=0;//Assuming all processes are done
for(i=0;i<n;i++){
if(p[i].f==1){//If process is unfinished
flag=1;//Atleast one process is still running
j=quantum;
//Check if remaining BT is more than quantum
if((p[i].burst-p[i].comp)>quantum){
p[i].comp+=quantum;
}
else{
//Process finishes in this round
p[i].wait=time-p[i].comp;
j=p[i].burst-p[i].comp;
p[i].comp=p[i].burst;
p[i].f=0;//Mark as completed
}
//Print the execution details
printf("Process #%-3d\t%-12d\t%-10d\t%-11d\n",i+1,time,time+j,p[i].burst-p[i].comp);
time+=j;
}
}
}

printf("\n-------------------------");
printf("\nProcess\tWaiting Time\tTurnaround Time\n");
for(i=0;i<n;i++){
printf("Process #%-12d%-15d%-15d\n",i+1,p[i].wait,p[i].wait+p[i].burst);
totalwait+=p[i].wait;
totalturn+=p[i].wait+p[i].burst;
}
//Calculate and display averages
printf("\n\nAverage \n-------------------------------\n");
printf("Waiting Time:%.2fms\n",totalwait/(float)n);
printf("Turnaround Time:%.2fms\n",totalturn/(float)n);
return 0;
}
