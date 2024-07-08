// disk fcfs

#include <stdio.h>
#include <math.h>

#define MAX 20

void FCFS(int arr[], int head, int size) {
    int seek_count = 0;
    int cur_track, prev_track = head, distance;
    
    
    // Seek sequence would be the same as request array sequence
    printf("Seek Sequence is\n");
    for(int i = 0; i < size; i++) {
        cur_track = arr[i];
        // calculate absolute distance
        distance = fabs(prev_track - cur_track);
        // increase the total count
        seek_count += distance;
        // accessed track is now new head
        prev_track = cur_track;
        printf("%d-> ", arr[i]);
    }

    printf("\nTotal number of seek operations: %d\n", seek_count);
}

int main() {
    int arr[MAX], head, n, i, t;
    printf("Enter the total no. of tracks: ");
    scanf("%d", &t);
    printf("Enter the no. of requests: ");
    scanf("%d", &n);
    printf("Enter the track requests: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position of read write head: ");
    scanf("%d", &head);
    FCFS(arr, head, n);
    return 0;
}
