#include<stdio.h>
#include<stdlib.h>

void main()
{

    int n,size,initial,move,rq[20],i,j,temp,Totalheadmovement=0;
    
    printf("Enter the number of requests:");
    scanf("%d",&n);
    printf("Enter the Requests:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&rq[i]);
    }
    
    printf("Enter the initial head position:");
    scanf("%d",&initial);
    
    printf("Enter the total disk size:");
    scanf("%d",&size);
    
    printf("Enter the direction to move first from the initial head position(high=1,low=0):");
    scanf("%d",&move);
    
    for(i=1;i<n;i++) //Bubble sort
    {
        for( j=0;j<n-i;j++)
        {
             if(rq[j]>rq[j+1])
             {
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
             }
        }
    }
    
    int index;
    for(int i=0;i<n;i++)
    {
        if(initial<rq[i])
        {
            index=i;
            break;
        }
    }
    printf("\n%d->",initial);
    if(move==1)//towards high
    {
        for(i=index;i<n;i++)
        {
            printf("%d->",rq[i]);
            Totalheadmovement += abs(rq[i]-initial);
            initial=rq[i];
        }
        printf("%d",size-1);
        Totalheadmovement+=abs(size-rq[i-1]-1);
        initial=size-1;
        for(i=index-1;i>=0;i--)
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
            Totalheadmovement += abs(rq[i]-initial);
            initial=rq[i];
        }
        printf("0");
        Totalheadmovement += abs(rq[i+1]-0);
        initial=0;
        for(i=index;i<n;i++)
        {
            printf("->%d",rq[i]);
            Totalheadmovement += abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("\n\nTotal head movement is:%d\n",Totalheadmovement);
}


