/*
Aim:
To solve the Travelling Salesman Problem (TSP) using Dynamic Programming
with bit masking to find the minimum travelling cost.
*/

#include <stdio.h>

#define MAXN 15
#define INF 999999

int n;
int costMatrix[MAXN][MAXN];
int memo[MAXN][1 << MAXN];

// Recursive function using DP + Bitmasking
int tsp(int currentCity, int remainingSet)
{
    // If all cities are visited, return cost to go back to start
    if (remainingSet == 0)
        return costMatrix[currentCity][0];

    // If already computed, return stored value
    if (memo[currentCity][remainingSet] != -1)
        return memo[currentCity][remainingSet];

    int minCost = INF;

    // Try visiting each unvisited city
    for (int next = 0; next < n; next++)
    {
        if (remainingSet & (1 << next))
        {
            int newCost = costMatrix[currentCity][next] +
                          tsp(next, remainingSet & ~(1 << next));

            if (newCost < minCost)
                minCost = newCost;
        }
    }

    return memo[currentCity][remainingSet] = minCost;
}

int main()
{
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    if (n <= 1)
    {
        printf("Error: Number of cities must be greater than 1.\n");
        return 1;
    }

    printf("\nEnter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Row %d: ", i);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    // Initialize memo table
    for (int i = 0; i < n; i++)
        for (int mask = 0; mask < (1 << n); mask++)
            memo[i][mask] = -1;

    // Create set of cities excluding starting city (0)
    int set = 0;
    for (int i = 1; i < n; i++)
        set |= (1 << i);

    // Display matrix (for clarity)
    printf("\nCost Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        printf("| ");
        for (int j = 0; j < n; j++)
            printf("%3d ", costMatrix[i][j]);
        printf("|\n");
    }

    printf("\nCalculating minimum travelling cost using DP...\n");

    // Compute result
    int result = tsp(0, set);

    printf("\nMinimum travelling cost (starting from City 0): %d\n", result);

    return 0;
}
