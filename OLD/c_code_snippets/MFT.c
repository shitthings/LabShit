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
