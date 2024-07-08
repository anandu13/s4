 #include <stdio.h>
 struct process
 {
 int pid, bt, ct, wt, tat;
 } p[20];
 int main()
 {
 int n, i;
 printf("\nEnter the Number of Processes : ");
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
 p[i].pid = i;
 printf("\nEnter the Burst time for Process %d : ", i);
 scanf("%d", &p[i].bt);
}
 p[0].ct = 0;
 for (i = 0; i < n; i++)
 {
 p[i].ct = p[i- 1].ct + p[i].bt;
 p[i].tat = p[i].ct;
 }
 p[0].wt = 0;
 for (i = 0; i < n; i++)
 p[i].wt = p[i].tat- p[i].bt;
 printf("\nProcess execution order:\n");
 for (i = 0; i < n; i++)
 printf("P%d->", p[i].pid);
 printf("\n\tPID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
 for (i = 0; i < n; i++)
 printf("\n\t%d\t\t%d\t\t\t%d\t\t\t%d", p[i].pid, p[i].bt, p[i].tat, p[i].wt);
 printf("\n");
 float avgtat = 0, avgwt = 0;
 for (i = 0; i < n; i++)
 {
 avgtat += p[i].tat;
 avgwt += p[i].wt;
 }
 printf("Average Turn Around Time = %.2f\n", avgtat / n);
 printf("Average Waiting Time = %.2f\n", avgwt / n);
 return 0;
 }
 /**
 OUTPUT : FCFS
 Enter the Number of Processes : 4
 Enter the Burst time for Process 0 : 21
 Enter the Burst time for Process 1 : 3
 Enter the Burst time for Process 2 : 6
 Enter the Burst time for Process 3 : 2
 Process execution order:
 P0->P1->P2->P3->
 PID
 Burst Time
 Turnaround Time
 Waiting Time
0 21 21 0
 1 3 24 21
 2 6 30 24
 3 2 32 30*/    