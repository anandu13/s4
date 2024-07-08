 #include<stdio.h>
 #define MAX 20
 int rq[20], front=0,rear=-1;
 struct process{
 int pid,bt,btcopy,wt, tat;
 }p[20],s;
 voidenqueue(int pid)
 {
 if(rear>MAX-1)
 return;
 else
 {
 rear=rear+1;
 rq[rear]=pid;
 }
 }
 intdequeue()
 {
 int ele, i;
 if(rear==-1)
 return-1;
 else
 {
ele = rq[0];
 for (i = 0; i <= rear; i++)
 rq[i] = rq[i + 1];
 rear--;
 return ele;
 }
 }
 int main()
 {
 int n, i, j, sum = 0, ts, id, ct = 0;
 printf("\nEnter the no. of processes : ");
 scanf("%d", &n);
 printf("\nEnter the Time Slice : ");
 scanf("%d", &ts);
 for (i = 0; i < n; i++)
 {
 p[i].pid = i;
 printf("\nEnter the burst time for Process %d : ", i);
 scanf("%d", &p[i].bt);
 p[i].btcopy = p[i].bt;
 }
 for (i = 0; i < n; i++)
 {
 enqueue(i);
 }
 id = dequeue();
 printf("\nExecution order: ");
 printf(" P%d->", id);
 while (id !=-1)
 {
 if (p[id].bt > ts)
 {
 ct = ct + ts;
 p[id].tat = ct;
 p[id].bt = p[id].bt- ts;
 if (p[id].bt != 0)
 enqueue(p[id].pid);
 }
 else
{
 ct = ct + p[id].bt;
 p[id].tat = ct;
 p[id].bt = 0;
 }
 id = dequeue();
 if (id !=-1)
 printf(" P%d->", id);
 }
 for (i = 0; i < n; i++)
 p[i].wt = p[i].tat- p[i].btcopy;
 printf("\n\n\n\tPID\t\tBurst Time\t\t Turnaround Time\t Waiting Time\n");
 for (i = 0; i < n; i++)
 printf("\n\t%d\t\t\t%d\t\t\t%d\t\t\t%d", p[i].pid, p[i].btcopy, p[i].tat, p[i].wt);
 printf("\n");
 return 0;
 }
 /*
 Output : Round Robin
 Enter the no. of processes : 4
 Enter the Time Slice : 5
 Enter the burst time for Process 0 : 21
 Enter the burst time for Process 1 : 3
 Enter the burst time for Process 2 : 6
 Enter the burst time for Process 3 : 2
 Execution order: P0-> P1-> P2-> P3-> P0-> P2-> P0-> P0-> P0->
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
 8
 21
 15
 Waiting Time
 11
 5
 15
 13
*/ 
