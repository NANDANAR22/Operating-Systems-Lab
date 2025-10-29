#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int n,RQ[100],i,initial,totalHeadMovement=0;
   
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the requests sequence: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&RQ[i]);
    }
   
    printf("Enter the initial Head position: ");
    scanf("%d",&initial);
    printf("\n%d",initial);
    for( i=0;i<n;i++)
    {
        totalHeadMovement = totalHeadMovement + abs(RQ[i] - initial);
        initial = RQ[i];
        printf(" -> %d ",RQ[i]);
    }
    
    printf("\n\nTotal Head Movements: %d\n",totalHeadMovement);
    return 0;
}




