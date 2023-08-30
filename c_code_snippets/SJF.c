#include <stdio.h>
int main() {
    int n, j, temp, temp1, pr[10], burst[10], wait[10], turn[10], process[10], i;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    for (i = 0; i < 10; i++) {
        burst[i] = 0;
        wait[i] = 0;
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
        process[i] = i;
    }
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (burst[i] > burst[j]) {
                temp = burst[i];
                temp1 = process[i];
                burst[i] = burst[j];
                process[i] = process[j];
                burst[j] = temp;
                process[j] = temp1;
            }
        }
    }
    wait[0] = 0;
    for (i = 0; i < n; i++)
        wait[i + 1] = wait[i] + burst[i];
    for (i = 0; i < n; i++) {
        turn[i] = wait[i] + burst[i];
        avg_waiting_time += wait[i];
        avg_turnaround_time += turn[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
        printf("P[%d]\t%d\t\t%d\n", process[i], wait[i], turn[i]);
    printf("Avg Waiting Time: %.2f\n", avg_waiting_time);
    printf("Avg Turnaround Time: %.2f\n", avg_turnaround_time);
}
