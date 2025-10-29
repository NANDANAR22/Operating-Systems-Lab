#include <stdio.h>

int main()
{
    int n, refst[10], frame[10], frameno, avail, count = 0;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &refst[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameno);

    for (int i = 0; i < frameno; i++) {
        frame[i] = -1;
    }

    printf("Output:\n");

    int j = 0;

    for (int i = 0; i < n; i++) {
        printf("%d\t\t", refst[i]);
        
        avail = 0;
        
        for (int k = 0; k < frameno; k++) {
            if (frame[k] == refst[i]) {
                avail = 1;
                printf("Hit");
                break;
            }
        }

        if(avail == 0){
            frame[j] = refst[i];
            j = (j + 1) % frameno;
            count++;
            printf("Miss");
        }
        
        printf("\n");
    }

    printf("Page fault is %d\n", count);

    return 0;
}