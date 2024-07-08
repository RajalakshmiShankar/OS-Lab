#include <stdio.h>
#include <limits.h> // For INT_MAX

void priorityScheduling(int n, int p[], int bt[], int at[], int priority[], int rt_b[]);

int main() {
    int p[100], a[100], b[100], priority[100],rt_b[100];
    int n;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for the number of processes.\n");
        return 1;
    }

    printf("Enter process IDs:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter Arrival Times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter Burst Times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        rt_b[i] = b[i];
    }

    printf("Enter Priorities:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &priority[i]);
    }

    // Execute priority scheduling
    priorityScheduling(n, p, b, a, priority, rt_b);

    return 0;
}

void priorityScheduling(int n, int p[], int bt[], int at[], int priority[], int rt_b[]) {
    int wt[100], tat[100], ct[100];
    float total_wt = 0, total_tat = 0;

    int time = 0, completed = 0;

    while (completed != n) {
        int minPriorityProcess = -1;
        int minPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && priority[i] < minPriority && bt[i] > 0) {
                minPriority = priority[i];
                minPriorityProcess = i;
            }
        }

        if (minPriorityProcess == -1) {
            time++;
            continue;
        }

        ct[minPriorityProcess] = time + bt[minPriorityProcess];
        time += bt[minPriorityProcess];
        tat[minPriorityProcess] = ct[minPriorityProcess] - at[minPriorityProcess];
        wt[minPriorityProcess] = tat[minPriorityProcess] - bt[minPriorityProcess];

        total_wt += wt[minPriorityProcess];
        total_tat += tat[minPriorityProcess];

        bt[minPriorityProcess] = 0;

        completed++;
    }

    printf("Process\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTAT\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n", p[i], at[i], rt_b[i], priority[i], ct[i], tat[i], wt[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}