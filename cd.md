```c
#include <stdio.h>
int main()
{
    int input[10], i, n, ch;
    printf("Enter length of input: ");
    scanf("%d", &n);
    printf("Enter input: ");
    for(i = 0; i < n; i++)
        scanf("%d", &input[i]);
    ch,i = 0;
    i = 0;
    do{
        switch(input[i]){
            case 0: 
            case 1: 
                ch ^= input[i];
                break;
            default:
                printf("Invalid binary input\n");
                return 1;
        }
        i++;
    }
    while(i < n);
    if(ch == 0)
        printf("Entered number is an even binary number\n");
    else
        printf("Input is not an even binary number\n");
    return 0;
}
```
```c
#include <stdio.h>
#include <string.h>
int isAccepted(char input[]) {
    int len = strlen(input);
    if (len < 3) return 0;
    for (int i = 0; i < len; i++)
        if (input[i] != 'a' && input[i] != 'b') return 0;
    return input[len - 3] == 'a';
}
int main() {
    char input[100];
    printf("Enter a string of 'a's and 'b's: ");
    scanf("%99s", input);
    if (isAccepted(input)) printf("String accepted!\n");
    else printf("String rejected!\n");
    return 0;
}
```
```c
#include <stdio.h>
int main(){
    int input[10], i, n, ch;
    printf("Enter length of input: ");
    scanf("%d", &n);
    printf("Enter input: ");
    for(i = 0; i < n; i++)
        scanf("%d", &input[i]);
    ch = 0;
    i = 0;
    do{
        switch(ch){
            case 0: 
                if(input[i] == 0)
                    ch = 1;
                else
                    ch = 0;
                break;
            case 1: 
                if(input[i] == 0)
                    ch = 2;
                else
                    ch = 0;
                break;
            case 2: 
                if(input[i] == 1)
                    ch = 0;
                break;
        }
        i++;
    }
    while(i < n);
    if(ch == 2)
        printf("Input accepted\n");
    else
        printf("Input not accepted\n");
    return 0;
}
```
```c
#include <stdio.h>
#include <stdbool.h>
bool isAccepted(const char *input) {
    int state = 0;
    int countA = 0;
    int countB = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        char symbol = input[i];
        switch (state) {
            case 0:
                if (symbol == 'a') {
                    state = 1;
                    countA++;
                } else if (symbol == 'b') {
                    state = 2;
                    countB++;
                } else {
                    return false;
                }
                break;
            case 1:
                if (symbol == 'a') {
                    state = 2;
                    countA++;
                } else if (symbol == 'b') {
                    state = 1;
                    countB++;
                } else {
                    return false;
                }
                break;
            case 2:
                if (symbol == 'a') {
                    state = 0;
                    countA++;
                } else if (symbol == 'b') {
                    state = 2;
                    countB++;
                } else {
                    return false;
                }
                break;
        }
    }
    return state == 0 && countA % 3 == 0 && countB % 2 == 0;
}
int main() {
    char input[100];
    printf("Enter a string of 'a's and 'b's: ");
    scanf("%s", input);
    if (isAccepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Not accepted\n");
    }
    return 0;
}
```
```c
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
```c
#include<stdio.h>
#include<string.h>
#define MAX_INPUT_LENGTH 100
char input[MAX_INPUT_LENGTH];
int i, len;
int E();
int EP();
int T();
int TP();
int F();
int main() {
    printf("\n The RDP grammar is\n E->TEP \n EP->+TEP |@ \n T->FTP \n TP->*FTP | @ \n F->(E) | id\n Enter the string to be parsed: ");
    scanf("%s", input);
    i = 0;
    len = strlen(input);
    if (E() && (i == len))
        printf("\nString is accepted\n");
    else
        printf("\nString is not accepted\n");
    return 0;
}
int E() {
    if (T() && EP())
        return 1;
    else
        return 0;
}
int EP() {
    if (input[i] == '+') {
        i++;
        if (T() && EP())
            return 1;
        else
            return 0;
    } else
        return 1;
}
int T() {
    if (F() && TP())
        return 1;
    else
        return 0;
}
int TP() {
    if (input[i] == '*') {
        i++;
        if (F() && TP())
            return 1;
        else
            return 0;
    } else
        return 1;
}
int F() {
    if (input[i] == '(') {
        i++;
        if (E()) {
            if (input[i] == ')') {
                i++;
                return 1;
            } else
                return 0;
        }
    } else if (input[i] == 'i' && input[i + 1] == 'd') {
        i += 2;
        return 1;
    } else
        return 0;
}
```
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
        if (S() && LP()) {
            return 1;
        } else {
            return 0;
        }
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
