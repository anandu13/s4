#include <stdio.h>

#define MAX 20

// Structure to represent a process
struct process {
    int pid;     // Process ID
    int bt;      // Burst Time
    int tat;     // Turnaround Time
    int wt;      // Waiting Time
};

// Function to perform Round-Robin scheduling
void round_robin(struct process p[], int n, int ts) {
    int time = 0, i;
    int remaining = n; // Number of processes left to execute

    // Loop until all processes are completed
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (p[i].bt > 0) { // Process has remaining burst time
                if (p[i].bt > ts) {
                    time += ts;
                    p[i].bt -= ts;
                } else {
                    time += p[i].bt;
                    p[i].tat = time;
                    p[i].wt = time - p[i].wt - p[i].tat;
                    p[i].bt = 0;
                    remaining--;
                }
            }
        }
    }
}

int main() {
    int n, i, ts;
    struct process p[MAX];

    // Input number of processes and time slice
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the Time Slice (Quantum): ");
    scanf("%d", &ts);

    // Input burst time for each process
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter the burst time for Process %d: ", p[i].pid);
        scanf("%d", &p[i].bt);
        p[i].wt = p[i].bt; // Initialize waiting time to burst time for calculation
    }

    // Perform Round-Robin scheduling
    round_robin(p, n, ts);

    // Output results
    printf("\nPID\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].wt, p[i].tat, p[i].tat - p[i].wt);
    }

    return 0;
}
