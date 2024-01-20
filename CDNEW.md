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
```c
#include <stdio.h>
int main() {
    int state = 0;
    char c;
    char lastThree[3] = {' ', ' ', ' '};
    printf("Enter a string of a's and b's: ");
    while ((c = getchar()) != '\n') {
        if (c != 'a' && c != 'b') {
            printf("Invalid input: Please enter a string of a's and b's.\n");
            return 1;
        }
        state = (c == 'a') ? 1 : 0;
        lastThree[0] = lastThree[1];
        lastThree[1] = lastThree[2];
        lastThree[2] = c;
    }
    printf((lastThree[0] == 'a') ? "Accepted\n" : "Rejected\n");
    return 0;
}
```
