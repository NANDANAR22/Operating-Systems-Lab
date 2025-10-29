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
    struct Block temp;
    
    printf("Enter the number of blocks:");
    scanf("%d",&m);
    
    printf("Enter the id & size of each blocks:\n");
    for(j=1;j<=m;j++)
    {
        scanf("%d%d",&B[j].id,&B[j].size);
        B[j].alloc = -1;
    }
    
    printf("Enter the number of processes:");
    scanf("%d",&n);
    
    printf("Enter the id & size of each process:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&P[i].id,&P[i].size);
        P[i].blkno = -1;
    }
    
    for(i=1;i<m;i++)
    {
        for(j=1;j<m-i;j++)
        {
            if( B[j].size > B[j+1].size )
            {
                temp = B[j];
                B[j] = B[j+1];
                B[j+1] = temp;
            }
        }
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
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
    for(i=1;i<=n;i++)
    {
        printf("%d\t%d\n",P[i].id,P[i].blkno);
    }
}




