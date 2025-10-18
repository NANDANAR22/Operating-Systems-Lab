#include<stdio.h>

struct Process
{
  int pid, AT, BT, ST, CT, TAT, WT;
} P[20];

void main ()
{
  float totalTAT = 0, totalWT = 0;
  int i, n, current_time = 0, completed = 0, prev = 0;
  int is_completed[20];
  for(i = 0; i < n; i++) 
  {
    is_completed[i] = 0;
  }
  

  printf ("Enter the number of processes= ");
  scanf ("%d", &n);

  printf ("Enter the process id,arrival time & burst time of each process:\n");
  for (i = 0; i < n; i++)
	{
	  scanf ("%d%d%d", &P[i].pid, &P[i].AT, &P[i].BT);
	}

  while (completed != n)
	{
	  int idx = -1;
	  int mn = 10000000;
	  for (i = 0; i < n; i++)
	  {
		    if (P[i].AT <= current_time && is_completed[i] == 0)
			{
			  if (P[i].BT < mn)
				{
				  mn = P[i].BT;
				  idx = i;
				}
			  if (P[i].BT == mn)
				{
				  if (P[i].AT < P[idx].AT)
					{
					  mn = P[i].BT;
					  idx = i;
					}
				}
			}
		}

	    if (idx != -1)
    	{
	    	  P[idx].ST = current_time;
	    	  P[idx].CT = P[idx].ST + P[idx].BT;
	    	  P[idx].TAT = P[idx].CT - P[idx].AT;
		      P[idx].WT = P[idx].TAT - P[idx].BT;
		  
		      totalTAT = totalTAT + P[idx].TAT;
		      totalWT = totalWT + P[idx].WT;
		  
		      is_completed[idx] = 1;
		      completed++;
		      current_time = P[idx].CT;
		      prev = current_time;
     	}
	    else
	    {
	        current_time++;
	    }
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",P[i].pid,P[i].AT,P[i].BT,P[i].CT,P[i].TAT,P[i].WT);
    }
    printf("Average TAT = %f\n",totalTAT/n);
    printf("Average WT = %f\n",totalWT/n);
}    


