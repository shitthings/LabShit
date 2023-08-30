# Question 1
## Round robin

```c
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
```

## Shortest job First
```c
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
```

## First Come First Serve
```c
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
```

## Priority Scheduling
```c
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
```

## First In First Out
```c
#include <stdio.h>
void display(int fr[], int f) {
    for (int i = 0; i < f; i++) {
        printf("%d ", fr[i]);
    }
    printf("\n");
}
int main() {
    int pg[20], fr[20], n, f, pf = 0, index = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    printf("Enter the page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pg[i]);
    }
    for (int i = 0; i < f; i++) {
        fr[i] = -1;
    }
    for (int j = 0; j < n; j++) {
        int flag = 0;
        for (int i = 0; i < f; i++) {
            if (fr[i] == pg[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            fr[index] = pg[j];
            index = (index + 1) % f;
            pf++;
            display(fr, f);
        }
    }
    printf("Number of page faults: %d\n", pf);
}
```


## LRU
```c
#include <stdio.h>
int main() {
    int frames, pages, pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    int frameArray[frames];
    int pageArray[pages];
    for (int i = 0; i < frames; i++) {
        frameArray[i] = -1;
    }
    printf("Enter the sequence of pages: ");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &pageArray[i]);
    }
    for (int i = 0; i < pages; i++) {
        int page = pageArray[i];
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frameArray[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int replaceIndex = 0;
            int minIndex = i;
            for (int j = 0; j < frames; j++) {
                int k = i - 1;
                while (k >= 0) {
                    if (frameArray[j] == pageArray[k])
                        break;
                    k--;
                }
                if (k < minIndex) {
                    minIndex = k;
                    replaceIndex = j;
                }
            }
            frameArray[replaceIndex] = page;
            pageFaults++;
        }
        printf("\nPage %d: ", page);
        for (int j = 0; j < frames; j++) {
            if (frameArray[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frameArray[j]);
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
}
```
## Optimal Page replacement
```c
#include <stdio.h>
int main() {
    int frames, pages, pageFaults = 0;
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    printf("Enter the number of pages: ");
    scanf("%d", &pages);
    int frameArray[frames];
    for (int i = 0; i < frames; i++) {
        frameArray[i] = -1;
    }
    printf("Enter the sequence of pages: ");
    for (int i = 0; i < pages; i++) {
        scanf("%d", &pageArray[i]);
    }
    for (int i = 0; i < pages; i++) {
        int page = pageArray[i];
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frameArray[j] == page) {
                found = 1;
                break;
            }
        }
        if (!found) {
            int replaceIndex = 0;
            int farthestIndex = i;
            for (int j = 0; j < frames; j++) {
                int k = i + 1;
                while (k < pages) {
                    if (frameArray[j] == pageArray[k])
                        break;
                    k++;
                }
                if (k > farthestIndex) {
                    farthestIndex = k;
                    replaceIndex = j;
                }
            }
            frameArray[replaceIndex] = page;
            pageFaults++;
        }
        printf("\nPage %d: ", page);
        for (int j = 0; j < frames; j++) {
            if (frameArray[j] == -1)
                printf(" - ");
            else
                printf(" %d ", frameArray[j]);
        }
    }
    printf("\nTotal Page Faults: %d\n", pageFaults);
}
```

---
# Question 2

## Sequential File Allocation
```c
#include <stdio.h>
int main() {
    int num_files, blocks[20], start_blocks[20], track[20], allocation[20][20];
    printf("Enter the number of files: ");
    scanf("%d", &num_files);
    for (int i = 0; i < num_files; i++) {
        printf("Enter the number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &blocks[i]);
        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &start_blocks[i]);
        track[i] = start_blocks[i];
        for (int j = 0; j < blocks[i]; j++)
            allocation[i][j] = start_blocks[i]++;
    }
    printf("Filename\tStart block\tLength\n");
    for (int i = 0; i < num_files; i++)
        printf("%d\t\t%d\t\t%d\n", i + 1, track[i], blocks[i]);
}
```


## Indexed File Allocation
```c
#include <stdio.h>
int main() {
    int n, m[20], sb[20], s[20], b[20][20];
    printf("Enter number of files: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter starting block and size of file %d: ", i + 1);
        scanf("%d %d", &sb[i], &s[i]);
        printf("Enter blocks occupied by file %d: ", i + 1);
        scanf("%d", &m[i]);
        printf("Enter blocks of file %d: ", i + 1);
        for (int j = 0; j < m[i]; j++)
            scanf("%d", &b[i][j]);
    }
    printf("\nFile\tIndex\tLength\n");
    for (int i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
}
```

