#include <stdio.h>
void main() {
    int burst_time[10], remaining_time[10], wait_time[10], turnaround_time[10];
    int n, time_quantum, total_time = 0;
    float avg_wait_time = 0.0, avg_turnaround_time = 0.0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time for processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                int execution_time = remaining_time[i] < time_quantum ? remaining_time[i] : time_quantum;
                remaining_time[i] -= execution_time;
                total_time += execution_time;
                turnaround_time[i] = total_time;
                wait_time[i] = turnaround_time[i] - burst_time[i];
            }
        }
        if (done)
            break;
    }
    for (int i = 0; i < n; i++) {
        avg_wait_time += wait_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;
    printf("\nProcess\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], wait_time[i], turnaround_time[i]);
    }
    printf("Avg Wait Time: %.2f\n", avg_wait_time);
    printf("Avg Turnaround Time: %.2f\n", avg_turnaround_time);
}