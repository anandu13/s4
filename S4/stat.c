#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    char path[100];
    struct stat nfile;

    printf("Enter the name of the file whose statistics you want to display: ");
    scanf("%s", path);

    if (stat(path, &nfile) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    printf("User ID: %d\n", nfile.st_uid);
    printf("Block size: %ld\n", nfile.st_blksize);
    printf("Last access time: %ld\n", nfile.st_atime);
    printf("Time of last modification: %ld\n", nfile.st_mtime);
    printf("Protection mode: %o\n", nfile.st_mode);
    printf("Size of file: %ld bytes\n", nfile.st_size);
    printf("Number of links: %ld\n", nfile.st_nlink);

    return 0;
}
