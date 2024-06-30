#include <stdio.h>
int main() {
    int n, m[20], sb[20], s[20], b[20][20];
    printf("Enter number of files: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter starting block and size of file %d: ", i + 1);
        scanf("%d %d", &sb[i], &s[i]);
        printf("Enter blocks occupied by file %d: ", i + 1);
        scanf("%d", &m[i]);
        printf("Enter blocks of file %d: ", i + 1);
        for (int j = 0; j < m[i]; j++)
            scanf("%d", &b[i][j]);
    }
    printf("\nFile\tIndex\tLength\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
}