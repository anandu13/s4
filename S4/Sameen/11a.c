// sequesntial

#include<stdio.h>

void main() {
    int n, blocks[100];
    printf("Input the number of blocks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    int flag = 0;
    do {
        int b;
        printf("\nInput file starting block: ");
        scanf("%d", &b);

        int len;
        printf("Input file length: ");
        scanf("%d", &len);

        if ((b + len - 1) > (n - 1))
            printf("\nfile cannot be allocated to disk!");
        else {
            int flag = 0;
            for (int i = b; i < (b + len); i++) {
                if (blocks[i] == 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                printf("\nblocks allocated to this file:");
                for (int i = b; i < (b + len); i++) {
                    printf("%d ", i);
                    blocks[i] = 1;
                }
            } else {
                printf("\nfile cannot be allocated to disk!");
            }
        }
        printf("\n\n0-continue, 1-exit: ");
        scanf("%d", &flag);
    } while (flag != 1);
}
