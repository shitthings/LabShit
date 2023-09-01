#include <stdio.h>
#define MAX 100
typedef struct Job {
    char id[5];
    int deadline;
    int profit;
} Job;
void jobSequencingWithDeadline(Job jobs[], int n);
int minValue(int x, int y) {
    return (x < y) ? x : y;
}

int main(void) {
    Job jobs[5] = {
        {"j1", 2, 30},
        {"j2", 1, 120},
        {"j3", 1, 80},
        {"j4", 3, 40},
        {"j5", 4, 50}
    };
    Job temp;
    int n = 5;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (jobs[j+1].profit > jobs[j].profit) {
                temp = jobs[j+1];
                jobs[j+1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for (int i = 0; i < n; i++) {
        printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }
    jobSequencingWithDeadline(jobs, n);
    return 0;
}
void jobSequencingWithDeadline(Job jobs[], int n) {
    int timeslot[MAX];
    int filledTimeSlot = 0;
    int dmax = 0;
    int maxprofit = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > dmax) {
            dmax = jobs[i].deadline;
        }
    }
    for (int i = 1; i <= dmax; i++) {
        timeslot[i] = -1;
    }
    printf("dmax: %d\n", dmax);
    for (int i = 1; i <= n; i++) {
        int k = minValue(dmax, jobs[i - 1].deadline);
        while (k >= 1) {
            if (timeslot[k] == -1) {
                timeslot[k] = i - 1;
                filledTimeSlot++;
                break;
            }
            k--;
        }
        if (filledTimeSlot == dmax) {
            break;
        }
    }
    printf("\nRequired Jobs: ");
    for (int i = 1; i <= dmax; i++) {
        printf("%s", jobs[timeslot[i]].id);
        if (i < dmax) {
            printf(" --> ");
        }
    }
    for (int i = 1; i <= dmax; i++) {
        maxprofit += jobs[timeslot[i]].profit;
    }
    printf("\nMax Profit: %d\n", maxprofit);
}