#include <stdio.h>

int main()
{
	int choice;	
    printf(" 1. First Come First Serve\n");
    printf(" 2. Shortest Job First\n ");
    printf("3. Priority Scheduling without Aging\n ");
    printf("4. Priority Scheduling with Aging\n ");
    printf("5. Round Robin\n ");
	printf("Enter which Scheduling Algorithm you want to execute: ");
	scanf("%d", &choice);

	if(choice == 1) {
	    printf("First Come First Serve begins: \n");
	    
	    int n,at[20],bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
 
    printf("\nEnter Process Arraival Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&at[i]);
    }
printf("\nEnter Process CPU Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0;    
 
    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcess\t\tArrival time\tBurst Time\tWaiting Time\tTurnaround Time");
 
    
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",i+1,at[i],bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
 
    return 0;
	   
	}
	
	if(choice == 2) {
	    printf("Shortest Job First begins: \n");
	    
	    int at[20],bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&at[i]);
        p[i]=i+1;           
    }
    printf("\nEnter CPU Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           
    }
 
    
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            
 
    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      
    total=0;
 
    printf("\nProcess\t    Arrival Time    \t  Burst time   \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t   %d\t\t   %d\t\t\t%d",p[i],at[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
	   
	}
	
	if(choice == 3) {
	    printf("Priority Scheduling without Aging begins: \n");
	    
	    int i,n,p[10]={1,2,3,4,5,6,7,8,9,10},min,k=1,burst=0,pri[10];
int bt[10],temp,temp1,j,at[10],wt[10],rt[10],tt[10],ta=0,sum=0;
float wavg,tavg,tsum,wsum;
printf("\nenter the No. processes ");
scanf("%d",&n);
for(i=0;i<n;i++) {
printf("\tenter the CPU burst time of %d process",i+1);
scanf("%d",&bt[i]);
printf("\tEnter the arrival time of %d process ",i+1);
scanf("%d",&at[i]);
printf("\tEnter the priority time of %d process",i+1);
scanf("%d",&pri[i]);
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(at[i]<at[j])
{
temp=p[j];
p[j]=p[i];
p[i]=temp;
temp=at[j];
at[j]=at[i];
at[i]=temp;
temp1=bt[j];
bt[j]=bt[i];
bt[i]=temp1;
}
}
}
for(j=0;j<n;j++)
{   burst=burst+bt[j];
   min=bt[k];
for(i=k;i<n;i++)
{ min=pri[k];
if (burst>=at[i])
{
if(pri[i]<min)
{
temp=p[k];
p[k]=p[i];
p[i]=temp;
temp=at[k];
at[k]=at[i];
at[i]=temp;
temp1=bt[k];
bt[k]=bt[i];
bt[i]=temp1;
temp=pri[k];
pri[k]=pri[i];
pri[i]=temp;

}
}
}
k++;
}
wt[0]=0;
for(i=1;i<n;i++)
{
sum=sum+bt[i-1];
wt[i]=sum-at[i];
}
for(i=0;i<n;i++)
{
wsum=wsum+wt[i];
}
wavg=wsum/n;
for(i=0;i<n;i++)
{
ta=ta+bt[i];
tt[i]=ta-at[i];
}
for(i=0;i<n;i++)
{
tsum=tsum+tt[i];
}
tavg=tsum/n;
for(i=0;i<n;i++)
{
rt[i]=wt[i];
}

printf("************************");
printf("\n RESULT:-\t\t\t VARIOUS TIMES");
printf("\nprocess\t burst\t arrival\tpriority " );
for(i=0;i<n;i++)
{
printf("\n  p%d",p[i]);
printf("\t   %d",bt[i]);
printf("\t   %d",at[i]);
printf("\t\t   %d",pri[i]);
}
printf("\nwaiting time\tturnaround time\tresponce time");
for(i=0;i<n;i++)
{
printf("\n  %d",wt[i]);
printf("\t\t  %d",tt[i]);
printf("\t\t%d",rt[i]);
}
printf("\nAVERAGE WAITING TIME:-  %f ms",wavg);
printf("\nAVERAGE TURN AROUND TIME:-  %f ms" ,tavg);
printf("\nAVERAGE RESPONSE TIME:-  %f ms\n",wavg);

	}
	
	if(choice == 4) {
	    printf("Priority Scheduling with Aging begins: \n");
	    
	     int Arrival_time[20],burst_time[20], process[20], waiting_time[20], turnaround_time[20], priority[20], Aiging[20];
      int i, j, limit, sum = 0, position, temp;
      float average_wait_time, average_turnaround_time;
      printf("Enter Total Number of Processes:\t");
      scanf("%d", &limit);
      printf("\nEnter CPU Burst Time and Priority For %d Processes\n", limit);
      for(i = 0; i < limit; i++)
      {
            printf("\nProcess[%d]\n", i + 1);
            printf("Process Arrival Time:\t");
            scanf("%d", &Arrival_time[i]);
            printf("Process CPU Burst Time:\t");
            scanf("%d", &burst_time[i]);
            printf("Process Priority:\t");
            scanf("%d", &priority[i]);
            printf("Aiging:\t");
            scanf("%d", &Aiging[i]);
            process[i] = i + 1;
      }
      for(i = 0; i < limit; i++)
      {
            position = i;
            for(j = i + 1; j < limit; j++)
            {
                  if(priority[j] < priority[position])
                  {
                        position = j;
                  }
            }
            temp = priority[i];
            priority[i] = priority[position];
            priority[position] = temp; 
            temp = burst_time[i];
            burst_time[i] = burst_time[position];
            burst_time[position] = temp;
            temp = process[i];
            process[i] = process[position];
            process[position] = temp;
      }
      waiting_time[0] = 0;
      for(i = 1; i < limit; i++)
      {
            waiting_time[i] = 0;
            for(j = 0; j < i; j++)
            {
                  waiting_time[i] = waiting_time[i] + burst_time[j];
            }
            sum = sum + waiting_time[i];
      }
      average_wait_time = sum / limit;
      sum = 0;
      printf("\nProcess ID      \t\tArrival time\t Burst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < limit; i++)
      {
            turnaround_time[i] = burst_time[i] + waiting_time[i];
            sum = sum + turnaround_time[i];
            printf("\nProcess[%d]\t\t\t    %d\t\t %d\t\t %d\t\t %d\n", process[i], Arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
      }
      average_turnaround_time = sum / limit;
      printf("\nAverage Waiting Time:\t%f", average_wait_time);
      printf("\nAverage Turnaround Time:\t%f\n", average_turnaround_time);
      return 0;

	}
	
	if(choice == 5) {
	    printf("Round Robin begins: \n");
	    
	    int i, limit, total = 0, x, counter = 0, time_quantum; 
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10]; 
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &limit); 
      x = limit; 
      for(i = 0; i < limit; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arrival_time[i]);
            printf("CPU Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i]; 
                  turnaround_time = turnaround_time + total - arrival_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            }
            else if(arrival_time[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", average_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time); 
      return 0; 
	   
	}
	
	if(choice>5) {
	    printf ("Please Input value between 1 to 5");
	}
	
}


