```c
#include <stdio.h>
#include <string.h>
int main() {
    char frame[50][50], str[50][50];
    char flag[10];
    strcpy(flag, "flag");
    char esc[10];
    strcpy(esc, "esc");
    int i, j, k = 0, n;
    strcpy(frame[k++], "flag");
    printf("Enter length of String : ");
    scanf("%d", &n);
    printf("Enter the String: ");
    for (i = 0; i <= n; i++) {// Use fgets instead of gets to avoid buffer overflow
        fgets(str[i], sizeof(str[i]), stdin);
        str[i][strcspn(str[i], "\n")] = '\0'; // Remove newline character
    }
    printf("\nYou entered : ");
    for (i = 0; i <= n; i++) {
        puts(str[i]);
    }
    printf("\n");
    for (i = 1; i <= n; i++) {
        if (strcmp(str[i], flag) != 0 && strcmp(str[i], esc) != 0) {
            strcpy(frame[k++], str[i]);
        } else {
            strcpy(frame[k++], "esc");
            strcpy(frame[k++], str[i]);
        }
    }
    strcpy(frame[k++], "flag");
    printf("------------------------------\n");
    printf("Byte stuffing at sender side:\n");
    printf("------------------------------\n");
    for (i = 0; i < k; i++) {
        printf("%s\t", frame[i]);
    }
    return 0;
}
```
```c
#include <stdio.h>
#include <string.h>
int main() {
    char data[100], stuffedData[200];
    int i, count = 0, j = 0;
    printf("Enter the data: ");
    scanf("%s", data);
    for(i = 0; i < strlen(data); i++) {
        if(data[i] == '1') {
            count++;
            stuffedData[j++] = data[i];
        } else {
            count = 0;
            stuffedData[j++] = data[i];
        }
        if(count == 5) {
            count = 0;
            stuffedData[j++] = '0';
        }
    }
    stuffedData[j] = '\0';
    printf("Data after bit stuffing: %s\n", stuffedData);
    return 0;
}
```
```c
#include <stdio.h>
int main(){
int w,i,f,frames[50];
printf("Enter window size: ");
scanf("%d",&w);
printf("\nEnter number of frames to transmit: ");
scanf("%d",&f);
printf("\nEnter %d frames: ",f);
for(i=1;i<=f;i++){scanf("%d",&frames[i]);}
printf("\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n",w);
for(i=1;i<=f;i++){
if(i%w-0){
printf("%d\n",frames[i]);
printf("Acknowledgement of above frames sent is received by sender\n\n");
}else{
printf("%d ",frames[i]);}
}
if(f%w!=0)
printf("\nAcknowledgement of above frames sent is received by sender\n");
return 0;}
```
