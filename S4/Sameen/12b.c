//scan disk 

#include <stdio.h>

int main() {
    int head, req[20], n, i, j, seektime = 0, max, flag = 0, seq[20], c = 0, temp;
    printf("Enter the Max number of Cylinders: ");
    scanf("%d", &max);
    printf("Enter the Number of Requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);

    if (req[0] > max - 1)
        flag = 1;
    
    if (flag == 1)
        printf("Process cannot complete");
    else {
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (req[j] > req[j + 1]) {
                    temp = req[j];
                    req[j] = req[j + 1];
                    req[j + 1] = temp;
                }
            }
        }

        printf("Enter the current position of the head: ");
        scanf("%d", &head);
        j = 0;
        while (req[j] <= head)
            j++;

        for (i = j; i < n; i++)
        {
            seektime += req[i] - head;
            head = req[i];
            seq[c] = req[i];
            c++;
        }

        seektime += (max - 1) - req[n - 1];
        head = max - 1;

        for (i = j - 1; i >= 0; i--)
        {
            seektime += head - req[i];
            head = req[i];
            seq[c] = req[i];
            c++;
        }

        printf("Seektime = %d\n", seektime);
        printf("Seek Sequence: ");
        for (i = 0; i < c; i++)
            printf("%d->", seq[i]);
    }
    return 0;
}
