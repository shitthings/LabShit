#include <stdio.h>
struct file {
    char fname[10];
    int start, size, block[10];
};
int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    struct file f[10];
    for (int i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);
        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter number of blocks: ");
        scanf("%d", &f[i].size);
        printf("Enter block numbers: ");
        for (int j = 1; j <= f[i].size; j++) {
            scanf("%d", &f[i].block[j]);
        }
    }
    printf("File\tStart\tSize\tBlocks\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (int j = 1; j <= f[i].size; j++) {
            printf("--->%d", f[i].block[j]);
        }
        printf("\b\b  \n");
    }
}