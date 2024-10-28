#include <stdio.h>
#include <stdbool.h>

#define N 4 // Number of men and women (you can change this value)

bool prefersNewManOverCurrent(int preference[N][N], int woman, int newMan, int currentMan) {
    for (int i = 0; i < N; i++) {
        // If the new man is ranked higher than the current man, she prefers the new man
        if (preference[woman][i] == newMan)
            return true;
        // If the current man is ranked higher, she prefers the current man
        if (preference[woman][i] == currentMan)
            return false;
    }
    return false; // Default return to avoid warnings
}

void stableMarriage(int menPref[N][N], int womenPref[N][N]) {
    int partnerOfWoman[N]; // Store partners of women (partnerOfWoman[i] is the partner of woman i)
    bool menFree[N];        // True if man is free, false otherwise

    for (int i = 0; i < N; i++) {
        partnerOfWoman[i] = -1; // Initialize all women as free
        menFree[i] = false;     // Initialize all men as free
    }

    int freeCount = N; // Count of free men

    // While there are free men
    while (freeCount > 0) {
        int man;

        // Find the first free man
        for (man = 0; man < N; man++)
            if (!menFree[man])
                break;

        // Go through the man's preference list
        for (int i = 0; i < N && !menFree[man]; i++) {
            int woman = menPref[man][i];

            // If the woman is free, engage her with the man
            if (partnerOfWoman[woman] == -1) {
                partnerOfWoman[woman] = man;
                menFree[man] = true;
                freeCount--;
            } else {
                // If the woman is already engaged, check if she prefers the new man
                int currentPartner = partnerOfWoman[woman];
                if (prefersNewManOverCurrent(womenPref, woman, man, currentPartner)) {
                    partnerOfWoman[woman] = man;
                    menFree[man] = true;
                    menFree[currentPartner] = false;
                }
            }
        }
    }

    // Print the final pairs
    printf("Woman\tMan\n");
    for (int i = 0; i < N; i++)
        printf("%d\t%d\n", i, partnerOfWoman[i]);
}

int main() {
    // Men's preferences (menPref[man][i] is the ith choice of the man)
    int menPref[N][N] = {
        {0, 1, 2, 3},
        {3, 2, 1, 0},
        {1, 0, 3, 2},
        {0, 2, 3, 1}
    };

    // Women's preferences (womenPref[woman][i] is the ith choice of the woman)
    int womenPref[N][N] = {
        {2, 1, 3, 0},
        {0, 1, 2, 3},
        {1, 2, 0, 3},
        {0, 2, 1, 3}
    };

    stableMarriage(menPref, womenPref);
    return 0;
}
