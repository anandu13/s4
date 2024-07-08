//indexed

#include<stdio.h>
#include<stdlib.h>

void main() {
    int n;
    printf("Input the number of blocks: ");
    scanf("%d", &n);

    int *blocks = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    int flag = 0;
    do {
        int index;
        printf("\nInput file index block no: ");
        scanf("%d", &index);

        if (blocks[index] == 1)
            printf("\nIndex block already allocated! No allocation possible");
        else {
            int length;
            printf("\nInput file length: ");
            scanf("%d", &length);

            int count = 0;
            blocks[index] = 1;
            int index_block[100];

            for (int i = 0; (i < n) && (count < length); i++) {
                if (blocks[i] == 0) {
                    blocks[i] = 1;
                    index_block[count] = i;
                    count++;
                }
            }

            if (count < length) {
                printf("\nInsufficient storage - no allocation");
                for (int i = 0; i < count; i++) {
                    blocks[index_block[i]] = 0;
                }
                blocks[index] = 0;
            } else {
                printf("\nFile allocated to disk with index block %d\n", index);
                for (int i = 0; i < count; i++) {
                    printf("%d->%d\n", index, index_block[i]);
                }
            }
        }
        printf("\n\n0-continue, 1-exit: ");
        scanf("%d", &flag);
    } while (flag != 1);
}
