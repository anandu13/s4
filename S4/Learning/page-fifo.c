#include <stdio.h>

int main() {
    int reference[50], frame[50], fsize, i, j, flag = 0, c = 0, n, fault = 0;
    float miss, hit;

    printf("Enter the number of references: ");
    scanf("%d", &n);

    printf("Enter the references: ");
    for (i = 0; i < n; i++)
        scanf("%d", &reference[i]);

    printf("Enter the frame size: ");
    scanf("%d", &fsize);

    for (i = 0; i < fsize; i++)
        frame[i] = -1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < fsize; j++) {
            if (frame[j] == reference[i]) {
                flag = 1;
                break; // Exit the loop once a match is found
            }
        }
        if (flag != 1) {
            fault++;
            frame[c] = reference[i];
            c = (c + 1) % fsize; // Update the frame index circularly
        }
        flag = 0;
    }

    printf("Total number of faults = %d\n", fault);
    miss = ((float)fault / n) * 100;
    hit = ((float)(n - fault) / n) * 100;
    printf("Total number of references = %d\n", n);
    printf("Miss ratio = %.2f%%\n", miss);
    printf("Hit ratio = %.2f%%\n", hit);

    return 0;
}
