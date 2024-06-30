#include <stdio.h>
void display(int fr[], int f) {
    for (int i = 0; i < f; i++) {
        printf("%d ", fr[i]);
    }
    printf("\n");
}
int main() {
    int pg[20], fr[20], n, f, pf = 0, index = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pg[i]);
    }
    for (int i = 0; i < f; i++) {
        fr[i] = -1;
    }
    for (int j = 0; j < n; j++) {
        int flag = 0;
        for (int i = 0; i < f; i++) {
            if (fr[i] == pg[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            fr[index] = pg[j];
            index = (index + 1) % f;
            pf++;
            display(fr, f);
        }
    }
    printf("Number of page faults: %d\n", pf);
}