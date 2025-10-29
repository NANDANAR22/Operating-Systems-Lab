#include <stdio.h>

void main() 
{
    int n,f,rs[50],m[10],count[10],pf,i,j,flag;
    
    printf("Enter the number of pages= ");
    scanf("%d",&n);
    
    printf("Enter the reference page string:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
    }
    
    printf("Enter the number of frames= ");
    scanf("%d",&f);
    
    for(i=0;i<f;i++)
    {
        m[i]=-1;
        count[i] = 0;
    }

    printf("----LFU PAGE REPLACEMENT ALGORITHM IS----\n");
    for ( i = 0; i < n; i++) 
    {
        flag = 0;

        for ( j = 0; j < f; j++) //page hit
        {
            if (m[j] == rs[i]) 
            {
                flag = 1;
                count[j]++;
                break;
            }
        }

        if (flag == 0) //page fault
        {
            int least = 0;
            for (j = 1; j < f; j++) 
            {
                if (count[j] < count[least]) 
                {
                    least = j;
                }
            }

            m[least] = rs[i];
            if (count[least] == 0) 
            {
                count[least] = 1;
            } 
            else 
            {
                count[least] += 1;
            }
            pf++;
        }

        // Print the current state of the frames
        for(j=0;j<f;j++)
        {
            if(m[j]==-1)
            {
               printf("\t_");
            }   
            else
            {
                printf("\t%d",m[j]);
            }
        }
        if(flag == 0 )
        {
            printf("\tMiss");
        }
        printf("\n");
    }

    printf("The number of page faults: %d\n", pf);
    printf("The number of page hits:%d\n",n-pf);
    
}