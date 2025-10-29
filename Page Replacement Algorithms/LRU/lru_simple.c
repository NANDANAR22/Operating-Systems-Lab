#include <stdio.h>

int find(int time[], int frameno) {
    int minimum = time[0], pos = 0;
    for (int i = 1; i < frameno; i++) {  // Start from 1 instead of 0
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, refst[10], frame[10], avail, count = 0, frameno, time[10], counter = 0;

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
        time[i] = 0;
    }

    printf("Output:\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t", refst[i]);

        avail = 0;
        for (int k = 0; k < frameno; k++) {
            if (frame[k] == refst[i]) {
                avail = 1;
                counter++;
                time[k] = counter;
                printf("Hit");
                break;
            }
        }

        if (avail == 0) {
            int pos = find(time, frameno);
            frame[pos] = refst[i];
            counter++;
            time[pos] = counter;
            count++;
            printf("Miss");
        }

        printf("\n");
    }

    printf("Page fault is %d\n", count);

    return 0;
}
