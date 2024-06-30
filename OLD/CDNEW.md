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
# 2
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
# 4
```c
#include <stdio.h>
int main() {
    int state_a = 0;
    int state_b = 0;
    char c;
    while ((c = getchar()) != '\n') {
        if (c != 'a' && c != 'b') {
            printf("Invalid input: Please enter a string of a's and b's.\n");
            return 1;
        }
        (c == 'a') ? state_a++ : state_b++;
    }
    printf((state_a % 3 == 0 && state_b % 2 == 0) ? "Accepted\n" : "Rejected\n");
    return 0;
}
```
# 5
```
%{
#include <stdio.h>
int wordCount = 0;
int lineCount = 0;
%}
%%
[a-zA-Z]+   { wordCount++; }
\n          { lineCount++; }
.           { /* ignore other characters */ }
%%
int main() {
    yylex();
    printf("Number of words: %d\n", wordCount);
    printf("Number of lines: %d\n", lineCount);
    return 0;
}
```
# 6
```c
#include<stdio.h>
#include<string.h>
#define M 100
char s[M];
int i, l;
int E(), EP(), T(), TP(), F();
int main() {
    printf("\nRDP grammar: E->TE', EP->+TE' |@, T->FT', TP->*FT' | @, F->(E) | id\nEnter string: ");
    scanf("%s", s);
    i = 0;
    l = strlen(s);
    if (E() && (i == l)) printf("\nAccepted\n");
    else printf("\nNot Accepted\n");
    return 0;
}
int E() { return T() && EP(); }
int EP() { return (s[i] == '+' && ++i && T() && EP()) || 1; }
int T() { return F() && TP(); }
int TP() { return (s[i] == '*' && ++i && F() && TP()) || 1; }
int F() { return (s[i] == '(' && ++i && E() && (s[i++] == ')')) || (s[i] == 'i' && s[i + 1] == 'd' && (i += 2, 1)); }
```
#7
```c
#include <stdio.h>
#include <string.h>
#define MAX_INPUT_LENGTH 100
char input[MAX_INPUT_LENGTH];
int i, len;
int S();
int L();
int LP();
int main() {
    printf("\n The RDP grammar is\n S -> (L)  \n S -> a  \n L -> L, S   \n L -> S\n Enter the string to be parsed: ");
    scanf("%s", input);
    i = 0;
    len = strlen(input);
    if (S() && (input[i] == '\0')) {
        printf("\n String is accepted\n");
    } else {
        printf("\n String is not accepted\n");
    }
    return 0;
}
int L() {
    if (S() && LP()) {
        return 1;
    } else {
        return 0;
    }
}
int LP() {
    if (input[i] == ',') {
        i++;
        L();
    } else {
        return 1;
    }
}
int S() {
    if (input[i] == '(') {
        i++;
        if (L()) {
            if (input[i] == ')') {
                i++;
                return 1;
            } else {
                return 0;
            }
        }
    } else if (input[i] == 'a') {
        i++;
        return 1;
    } else {
        return 0;
    }
}
```
# 8
```c
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char getNextToken(const char **input) {
    return *(*input)++;
}

void addToFirstSet(char firstSet[], char symbol) {
    int i;
    for (i = 0; firstSet[i] != '\0'; ++i) {
        if (firstSet[i] == symbol) {
            return;
        }
    }
    firstSet[i] = symbol;
    firstSet[i + 1] = '\0';
}

void first_E(const char **input, char firstSet[]);
void first_T(const char **input, char firstSet[]);
void first_F(const char **input, char firstSet[]);

void first_T(const char **input, char firstSet[]) {
    char token = getNextToken(input);

    if (isalpha(token) || token == '(') {
        addToFirstSet(firstSet, token);
    }
}

void first_F(const char **input, char firstSet[]) {
    char token = getNextToken(input);

    if (isalpha(token) || token == '(') {
        addToFirstSet(firstSet, token);
    }
}

void first_E(const char **input, char firstSet[]) {
    first_T(input, firstSet);
}

void printFirstSet(char nonTerminal, char firstSet[]) {
    printf("First(%c) = {", nonTerminal);
    for (int i = 0; firstSet[i] != '\0'; ++i) {
        printf(" %c", firstSet[i]);
        if (firstSet[i + 1] != '\0') {
            printf(",");
        }
    }
    printf(" }\n");
}

int main() {
    const char *inputString = "id+id*id";
    const char *input = inputString;

    char firstSetE[100] = "";
    first_E(&input, firstSetE);
    printFirstSet('E', firstSetE);

    return 0;
}
```
