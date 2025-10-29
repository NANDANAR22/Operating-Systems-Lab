#include <stdio.h>

int findLFU(int freq[], int n) {
    int i, minimum = freq[0], pos = 0;

    for (i = 1; i < n; ++i) {
        if (freq[i] < minimum) {
            minimum = freq[i];
            pos = i;
        }
    }

    return pos;
}

int main() {
    int n, refst[10], frame[10], frameno, avail, count = 0, freq[10];

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
        freq[i] = 0;  // Initialize frequency array
    }

    printf("Output:\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t", refst[i]);

        avail = 0;

        for (int k = 0; k < frameno; k++) {
            if (frame[k] == refst[i]) { // if hit
                avail = 1;
                freq[k]++; // Increase frequency for the current page
                printf("Hit");
                break;
            }
        }

        if (avail == 0) { // if miss
            int pos = findLFU(freq, frameno);
            frame[pos] = refst[i];
            freq[pos] = 1; // Reset frequency for the new page
            count++;
            printf("Miss");
        }
        printf("\n");
    }

    printf("Page fault is %d\n", count);

    return 0;
}