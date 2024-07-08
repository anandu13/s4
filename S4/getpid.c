#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    printf("Process ID is %d\n", pid);
    pid_t ppid = getppid();
    printf("Parent process ID is %d\n", ppid);
    return 0; // Added return statement
}
