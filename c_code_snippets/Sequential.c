#include <stdio.h>
int main() {
    int num_files, blocks[20], start_blocks[20], track[20], allocation[20][20];
    printf("Enter the number of files: ");
    scanf("%d", &num_files);
    for (int i = 0; i < num_files; i++) {
        printf("Enter the number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &blocks[i]);
        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &start_blocks[i]);
        track[i] = start_blocks[i];
        for (int j = 0; j < blocks[i]; j++)
            allocation[i][j] = start_blocks[i]++;
    }
    printf("Filename\tStart block\tLength\n");
    for (int i = 0; i < num_files; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, track[i], blocks[i]);
}