#include <stdio.h>

struct Block
{
    int id,size,alloc;
}B[10];

struct Process
{
    int id,size,blkno;
}P[10];

void main()
{
    int i,j,n,m;
    
    printf("Enter the number of blocks:");
    scanf("%d",&m);
    
    printf("Enter the id & size of each blocks:\n");
    for(j=0;j<m;j++)
    {
        scanf("%d%d",&B[j].id,&B[j].size);
        B[j].alloc = -1;
    }
    
    printf("Enter the number of processes:");
    scanf("%d",&n);
    
    printf("Enter the id & size of each process:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&P[i].id,&P[i].size);
        P[i].blkno = -1;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if( B[j].alloc == -1 && B[j].size >= P[i].size )
            {
                P[i].blkno = B[j].id;
                B[j].alloc = 1;
                break;
            }
        }
    }
    
    printf("Process\tBlock\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\n",P[i].id,P[i].blkno);
    }
}




