#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,j,n,size,initial,move,rq[20],Totalheadmovement=0;
    
    printf("Enter the number of requests: ");
    scanf("%d",&n);
    printf("Enter the Requests: ");
    for( i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d",&initial);
    
    printf("Enter the total disk size: ");
    scanf("%d",&size); 
    
    printf("Enter the direction to move first from the initial head position(high=1,low=0): ");
    scanf("%d",&move);

    for( i=1;i<n;i++) //Bubble sort
    {                    
        for( j=0;j<n-i;j++)
        {
             if(rq[j]>rq[j+1])
             {
                int temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
             }
        }
    }

    int index;
    for( i=0;i<n;i++)
    {
        if(initial<rq[i])
        {
            index=i;
            break;
        }
    }
    
    printf("\n%d->",initial);
    if(move==1) //towards high
    {
        for(i=index;i<n;i++)
        {
            printf("%d->",rq[i]);
            Totalheadmovement+=abs(rq[i]-initial);
            initial=rq[i];
        }
        printf("%d",size-1);
        Totalheadmovement+=abs(size-rq[i-1]-1);
        Totalheadmovement+=abs(size-1-0);
        initial=0;
        printf("->0");
        for( i=0;i<index;i++)
        {
            printf("->%d",rq[i]);
            Totalheadmovement+=abs(rq[i]-initial);
            initial=rq[i];
        }
        
    }
    else
    {
        for(i=index-1;i>=0;i--)
        {
            printf("%d->",rq[i]);
            Totalheadmovement+=abs(rq[i]-initial);
            initial=rq[i];
        }
        printf("0->");
        printf("%d",size-1);
        Totalheadmovement+=abs(rq[i+1]-0);
        Totalheadmovement+=abs(size-1-0);
        initial=size-1; 
        for( i=n-1;i>=index;i--)
        {
            printf("->%d",rq[i]);
            Totalheadmovement+=abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("\n\nTotal head movement is:%d",Totalheadmovement);
}
