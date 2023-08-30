#include <stdio.h>
int main() {
    int frames, pages, pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    int frameArray[frames];
    for (int i = 0; i < frames; i++) {
        frameArray[i] = -1;
    }
    printf("Enter the sequence of pages: ");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &pageArray[i]);
    }
    for (int i = 0; i < pages; i++) {
        int page = pageArray[i];
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frameArray[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int replaceIndex = 0;
            int farthestIndex = i;
            for (int j = 0; j < frames; j++) {
                int k = i + 1;
                while (k < pages) {
                    if (frameArray[j] == pageArray[k])
                        break;
                    k++;
                }
                if (k > farthestIndex) {
                    farthestIndex = k;
                    replaceIndex = j;
                }
            }
            frameArray[replaceIndex] = page;
            pageFaults++;
        }
        printf("\nPage %d: ", page);
        for (int j = 0; j < frames; j++) {
            if (frameArray[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frameArray[j]);
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
}
