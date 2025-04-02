#include<stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], i, p[20], j, temp;
    float wtavg = 0;
    float tatavg = 0;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        wtavg += wt[i];
    }
    for(i=0;i<n;i++){
        tat[i]=tat[i-1]+bt[i];
        tatavg+=tat[i];
    }

    tatavg /= n;
    wtavg /= n;

    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage WT = %.2f\n", wtavg);
    printf("Average TAT = %.2f\n", tatavg);

    return 0;
}
