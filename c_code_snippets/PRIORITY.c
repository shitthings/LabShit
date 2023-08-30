#include <stdio.h>
void main() {
    int n, burst[10], process[10], wait[10] = {0}, priority[10];
    float total_wait = 0, total_turnaround = 0, avg_wait, avg_turnaround;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter process id, burst time, and priority for process %d: ", i);
        scanf("%d %d %d", &process[i], &burst[i], &priority[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (priority[i] >= priority[j]) {
                int temp_burst = burst[i], temp_process = process[i], temp_priority = priority[i];
                burst[i] = burst[j], process[i] = process[j], priority[i] = priority[j];
                burst[j] = temp_burst, process[j] = temp_process, priority[j] = temp_priority;
            }
        }
        wait[i] = wait[i - 1] + burst[i - 1];
        total_wait += wait[i];
        total_turnaround += wait[i] + burst[i];
    }
    avg_wait = total_wait / n, avg_turnaround = total_turnaround / n;
    printf("\nPID\tBurst Time\tWait Time\tPriority\tTurnaround Time\n");
    for (int i = 1; i <= n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", process[i], burst[i], wait[i], priority[i], wait[i] + burst[i]);
    printf("Average Waiting Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
}
