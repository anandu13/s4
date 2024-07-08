#include<stdio.h>
 struct process {
 int pid,bt,ct,wt, tat;
 }p[20],s;
 intmain()
 {
 int n, i, j;
 printf("\nEntertheno.ofprocesses:");
 scanf("%d",&n);
 for(i=0; i<n; i++)
 {
 p[i].pid=i;
 printf("\nEntertheburst timeforProcess%d:", i);
 scanf("%d",&p[i].bt);
}
 for (i = 0; i < n- 1; i++)
 for (j = 0; j < n- i- 1; j++)
 if (p[j].bt > p[j + 1].bt)
 {
 s = p[j];
 p[j] = p[j + 1];
 p[j + 1] = s;
 }
 p[-1].ct = 0;
 for (i = 0; i < n; i++)
 {
 p[i].ct = p[i- 1].ct + p[i].bt;
 p[i].tat = p[i].ct;
 }
 p[0].wt = 0;
 for (i = 1; i < n; i++)
 p[i].wt = p[i].tat- p[i].bt;
 printf("\nProcess execution order:\n");
 for (i = 0; i < n; i++)
 printf("P%d->", p[i].pid);
 for (i = 0; i < n- 1; i++)
 for (j = 0; j < n- i- 1; j++)
 if (p[j].pid > p[j + 1].pid)
 {
 s = p[j];
 p[j] = p[j + 1];
 p[j + 1] = s;
 }
 printf("\n\tPID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
 for (i = 0; i < n; i++)
 printf("\n\t%d\t\t%d\t\t\t%d\t\t\t%d", p[i].pid, p[i].bt, p[i].tat, p[i].wt);
 printf("\n");
 return 0;
 }
 /*
 Output : SJF
 Enter the Number of Processes : 4
 Enter the Burst time for Process 0 : 21
 Enter the Burst time for Process 1 : 3
 Enter the Burst time for Process 2 : 6
 Enter the Burst time for Process 3 : 2
 Process execution order:
 P3->P1->P2->P0->
 PID
 0
 1
 2
 3
 Burst Time
 21
 3
 6
 2
 Turnaround Time
 32
 5
 11
 2
 Waiting Time
 11
 2
 5
 0
*/