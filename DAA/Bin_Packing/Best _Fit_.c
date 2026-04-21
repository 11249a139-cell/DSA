/*
Objective:
Demonstrate the Best Fit bin packing technique, where every item
is assigned to the bin that results in the least remaining space.
*/

#include <stdio.h>

// Function to execute Best Fit strategy
void applyBestFit(int weights[], int totalItems, int maxCapacity)
{
    printf("\n=== Best Fit Strategy Execution ===\n");

    int remainingSpace[totalItems];   // Keeps track of free space in each bin
    int binsUsed = 0;

    // Initially, all bins have full capacity
    for (int i = 0; i < totalItems; i++)
    {
        remainingSpace[i] = maxCapacity;
    }

    // Iterate through each item
    for (int i = 0; i < totalItems; i++)
    {
        int selectedBin = -1;
        int leastSpaceLeft = maxCapacity + 1;

        // Search for the most suitable bin
        for (int j = 0; j < binsUsed; j++)
        {
            int spaceAfterPlacing = remainingSpace[j] - weights[i];

            if (spaceAfterPlacing >= 0 && spaceAfterPlacing < leastSpaceLeft)
            {
                selectedBin = j;
                leastSpaceLeft = spaceAfterPlacing;
            }
        }

        // If a matching bin is found
        if (selectedBin != -1)
        {
            remainingSpace[selectedBin] -= weights[i];
            printf("Placing item %d (weight %d) into bin %d\n",
                   i + 1, weights[i], selectedBin + 1);
        }
        else
        {
            // Allocate a new bin
            remainingSpace[binsUsed] = maxCapacity - weights[i];
            printf("Placing item %d (weight %d) into new bin %d\n",
                   i + 1, weights[i], binsUsed + 1);
            binsUsed++;
        }
    }

    printf("Number of bins used: %d\n", binsUsed);
}

int main()
{
    int n, capacity;

    printf("Input total number of items: ");
    scanf("%d", &n);

    int items[n];

    printf("Input maximum bin capacity: ");
    scanf("%d", &capacity);

    printf("Provide the sizes of items:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Size of item %d: ", i + 1);
        scanf("%d", &items[i]);

        // Validate input against capacity
        if (items[i] > capacity)
        {
            printf("Error: Item size exceeds capacity. Please re-enter.\n");
            i--; // redo input for this item
        }
    }

    applyBestFit(items, n, capacity);

    return 0;
}
