#include<stdio.h>

void main()
{
    int i,n,sum;
    int AT[10]={0},BT[10]={0},CT[10]={0},TAT[10]={0},WT[10]={0};
    float totalTAT=0,totalWT=0;
    
    printf("Enter the number of processes= ");
    scanf("%d",&n);
    
    printf("Enter arrival time and burst time of each process=\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&AT[i],&BT[i]);
    }
    
    sum = AT[0];
    for(i=0;i<n;i++)
    {
        sum = sum + BT[i];
        
        CT[i] = sum;
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        
        totalTAT = totalTAT + TAT[i];
        totalWT = totalWT + WT[i];
    }
    
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,AT[i],BT[i],CT[i],TAT[i],WT[i]);
    }
    printf("Average TAT= %f\n",totalTAT/n);
    printf("Average WT= %f\n",totalWT/n);
}