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