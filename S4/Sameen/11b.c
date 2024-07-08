//linked

#include<stdio.h>
#include<stdlib.h>

typedef struct block {
    int block_no;
    struct block *next;
} block;

typedef struct {
    int start_block;
    int length;
    block *list; // list of blocks allocated to this process
} file;

void main() {
    int n;
    printf("Input the number of free blocks: ");
    scanf("%d", &n);

    int blocks[100];
    for (int i = 0; i < n; i++)
        blocks[i] = 0;

    int flag = 0;
    do {
        file *ptr = (file*) malloc(sizeof(file));
        printf("\nInput file starting block: ");
        scanf("%d", &(ptr->start_block));
        printf("Input file length: ");
        scanf("%d", &(ptr->length));

        if (blocks[ptr->start_block] == 1) {
            printf("\nStarting block already allocated! Allocation not possible.");
        } else {
            block *b = (block*) malloc(sizeof(block));
            b->block_no = ptr->start_block;
            b->next = NULL;
            ptr->list = b;
            blocks[ptr->start_block] = 1;

            int count = 1, i;
            for (i = 0; (i < n) && (count < (ptr->length)); i++) {
                if (blocks[i] == 0) {
                    block *new = (block*) malloc(sizeof(block));
                    new->block_no = i;
                    new->next = NULL;
                    block *p = ptr->list;
                    while (p->next != NULL)
                        p = p->next;
                    p->next = new;
                    count++;
                    blocks[i] = 1;
                }
            }

            if (i == n && count < (ptr->length)) {
                printf("\nAllocation not possible - insufficient storage!");
            } else {
                printf("\nFile allocated to disk.");
                printf("\nLinked list of blocks allocated to this file:");
                block *p = ptr->list;
                while (p->next != NULL) {
                    printf("%d->", p->block_no);
                    p = p->next;
                }
                printf("%d", p->block_no);
            }
        }
        printf("\n\n0-continue, 1-exit: ");
        scanf("%d", &flag);
    } while (flag != 1);
}
