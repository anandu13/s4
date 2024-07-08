#include <stdio.h>

#define max 25

int i, j, k = 0, nb, nf, temp = 0, highest = 0;

void worstfit(int b[], int f[]) {
    for (i = 1; i <= nf; i++) {
        for (j = 1; j <= nb; j++) {
            temp = b[j] - f[i];
            if (temp >= 0) {
                if (highest < temp) {
                    k = j;
                    highest = temp;
                }
            }
        }
        if (highest != 0)
            printf("\nFile Size %d is put in %d partition", f[i], b[k]);
        else
            printf("\nFile Size %d must wait", f[i]);
        b[k] = highest;
        highest = 0;
    }
}

int main() {
    int b[max], f[max];
    printf("\nMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks : ");
    scanf("%d", &nb);
    printf("Enter the number of files : ");
    scanf("%d", &nf);
    printf("\nEnter the size of the blocks : \n");
    for (i = 1; i <= nb; i++) {
        printf("Block %d : ", i);
        scanf("%d", &b[i]);
    }
    printf("Enter the size of the files :-\n");
    for (i = 1; i <= nf; i++) {
        printf("File %d: ", i);
        scanf("%d", &f[i]);
    }
    worstfit(b, f);
    return 0;
}
