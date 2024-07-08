#include <stdio.h>

int main() {
    int reference[50], frame[50], recent[50], fsize, n, fault = 0, c = 0, k, temp, flag, flag1;
    float miss, hit;

    printf("Enter the number of references: ");
    scanf("%d", &n);

    printf("Enter the references: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &reference[i]);

    printf("Enter the frame size: ");
    scanf("%d", &fsize);

    for (int i = 0; i < fsize; i++) {
        fault++;
        frame[i] = reference[i];
        recent[i] = reference[i];
        c++;
    }
    recent[c] = 0;

    for (int i = fsize; i < n; i++) {
        flag1 = 0;
        for (k = 0; k < c; k++) {
            if (reference[i] == recent[k]) {
                flag1 = 1;
                break;
            }
        }

        if (flag1 == 1) {
            temp = recent[k];
            for (int j = k; j < c; j++)
                recent[j] = recent[j + 1];
            recent[c - 1] = temp;
        } else {
            recent[c] = reference[i];
            c++;
            recent[c] = 0;
        }

        flag = 0;
        for (int j = 0; j < fsize; j++) {
            if (frame[j] == reference[i])
                flag = 1;
        }

        if (flag != 1) {
            fault++;
            for (k = 0; k < c; k++) {
                for (int j = 0; j < fsize; j++) {
                    if (recent[k] == frame[j]) {
                        frame[j] = reference[i];
                        goto end;
                    }
                }
            }
        }
        end:
        flag = 0;
    }

    printf("\nTotal number of faults = %d\n", fault);
    miss = ((float) fault / n) * 100;
    hit = ((float) (n - fault) / n) * 100;
    printf("Total number of references = %d\n", n);
    printf("Miss ratio = %.2f%\n", miss);
    printf("Hit ratio = %.2f%\n", hit);

    return 0;
}
