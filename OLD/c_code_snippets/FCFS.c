#include <stdio.h>
void main() {
    int n, burst[10], wait[10] = {0}, turnaround[10], total_wait = 0, total_turnaround = 0;
    float avg_wait, avg_turnaround;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &burst[i]);
    }
    for (int i = 1; i <= n; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
        total_wait += wait[i];
        turnaround[i] = wait[i] + burst[i];
        total_turnaround += turnaround[i];
    }
    avg_wait = (float) total_wait / n;
    avg_turnaround = (float) total_turnaround / n;
    printf("\nPID\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 1; i <= n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", i, burst[i], wait[i], turnaround[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}