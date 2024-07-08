#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3,x =0;

int signal(int s){
    return(++s);
}

int wait(int s){
    return(--s);
}

void producer(){
    empty = wait(empty);
    mutex = wait(mutex);
    x++;
    printf("Producer produced");
    full = signal(full);
    mutex = signal(mutex);
}

void consumer(){
    full = wait(full);
    mutex = wait(mutex);
    printf("consumer consumed");
    x--;
    empty = signal(full);
    mutex = signal(mutex);
}

void main(){
    int n;
    while(1){
        printf("Enter your choice\n 1.Producer 2.Consumer 3.Exit\n Choice:");
        scanf("%d",&n);

        switch(n){
            case 1:if(mutex == 1 && empty != 0)
                        producer();
                    else
                        printf("BUffer is full");                    
                    break;
            
            case 2:if(mutex == 1 && full != 0)
                        consumer();
                    else
                        printf("BUffer is emopty");                    
                    break;
            
            case 3:exit(0);;
                    break;
        }
    }
}