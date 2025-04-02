#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int type;
} Process;

void sort_by_arrival(Process queue[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (queue[j].arrival_time > queue[j + 1].arrival_time) {
                Process temp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = temp;
            }
        }
    }
}

void fcfs_scheduling(Process queue[], int n) {
    int wait_time = 0, turn_around_time = 0, completion_time = 0;
    int total_wait_time = 0, total_turn_around_time = 0;

    printf("\nProcess Execution Order:\n");
    for (int i = 0; i < n; i++) {
        if (completion_time < queue[i].arrival_time) {
            completion_time = queue[i].arrival_time;
        }
        wait_time = completion_time - queue[i].arrival_time;
        completion_time += queue[i].burst_time;
        turn_around_time = completion_time - queue[i].arrival_time;

        total_wait_time += wait_time;
        total_turn_around_time += turn_around_time;

        printf("Process %d | Arrival Time: %d | Burst Time: %d | Waiting Time: %d | Turnaround Time: %d\n",
                queue[i].pid, queue[i].arrival_time, queue[i].burst_time, wait_time, turn_around_time);
    }

    if (n > 0) {
        printf("\nOverall Average Waiting Time: %.2f\n", (float)total_wait_time / n);
        printf("Overall Average Turnaround Time: %.2f\n", (float)turn_around_time / n);
    }
}

int main(){
    Process process_queue[MAX_PROCESSES];
    int total_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &total_processes);

    for (int i = 0; i < total_processes; i++) {
        Process p;
        printf("Enter Process ID, Arrival Time, Burst Time, and Type (0 for System, 1 for User): ");
        scanf("%d %d %d %d", &p.pid, &p.arrival_time, &p.burst_time, &p.type);
        process_queue[i] = p;
    }

    sort_by_arrival(process_queue, total_processes);

    Process sorted_queue[MAX_PROCESSES];
    int index = 0;

    for (int i = 0; i < total_processes; i++) {
        if (process_queue[i].type == 0) {
            sorted_queue[index++] = process_queue[i];
        }
    }
    for (int i = 0; i < total_processes; i++) {
        if (process_queue[i].type == 1) {
            sorted_queue[index++] = process_queue[i];
        }
    }

    printf("\nExecuting Processes (FCFS Scheduling with System Priority)\n");
    fcfs_scheduling(sorted_queue, total_processes);

    return 0;
}

