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
    char c;
    char lastThree[3] = {' ', ' ', ' '};
    printf("Enter a string of a's and b's: ");
    while ((c = getchar()) != '\n') {
        if (c != 'a' && c != 'b') {
            printf("Invalid input: Please enter a string of a's and b's.\n");
            return 1;
        }
        lastThree[0] = lastThree[1];
        lastThree[1] = lastThree[2];
        lastThree[2] = c;
    }
    printf((lastThree[0] == 'a') ? "Accepted\n" : "Rejected\n");
    return 0;
}
```
# 3
```c
#include <stdio.h>
int main() {
    char c;
    char lastTwo[2] = {' ', ' '};
    printf("Enter a string of 0's and 1's: ");
    while ((c = getchar()) != '\n') {
        if (c != '0' && c != '1') {
            printf("Invalid input: Please enter a string of 0's and 1's.\n");
            return 1;
        }
        lastTwo[0] = lastTwo[1];
        lastTwo[1] = c;
    }
    printf((lastTwo[0] == '0'&lastTwo[1] == '0') ? "Accepted\n" : "Rejected\n");
    return 0;
}
```
