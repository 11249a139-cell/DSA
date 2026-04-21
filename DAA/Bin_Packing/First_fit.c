/*
Objective:
Implement the First Fit bin packing approach, where each item
is assigned to the earliest bin that can accommodate it.
*/

#include <stdio.h>

// Function to execute First Fit method
void applyFirstFit(int sizes[], int totalItems, int maxCapacity)
{
    int remaining[totalItems];   // Tracks available space in bins
    int binsUsed = 0;

    // Set all bins to full capacity initially
    for (int i = 0; i < totalItems; i++)
    {
        remaining[i] = maxCapacity;
    }

    // Process each item one by one
    for (int i = 0; i < totalItems; i++)
    {
        int isPlaced = 0;

        // Check existing bins for placement
        for (int j = 0; j < binsUsed; j++)
        {
            if (remaining[j] >= sizes[i])
            {
                remaining[j] -= sizes[i];
                printf("Item %d with size %d placed in bin %d\n",
                       i + 1, sizes[i], j + 1);
                isPlaced = 1;
                break;
            }
        }

        // If no suitable bin is found, open a new bin
        if (!isPlaced)
        {
            remaining[binsUsed] = maxCapacity - sizes[i];
            printf("Item %d with size %d placed in new bin %d\n",
                   i + 1, sizes[i], binsUsed + 1);
            binsUsed++;
        }
    }

    printf("Total number of bins used: %d\n", binsUsed);
}

int main()
{
    int n, capacity;

    printf("Enter total items count: ");
    scanf("%d", &n);

    int items[n];

    printf("Enter capacity of each bin: ");
    scanf("%d", &capacity);

    printf("Enter sizes of the items:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Size for item %d: ", i + 1);
        scanf("%d", &items[i]);

        // Ensure item fits within capacity
        if (items[i] > capacity)
        {
            printf("Error: Size exceeds bin capacity. Try again.\n");
            i--; // repeat entry for same index
        }
    }

    applyFirstFit(items, n, capacity);

    return 0;
}
