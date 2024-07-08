 #include <stdio.h>
 struct process
 {
 int pid, bt, ct, wt, tat, priority;
 } p[20], s;
 int main()
 {
 int n, i, j;
 printf("\n Enter the no. of processes : ");
 scanf("%d", &n);
 for (i = 0; i < n; i++)
 {
 p[i].pid = i;
 printf("\n Enter the Priority for Process %d : ", i);
 scanf("%d", &p[i].priority);
 printf("\n Enter the burst time for Process %d : ", i);
 scanf("%d", &p[i].bt);
 }
 for (i = 0; i < n- 1; i++)
 for (j = 0; j < n- i- 1; j++)
 if (p[j].priority > p[j + 1].priority)
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
 printf("\n\tPID\tPriority\tBurst Time\t Turnaround Time\t Waiting Time\n");
 for (i = 0; i < n; i++)
 printf("\n\t%d\t%d\t\t%d\t\t\t%d\t\t\t%d", p[i].pid, p[i].priority, p[i].bt, p[i].tat, p[i].wt);
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
 /*
 Output : Priority
 Enter the no. of processes : 4
 Enter the Priority for Process 0 : 3
 Enter the burst time for Process 0 : 21
 Enter the Priority for Process 1 : 1
 Enter the burst time for Process 1 : 6
 Enter the Priority for Process 2 : 2
 Enter the burst time for Process 2 : 3
 Enter the Priority for Process 3 : 4
 Enter the burst time for Process 3 : 2
 Process execution order:
P1->P2->P0->P3->
 PID Priority BurstTime TurnaroundTime WaitingTime
 0 3 21 30 9
 1 1 6 6 0
 2 2 3 9 6
 3 4 2 32 30*/