#include <stdio.h>
#define MAX 20
 
int rq[MAX], front = 0, rear = -1;

struct process {
    int pid,bt,btcopy,wt,tat;
} p[MAX], s;

void enqueue(int pid) {
    if (rear >= MAX - 1) {
        return; // queue is full
    } else {
        rear++;
        rq[rear] = pid;
    }
}
 
int dequeue() {
    int ele, i;
    if (rear == -1) {
        return -1; // queue is empty
    } else {
        ele = rq[0];
        for (i = 0; i < rear; i++) {
            rq[i] = rq[i + 1];
        }
        rear--;
        return ele;
    }
}
 
int main() {
    int n, i, sum = 0, ts, id, ct = 0;
 
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter the Time Slice: ");
    scanf("%d", &ts);
 
    for (i = 0; i < n; i++) {
        p[i].pid = i;
        printf("\nEnter the burst time for Process %d: ", i);
        scanf("%d", &p[i].bt);
        p[i].btcopy = p[i].bt;
    }
 
    for (i = 0; i < n; i++) {
        enqueue(i);
    }
 
    printf("\nExecution order: ");
    id = dequeue();
    while (id != -1) {
        printf(" P%d->", id);
 
        if (p[id].bt > ts) {
            ct += ts; 
            p[id].tat = ct; 
            p[id].bt -= ts; 
            if (p[id].bt != 0) {
                enqueue(p[id].pid); 
            }
        } else { 
            ct += p[id].bt; 
            p[id].tat = ct; 
            p[id].bt = 0; 
        }
        id = dequeue(); 
    }
 
    for (i = 0; i < n; i++) {
        p[i].wt = p[i].tat - p[i].btcopy;
    }
  
    printf("\n\n\n\tPID\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("\n\t%d\t\t\t%d\t\t\t%d\t\t\t%d",
               p[i].pid, p[i].btcopy, p[i].tat, p[i].wt);
    }
    printf("\n");

    return 0;
}
