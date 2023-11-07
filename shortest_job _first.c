#include <stdio.h>

int main()
{
 int arrival_time[10], burst_time[10], temp[10];
 int i, smallest, count = 0, time, limit;
 double wait_time = 0, turnaround_time = 0, end;
 float average_waiting_time, average_turnaround_time;
 printf("\nEnter the Total Number of Processes:\t");
 scanf("%d", &limit);
 printf("\nEnter Details of %d Processes\n", limit);
 for(i = 0; i < limit; i++)
 {
 printf("\nEnter Arrival Time:\t");
 scanf("%d", &arrival_time[i]);
 printf("\nEnter Burst Time:\t");
 scanf("%d", &burst_time[i]);
 temp[i] = burst_time[i];
 }
 printf("process\tArrival_time\tBurst_time\n");
 for(i=0; i<limit; i++)
 {
 printf("p%d\t\t%d\t\t%d\n",i+1,arrival_time[i],burst_time[i]);
 }
 burst_time[9] = 9999;
 for(time = 0; count != limit; time++)
 {
 smallest = 9;
 for(i = 0; i < limit; i++)
 {
 if(arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] >
0)
 {
 smallest = i;
 }
 }
 burst_time[smallest]--;
 if(burst_time[smallest] == 0)
 {
 count++;
 end = time + 1;
 wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
 turnaround_time = turnaround_time + end - arrival_time[smallest];
 }
 }
 average_waiting_time = wait_time / limit;
 average_turnaround_time = turnaround_time / limit;
 printf("\nAverage Waiting Time:\t%lf\n", average_waiting_time);
 printf("\nAverage Turnaround Time:\t%lf\n",average_turnaround_time);
 return 0;
}


/*
output:
avcoe@avcoe-HP-ProDesk-400-G1-SFF:~$ gcc sjf.c
avcoe@avcoe-HP-ProDesk-400-G1-SFF:~$ ./a.out
Enter the Total Number of Processes: 4
Enter Details of 4 Processes
Enter Arrival Time: 0
Enter Burst Time: 4
Enter Arrival Time: 1
Enter Burst Time: 5
Enter Arrival Time: 3
Enter Burst Time: 8
Enter Arrival Time: 4
Enter Burst Time: 9
process Arrival_time Burst_time
p1 0 4
p2 1 5
p3 3 8
p4 4 9
Average Waiting Time: 5.500000
Average Turnaround Time: 12.000000
*/
