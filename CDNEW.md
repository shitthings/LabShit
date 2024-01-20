# 1
```c
#include <stdio.h>
int main() {
    int state = 0, c;
    while ((c = getchar()) != '\n') {
        if (c != '0' && c != '1') {
            printf("Invalid input: Please enter a binary number.\n");
            return 1; // Exit with an error code
        }
        state = (state * 2) + (c - '0');
    }
    printf(state % 2 ? "Rejected\n" : "Accepted\n");
    return 0;
}
```
