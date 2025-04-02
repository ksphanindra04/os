#include<stdio.h>
int main(){
    int n, bt[20], wt[20], tat[20], i;
    float wtavg=0;
    float tatavg=0;
    printf("Enter the total number of processors here:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Emter the burst time of the processor:");
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        wtavg+=wt[i];
    }
    for(i=0;i<n;i++){
        tat[i]=tat[i-1]+bt[i];
        tatavg+=tat[i];
    }
    tatavg/=n;
    wtavg/=n;

    printf("Processor\t Burst TIme\t Waiting Time\t TurnAroundtime\n");
    for(i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i+1,bt[i],wt[i],tat[i]);
    }
    printf("Average WT = %.2f", wtavg);
    printf("Average TAT = %.2f", tatavg);

}
