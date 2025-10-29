#include <stdio.h>

int main()
{
    int i,j,k,n,rs[30],f,pf=0,m[10],count=0;
    
    printf("Enter the length of page string: ");
    scanf("%d",&n);
    
    printf("Enter the reference page string: ");
    for( i=0;i<n;i++ )
    {
      scanf("%d", &rs[i]);
    }
    
    printf("Enter the number of frames: ");
    scanf("%d",&f);

    for( i=0;i<f;i++) // initalizing all frames with -1
    {
        m[i] = -1;
    }
    
    printf("The FIFO Page Replacement Process is : \n");
    for( i=0;i<n;i++)
    {
        for(k=0;k<f;k++) 
        {
            if(m[k]==rs[i]) // checking for hit
            {
                break;
            }
        }

        if(k==f) // condition for page fault
        {
            m[count++] = rs[i];
            pf++;
        }
        for( j=0;j<f;j++) // for printf the current frame values
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
        if(k==f)
        {
            printf("\tMiss");
        }
        printf("\n");
        if(count==f)
        {
            count=0;
        }
    }
    printf("\n The number of Page faults: %d",pf);
    printf("\n The number of Hits: %d",n-pf);
}