## Linked File Allocation
```c
#include <stdio.h>
struct file {
    char fname[10];
    int start, size, block[10];
};
int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    struct file f[10];
    for (int i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);
        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter number of blocks: ");
        scanf("%d", &f[i].size);
        printf("Enter block numbers: ");
        for (int j = 1; j <= f[i].size; j++) {
            scanf("%d", &f[i].block[j]);
        }
    }
    printf("File\tStart\tSize\tBlocks\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (int j = 1; j <= f[i].size; j++) {
            printf("--->%d", f[i].block[j]);
        }
        printf("\b\b  \n");
    }
}
```
## MVT
```c
#include <stdio.h>
void main() {
    int total_memory = 0, available_memory = 0, process_count = 0;
    printf("\nEnter the memory capacity: ");
    scanf("%d", &total_memory);
    available_memory = total_memory;
    printf("\nEnter the number of processes: ");
    scanf("%d", &process_count);
    for (int i = 0; i < process_count; i++) {
        int required_memory = 0;
        printf("\nEnter memory required for process %d: ", i + 1);
        scanf("%d", &required_memory);
        if (required_memory <= available_memory) {
            printf("Memory allocated for process %d is: %d\n", i + 1, required_memory);
            available_memory -= required_memory;
            printf("Remaining memory is: %d\n", available_memory);
        } else {
            printf("Memory is not allocated for process %d\n", i + 1);
        }
        printf("External fragmentation for this process is: %d\n", available_memory);
    }
}
```

## MFT
```c
#include <stdio.h>
int main() {
    int memory_size, partitions, partition_size, process_count;
    int allocated_memory[4], internal_fragmentation = 0, external_fragmentation = 0;
    printf("Enter the memory size: ");
    scanf("%d", &memory_size);
    printf("Enter the number of partitions: ");
    scanf("%d", &partitions);
    partition_size = memory_size / partitions;
    printf("Each partition size is: %d\n", partition_size);
    printf("Enter the number of processes: ");
    scanf("%d", &process_count);
    int remaining_memory = memory_size;
    for (int i = 0; i < process_count; i++) {
        printf("\nEnter the memory required for process %d: ", i + 1);
        scanf("%d", &allocated_memory[i]);
        if (allocated_memory[i] <= partition_size) {
            printf("Process is allocated in partition %d\n", i + 1);
            internal_fragmentation += partition_size - allocated_memory[i];
            remaining_memory -= partition_size;
        } else {
            printf("Process not allocated in partition %d\n", i + 1);
            int process_size = allocated_memory[i];
            while (process_size > partition_size) {
                process_size -= partition_size;
                remaining_memory -= partition_size;
            }
            external_fragmentation += partition_size - process_size;
            remaining_memory -= process_size;
            printf("External Fragmentation for this process is: %d\n", partition_size - process_size);
        }
    }
    printf("\nProcess\tAllocated Memory\n");
    for (int i = 0; i < process_count; i++)
        printf("%5d\t%5d\n", i + 1, allocated_memory[i]);
    int total_fragmentation = internal_fragmentation + external_fragmentation;
    printf("The total fragmentation is: %d\n", total_fragmentation);
}
```

## Deadlock avoidance
```c
#include <stdio.h>
#include <stdlib.h>
int main() {
    int Max[10][10], need[10][10], alloc[10][10], avail[10], completed[10], safeSequence[10];
    int p, r, i, j, process, count = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++)
        completed[i] = 0;
    printf("\nEnter the number of resources: ");
    scanf("%d", &r);
    for (i = 0; i < p; i++) {
        printf("\nFor process %d: ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }
    printf("\nEnter the allocation for each process: ");
    for (i = 0; i < p; i++) {
        printf("\nFor process %d: ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("\nEnter the available resources: ");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            need[i][j] = Max[i][j] - alloc[i][j];
    do {
        process = -1;
        for (i = 0; i < p; i++) {
            if (completed[i] == 0) {
                process = i;
                for (j = 0; j < r; j++) {
                    if (avail[j] < need[i][j]) {
                        process = -1;
                        break;
                    }
                }
            }
            if (process != -1)
                break;
        }
        if (process != -1) {
            safeSequence[count] = process + 1;
            count++;
            for (j = 0; j < r; j++) {
                avail[j] += alloc[process][j];
                alloc[process][j] = 0;
                Max[process][j] = 0;
                completed[process] = 1;
            }
        }
    } while (count != p && process != -1);
    if (count == p) {
        printf("\nThe system is in a safe state!!\n");
        printf("Safe Sequence: < ");
        for (i = 0; i < p; i++)
            printf("%d ", safeSequence[i]);
        printf(">\n");
    } else {
        printf("\nThe system is in an unsafe state!!\n");
    }
}
```

---
## simulate paging technique
```c
#include <stdio.h>
#define MAX 50
int main() {
    int page[MAX], n, f, ps, off, pno;
    printf("Enter the number of pages in memory: ");
    scanf("%d", &n);
    printf("Enter page size: ");
    scanf("%d", &ps);
    printf("Enter number of frames: ");
    scanf("%d", &f);
    for (int i = 0; i < n; i++)
        page[i] = -1;
    printf("\nEnter the page table\n");
    printf("(Enter frame no as -1 if that page is not present in any frame)\n\n");
    printf("pageno\tframeno\n-------\t-------");
    for (int i = 0; i < n; i++) {
        printf("\n\n%d\t\t", i);
        scanf("%d", &page[i]);
    }
    printf("\n\nEnter the logical address (i.e., page no & offset): ");
    scanf("%d%d", &pno, &off);

    if (page[pno] == -1)
        printf("\n\nThe required page is not available in any of the frames");
    else
        printf("\n\nPhysical address (i.e., frame no & offset): %d, %d", page[pno], off);
}
```


