#include <stdio.h>
#define MAX 50
int main() {
    int page[MAX], n, f, ps, off, pno;
    printf("Enter the number of pages in memory: ");
    scanf("%d", &n);
    printf("Enter page size: ");
    scanf("%d", &ps);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (int i = 0; i < n; i++)
        page[i] = -1;
    printf("\nEnter the page table\n");
    printf("(Enter frame no as -1 if that page is not present in any frame)\n\n");
    printf("pageno\tframeno\n-------\t-------");
    for (int i = 0; i < n; i++) {
        printf("\n\n%d\t\t", i);
        scanf("%d", &page[i]);
    }
    printf("\n\nEnter the logical address (i.e., page no & offset): ");
    scanf("%d%d", &pno, &off);

    if (page[pno] == -1)
        printf("\n\nThe required page is not available in any of the frames");
    else
        printf("\n\nPhysical address (i.e., frame no & offset): %d, %d", page[pno], off);
}